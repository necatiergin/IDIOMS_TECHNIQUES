#ifndef STREAM_H
#define STREAM_H

class Stream {
public:
	Stream();
	~Stream();
};

extern Stream& gstream;		//global stream object

static struct StreamInitializer {
	StreamInitializer();
	~StreamInitializer();
} gstreamInitializer;  // static initializer for every translation unit

#endif 
