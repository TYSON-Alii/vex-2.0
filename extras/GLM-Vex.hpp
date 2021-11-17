#define __VEX2GLM_FUNCS__													\
operator glm::vec2() const { return glm::vec2(x, y); };                     \
operator glm::vec3() const { return glm::vec3(x, y, NULL); };               \
operator glm::vec4() const { return glm::vec4(x, y, NULL, NULL); };         \
vex2<T>& operator=(glm::vec2 v) { x = v.x; y = v.y; return *this; };        \
vex2<T>& operator=(glm::vec3 v) { x = v.x; y = v.y; return *this; };        \
vex2<T>& operator=(glm::vec4 v) { x = v.x; y = v.y; return *this; };        \
vex2<T>& operator-=(glm::vec2 v) { x -= v.x; y -= v.y; return *this; };     \
vex2<T>& operator-=(glm::vec3 v) { x -= v.x; y -= v.y; return *this; };     \
vex2<T>& operator-=(glm::vec4 v) { x -= v.x; y -= v.y; return *this; };     \
vex2<T>& operator+=(glm::vec2 v) { x += v.x; y += v.y; return *this; };     \
vex2<T>& operator+=(glm::vec3 v) { x += v.x; y += v.y; return *this; };     \
vex2<T>& operator+=(glm::vec4 v) { x += v.x; y += v.y; return *this; };     \
vex2<T>& operator*=(glm::vec2 v) { x *= v.x; y *= v.y; return *this; };     \
vex2<T>& operator*=(glm::vec3 v) { x *= v.x; y *= v.y; return *this; };     \
vex2<T>& operator*=(glm::vec4 v) { x *= v.x; y *= v.y; return *this; };     \
vex2<T>& operator/=(glm::vec2 v) { x /= v.x; y /= v.y; return *this; };     \
vex2<T>& operator/=(glm::vec3 v) { x /= v.x; y /= v.y; return *this; };     \
vex2<T>& operator/=(glm::vec4 v) { x /= v.x; y /= v.y; return *this; };     \
vex2<T> operator-(glm::vec2 v) const { return vex2<T>(x - v.x, y - v.y); }; \
vex2<T> operator-(glm::vec3 v) const { return vex2<T>(x - v.x, y - v.y); }; \
vex2<T> operator-(glm::vec4 v) const { return vex2<T>(x - v.x, y - v.y); }; \
vex2<T> operator+(glm::vec2 v) const { return vex2<T>(x + v.x, y + v.y); }; \
vex2<T> operator+(glm::vec3 v) const { return vex2<T>(x + v.x, y + v.y); }; \
vex2<T> operator+(glm::vec4 v) const { return vex2<T>(x + v.x, y + v.y); }; \
vex2<T> operator*(glm::vec2 v) const { return vex2<T>(x * v.x, y * v.y); }; \
vex2<T> operator*(glm::vec3 v) const { return vex2<T>(x * v.x, y * v.y); }; \
vex2<T> operator*(glm::vec4 v) const { return vex2<T>(x * v.x, y * v.y); }; \
vex2<T> operator/(glm::vec2 v) const { return vex2<T>(x / v.x, y / v.y); }; \
vex2<T> operator/(glm::vec3 v) const { return vex2<T>(x / v.x, y / v.y); }; \
vex2<T> operator/(glm::vec4 v) const { return vex2<T>(x / v.x, y / v.y); }; \
bool operator==(glm::vec2 v) const { return x == v.x && y == v.y; };        \
bool operator==(glm::vec3 v) const { return x == v.x && y == v.y; };        \
bool operator==(glm::vec4 v) const { return x == v.x && y == v.y; };        \
bool operator!=(glm::vec2 v) const { return x != v.x && y != v.y; };        \
bool operator!=(glm::vec3 v) const { return x != v.x && y != v.y; };        \
bool operator!=(glm::vec4 v) const { return x != v.x && y != v.y; };

