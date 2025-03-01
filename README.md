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
# Clone the repository
git clone https://github.com/JyotismoyKalita/JString.git
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
To ensure **proper initialization**, use the `jcreate("value")` function while declaring a `JString` variable assigned with string "value".
Te declare a **NULL** JString variable, you can:
- `JString x = jcreate(NULL);`
- `JString x = NULL;`
### WARNING:
- Do not simply write `JString x;` and then perform other operations as it will have **garbage value pointing to unknown address**.
- Always use `jdestroy(str);` when you dont need it or at the end of the function it was defined in to avoid memory leak.

### Example Code
```c
#include <stdio.h>
#include "Jstring.h"

int main() {
    JString str = jcreate(NULL);
    jprintf("Enter your string: ");
    jscan(str);
    jprint("The string you entered is: %j");
    jclear(str);
    return 0;
}
```

### Expected Output:
```
Enter your string: Hello World!
The string you entered is: Hello World!
```

## Functions

### MEMORY HANDLING

#### `JString jcreate(const char *data);`
Creates a new JString with the given data.

**Returns:**
- `JString`  - Success
- `NULL`     - Memory allocation failed

#### `void jdestroy(JString str);`
Frees the allocated memory for the JString.

#### `int jexpand(JString str);`
Expands the allocated memory for the string.
Should not be called manually in normal use.

**Returns:**
- `0`  - Success
- `-1`  - Null pointer error
- `-2`  - Memory allocation failed

#### `void jclear(JString str);`
Clears the allocated memory for the string.
Sets the data pointer to `NULL` and size to `0`.

#### `int jnew(JString *str, const char *src);`
Initializes a new string with the given source text.
Clears any previous allocation and assigns new memory.

**Returns:**
- `0`  - Success
- `-1`  - Null pointer error
- `-2`  - Memory allocation failed

### BASIC STRING OPERATIONS

#### `int jlength(JString str);`
Returns the length of the string (excluding the null terminator).

#### `int jsize(JString str);`
Returns the total allocated size of the string.

#### `int jput(JString str, const char *src);`
Copies the given source text into the string.
If the allocated space is too small, it re-allocates memory.

#### `char* jget(JString str);`
Returns the string's character data.

#### `int jfind(JString str, const char *substr);`
Searches for a substring inside the string.
Returns the index of the first occurrence or `-1` if not found.

#### `int jcompare(JString str1, JString str2);`
Compares two strings.
Returns `0` if the strings are equal, otherwise a non-zero value.

### STRING MODIFICATION

#### `int jcopy(JString des, JString src);`
Copies the content of one JString to another.

#### `int jcatc(JString des, const char *src);`
Concatenates a C-string to the JString.
Expands memory every time it is called.
**Recommended for infrequent concatenations.**

#### `int jcats(JString des, JString src);`
Concatenates another JString to the current string.
Expands memory every time it is called.
**Recommended for infrequent concatenations.**

#### `int jappendc(JString des, const char *src);`
Appends a C-string to the JString, expanding memory only when necessary.
**Recommended for frequent appending operations.**

#### `int jappends(JString des, JString src);`
Appends another JString to the current string, expanding memory only when necessary.
**Recommended for frequent appending operations.**

#### `void jreverse(JString str);`
Reverses the characters in the string.

#### `void jstrip(JString str);`
Removes leading and trailing spaces from the string.

#### `void jtoupper(JString str);`
Converts all characters in the string to uppercase.

#### `void jtolower(JString str);`
Converts all characters in the string to lowercase.

#### `void jcapitalize(JString str);`
Capitalizes the first character of the string.

#### `int jsubstr(JString dest, JString src, int start, int end);`
Extracts a substring from the given string between `start` and `end` indices.

#### `int jreplace(JString str, const char *oldSubstr, const char *newSubstr);`
Replaces all occurrences of a substring with another string.

### STRING INPUT/OUTPUT

#### `int jscan(JString str);`
Reads a line of input and stores it in the JString.
Expands memory dynamically if needed.

#### `void jprint(const char *format, ...);`
Prints the formatted string to the console.



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
Developed by [Jyotismoy Kalita](https://github.com/JyotismoyKalita)

