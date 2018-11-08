#ifndef BUILD_H
#define BUILD_H

#include <string>
#include "Options.h"

class Build {
    public:
        Build(Options);
        void run();

    private:
        Options options;

};

#endif // BUILD_H
