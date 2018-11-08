#ifndef METACACHEHASHMULTIMAP_H
#define METACACHEHASHMULTIMAP_H

#include "hash_multimap.h"
#include "location.h"
#include "Options.h"

class MetacacheHashMultiMap
{
public:
    MetacacheHashMultiMap(Options);
    void run();

private:
    Options options;
    mc::hash_multimap<unsigned, location> map;

    void read_data();
    void access_data();
};

#endif // METACACHEHASHMULTIMAP_H
