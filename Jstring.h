/*
 * JString - A Dynamic String Library for C
 * ----------------------------------------
 * JString is a lightweight dynamic string library that provides an efficient alternative
 * to fixed-size character arrays in C. It handles memory management automatically,
 * simplifying operations like concatenation, replacement, and input handling.
 *
 * Features:
 * - Dynamic memory allocation
 * - Safe string manipulation functions
 * - Efficient appending and modification
 * - Encapsulation for better memory safety
 *
 * MIT License
 *
 * Copyright (c) 2025 Jyotismoy Kalita
 * Contact: jyotismoykalita03@gmail.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef JSTRING_H
#define JSTRING_H

#define JSTRING_SUCCESS 0
#define JSTRING_NULL_PTR -1
#define JSTRING_ALLOC_FAILED -2

// Structure to represent a dynamic string
typedef struct jstrng* JString;

// MEMORY HANDLING

/*
 * Creates a new JString with the given data.
 * Returns:
 *   JString  - Success
 *   NULL     - Memory allocation failed
 */
JString jcreate(const char *data);

/*
 * Frees the allocated memory for the JString.
 */
void jdestroy(JString str);

/*
 * Expands the allocated memory for the string (multiplies by GRWTH_RATE, default is 2).
 * Should not be called manually in normal use.
 * Returns:
 *   0  - Success
 *  -1  - Null pointer error
 *  -2  - Memory allocation failed
 */
int jexpand(JString str);

/*
 * Clears the allocated memory for the string.
 * Sets the data pointer to NULL and size to 0.
 */
void jclear(JString str);

/*
 * Initializes a new string with the given source text.
 * Clears any previous allocation and assigns new memory.
 * Returns:
 *   0  - Success
 *  -1  - Null pointer error
 *  -2  - Memory allocation failed
 */
int jnew(JString *str, const char *src);

// BASIC STRING OPERATIONS

/*
 * Returns the length of the string (excluding the null terminator).
 */
int jlength(JString str);

/*
 * Returns the total allocated size of the string.
 */
int jsize(JString str);

/*
 * Copies the given source text into the string.
 * If the allocated space is too small, it re-allocates memory.
 */
int jput(JString str, const char *src);

/*
 * Returns the string's character data.
 */
char* jget(JString str);

/*
 * Searches for a substring inside the string.
 * Returns the index of the first occurrence or -1 if not found.
 */
int jfind(JString str, const char *substr);

/*
 * Compares two strings.
 * Returns 0 if the strings are equal, otherwise a non-zero value.
 */
int jcompare(JString str1, JString str2);

// STRING MODIFICATION

/*
 * Copies the content of one JString to another.
 */
int jcopy(JString des, JString src);

/*
 * Concatenates a C-string to the JString.
 * Expands memory every time it is called.
 * Recommended for infrequent concatenations.
 */
int jcatc(JString des, const char *src);

/*
 * Concatenates another JString to the current string.
 * Expands memory every time it is called.
 * Recommended for infrequent concatenations.
 */
int jcats(JString des, JString src);

/*
 * Appends a C-string to the JString, expanding memory only when necessary.
 * Recommended for frequent appending operations.
 */
int jappendc(JString des, const char *src);

/*
 * Appends another JString to the current string, expanding memory only when necessary.
 * Recommended for frequent appending operations.
 */
int jappends(JString des, JString src);

/*
 * Reverses the characters in the string.
 */
void jreverse(JString str);

/*
 * Removes leading and trailing spaces from the string.
 */
void jstrip(JString str);

/*
 * Converts all characters in the string to uppercase.
 */
void jtoupper(JString str);

/*
 * Converts all characters in the string to lowercase.
 */
void jtolower(JString str);

/*
 * Capitalizes the first character of the string.
 */
void jcapitalize(JString str);

/*
 * Extracts a substring from the given string between start and end indices.
 */
int jsubstr(JString dest, JString src, int start, int end);

/*
 * Replaces all occurrences of a substring with another string.
 */
int jreplace(JString str, const char *oldSubstr, const char *newSubstr);

// STRING INPUT/OUTPUT

/*
 * Reads a line of input and stores it in the JString.
 * Expands memory dynamically if needed.
 */
int jscan(JString str);

/*
 * Prints the formatted string to the console.
 */
void jprint(const char *format, ...);

#endif
