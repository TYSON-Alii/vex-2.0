#define __VEX2IM_FUNCS__														\
operator ImVec2() const { return ImVec2(x, y); };								\
operator ImVec4() const { return ImVec4(x, y, NULL, NULL); };					\
vex2<T>& operator=(ImVec2 v)  { x  = T(v.x); y  = T(v.y); return *this; };		\
vex2<T>& operator=(ImVec4 v)  { x  = T(v.x); y  = T(v.y); return *this; };		\
vex2<T>& operator-=(ImVec2 v) { x -= T(v.x); y -= T(v.y); return *this; };		\
vex2<T>& operator-=(ImVec4 v) { x -= T(v.x); y -= T(v.y); return *this; };		\
vex2<T>& operator+=(ImVec2 v) { x += T(v.x); y += T(v.y); return *this; };		\
vex2<T>& operator+=(ImVec4 v) { x += T(v.x); y += T(v.y); return *this; };		\
vex2<T>& operator*=(ImVec2 v) { x *= T(v.x); y *= T(v.y); return *this; };		\
vex2<T>& operator*=(ImVec4 v) { x *= T(v.x); y *= T(v.y); return *this; };		\
vex2<T>& operator/=(ImVec2 v) { x /= T(v.x); y /= T(v.y); return *this; };		\
vex2<T>& operator/=(ImVec4 v) { x /= T(v.x); y /= T(v.y); return *this; };		\
vex2<T> operator-(ImVec2 v) const { return vex2<T>(x - T(v.x), y - T(v.y)); };	\
vex2<T> operator-(ImVec4 v) const { return vex2<T>(x - T(v.x), y - T(v.y)); };	\
vex2<T> operator+(ImVec2 v) const { return vex2<T>(x + T(v.x), y + T(v.y)); };	\
vex2<T> operator+(ImVec4 v) const { return vex2<T>(x + T(v.x), y + T(v.y)); };	\
vex2<T> operator*(ImVec2 v) const { return vex2<T>(x * T(v.x), y * T(v.y)); };	\
vex2<T> operator*(ImVec4 v) const { return vex2<T>(x * T(v.x), y * T(v.y)); };	\
vex2<T> operator/(ImVec2 v) const { return vex2<T>(x / T(v.x), y / T(v.y)); };	\
vex2<T> operator/(ImVec4 v) const { return vex2<T>(x / T(v.x), y / T(v.y)); };	\
bool operator==(ImVec2 v) const { return x == T(v.x) && y == T(v.y); };			\
bool operator==(ImVec4 v) const { return x == T(v.x) && y == T(v.y); };			\
bool operator!=(ImVec2 v) const { return x != T(v.x) && y != T(v.y); };			\
bool operator!=(ImVec4 v) const { return x != T(v.x) && y != T(v.y); };

#define __VEX3IM_FUNCS__																		\
operator ImVec2() const { return ImVec2(x, y); };											\
operator ImVec4() const { return ImVec4(x, y, z, NULL); };									\
vex3<T>& operator=(ImVec2 v)  { x  = T(v.x); y  = T(v.y); return *this; };					\
vex3<T>& operator=(ImVec4 v)  { x  = T(v.x); y  = T(v.y); z  = T(v.z); return *this; };		\
vex3<T>& operator-=(ImVec2 v) { x -= T(v.x); y -= T(v.y); return *this; };					\
vex3<T>& operator-=(ImVec4 v) { x -= T(v.x); y -= T(v.y); z -= T(v.z); return *this; };		\
vex3<T>& operator+=(ImVec2 v) { x += T(v.x); y += T(v.y); return *this; };					\
vex3<T>& operator+=(ImVec4 v) { x += T(v.x); y += T(v.y); z += T(v.z); return *this; };		\
vex3<T>& operator*=(ImVec2 v) { x *= T(v.x); y *= T(v.y); return *this; };					\
vex3<T>& operator*=(ImVec4 v) { x *= T(v.x); y *= T(v.y); z *= T(v.z); return *this; };		\
vex3<T>& operator/=(ImVec2 v) { x /= T(v.x); y /= T(v.y); return *this; };					\
vex3<T>& operator/=(ImVec4 v) { x /= T(v.x); y /= T(v.y); z /= T(v.z); return *this; };		\
vex3<T> operator-(ImVec2 v) const { return vex3<T>(x - T(v.x), y - T(v.y)); };				\
vex3<T> operator-(ImVec4 v) const { return vex3<T>(x - T(v.x), y - T(v.y), z - T(v.z)); };	\
vex3<T> operator+(ImVec2 v) const { return vex3<T>(x + T(v.x), y + T(v.y)); };				\
vex3<T> operator+(ImVec4 v) const { return vex3<T>(x + T(v.x), y + T(v.y), z + T(v.z)); };	\
vex3<T> operator*(ImVec2 v) const { return vex3<T>(x * T(v.x), y * T(v.y)); };				\
vex3<T> operator*(ImVec4 v) const { return vex3<T>(x * T(v.x), y * T(v.y), z * T(v.z)); };	\
vex3<T> operator/(ImVec2 v) const { return vex3<T>(x / T(v.x), y / T(v.y)); };				\
vex3<T> operator/(ImVec4 v) const { return vex3<T>(x / T(v.x), y / T(v.y), z / T(v.z)); };	\
bool operator==(ImVec2 v) const { return x == T(v.x) && y == T(v.y); };						\
bool operator==(ImVec4 v) const { return x == T(v.x) && y == T(v.y) && z == T(v.z); };		\
bool operator!=(ImVec2 v) const { return x != T(v.x) && y != T(v.y); };						\
bool operator!=(ImVec4 v) const { return x != T(v.x) && y != T(v.y) && z != T(v.z); };

