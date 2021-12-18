#define _XS_VEX2_
#include <string>
#include <sstream>
template <typename T> struct vex2;
template <typename T> struct vex3;
template <typename T> struct vex4;

template <typename T>
struct vex2 {
    T x, y;
    operator std::string() const { return (std::to_string(x) + ' ' + std::to_string(y)); };
    operator char* () const { return _strdup((std::to_string(x) + ' ' + std::to_string(y)).c_str()); };
#ifdef _XS_STRINX_
    operator strinx() const { return strinx(x) + ' ' + strinx(y); };
#endif
#ifdef __VEX2GLM_FUNCS__ // in GLM-Vex.hpp
    __VEX2GLM_FUNCS__
#endif
#ifdef __VEX2IM_FUNCS__ // in ImGui-Vex.hpp
        __VEX2IM_FUNCS__
#endif
    T* arr() const { return new T[2]{ x, y }; };
    std::string str(const char* sep = " ", const char* end = "") const { return std::to_string(x) + sep + std::to_string(y) + end; };
    vex2() = default;
    vex2(const vex2<T>&) = default;
    template <typename _T> vex2(_T v) { x = y = T(v); };
    template <typename _T> vex2(vex2<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T> vex2(vex3<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T> vex2(vex4<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T1, typename _T2> vex2(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };

    template <typename _T>  vex2<T>& operator=(_T v) { x = y = T(v);             return *this; };
    template <typename _T>  vex2<T>& operator=(vex2<_T> v) { x = T(v.x); y = T(v.y);   return *this; };

    template <> vex2(std::string v);
    template <> vex2(std::string v1, std::string v2);
    template <> vex2<T>& operator=(std::string v);

    bool isEmpty() const { return (x && y) ? false : true; };
    operator bool() const { return isEmpty(); };

    vex2<T>& operator~() { x = T(); y = T(); return *this; };
    bool operator!() const { return !isEmpty(); };
    vex2<T>& swap() { *this = vex2<T>(y, x); return *this; };
    vex2<T> swap() const { *this = vex2<T>(y, x); return *this; };
    template <typename _T>
    vex2<T>& operator,(vex2<_T>& v) {
        const vex2<T> c = *this;
        *this = v;
        v = c;
        return *this;
    };

    vex2<T> operator()() const { return *this; };
    vex2<T> copy() const { return *this; };

    T& operator[](const int& v) { return (v % 2) == 0 ? x : y; };
    T operator[](const int& v) const { return (v % 2) == 0 ? x : y; };

    template <typename _T>  vex2<T> operator%(_T v) const { return vex2<T>(std::rand() % int(v), std::rand() % int(v)); };
    template <typename _T>  vex2<T> operator%(vex2<_T> v) const { return vex2<T>(std::rand() % int(v.x), std::rand() % int(v.y)); };

    template <typename _T>  vex2<T>& operator%=(_T v) { x = std::rand() % int(v);     y = std::rand() % int(v);   return *this; };
    template <typename _T>  vex2<T>& operator%=(vex2<_T> v) { x = std::rand() % int(v.x);   y = std::rand() % int(v.y); return *this; };

    template <typename _T>  vex2<T> operator|(_T v) const { return std::rand() % 2 == 0 ? vex2<T>(v) : *this; };
    template <typename _T>  vex2<T> operator|(vex2<_T> v) const { return std::rand() % 2 == 0 ? vex2<T>(v) : *this; };
    template <typename _T>  vex2<T>& operator|=(vex2<_T> v) { *this = std::rand() % 2 == 0 ? vex2<T>(v) : *this; };

    template <typename _T>  vex2<T> operator|(vex3<_T> v) const { return std::rand() % 2 == 0 ? vex2<T>(v) : *this; };
    template <typename _T>  vex2<T>& operator|=(vex3<_T> v) { *this = std::rand() % 2 == 0 ? vex2<T>(v) : *this; };

    template <typename _T>  vex2<T> operator|(vex4<_T> v) const { return std::rand() % 2 == 0 ? vex2<T>(v) : *this; };
    template <typename _T>  vex2<T>& operator|=(vex4<_T> v) { *this = std::rand() % 2 == 0 ? vex2<T>(v) : *this; };

    vex2<T>& operator++() { x++; y++; return *this; };
    vex2<T>& operator--() { x--; y--; return *this; };

    template <typename _T>  vex2<T>& operator+=(_T v) { x += T(v);    y += T(v);      return *this; };
    template <typename _T>  vex2<T>& operator+=(vex2<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };

    template <typename _T>  vex2<T>& operator-=(_T v) { x -= T(v);    y -= T(v);      return *this; };
    template <typename _T>  vex2<T>& operator-=(vex2<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };

    template <typename _T>  vex2<T>& operator*=(_T v) { x *= T(v);    y *= T(v);      return *this; };
    template <typename _T>  vex2<T>& operator*=(vex2<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };

    template <typename _T>  vex2<T>& operator/=(_T v) { x /= T(v);    y /= T(v);      return *this; };
    template <typename _T>  vex2<T>& operator/=(vex2<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };

    template <typename _T>  vex2<T> operator+(_T v) const { return vex2<T>(this->x + T(v), this->y + T(v)); };
    template <typename _T>  vex2<T> operator+(vex2<_T> v) const { return vex2<T>(this->x + T(v.x), this->y + T(v.y)); };

    template <typename _T>  vex2<T> operator-(_T v) const { return vex2<T>(this->x - T(v), this->y - T(v)); };
    template <typename _T>  vex2<T> operator-(vex2<_T> v) const { return vex2<T>(this->x - T(v.x), this->y - T(v.y)); };

    template <typename _T>  vex2<T> operator*(_T v) const { return vex2<T>(this->x * T(v), this->y * T(v)); };
    template <typename _T>  vex2<T> operator*(vex2<_T> v) const { return vex2<T>(this->x * T(v.x), this->y * T(v.y)); };

    template <typename _T>  vex2<T> operator/(_T v) const { return vex2<T>(this->x / T(v), this->y / T(v)); };
    template <typename _T>  vex2<T> operator/(vex2<_T> v) const { return vex2<T>(this->x / T(v.x), this->y / T(v.y)); };

    template <typename _T>  vex2<T> operator^(_T v) const { return vex2<T>(std::pow(this->x, T(v)), std::pow(this->y / T(v))); };
    template <typename _T>  vex2<T> operator^(vex2<_T> v) const { return vex2<T>(std::pow(this->x / T(v.x)), std::pow(this->y / T(v.y))); };

    template <typename _T>  bool operator==(_T v) const { return this->x == T(v) && this->y == T(v); };
    template <typename _T>  bool operator==(vex2<_T> v) const { return this->x == T(v.x) && this->y == T(v.y); };

    template <typename _T>  bool operator!=(_T v) const { return this->x != T(v) && this->y != T(v); };
    template <typename _T>  bool operator!=(vex2<_T> v) const { return this->x != T(v.x) && this->y != T(v.y); };

    template <typename _T>  bool operator>(_T v) const { return this->x > T(v) && this->y > T(v); };
    template <typename _T>  bool operator>(vex2<_T> v) const { return this->x > T(v.x) && this->y > T(v.y); };

    template <typename _T>  bool operator<(_T v) const { return this->x < T(v) && this->y < T(v); };
    template <typename _T>  bool operator<(vex2<_T> v) const { return this->x < T(v.x) && this->y < T(v.y); };

    template <typename _T>  bool operator>=(_T v) const { return this->x >= T(v) && this->y >= T(v); };
    template <typename _T>  bool operator>=(vex2<_T> v) const { return this->x >= T(v.x) && this->y >= T(v.y); };

    template <typename _T>  bool operator<=(_T v) const { return this->x <= T(v) && this->y <= T(v); };
    template <typename _T>  bool operator<=(vex2<_T> v) const { return this->x <= T(v.x) && this->y <= T(v.y); };

    template <typename _T> vex2<T>& operator<<(_T v) const { x = v.x; y = v.y; return *this; };

    vex2<T>& normalize() { *this /= (x > y ? x : y); return *this; };
    vex2<T> normalize() const { return (*this) / (x > y ? x : y); };

    template <typename _T> vex2<T>& operator=(vex3<_T> v) { x = T(v.x);  y = T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator+=(vex3<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator-=(vex3<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator*=(vex3<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator/=(vex3<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };
    template <typename _T> vex2<T> operator+(vex3<_T> v) const { return vex2<T>(x + T(v.x), y + T(v.y)); };
    template <typename _T> vex2<T> operator-(vex3<_T> v) const { return vex2<T>(x - T(v.x), y - T(v.y)); };
    template <typename _T> vex2<T> operator*(vex3<_T> v) const { return vex2<T>(x * T(v.x), y * T(v.y)); };
    template <typename _T> vex2<T> operator/(vex3<_T> v) const { return vex2<T>(x / T(v.x), y / T(v.y)); };
    template <typename _T>  bool operator==(vex3<_T> v) const { return this->x == T(v.x) && this->y == T(v.y); };
    template <typename _T>  bool operator!=(vex3<_T> v) const { return this->x != T(v.x) && this->y != T(v.y); };
    template <typename _T>  bool operator>(vex3<_T> v)  const { return this->x > T(v.x) && this->y > T(v.y); };
    template <typename _T>  bool operator<(vex3<_T> v)  const { return this->x < T(v.x) && this->y < T(v.y); };
    template <typename _T>  bool operator>=(vex3<_T> v) const { return this->x >= T(v.x) && this->y >= T(v.y); };
    template <typename _T>  bool operator<=(vex3<_T> v) const { return this->x <= T(v.x) && this->y <= T(v.y); };

    template <typename _T> vex2<T>& operator=(vex4<_T> v) { x = T(v.x);  y = T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator+=(vex4<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator-=(vex4<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator*=(vex4<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator/=(vex4<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };
    template <typename _T> vex2<T>& operator+(vex4<_T> v)  const { return vex2<T>(x + T(v.x), y + T(v.y)); };
    template <typename _T> vex2<T>& operator-(vex4<_T> v)  const { return vex2<T>(x - T(v.x), y - T(v.y)); };
    template <typename _T> vex2<T>& operator*(vex4<_T> v)  const { return vex2<T>(x * T(v.x), y * T(v.y)); };
    template <typename _T> vex2<T>& operator/(vex4<_T> v)  const { return vex2<T>(x / T(v.x), y / T(v.y)); };
    template <typename _T>  bool operator==(vex4<_T> v)  const { return this->x == T(v.x) && this->y == T(v.y); };
    template <typename _T>  bool operator!=(vex4<_T> v)  const { return this->x != T(v.x) && this->y != T(v.y); };
    template <typename _T>  bool operator>(vex4<_T> v)   const { return this->x > T(v.x) && this->y > T(v.y); };
    template <typename _T>  bool operator<(vex4<_T> v)   const { return this->x < T(v.x) && this->y < T(v.y); };
    template <typename _T>  bool operator>=(vex4<_T> v)  const { return this->x >= T(v.x) && this->y >= T(v.y); };
    template <typename _T>  bool operator<=(vex4<_T> v)  const { return this->x <= T(v.x) && this->y <= T(v.y); };

    friend std::ostream& operator<<(std::ostream& os, const vex2<T>& v) { os << v.x << ' ' << v.y; return os; };
    friend std::istream& operator>>(std::istream& is, vex2<T>& v) { std::cout << "x: "; is >> v.x; std::cout << "y: "; is >> v.y; return is; };
};

template <typename T>
struct vex3 {
    T x, y, z;
    operator std::string() const { return (std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z)); };
    operator char* () const { return _strdup((std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z)).c_str()); };
#ifdef _XS_STRINX_
    operator strinx() const { return strinx(x) + ' ' + strinx(y) + ' ' + strinx(z); };
#endif
#ifdef __VEX3GLM_FUNCS__
    __VEX3GLM_FUNCS__
#endif
#ifdef __VEX3IM_FUNCS__
        __VEX3IM_FUNCS__
#endif
        T* arr() const { return new T[3]{ x, y, z }; };
    std::string str(const char* sep = " ", const char* end = "") const { return std::to_string(x) + sep + std::to_string(y) + sep + std::to_string(z) + end; };
    vex3() = default;
    vex3(const vex3<T>&) = default;
    template <typename _T> vex3(_T v) { x = y = z = T(v); };
    template <typename _T> vex3(vex2<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T> vex3(vex3<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); };
    template <typename _T> vex3(vex4<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); };
    template <typename _T1, typename _T2> vex3(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };
    template <typename _T1, typename _T2, typename _T3> vex3(_T1 v1, _T2 v2, _T3 v3) { x = T(v1); y = T(v2); z = T(v3); };

    template <typename _T1, typename _T2> vex3(vex2<_T1> v1_2, _T2 v3) { x = T(v1_2.x); y = T(v1_2.y); z = T(v3); };
    template <typename _T1, typename _T2> vex3(_T1 v1, vex2<_T2> v2_3) { x = T(v1); y = T(v2_3.x); z = T(v2_3.y); };

    template <typename _T>  vex3<T>& operator=(_T v) { x = y = z = T(v); return *this; };
    template <typename _T>  vex3<T>& operator=(vex3<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); return *this; };

    template <> vex3(std::string v);
    template <> vex3(std::string v1, std::string v2);
    template <> vex3(std::string v1, std::string v2, std::string v3);
    template <> vex3<T>& operator=(std::string v);

    bool isEmpty()  const { return (x && y && z) ? false : true; };
    operator bool() const { return isEmpty(); };

    vex3<T>& operator~() { x = T(); y = T(); z = T(); return *this; };
    bool operator!() const { return !isEmpty(); };
    vex3<T>& swap() { *this = vex3<T>(z, y, x); return *this; };
    vex3<T> swap() const { return vex3<T>(z, y, x); };

    template <typename _T>
    vex3<T>& operator,(vex3<_T>& v) {
        const vex3<T> c = *this;
        *this = v;
        v = c;
        return *this;
    };

    vex3<T> operator()() const { return *this; };
    vex3<T> copy() const { return *this; };

    T& operator[](const int& v) { return (v % 3) == 0 ? x : (v % 3) == 1 ? y : z; };
    T operator[](const int& v) const { return (v % 3) == 0 ? x : (v % 3) == 1 ? y : z; };

    template <typename _T>  vex3<T> operator%(_T v) const { return vex3<T>(std::rand() % int(v), std::rand() % int(v), std::rand() % int(v)); };
    template <typename _T>  vex3<T> operator%(vex3<_T> v) const { return vex3<T>(std::rand() % int(v.x), std::rand() % int(v.y), std::rand() % int(v.z)); };

    template <typename _T>  vex3<T>& operator%=(_T v) { x = std::rand() % int(v);     y = std::rand() % int(v);   z = std::rand() % int(v);   return *this; };
    template <typename _T>  vex3<T>& operator%=(vex3<_T> v) { x = std::rand() % int(v.x);   y = std::rand() % int(v.y); z = std::rand() % int(v.z); return *this; };

    template <typename _T>  vex3<T> operator|(_T v) const { return std::rand() % 2 == 0 ? vex3<T>(v) : *this; };
    template <typename _T>  vex3<T> operator|(vex3<_T> v) const { return std::rand() % 2 == 0 ? vex3<T>(v) : *this; };
    template <typename _T>  vex3<T>& operator|=(vex3<_T> v) { *this = std::rand() % 2 == 0 ? vex3<T>(v) : *this; };

    template <typename _T>  vex3<T> operator|(vex2<_T> v) const { return std::rand() % 2 == 0 ? vex3<T>(v) : *this; };
    template <typename _T>  vex3<T>& operator|=(vex2<_T> v) { *this = std::rand() % 2 == 0 ? vex3<T>(v) : *this; };

    template <typename _T>  vex3<T> operator|(vex4<_T> v) const { return std::rand() % 2 == 0 ? vex3<T>(v) : *this; };
    template <typename _T>  vex3<T>& operator|=(vex4<_T> v) { *this = std::rand() % 2 == 0 ? vex3<T>(v) : *this; };

    vex3<T>& operator++() { x++; y++; z++; return *this; };
    vex3<T>& operator--() { x--; y--; z--; return *this; };

    template <typename _T>  vex3<T>& operator+=(_T v) { x += T(v);    y += T(v);      z += T(v);      return *this; };
    template <typename _T>  vex3<T>& operator+=(vex3<_T> v) { x += T(v.x);  y += T(v.y);    z += T(v.z);    return *this; };

    template <typename _T>  vex3<T>& operator-=(_T v) { x -= T(v);    y -= T(v);      z -= T(v);      return *this; };
    template <typename _T>  vex3<T>& operator-=(vex3<_T> v) { x -= T(v.x);  y -= T(v.y);    z -= T(v.z);    return *this; };

    template <typename _T>  vex3<T>& operator*=(_T v) { x *= T(v);    y *= T(v);      z *= T(v);      return *this; };
    template <typename _T>  vex3<T>& operator*=(vex3<_T> v) { x *= T(v.x);  y *= T(v.y);    z *= T(v.z);    return *this; };

    template <typename _T>  vex3<T>& operator/=(_T v) { x /= T(v);    y /= T(v);      z /= T(v);      return *this; };
    template <typename _T>  vex3<T>& operator/=(vex3<_T> v) { x /= T(v.x);  y /= T(v.y);    z /= T(v.z);    return *this; };

    template <typename _T>  vex3<T> operator+(_T v) const { return vex3<T>(this->x + T(v), this->y + T(v), this->z + T(v)); };
    template <typename _T>  vex3<T> operator+(vex3<_T> v) const { return vex3<T>(this->x + T(v.x), this->y + T(v.y), this->z + T(v.z)); };

    template <typename _T>  vex3<T> operator-(_T v) const { return vex3<T>(this->x - T(v), this->y - T(v), this->z - T(v)); };
    template <typename _T>  vex3<T> operator-(vex3<_T> v) const { return vex3<T>(this->x - T(v.x), this->y - T(v.y), this->z - T(v.z)); };

    template <typename _T>  vex3<T> operator*(_T v) const { return vex3<T>(this->x * T(v), this->y * T(v), this->z * T(v)); };
    template <typename _T>  vex3<T> operator*(vex3<_T> v) const { return vex3<T>(this->x * T(v.x), this->y * T(v.y), this->z * T(v.z)); };

    template <typename _T>  vex3<T> operator/(_T v) const { return vex3<T>(this->x / T(v), this->y / T(v), this->z / T(v)); };
    template <typename _T>  vex3<T> operator/(vex3<_T> v) const { return vex3<T>(this->x / T(v.x), this->y / T(v.y), this->z / T(v.z)); };

    template <typename _T>  bool operator==(_T v) const { return this->x == T(v) && this->y == T(v) && this->z == T(v); };
    template <typename _T>  bool operator==(vex3<_T> v) const { return this->x == T(v.x) && this->y == T(v.y) && this->z == T(v.z); };

    template <typename _T>  bool operator!=(_T v) const { return this->x != T(v) && this->y != T(v) && this->z != T(v); };
    template <typename _T>  bool operator!=(vex3<_T> v) const { return this->x != T(v.x) && this->y != T(v.y) && this->z != T(v.z); };

    template <typename _T>  bool operator>(_T v) const { return this->x > T(v) && this->y > T(v) && this->z > T(v); };
    template <typename _T>  bool operator>(vex3<_T> v) const { return this->x > T(v.x) && this->y > T(v.y) && this->z > T(v.z); };

    template <typename _T>  bool operator<(_T v) const { return this->x < T(v) && this->y < T(v) && this->z < T(v); };
    template <typename _T>  bool operator<(vex3<_T> v) const { return this->x < T(v.x) && this->y < T(v.y) && this->z < T(v.z); };

    template <typename _T>  bool operator>=(_T v) const { return this->x >= T(v) && this->y >= T(v) && this->z >= T(v); };
    template <typename _T>  bool operator>=(vex3<_T> v) const { return this->x >= T(v.x) && this->y >= T(v.y) && this->z >= T(v.z); };

    template <typename _T>  bool operator<=(_T v) const { return this->x <= T(v) && this->y <= T(v) && this->z <= T(v); };
    template <typename _T>  bool operator<=(vex3<_T> v) const { return this->x <= T(v.x) && this->y <= T(v.y) && this->z <= T(v.z); };

    template <typename _T> vex3<T>& operator<<(_T v) const { x = v.x; y = v.y; z = v.z; return *this; };

    vex3<T>& normalize() { *this /= x > y ? x : y > z ? y : z; return *this; };
    vex3<T> normalize() const { return (*this) / (x > y ? x : y > z ? y : z); };

    template <typename _T> vex3<T>& operator=(vex2<_T> v) { x = T(v.x);  y = T(v.y);    return *this; };
    template <typename _T> vex3<T>& operator+=(vex2<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };
    template <typename _T> vex3<T>& operator-=(vex2<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };
    template <typename _T> vex3<T>& operator*=(vex2<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };
    template <typename _T> vex3<T>& operator/=(vex2<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };
    template <typename _T> vex3<T> operator+(vex2<_T> v) const { return vex3<T>(x + T(v.x), y + T(v.y)); };
    template <typename _T> vex3<T> operator-(vex2<_T> v) const { return vex3<T>(x - T(v.x), y - T(v.y)); };
    template <typename _T> vex3<T> operator*(vex2<_T> v) const { return vex3<T>(x * T(v.x), y * T(v.y)); };
    template <typename _T> vex3<T> operator/(vex2<_T> v) const { return vex3<T>(x / T(v.x), y / T(v.y)); };
    template <typename _T>  bool operator==(vex2<_T> v) const { return this->x == T(v.x) && this->y == T(v.y); };
    template <typename _T>  bool operator!=(vex2<_T> v) const { return this->x != T(v.x) && this->y != T(v.y); };
    template <typename _T>  bool operator>(vex2<_T> v)  const { return this->x > T(v.x) && this->y > T(v.y); };
    template <typename _T>  bool operator<(vex2<_T> v)  const { return this->x < T(v.x) && this->y < T(v.y); };
    template <typename _T>  bool operator>=(vex2<_T> v) const { return this->x >= T(v.x) && this->y >= T(v.y); };
    template <typename _T>  bool operator<=(vex2<_T> v) const { return this->x <= T(v.x) && this->y <= T(v.y); };

    template <typename _T> vex3<T>& operator=(vex4<_T> v) { x = T(v.x);  y = T(v.y);  z = T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator+=(vex4<_T> v) { x += T(v.x);  y += T(v.y);  z += T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator-=(vex4<_T> v) { x -= T(v.x);  y -= T(v.y);  z -= T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator*=(vex4<_T> v) { x *= T(v.x);  y *= T(v.y);  z *= T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator/=(vex4<_T> v) { x /= T(v.x);  y /= T(v.y);  z /= T(v.z);  return *this; };
    template <typename _T> vex3<T>& operator+(vex4<_T> v) const { return vex3<T>(x + T(v.x), y + T(v.y), z + T(v.z)); };
    template <typename _T> vex3<T>& operator-(vex4<_T> v) const { return vex3<T>(x - T(v.x), y - T(v.y), z - T(v.z)); };
    template <typename _T> vex3<T>& operator*(vex4<_T> v) const { return vex3<T>(x * T(v.x), y * T(v.y), z * T(v.z)); };
    template <typename _T> vex3<T>& operator/(vex4<_T> v) const { return vex3<T>(x / T(v.x), y / T(v.y), z / T(v.z)); };
    template <typename _T>  bool operator==(vex4<_T> v) const { return this->x == T(v.x) && this->y == T(v.y) && this->z == T(v.z); };
    template <typename _T>  bool operator!=(vex4<_T> v) const { return this->x != T(v.x) && this->y != T(v.y) && this->z != T(v.z); };
    template <typename _T>  bool operator>(vex4<_T> v)  const { return this->x > T(v.x) && this->y > T(v.y) && this->z > T(v.z); };
    template <typename _T>  bool operator<(vex4<_T> v)  const { return this->x < T(v.x) && this->y < T(v.y) && this->z < T(v.z); };
    template <typename _T>  bool operator>=(vex4<_T> v) const { return this->x >= T(v.x) && this->y >= T(v.y) && this->z >= T(v.z); };
    template <typename _T>  bool operator<=(vex4<_T> v) const { return this->x <= T(v.x) && this->y <= T(v.y) && this->z <= T(v.z); };

    friend std::ostream& operator<<(std::ostream& os, const vex3<T>& v) { os << v.x << ' ' << v.y << ' ' << v.z; return os; };
    friend std::istream& operator>>(std::istream& is, vex3<T>& v) { std::cout << "x: "; is >> v.x; std::cout << "y: "; is >> v.y; std::cout << "z: "; is >> v.z; return is; };
};

template <typename T>
struct vex4 {
    T x, y, z, w;
    operator std::string() const { return (std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z) + ' ' + std::to_string(w)); };
    operator char* () const { return _strdup((std::to_string(x) + ' ' + std::to_string(y) + ' ' + std::to_string(z) + ' ' + std::to_string(w)).c_str()); };
#ifdef _XS_STRINX_
    operator strinx() const { return strinx(x) + ' ' + strinx(y) + ' ' + strinx(z) + ' ' + strinx(w); };
#endif
#ifdef __VEX4GLM_FUNCS__
    __VEX4GLM_FUNCS__
#endif
#ifdef __VEX4IM_FUNCS__
        __VEX4IM_FUNCS__
#endif
        T* arr() { return new T[4]{ x, y, z, w }; };
    std::string str(const char* sep = " ", const char* end = "") const { return std::to_string(x) + sep + std::to_string(y) + sep + std::to_string(z) + sep + std::to_string(w) + end; };
    vex4() = default;
    vex4(const vex4<T>&) = default;
    template <typename _T> vex4(_T v) { x = y = z = w = T(v); };
    template <typename _T> vex4(vex2<_T> v) { x = T(v.x); y = T(v.y); };
    template <typename _T> vex4(vex3<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); };
    template <typename _T> vex4(vex4<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); w = T(v.w); };
    template <typename _T1, typename _T2> vex4(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };
    template <typename _T1, typename _T2, typename _T3> vex4(_T1 v1, _T2 v2, _T3 v3) { x = T(v1); y = T(v2); z = T(v3); };
    template <typename _T1, typename _T2, typename _T3, typename _T4> vex4(_T1 v1, _T2 v2, _T3 v3, _T4 v4) { x = T(v1); y = T(v2); z = T(v3); w = T(v4); };

    template <typename _T1, typename _T2> vex4(_T1 v1, vex3<_T2> v2_3_4) { x = T(v1); y = T(v2_3_4.x); z = T(v2_3_4.y); w = T(v2_3_4.z); };
    template <typename _T1, typename _T2> vex4(vex3<_T1> v1_2_3, _T2 v4) { x = T(v1_2_3.x); y = T(v1_2_3.y); z = T(v1_2_3.z); w = T(v4); };

    template <typename _T1, typename _T2> vex4(vex2<_T1> v1_2, _T2 v3) { x = T(v1_2.x); y = T(v1_2.y); z = T(v3); };
    template <typename _T1, typename _T2> vex4(_T1 v1, vex2<_T2> v2_3) { x = T(v1); y = T(v2_3.x); z = T(v2_3.y); };
    template <typename _T1, typename _T2> vex4(vex2<_T1> v1_2, vex2<_T2> v3_4) { x = T(v1_2.x); y = T(v1_2.y); z = T(v3_4.x); w = T(v3_4.y); };
    template <typename _T1, typename _T2, typename _T3> vex4(vex2<_T1> v1_2, _T2 v3, _T3 v4) { x = T(v1_2.x); y = T(v1_2.y); z = T(v3); w = T(v4); };
    template <typename _T1, typename _T2, typename _T3> vex4(_T1 v1, vex2<_T2> v2_3, _T3 v4) { x = T(v1); y = T(v2_3.x); z = T(v2_3.y); w = T(v4); };
    template <typename _T1, typename _T2, typename _T3> vex4(_T1 v1, _T2 v2, vex2<_T3> v3_4) { x = T(v1); y = T(v2); z = T(v3_4.x); w = T(v3_4.y); };

    template <typename _T>  vex4<T>& operator=(_T v) { x = y = z = T(v); return *this; };
    template <typename _T>  vex4<T>& operator=(vex4<_T> v) { x = T(v.x); y = T(v.y); z = T(v.z); w = T(v.w); return *this; };

    template <> vex4(std::string v);
    template <> vex4(std::string v1, std::string v2);
    template <> vex4(std::string v1, std::string v2, std::string v3);
    template <> vex4(std::string v1, std::string v2, std::string v3, std::string v4);
    template <> vex4<T>& operator=(std::string v);

    bool isEmpty()  const { return (x && y && z && w) ? false : true; };
    operator bool() const { return isEmpty(); };

    vex4<T>& operator~() { x = T(); y = T(); z = T(); w = T(); return *this; };
    bool operator!() const { return !isEmpty(); };
    vex4<T>& swap() { *this = vex4<T>(w, z, y, x); return *this; };
    vex4<T> swap() const { return vex4<T>(w, z, y, x); };

    template <typename _T>
    vex4<T>& operator,(vex4<_T>& v) {
        const vex4<T> c = *this;
        *this = v;
        v = c;
        return *this;
    };

    vex4<T> operator()() const { return *this; };
    vex4<T> copy() const { return *this; };

    T& operator[](const int& v) { return (v % 4) == 0 ? x : (v % 4) == 1 ? y : (v % 4) == 2 ? z : w; };
    T operator[](const int& v) const { return (v % 4) == 0 ? x : (v % 4) == 1 ? y : (v % 4) == 2 ? z : w; };

    template <typename _T>  vex4<T> operator%(_T v) const { return vex4<T>(std::rand() % int(v), std::rand() % int(v), std::rand() % int(v), std::rand() % int(v)); };
    template <typename _T>  vex4<T> operator%(vex4<_T> v) const { return vex4<T>(std::rand() % int(v.x), std::rand() % int(v.y), std::rand() % int(v.z), std::rand() % int(v.w)); };

    template <typename _T>  vex4<T>& operator%=(_T v) { x = std::rand() % int(v);     y = std::rand() % int(v);   z = std::rand() % int(v);   w = std::rand() % int(v);  return *this; };
    template <typename _T>  vex4<T>& operator%=(vex4<_T> v) { x = std::rand() % int(v.x);   y = std::rand() % int(v.y); z = std::rand() % int(v.z); w = std::rand() % int(v.w); return *this; };

    template <typename _T>  vex4<T> operator|(_T v) const { return std::rand() % 2 == 0 ? vex4<T>(v) : *this; };
    template <typename _T>  vex4<T> operator|(vex4<_T> v) const { return std::rand() % 2 == 0 ? vex4<T>(v) : *this; };
    template <typename _T>  vex4<T>& operator|=(vex4<_T> v) { *this = std::rand() % 2 == 0 ? vex4<T>(v) : *this; };

    template <typename _T>  vex4<T> operator|(vex3<_T> v) const { return std::rand() % 2 == 0 ? vex4<T>(v) : *this; };
    template <typename _T>  vex4<T>& operator|=(vex3<_T> v) { *this = std::rand() % 2 == 0 ? vex4<T>(v) : *this; };

    template <typename _T>  vex4<T> operator|(vex2<_T> v) const { return std::rand() % 2 == 0 ? vex4<T>(v) : *this; };
    template <typename _T>  vex4<T>& operator|=(vex2<_T> v) { *this = std::rand() % 2 == 0 ? vex4<T>(v) : *this; };

    vex4<T>& operator++() { x++; y++; z++; w++; return *this; };
    vex4<T>& operator--() { x--; y--; z--; w--; return *this; };

    template <typename _T>  vex4<T>& operator+=(_T v) { x += T(v);    y += T(v);      z += T(v);    w += T(v);    return *this; };
    template <typename _T>  vex4<T>& operator+=(vex4<_T> v) { x += T(v.x);  y += T(v.y);    z += T(v.z);  w += T(v.w);  return *this; };

    template <typename _T>  vex4<T>& operator-=(_T v) { x -= T(v);    y -= T(v);      z -= T(v);   w -= T(v);     return *this; };
    template <typename _T>  vex4<T>& operator-=(vex4<_T> v) { x -= T(v.x);  y -= T(v.y);    z -= T(v.z); w -= T(v.w);   return *this; };

    template <typename _T>  vex4<T>& operator*=(_T v) { x *= T(v);    y *= T(v);      z *= T(v);   w *= T(v);     return *this; };
    template <typename _T>  vex4<T>& operator*=(vex4<_T> v) { x *= T(v.x);  y *= T(v.y);    z *= T(v.z); w *= T(v.w);   return *this; };

    template <typename _T>  vex4<T>& operator/=(_T v) { x /= T(v);    y /= T(v);      z /= T(v);   w /= T(v);     return *this; };
    template <typename _T>  vex4<T>& operator/=(vex4<_T> v) { x /= T(v.x);  y /= T(v.y);    z /= T(v.z); w /= T(v.w);   return *this; };

    template <typename _T>  vex4<T> operator+(_T v) const { return vex4<T>(this->x + T(v), this->y + T(v), this->z + T(v), this->w + T(v)); };
    template <typename _T>  vex4<T> operator+(vex4<_T> v) const { return vex4<T>(this->x + T(v.x), this->y + T(v.y), this->z + T(v.z), this->w + T(v.w)); };

    template <typename _T>  vex4<T> operator-(_T v) const { return vex4<T>(this->x - T(v), this->y - T(v), this->z - T(v), this->w - T(v)); };
    template <typename _T>  vex4<T> operator-(vex4<_T> v) const { return vex4<T>(this->x - T(v.x), this->y - T(v.y), this->z - T(v.z), this->w - T(v.w)); };

    template <typename _T>  vex4<T> operator*(_T v) const { return vex4<T>(this->x * T(v), this->y * T(v), this->z * T(v), this->w * T(v)); };
    template <typename _T>  vex4<T> operator*(vex4<_T> v) const { return vex4<T>(this->x * T(v.x), this->y * T(v.y), this->z * T(v.z), this->w * T(v.w)); };

    template <typename _T>  vex4<T> operator/(_T v) const { return vex4<T>(this->x / T(v), this->y / T(v), this->z / T(v), this->w / T(v)); };
    template <typename _T>  vex4<T> operator/(vex4<_T> v) const { return vex4<T>(this->x / T(v.x), this->y / T(v.y), this->z / T(v.z), this->w / T(v.w)); };

    template <typename _T>  bool operator==(_T v) const { return this->x == T(v) && this->y == T(v) && this->z == T(v) && this->w == T(v); };
    template <typename _T>  bool operator==(vex4<_T> v) const { return this->x == T(v.x) && this->y == T(v.y) && this->z == T(v.z) && this->w == T(v.w); };

    template <typename _T>  bool operator!=(_T v) const { return this->x != T(v) && this->y != T(v) && this->z != T(v) && this->w != T(v); };
    template <typename _T>  bool operator!=(vex4<_T> v) const { return this->x != T(v.x) && this->y != T(v.y) && this->z != T(v.z) && this->w != T(v.w); };

    template <typename _T>  bool operator>(_T v) const { return this->x > T(v) && this->y > T(v) && this->z > T(v) && this->w > T(v); };
    template <typename _T>  bool operator>(vex4<_T> v) const { return this->x > T(v.x) && this->y > T(v.y) && this->z > T(v.z) && this->w > T(v.w); };

    template <typename _T>  bool operator<(_T v) const { return this->x < T(v) && this->y < T(v) && this->z < T(v) && this->w < T(v); };
    template <typename _T>  bool operator<(vex4<_T> v) const { return this->x < T(v.x) && this->y < T(v.y) && this->z < T(v.z) && this->w < T(v.w); };

    template <typename _T>  bool operator>=(_T v) const { return this->x >= T(v) && this->y >= T(v) && this->z >= T(v) && this->w >= T(v); };
    template <typename _T>  bool operator>=(vex4<_T> v) const { return this->x >= T(v.x) && this->y >= T(v.y) && this->z >= T(v.z) && this->w >= T(v.w); };

    template <typename _T>  bool operator<=(_T v) const { return this->x <= T(v) && this->y <= T(v) && this->z <= T(v) && this->w <= T(v); };
    template <typename _T>  bool operator<=(vex4<_T> v) const { return this->x <= T(v.x) && this->y <= T(v.y) && this->z <= T(v.z) && this->w <= T(v.w); };

    template <typename _T> vex4<T>& operator<<(_T v) const { x = v.x; y = v.y; z = v.z; w = v.w; return *this; };

    vex4<T>& normalize() { *this /= x > y ? x : y; return *this; };
    vex4<T> normalize() const { return (*this) / (x > y) ? x : y; };

    template <typename _T> vex4<T>& operator=(vex2<_T> v) { x = T(v.x);  y = T(v.y);    return *this; };
    template <typename _T> vex4<T>& operator+=(vex2<_T> v) { x += T(v.x);  y += T(v.y);    return *this; };
    template <typename _T> vex4<T>& operator-=(vex2<_T> v) { x -= T(v.x);  y -= T(v.y);    return *this; };
    template <typename _T> vex4<T>& operator*=(vex2<_T> v) { x *= T(v.x);  y *= T(v.y);    return *this; };
    template <typename _T> vex4<T>& operator/=(vex2<_T> v) { x /= T(v.x);  y /= T(v.y);    return *this; };
    template <typename _T> vex4<T> operator+(vex2<_T> v) const { return vex4<T>(x + T(v.x), y + T(v.y)); };
    template <typename _T> vex4<T> operator-(vex2<_T> v) const { return vex4<T>(x - T(v.x), y - T(v.y)); };
    template <typename _T> vex4<T> operator*(vex2<_T> v) const { return vex4<T>(x * T(v.x), y * T(v.y)); };
    template <typename _T> vex4<T> operator/(vex2<_T> v) const { return vex4<T>(x / T(v.x), y / T(v.y)); };
    template <typename _T>  bool operator==(vex2<_T> v) const { return this->x == T(v.x) && this->y == T(v.y); };
    template <typename _T>  bool operator!=(vex2<_T> v) const { return this->x != T(v.x) && this->y != T(v.y); };
    template <typename _T>  bool operator>(vex2<_T> v)  const { return this->x > T(v.x) && this->y > T(v.y); };
    template <typename _T>  bool operator<(vex2<_T> v)  const { return this->x < T(v.x) && this->y < T(v.y); };
    template <typename _T>  bool operator>=(vex2<_T> v) const { return this->x >= T(v.x) && this->y >= T(v.y); };
    template <typename _T>  bool operator<=(vex2<_T> v) const { return this->x <= T(v.x) && this->y <= T(v.y); };

    template <typename _T> vex4<T>& operator=(vex3<_T> v) { x = T(v.x);  y = T(v.y);  z = T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator+=(vex3<_T> v) { x += T(v.x);  y += T(v.y);  z += T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator-=(vex3<_T> v) { x -= T(v.x);  y -= T(v.y);  z -= T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator*=(vex3<_T> v) { x *= T(v.x);  y *= T(v.y);  z *= T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator/=(vex3<_T> v) { x /= T(v.x);  y /= T(v.y);  z /= T(v.z);  return *this; };
    template <typename _T> vex4<T>& operator+(vex3<_T> v) const { return vex4<T>(x + T(v.x), y + T(v.y), z + T(v.z)); };
    template <typename _T> vex4<T>& operator-(vex3<_T> v) const { return vex4<T>(x - T(v.x), y - T(v.y), z - T(v.z)); };
    template <typename _T> vex4<T>& operator*(vex3<_T> v) const { return vex4<T>(x * T(v.x), y * T(v.y), z * T(v.z)); };
    template <typename _T> vex4<T>& operator/(vex3<_T> v) const { return vex4<T>(x / T(v.x), y / T(v.y), z / T(v.z)); };
    template <typename _T>  bool operator==(vex3<_T> v) const { return this->x == T(v.x) && this->y == T(v.y) && this->z == T(v.z); };
    template <typename _T>  bool operator!=(vex3<_T> v) const { return this->x != T(v.x) && this->y != T(v.y) && this->z != T(v.z); };
    template <typename _T>  bool operator>(vex3<_T> v)  const { return this->x > T(v.x) && this->y > T(v.y) && this->z > T(v.z); };
    template <typename _T>  bool operator<(vex3<_T> v)  const { return this->x < T(v.x) && this->y < T(v.y) && this->z < T(v.z); };
    template <typename _T>  bool operator>=(vex3<_T> v) const { return this->x >= T(v.x) && this->y >= T(v.y) && this->z >= T(v.z); };
    template <typename _T>  bool operator<=(vex3<_T> v) const { return this->x <= T(v.x) && this->y <= T(v.y) && this->z <= T(v.z); };

    friend std::ostream& operator<<(std::ostream& os, const vex4<T>& v) { os << v.x << ' ' << v.y << ' ' << v.z << ' ' << v.w; return os; };
    friend std::istream& operator>>(std::istream& is, vex4<T>& v) { std::cout << "x: "; is >> v.x; std::cout << "y: "; is >> v.y; std::cout << "z: "; is >> v.z; std::cout << "w: "; is >> v.w; return is; };
};

#define DelForIntVexs(_type) \
template<> vex2<_type>& vex2<_type>::normalize() = delete;      \
template<> vex2<_type> vex2<_type>::normalize() const = delete; \
template<> vex3<_type>& vex3<_type>::normalize() = delete;      \
template<> vex3<_type> vex3<_type>::normalize() const = delete; \
template<> vex4<_type>& vex4<_type>::normalize() = delete;      \
template<> vex4<_type> vex4<_type>::normalize() const = delete;
DelForIntVexs(int)
DelForIntVexs(size_t)
DelForIntVexs(long int)
DelForIntVexs(long long int)

#undef DelForIntVexs

#define DelSVexs(_type, _t)                                                            \
template<> template <typename _T> _type _type::operator%(_T v) const = delete;       \
template<> template <typename _T> _type& _type::operator%=(_T v) = delete;           \
template<> template <typename _T> _type _type::operator%(_t<_T> v) const = delete; \
template<> template <typename _T> _type& _type::operator%=(_t<_T> v) = delete;     \
template<> template <typename _T> bool _type::operator<(_T v) const = delete;        \
template<> template <typename _T> bool _type::operator<(_t<_T> v) const = delete;  \
template<> template <typename _T> bool _type::operator>(_T v) const = delete;        \
template<> template <typename _T> bool _type::operator>(_t<_T> v) const = delete;  \
template<> template <typename _T> bool _type::operator<=(_T v) const = delete;       \
template<> template <typename _T> bool _type::operator<=(_t<_T> v) const = delete; \
template<> template <typename _T> bool _type::operator>=(_T v) const = delete;       \
template<> template <typename _T> bool _type::operator>=(_t<_T> v) const = delete; \
template<> template <typename _T> _type _type::operator-(_T v)const = delete;        \
template<> template <typename _T> _type _type::operator-(_t<_T> v) const = delete; \
template<> template <typename _T> _type& _type::operator-=(_T v) = delete;           \
template<> template <typename _T> _type& _type::operator-=(_t<_T> v) = delete;     \
template<> template <typename _T> _type _type::operator*(_T v) const = delete;       \
template<> template <typename _T> _type _type::operator*(_t<_T> v) const = delete; \
template<> template <typename _T> _type& _type::operator*=(_T v) = delete;           \
template<> template <typename _T> _type& _type::operator*=(_t<_T> v) = delete;     \
template<> template <typename _T> _type _type::operator/(_T v) const = delete;       \
template<> template <typename _T> _type _type::operator/(_t<_T> v) const = delete; \
template<> template <typename _T> _type& _type::operator/=(_T v) = delete;           \
template<> template <typename _T> _type& _type::operator/=(_t<_T> v) = delete;     \
template<> _type& _type::operator++() = delete;                                      \
template<> _type& _type::operator--() = delete;                                      \
template<> _type& _type::normalize() = delete;                                       \
template<> _type _type::normalize() const = delete;                                  \

DelSVexs(vex2<std::string>, vex2)
DelSVexs(vex3<std::string>, vex3)
DelSVexs(vex4<std::string>, vex4)
DelSVexs(vex2<bool>, vex2)
DelSVexs(vex3<bool>, vex3)
DelSVexs(vex4<bool>, vex4)

#undef DelSVexs

#ifdef _XS_STRINX_
template<> template <typename _T> vex2<strinx> vex2<strinx>::operator%(_T v) const = delete;
template<> template <typename _T> vex2<strinx>& vex2<strinx>::operator%=(_T v) = delete;
template<> template <typename _T> vex2<strinx> vex2<strinx>::operator%(vex2<_T> v) const = delete;
template<> template <typename _T> vex2<strinx>& vex2<strinx>::operator%=(vex2<_T> v) = delete;
template<> template <typename _T> bool vex2<strinx>::operator<(_T v) const = delete;
template<> template <typename _T> bool vex2<strinx>::operator<(vex2<_T> v) const = delete;
template<> template <typename _T> bool vex2<strinx>::operator>(_T v) const = delete;
template<> template <typename _T> bool vex2<strinx>::operator>(vex2<_T> v) const = delete;
template<> template <typename _T> bool vex2<strinx>::operator<=(_T v) const = delete;
template<> template <typename _T> bool vex2<strinx>::operator<=(vex2<_T> v) const = delete;
template<> template <typename _T> bool vex2<strinx>::operator>=(_T v) const = delete;
template<> template <typename _T> bool vex2<strinx>::operator>=(vex2<_T> v) const = delete;
template<> vex2<strinx>& vex2<strinx>::normalize() = delete;
template<> vex2<strinx> vex2<strinx>::normalize() const = delete;
typedef vex2<strinx> vex2x;

template<> template <typename _T> vex3<strinx> vex3<strinx>::operator%(_T v) const = delete;
template<> template <typename _T> vex3<strinx>& vex3<strinx>::operator%=(_T v) = delete;
template<> template <typename _T> vex3<strinx> vex3<strinx>::operator%(vex3<_T> v) const = delete;
template<> template <typename _T> vex3<strinx>& vex3<strinx>::operator%=(vex3<_T> v) = delete;
template<> template <typename _T> bool vex3<strinx>::operator<(_T v) const = delete;
template<> template <typename _T> bool vex3<strinx>::operator<(vex3<_T> v) const = delete;
template<> template <typename _T> bool vex3<strinx>::operator>(_T v) const = delete;
template<> template <typename _T> bool vex3<strinx>::operator>(vex3<_T> v) const = delete;
template<> template <typename _T> bool vex3<strinx>::operator<=(_T v) const = delete;
template<> template <typename _T> bool vex3<strinx>::operator<=(vex3<_T> v) const = delete;
template<> template <typename _T> bool vex3<strinx>::operator>=(_T v) const = delete;
template<> template <typename _T> bool vex3<strinx>::operator>=(vex3<_T> v) const = delete;
template<> vex3<strinx>& vex3<strinx>::normalize() = delete;
template<> vex3<strinx> vex3<strinx>::normalize() const = delete;
typedef vex3<strinx> vex3x;

template<> template <typename _T> vex4<strinx> vex4<strinx>::operator%(_T v) const = delete;
template<> template <typename _T> vex4<strinx>& vex4<strinx>::operator%=(_T v) = delete;
template<> template <typename _T> vex4<strinx> vex4<strinx>::operator%(vex4<_T> v) const = delete;
template<> template <typename _T> vex4<strinx>& vex4<strinx>::operator%=(vex4<_T> v) = delete;
template<> template <typename _T> bool vex4<strinx>::operator<(_T v) const = delete;
template<> template <typename _T> bool vex4<strinx>::operator<(vex4<_T> v) const = delete;
template<> template <typename _T> bool vex4<strinx>::operator>(_T v) const = delete;
template<> template <typename _T> bool vex4<strinx>::operator>(vex4<_T> v) const = delete;
template<> template <typename _T> bool vex4<strinx>::operator<=(_T v) const = delete;
template<> template <typename _T> bool vex4<strinx>::operator<=(vex4<_T> v) const = delete;
template<> template <typename _T> bool vex4<strinx>::operator>=(_T v) const = delete;
template<> template <typename _T> bool vex4<strinx>::operator>=(vex4<_T> v) const = delete;
template<> vex4<strinx>& vex4<strinx>::normalize() = delete;
template<> vex4<strinx> vex4<strinx>::normalize() const = delete;
template<> vex4<strinx> vex4<strinx>::percent(strinx v) const = delete;
template<> vex4<strinx> vex4<strinx>::percent(strinx v1, strinx v2, strinx v3, strinx v4) const = delete;
typedef vex4<strinx> vex4x;
#endif

template<> template<> vex2<float>::vex2(std::string v) { x = y = std::stof(v.c_str()); };
template<> template<> vex2<int>::vex2(std::string v) { x = y = std::stoi(v.c_str()); };
template<> template<> vex2<size_t>::vex2(std::string v) { x = y = std::stoi(v.c_str()); };
template<> template<> vex2<long int>::vex2(std::string v) { x = y = std::stoi(v.c_str()); };
template<> template<> vex2<long long int>::vex2(std::string v) { x = y = std::stoi(v.c_str()); };
template<> template<> vex2<double>::vex2(std::string v) { x = y = std::stof(v.c_str()); };
template<> template<> vex2<long double>::vex2(std::string v) { x = y = std::stof(v.c_str()); };

template<> template<> vex2<float>::vex2(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex2<int>::vex2(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex2<size_t>::vex2(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex2<long int>::vex2(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex2<long long int>::vex2(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex2<double>::vex2(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex2<long double>::vex2(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };

template<> template<> vex2<float>& vex2<float>::operator=(std::string v) { x = y = std::stof(v.c_str()); return *this; };
template<> template<> vex2<int>& vex2<int>::operator=(std::string v) { x = y = std::stoi(v.c_str()); return *this; };
template<> template<> vex2<size_t>& vex2<size_t>::operator=(std::string v) { x = y = std::stoi(v.c_str()); return *this; };
template<> template<> vex2<long int>& vex2<long int>::operator=(std::string v) { x = y = std::stoi(v.c_str()); return *this; };
template<> template<> vex2<long long int>& vex2<long long int>::operator=(std::string v) { x = y = std::stoi(v.c_str()); return *this; };
template<> template<> vex2<double>& vex2<double>::operator=(std::string v) { x = y = std::stof(v.c_str()); return *this; };
template<> template<> vex2<long double>& vex2<long double>::operator=(std::string v) { x = y = std::stof(v.c_str()); return *this; };


template<> template<> vex3<float>::vex3(std::string v) { x = y = z = std::stof(v); };
template<> template<> vex3<int>::vex3(std::string v) { x = y = z = std::stoi(v); };
template<> template<> vex3<size_t>::vex3(std::string v) { x = y = z = std::stoi(v); };
template<> template<> vex3<long int>::vex3(std::string v) { x = y = z = std::stoi(v); };
template<> template<> vex3<long long int>::vex3(std::string v) { x = y = z = std::stoi(v); };
template<> template<> vex3<double>::vex3(std::string v) { x = y = z = std::stof(v); };
template<> template<> vex3<long double>::vex3(std::string v) { x = y = z = std::stof(v); };

template<> template<> vex3<float>::vex3(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex3<int>::vex3(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex3<size_t>::vex3(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex3<long int>::vex3(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex3<long long int>::vex3(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex3<double>::vex3(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex3<long double>::vex3(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };

template<> template<> vex3<float>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };
template<> template<> vex3<int>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex3<size_t>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex3<long int>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex3<long long int>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex3<double>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };
template<> template<> vex3<long double>::vex3(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };

template<> template<> vex3<float>& vex3<float>::operator=(std::string v) { x = y = z = std::stof(v.c_str()); return *this; };
template<> template<> vex3<int>& vex3<int>::operator=(std::string v) { x = y = z = std::stoi(v.c_str()); return *this; };
template<> template<> vex3<size_t>& vex3<size_t>::operator=(std::string v) { x = y = z = std::stoi(v.c_str()); return *this; };
template<> template<> vex3<long int>& vex3<long int>::operator=(std::string v) { x = y = z = std::stoi(v.c_str()); return *this; };
template<> template<> vex3<long long int>& vex3<long long int>::operator=(std::string v) { x = y = z = std::stoi(v.c_str()); return *this; };
template<> template<> vex3<double>& vex3<double>::operator=(std::string v) { x = y = z = std::stof(v.c_str()); return *this; };
template<> template<> vex3<long double>& vex3<long double>::operator=(std::string v) { x = y = z = std::stof(v.c_str()); return *this; };


template<> template<> vex4<float>::vex4(std::string v) { x = y = z = w = std::stof(v.c_str()); };
template<> template<> vex4<int>::vex4(std::string v) { x = y = z = w = std::stoi(v.c_str()); };
template<> template<> vex4<size_t>::vex4(std::string v) { x = y = z = w = std::stoi(v.c_str()); };
template<> template<> vex4<long int>::vex4(std::string v) { x = y = z = w = std::stoi(v.c_str()); };
template<> template<> vex4<long long int>::vex4(std::string v) { x = y = z = w = std::stoi(v.c_str()); };
template<> template<> vex4<double>::vex4(std::string v) { x = y = z = w = std::stof(v.c_str()); };
template<> template<> vex4<long double>::vex4(std::string v) { x = y = z = w = std::stof(v.c_str()); };

template<> template<> vex4<float>::vex4(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex4<int>::vex4(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex4<size_t>::vex4(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex4<long int>::vex4(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex4<long long int>::vex4(std::string v1, std::string v2) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); };
template<> template<> vex4<double>::vex4(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };
template<> template<> vex4<long double>::vex4(std::string v1, std::string v2) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); };

template<> template<> vex4<float>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };
template<> template<> vex4<int>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex4<size_t>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex4<long int>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex4<long long int>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); };
template<> template<> vex4<double>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };
template<> template<> vex4<long double>::vex4(std::string v1, std::string v2, std::string v3) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); };

template<> template<> vex4<float>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); w = std::stof(v4.c_str()); };
template<> template<> vex4<int>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); w = std::stoi(v4.c_str()); };
template<> template<> vex4<size_t>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); w = std::stoi(v4.c_str()); };
template<> template<> vex4<long int>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); w = std::stoi(v4.c_str()); };
template<> template<> vex4<long long int>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stoi(v1.c_str()); y = std::stoi(v2.c_str()); z = std::stoi(v3.c_str()); w = std::stoi(v4.c_str()); };
template<> template<> vex4<double>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); w = std::stof(v4.c_str()); };
template<> template<> vex4<long double>::vex4(std::string v1, std::string v2, std::string v3, std::string v4) { x = std::stof(v1.c_str()); y = std::stof(v2.c_str()); z = std::stof(v3.c_str()); w = std::stof(v4.c_str()); };

template<> template<> vex4<float>& vex4<float>::operator=(std::string v) { x = y = z = w = std::stof(v.c_str()); return *this; };
template<> template<> vex4<int>& vex4<int>::operator=(std::string v) { x = y = z = w = std::stoi(v.c_str()); return *this; };
template<> template<> vex4<size_t>& vex4<size_t>::operator=(std::string v) { x = y = z = w = std::stoi(v.c_str()); return *this; };
template<> template<> vex4<long int>& vex4<long int>::operator=(std::string v) { x = y = z = w = std::stoi(v.c_str()); return *this; };
template<> template<> vex4<long long int>& vex4<long long int>::operator=(std::string v) { x = y = z = w = std::stoi(v.c_str()); return *this; };
template<> template<> vex4<long double>& vex4<long double>::operator=(std::string v) { x = y = z = w = std::stof(v.c_str()); return *this; };

typedef vex2<bool>          vex2b;
typedef vex2<float>         vex2f;
typedef vex2<int>           vex2i;
typedef vex2<size_t>        vex2ui;
typedef vex2<double>        vex2d;
typedef vex2<long double>   vex2ld;
typedef vex2<long int>      vex2li;
typedef vex2<long long int> vex2lli;
typedef vex2<std::string>   vex2s;

typedef vex3<bool>          vex3b;
typedef vex3<float>         vex3f;
typedef vex3<int>           vex3i;
typedef vex3<size_t>        vex3ui;
typedef vex3<double>        vex3d;
typedef vex3<long double>   vex3ld;
typedef vex3<long int>      vex3li;
typedef vex3<long long int> vex3lli;
typedef vex3<std::string>   vex3s;

typedef vex4<bool>          vex4b;
typedef vex4<float>         vex4f;
typedef vex4<int>           vex4i;
typedef vex4<size_t>        vex4ui;
typedef vex4<double>        vex4d;
typedef vex4<long double>   vex4ld;
typedef vex4<long int>      vex4li;
typedef vex4<long long int> vex4lli;
typedef vex4<std::string>   vex4s;

vex2f operator""_vex2f(unsigned long long v) { return vex2f(v); };
vex2i operator""_vex2i(unsigned long long v) { return vex2i(v); };
vex2ui operator""_vex2ui(unsigned long long v) { return vex2ui(v); };
vex2d operator""_vex2d(unsigned long long v) { return vex2d(v); };
vex2ld operator""_vex2ld(unsigned long long v) { return vex2ld(v); };
vex2li operator""_vex2li(unsigned long long v) { return vex2li(v); };
vex2lli operator""_vex2lli(unsigned long long v) { return vex2lli(v); };

vex3f operator""_vex3f(unsigned long long v) { return vex3f(v); };
vex3i operator""_vex3i(unsigned long long v) { return vex3i(v); };
vex3ui operator""_vex3ui(unsigned long long v) { return vex3ui(v); };
vex3d operator""_vex3d(unsigned long long v) { return vex3d(v); };
vex3ld operator""_vex3ld(unsigned long long v) { return vex3ld(v); };
vex3li operator""_vex3li(unsigned long long v) { return vex3li(v); };
vex3lli operator""_vex3lli(unsigned long long v) { return vex3lli(v); };

vex4f operator""_vex4f(unsigned long long v) { return vex4f(v); };
vex4i operator""_vex4i(unsigned long long v) { return vex4i(v); };
vex4ui operator""_vex4ui(unsigned long long v) { return vex4ui(v); };
vex4d operator""_vex4d(unsigned long long v) { return vex4d(v); };
vex4ld operator""_vex4ld(unsigned long long v) { return vex4ld(v); };
vex4li operator""_vex4li(unsigned long long v) { return vex4li(v); };
vex4lli operator""_vex4lli(unsigned long long v) { return vex4lli(v); };

vex2f operator""_vex2f(long double v) { return vex2f(v); };
vex2i operator""_vex2i(long double v) { return vex2i(v); };
vex2ui operator""_vex2ui(long double v) { return vex2ui(v); };
vex2d operator""_vex2d(long double v) { return vex2d(v); };
vex2ld operator""_vex2ld(long double v) { return vex2ld(v); };
vex2li operator""_vex2li(long double v) { return vex2li(v); };
vex2lli operator""_vex2lli(long double v) { return vex2lli(v); };

vex3f operator""_vex3f(long double v) { return vex3f(v); };
vex3i operator""_vex3i(long double v) { return vex3i(v); };
vex3ui operator""_vex3ui(long double v) { return vex3ui(v); };
vex3d operator""_vex3d(long double v) { return vex3d(v); };
vex3ld operator""_vex3ld(long double v) { return vex3ld(v); };
vex3li operator""_vex3li(long double v) { return vex3li(v); };
vex3lli operator""_vex3lli(long double v) { return vex3lli(v); };

vex4f operator""_vex4f(long double v) { return vex4f(v); };
vex4i operator""_vex4i(long double v) { return vex4i(v); };
vex4ui operator""_vex4ui(long double v) { return vex4ui(v); };
vex4d operator""_vex4d(long double v) { return vex4d(v); };
vex4ld operator""_vex4ld(long double v) { return vex4ld(v); };
vex4li operator""_vex4li(long double v) { return vex4li(v); };
vex4lli operator""_vex4lli(long double v) { return vex4lli(v); };

#ifdef __XSIMFUNCS__
__XSIMFUNCS__
#endif

#define _VexTypedefs_              \
typedef vex2<bool>          v2b;   \
typedef vex2<float>         v2f;   \
typedef vex2<int>           v2i;   \
typedef vex2<size_t>        v2ui;  \
typedef vex2<double>        v2d;   \
typedef vex2<long double>   v2ld;  \
typedef vex2<long int>      v2li;  \
typedef vex2<long long int> v2lli; \
typedef vex2<std::string>   v2s;   \
                                   \
typedef vex3<bool>          v3b;   \
typedef vex3<float>         v3f;   \
typedef vex3<int>           v3i;   \
typedef vex3<size_t>        v3ui;  \
typedef vex3<double>        v3d;   \
typedef vex3<long double>   v3ld;  \
typedef vex3<long int>      v3li;  \
typedef vex3<long long int> v3lli; \
typedef vex3<std::string>   v3s;   \
                                   \
typedef vex4<bool>          v4b;   \
typedef vex4<float>         v4f;   \
typedef vex4<int>           v4i;   \
typedef vex4<size_t>        v4ui;  \
typedef vex4<double>        v4d;   \
typedef vex4<long double>   v4ld;  \
typedef vex4<long int>      v4li;  \
typedef vex4<long long int> v4lli; \
typedef vex4<std::string>   v4s;

#if !defined(_VEX_NO_SHORT_NAMES)
_VexTypedefs_
#endif

namespace std {
    inline vex2f    ceil(vex2f v) { return vex2f(std::ceil(v.x), std::ceil(v.y)); };
    inline vex2d    ceil(vex2d v) { return vex2d(std::ceil(v.x), std::ceil(v.y)); };
    inline vex2f    floor(vex2f v) { return vex2f(std::floor(v.x), std::floor(v.y)); };
    inline vex2d    floor(vex2d v) { return vex2d(std::floor(v.x), std::floor(v.y)); };
    inline vex2f    abs(vex2f v) { return vex2f(std::abs(v.x), std::abs(v.y)); };
    inline vex2d    abs(vex2d v) { return vex2d(std::abs(v.x), std::abs(v.y)); };
    inline vex2f    round(vex2f v) { return vex2f(std::round(v.x), std::round(v.y)); };
    inline vex2d    round(vex2d v) { return vex2d(std::round(v.x), std::round(v.y)); };
    inline vex2f    trunc(vex2f v) { return vex2f(std::trunc(v.x), std::trunc(v.y)); };
    inline vex2d    trunc(vex2d v) { return vex2d(std::trunc(v.x), std::trunc(v.y)); };
    inline vex2f    exp(vex2f v) { return vex2f(std::exp(v.x), std::exp(v.y)); };
    inline vex2d    exp(vex2d v) { return vex2d(std::exp(v.x), std::exp(v.y)); };
    inline vex2f    sqrt(vex2f v) { return vex2f(std::sqrt(v.x), std::sqrt(v.y)); };
    inline vex2d    sqrt(vex2d v) { return vex2d(std::sqrt(v.x), std::sqrt(v.y)); };
    inline vex2i    sqrt(vex2i v) { return vex2i(std::sqrt(v.x), std::sqrt(v.y)); };
    inline vex2li   sqrt(vex2li v) { return vex2li(std::sqrt(v.x), std::sqrt(v.y)); };
    inline vex2lli  sqrt(vex2lli v) { return vex2lli(std::sqrt(v.x), std::sqrt(v.y)); };
    inline vex2f    cbrt(vex2f v) { return vex2f(std::cbrt(v.x), std::cbrt(v.y)); };
    inline vex2d    cbrt(vex2d v) { return vex2d(std::cbrt(v.x), std::cbrt(v.y)); };
    inline vex2i    cbrt(vex2i v) { return vex2i(std::cbrt(v.x), std::cbrt(v.y)); };
    inline vex2li   cbrt(vex2li v) { return vex2li(std::cbrt(v.x), std::cbrt(v.y)); };
    inline vex2lli  cbrt(vex2lli v) { return vex2lli(std::cbrt(v.x), std::cbrt(v.y)); };
    inline vex2f    pow(vex2f v, int p) { return vex2f(std::pow(v.x, p), std::pow(v.y, p)); };
    inline vex2d    pow(vex2d v, int p) { return vex2d(std::pow(v.x, p), std::pow(v.y, p)); };
    inline vex2i    pow(vex2i v, int p) { return vex2i(std::pow(v.x, p), std::pow(v.y, p)); };
    inline vex2li   pow(vex2li v, int p) { return vex2li(std::pow(v.x, p), std::pow(v.y, p)); };
    inline vex2lli  pow(vex2lli v, int p) { return vex2lli(std::pow(v.x, p), std::pow(v.y, p)); };
    inline vex2f&   max(vex2f& v1, vex2f& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex2d&   max(vex2d& v1, vex2d& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex2i&   max(vex2i& v1, vex2i& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex2li&  max(vex2li& v1, vex2li& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex2lli& max(vex2lli& v1, vex2lli& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex2f&   min(vex2f& v1, vex2f& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex2d&   min(vex2d& v1, vex2d& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex2i&   min(vex2i& v1, vex2i& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex2li&  min(vex2li& v1, vex2li& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex2lli& min(vex2lli& v1, vex2lli& v2) { return (v1 < v2) ? v1 : v2; };

    inline vex3f   ceil(vex3f v) { return vex3f(std::ceil(v.x), std::ceil(v.y), std::ceil(v.z)); };
    inline vex3d   ceil(vex3d v) { return vex3f(std::ceil(v.x), std::ceil(v.y), std::ceil(v.z)); };
    inline vex3f   floor(vex3f v) { return vex3f(std::floor(v.x), std::floor(v.y), std::floor(v.z)); };
    inline vex3d   floor(vex3d v) { return vex3d(std::floor(v.x), std::floor(v.y), std::floor(v.z)); };
    inline vex3f   abs(vex3f v) { return vex3f(std::abs(v.x), std::abs(v.y), std::abs(v.z)); };
    inline vex3d   abs(vex3d v) { return vex3d(std::abs(v.x), std::abs(v.y), std::abs(v.z)); };
    inline vex3f   round(vex3f v) { return vex3f(std::round(v.x), std::round(v.y), std::round(v.z)); };
    inline vex3d   round(vex3d v) { return vex3d(std::round(v.x), std::round(v.y), std::round(v.z)); };
    inline vex3f   trunc(vex3f v) { return vex3f(std::trunc(v.x), std::trunc(v.y), std::trunc(v.z)); };
    inline vex3d   trunc(vex3d v) { return vex3d(std::trunc(v.x), std::trunc(v.y), std::trunc(v.z)); };
    inline vex3f   exp(vex3f v) { return vex3f(std::exp(v.x), std::exp(v.y), std::exp(v.z)); };
    inline vex3d   exp(vex3d v) { return vex3d(std::exp(v.x), std::exp(v.y), std::exp(v.z)); };
    inline vex3f   sqrt(vex3f v) { return vex3f(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z)); };
    inline vex3d   sqrt(vex3d v) { return vex3d(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z)); };
    inline vex3i   sqrt(vex3i v) { return vex3i(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z)); };
    inline vex3li  sqrt(vex3li v) { return vex3li(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z)); };
    inline vex3lli sqrt(vex3lli v) { return vex3lli(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z)); };
    inline vex3f   cbrt(vex3f v) { return vex3f(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z)); };
    inline vex3d   cbrt(vex3d v) { return vex3d(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z)); };
    inline vex3i   cbrt(vex3i v) { return vex3i(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z)); };
    inline vex3li  cbrt(vex3li v) { return vex3li(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z)); };
    inline vex3lli cbrt(vex3lli v) { return vex3lli(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z)); };
    inline vex3f   pow(vex3f v, int p) { return vex3f(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p)); };
    inline vex3d   pow(vex3d v, int p) { return vex3d(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p)); };
    inline vex3i   pow(vex3i v, int p) { return vex3i(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p)); };
    inline vex3li  pow(vex3li v, int p) { return vex3li(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p)); };
    inline vex3lli pow(vex3lli v, int p) { return vex3lli(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p)); };
    inline vex3f&  max(vex3f& v1, vex3f& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex3d&  max(vex3d& v1, vex3d& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex3i&  max(vex3i& v1, vex3i& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex3li& max(vex3li& v1, vex3li& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex3lli& max(vex3lli& v1, vex3lli& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex3f&  min(vex3f& v1, vex3f& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex3d&  min(vex3d& v1, vex3d& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex3i&  min(vex3i& v1, vex3i& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex3li& min(vex3li& v1, vex3li& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex3lli& min(vex3lli& v1, vex3lli& v2) { return (v1 < v2) ? v1 : v2; };

    inline vex4f   ceil(vex4f v) { return vex4f(std::ceil(v.x), std::ceil(v.y), std::ceil(v.z), std::ceil(v.w)); };
    inline vex4d   ceil(vex4d v) { return vex4f(std::ceil(v.x), std::ceil(v.y), std::ceil(v.z), std::ceil(v.w)); };
    inline vex4f   floor(vex4f v) { return vex4f(std::floor(v.x), std::floor(v.y), std::floor(v.z), std::floor(v.w)); };
    inline vex4d   floor(vex4d v) { return vex4d(std::floor(v.x), std::floor(v.y), std::floor(v.z), std::floor(v.w)); };
    inline vex4f   abs(vex4f v) { return vex4f(std::abs(v.x), std::abs(v.y), std::abs(v.z), std::abs(v.w)); };
    inline vex4d   abs(vex4d v) { return vex4d(std::abs(v.x), std::abs(v.y), std::abs(v.z), std::abs(v.w)); };
    inline vex4f   round(vex4f v) { return vex4f(std::round(v.x), std::round(v.y), std::round(v.z), std::round(v.w)); };
    inline vex4d   round(vex4d v) { return vex4d(std::round(v.x), std::round(v.y), std::round(v.z), std::round(v.w)); };
    inline vex4f   trunc(vex4f v) { return vex4f(std::trunc(v.x), std::trunc(v.y), std::trunc(v.z), std::trunc(v.w)); };
    inline vex4d   trunc(vex4d v) { return vex4d(std::trunc(v.x), std::trunc(v.y), std::trunc(v.z), std::trunc(v.w)); };
    inline vex4d   exp(vex4d v) { return vex4f(std::exp(v.x), std::exp(v.y), std::exp(v.z), std::exp(v.w)); };
    inline vex4f   exp(vex4f v) { return vex4d(std::exp(v.x), std::exp(v.y), std::exp(v.z), std::exp(v.w)); };
    inline vex4f   sqrt(vex4f v) { return vex4f(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z), std::sqrt(v.w)); };
    inline vex4d   sqrt(vex4d v) { return vex4d(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z), std::sqrt(v.w)); };
    inline vex4i   sqrt(vex4i v) { return vex4i(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z), std::sqrt(v.w)); };
    inline vex4li  sqrt(vex4li v) { return vex4li(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z), std::sqrt(v.w)); };
    inline vex4lli sqrt(vex4lli v) { return vex4lli(std::sqrt(v.x), std::sqrt(v.y), std::sqrt(v.z), std::sqrt(v.w)); };
    inline vex4f   cbrt(vex4f v) { return vex4f(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z), std::cbrt(v.w)); };
    inline vex4d   cbrt(vex4d v) { return vex4d(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z), std::cbrt(v.w)); };
    inline vex4i   cbrt(vex4i v) { return vex4i(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z), std::cbrt(v.w)); };
    inline vex4li  cbrt(vex4li v) { return vex4li(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z), std::cbrt(v.w)); };
    inline vex4lli cbrt(vex4lli v) { return vex4lli(std::cbrt(v.x), std::cbrt(v.y), std::cbrt(v.z), std::cbrt(v.w)); };
    inline vex4f   pow(vex4f v, int p) { return vex4f(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p), std::pow(v.w, p)); };
    inline vex4d   pow(vex4d v, int p) { return vex4d(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p), std::pow(v.w, p)); };
    inline vex4i   pow(vex4i v, int p) { return vex4i(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p), std::pow(v.w, p)); };
    inline vex4li  pow(vex4li v, int p) { return vex4li(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p), std::pow(v.w, p)); };
    inline vex4lli pow(vex4lli v, int p) { return vex4lli(std::pow(v.x, p), std::pow(v.y, p), std::pow(v.z, p), std::pow(v.w, p)); };
    inline vex4f&  max(vex4f& v1, vex4f& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex4d&  max(vex4d& v1, vex4d& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex4i&  max(vex4i& v1, vex4i& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex4li& max(vex4li& v1, vex4li& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex4lli& max(vex4lli& v1, vex4lli& v2) { return (v1 > v2) ? v1 : v2; };
    inline vex4f&  min(vex4f& v1, vex4f& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex4d&  min(vex4d& v1, vex4d& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex4i&  min(vex4i& v1, vex4i& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex4li& min(vex4li& v1, vex4li& v2) { return (v1 < v2) ? v1 : v2; };
    inline vex4lli& min(vex4lli& v1, vex4lli& v2) { return (v1 < v2) ? v1 : v2; };
    vex2f strtov2f(const std::string& _s) {
        stringstream ss;
        string s;
        vex2f t;
        ss << _s;
        for (size_t i = 0u; i < 2u and ss >> s; i++)
            t[i] = stof(s);
        return t;
    };
    vex2d strtov2d(const std::string& _s) {
        stringstream ss;
        string s;
        vex2d t;
        ss << _s;
        for (size_t i = 0u; i < 2u and ss >> s; i++)
            t[i] = stod(s);
        return t;
    };
    vex2i strtov2i(const std::string& _s) {
        stringstream ss;
        string s;
        vex2i t;
        ss << _s;
        for (size_t i = 0u; i < 2u and ss >> s; i++)
            t[i] = stoi(s);
        return t;
    };
    vex3f strtov3f(const std::string& _s) {
        stringstream ss;
        string s;
        vex3f t;
        ss << _s;
        for (size_t i = 0u; i < 3u and ss >> s; i++)
            t[i] = stof(s);
        return t;
    };
    vex3d strtov3d(const std::string& _s) {
        stringstream ss;
        string s;
        vex3d t;
        ss << _s;
        for (size_t i = 0u; i < 3u and ss >> s; i++)
            t[i] = stod(s);
        return t;
    };
    vex3i strtov3i(const std::string& _s) {
        stringstream ss;
        string s;
        vex3i t;
        ss << _s;
        for (size_t i = 0u; i < 3u and ss >> s; i++)
            t[i] = stoi(s);
        return t;
    };
    vex4f strtov4f(const std::string& _s) {
        stringstream ss;
        string s;
        vex4f t;
        ss << _s;
        for (size_t i = 0u; i < 4u and ss >> s; i++)
            t[i] = stof(s);
        return t;
    };
    vex4d strtov4d(const std::string& _s) {
        stringstream ss;
        string s;
        vex4d t;
        ss << _s;
        for (size_t i = 0u; i < 4u and ss >> s; i++)
            t[i] = stod(s);
        return t;
    };
    vex4i strtov4i(const std::string& _s) {
        stringstream ss;
        string s;
        vex4i t;
        ss << _s;
        for (size_t i = 0u; i < 4u and ss >> s; i++)
            t[i] = stoi(s);
        return t;
    };
};

namespace std {
    template <typename T> std::string to_string(vex2<T> v, const std::string& sep = " ", const std::string& end = "") { return v.str(sep, end); };
    template <typename T> std::string to_string(vex3<T> v, const std::string& sep = " ", const std::string& end = "") { return v.str(sep, end); };
    template <typename T> std::string to_string(vex4<T> v, const std::string& sep = " ", const std::string& end = "") { return v.str(sep, end); };
};

#if !defined(_VEX_NO_MATH_FUNCS)
template <typename T, typename T1, typename T2> vex2<T>& limit(vex2<T>& v, const T1 min, const T2 max, const bool& _restart = false) {
    if (v.x < (T)min)
        v.x = _restart ? (T)max : (T)min;
    else if (v.x > (T)max)
        v.x = _restart ? (T)min : (T)max;
    if (v.y < (T)min)
        v.y = _restart ? (T)max : (T)min;
    else if (v.y > (T)max)
        v.y = _restart ? (T)min : (T)max;
    return v;
};
template <typename T, typename T1, typename T2> vex2<T>& limit(vex2<T>& v, const vex2<T1> min, const vex2<T2> max, const bool& _restart = false) {
    if (v.x < (T)min.x)
        v.x = _restart ? (T)max.x : (T)min.x;
    else if (v.x > (T)max.x)
        v.x = _restart ? (T)min.x : (T)max.x;
    if (v.y < (T)min.y)
        v.y = _restart ? (T)max.y : (T)min.y;
    else if (v.y > (T)max.y)
        v.y = _restart ? (T)min.y : (T)max.y;
    return v;
};

template <typename T, typename T1, typename T2> vex3<T>& limit(vex3<T>& v, const T1 min, const T2 max, const bool& _restart = false) {
    if (v.x < (T)min)
        v.x = _restart ? (T)max : (T)min;
    else if (v.x > (T)max)
        v.x = _restart ? (T)min : (T)max;
    if (v.y < (T)min)
        v.y = _restart ? (T)max : (T)min;
    else if (v.y > (T)max)
        v.y = _restart ? (T)min : (T)max;
    if (v.z < (T)min)
        v.z = _restart ? (T)max : (T)min;
    else if (v.z > (T)max)
        v.z = _restart ? (T)min : (T)max;
    return v;
};
template <typename T, typename T1, typename T2> vex3<T>& limit(vex3<T>& v, const vex3<T1> min, const vex3<T2> max, const bool& _restart = false) {
    if (v.x < (T)min.x)
        v.x = _restart ? (T)max.x : (T)min.x;
    else if (v.x > (T)max.x)
        v.x = _restart ? (T)min.x : (T)max.x;
    if (v.y < (T)min.y)
        v.y = _restart ? (T)max.y : (T)min.y;
    else if (v.y > (T)max.y)
        v.y = _restart ? (T)min.y : (T)max.y;
    if (v.z < (T)min.z)
        v.z = _restart ? (T)max.z : (T)min.z;
    else if (v.z > (T)max.z)
        v.z = _restart ? (T)min.z : (T)max.z;
    return v;
};

template <typename T, typename T1, typename T2> vex4<T>& limit(vex4<T>& v, const T1 min, const T2 max, const bool& _restart = false) {
    if (v.x < (T)min)
        v.x = _restart ? (T)max : (T)min;
    else if (v.x > (T)max)
        v.x = _restart ? (T)min : (T)max;
    if (v.y < (T)min)
        v.y = _restart ? (T)max : (T)min;
    else if (v.y > (T)max)
        v.y = _restart ? (T)min : (T)max;
    if (v.z < (T)min)
        v.z = _restart ? (T)max : (T)min;
    else if (v.z > (T)max)
        v.z = _restart ? (T)min : (T)max;
    if (v.w < (T)min)
        v.w = _restart ? (T)max : (T)min;
    else if (v.w > (T)max)
        v.w = _restart ? (T)min : (T)max;
    return v;
};
template <typename T, typename T1, typename T2> vex4<T>& limit(vex4<T>& v, const vex4<T1> min, const vex4<T2> max, const bool& _restart = false) {
    if (v.x < (T)min.x)
        v.x = _restart ? (T)max.x : (T)min.x;
    else if (v.x > (T)max.x)
        v.x = _restart ? (T)min.x : (T)max.x;
    if (v.y < (T)min.y)
        v.y = _restart ? (T)max.y : (T)min.y;
    else if (v.y > (T)max.y)
        v.y = _restart ? (T)min.y : (T)max.y;
    if (v.z < (T)min.z)
        v.z = _restart ? (T)max.z : (T)min.z;
    else if (v.z > (T)max.z)
        v.z = _restart ? (T)min.z : (T)max.z;
    if (v.w < (T)min.w)
        v.w = _restart ? (T)max.w : (T)min.w;
    else if (v.w > (T)max.w)
        v.w = _restart ? (T)min.w : (T)max.w;
    return v;
};

template <typename T> const T& max(const vex2<T>& v) { return (v.x > v.y) ? v.x : v.y; };
template <typename T> const T& max(const vex3<T>& v) { return (v.x > v.y && v.x > v.z) ? v.x : (v.y > v.z) ? v.y : v.z; };
template <typename T> const T& max(const vex4<T>& v) { return (v.x > v.y && v.x > v.z && v.x > v.w) ? v.x : (v.y > v.z && v.y > v.w) ? v.y : (v.z > v.w) ? v.z : v.w; };

template <typename T> const T& min(const vex2<T>& v) { return (v.x < v.y) ? v.x : v.y; };
template <typename T> const T& min(const vex3<T>& v) { return (v.x < v.y&& v.x < v.z) ? v.x : (v.y < v.z) ? v.y : v.z; };
template <typename T> const T& min(const vex4<T>& v) { return (v.x < v.y&& v.x < v.z&& v.x < v.w) ? v.x : (v.y < v.z&& v.y < v.w) ? v.y : (v.z < v.w) ? v.z : v.w; };
#endif
