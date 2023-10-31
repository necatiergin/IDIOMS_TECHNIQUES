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

- Sınıfın _private_ bölümünü (private veri elemanlarını ve private üye fonksiyonlarını) gizliyoruz.
- sınıfın veri elemanları ve üye fonksiyonları impelemtasyon dosyasında tanımlanan ancak başlık dosyasında bildirilen bir sınıfın elemanları yapılıyor.
- eski gerçekleştirimlerde sınıfın veri elemanı ham pointer _(raw pointer)_ yapılıyordu. Şimdi artık veri elemanı olarak std::unique_ptr sınıfı türünden yapılıyor.