#define __VEX4IM_FUNCS__																				\
operator ImVec2() const { return ImVec2(x, y); };														\
operator ImVec4() const { return ImVec4(x, y, z, w); };													\
vex4<T>& operator=(ImVec2 v)  { x  = T(v.x); y  = T(v.y); return *this; };								\
vex4<T>& operator=(ImVec4 v)  { x  = T(v.x); y  = T(v.y); z  = T(v.z); w  = T(v.w); return *this; };	\
vex4<T>& operator-=(ImVec2 v) { x -= T(v.x); y -= T(v.y); return *this; };								\
vex4<T>& operator-=(ImVec4 v) { x -= T(v.x); y -= T(v.y); z -= T(v.z); w -= T(v.w); return *this; };	\
vex4<T>& operator+=(ImVec2 v) { x += T(v.x); y += T(v.y); return *this; };								\
vex4<T>& operator+=(ImVec4 v) { x += T(v.x); y += T(v.y); z += T(v.z); w += T(v.w); return *this; };	\
vex4<T>& operator*=(ImVec2 v) { x *= T(v.x); y *= T(v.y); return *this; };								\
vex4<T>& operator*=(ImVec4 v) { x *= T(v.x); y *= T(v.y); z *= T(v.z); w *= T(v.w); return *this; };	\
vex4<T>& operator/=(ImVec2 v) { x /= T(v.x); y /= T(v.y); return *this; };								\
vex4<T>& operator/=(ImVec4 v) { x /= T(v.x); y /= T(v.y); z /= T(v.z); w /= T(v.w); return *this; };	\
vex4<T> operator-(ImVec2 v) const { return vex3<T>(x - T(v.x), y - T(v.y)); };							\
vex4<T> operator-(ImVec4 v) const { return vex3<T>(x - T(v.x), y - T(v.y), z - T(v.z), w - T(v.w)); };	\
vex4<T> operator+(ImVec2 v) const { return vex3<T>(x + T(v.x), y + T(v.y)); };							\
vex4<T> operator+(ImVec4 v) const { return vex3<T>(x + T(v.x), y + T(v.y), z + T(v.z), w + T(v.w)); };	\
vex4<T> operator*(ImVec2 v) const { return vex3<T>(x * T(v.x), y * T(v.y)); };							\
vex4<T> operator*(ImVec4 v) const { return vex3<T>(x * T(v.x), y * T(v.y), z * T(v.z), w * T(v.w)); };	\
vex4<T> operator/(ImVec2 v) const { return vex3<T>(x / T(v.x), y / T(v.y)); };							\
vex4<T> operator/(ImVec4 v) const { return vex3<T>(x / T(v.x), y / T(v.y), z / T(v.z), w / T(v.w)); };	\
bool operator==(ImVec2 v) const { return x == T(v.x) && y == T(v.y); };									\
bool operator==(ImVec4 v) const { return x == T(v.x) && y == T(v.y) && z == T(v.z) && w == T(v.w); };	\
bool operator!=(ImVec2 v) const { return x != T(v.x) && y != T(v.y); };									\
bool operator!=(ImVec4 v) const { return x != T(v.x) && y != T(v.y) && z != T(v.z) && w != T(v.w); };

