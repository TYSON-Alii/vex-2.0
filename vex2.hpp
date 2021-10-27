template <typename T>
struct vex2 {
    T x, y;
    vex2() = default;
    vex2(const vex2<T>&) = default;

    template <typename _T>
    vex2(_T v) { x = y = T(v); };
    
    template <typename _T1, typename _T2>
    vex2(_T1 v1, _T2 v2) { x = T(v1); y = T(v2); };

    template <typename _T>
    vex2<T>& operator=(_T v) { x = y = T(v); return *this; };
};

template<> template<> vex2<float>::vex2<std::string>(std::string v) { x = y = std::atof(v.c_str()); };
template<> template<> vex2<float>::vex2<std::string, std::string>(std::string v1, std::string v2) { x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); };
template<> template<> vex2<float>& vex2<float>::operator=<vex2<int>>(vex2<int> v) { x = v.x; y = v.y; return *this; };

template<> template<> vex2<int>::vex2<std::string>(std::string v) { x = y = std::atof(v.c_str()); };
template<> template<> vex2<int>::vex2<std::string, std::string>(std::string v1, std::string v2) { x = std::atoi(v1.c_str()); y = std::atoi(v2.c_str()); };

template<> template<> vex2<double>::vex2<std::string>(std::string v) { x = y = std::atof(v.c_str()); };
template<> template<> vex2<double>::vex2<std::string, std::string>(std::string v1, std::string v2) { x = std::atof(v1.c_str()); y = std::atof(v2.c_str()); };


typedef vex2<float> vex2f;
typedef vex2<int> vex2f;
