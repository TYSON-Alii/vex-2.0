## vex-2.0

Vector2, Vector3 and Vector4.

_Code View:_
```cpp
#include <iostream>
//#include "GLM-Vec.hpp" // optional (if you using glm vectors)
//#define _VEX_NO_SHORT_NAMES // delete v2f/v4i like vex types.
#include "Vex.hpp"

using namespace std;

int main() {
    srand(time(NULL)); // optional
    /*v2i = vex2i*/
    v2i vec = vex4f(5, vex3d(double(2), vex2f("5"s) % 15)) | vex2d(float(3), int(8)) * vex3d(0u, vex2f(53)); // works!!
    
    cout << vec.str(", ") << '\n';
};
```

### Supported Types
- float
- double
- bool
- int
- unsigned int
- long int
- long long int
- string
- [strinx](https://github.com/TYSON-Alii/strinx)
### Integrations
- [GLM Vectors](https://github.com/TYSON-Alii/vex-2.0/blob/main/extras/GLM-Vex.hpp)
- [ImGui Vectors ~~and Functions~~ _(Design Feature)_](https://github.com/TYSON-Alii/vex-2.0/blob/main/extras/ImGui-Vex.hpp)
- [Some OpenGL Functions](https://github.com/TYSON-Alii/vex-2.0/blob/main/extras/GL-Vex.hpp)
- Some STL Functions
## Docs
### Consturactors
```cpp
float arr[] { 31,69,42 };
vex2f vec = 0.f; // set all element.
vex2f vec = arr; // set x = arr[0], y = arr[1].
vex2f vec = vex3f(1,5,7); // set x and y, works any vex type.
vex4f vec = vex2f(34,567); // set x and y.
vex3f(vex2f(), float()); // ok.
vex3f(0u, vex2f()); // ok.
vex4f(0.f, vex2f(), 0.0); // ok.
vex4f(vex2i(), vex2d()); // like these all ok.
```
### Arithmetic Operators (+, -, /, *, ^, ++, --)
```cpp
vex3f vec = 0.f;
vec += 5.f; // x + 5, y + 5 and z + 5.
vec -= vex2f(3); // x - 3 and y - 5.
vec *= vex4f(17.f, 19.f, 0.f); // x * 17, y * 19 and z * 0.f.
vec /= 255; // x, y and z divide 255.
vec = vec^5; // x, y and z pow 5.
vec = vec - vex4f(6.f, 89ui);
vec = -vec; // x = -x, y = -y and z = -z;
int arr[] { 21,16,48 };
vec += arr; // x += arr[0]...
```
### Boolean Operators (==, !=, <, <=, >, >=)
```cpp
vex3f vec = 37;
if (vec == 0.f); // check all element.
if (vec == vex2f(0.f)) // check x and y.
if (vec != vex3f(0.f)) // check x and y.
if (vec <= vex4f(0.f)) // check x, y and z.
if (vec >= vex2i(0.f)) // check x and y.
if (vec < vex4d(0.f)) // check x, y and z.
if (vec > vex2ui(0.f)) // check x and y.
// any vex type support.
```
### Special Operators (%, |, ',', ~, [], ())
```cpp
vex4f vec = 0;
vec = vec % 100; // x, y, z, and w random 0-100 a value.
vec = vex2f(31) | vex3i(453); // randomly chooses one
vex4f vec2 = 45;
vec, vec2; // swap.
vec = ~vec; // x, y, z and w make float().
float v = vec[0]; // get elemnt like array (0 = x, 1 = y..).
vec() += 10; // copy of vec.
```
### Casts
```cpp
vex4f vec = 5.f;
std::cout << (char*)vec << '\n';
std::cout << (std::string)vec << '\n';
float* arr = (float*)vec;
if (vec); // bool cast
```
### Usefull Functions
```cpp
vex3f vec = 0.f;
float* v_array = vec.arr(); // float[3] { x, y, z };
std::vector<float> list = vec;
std::cout << vec.str(", ", "\n"); // ", " is seperate, "\n" is end.
bool b = vec.isEmpty(); // check (x && y) ? false : true.
vex2f vec = 0.f;
vec.swap(); // x = y, y = x.
vec.copy(); // copy.
vec.normalize(); // normalize vec. just float and double vex's.
float* ptr = *vec; // or vec.data() return &x;
ptr[0] = 25; // set x = 25;
```
## Another Features
*  All vex's work integrated with each other.
*  Most functional vector's
```cpp
vex3f vec(135,212,255);
vex3f norm = vec / max(vec); // normalize vec
vex2f wtf = vex2f(-FLT_MAX,FLT_MAX)[13576839];
for (vex2i i = 0; i < 10; i++)
    cout << i << '\n'; // works
vex2b vec2(false,true);
std::vector list = vec("xyxyxyxyxyxyyyxyxxyxyxyyxyxyxxyy");
```
*  Copyable any vectors
```cpp
//vex4f vec << sf::Vector2f(23,234); // error, z and w not element of sf::Vector2f.
vex2f vec << sf::Vector3f(23,234,543); // set x and y.
MyVector2 vec2;
vec >> vec2; // sets x and y of vec2
```
* All functions return a value. (returns a copy or self address)
```cpp
vex2i vec, vec2, vec3;
vec = vec2 = vec3 = 35; // works.
```
* ostream and istream support
```cpp
vex3f vec = 9.7f;
std::cout << vec << '\n';
std::cin >> vec;
```
* OpenGL Functions, GLM Vectors, ImGui Vectors/Functions integration.
```cpp
vex2i vec = glm::vec3(345,435,354); // works.
ImGui::SliderFloat2("Slider", *vec/* unary '*' operator returning self adress*/, 0, 100); // works.
abs(vec);
ceil(vec);
```
* User Defined Literals.
```cpp
std::cout << 87.0_vex4f + 5 << '\n'; // works.
```
* Extra overloaded operators.
```cpp
vex3f vec1 = "12 15 18" + vex3f(8,5,2);
vex2i vec2 = 15 * vex2i(2,3);
std::vector<float> vec;
vec << vex2f(1,2); // or vec += vex4d(12,3,21,5)
vec(/*vex3<bool>*/{true, false, true}, vec + 0.1); // x = x + 0.1 and z = z + 0.1, y not change.
```
* Advanced math functions
```cpp
vex3f rot = 0.f, pos = 0.f;
limit(rot, 0 /*min value*/, 360 /*max value*/, true /*start over when exceeding the limit*/);
limit(pos, vex3f(-256,0,-256) /*advanced min*/, vex3f(256, 256, 256) /*advaced max*/, false);
cout << max(pos); // return bigger member
```
* Convertable
```cpp
vex3f vec = 0;
string str;
str = vec.str(", ");
str = string(vec);
str = to_string(vec);
char* cstr = (char*)vec;
vex3f vec2 = std::strtov3f(str); // support any vex.
"12 24" / vex2f(2); // Convert string to vex2f and divide.
5 * vex2f(2); // Convert to vex2f and multiply.
vec.arr(); // array of vec
vec.vec(); // std::vector of vec
```
