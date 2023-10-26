#include <utility>

template<class T>
void foo(T) {
    T x;
    T y;
    //...
    using std::swap;
    swap(x, y);
}

/*
    Burada swap için bir "customization point" oluşturuluyor
    T için kullanılan argümanın bulunduğu isim alanında custom bir swap fonksiyonu varsa 
    swap(T&, T&) 
    Bu fonksiyon ismi ADL ile bulunacak ve bu seçilecek
    Eğer böyle bir overload yok ise
    fallback olarak std::swap kullanılacak (using bildirimi ile görünür kılınıyor)
    Eğer ADL'i devre dışı bırakmak istersek yani her zaman std::swap'ın kullanılmasını istersek 
    nitelenmiş isimle (qualified name) çağırmalıyız:
    std::swap(x,y).

*/
