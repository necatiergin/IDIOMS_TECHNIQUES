#ifndef STREAM_H
#define STREAM_H

#include <iostream>

class Stream {
public:
    Stream();
    ~Stream();
    void write(const char* msg);
};

// global reference to the single shared-variable
extern Stream& gstream;

// a separate guard for each translation unit
struct StreamInitializer {
    StreamInitializer();
    ~StreamInitializer();
};

// internal linkage- each TU will have its own object
static StreamInitializer gstreamInitializer;

#endif
