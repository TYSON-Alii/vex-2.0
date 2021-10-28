template <typename T> struct vex2;
template <typename T> struct vex3;
template <typename T> struct vex4;

template <typename T>
struct vex2 {
    T x, y;
    vex2() = default;
    vex2(const vex2<T>&) = default;
    template <typename _T> vex2(_T v) { x = y = T(v); };
    template <typename _T1, typename _T2> vex2(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };

    template <typename _T>  vex2<T>& operator=(_T v)        { x = y = T(v);             return *this; };
    template <typename _T>  vex2<T>& operator=(vex2<_T> v)  { x = T(v.x); y = T(v.y);   return *this; };

    template <> vex2(std::string v);
    template <> vex2(std::string v1, std::string v2);
    template <> vex2<T>& operator=(std::string v);

    vex2<T>& operator~(){ x = T(); y = T(); return *this; };
    vex2<T> operator!() { return vex2<T>(y, x); };
    vex2<T>& swap()     { *this = vex2<T>(y, x); return *this; };

    vex2<T> operator()(){ return *this; };
    vex2<T> copy()      { return *this; };

    T& operator[](int v) { return fmod(v, 2) == 0 ? x : y; };

    template <typename _T>  vex2<T> operator%(_T v)         { return vex2<T>(std::rand() % int(v),      std::rand() % int(v)); };
    template <typename _T>  vex2<T> operator%(vex2<_T> v)   { return vex2<T>(std::rand() % int(v.x),    std::rand() % int(v.y)); };

    template <typename _T>  vex2<T>& operator%=(_T v)       { x = std::rand() % int(v);     y = std::rand() % int(v);   return *this; };
    template <typename _T>  vex2<T>& operator%=(vex2<_T> v) { x = std::rand() % int(v.x);   y = std::rand() % int(v.y); return *this; };

    template <typename _T>  vex2<T> operator|(vex2<_T> v)   { return std::rand() % 2 == 0 ? vex2<T>(v) : *this; };

    template <typename _T>  vex2<T>& operator|=(vex2<_T> v) { *this = std::rand() % 2 == 0 ? vex2<T>(v) : *this; };

    vex2<T>& operator++() { x++; y++; return *this; };
    vex2<T>& operator--() { x--; y--; return *this; };

    template <typename _T>  vex2<T>& operator+=(_T v)       { x += T(v);    y += T(v);      return *this; };
    template <typename _T>  vex2<T>& operator+=(vex2<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };

    template <typename _T>  vex2<T>& operator-=(_T v)       { x -= T(v);    y -= T(v);      return *this; };
    template <typename _T>  vex2<T>& operator-=(vex2<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };

    template <typename _T>  vex2<T>& operator*=(_T v)       { x *= T(v);    y *= T(v);      return *this; };
    template <typename _T>  vex2<T>& operator*=(vex2<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };

    template <typename _T>  vex2<T>& operator/=(_T v)       { x /= T(v);    y /= T(v);      return *this; };
    template <typename _T>  vex2<T>& operator/=(vex2<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };

    template <typename _T>  vex2<T> operator+(_T v)         { return vex2<T>(this->x + T(v),    this->y + T(v)); };
    template <typename _T>  vex2<T> operator+(vex2<_T> v)   { return vex2<T>(this->x + T(v.x),  this->y + T(v.y)); };

    template <typename _T>  vex2<T> operator-(_T v)         { return vex2<T>(this->x - T(v),    this->y - T(v)); };
    template <typename _T>  vex2<T> operator-(vex2<_T> v)   { return vex2<T>(this->x - T(v.x),  this->y - T(v.y)); };

    template <typename _T>  vex2<T> operator*(_T v)         { return vex2<T>(this->x * T(v),    this->y * T(v)); };
    template <typename _T>  vex2<T> operator*(vex2<_T> v)   { return vex2<T>(this->x * T(v.x),  this->y * T(v.y)); };

    template <typename _T>  vex2<T> operator/(_T v)         { return vex2<T>(this->x / T(v),    this->y / T(v)); };
    template <typename _T>  vex2<T> operator/(vex2<_T> v)   { return vex2<T>(this->x / T(v.x),  this->y / T(v.y)); };

