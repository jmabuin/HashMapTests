#include "Build.h"
#include <iostream>
#include <fstream>

Build::Build(Options options) {
    this->options = options;
}

void Build::run() {

    // First, test parameters
    if (this->options.get_output_file().compare("") == 0) {

        std::cerr << "No output file name. Aborting\n";
        exit(-1);
    }


    //std::ofstream os(options.get_output_file(), std::ios::out | std::ios::binary);
    std::ofstream os;

    os.open(this->options.get_output_file());

    if(!os.good()) {
        std::cerr << "Can't open file" << this->options.get_output_file() << "\n";
        exit(1);
    }

    //        this->serialize(os);

    for (unsigned i = 0; i < this->options.get_map_size(); ++i) {
        os << i << ":";

        for (unsigned int j = 0; j < this->options.get_list_size() * 2; ++j) {
            os << j << ";";
        }

        os << "\n";


    }

    os.close();


}
