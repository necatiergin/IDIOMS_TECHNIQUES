#include "stream.h"
#include <string>

struct UserB {
    UserB()
    {
        gstream.write("UserB::ctor");
    }

    ~UserB()
    {
        gstream.write("UserB::dtor");
    }
};

static UserB buser;