    template <typename _T>  bool operator==(_T v)       { return this->x == T(v)    && this->y == T(v); };
    template <typename _T>  bool operator==(vex2<_T> v) { return this->x == T(v.x)  && this->y == T(v.y); };

    template <typename _T>  bool operator!=(_T v)       { return this->x != T(v)    && this->y != T(v); };
    template <typename _T>  bool operator!=(vex2<_T> v) { return this->x != T(v.x)  && this->y != T(v.y); };

    template <typename _T>  bool operator>(_T v)        { return this->x > T(v)     && this->y > T(v); };
    template <typename _T>  bool operator>(vex2<_T> v)  { return this->x > T(v.x)   && this->y > T(v.y); };

    template <typename _T>  bool operator<(_T v)        { return this->x < T(v)     && this->y < T(v); };
    template <typename _T>  bool operator<(vex2<_T> v)  { return this->x < T(v.x)   && this->y < T(v.y); };

    template <typename _T>  bool operator>=(_T v)       { return this->x >= T(v)    && this->y >= T(v); };
    template <typename _T>  bool operator>=(vex2<_T> v) { return this->x >= T(v.x)  && this->y >= T(v.y); };

    template <typename _T>  bool operator<=(_T v)       { return this->x <= T(v)    && this->y <= T(v); };
    template <typename _T>  bool operator<=(vex2<_T> v) { return this->x <= T(v.x)  && this->y <= T(v.y); };

    vex2<T>& normalize(){ *this /= x > y ? x : y; return *this; };
    vex2<T> ceil()      { return vex2<T>(std::ceil(x),  std::ceil(y)); };
    vex2<T> floor()     { return vex2<T>(std::floor(x), std::floor(y)); };
    vex2<T> abs()       { return vex2<T>(std::abs(x),   std::abs(y)); };
    vex2<T> sqrt()      { return vex2<T>(std::sqrt(x),  std::sqrt(y)); };
    vex2<T> cbrt()      { return vex2<T>(std::cbrt(x),  std::cbrt(y)); };
    vex2<T> pow(int v)  { return vex2<T>(std::pow(x,v), std::pow(y,v)); };
    vex2<T> round()     { return vex2<T>(std::round(x), std::round(y)); };
    vex2<T> trunc()     { return vex2<T>(std::trunc(x), std::trunc(y)); };
    vex2<T> exp()       { return vex2<T>(std::exp(x),   std::exp(y)); };
    vex2<T> percent(T v)        { return vex2<T>(x / T(100) * T(v), y / T(100) * T(v)); };
    vex2<T> percent(T v1, T v2) { return vex2<T>(x / T(100) * T(v1), y / T(100) * T(v2)); };

    friend std::ostream& operator<<(std::ostream& os, const vex2<T>& v) { os << v.x << ' ' << v.y; return os; };
};

template <typename T>
struct vex3 {
    T x, y, z;
    vex3() = default;
    vex3(const vex3<T>&) = default;
    template <typename _T> vex3(_T v) { x = y = z = T(v); };
    template <typename _T1, typename _T2> vex3(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };
    template <typename _T1, typename _T2, typename _T3> vex3(_T1 v1, _T2 v2, _T3 v3) { x = T(v1); y = T(v2); z = T(v3); };

