#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jstring.h"

void test_jcreate(){
    JString str = jcreate("Hello");
    if (strcmp(jget(str), "Hello") == 0) {
        printf("jcreate: PASS\n");
    } else {
        printf("jcreate: FAIL\n");
    }
    jdestroy(str);
}

void test_jexpand(){
    JString str = jcreate("Hello");
    jexpand(str);
    if (jsize(str) == 12) {
        printf("jexpand: PASS\n");
    } else {
        printf("jexpand: FAIL\n");
    }
    jdestroy(str);
}

void test_jclear(){
    JString str = jcreate("Hello");
    jclear(str);
    if (jsize(str) == 0) {
        printf("jclear: PASS\n");
    } else {
        printf("jclear: FAIL\n");
    }
    jdestroy(str);
}

void test_jnew() {
    JString str = jcreate("First Word");
    jnew(&str, "Hello");
    if (strcmp(jget(str), "Hello") == 0) {
        printf("jnew: PASS\n");
    } else {
        printf("jnew: FAIL\n");
    }
    jdestroy(str);
}

void test_jlength() {
    JString str = jcreate("Hello");
    if (jlength(str) == 5) {
        printf("jlength: PASS\n");
    } else {
        printf("jlength: FAIL\n");
    }
    jdestroy(str);
}

void test_jsize() {
    JString str = jcreate("Hello");
    if (jsize(str) == 6) {
        printf("jsize: PASS\n");
    } else {
        printf("jsize: FAIL\n");
    }
    jdestroy(str);
}

void test_jput(){
    JString str = NULL;
    jnew(&str, "First Word");
    jput(str, "Hello");
    if (strcmp(jget(str), "Hello") == 0) {
        printf("jput: PASS\n");
    } else {
        printf("jput: FAIL\n");
    }
    jdestroy(str);
}

void test_jget(){
    JString str = jcreate("Hello");
    if (strcmp(jget(str), "Hello") == 0) {
        printf("jget: PASS\n");
    } else {
        printf("jget: FAIL\n");
    }
    jdestroy(str);
}

void test_jfind() {
    JString str = jcreate("Hello World");
    int index = jfind(str, "World");
    if (index == 6) {
        printf("jfind: PASS\n");
    } else {
        printf("jfind: FAIL\n");
    }
    jdestroy(str);
}

void test_jcompare() {
    JString str1 = jcreate("Hello");
    JString str2 = jcreate("Hello");
    JString str3 = jcreate("World");
    int result1 = jcompare(str1, str2);
    int result2 = jcompare(str1, str3);
    int result3 = jcompare(str3, str1);

    if(result1 == 0 && result2 <= 0 && result3 >= 0) {
        printf("jcompare: PASS\n");
    } else {
        printf("jcompare: FAIL\n");
    }

    jdestroy(str1);
    jdestroy(str2);
    jdestroy(str3);
}

void test_jcopy() {
    JString str1 = jcreate("Hello");
    JString str2 = jcreate(NULL);
    jcopy(str2, str1);
    if (strcmp(jget(str2), "Hello") == 0) {
        printf("jcopy: PASS\n");
    } else {
        printf("jcopy: FAIL\n");
    }
    jdestroy(str1);
    jdestroy(str2);
}

void test_catc() {
    JString str = jcreate("Hello");
    jcatc(str, " World");
    
    if (strcmp(jget(str), "Hello World") == 0) {
        printf("jcatc: PASS\n");
    } else {
        printf("jcatc: FAIL\n");
    }
    jdestroy(str);
}

void test_cats(){
    JString str1 = jcreate("Hello");
    JString str2 = jcreate(" World");
    jcats(str1, str2);
    
    if (strcmp(jget(str1), "Hello World") == 0) {
        printf("jcats: PASS\n");
    } else {
        printf("jcats: FAIL\n");
    }
    jdestroy(str1);
    jdestroy(str2);
}

void test_jappendc() {
    JString str = jcreate("Hello");
    jappendc(str, " World");
    
    if (strcmp(jget(str), "Hello World") == 0) {
        printf("jappendc: PASS\n");
    } else {
        printf("jappendc: FAIL (Got: %s)\n", jget(str));
    }
    jdestroy(str);
}