#define __XSIMFUNCS__                                                                                                                                                 \
namespace ImGui {                                                                                                                                                     \
    void DragFloat2(const std::string& label, vex2f& v, float v_speed, float _min, float _max) {                                                                      \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::DragFloat2(label.c_str(), _v, v_speed, _min, _max);                                                                                                    \
        v = vex2f(_v[0], _v[1]);                                                                                                                                      \
    };                                                                                                                                                                \
    void DragFloat3(const std::string& label, vex3f& v, float v_speed, float _min, float _max) {                                                                      \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::DragFloat3(label.c_str(), _v, v_speed, _min, _max);                                                                                                    \
        v = vex3f(_v[0], _v[1], _v[2]);                                                                                                                               \
    };                                                                                                                                                                \
    void DragFloat4(const std::string& label, vex4f& v, float v_speed, float _min, float _max) {                                                                      \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::DragFloat4(label.c_str(), _v, v_speed, _min, _max);                                                                                                    \
        v = vex4f(_v[0], _v[1], _v[2], _v[3]);                                                                                                                        \
    };                                                                                                                                                                \
    void SliderFloat2(const std::string& label, vex2f& v, float _min, float _max) {                                                                                   \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::SliderFloat2(label.c_str(), _v, _min, _max);                                                                                                           \
        v = vex2f(_v[0], _v[1]);                                                                                                                                      \
    };                                                                                                                                                                \
    void SliderFloat3(const std::string& label, vex3f& v, float _min, float _max) {                                                                                   \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::SliderFloat3(label.c_str(), _v, _min, _max);                                                                                                           \
        v = vex3f(_v[0], _v[1], _v[2]);                                                                                                                               \
    };                                                                                                                                                                \
    void SliderFloat4(const std::string& label, vex4f& v, float _min, float _max) {                                                                                   \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::SliderFloat4(label.c_str(), _v, _min, _max);                                                                                                           \
        v = vex4f(_v[0], _v[1], _v[2], _v[3]);                                                                                                                        \
    };                                                                                                                                                                \
    void DragInt2(const std::string& label, vex2i& v, float v_speed, int _min, int _max) {                                                                            \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::DragInt2(label.c_str(), _v, v_speed, _min, _max);                                                                                                      \
        v = vex2i(_v[0], _v[1]);                                                                                                                                      \
    };                                                                                                                                                                \
    void DragInt3(const std::string& label, vex3i& v, float v_speed, int _min, int _max) {                                                                            \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::DragInt3(label.c_str(), _v, v_speed, _min, _max);                                                                                                      \
        v = vex3i(_v[0], _v[1], _v[2]);                                                                                                                               \
    };                                                                                                                                                                \
    void DragInt4(const std::string& label, vex4i& v, float v_speed, int _min, int _max) {                                                                            \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::DragInt4(label.c_str(), _v, v_speed, _min, _max);                                                                                                      \
        v = vex4i(_v[0], _v[1], _v[2], _v[3]);                                                                                                                        \
    };                                                                                                                                                                \
    void DragInt2(const std::string& label, vex2ui& v, float v_speed, size_t _min, size_t _max) {                                                                     \
        int _v[2]{ v.x, v.y };                                                                                                                                        \
        ImGui::DragInt2(label.c_str(), _v, v_speed, _min, _max);                                                                                                      \
        v = vex2i(_v[0], _v[1]);                                                                                                                                      \
    };                                                                                                                                                                \
    void DragInt3(const std::string& label, vex3ui& v, float v_speed, size_t _min, size_t _max) {                                                                     \
        int _v[3]{ v.x, v.y, v.z };                                                                                                                                   \
        ImGui::DragInt3(label.c_str(), _v, v_speed, _min, _max);                                                                                                      \
        v = vex3i(_v[0], _v[1], _v[2]);                                                                                                                               \
    };                                                                                                                                                                \
    void DragInt4(const std::string& label, vex4ui& v, float v_speed, size_t _min, size_t _max) {                                                                     \
        int _v[4]{ v.x, v.y, v.z, v.w };                                                                                                                              \
        ImGui::DragInt4(label.c_str(), _v, v_speed, _min, _max);                                                                                                      \
        v = vex4i(_v[0], _v[1], _v[2], _v[3]);                                                                                                                        \
    };                                                                                                                                                                \
    void SliderInt2(const std::string& label, vex2i& v, int _min, int _max) {                                                                                         \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::SliderInt2(label.c_str(), _v, _min, _max);                                                                                                             \
        v = vex2i(_v[0], _v[1]);                                                                                                                                      \
    };                                                                                                                                                                \
    void SliderInt3(const std::string& label, vex3i& v, int _min, int _max) {                                                                                         \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::SliderInt3(label.c_str(), _v, _min, _max);                                                                                                             \
        v = vex3i(_v[0], _v[1], _v[2]);                                                                                                                               \
    };                                                                                                                                                                \
    void SliderInt4(const std::string& label, vex4i& v, int _min, int _max) {                                                                                         \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::SliderInt4(label.c_str(), _v, _min, _max);                                                                                                             \
        v = vex4i(_v[0], _v[1], _v[2], _v[3]);                                                                                                                        \
    };                                                                                                                                                                \
    void ColorPicker4(const std::string& label, vex4f& v) {                                                                                                           \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::ColorPicker4(label.c_str(), _v);                                                                                                                       \
        v = vex4f(_v[0], _v[1], _v[2], _v[3]);                                                                                                                        \
    };                                                                                                                                                                \
    void ColorPicker3(const std::string& label, vex3f& v) {                                                                                                           \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::ColorPicker3(label.c_str(), _v);                                                                                                                       \
        v = vex3f(_v[0], _v[1], _v[2]);                                                                                                                               \
    };                                                                                                                                                                \
    void InputFloat2(const std::string& label, vex2f& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) {                                                \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::InputFloat2(label.c_str(), _v, format, flags);                                                                                                         \
        v = vex2f(_v[0], _v[1]);                                                                                                                                      \
    };                                                                                                                                                                \
    void InputFloat3(const std::string& label, vex3f& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) {                                                \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::InputFloat3(label.c_str(), _v, format, flags);                                                                                                         \
        v = vex3f(_v[0], _v[1], _v[2]);                                                                                                                               \
    };                                                                                                                                                                \
    void InputFloat4(const std::string& label, vex4f& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) {                                                \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::InputFloat4(label.c_str(), _v, format, flags);                                                                                                         \
        v = vex4f(_v[0], _v[1], _v[2], _v[3]);                                                                                                                        \
    };                                                                                                                                                                \
    void InputInt2(const std::string& label, vex2i& v, ImGuiInputTextFlags flags = 0) {                                                                               \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::InputInt2(label.c_str(), _v, flags);                                                                                                                   \
        v = vex2f(_v[0], _v[1]);                                                                                                                                      \
    };                                                                                                                                                                \
    void InputInt3(const std::string& label, vex3i& v, ImGuiInputTextFlags flags = 0) {                                                                               \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::InputInt3(label.c_str(), _v, flags);                                                                                                                   \
        v = vex3i(_v[0], _v[1], _v[2]);                                                                                                                               \
    };                                                                                                                                                                \
    void InputInt4(const std::string& label, vex4i& v, ImGuiInputTextFlags flags = 0) {                                                                               \
        auto _v = v.arr();                                                                                                                                            \
        ImGui::InputInt4(label.c_str(), _v, flags);                                                                                                                   \
        v = vex4i(_v[0], _v[1], _v[2], _v[3]);                                                                                                                        \
    };                                                                                                                                                                \
    inline void InputFloat(const std::string& label, vex2f& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { InputFloat2(label, v, format, flags); }; \
    inline void InputFloat(const std::string& label, vex3f& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { InputFloat3(label, v, format, flags); }; \
    inline void InputFloat(const std::string& label, vex4f& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { InputFloat4(label, v, format, flags); }; \
    inline void InputInt(const std::string& label, vex2i& v, ImGuiInputTextFlags flags = 0) { InputInt2(label, v, flags); };                                          \
    inline void InputInt(const std::string& label, vex3i& v, ImGuiInputTextFlags flags = 0) { InputInt3(label, v, flags); };                                          \
    inline void InputInt(const std::string& label, vex4i& v, ImGuiInputTextFlags flags = 0) { InputInt4(label, v, flags); };                                          \
    inline void Input(const std::string& label, vex2f& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { InputFloat2(label, v, format, flags); };      \
    inline void Input(const std::string& label, vex3f& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { InputFloat3(label, v, format, flags); };      \
    inline void Input(const std::string& label, vex4f& v, const char* format = "%.3f", ImGuiInputTextFlags flags = 0) { InputFloat4(label, v, format, flags); };      \
    inline void Input(const std::string& label, vex2i& v, ImGuiInputTextFlags flags = 0) { InputInt2(label, v, flags); };                                             \
    inline void Input(const std::string& label, vex3i& v, ImGuiInputTextFlags flags = 0) { InputInt3(label, v, flags); };                                             \
    inline void Input(const std::string& label, vex4i& v, ImGuiInputTextFlags flags = 0) { InputInt4(label, v, flags); };                                             \
    inline void DragFloat(const std::string& label, vex2f& v, float v_speed, float _min, float _max) { DragFloat2(label, v, v_speed, _min, _max); };                  \
    inline void DragFloat(const std::string& label, vex3f& v, float v_speed, float _min, float _max) { DragFloat3(label, v, v_speed, _min, _max); };                  \
    inline void DragFloat(const std::string& label, vex4f& v, float v_speed, float _min, float _max) { DragFloat4(label, v, v_speed, _min, _max); };                  \
    inline void DragInt(const std::string& label, vex2i& v, int v_speed, int _min, int _max) { DragInt2(label, v, v_speed, _min, _max); };                            \
    inline void DragInt(const std::string& label, vex3i& v, int v_speed, int _min, int _max) { DragInt3(label, v, v_speed, _min, _max); };                            \
    inline void DragInt(const std::string& label, vex4i& v, int v_speed, int _min, int _max) { DragInt4(label, v, v_speed, _min, _max); };                            \
    inline void Drag(const std::string& label, vex2f& v, float v_speed, float _min, float _max) { DragFloat2(label, v, v_speed, _min, _max); };                       \
    inline void Drag(const std::string& label, vex3f& v, float v_speed, float _min, float _max) { DragFloat3(label, v, v_speed, _min, _max); };                       \
    inline void Drag(const std::string& label, vex4f& v, float v_speed, float _min, float _max) { DragFloat4(label, v, v_speed, _min, _max); };                       \
    inline void Drag(const std::string& label, vex2i& v, int v_speed, int _min, int _max) { DragInt2(label, v, v_speed, _min, _max); };                               \
    inline void Drag(const std::string& label, vex3i& v, int v_speed, int _min, int _max) { DragInt3(label, v, v_speed, _min, _max); };                               \
    inline void Drag(const std::string& label, vex4i& v, int v_speed, int _min, int _max) { DragInt4(label, v, v_speed, _min, _max); };                               \
    inline void SliderFloat(const std::string& label, vex2f& v, float _min, float _max) { SliderFloat2(label, v, _min, _max); };                                      \
    inline void SliderFloat(const std::string& label, vex3f& v, float _min, float _max) { SliderFloat3(label, v, _min, _max); };                                      \
    inline void SliderFloat(const std::string& label, vex4f& v, float _min, float _max) { SliderFloat4(label, v, _min, _max); };                                      \
    inline void SliderInt(const std::string& label, vex2i& v, int _min, int _max) { SliderInt2(label, v, _min, _max); };                                              \
    inline void SliderInt(const std::string& label, vex3i& v, int _min, int _max) { SliderInt3(label, v, _min, _max); };                                              \
    inline void SliderInt(const std::string& label, vex4i& v, int _min, int _max) { SliderInt4(label, v, _min, _max); };                                              \
    inline void Slider(const std::string& label, vex2f& v, float _min, float _max) { SliderFloat2(label, v, _min, _max); };                                           \
    inline void Slider(const std::string& label, vex3f& v, float _min, float _max) { SliderFloat3(label, v, _min, _max); };                                           \
    inline void Slider(const std::string& label, vex4f& v, float _min, float _max) { SliderFloat4(label, v, _min, _max); };                                           \
    inline void Slider(const std::string& label, vex2i& v, int _min, int _max) { SliderInt2(label, v, _min, _max); };                                                 \
    inline void Slider(const std::string& label, vex3i& v, int _min, int _max) { SliderInt3(label, v, _min, _max); };                                                 \
    inline void Slider(const std::string& label, vex4i& v, int _min, int _max) { SliderInt4(label, v, _min, _max); };
};