    template <typename _T>  vex3<T>& operator=(_T v) { x = y = z = T(v); return *this; };
    template <typename _T>  vex3<T>& operator=(vex3<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); return *this; };

    template <> vex3(std::string v);
    template <> vex3(std::string v1, std::string v2);
    template <> vex3(std::string v1, std::string v2, std::string v3);
    template <> vex3<T>& operator=(std::string v);

    vex3<T>& operator~() { x = T(); y = T(); z = T(); return *this; };
    vex3<T> operator!() { return vex3<T>(z, y, x); };
    vex3<T>& swap() { *this = vex3<T>(z, y, x); return *this; };

    vex3<T> operator()() { return *this; };
    vex3<T> copy() { return *this; };

    T& operator[](int v) { return fmod(v, 3) == 0 ? x : fmod(v, 3) == 1 ? y : z; };

    template <typename _T>  vex3<T> operator%(_T v)         { return vex3<T>(std::rand() % int(v),      std::rand() % int(v)); };
    template <typename _T>  vex3<T> operator%(vex3<_T> v)   { return vex3<T>(std::rand() % int(v.x),    std::rand() % int(v.y), std::rand() % int(v.z)); };

    template <typename _T>  vex3<T>& operator%=(_T v)       { x = std::rand() % int(v);     y = std::rand() % int(v);   return *this; };
    template <typename _T>  vex3<T>& operator%=(vex3<_T> v) { x = std::rand() % int(v.x);   y = std::rand() % int(v.y); z = std::rand() % int(v.z); return *this; };

    template <typename _T>  vex3<T> operator|(vex3<_T> v)   { return std::rand() % 2 == 0 ? vex3<T>(v) : *this; };

    template <typename _T>  vex3<T>& operator|=(vex3<_T> v) { *this = std::rand() % 2 == 0 ? vex3<T>(v) : *this; };

    vex3<T>& operator++() { x++; y++; return *this; };
    vex3<T>& operator--() { x--; y--; return *this; };

    template <typename _T>  vex3<T>& operator+=(_T v)       { x += T(v);    y += T(v);      z += T(v);      return *this; };
    template <typename _T>  vex3<T>& operator+=(vex3<_T> v) { x += T(v.x);  y += T(v.y);    z += T(v.z);    return *this; };

    template <typename _T>  vex3<T>& operator-=(_T v)       { x -= T(v);    y -= T(v);      z -= T(v);      return *this; };
    template <typename _T>  vex3<T>& operator-=(vex3<_T> v) { x -= T(v.x);  y -= T(v.y);    z -= T(v.z);    return *this; };

    template <typename _T>  vex3<T>& operator*=(_T v)       { x *= T(v);    y *= T(v);      z *= T(v);      return *this; };
    template <typename _T>  vex3<T>& operator*=(vex3<_T> v) { x *= T(v.x);  y *= T(v.y);    z *= T(v.z);    return *this; };

    template <typename _T>  vex3<T>& operator/=(_T v)       { x /= T(v);    y /= T(v);      z /= T(v);      return *this; };
    template <typename _T>  vex3<T>& operator/=(vex3<_T> v) { x /= T(v.x);  y /= T(v.y);    z /= T(v.z);    return *this; };

    template <typename _T>  vex3<T> operator+(_T v)         { return vex3<T>(this->x + T(v),    this->y + T(v),     this->z + T(v)); };
    template <typename _T>  vex3<T> operator+(vex3<_T> v)   { return vex3<T>(this->x + T(v.x),  this->y + T(v.y),   this->z + T(v.z)); };

    template <typename _T>  vex3<T> operator-(_T v)         { return vex3<T>(this->x - T(v),    this->y - T(v),     this->z - T(v)); };
    template <typename _T>  vex3<T> operator-(vex3<_T> v)   { return vex3<T>(this->x - T(v.x),  this->y - T(v.y),   this->z - T(v.z)); };

    template <typename _T>  vex3<T> operator*(_T v)         { return vex3<T>(this->x * T(v),    this->y * T(v),     this->z * T(v)); };
    template <typename _T>  vex3<T> operator*(vex3<_T> v)   { return vex3<T>(this->x * T(v.x),  this->y * T(v.y),   this->z * T(v.z)); };

    template <typename _T>  vex3<T> operator/(_T v)         { return vex3<T>(this->x / T(v),    this->y / T(v),     this->z / T(v)); };
    template <typename _T>  vex3<T> operator/(vex3<_T> v)   { return vex3<T>(this->x / T(v.x),  this->y / T(v.y),   this->z / T(v.z)); };

    template <typename _T>  bool operator==(_T v)       { return this->x == T(v)    && this->y == T(v)      && this->z == T(v); };
    template <typename _T>  bool operator==(vex3<_T> v) { return this->x == T(v.x)  && this->y == T(v.y)    && this->z == T(v.z); };

    template <typename _T>  bool operator!=(_T v)       { return this->x != T(v)    && this->y != T(v)      && this->z != T(v); };
    template <typename _T>  bool operator!=(vex3<_T> v) { return this->x != T(v.x)  && this->y != T(v.y)    && this->z != T(v.z); };

    template <typename _T>  bool operator>(_T v)        { return this->x > T(v)     && this->y > T(v)       && this->z > T(v); };
    template <typename _T>  bool operator>(vex3<_T> v)  { return this->x > T(v.x)   && this->y > T(v.y)     && this->z > T(v.z); };

    template <typename _T>  bool operator<(_T v)        { return this->x < T(v)     && this->y < T(v)       && this->z < T(v); };
    template <typename _T>  bool operator<(vex3<_T> v)  { return this->x < T(v.x)   && this->y < T(v.y)     && this->z < T(v.z); };

    template <typename _T>  bool operator>=(_T v)       { return this->x >= T(v)    && this->y >= T(v)      && this->z >= T(v); };
    template <typename _T>  bool operator>=(vex3<_T> v) { return this->x >= T(v.x)  && this->y >= T(v.y)    && this->z >= T(v.z); };

    template <typename _T>  bool operator<=(_T v)       { return this->x <= T(v)    && this->y <= T(v)      && this->z <= T(v); };
    template <typename _T>  bool operator<=(vex3<_T> v) { return this->x <= T(v.x)  && this->y <= T(v.y)    && this->z <= T(v.z); };

    vex3<T>& normalize() { *this /= x > y ? x : y; return *this; };
    vex3<T> ceil()      { return vex3<T>(std::ceil(x)  , std::ceil(y) , std::ceil(z) ); };
    vex3<T> floor()     { return vex3<T>(std::floor(x) , std::floor(y), std::floor(z)); };
    vex3<T> abs()       { return vex3<T>(std::abs(x)   , std::abs(y)  , std::abs(z)  ); };
    vex3<T> sqrt()      { return vex3<T>(std::sqrt(x)  , std::sqrt(y) , std::sqrt(z) ); };
    vex3<T> cbrt()      { return vex3<T>(std::cbrt(x)  , std::cbrt(y) , std::cbrt(z) ); };
    vex3<T> pow(int v)  { return vex3<T>(std::pow(x, v), std::pow(y,v), std::pow(z,v)); };
    vex3<T> round()     { return vex3<T>(std::round(x) , std::round(y), std::round(z)); };
    vex3<T> trunc()     { return vex3<T>(std::trunc(x) , std::trunc(y), std::trunc(z)); };
    vex3<T> exp()       { return vex3<T>(std::exp(x)   , std::exp(y)  , std::exp(z)  ); };
    vex3<T> percent(T v)        { return vex2<T>(x / T(100) * T(v), y / T(100) * T(v)); };
    vex3<T> percent(T v1, T v2) { return vex2<T>(x / T(100) * T(v1), y / T(100) * T(v2)); };

    friend std::ostream& operator<<(std::ostream& os, const vex3<T>& v) { os << v.x << ' ' << v.y << ' ' << v.z; return os; };
};

