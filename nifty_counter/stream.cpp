// Stream.cpp
//#include "Stream.h"

#include <new>         // placement new
#include <type_traits> // aligned_storage

static int nifty_counter; // zero initialized at load time
//static typename std::aligned_storage<sizeof(Stream), alignof (Stream)>::type stream_buf; // memory for the stream object
alignas(Stream) std::byte stream_buf[sizeof(Stream)];

Stream& stream = reinterpret_cast<Stream&> (stream_buf);

Stream::Stream()
{
	// initialize things
}
Stream::~Stream()
{
	// clean-up
}

StreamInitializer::StreamInitializer()
{
	if (nifty_counter++ == 0) new (&stream) Stream(); // placement new
}
StreamInitializer::~StreamInitializer()
{
	if (--nifty_counter == 0) (&stream)->~Stream();
}


