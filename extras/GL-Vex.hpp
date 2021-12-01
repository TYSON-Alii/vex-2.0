inline void glColor3f(vex3f v) { glColor3f(v.x, v.y, v.z); };
inline void glColor3f(vex4f v) { glColor3f(v.x, v.y, v.z); };
inline void glColor3i(vex3i v) { glColor3i(v.x, v.y, v.z); };
inline void glColor3f(vex2f v, float v1) { glColor3f(v.x, v.y, v1); };
inline void glColor3f(float v1, vex2f v) { glColor3f(v1, v.x, v.y); };
inline void glColor4f(vex3f v) { glColor4f(v.x, v.y, v.z, 1); };
inline void glColor4i(vex3i v) { glColor4i(float(v.x) / 256.f, float(v.y) / 256.f, float(v.z) / 256.f, 1.f); };
inline void glColor4f(vex4f v) { glColor4f(v.x, v.y, v.z, v.w); };
inline void glColor4i(vex4i v) { glColor4i(float(v.x) / 256.f, float(v.y) / 256.f, float(v.z) / 256.f, float(v.w) / 256.f); };
inline void glColor4f(vex3f v, float v1) { glColor4f(v.x, v.y, v.z, v1); };
inline void glColor4f(float v1, vex3f v) { glColor4f(v1, v.x, v.y, v.z); };
inline void glColor4f(vex2f v, float v1, float v2) { glColor4f(v.x, v.y, v1, v2); };
inline void glColor4f(float v1, vex2f v, float v2) { glColor4f(v1, v.x, v.y, v2); };
inline void glColor4f(float v1, float v2, vex2f v) { glColor4f(v1, v2, v.x, v.y); };

inline void glTranslatef(vex2f v) { glTranslatef(v.x, v.y, 0); };
inline void glTranslatef(vex2f v, float v1) { glTranslatef(v.x, v.y, v1); };
inline void glTranslatef(vex3f v) { glTranslatef(v.x, v.y, v.z); };
inline void glTranslatef(vex4f v) { glTranslatef(v.x, v.y, v.z); };

inline void glRotatef(float v1, vex3f v) { glRotatef(v1, v.x, v.y, v.z); };
inline void glRotatef(vex3f v, float v1) { glRotatef(v1, v.x, v.y, v.z); };
inline void glRotatef(float v1, vex3d v) { glRotatef(v1, v.x, v.y, v.z); };
inline void glRotatef(vex3d v, float v1) { glRotatef(v1, v.x, v.y, v.z); };
inline void glRotatef(vex3f v) { glRotatef(v.x, 1, 0, 0); glRotatef(v.y, 0, 1, 0); glRotatef(v.z, 0, 0, 1); };
inline void glRotatef(vex4f v) { glRotatef(v.w, v.x, v.y, v.z); };
inline void glRotatef(vex4d v) { glRotatef(v.w, v.x, v.y, v.z); };

template <typename T> inline void glScalef(vex2<T> v) { glScalef(float(v.x), float(v.y), 1.f); };
template <typename T> inline void glScalef(vex3<T> v) { glScalef(float(v.x), float(v.y), float(v.z)); };
template <typename T> inline void glScalef(vex4<T> v) { glScalef(float(v.x), float(v.y), float(v.z)); };

template <typename T> inline void glVertex3f(T v) { glVertex3f(float(v), float(v), float(v)); };
template <typename T> inline void glVertex3f(vex2<T> v) { glVertex3f(float(v.x), float(v.y), 0.f); };
template <typename T> inline void glVertex3f(vex3<T> v) { glVertex3f(float(v.x), float(v.y), float(v.z)); };
template <typename T> inline void glVertex3f(vex4<T> v) { glVertex3f(float(v.x), float(v.y), float(v.z)); };
template <typename T> inline void glVertex2f(vex2<T> v) { glVertex2f(float(v.x), float(v.y)); };
template <typename T> inline void glVertex2f(vex3<T> v) { glVertex2f(float(v.x), float(v.y)); };
template <typename T> inline void glVertex2f(vex4<T> v) { glVertex2f(float(v.x), float(v.y)); };