template<> vex2<int>& vex2<int>::normalize()  = delete;
template<> vex2<int> vex2<int>::ceil()      = delete;
template<> vex2<int> vex2<int>::floor()     = delete;
template<> vex2<int> vex2<int>::round()     = delete;
template<> vex2<int> vex2<int>::trunc()     = delete;

template<> vex3<int>& vex3<int>::normalize()  = delete;
template<> vex3<int> vex3<int>::ceil()      = delete;
template<> vex3<int> vex3<int>::floor()     = delete;
template<> vex3<int> vex3<int>::round()     = delete;
template<> vex3<int> vex3<int>::trunc()     = delete;

template<> template <typename _T> vex2<std::string> vex2<std::string>::operator%(_T v)          = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator%=(_T v)        = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator%(vex2<_T> v)    = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator%=(vex2<_T> v)  = delete;
template<> template <typename _T> bool vex2<std::string>::operator<(_T v)                       = delete;
template<> template <typename _T> bool vex2<std::string>::operator<(vex2<_T> v)                 = delete;
template<> template <typename _T> bool vex2<std::string>::operator>(_T v)                       = delete;
template<> template <typename _T> bool vex2<std::string>::operator>(vex2<_T> v)                 = delete;
template<> template <typename _T> bool vex2<std::string>::operator<=(_T v)                      = delete;
template<> template <typename _T> bool vex2<std::string>::operator<=(vex2<_T> v)                = delete;
template<> template <typename _T> bool vex2<std::string>::operator>=(_T v)                      = delete;
template<> template <typename _T> bool vex2<std::string>::operator>=(vex2<_T> v)                = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator-(_T v)          = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator-(vex2<_T> v)    = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator-=(_T v)        = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator-=(vex2<_T> v)  = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator*(_T v)          = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator*(vex2<_T> v)    = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator*=(_T v)        = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator*=(vex2<_T> v)  = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator/(_T v)          = delete;
template<> template <typename _T> vex2<std::string> vex2<std::string>::operator/(vex2<_T> v)    = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator/=(_T v)        = delete;
template<> template <typename _T> vex2<std::string>& vex2<std::string>::operator/=(vex2<_T> v)  = delete;
template<> vex2<std::string>& vex2<std::string>::operator++()                                   = delete;
template<> vex2<std::string>& vex2<std::string>::operator--()                                   = delete;
template<> vex2<std::string>& vex2<std::string>::normalize()                                    = delete;
template<> vex2<std::string> vex2<std::string>::ceil()                                          = delete;
template<> vex2<std::string> vex2<std::string>::floor()                                         = delete;
template<> vex2<std::string> vex2<std::string>::abs()                                           = delete;
template<> vex2<std::string> vex2<std::string>::sqrt()                                          = delete;
template<> vex2<std::string> vex2<std::string>::cbrt()                                          = delete;
template<> vex2<std::string> vex2<std::string>::pow(int v)                                      = delete;
template<> vex2<std::string> vex2<std::string>::round()                                         = delete;
template<> vex2<std::string> vex2<std::string>::trunc()                                         = delete;
template<> vex2<std::string> vex2<std::string>::exp()                                           = delete;
template<> vex2<std::string> vex2<std::string>::percent(std::string v)                          = delete;
template<> vex2<std::string> vex2<std::string>::percent(std::string v1, std::string v2)         = delete;

