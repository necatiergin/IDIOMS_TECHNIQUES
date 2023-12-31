#### örnek kodun açıklaması

- _Stream_ sınıfının başlık dosyası _Stream_ nesnesinin kullanılmasından önce mutlaka koda dahil edilmeli _(include edilmeli)_
- Her çeviri biriminde _(translation unit)_ statik ömürlü ayrı bir _StreamIninitializer_ nesnesi oluşturuluyor
- _Stream_ nesnesini kullanan herhangi bir kod önce _Stream_ sınıfının  başlık dosyasını dahil ettiğinden global _Stream_ nesnesi olan _scout_'un _construct_ edilmiş olması garanti altına alınmış oluyor.
- _Stream_ sınıfının başlık dosyası global bir _Stream_ nesnesi olan _scout_ değişkenine bir referans bildiriyor.
- Bu referansın _extern_ anahtar sözcüğü ile bildirilmesi, _scout_ değişkeninin bir çeviri birimi _(translation unit)_ içinde tanımlandığını ve 
çözümlemesinin derleyici tarafından değil bağlayıcı tarafından yapılacağını anlatıyor.
- implementasyon dosyası _scout_ nesnesini sıradışı bir şekilde tanımlıyor.
Önce çeviri birimi içinde, nesnenin yaratılacağı bellek alanı olarak kullanılacak _static_ bir _buffer_ tanımlıyor.
Nesnenin sığacağı büyüklükte olan bu _buffer_ uygun şekilde hizalanmış.
Burada kullanılan standart kütüphane öğelerini bilmiyorsanız buraya takılmayın.
- Başlık dosyası içinde bildirilen _Stream_ nesnesine referans olan _scout_ bu _buffer_'ı gösterir biçimde tanımlanıyor:
```
Stream& scout = reinterpret_cast<Stream&> (stream_buf);
```
- İlk _StreamInıtializer_ nesnesi hayata geldiğinde çağrılan _StreamInıtializer_ _constructor_'u, _placement new_ ifadesi ile _Stream_ nesnesinin _constructor_'unun çağrılmasını sağlıyor.
- Son _StreamInitializer_ nesnesinin _destructor_'u ise _Stream_ nesnesinin _destructor_'unu çağırıyor.
<!--
This workaround is necessary because defining a Stream variable within Stream.cpp - be it static or not - will define it after the StreamInitializer, 
which is defined by including the header. 
Then, the StreamInitializer's constructor is run before Stream's constructor and even worse, 
the initializer's destructor is run after the Stream object's destructor. The buffer solution above avoids this.
-->
