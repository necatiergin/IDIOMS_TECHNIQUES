#### hidden friends
Bir sınıf tanımı içinde sınıfın üye fonksiyonu olmayan ve sınıf tanımının içinde yer aldığı isim alanında _(namespace)_ bulunan bir fonksiyon _friend_ bildirimiyle sınıf içinde tanımlanabilir. Böyle fonksiyonlara _"hidden friend"_ denmektedir. BU fonksiyonlar sınıfın _friend_'i olduklarından sınıfın _private_ bölümüne erişebilirler.

+ Sınıf nesneleri üstünde işlem yapacak bir fonksiyonun sınıfın içinde _friend_ anahtar sözcüğü ile _namespace_ kapsamında _(namespace scope)_ tanımlanması.
+ Özellikle operator fonksiyonları için tercih ediliyor.
+ Bu durumda fonksiyon ismi _ADL_ ile bulunuyor. 
Bu fonksiyonları _ADL_ dışında çağırmak mümkün olmadığından bu fonksiyonlar gizlenmiş oluyor. 
+ Hata mesajları daha kısa oluyor. Verilen örneklere bakınız. 
+ Derleme süresi kısalıyor.
+ _hidden friend_'ler ile _customization point_ oluşturuluyor. (Derste anlatıyorum)
+ İstenmeyen örtülü tür dönüşümleri engellenmiş oluyor. (Örneğe bakınız)

okumakta fayda olan bağlantılar:

https://www.justsoftwaresolutions.co.uk/cplusplus/hidden-friends.html <br>
https://quuxplusone.github.io/blog/2019/04/26/what-is-adl/ <br>
https://blog.panicsoftware.com/friends-and-where-to-find-them/ <br>