template<> template <typename _T> vex3<std::string> vex3<std::string>::operator%(_T v)          = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator%=(_T v)        = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator%(vex3<_T> v)    = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator%=(vex3<_T> v)  = delete;
template<> template <typename _T> bool vex3<std::string>::operator<(_T v)                       = delete;
template<> template <typename _T> bool vex3<std::string>::operator<(vex3<_T> v)                 = delete;
template<> template <typename _T> bool vex3<std::string>::operator>(_T v)                       = delete;
template<> template <typename _T> bool vex3<std::string>::operator>(vex3<_T> v)                 = delete;
template<> template <typename _T> bool vex3<std::string>::operator<=(_T v)                      = delete;
template<> template <typename _T> bool vex3<std::string>::operator<=(vex3<_T> v)                = delete;
template<> template <typename _T> bool vex3<std::string>::operator>=(_T v)                      = delete;
template<> template <typename _T> bool vex3<std::string>::operator>=(vex3<_T> v)                = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator-(_T v)          = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator-(vex3<_T> v)    = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator-=(_T v)        = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator-=(vex3<_T> v)  = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator*(_T v)          = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator*(vex3<_T> v)    = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator*=(_T v)        = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator*=(vex3<_T> v)  = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator/(_T v)          = delete;
template<> template <typename _T> vex3<std::string> vex3<std::string>::operator/(vex3<_T> v)    = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator/=(_T v)        = delete;
template<> template <typename _T> vex3<std::string>& vex3<std::string>::operator/=(vex3<_T> v)  = delete;
template<> vex3<std::string>& vex3<std::string>::operator++()                                   = delete;
template<> vex3<std::string>& vex3<std::string>::operator--()                                   = delete;
template<> vex3<std::string>& vex3<std::string>::normalize()                                    = delete;
template<> vex3<std::string> vex3<std::string>::ceil()                                          = delete;
template<> vex3<std::string> vex3<std::string>::floor()                                         = delete;
template<> vex3<std::string> vex3<std::string>::abs()                                           = delete;
template<> vex3<std::string> vex3<std::string>::sqrt()                                          = delete;
template<> vex3<std::string> vex3<std::string>::cbrt()                                          = delete;
template<> vex3<std::string> vex3<std::string>::pow(int v)                                      = delete;
template<> vex3<std::string> vex3<std::string>::round()                                         = delete;
template<> vex3<std::string> vex3<std::string>::trunc()                                         = delete;
template<> vex3<std::string> vex3<std::string>::exp()                                           = delete;
template<> vex3<std::string> vex3<std::string>::percent(std::string v)                          = delete;
template<> vex3<std::string> vex3<std::string>::percent(std::string v1, std::string v2)         = delete;

