#pragma once

#include <ostream>

class Car {
public:
	virtual ~Car() {}
	//...
	friend std::ostream& operator<<(std::ostream& os, const Car& car)
	{
		return car.print(os);		
	}
protected:
	virtual std::ostream& print(std::ostream& os)const = 0;
};


class Volvo : public Car {
public:

	std::ostream& print(std::ostream& os)const override
	{
		return os << "I am a Volvo";
	}
};


class Audi : public Car {
public:
	std::ostream& print(std::ostream& os)const override
	{
		return os << "I am an Audi";
	}
};

class Tesla : public Car {
public:
	std::ostream& print(std::ostream& os)const override
	{
		return os << "I am a Tesla";
	}
};

#include <iostream>


void car_foo(Car& car)
{
	//...
	std::cout << car << '\n';
}

int main()
{
	Tesla tesla;
	Audi audi;
	Volvo volvo;

	car_foo(tesla);
	car_foo(audi);
	car_foo(volvo);
}