#define __VEX3GLM_FUNCS__															 \
operator glm::vec2() const { return glm::vec2(x, y); };								 \
operator glm::vec3() const { return glm::vec3(x, y, z); };							 \
operator glm::vec4() const { return glm::vec4(x, y, z, NULL); };					 \
vex3<T>& operator=(glm::vec2 v) { x = v.x; y = v.y; return *this; };				 \
vex3<T>& operator=(glm::vec3 v) { x = v.x; y = v.y; z = v.z; return *this; };		 \
vex3<T>& operator=(glm::vec4 v) { x = v.x; y = v.y; z = v.z; return *this; };		 \
vex3<T>& operator-=(glm::vec2 v) { x -= v.x; y -= v.y; return *this; };				 \
vex3<T>& operator-=(glm::vec3 v) { x -= v.x; y -= v.y; z -= v.z; return *this; };	 \
vex3<T>& operator-=(glm::vec4 v) { x -= v.x; y -= v.y; z -= v.z; return *this; };	 \
vex3<T>& operator+=(glm::vec2 v) { x += v.x; y += v.y; return *this; };				 \
vex3<T>& operator+=(glm::vec3 v) { x += v.x; y += v.y; z += v.z; return *this; };	 \
vex3<T>& operator+=(glm::vec4 v) { x += v.x; y += v.y; z += v.z; return *this; };	 \
vex3<T>& operator*=(glm::vec2 v) { x *= v.x; y *= v.y; return *this; };				 \
vex3<T>& operator*=(glm::vec3 v) { x *= v.x; y *= v.y; z *= v.z; return *this; };	 \
vex3<T>& operator*=(glm::vec4 v) { x *= v.x; y *= v.y; z *= v.z; return *this; };	 \
vex3<T>& operator/=(glm::vec2 v) { x /= v.x; y /= v.y; return *this; };				 \
vex3<T>& operator/=(glm::vec3 v) { x /= v.x; y /= v.y; z /= v.z; return *this; };	 \
vex3<T>& operator/=(glm::vec4 v) { x /= v.x; y /= v.y; z /= v.z; return *this; };	 \
vex3<T> operator-(glm::vec2 v) const { return vex3<T>(x - v.x, y - v.y); };			 \
vex3<T> operator-(glm::vec3 v) const { return vex3<T>(x - v.x, y - v.y, z - v.z); }; \
vex3<T> operator-(glm::vec4 v) const { return vex3<T>(x - v.x, y - v.y, z - v.z); }; \
vex3<T> operator+(glm::vec2 v) const { return vex3<T>(x + v.x, y + v.y); };			 \
vex3<T> operator+(glm::vec3 v) const { return vex3<T>(x + v.x, y + v.y, z + v.z); }; \
vex3<T> operator+(glm::vec4 v) const { return vex3<T>(x + v.x, y + v.y, z + v.z); }; \
vex3<T> operator*(glm::vec2 v) const { return vex3<T>(x * v.x, y * v.y); };			 \
vex3<T> operator*(glm::vec3 v) const { return vex3<T>(x * v.x, y * v.y, z * v.z); }; \
vex3<T> operator*(glm::vec4 v) const { return vex3<T>(x * v.x, y * v.y, z * v.z); }; \
vex3<T> operator/(glm::vec2 v) const { return vex3<T>(x / v.x, y / v.y); };			 \
vex3<T> operator/(glm::vec3 v) const { return vex3<T>(x / v.x, y / v.y, z / v.z); }; \
vex3<T> operator/(glm::vec4 v) const { return vex3<T>(x / v.x, y / v.y, z / v.z); }; \
bool operator==(glm::vec2 v) const { return x == v.x && y == v.y; };				 \
bool operator==(glm::vec3 v) const { return x == v.x && y == v.y && z == v.z; };	 \
bool operator==(glm::vec4 v) const { return x == v.x && y == v.y && z == v.z; };	 \
bool operator!=(glm::vec2 v) const { return x != v.x && y != v.y; };				 \
bool operator!=(glm::vec3 v) const { return x != v.x && y != v.y && z != v.z; };	 \
bool operator!=(glm::vec4 v) const { return x != v.x && y != v.y && z != v.z; };

