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

