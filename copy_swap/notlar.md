## copy & swap idiyomu

+ Bu idiyom çok yaygın bir kullanıma sahip. Bu yüzden öğrenmek gerekiyor.
+ Sınıfın atama operatör fonksiyonlarının yazılmasında kullanılıyor.
+ Modern C++ öncesi implementasyonlara dikkat. 
Taşıma semantiği _(move semantics)_ söz konusu olduğunda taşıyan atama operatör __(move assignment)__ fonksiyonunu da dikkate almak gerekiyor.
+ İdiyom atama operatör fonksiyonlarına __strong exception guarantee__ kazandırmayı ve kod tekrarından kaçınmayı sağlıyor. (Temel C++ kursunda detaylı anlatılıyor.)
+ Elde edilebilecek diğer faydalar: ortak kodu tek bir yere toplamak, klasik gerçekleştirimdeki  "kendi kendine atama" _(self assignment)_ kontrolünü yapmamak.
+ Dezavantajları _Howerd Hinnant_ tarafından çok iyi açıklanmış: <br>
Verim açısından (duruma göre) ciddi bir ekstra maliyeti olabilir. 
  + Birçok  sınıf için ayrı ayrı yazılmış _copy assignment_ ve _copy constructor_ daha etkin bir kod oluşturur. 
  + _strong exception guaarantee_ istenmiyor ise neden verimden _(efficiency)_ taviz verelim?
  + dileyen _generic_ strong exception guarantee sağlayan bir fonksiyonu kullanabilir:

```
template <typename T>
T& strong_assign(T& dest, T source)
{
	using std::swap;
	swap(dest, source);
	return dest;
}
```` 
_(Howard Hinnant)_

+ copy-constructor'ı kullanarak atamada kullanılacak (atama operatörünün sağ tarafındaki) sınıf nesnesinin (yerel-geçici nesne olarak) bir kopyasını oluşturuyoruz.
+ Sonra _swap_ fonksiyonuna çağrı yaparak eski veriyi yeni veri ile takas ediyoruz.
+ Oluşturduğumuz yerel/geçici nesne eski datayı almış oluyor ve yok ediliyor.
+ Tutulmakta olan veri değişiyor.

Bu idiyomu implemente etmek için nelere ihtiyacımız var?
+ İşini doğru şekilde yapan bir copy ctor
+ İşini doğru şekilde yapan bir destructor
+ (exception throw) etmeyen bir swap işlevi

Buradaki swap fonksiyonu, sınıf türünden iki nesneyi eleman-eleman takas eden _exception throw etmeyen_ bir işlev olmalı.
Sınıf türünden iki nesneyi takas etmek için standart _swap_ işlevi kullanılmamalı. 
Çünkü swap işlevinin kendisi _copy ctor_ ve _copy assignment_ fonksiyonlarını çağırıyor.
Bu durumda atama operatör fonksiyonu özyinelemeli _(recursive)_ olarak atama operator fonksiyonunu çağırıyor olabilir.

+ idiyomun genel tanımı (implementasyonlar farklı olabilir)
  + kaynakları geri veren bir _destructor_ olsun
  + _copy ctor_ doğal şekilde yazılsın (deep- copy) ya da duruma göre_ default_ edilsin.
  + iki nesnenin içeriğini takas eden (muhtemelen elemanlarını) bir _swap_ fonksiyonu yazılsın. Bu sınıfın üye fonksiyonu da olabilir sınıfa _friend_ bir global _(free)_ fonksiyon da olabilir. 
Genel tercih çağrılacak _swap_ işlevinin __friend__ olması. 
    + Bu fonksiyon içinde neden using _std::swap_ bildirimi yapıyoruz? 
      Doğrudan std::swap çağrısı yaparsak sınıfın veri elemanları için yazılmış _swap_ işlevleri _ADL_ ile bulunamaz.
  + atama operatör fonksiyonunda 
    + atama operatörünün sağ tarafındaki nesnenin lokal bir kopyasını oluştur (bu amaçla _copy ctor_ çağrılacak) 
      + bunun en kolay yolu atama operatör fonksiyonunun parametresini sınıf türünden yapmak (sınıf türünden const & değil)
      + Böylece hem _copy elision_ olanağı korunmuş olacak hem de ayrı bir_ move assignment_ işlevi yazmak zorunda kalmayacağız.
    + *this nesnesi ile bu kopyayı takas et
    + Yerel nesne için kapsam _(scope)_ sonunda _destructor_ çağrılacak. Ve eski kaynaklar geri verilecek.
 
  + Sınıf için yazılacak _move ctor_ da _swap_ işlevini çağırabilir. 
   C++11 ile _move ctor_ _default ctor_'a delege edip _swap_ fonksiyonunu çağırabilir. _(delegated constructor)_

  + _Howard Hinnant_ copy & swap idiyomunun muhaliflerinden biri.
