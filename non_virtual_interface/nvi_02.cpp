#include <istream>
#include <ostream>
#include <cassert>

class Lock {
public:
    //...
    void acquire();
    void release();
};

class Data {
public:
    //...
    bool check_invariants()const;
};

class Base {
private:
    Lock m_lock;
    Data m_data;
public:
    void read(std::istream& iss)  //virtual değil
    { 
        m_lock.acquire();
        assert(m_data.check_invariants()); // must be true

        do_read(iss);

        assert(m_data.check_invariants()); // must be true
        m_lock.release();
    }

    void write_to(std::ostream& o) // virtual değil
    { 
        m_lock.acquire();
        do_write(o);
        m_lock.release();
    }

    virtual ~Base() {}  
private:
    virtual void do_read(std::istream&) = 0;
    virtual void do_write(std::ostream&) = 0;
};

class XMLReaderWriter : public Base {
private:
    void do_read(std::istream&) override
    {
        // Read XML.
    }
    
    void do_write(std::ostream&) override
    {
        // Write XML.
    }
};

class JasonReaderWriter : public Base {
private:
    void do_read(std::istream&) override
    {
        // Read Jason.
    }

    void do_write(std::ostream&) override
    {
        // Write Jason.
    }
};


class TextReaderWriter : public Base {
private:
    void do_read(std::istream&) override
    {
        // Read Text
    }

    void do_write(std::ostream&) override
    {
        //write text
    }
};
