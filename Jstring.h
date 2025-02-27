#ifndef JSTRING_H
#define JSTRING_H

#define GET_MACRO(_1, _2, NAME, ...) NAME
#define Jstring1(var) \
    JString var = {NULL, 0};
#define Jstring2(var, value) \
    JString var = {NULL, 0}; \
    jnew(&var, value);

#define Jstring(...) GET_MACRO(__VA_ARGS__, Jstring2, Jstring1)(__VA_ARGS__)

#define JSTRING_SUCCESS 0
#define JSTRING_NULL_PTR -1
#define JSTRING_ALLOC_FAILED -2

// Structure to represent a dynamic string
typedef struct {
    char *data; // Pointer to the character array
    int size;   // Allocated size of the character array
} JString;

// MEMORY HANDLING

/*
 * Expands the allocated memory for the string (multiplies by GRWTH_RATE, default is 2).
 * Should not be called manually in normal use.
 * Returns:
 *   0  - Success
 *  -1  - Null pointer error
 *  -2  - Memory allocation failed
 */
int jexpand(JString *str);

/*
 * Clears the allocated memory for the string.
 * Sets the data pointer to NULL and size to 0.
 */
void jclear(JString *str);

// BASIC STRING OPERATIONS

/*
 * Returns the length of the string (excluding the null terminator).
 */
int jlength(JString *str);

/*
 * Returns the total allocated size of the string.
 */
int jsize(JString *str);

/*
 * Initializes a new string with the given source text.
 * Clears any previous allocation and assigns new memory.
 * Returns:
 *   0  - Success
 *  -1  - Null pointer error
 *  -2  - Memory allocation failed
 */
int jnew(JString *str, const char *src);

/*
 * Copies the given source text into the string.
 * If the allocated space is too small, it re-allocates memory.
 */
int jput(JString *str, const char *src);

/*
 * Returns the string's character data.
 */
char* jget(JString *str);

/*
 * Searches for a substring inside the string.
 * Returns the index of the first occurrence or -1 if not found.
 */
int jfind(JString *str, const char *substr);

// STRING MODIFICATION

/*
 * Copies the content of one JString to another.
 */
int jcopy(JString *des, JString src);

/*
 * Concatenates a C-string to the JString.
 * Expands memory every time it is called.
 * Recommended for infrequent concatenations.
 */
int jcatc(JString *des, const char *src);

/*
 * Concatenates another JString to the current string.
 * Expands memory every time it is called.
 * Recommended for infrequent concatenations.
 */
int jcats(JString *des, JString src);

/*
 * Appends a C-string to the JString, expanding memory only when necessary.
 * Recommended for frequent appending operations.
 */
int jappendc(JString *des, const char *src);

/*
 * Appends another JString to the current string, expanding memory only when necessary.
 * Recommended for frequent appending operations.
 */
int jappends(JString *des, JString src);

/*
 * Reverses the characters in the string.
 */
void jreverse(JString *str);

/*
 * Removes leading and trailing spaces from the string.
 */
void jstrip(JString *str);

/*
 * Converts all characters in the string to uppercase.
 */
void jtoupper(JString *str);

/*
 * Converts all characters in the string to lowercase.
 */
void jtolower(JString *str);

/*
 * Capitalizes the first character of the string.
 */
void jcapitalize(JString *str);

/*
 * Extracts a substring from the given string between start and end indices.
 */
int jsubstr(JString *dest, JString *src, int start, int end);

/*
 * Replaces all occurrences of a substring with another string.
 */
int jreplace(JString *str, const char *oldSubstr, const char *newSubstr);

// STRING INPUT/OUTPUT

/*
 * Reads a line of input and stores it in the JString.
 * Expands memory dynamically if needed.
 */
int jscan(JString *str);

/*
 * Prints the JString to the console.
 * If the string is empty, prints "JString is empty".
 */
void jprint(JString *str);

#endif
