#include <cstdlib>
#include <algorithm>

class DArray
{
public:
	DArray(std::size_t size = 0) : m_size(size),
	mptr(m_size ? new int[m_size]() : nullptr) { }
	
	
	//copy ctor may throw
	DArray(const DArray& other) : m_size(other.m_size), 
		       mptr(m_size ? new int[m_size] : nullptr)
	{
		std::copy(other.mptr, other.mptr + m_size, mptr);
	}

	//copy assignment doesn't give strong exception guarantee

	DArray& operator=(const DArray& other)
	{
		if (this != &other) // (1)
		{
			delete[] mptr; // (2)
			mptr = nullptr;
			// 
			m_size = other.m_size;
			mptr = m_size ? new int[m_size] : nullptr;
			std::copy(other.mptr, other.mptr + m_size, mptr);
		}
		return *this;
	}

	//move constructor code is here
	//move assignment code is here	
	
	~DArray()
	{
		delete[] mptr;
	}
private:
	std::size_t m_size;
	int* mptr;
};
