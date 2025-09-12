#include "stream.h"
#include <cstddef> // std::byte
#include <new>     // placement-new

// TU-local counter: initialized to 0 at program load time

static int nifty_counter = 0;

// aligned storage for stream object
alignas(Stream) static std::byte stream_buf[sizeof(Stream)];

// definition of Stream& gstream declared as extern in the header stream.h
Stream& gstream = reinterpret_cast<Stream&>(stream_buf);

// --- Stream members ---
Stream::Stream() 
{
    std::cout << "[Stream::ctor]\n";
}

Stream::~Stream() 
{
    std::cout << "[Stream::dtor]\n";
}

void Stream::write(const char* msg) 
{
    std::cout << "[Stream] " << msg << '\n';
}

// --- Nifty guard ---
StreamInitializer::StreamInitializer() 
{
    if (nifty_counter++ == 0) {
        // first guard constructs the object with placement new
        new (&gstream) Stream();
    }
}

StreamInitializer::~StreamInitializer() 
{
    if (--nifty_counter == 0) {
        // last guard calls the destructor of the srvice object
        (&gstream)->~Stream();
    }
}
