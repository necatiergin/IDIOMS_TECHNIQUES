- Pimpl, en çok kullanılan tekniklerden biri. _pointer to implementation_ sözcüklerinden uydurulmuş. Bu idiyom farklı terimlerle anılıyor:
  - pimpl
  - opaque pointer
  - handle body
  - d pointer
  - cheshire cat
  - compiler firewall

- Bu teknikteki genel amaç sınıfın arayüzü _(interface)_ ile sınıfın gerçekleştirimi _(implementation)_ arasındaki bağımlılığı _(dependancy)_ ortadan kaldırmak. 
- Sınıfın gerçekleştiriminde bir değişiklik yapıldığında müşteri kodların bundan etkilenmemesini sağlamak. Hizmet veren kodlar değiştiğinde hizmet alan kodların yeniden derlenmesi gerekmeyecek. 
- Sınıfa kararlı bir _"abstract binary interface"_ _(binary compatibility)_ kazandırmak.
- Derleme sürelerini kısaltmak. Başlık dosyaları başlık dosyalarını include etmek zorunda kalmıyor.
- Sınıfın gerçekleştirimi hakkında kullanıcı kodlara bilgi vermemek (bunu gizli tutmak).

#### nasıl gerçekleştiriliyor?

- Sınıfın _private_ bölümünü (_private_ veri elemanlarını ve _private_ üye fonksiyonlarını) gizliyoruz. Bunları ayrı bir sınıfın _(pimpl)_ elemanları yapıyoruz.
- sınıfın veri elemanları ve üye fonksiyonları implementasyon dosyasında tanımlanan ancak başlık dosyasında bildirilen bir sınıfın _(pimpl)_ elemanları yapılıyor. Sınıf bu türden bir _pointer_ ya da _smart pointer_ (_std::unique_ptr_) veri elemanına sahip oluyor. Eski gerçekleştirimlerde sınıfın veri elemanı ham pointer _(raw pointer)_ yapılıyordu:

```
class Nec {
	//...
	struct pimpl;
	pimple*  mp;
};
```

Günümüzde artık veri elemanı _std::unique_ptr_ sınıfı türünden yapılıyor.

```
#include <memory>

class Nec {
	//...
	struct pimpl;
	std::unique_ptr<pimpl> mp;
};
```

_pimpl_ sınıfının bir _nested class_ ya da _namespace_ içinde bir _class_ olması ciddi bir fark oluşturmuyor. Kapsamı daraltmak için _nested class_ olması daha iyi olabilir. Ancak bu daha çok konvensiyonel. Aynı konvensiyonlara tutarlı bir şekilde bağlı kalmak önemli.

Sınıfın _private_ veri elemanlarında bir değişiklik yaptığımızda sınıf nesnesinin temsili _(object layout)_ değişebilir.

Veri elemanlarının değiştirilmesinden ne kast ediyoruz?
- yeni bir eleman eklenmesi
- var olan bir elemanın silinmesi
- bir elemanın türünün değiştirilmesi

Sınıfın  bir _private_ fonksiyonunda değişiklik yaptığımızda bu durum
	- _function overload resolution_'ı etkiler.
	- Önce _overload resolution_ yapılır sonra erişim kontrolü gerçekleşir.

- Büyük projelerde derleme süreleri ciddi oranda kısalıyor. 
Bunun başlıca nedeni başlık dosyalarındaki _include_ komutlarının sayısının azalması.
Kritik sınıflarda _pimpl_ idiyomunun kullanılması projenin toplam derleme süresini 2 - 4 kat kadar kısaltabiliyor. _(Herb Sutter - john Lakos)_

- _pimpl_ idiyomu kullanıldığında _strong exception_ güvencesi vermek (copy swap idiyomu ile)  daha kolay ve pratik hale geliyor.

#### Olası dezavantajlar
- _pimpl_ idiyomu şüphesiz ek bir maliyet getiriyor. 
Sınıfın veri elemanlarını tutan _pimpl_ nesnesi dinamik olarak oluşturuluyor ve onun için bir bellek alanı ediniliyor _(allocate ediliyor)_.
- dinamik bellek ediniminden kaçınmak için
	- özelleştirilmiş bir _allocator_ kullanılabilir. 
	- ya da _"fast pimple idiom"_ tercih edilebilir. 
Bu tür yöntemler de tipik olarak karmaşıklığı arttırır ve _maintanance_ tarafında sorun çıkartabilir.
- _debug_ süreci daha zor olabilir.

#### okunmasında fayda olan bazı bağlantılar

(https://en.wikipedia.org/wiki/Opaque_pointer)<br>
[PIpmp - cppreference](https://en.cppreference.com/w/cpp/language/pimpl)<br>
[Pimp my pimpl - Marc Mutz](https://marcmutz.wordpress.com/translated-articles/pimp-my-pimpl/) <br>
(http://www.gotw.ca/gotw/028.htm) <br>
(https://herbsutter.com/gotw/_100/)<br>
(https://www.cppstories.com/2018/01/pimpl/)<br>
(https://www.gamedeveloper.com/programming/in-depth-pimpl-vs-pure-virtual-interfaces)<br>
(https://www.cppstories.com/2018/01/pimpl-interface/)<br>
