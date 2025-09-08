## non-virtual interface

+ İdiyomu ilk tanıtan _Herb Sutter_: <br>
<<Prefer to use Template Method to make the interface stable and nonvirtual, 
while delegating customizable work to nonpublic virtual functions that are responsible for implementing the customizable behavior. >>

+ Bu idiyom _template method_ tasarım kalıbının özel bir kullanım senaryosu olarak görülebilir.

+ Sınıfın sanal fonksiyonlarını _public_ yapmak yerine _private_ ya da _protected_ yapıyoruz. 
Böylece bu fonksiyonlar sınıfın public arayüzünde yer almıyorlar. Bu fonksiyonları sınıfın public arayüzünde yer alan sanal olmayan fonkisyon(lar) çağırıyorlar.
Eğer taban sınıfın sanal fonksiyonlarının implementasyonu türemiş sınıf kodları tarafından kullanılacak ise bu fonksiyonlar  _protected_ aksi halde _private_ oluyorlar. 
+ Sınıfın _public_ arayüzünde sanal fonksiyon bulunmuyor. (Bu yüzden _non-virtual interface_ deniyor.)

### avantajlar?

#### güvenli ve kararlı bir arayüz sağlanıyor. (stable public interface)
  - Kullanıcılar doğrudan sanal fonksiyonları çağırmaz.
  - Tüm erişim, sınıf tarafından tanımlanmış sabit bir yoldan (non-virtual public fonksiyon) geçer.
  - Böylece sınıfın davranışı daha öngörülebilir ve kontrollü hale gelir.

#### Sabit Akış (Fixed Execution Flow)
sanal olmayan public fonksiyon içinde alt sınıfa bırakılmayan genel bir mantık yürütülebilir. Yani taban sınıf türemiş sınıflara kendi sözleşmesini dayatabiliyor. (preconditions - postconditions)
Örneğin taban sınıfın üye fonksiyonu içinde 
- loglama yapılabilir
- kaynak doğrulama yapılabilir.
- exception handling yapılabilir.
- senkronizasyon sağlanabilir.
- eişim kontrolü yapılabilir.

#### customization/specialization noktası. 
Sınıfın sanal fonksiyonları türemiş sınıflar için aslında bir customization/specialization noktası. 
Dolayısıyla çoğunlukla bu kodlar implementasyona ilişkin. 
Sanal fonksiyonları _public_ yaparak _interface_ ile _implementasyon_'ı birbirinden ayırmamış oluyoruz.

#### implementasyondaki bir değişiklik sınıfın _public_ arayüzünde bir değişimi gerektirmiyor. 
Taban sınıf daha sağlam _(robust)_ oluyor. Böylece client kodlarda değişiklik yapılması ya da clkiednt kodların tekrar derlenmesi gerekmiyor.

#### kod tekrarı
Belirli kodlar türemiş sınıfların implementasyonunda tekrar etmiyor. Bunlar taban sınıfın istediği noktada yani taban sınıfın sanal olmayan fonksiyonu içinde toplanmış ve kullanılmış oluyorlar.

### NVI’nin Dezavantajları
#### Kod Karmaşıklığı ve Öğrenme Eğrisi
Yeni başlayanlar için neden “iki katmanlı” fonksiyon yapısına ihtiyaç duyulduğu anlaşılması zor olabilir.
_virtual_ yerine _override_ edilen fonksiyonlar _protected_ olmalı, bu da kavram karmaşası yaratabilir.

#### sınıf tasarımında fazladan detay
her bir davranış için hem bir _public wrapper_, hem de _protected virtual_ bir fonksiyon yazmanız gerekir.


#### Sanal tabloda (vtable) karmaşıklık yaratabilir
Vtable kullanımı doğrudan kullanıcı tarafından değil, public fonksiyonlar üzerinden dolaylı olur. Bu bazen debug sürecini zorlaştırabilir.


