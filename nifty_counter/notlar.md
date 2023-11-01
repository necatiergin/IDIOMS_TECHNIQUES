#### örnek kodun açıklaması

he header file of the Stream class must be included before any member function 
can be called on the Stream object. 
An instance of the StreamInitializer class is included in each compilation unit. 
Any use of the Stream object follows the inclusion of the header, 
which ensures that the constructor of the initializer object is called before the Stream object is used.
<br>
_Stream_ sınıfının başlık dosyası global bir _Stream_ nesnesi olan _scout_ değişkenine bir referans bildiriyor.
Bu referansın _extern_ anahtar sözcüğü ile bildirilmesi, scout değişkeninin bir çeviri birimi _(translation unit)_ içinde tanımlandığını ve 
çözümlemesinin derleyici tarafından değil bağlayıcı tarafından yapılacağını anlatıyor.
implementasyon dosyası _scout_ nesnesini sıradışı bir şekilde tanımlıyor.
Önce çeviri birimi içinde, nesnenin yaratılacağı bellek alanı olarak kullanılacak _static_ bir _buffer_ tanımlıyor.
Nesnenin sığacağı büyüklükte olan bu _buffer_ uygun şekilde hizalanmış.
Burada kullanılan standart kütüphane öğelerini bilmiyorsanız buraya takılmayın.
<br>


The reference to the Stream object defined in the header is then set to point to this buffer.
This buffer workaround enables fine-grained control of when the Stream object's constructor and destructor are called. 
In the example above, the constructor is called within the constructor of the first StreamInitializer object - 
using placement new to place it within the buffer. The Stream object's destructor is called, when the last StreamInitializer is destroyed,

This workaround is necessary because defining a Stream variable within Stream.cpp - be it static or not - will define it after the StreamInitializer, 
which is defined by including the header. 
Then, the StreamInitializer's constructor is run before Stream's constructor and even worse, 
the initializer's destructor is run after the Stream object's destructor. The buffer solution above avoids this.


*/
