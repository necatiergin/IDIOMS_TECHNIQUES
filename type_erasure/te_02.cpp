#include <memory>

class Animal {
public:
	template <typename T>
	Animal(T&& tval) : mptr(std::make_unique<AnimalModel<T>>(std::forward<T>(tval))) {}
	Animal(const Animal& other) : mptr(other.mptr->clone()) {}
	
	Animal& operator=(const Animal& other)
	{
		return *this = Animal(other);
	}

	Animal(Animal&&)noexcept = default;
	Animal& operator=(Animal&&)noexcept = default;

	void cry()
	{
		mptr->cry();
	}

private:
	struct AnimalConcept {
		virtual ~AnimalConcept() = default;
		virtual std::unique_ptr<AnimalConcept> clone()const = 0;
		virtual void cry() = 0;
	};

	template <typename T>
	struct AnimalModel : public AnimalConcept {
		AnimalModel(const T& t) : m_object(t) {}

		std::unique_ptr<AnimalConcept> clone()const override
		{
			return std::make_unique<AnimalModel>(*this);
		}

		void cry() override
		{
			m_object.cry();
		}

		T m_object;
	};

	std::unique_ptr<AnimalConcept> mptr;
};

#include <iostream>
#include <vector>


class Cat {
public:
	void cry()
	{
		std::cout << "miyav miyav miyav\n";
	}
};

class Dog {
public:
	void cry()
	{
		std::cout << "hav hav hav\n";
	}
};

class Bird {
public:
	void cry()
	{
		std::cout << "cik cik cik\n";
	}
};

int main()
{
	/*Animal a1{ Cat{} };
	Animal a2{ Dog{} };
	Animal a3{ Bird{} };

	a1.cry();
	a2.cry();
	a3.cry();*/

	std::vector<Animal> avec;

	avec.emplace_back(Dog{});
	avec.emplace_back(Cat{});
	avec.emplace_back(Bird{});

	for (auto& a : avec)
		a.cry();
}