void test_jappends() {
    JString str1 = jcreate("Hello");
    JString str2 = jcreate(" World");
    jappends(str1, str2);
    
    if (strcmp(jget(str1), "Hello World") == 0) {
        printf("jappends: PASS\n");
    } else {
        printf("jappends: FAIL (Got: %s)\n", jget(str1));
    }
    jdestroy(str1);
    jdestroy(str2);
}

void test_jreverse() {
    JString str = jcreate("Hello");
    jreverse(str);
    if (strcmp(jget(str), "olleH") == 0) {
        printf("jreverse: PASS\n");
    } else {
        printf("jreverse: FAIL\n");
    }
    jdestroy(str);
}

void test_jstrip(){
    JString str = jcreate("  Hello  ");
    jstrip(str);
    if (strcmp(jget(str), "Hello") == 0) {
        printf("jstrip: PASS\n");
    } else {
        printf("jstrip: FAIL\n");
    }
    jdestroy(str);
}

void test_jtoupper() {
    JString str = jcreate("Hello");
    jtoupper(str);
    if (strcmp(jget(str), "HELLO") == 0) {
        printf("jtoupper: PASS\n");
    } else {
        printf("jtoupper: FAIL\n");
    }
    jdestroy(str);
}

void test_jtolower() {
    JString str = jcreate("Hello");
    jtolower(str);
    if (strcmp(jget(str), "hello") == 0) {
        printf("jtolower: PASS\n");
    } else {
        printf("jtolower: FAIL\n");
    }
    jdestroy(str);
}

void test_jcapitalize() {
    JString str = jcreate("hello");
    jcapitalize(str);
    if (strcmp(jget(str), "Hello") == 0) {
        printf("jcapitalize: PASS\n");
    } else {
        printf("jcapitalize: FAIL\n");
    }
    jdestroy(str);
}

void test_jsubstr() {
    JString str = jcreate("Hello World!");
    JString sub = jcreate(NULL);
    int result = jsubstr(sub, str, 6, 10);
    if (result == JSTRING_SUCCESS && strcmp(jget(sub), "World") == 0) {
        printf("jsubstr: PASS\n");
    } else {
        printf("jsubstr: FAIL\n");
    }
    jdestroy(str);
    jdestroy(sub);
}

void test_jreplace() {
    JString str = jcreate("Hello World BRO!");
    int result1 = jreplace(str, "World", "JString");
    int result2 = jreplace(str, "BRO!", "Man!!");
    if (result1 == JSTRING_SUCCESS && result2 == JSTRING_SUCCESS && strcmp(jget(str), "Hello JString Man!!") == 0) {
        printf("jreplace: PASS\n");
    } else {
        printf("jreplace: FAIL\n");
    }
    jdestroy(str);
}

void test_jscan() {
    jprint("\nTesting jscan():\n");
    JString str = jcreate(NULL);
    jscan(str);
    jprint("jscan Scanned:\n%j\n", str);
    jdestroy(str);
}

void test_jprint() {
    JString name = jcreate("JString");
    JString feature = jcreate("dynamic string handling");

    jprint("\nTesting jprint():\n");
    
    jprint("Welcome to %js!\n", name);
    jprint("%js provides %js in %s.\n", name, feature, "C language");
    jprint("Version: %lld, Status: %c%.2f\n", 12344243, 'A', 3.1415);

    jdestroy(name);
    jdestroy(feature);
}

void test_all() {
    test_jcreate();
    test_jexpand();
    test_jclear();
    test_jnew();
    test_jlength();
    test_jsize();
    test_jput();
    test_jget();
    test_jfind();
    test_jcompare();
    test_jcopy();
    test_catc();
    test_cats();
    test_jappendc();
    test_jappends();
    test_jreverse();
    test_jstrip();
    test_jtoupper();
    test_jtolower();
    test_jcapitalize();
    test_jsubstr();
    test_jreplace();
    test_jprint();

    //uncomment to test jscan()
    //test_jscan();
}

int main() {
    test_all();

    //this is to check encapsulation of the JString objects
    //it should return error at compile time
    //uncommemt to check

    /*JString str = jcreate("Hello");
    str->data[0] = 'h';
    str->size = 100;*/

    return 0;
}