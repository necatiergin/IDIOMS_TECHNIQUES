- Güçlü türler _(strong types)_, kodun ifade gücünü artırmaya yönelik basit ve etkili bir araçtır. 
- Kodun niyetini hem derleyiciye hem de kodu okuyan programcılara daha iyi anlatır.

- Güçlü türler, türden bağımsız ince bir sarmalayıcı sınıf _(thin wrapper)_ olarak ifade edilebildiklerinden verim açısından bir dezavantaj oluşturmazlar.

```

template <typename T, typename Tag>
class NamedType
{
public:
    explicit NamedType(T const& value) : mval(value) {}
    T& get()
    {
        return mval;
    }
    
    T const& get() const 
    {
        return mval;
    }
private:
    T mval;
};

using Weight = NamedType<double, struct KilogramTag>;
using Height = NamedType<double, struct LengthTag>;

class Athlete {
public:
    Athlete(Weight, Height);
    //...
};

```
<!--
-->
