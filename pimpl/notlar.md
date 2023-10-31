- Pimpl, en çok kullanılan tekniklerden biri. _pointer implementation_ sözcüklerinden uydurulmuş. Bu idiyom farklı terimlerle anılıyor:
  - pimpl
  - opaque pointer
  - handle body
  - d pointer
  - cheshire cat

- Bu teknikteki genel amaç sınıfın arayüzü ile sınıfın gerçekleştirimi arasındaki bağımlılığı ortadan kaldırmak. 
- Sınıfın gerçekleştiriminde bir değişiklik yapıldığında müşteri kodların bundan etkilenmemesini sağlamak.
- Sınıfa kararlı bir _"abstract binary interface"_ kazandırmak.
- Derleme sürelerini kısaltmak. Başlık dosyaları başlık dosyalarını include etmek zorunda kalmıyor. 

#### nasıl gerçekleştiriliyor?

- Sınıfın _private_ bölümünü (_private_ veri elemanlarını ve _private_ üye fonksiyonlarını) gizliyoruz.
- sınıfın veri elemanları ve üye fonksiyonları implementasyon dosyasında tanımlanan ancak başlık dosyasında bildirilen bir sınıfın elemanları yapılıyor. Sınıf bu türden birt pointer ya da _smart pointer_ (_std::unique_ptr_) veri elemanına sahip oluyor. Eski gerçekleştirimlerde sınıfın veri elemanı ham pointer _(raw pointer)_ yapılıyordu. Şimdi artık veri elemanı  _std::unique_ptr_ sınıfı türünden yapılıyor.


```
#include <memory>

class Nec {
	//...
	struct pimpl;
	std::unique_ptr<pimpl> mp;
};
```

Sınıfın _private_ veri elemanlarında bir değişiklik yaptığımızda sınıf nesnesinin temsili _(object layout)_ değişebilir.

Veri elemanlarının değiştirilmesinden ne kast ediyoruz?
- yeni bir eleman eklenmesi
- var olan bir elemanın silinmesi
- bir elemanın türünün değiştirilmesi

Sınıfın  bir _private_ fonksiyonunda değişiklik yaptığımızda bu durum
	- _function overload resolution_'ı etkiler.
	- Önce _overload resolution_ yapılır sonra erişim kontrolü gerçekleşir.
