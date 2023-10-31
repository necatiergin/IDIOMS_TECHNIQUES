- Pimpl, en çok kullanılan tekniklerden biri. pointer implementation sözcüklerinden uydurulmuş. Bu idiyom farklı terimlerle anılıyor:
  - pimpl
  - opaque pointer
  - handle body
  - d pointer
  - cheshire cat

- Bu teknikteki genel amaç sınıfın arayüzü ile sınıfın gerçekleştirimi arasındaki bağımlılığı ortadan kaldırmak. 
- Sınıfın gerçekleştiriminde bir değişiklik yapıldığında müşteri kodların bundan etkilenmemesini sağlamak.
- Sınıfa kararlı bir "abstract binary interface" kazandırmak.
- derleme sürelerini kısaltmak.

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
