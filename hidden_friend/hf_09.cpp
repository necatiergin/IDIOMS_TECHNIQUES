#include <cstddef>

template <typename T> 
class Array {
public:
	Array(T* array, std::size_t size) : m_pa{ array }, m_size{ size } {}
	
	~Array() 
	{
		delete[] m_pa;
	}
	
	T& operator[](std::size_t idx) { return m_pa[idx]; }
	const T& operator[](std::size_t idx)const { return m_pa[idx]; }
	
	std::size_t size() const { return m_size; }
	friend void swap(Array& left, Array& right) noexcept 
	{
		//two-step ADL and fallback idiom
		using std::swap;
		swap(left.m_pa, right.m_pa);
		swap(left.m_size, right.m_size);
	}
private:
	T* m_pa;
	std::size_t m_size;
};
