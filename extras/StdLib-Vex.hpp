#include <sstream>
#define __XSSTDLIB_FUNCS__ namespace std {                                         \
    inline vex2f    ceil(vex2f v) { return v.ceil(); };                            \
    inline vex2d    ceil(vex2d v) { return v.ceil(); };                            \
    inline vex2f    floor(vex2f v) { return v.floor(); };                          \
    inline vex2d    floor(vex2d v) { return v.floor(); };                          \
    inline vex2f    abs(vex2f v) { return v.floor(); };                            \
    inline vex2d    abs(vex2d v) { return v.floor(); };                            \
    inline vex2f    round(vex2f v) { return v.round(); };                          \
    inline vex2d    round(vex2d v) { return v.round(); };                          \
    inline vex2f    trunc(vex2f v) { return v.trunc(); };                          \
    inline vex2d    trunc(vex2d v) { return v.trunc(); };                          \
    inline vex2f    exp(vex2f v) { return v.exp(); };                              \
    inline vex2d    exp(vex2d v) { return v.exp(); };                              \
    inline vex2f    sqrt(vex2f v) { return v.sqrt(); };                            \
    inline vex2d    sqrt(vex2d v) { return v.sqrt(); };                            \
    inline vex2i    sqrt(vex2i v) { return v.sqrt(); };                            \
    inline vex2li   sqrt(vex2li v) { return v.sqrt(); };                           \
    inline vex2lli  sqrt(vex2lli v) { return v.sqrt(); };                          \
    inline vex2f    cbrt(vex2f v) { return v.cbrt(); };                            \
    inline vex2d    cbrt(vex2d v) { return v.cbrt(); };                            \
    inline vex2i    cbrt(vex2i v) { return v.cbrt(); };                            \
    inline vex2li   cbrt(vex2li v) { return v.cbrt(); };                           \
    inline vex2lli  cbrt(vex2lli v) { return v.cbrt(); };                          \
    inline vex2f    pow(vex2f v, int p) { return v.pow(p); };                      \
    inline vex2d    pow(vex2d v, int p) { return v.pow(p); };                      \
    inline vex2i    pow(vex2i v, int p) { return v.pow(p); };                      \
    inline vex2li   pow(vex2li v, int p) { return v.pow(p); };                     \
    inline vex2lli  pow(vex2lli v, int p) { return v.pow(p); };                    \
    inline vex2f& max(vex2f& v1, vex2f& v2) { return (v1 > v2) ? v1 : v2; };       \
    inline vex2d& max(vex2d& v1, vex2d& v2) { return (v1 > v2) ? v1 : v2; };       \
    inline vex2i& max(vex2i& v1, vex2i& v2) { return (v1 > v2) ? v1 : v2; };       \
    inline vex2li& max(vex2li& v1, vex2li& v2) { return (v1 > v2) ? v1 : v2; };    \
    inline vex2lli& max(vex2lli& v1, vex2lli& v2) { return (v1 > v2) ? v1 : v2; }; \
    inline vex2f& min(vex2f& v1, vex2f& v2) { return (v1 < v2) ? v1 : v2; };       \
    inline vex2d& min(vex2d& v1, vex2d& v2) { return (v1 < v2) ? v1 : v2; };       \
    inline vex2i& min(vex2i& v1, vex2i& v2) { return (v1 < v2) ? v1 : v2; };       \
    inline vex2li& min(vex2li& v1, vex2li& v2) { return (v1 < v2) ? v1 : v2; };    \
    inline vex2lli& min(vex2lli& v1, vex2lli& v2) { return (v1 < v2) ? v1 : v2; }; \
    inline vex3f    ceil(vex3f v) { return v.ceil(); };                            \
    inline vex3d    ceil(vex3d v) { return v.ceil(); };                            \
    inline vex3f    floor(vex3f v) { return v.floor(); };                          \
    inline vex3d    floor(vex3d v) { return v.floor(); };                          \
    inline vex3f    abs(vex3f v) { return v.floor(); };                            \
    inline vex3d    abs(vex3d v) { return v.floor(); };                            \
    inline vex3f    round(vex3f v) { return v.round(); };                          \
    inline vex3d    round(vex3d v) { return v.round(); };                          \
    inline vex3f    trunc(vex3f v) { return v.trunc(); };                          \
    inline vex3d    trunc(vex3d v) { return v.trunc(); };                          \
    inline vex3f    exp(vex3f v) { return v.exp(); };                              \
    inline vex3d    exp(vex3d v) { return v.exp(); };                              \
    inline vex3f    sqrt(vex3f v) { return v.sqrt(); };                            \
    inline vex3d    sqrt(vex3d v) { return v.sqrt(); };                            \
    inline vex3i    sqrt(vex3i v) { return v.sqrt(); };                            \
    inline vex3li   sqrt(vex3li v) { return v.sqrt(); };                           \
    inline vex3lli  sqrt(vex3lli v) { return v.sqrt(); };                          \
    inline vex3f    cbrt(vex3f v) { return v.cbrt(); };                            \
    inline vex3d    cbrt(vex3d v) { return v.cbrt(); };                            \
    inline vex3i    cbrt(vex3i v) { return v.cbrt(); };                            \
    inline vex3li   cbrt(vex3li v) { return v.cbrt(); };                           \
    inline vex3lli  cbrt(vex3lli v) { return v.cbrt(); };                          \
    inline vex3f    pow(vex3f v, int p) { return v.pow(p); };                      \
    inline vex3d    pow(vex3d v, int p) { return v.pow(p); };                      \
    inline vex3i    pow(vex3i v, int p) { return v.pow(p); };                      \
    inline vex3li   pow(vex3li v, int p) { return v.pow(p); };                     \
    inline vex3lli  pow(vex3lli v, int p) { return v.pow(p); };                    \
    inline vex3f& max(vex3f& v1, vex3f& v2) { return (v1 > v2) ? v1 : v2; };       \
    inline vex3d& max(vex3d& v1, vex3d& v2) { return (v1 > v2) ? v1 : v2; };       \
    inline vex3i& max(vex3i& v1, vex3i& v2) { return (v1 > v2) ? v1 : v2; };       \
    inline vex3li& max(vex3li& v1, vex3li& v2) { return (v1 > v2) ? v1 : v2; };    \
    inline vex3lli& max(vex3lli& v1, vex3lli& v2) { return (v1 > v2) ? v1 : v2; }; \
    inline vex3f& min(vex3f& v1, vex3f& v2) { return (v1 < v2) ? v1 : v2; };       \
    inline vex3d& min(vex3d& v1, vex3d& v2) { return (v1 < v2) ? v1 : v2; };       \
    inline vex3i& min(vex3i& v1, vex3i& v2) { return (v1 < v2) ? v1 : v2; };       \
    inline vex3li& min(vex3li& v1, vex3li& v2) { return (v1 < v2) ? v1 : v2; };    \
    inline vex3lli& min(vex3lli& v1, vex3lli& v2) { return (v1 < v2) ? v1 : v2; }; \
    inline vex4f    ceil(vex4f v) { return v.ceil(); };                            \
    inline vex4d    ceil(vex4d v) { return v.ceil(); };                            \
    inline vex4f    floor(vex4f v) { return v.floor(); };                          \
    inline vex4d    floor(vex4d v) { return v.floor(); };                          \
    inline vex4f    abs(vex4f v) { return v.floor(); };                            \
    inline vex4d    abs(vex4d v) { return v.floor(); };                            \
    inline vex4f    round(vex4f v) { return v.round(); };                          \
    inline vex4d    round(vex4d v) { return v.round(); };                          \
    inline vex4f    trunc(vex4f v) { return v.trunc(); };                          \
    inline vex4d    trunc(vex4d v) { return v.trunc(); };                          \
    inline vex4f    exp(vex4f v) { return v.exp(); };                              \
    inline vex4d    exp(vex4d v) { return v.exp(); };                              \
    inline vex4f    sqrt(vex4f v) { return v.sqrt(); };                            \
    inline vex4d    sqrt(vex4d v) { return v.sqrt(); };                            \
    inline vex4i    sqrt(vex4i v) { return v.sqrt(); };                            \
    inline vex4li   sqrt(vex4li v) { return v.sqrt(); };                           \
    inline vex4lli  sqrt(vex4lli v) { return v.sqrt(); };                          \
    inline vex4f    cbrt(vex4f v) { return v.cbrt(); };                            \
    inline vex4d    cbrt(vex4d v) { return v.cbrt(); };                            \
    inline vex4i    cbrt(vex4i v) { return v.cbrt(); };                            \
    inline vex4li   cbrt(vex4li v) { return v.cbrt(); };                           \
    inline vex4lli  cbrt(vex4lli v) { return v.cbrt(); };                          \
    inline vex4f    pow(vex4f v, int p) { return v.pow(p); };                      \
    inline vex4d    pow(vex4d v, int p) { return v.pow(p); };                      \
    inline vex4i    pow(vex4i v, int p) { return v.pow(p); };                      \
    inline vex4li   pow(vex4li v, int p) { return v.pow(p); };                     \
    inline vex4lli  pow(vex4lli v, int p) { return v.pow(p); };                    \
    inline vex4f& max(vex4f& v1, vex4f& v2) { return (v1 > v2) ? v1 : v2; };       \
    inline vex4d& max(vex4d& v1, vex4d& v2) { return (v1 > v2) ? v1 : v2; };       \
    inline vex4i& max(vex4i& v1, vex4i& v2) { return (v1 > v2) ? v1 : v2; };       \
    inline vex4li& max(vex4li& v1, vex4li& v2) { return (v1 > v2) ? v1 : v2; };    \
    inline vex4lli& max(vex4lli& v1, vex4lli& v2) { return (v1 > v2) ? v1 : v2; }; \
    inline vex4f& min(vex4f& v1, vex4f& v2) { return (v1 < v2) ? v1 : v2; };       \
    inline vex4d& min(vex4d& v1, vex4d& v2) { return (v1 < v2) ? v1 : v2; };       \
    inline vex4i& min(vex4i& v1, vex4i& v2) { return (v1 < v2) ? v1 : v2; };       \
    inline vex4li& min(vex4li& v1, vex4li& v2) { return (v1 < v2) ? v1 : v2; };    \
    inline vex4lli& min(vex4lli& v1, vex4lli& v2) { return (v1 < v2) ? v1 : v2; }; \
    vex2f strtov2f(const std::string& _s) {                                        \
        stringstream ss;                                                           \
        string s;                                                                  \
        vex2f t;                                                                   \
        ss << _s;                                                                  \
        for (size_t i = 0u; i < 2u and ss >> s; i++)                               \
            t[i] = stof(s);                                                        \
        return t;                                                                  \
    };                                                                             \
    vex2d strtov2d(const std::string& _s) {                                        \
        stringstream ss;                                                           \
        string s;                                                                  \
        vex2d t;                                                                   \
        ss << _s;                                                                  \
        for (size_t i = 0u; i < 2u and ss >> s; i++)                               \
            t[i] = stod(s);                                                        \
        return t;                                                                  \
    };                                                                             \
    vex2i strtov2i(const std::string& _s) {                                        \
        stringstream ss;                                                           \
        string s;                                                                  \
        vex2i t;                                                                   \
        ss << _s;                                                                  \
        for (size_t i = 0u; i < 2u and ss >> s; i++)                               \
            t[i] = stoi(s);                                                        \
        return t;                                                                  \
    };                                                                             \
    vex3f strtov3f(const std::string& _s) {                                        \
        stringstream ss;                                                           \
        string s;                                                                  \
        vex3f t;                                                                   \
        ss << _s;                                                                  \
        for (size_t i = 0u; i < 3u and ss >> s; i++)                               \
            t[i] = stof(s);                                                        \
        return t;                                                                  \
    };                                                                             \
    vex3d strtov3d(const std::string& _s) {                                        \
        stringstream ss;                                                           \
        string s;                                                                  \
        vex3d t;                                                                   \
        ss << _s;                                                                  \
        for (size_t i = 0u; i < 3u and ss >> s; i++)                               \
            t[i] = stod(s);                                                        \
        return t;                                                                  \
    };                                                                             \
    vex3i strtov3i(const std::string& _s) {                                        \
        stringstream ss;                                                           \
        string s;                                                                  \
        vex3i t;                                                                   \
        ss << _s;                                                                  \
        for (size_t i = 0u; i < 3u and ss >> s; i++)                               \
            t[i] = stoi(s);                                                        \
        return t;                                                                  \
    };                                                                             \
    vex4f strtov4f(const std::string& _s) {                                        \
        stringstream ss;                                                           \
        string s;                                                                  \
        vex4f t;                                                                   \
        ss << _s;                                                                  \
        for (size_t i = 0u; i < 4u and ss >> s; i++)                               \
            t[i] = stof(s);                                                        \
        return t;                                                                  \
    };                                                                             \
    vex4d strtov4d(const std::string& _s) {                                        \
        stringstream ss;                                                           \
        string s;                                                                  \
        vex4d t;                                                                   \
        ss << _s;                                                                  \
        for (size_t i = 0u; i < 4u and ss >> s; i++)                               \
            t[i] = stod(s);                                                        \
        return t;                                                                  \
    };                                                                             \
    vex4i strtov4i(const std::string& _s) {                                        \
        stringstream ss;                                                           \
        string s;                                                                  \
        vex4i t;                                                                   \
        ss << _s;                                                                  \
        for (size_t i = 0u; i < 4u and ss >> s; i++)                               \
            t[i] = stoi(s);                                                        \
        return t;                                                                  \
    };                                                                             \
};
