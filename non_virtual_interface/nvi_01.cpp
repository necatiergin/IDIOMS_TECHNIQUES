#include <iostream>

class Widget
{
public:
	void draw()
	{
		clear_background();
		paint();
	}
	virtual ~Widget() = default;
private:
	virtual void paint() = 0;
protected:
	virtual void clear_background()
	{
		std::cout << "clearing Widget background..." << '\n';
	}
};

class Button : public Widget
{
private:
	virtual void paint() override
	{
		std::cout << "painting Button..." << '\n';
	}
protected:
	virtual void clear_background() override
	{
		Widget::clear_background();
		std::cout << "clearing  Button background..." << '\n';
	}
};

class CheckBox : public Button
{
private:
	virtual void paint() override
	{
		std::cout << "painting CheckBox..." << '\n';
	}
protected:
	virtual void clear_background() override
	{
		Button::clear_background();
		std::cout << "clearing CheckBox background..." << '\n';
	}
};
