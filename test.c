#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jstring.h"

void test_jnew() {
    Jstring(str, "Hello");
    if (strcmp(jget(&str), "Hello") == 0) {
        printf("jnew: PASS\n");
    } else {
        printf("jnew: FAIL\n");
    }
    jclear(&str);
}

void test_jappendc() {
    Jstring(str, "Hello");
    jappendc(&str, " World");
    
    if (strcmp(jget(&str), "Hello World") == 0) {
        printf("jappendc: PASS\n");
    } else {
        printf("jappendc: FAIL (Got: %s)\n", jget(&str));
    }
    jclear(&str);
}

void test_jsubstr() {
    Jstring(str, "Hello World");
    Jstring(sub);
    int result = jsubstr(&sub, &str, 6, 10);
    printf("jsubstr result: %d, Extracted: '%s'\n", result, jget(&sub));
    if (result == JSTRING_SUCCESS && strcmp(jget(&sub), "World") == 0) {
        printf("jsubstr: PASS\n");
    } else {
        printf("jsubstr: FAIL\n");
    }
    jclear(&str);
    jclear(&sub);
}

void test_jreplace() {
    Jstring(str, "Hello World");
    printf("Before replace: %s\n", jget(&str));
    int result = jreplace(&str, "World", "JString");
    printf("After replace: %s\n", jget(&str));
    if (result == JSTRING_SUCCESS && strcmp(jget(&str), "Hello JString") == 0) {
        printf("jreplace: PASS\n");
    } else {
        printf("jreplace: FAIL\n");
    }
    jclear(&str);
}

void test_jfind() {
    Jstring(str, "Hello World");
    int index = jfind(&str, "World");
    printf("jfind result: %d\n", index);
    if (index == 6) {
        printf("jfind: PASS\n");
    } else {
        printf("jfind: FAIL\n");
    }
    jclear(&str);
}

void test_all() {
    test_jnew();
    test_jappendc();
    test_jsubstr();
    test_jreplace();
    test_jfind();
}

int main() {
    test_all();
    return 0;
}