#### non-virtual interface

+ İdiyomu ilk tanıtan _Herb Sutter_: <br>
<<Prefer to use Template Method to make the interface stable and nonvirtual, 
while delegating customizable work to nonpublic virtual functions that are responsible for implementing the customizable behavior. >>

+ Bu idiyom _template method_ tasarım kalıbının özel bir kullanım senaryosu olarak görülebilir.

+ Sınıfın sanal fonksiyonlarını _public_ yapmak yerine _private_ ya da _protected_ yapıyoruz. 
Böylece bu fonksiyonlar sınıfın public arayüzünde yer almıyorlar. Bu fonksiyonları sınıfın public arayüzünde yer alan sanal olmayan fonkisyon(lar) çağırıyorlar.
Eğer taban sınıfın sanal fonksiyonlarının implementasyonu türemiş sınıf kodları tarafından kullanılacak ise bu fonksiyonlar  _protected_ aksi halde _private_ oluyorlar. 
+ Sınıfın public arayüzünde sanal fonksiyon bulunmuyor.

#### neden böyle yapıyoruz?

+ Sınıfın sanal fonksiyonları türemiş sınıflar için aslında bir customization/specialization noktası. 
Dolayısıyla çoğunlukla bu kodlar implementasyona ilişkin. 
Sanal fonksiyonları public yaparak interface ile implementasyon'ı birbirinden ayırmamış oluyoruz.
+ public sanal arayüz bir sınıfın türemiş sınıflara pre-conditions/post_conditions dayatmasını sağlamıyor. 
Çünkü bu fonksiyonlar çağrıldığında türemiş sınıfların override'ları çağrılmış olacak. 
Taban sınıf davranış üzerinde daha belirleyici bir rol oynuyor ve sağlayacağı işlevsellik üzerinde garantiler verebiliyor.

+ Bu şekilde türemiş sınıfların taban sınıfın yerine geçebilirliği taban sınıf tarafından kontrol edilebiliyor.

+ verimlilik _(efficiency)_ kaygısı varsa _preconditions_ ve _postconditions_ sınama kodları duruma göre sadece debug sürümünde yer alabilir. 
+ implementasyondaki bir değişiklik sınıfın _public_ arayüzünde bir değişimi gerektirmiyor. Taban sınıf daha sağlam _(robust)_ oluyor. 
Böylece client kodlarda değişiklik yapılması gerekmiyor.

+ taban sınıf kendi sözleşmesini dayatabiliyor. (preconditions - postconditions)

+ belirli kodlar türemiş sınıfların implementasyonunda tekrar etmiyor. Bunlar taban sınıfın istediği noktada toplanmış ve kullanılmış oluyorlar. (yani taban sınıfın sanal olmayan fonksiyonu içinde)


