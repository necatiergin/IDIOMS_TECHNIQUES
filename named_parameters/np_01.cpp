//parametre değişkeni sayısı fazla olduğunda isimlendirilmiş argüman kullanmak bir avantaj sağlıyor.

#include <string>

class File {
public:
    File(std::string file_name, bool m_readonly, bool create_if_not_exists, unsigned block_size);
//...
};


int main()
{
    File myfile("deneme.txt", true, false, 1024);
}
