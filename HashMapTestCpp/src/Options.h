#ifndef OPTIONS_H
#define OPTIONS_H

#include <getopt.h>
#include <string>
#include <iostream>
#include "Modes.h"

class Options {

public:
    Options();
	Options(int, char**);
	void print_args();
    Mode get_mode();
    std::string get_mode_str();
    std::string get_input_file();
    std::string get_output_file();
    unsigned get_map_size();
    unsigned get_list_size();

private:
    Mode mode;
    std::string input_file = "";
    std::string output_file = "";
    unsigned map_size = 1000000;
    unsigned list_size = 256;
};

#endif // OPTIONS_H
