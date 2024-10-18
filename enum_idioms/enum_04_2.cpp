#define STRONG_BOOL(e)   \
    enum class e : bool  \
    {                    \
        No  = false,    \
        Yes = true      \
    }

STRONG_BOOL(Open);
STRONG_BOOL(Close);
STRONG_BOOL(ReadOnly);
STRONG_BOOL(Write);

void access_file(Open open, Close close, ReadOnly readonly, Write write);

void foo()
{
    access_file(Open::Yes, Close::No, ReadOnly::No, Write::No);
}