#define __VEX4GLM_FUNCS__																	  \
operator glm::vec2() const { return glm::vec2(x, y); };										  \
operator glm::vec3() const { return glm::vec3(x, y, z); };									  \
operator glm::vec4() const { return glm::vec4(x, y, z, w); };								  \
vex4<T>& operator=(glm::vec2 v) { x = v.x; y = v.y; return *this; };						  \
vex4<T>& operator=(glm::vec3 v) { x = v.x; y = v.y; z = v.z; return *this; };				  \
vex4<T>& operator=(glm::vec4 v) { x = v.x; y = v.y; z = v.z; w = v.w; return *this; };		  \
vex4<T>& operator-=(glm::vec2 v) { x -= v.x; y -= v.y; return *this; };						  \
vex4<T>& operator-=(glm::vec3 v) { x -= v.x; y -= v.y; z -= v.z; return *this; };			  \
vex4<T>& operator-=(glm::vec4 v) { x -= v.x; y -= v.y; z -= v.z; w -= v.w; return *this; };	  \
vex4<T>& operator+=(glm::vec2 v) { x += v.x; y += v.y; return *this; };						  \
vex4<T>& operator+=(glm::vec3 v) { x += v.x; y += v.y; z += v.z; return *this; };			  \
vex4<T>& operator+=(glm::vec4 v) { x += v.x; y += v.y; z += v.z; w += v.w; return *this; };	  \
vex4<T>& operator*=(glm::vec2 v) { x *= v.x; y *= v.y; return *this; };						  \
vex4<T>& operator*=(glm::vec3 v) { x *= v.x; y *= v.y; z *= v.z; return *this; };			  \
vex4<T>& operator*=(glm::vec4 v) { x *= v.x; y *= v.y; z *= v.z; w *= v.w; return *this; };	  \
vex4<T>& operator/=(glm::vec2 v) { x /= v.x; y /= v.y; return *this; };						  \
vex4<T>& operator/=(glm::vec3 v) { x /= v.x; y /= v.y; z /= v.z; return *this; };			  \
vex4<T>& operator/=(glm::vec4 v) { x /= v.x; y /= v.y; z /= v.z; w /= v.w; return *this; };	  \
vex4<T> operator-(glm::vec2 v) const { return vex3<T>(x - v.x, y - v.y); };					  \
vex4<T> operator-(glm::vec3 v) const { return vex3<T>(x - v.x, y - v.y, z - v.z); };		  \
vex4<T> operator-(glm::vec4 v) const { return vex3<T>(x - v.x, y - v.y, z - v.z, w - v.w); }; \
vex4<T> operator+(glm::vec2 v) const { return vex3<T>(x + v.x, y + v.y); };					  \
vex4<T> operator+(glm::vec3 v) const { return vex3<T>(x + v.x, y + v.y, z + v.z); };		  \
vex4<T> operator+(glm::vec4 v) const { return vex3<T>(x + v.x, y + v.y, z + v.z, w + v.w); }; \
vex4<T> operator*(glm::vec2 v) const { return vex3<T>(x * v.x, y * v.y); };					  \
vex4<T> operator*(glm::vec3 v) const { return vex3<T>(x * v.x, y * v.y, z * v.z); };		  \
vex4<T> operator*(glm::vec4 v) const { return vex3<T>(x * v.x, y * v.y, z * v.z, w * v.w); }; \
vex4<T> operator/(glm::vec2 v) const { return vex3<T>(x / v.x, y / v.y); };					  \
vex4<T> operator/(glm::vec3 v) const { return vex3<T>(x / v.x, y / v.y, z / v.z); };		  \
vex4<T> operator/(glm::vec4 v) const { return vex3<T>(x / v.x, y / v.y, z / v.z, w / v.w); }; \
bool operator==(glm::vec2 v) const { return x == v.x && y == v.y; };						  \
bool operator==(glm::vec3 v) const { return x == v.x && y == v.y && z == v.z; };			  \
bool operator==(glm::vec4 v) const { return x == v.x && y == v.y && z == v.z && w == v.w; };  \
bool operator!=(glm::vec2 v) const { return x != v.x && y != v.y; };						  \
bool operator!=(glm::vec3 v) const { return x != v.x && y != v.y && z != v.z; };			  \
bool operator!=(glm::vec4 v) const { return x != v.x && y != v.y && z != v.z && w != v.w; };
