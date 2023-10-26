#include <string>

class OpenFile {
public:
    OpenFile(std::string const& filename) : m_filename{ filename } {}

    OpenFile& readonly()
    {
        m_readonly = true;
        return *this;
    }

    OpenFile& readwrite()
    {
        m_readonly = true;
        return *this;
    }

    OpenFile& create_if_not_exists()
    {
        m_create_if_not_exists = true;
        return *this;
    }

    OpenFile& block_size(unsigned nbytes)
    {
        m_block_size = nbytes;
        return *this;
    }
private:
    friend class File;
    std::string m_filename;
    bool m_readonly{};
    bool m_create_if_not_exists{};
    unsigned m_block_size{ 4096 };     
};


class File {
public:
    File(const OpenFile& params) :
        m_filename{ params.m_filename },
        m_readonly{ params.m_readonly },
        m_create_if_not_exists{ params.m_create_if_not_exists },
        m_block_size{ params.m_block_size } {}
private:
    std::string m_filename;
    bool m_readonly{};
    bool m_create_if_not_exists;
    unsigned m_block_size;
};


int main()
{
    File myfile(OpenFile{ "necati.txt" }
        .readonly()
        .create_if_not_exists()
        .block_size(2048)
    );
}
