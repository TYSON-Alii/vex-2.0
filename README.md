## vex-2.0

Vector2, Vector3 and Vector4.

_Code View:_
```cpp
#include <iostream>
#include "Vex.hpp"

using namespace std;

int main() {
    srand(time(NULL)); // optional
    vex2i vec = vex4f(5, vex3d(float(2), vex2f("5"s) % 15)) | vex2d(float(3), int(8)) * vex3d(0.f, vex2f(53)); // works!!
    
    cout << vec << '\n';
};
```

###Supported Types
- float
- double
- long double
- bool
- int
- unsigned int
- long int
- long long int
- string
- !(strinx)[https://github.com/TYSON-Alii/strinx]
