#include <cstdio>
#include <cstring>
#include <iostream>
#include "Options.h"

Options::Options() {
    
}

Options::Options(int argc, char** argv) {
	const char* const short_opts = "i:o:s:l:m:";
    
    const option long_options[] = {
          {"input_file", required_argument, nullptr, 'i'},
          {"output_file", required_argument, nullptr, 'o'},
          {"map_size", required_argument, nullptr, 's'},
          {"list_size", required_argument, nullptr, 'l'},
          {"mode", required_argument, nullptr, 'm'}, //Modes are: build, unordered_map and metacache_map
          {nullptr, no_argument, nullptr, 0}
    };
    	
    while (true)
    {
        const auto opt = getopt_long(argc, argv, short_opts, long_options, nullptr);

        if (-1 == opt)
            break;
				
        switch (opt) {
            case 'i':
                // Input file name
                this->input_file = optarg;
                break;
            case 'o':
                this->output_file = optarg;
                break;
            case 's':
                this->map_size = std::stoi(optarg);
                break;
            case 'l':
                this->list_size = std::stoi(optarg);
                break;
            case 'm':
                if(std::strcmp(optarg, "build") == 0) {
                    this->mode = BUILD;
                }
                else if(std::strcmp(optarg, "unordered_map") == 0) {
                    this->mode = UNORDERED_MAP;
                }
                else if(std::strcmp(optarg, "metacache_map") == 0) {
                    this->mode = METACACHE_MAP;
                }
                else {
                    std::cerr << "Not recognized mode. Aborting\n";
                    exit(-1);
                }
                break;
            default:
                break;
        }
    }
}

Mode Options::get_mode() {
    return this->mode;
}

std::string Options::get_mode_str() {
    
    switch (this->mode) {
        case BUILD:
            return "build";
        case UNORDERED_MAP:
            return "unordered_map";
        case METACACHE_MAP:
            return "metacache_map";
        default:
            return "nullptr";
        
    }
    
}

void Options::print_args() {
    
    std::cout << "Test launched with the followin options\n";
    std::cout << "Working mode: " << this->get_mode_str() << "\n";
    std::cout << "Input file:   " << this->input_file << "\n";
    std::cout << "Output file:  " << this->output_file << "\n";
    std::cout << "Map size:     " << this->map_size << "\n";
    std::cout << "List size:    " << this->list_size << "\n";
    
}


std::string Options::get_input_file() {
    return this->input_file;
}

std::string Options::get_output_file() {
    return this->output_file;
}

unsigned Options::get_map_size() {
    return this->map_size;
}

unsigned Options::get_list_size() {
    return this->list_size;
}