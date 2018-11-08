#ifndef UNORDERED_H
#define UNORDERED_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Options.h"
#include "location.h"

class Unordered {
    public:
        Unordered(Options);
        void run();

    private:
        Options options;
        std::unordered_map<unsigned, std::vector<location>> map;

        void read_data();
        void access_data();
};

#endif // UNORDERED_H
