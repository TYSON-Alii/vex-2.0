## vex-2.0

Vector2, Vector3 and Vector4.

_Code View:_
```cpp
#include <iostream>
//#include "GLM-Vec.hpp" // optional (if you using glm vectors)
#include "vex.hpp"

using namespace std;

int main() {
    srand(time(NULL)); // optional
    vex2i vec = vex4f(5, vex3d(float(2), vex2f("5"s) % 15)) | vex2d(float(3), int(8)) * vex3d(0.f, vex2f(53)); // works!!
    
    cout << vec.str(", ") << '\n';
};
```

### Supported Types
- float
- double
- long double
- bool
- int
- unsigned int
- long int
- long long int
- string
- [strinx](https://github.com/TYSON-Alii/strinx)
### Integrations
- GLM Vectors
- ImGui Vectors and Functions
## Docs
# Consturactors
```cpp
vex2f vec = 0.f; // set all element.
vex2f vec = vex3f(1,5,7); // any vex type.
vex4f vec = vex2f(34,567); // set x and y.
vex3f(vex2f(), float()) // ok.
vex3f(float(), vex2f()) // ok.
vex4f(float(), vex2f(), float()) // ok.
vex4f(float(), vex3f()) // like these all ok.
vec << sf::Vector2f(234,356); // this is how you can copy other non-integrated vectors.
```
# Arithmetic Operators (+, -, /, *, ^, ++, --)
```cpp
vex3f vec = 0.f;
vec += 5.f; // x + 5.f, y + 5.f and z + 5.f.
vec -= vex2f(3); // x - 3.f and y - 5.f.
vec *= vex4f(17.f, 19.f, 0.f); // x * 17.f, y * 19.f and z * 0.f.
vec /= 255; // x * 255, y * 255 and z * 255.
vec = vec^5; // x, y and z pow 5.
vec = vec - vex4f(6.f, 89ui);
```
# Boolean Operators (==, !=, <, <=, >, >=)
```cpp
vex3f vec = 37;
if (vec == 0.f); // check all element.
if (vec == vex2f(0.f)) // check x and y.
if (vec != vex2f(0.f)) // check x and y.
if (vec <= vex2f(0.f)) // check x and y.
if (vec >= vex2f(0.f)) // check x and y.
if (vec < vex2f(0.f)) // check x and y.
if (vec > vex2f(0.f)) // check x and y.
// any vex type support.
```
# Special Operators (%, |, ',', ~, [], ())
```cpp
vex4f vec = 0;
vec = vec % 100; // x, y, z, and w random 0-100 a value.
vec = vex2f(31) | vex3i(453); // randomly chooses one of the two.
vex4f vec2 = 45;
vec, vec2; // swap.
vec = ~vec; // x, y, z and w make float().
float v = vec[0]; // get elemnt like array (0 = x, 1 = y..).
vec() += 10; // copy of vec.
```
# Casts
```cpp
vex4f vec = 5.f;
std::cout << (char*)vec << '\n';
std::cout << (std::string)vec << '\n';
if (vec); // bool cast
```
# Usefull Functions
```cpp
vex3f vec = 0.f;
float* v_array = vec.arr(); // float[3] { x, y, z };
std::string str = vec.str(", ", "\n"); // ", " is seperate, "\n" is end.
bool b = vec.isEmpty(); // check (x && y) ? false : true.
vex2f vec = 0.f;
vec.swap(); // x = y, y = x.
vec.copy(); // copy.
vec.normalize(); // normalize vec. just float and double vex's.
vec.percent(10); // percent.
std::cout << vec; // ostream support.
std::cin >> vec; // istream support.
```
# Another Features
*  All vex's work integrated with each other.
*  Copyable any vectors
```cpp
vex4f vec << sf::Vector2f(23,234); // copy x and y.
//vex2f vec << sf::Vector3f(23,234); // error.
```
* All functions return a value. (returns a copy or self address)
```cpp
vex2i vec, vec2, vec3;
vec = vec2 = vec3 = 35; // works.
```
* GLM Vector, ImGui Vector and Functions integration.
```cpp
vex2i vec = glm::vec3(345,435,354); // works.
ImGui::SliderFloat2("Slider", vec, 0, 100); // works.
```
* User Defined Literals.
```cpp
std::cout << 87.0_vex4f + 5 << '\n'; // works.
```
