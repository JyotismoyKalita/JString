# JString - A Dynamic String Library for C

## Overview
JString(Initial J is taken from my name) is a lightweight and efficient dynamic string library for C that provides a flexible alternative to fixed-size character arrays. It supports memory-safe string operations such as concatenation, appending, substring extraction, and replacement while handling dynamic memory allocation internally.

## Features
- Dynamic memory management with automatic resizing
- String concatenation, appending, and substring operations
- Case conversion (uppercase, lowercase, capitalization)
- Trimming of whitespace
- Safe string replacement
- Custom input scanning
- Well-defined error handling

## Installation
To use JString in your project, simply include the `Jstring.h` and `Jstring.c` files in your source code.

```sh
# Clone the repository (after pushing to GitHub)
git clone https://github.com/yourusername/JString.git
cd JString
```

## Usage
### Compiling and Running
You can compile your program using JString with GCC:
```sh
gcc your_program.c Jstring.c -o your_program
./your_program
```

### Declaring a JString
To ensure **proper initialization**, always use the `Jstring` macro instead of directly declaring a `JString` variable. This avoids uninitialized values and ensures the struct starts as `{NULL, 0}`.

### Example Code
```c
#include <stdio.h>
#include "Jstring.h"

int main() {
    Jstring(str);
    printf("Enter your string: ");
    jscan(&str);
    jprint(&str);
    jclear(&str);
    return 0;
}
```

### Expected Output:
```
Hello World!
```

## Functions
### Memory Management
- `int jexpand(JString *str)` - Expands allocated memory dynamically.
- `void jclear(JString *str)` - Clears allocated memory and resets size.

### Basic String Operations
- `int jnew(JString *str, const char *src)` - Initializes a new string.
- `int jput(JString *str, const char *src)` - Copies a string.
- `char* jget(JString *str)` - Returns the string's character data.
- `int jlength(JString *str)` - Returns the length of the string.
- `int jfind(JString *str, const char *substr)` - Finds a substring.

### String Modification
- `int jcatc(JString *des, const char *src)` - Concatenates a C-string.
- `int jcats(JString *des, JString src)` - Concatenates another JString.
- `int jappendc(JString *des, const char *src)` - Appends a C-string efficiently.
- `int jappends(JString *des, JString src)` - Appends another JString efficiently.
- `void jreverse(JString *str)` - Reverses the string.
- `void jstrip(JString *str)` - Removes leading and trailing spaces.
- `void jtoupper(JString *str)` - Converts the string to uppercase.
- `void jtolower(JString *str)` - Converts the string to lowercase.
- `void jcapitalize(JString *str)` - Capitalizes the first letter.
- `int jsubstr(JString *dest, JString *src, int start, int end)` - Extracts a substring.
- `int jreplace(JString *str, const char *oldSubstr, const char *newSubstr)` - Replaces occurrences of a substring.

### Input/Output
- `int jscan(JString *str)` - Reads a line of input and stores it in JString.
- `void jprint(JString *str)` - Prints the JString to the console.

## Error Handling
JString functions return integer codes for status:
- `0` - Success
- `-1` - Null pointer error
- `-2` - Memory allocation failed

## Contributing
Contributions are welcome! Feel free to submit issues, feature requests, or pull requests.

## License
This project is licensed under the MIT License.

## Author
Developed by [Jyotismoy Kalita](https://github.com/yourusername)

