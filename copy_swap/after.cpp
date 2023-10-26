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


	friend void swap(DArray& lhs, DArray& rhs)noexcept
	{
		using std::swap; //not necessary here 
		//may be necessasy for the members' swap function to be find by ADL
		swap(lhs.mptr, rhs.mptr);
	}
	
	//copy assignment now gives strong exception guarantee
	DArray& operator=(DArray copy)
	{
		swap(*this, copy);
		return *this;
	}

	//move constructor code is here
	//no any other move assignment function
	
	~DArray()
	{
		delete[] mptr;
	}
private:
	std::size_t m_size;
	int* mptr;
};
