#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>

#include "MetacacheHashMultiMap.h"

MetacacheHashMultiMap::MetacacheHashMultiMap(Options options) {
    this->options = options;
}

void MetacacheHashMultiMap::run() {
    // First, test parameters
    if (this->options.get_input_file().compare("") == 0) {

        std::cerr << "No input file name. Aborting\n";
        exit(-1);
    }

    std::cout << "Running...\n";

    auto start = std::chrono::high_resolution_clock::now();
    this->read_data();
    auto finish = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = finish - start;

    std::cout << "Elapsed time in reading data: " << elapsed.count() << " s\n";

    std::cout << "Size of metacache_map is: " << this->map.key_count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    this->access_data();
    finish = std::chrono::high_resolution_clock::now();

    elapsed = finish - start;
    std::cout << "Elapsed time in accessing data: " << elapsed.count() << " s\n";
}


void MetacacheHashMultiMap::read_data() {
    std::ifstream is;

    is.open(this->options.get_input_file());

    if(!is.good()) {
        std::cerr << "Can't open file" << this->options.get_input_file() << std::endl;
        exit(1);
    }

    std::string line;
    std::string key_delimiter = ":";
    char values_delimiter = ';';
    unsigned key;

    std::vector<std::string> tokens;
    std::string token;
    std::string key_string;
    std::string values_string;
    std::istringstream tokenStream;
    unsigned value1, value2;
    //std::cout << "Starting to read lines..." << std::endl;

    while (getline(is, line)) {
        key_string = line.substr(0, line.find(key_delimiter));
        //std::cout << "Current key... " << key_string << std::endl;
        //key = std::stoul (key_string, nullptr, 0);
        key = std::stoul (key_string, nullptr, 0);
        //std::cout << "Now line" << std::endl;
        values_string = line.substr(line.find(key_delimiter)+1, line.length());


        tokenStream = std::istringstream(values_string);

        while (std::getline(tokenStream, token, values_delimiter)) {
            tokens.push_back(token);
        }

        tokenStream.clear();
        values_string.clear();
        key_string.clear();

        for ( unsigned i = 0; i< tokens.size(); i+=2) {
            //std::cout << "Now line: "<< tokens.at(i) << " :: " << tokens.at(i+1) << std::endl;
            value1 = std::stoul(tokens.at(i), nullptr, 0);
            value2 = std::stoul(tokens.at(i+1), nullptr, 0);

            location new_location{value1, value2};
            this->map.insert(key, new_location);
        }

        tokens.clear();

    }

    is.close();
}

void MetacacheHashMultiMap::access_data() {
    srand(time(nullptr));
    unsigned random_number; // rand() return a number between ​0​ and RAND_MAX
    unsigned random_list_item;

    double result = 0.0;
    std::vector<location> res;

    for (unsigned i = 0; i< this->map.key_count(); ++i) {

        res.clear();

        random_number = std::rand() % this->map.key_count();

        auto locs = this->map.find(random_number);


        //if(locs != this->map.end() && locs->size() > 0) {
            res.insert(res.end(), locs->begin(), locs->end());

            random_list_item = std::rand() % res.size();
            result = res.at(random_list_item).tgt - result + res.at(random_list_item).win;
        //}
    }

    std::cout << "Obtained result is: " << result << std::endl;
}
