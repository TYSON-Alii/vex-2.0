template <typename T>
struct vex2 {
    T x, y;
    vex2() = default;
    vex2(const vex2<T>&) = default;

    template <typename _T>
    vex2(_T v) { x = y = T(v); };
    template <> vex2(std::string v);
    
    template <typename _T1, typename _T2>
    vex2(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };
    template <> vex2(std::string v1, std::string v2);

    template <typename _T>
    vex2<T>& operator=(_T v) { x = y = T(v); return *this; };
    template <> vex2<T>& operator=(std::string v);
    template<typename _T>
    vex2<T>& operator=(vex2<_T> v) { x = T(v.x); y = T(v.y); return *this; };

    vex2<T> operator!() { return vex2<T>(y, x); };
    vex2<T>& swap() { *this = vex2<T>(y, x); return *this; };

    vex2<T> operator()() { return *this; };
    vex2<T> copy() { return *this; };

    T& operator[](int v) { return fmod(v, 2) == 0 ? x : y; };

    template <typename _T>
    vex2<T> operator%(_T v) { return vex2<T>(std::rand() % int(v), std::rand() % int(v)); };
    template <typename _T>
    vex2<T> operator%(vex2<_T> v) { return vex2<T>(std::rand() % int(v.x), std::rand() % int(v.y)); };

    template <typename _T>
    vex2<T>& operator%=(_T v) { x = std::rand() % int(v); y = std::rand() % int(v); return *this; };
    template <typename _T>
    vex2<T>& operator%=(vex2<_T> v) { x = std::rand() % int(v.x); y = std::rand() % int(v.y); return *this; };

    vex2<T>& operator++() { x++; y++; return *this; };
    vex2<T>& operator--() { x--; y--; return *this; };

    template <typename _T>
    vex2<T>& operator+=(_T v) { x += T(v); y += T(v); return *this; };
    template<typename _T>
    vex2<T>& operator+=(vex2<_T> v) { x += T(v.x); y += T(v.y); return *this; };

    template <typename _T>
    vex2<T>& operator-=(_T v) { x -= T(v); y -= T(v); return *this; };
    template<typename _T>
    vex2<T>& operator-=(vex2<_T> v) { x -= T(v.x); y -= T(v.y); return *this; };

    template <typename _T>
    vex2<T>& operator*=(_T v) { x *= T(v); y *= T(v); return *this; };
    template<typename _T>
    vex2<T>& operator*=(vex2<_T> v) { x *= T(v.x); y *= T(v.y); return *this; };

    template <typename _T>
    vex2<T>& operator/=(_T v) { x /= T(v); y /= T(v); return *this; };
    template<typename _T>
    vex2<T>& operator/=(vex2<_T> v) { x /= T(v.x); y /= T(v.y); return *this; };

    template <typename _T>
    vex2<T> operator+(_T v) { return vex2<T>(this->x + T(v), this->y + T(v)); };
    template<typename _T>
    vex2<T> operator+(vex2<_T> v) { return vex2<T>(this->x + T(v.x), this->y + T(v.y)); };

    template <typename _T>
    vex2<T> operator-(_T v) { return vex2<T>(this->x - T(v), this->y - T(v)); };
    template<typename _T>
    vex2<T> operator-(vex2<_T> v) { return vex2<T>(this->x - T(v.x), this->y - T(v.y)); };

    template <typename _T>
    vex2<T> operator*(_T v) { return vex2<T>(this->x * T(v), this->y * T(v)); };
    template<typename _T>
    vex2<T> operator*(vex2<_T> v) { return vex2<T>(this->x * T(v.x), this->y * T(v.y)); };

    template <typename _T>
    vex2<T> operator/(_T v) { return vex2<T>(this->x / T(v), this->y / T(v)); };
    template<typename _T>
    vex2<T> operator/(vex2<_T> v) { return vex2<T>(this->x / T(v.x), this->y / T(v.y)); };

    template <typename _T>
    bool operator==(_T v) { return this->x == T(v) && this->y == T(v)); };
    template<typename _T>
    bool operator==(vex2<_T> v) { return this->x == T(v.x) && this->y == T(v.y)); };

    template <typename _T>
    bool operator!=(_T v) { return this->x != T(v) && this->y != T(v)); };
    template<typename _T>
    bool operator!=(vex2<_T> v) { return this->x != T(v.x) && this->y != T(v.y)); };

    template <typename _T>
    bool operator>(_T v) { return this->x > T(v) && this->y > T(v)); };
    template<typename _T>
    bool operator>(vex2<_T> v) { return this->x > T(v.x) && this->y > T(v.y)); };

    template <typename _T>
    bool operator<(_T v) { return this->x < T(v) && this->y < T(v)); };
    template<typename _T>
    bool operator<(vex2<_T> v) { return this->x < T(v.x) && this->y < T(v.y)); };

    template <typename _T>
    bool operator>=(_T v) { return this->x >= T(v) && this->y >= T(v)); };
    template<typename _T>
    bool operator>=(vex2<_T> v) { return this->x >= T(v.x) && this->y >= T(v.y)); };

    template <typename _T>
    bool operator<=(_T v) { return this->x <= T(v) && this->y <= T(v)); };
    template<typename _T>
    bool operator<=(vex2<_T> v) { return this->x <= T(v.x) && this->y <= T(v.y)); };

    friend std::ostream& operator<<(std::ostream& os, const vex2<T>& v) { os << v.x << ' ' << v.y; return os; };
};

template<> template<> vex2<float>::vex2(std::string v)  { x = y = std::atof(v.c_str()); };
template<> template<> vex2<int>::vex2(std::string v)    { x = y = std::atoi(v.c_str()); };
template<> template<> vex2<double>::vex2(std::string v) { x = y = std::atof(v.c_str()); };

template<> template<> vex2<float>::vex2(std::string v1, std::string v2) { x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); };
template<> template<> vex2<int>::vex2(std::string v1, std::string v2)   { x = std::atof(v1.c_str()); y = std::atoi(v2.c_str()); };
template<> template<> vex2<double>::vex2(std::string v1, std::string v2){ x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); };

template<> template<> vex2<float>& vex2<float>::operator=(std::string v)    { x = y = std::atof(v.c_str()); return *this; };
template<> template<> vex2<int>& vex2<int>::operator=(std::string v)        { x = y = std::atoi(v.c_str()); return *this; };
template<> template<> vex2<double>& vex2<double>::operator=(std::string v)  { x = y = std::atof(v.c_str()); return *this; };

typedef vex2<float> vex2f;
typedef vex2<int> vex2i;
typedef vex2<double> vex2d;
