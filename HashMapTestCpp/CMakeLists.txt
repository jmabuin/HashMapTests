cmake_minimum_required(VERSION 3.12)
project(HashMapTestCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(HashMapTestCpp
        src/Build.cpp
        src/Build.h
        src/chunk_allocator.h
        src/hash_multimap.h
        src/HashMapTest.cpp
        src/io_serialize.h
        src/location.h
        src/MetacacheHashMultiMap.cpp
        src/MetacacheHashMultiMap.h
        src/Modes.h
        src/Options.cpp
        src/Options.h
        src/Unordered.cpp
        src/Unordered.h
        Makefile
        Makefile.in)
