#include <stdio.h>
#include "Options.h"
#include "Build.h"
#include "Unordered.h"
#include "MetacacheHashMultiMap.h"

int main(int argc, char **argv)
{
    Options program_options = Options(argc, argv);

    program_options.print_args();

    if (program_options.get_mode() == BUILD) {
            std::cout << "build case\n";
            Build build_obj = Build(program_options);
            build_obj.run();
    }
    else if (program_options.get_mode() == UNORDERED_MAP) {
            std::cout << "unordered_map case\n";
            Unordered unordered_obj = Unordered(program_options);
            unordered_obj.run();
    }
    else if (program_options.get_mode() == METACACHE_MAP) {
            std::cout << "metacache_map case\n";
            MetacacheHashMultiMap metacache_obj = MetacacheHashMultiMap(program_options);
            metacache_obj.run();
    }

    return 0;
}
