#include "stream.h"
#include <string>

struct UserA
{
    UserA()
    {
        gstream.write("UserA::ctor");
    }

    ~UserA()
    {
        gstream.write("UserA::dtor");
    }
};

// This definition comes AFTER `gstreamInitializer` from the header.
// In the destruction phase of this translation unit, AUser is destroyed first,
// then the guard Stream is destroyed last.

static UserA auser;