#ifdef _XS_STRINX_
template<> template <typename _T> vex2<std::string> vex2<strinx>::operator%(_T v)           = delete;
template<> template <typename _T> vex2<std::string>& vex2<strinx>::operator%=(_T v)         = delete;
template<> template <typename _T> vex2<std::string> vex2<strinx>::operator%(vex2<_T> v)     = delete;
template<> template <typename _T> vex2<std::string>& vex2<strinx>::operator%=(vex2<_T> v)   = delete;
template<> template <typename _T> bool vex2<strinx>::operator<(_T v)                        = delete;
template<> template <typename _T> bool vex2<strinx>::operator<(vex2<_T> v)                  = delete;
template<> template <typename _T> bool vex2<strinx>::operator>(_T v)                        = delete;
template<> template <typename _T> bool vex2<strinx>::operator>(vex2<_T> v)                  = delete;
template<> template <typename _T> bool vex2<strinx>::operator<=(_T v)                       = delete;
template<> template <typename _T> bool vex2<strinx>::operator<=(vex2<_T> v)                 = delete;
template<> template <typename _T> bool vex2<strinx>::operator>=(_T v)                       = delete;
template<> template <typename _T> bool vex2<strinx>::operator>=(vex2<_T> v)                 = delete;
template<> vex2<T>& vex2<strinx>::normalize()                                                   = delete;
template<> vex2<strinx> vex2<strinx>::ceil()                                                = delete;
template<> vex2<strinx> vex2<strinx>::floor()                                               = delete;
template<> vex2<strinx> vex2<strinx>::abs()                                                 = delete;
template<> vex2<strinx> vex2<strinx>::sqrt()                                                = delete;
template<> vex2<strinx> vex2<strinx>::cbrt()                                                = delete;
template<> vex2<strinx> vex2<strinx>::pow()                                                 = delete;
template<> vex2<strinx> vex2<strinx>::round()                                               = delete;
template<> vex2<strinx> vex2<strinx>::trunc()                                               = delete;
template<> vex2<strinx> vex2<strinx>::exp()                                                 = delete;
template<> vex2<strinx> vex2<strinx>::percent(strinx v)                                     = delete;
template<> vex2<strinx> vex2<strinx>::percent(strinx v1, strinx v2)                         = delete;
typedef vex2<strinx> vex2x;

