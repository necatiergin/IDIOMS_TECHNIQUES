#include <utility>

//possibly same assembly code for both functions

char* strcpy1(char* pdest, const char* psource) 
{
    while ((*pdest++ = *psource++))
        ;
    return pdest;
}

char* strcpy2(char* pdest, const char* psource) 
{
    for (;;) {
        auto sc = std::exchange(psource, psource + 1);
        auto dc = std::exchange(pdest, pdest + 1);
        *dc = *sc;
        if (*dc == '\0') 
            break;
    }
    return pdest;
}
