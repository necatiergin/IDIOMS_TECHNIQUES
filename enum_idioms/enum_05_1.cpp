void access_file(bool open, bool close, bool readonly, bool write);

void foo()
{
    access_file(true, false, false, true);
}

void bar()
{
    access_file(/*open*/ true, /*close*/ false, /*readonly*/ false, /*write*/ true);
}