template<> template <typename _T> vex3<std::string> vex3<strinx>::operator%(_T v)           = delete;
template<> template <typename _T> vex3<std::string>& vex3<strinx>::operator%=(_T v)         = delete;
template<> template <typename _T> vex3<std::string> vex3<strinx>::operator%(vex3<_T> v)     = delete;
template<> template <typename _T> vex3<std::string>& vex3<strinx>::operator%=(vex3<_T> v)   = delete;
template<> template <typename _T> bool vex3<strinx>::operator<(_T v)                        = delete;
template<> template <typename _T> bool vex3<strinx>::operator<(vex3<_T> v)                  = delete;
template<> template <typename _T> bool vex3<strinx>::operator>(_T v)                        = delete;
template<> template <typename _T> bool vex3<strinx>::operator>(vex3<_T> v)                  = delete;
template<> template <typename _T> bool vex3<strinx>::operator<=(_T v)                       = delete;
template<> template <typename _T> bool vex3<strinx>::operator<=(vex3<_T> v)                 = delete;
template<> template <typename _T> bool vex3<strinx>::operator>=(_T v)                       = delete;
template<> template <typename _T> bool vex3<strinx>::operator>=(vex3<_T> v)                 = delete;
template<> vex3<T>& vex3<strinx>::normalize()                                               = delete;
template<> vex3<strinx> vex3<strinx>::ceil()                                                = delete;
template<> vex3<strinx> vex3<strinx>::floor()                                               = delete;
template<> vex3<strinx> vex3<strinx>::abs()                                                 = delete;
template<> vex3<strinx> vex3<strinx>::sqrt()                                                = delete;
template<> vex3<strinx> vex3<strinx>::cbrt()                                                = delete;
template<> vex3<strinx> vex3<strinx>::pow()                                                 = delete;
template<> vex3<strinx> vex3<strinx>::round()                                               = delete;
template<> vex3<strinx> vex3<strinx>::trunc()                                               = delete;
template<> vex3<strinx> vex3<strinx>::exp()                                                 = delete;
template<> vex3<strinx> vex3<strinx>::percent(strinx v)                                     = delete;
template<> vex3<strinx> vex3<strinx>::percent(strinx v1, strinx v2)                         = delete;
typedef vex3<strinx> vex3x;
#endif

template<> template<> vex2<float>::vex2(std::string v)  { x = y = std::atof(v.c_str()); };
template<> template<> vex2<int>::vex2(std::string v)    { x = y = std::atoi(v.c_str()); };
template<> template<> vex2<double>::vex2(std::string v) { x = y = std::atof(v.c_str()); };

template<> template<> vex2<float>::vex2(std::string v1, std::string v2) { x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); };
template<> template<> vex2<int>::vex2(std::string v1, std::string v2)   { x = std::atof(v1.c_str()); y = std::atoi(v2.c_str()); };
template<> template<> vex2<double>::vex2(std::string v1, std::string v2){ x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); };

template<> template<> vex2<float>& vex2<float>::operator=(std::string v)    { x = y = std::atof(v.c_str()); return *this; };
template<> template<> vex2<int>& vex2<int>::operator=(std::string v)        { x = y = std::atoi(v.c_str()); return *this; };
template<> template<> vex2<double>& vex2<double>::operator=(std::string v)  { x = y = std::atof(v.c_str()); return *this; };


template<> template<> vex3<float>::vex3(std::string v)  { x = y = z = std::atof(v.c_str()); };
template<> template<> vex3<int>::vex3(std::string v)    { x = y = z = std::atoi(v.c_str()); };
template<> template<> vex3<double>::vex3(std::string v) { x = y = z = std::atof(v.c_str()); };

template<> template<> vex3<float>::vex3(std::string v1, std::string v2) { x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); };
template<> template<> vex3<int>::vex3(std::string v1, std::string v2)   { x = std::atof(v1.c_str()); y = std::atoi(v2.c_str()); };
template<> template<> vex3<double>::vex3(std::string v1, std::string v2){ x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); };

template<> template<> vex3<float>::vex3(std::string v1, std::string v2, std::string v3) { x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); z = std::atof(v3.c_str()); };
template<> template<> vex3<int>::vex3(std::string v1, std::string v2, std::string v3)   { x = std::atof(v1.c_str()); y = std::atoi(v2.c_str()); z = std::atoi(v3.c_str()); };
template<> template<> vex3<double>::vex3(std::string v1, std::string v2, std::string v3){ x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); z = std::atof(v3.c_str()); };

template<> template<> vex3<float>& vex3<float>::operator=(std::string v)    { x = y = z = std::atof(v.c_str()); return *this; };
template<> template<> vex3<int>& vex3<int>::operator=(std::string v)        { x = y = z = std::atoi(v.c_str()); return *this; };
template<> template<> vex3<double>& vex3<double>::operator=(std::string v)  { x = y = z = std::atof(v.c_str()); return *this; };

typedef vex2<float>         vex2f;
typedef vex2<int>           vex2i;
typedef vex2<double>        vex2d;
typedef vex2<std::string>   vex2s;

typedef vex3<float>         vex3f;
typedef vex3<int>           vex3i;
typedef vex3<double>        vex3d;
typedef vex3<std::string>   vex3s;
