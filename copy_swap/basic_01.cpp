#include <cstddef>
#include <algorithm>
#include <utility>

template <typename T>
class Array {
public:
	Array(T* array, std::size_t size) : m_pa{ array }, m_size{ size } {}

	Array(const Array& other) : m_pa{ new T[other.m_size] }, m_size{ other.m_size }
	{
		std::copy_n(other.m_pa, m_size, m_pa);
	}

	Array(Array&& other) noexcept : m_pa{ std::exchange(other.m_pa, nullptr) },
		m_size{ std::exchange(other.m_size, 0) } {
	}

	Array& operator=(Array copy)
	{
		swap(*this, copy);
		return *this;
	}

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
