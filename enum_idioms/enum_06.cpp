enum class Color { White, Yellow, Red, Brown, Blue, Black, NoOfColors };

int main()
{
    for (int i = 0; i < static_cast<int>(Color::NoOfColors); ++i) {
        Color c = static_cast<Color>(i);
        //...
    }

}

