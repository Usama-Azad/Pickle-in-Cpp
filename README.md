# Pickle-in-C++
```Module``` for ```Pickling``` objects in ```C++```.

#
## Download
For Downloading `zip` file [Click Here](https://github.com/Usama-Azad/Pickle-in-Cpp/archive/master.zip) .

#
## Note
This ```Pickle class``` can't pickle the object of those class which contain `pointers` as their data Members or Attributes like vector, string etc. 

For More [Click Here](https://www.geeksforgeeks.org/serialize-deserialize-binary-tree/amp/) .
#


## Get started
1. Clone or [download](https://github.com/Usama-Azad/Pickle-in-Cpp/archive/master.zip)
the ```repo```, and then,
2. Paste the header files [pickle.h](https://github.com/Usama-Azad/Pickle-in-Cpp/blob/master/pickle.h) and [pickleException.h](https://github.com/Usama-Azad/Pickle-in-Cpp/blob/master/pickleException.h) in your program directory where your ```source.cpp``` file is present.
3. Include ```pickle``` header file in your ```source.cpp``` file like ```#include"pickle.h"```.
<br/><br/>

### *Pickling Object Example*
<br/>

``` cpp
#include<iostream>
#include<array>
#include"pickle.h"
using namespace std;

int main()
{
    std::array<int,100> myArray;

    for (int i = 0; i < 100; i++)
        myArray[i] = i*i;

    for (auto i : myArray)
        cout << i << endl;

    usa::Pickle pickle;

    pickle.dump("output",myArray);

    return 0;
}
```

<br/>

### *Unpickling Object Example*

<br/>

``` cpp
#include<iostream>
#include<array>
#include"pickle.h"
using namespace std;

int main()
{
    std::array<int, 100> myNewArray;

    usa::Pickle pickle;

    pickle.load("output", myNewArray);

    for (auto i : myNewArray)
        cout << i << endl;

    return 0;
}
```
#
## Purpose

```Pickle Module``` helps to store objects into a `binary file` and then we can use the stores data any time by just `loading` the binary file into program. We can also share our data that is stored on binary file with others by just sharing a binary file with them and they use the data by loading the binary file into program.

#
## Author
## [Usama Azad](https://github.com/Usama-Azad/)
<!-- <br/> -->

<!-- ![Usama Azad](https://avatars1.githubusercontent.com/u/68641880?s=400&u=36a8f07494dc385f817b1767ee2c64717a5a9d2c&v=4) -->
