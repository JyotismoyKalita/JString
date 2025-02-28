#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Jstring.h"

#define GRWTH_RATE 2

int jexpand(JString *str) {
    if (!str || !str->data || str->size == 0) return JSTRING_NULL_PTR;
    
    int newSize = str->size * GRWTH_RATE;
    char *newData = realloc(str->data, newSize * sizeof(char));
    if (!newData) return JSTRING_ALLOC_FAILED;
    
    memset(newData + str->size, 0, newSize - str->size);
    str->data = newData;
    str->size = newSize;
    return JSTRING_SUCCESS;
}

void jclear(JString *str) {
    if (str && str->data) {
        free(str->data);
        str->data = NULL;
        str->size = 0;
    }
}

int jlength(JString *str) {
    return (str && str->data) ? strlen(str->data) : 0;
}

int jsize(JString *str) {
    return (str) ? str->size : JSTRING_NULL_PTR;
}

int jnew(JString *str, const char *src) {
    if (!str || !src) return JSTRING_NULL_PTR;
    
    jclear(str);
    int size = strlen(src) + 1;
    str->data = (char*)malloc(size * sizeof(char));
    if (!str->data) return JSTRING_ALLOC_FAILED;
    
    strncpy(str->data, src, size);
    str->size = size;
    return JSTRING_SUCCESS;
}

int jput(JString *str, const char *src)
{
    if(!str || !src) return JSTRING_NULL_PTR;
    if(!str->data || (strlen(src) > strlen(str->data))){
        int ret = jnew(str, src);
        return ret;
    }
    else{
        strcpy(str->data, src);
    }
    return JSTRING_SUCCESS;
}

char *jget(JString *str) {
    return (str && str->data) ? str->data : NULL;
}

int jfind(JString *str, const char *substr) {
    if (!str || !str->data || !substr) return -1;
    char *pos = strstr(str->data, substr);
    return (pos) ? (pos - str->data) : -1;
}

int jcopy(JString *des, JString src) {
    return jnew(des, src.data);
}

int jcatc(JString *des, const char *src) {
    if (!des || !src) return JSTRING_NULL_PTR;
    int newSize = jlength(des) + strlen(src) + 1;
    char *temp = realloc(des->data, newSize * sizeof(char));
    if (!temp) return JSTRING_ALLOC_FAILED;
    des->data = temp;
    strcat(des->data, src);
    des->size = newSize;
    return JSTRING_SUCCESS;
}

int jcats(JString *des, JString src) {
    return (src.data) ? jcatc(des, src.data) : JSTRING_NULL_PTR;
}

int jappendc(JString *des, const char *src) {
    if (!des || !src) return JSTRING_NULL_PTR;
    
    if (!des->data) {
        return jnew(des, src);
    }
    
    int newSize = strlen(des->data) + strlen(src) + 1;
    while (newSize > des->size) {
        int res = jexpand(des);
        if (res != JSTRING_SUCCESS) return res;
    }
    
    strcat(des->data, src);
    return JSTRING_SUCCESS;
}

int jappends(JString *des, JString src){
    return jappendc(des, src.data);
}

void jtoupper(JString *str) {
    if (!str || !str->data) return;
    for (int i = 0; str->data[i]; i++) {
        str->data[i] = toupper(str->data[i]);
    }
}

void jtolower(JString *str) {
    if (!str || !str->data) return;
    for (int i = 0; str->data[i]; i++) {
        str->data[i] = tolower(str->data[i]);
    }
}

void jcapitalize(JString *str) {
    if (!str || !str->data) return;
    if (str->data[0]) str->data[0] = toupper(str->data[0]);
}

int jsubstr(JString *dest, JString *src, int start, int end) {
    if (!dest || !src || !src->data || start < 0 || end >= jlength(src) || start > end) return JSTRING_NULL_PTR;
    
    int len = end - start + 1;
    jclear(dest);
    dest->data = (char*)malloc((len + 1) * sizeof(char));
    if (!dest->data) return JSTRING_ALLOC_FAILED;
    
    strncpy(dest->data, src->data + start, len);
    dest->data[len] = '\0';
    dest->size = len + 1;
    return JSTRING_SUCCESS;
}

int jreplace(JString *str, const char *oldSubstr, const char *newSubstr) {
    if (!str || !str->data || !oldSubstr || !newSubstr) return JSTRING_NULL_PTR;
    
    char *pos = strstr(str->data, oldSubstr);
    if (!pos) {
        //printf("jreplace: Substring not found\n");
        return JSTRING_SUCCESS;
    }
    int index = pos - str->data;
    int oldLen = strlen(oldSubstr);
    int newLen = strlen(newSubstr);
    int diff = newLen - oldLen;
    int isEnd = (index + oldLen == '\0');
    
    if (diff > 0) {
        while (strlen(str->data) + diff >= str->size) {
            if (jexpand(str) != JSTRING_SUCCESS) return JSTRING_ALLOC_FAILED;
        }
    }

    if(isEnd){
        strcpy(str->data+index, newSubstr);
        str->data[index+newLen] = '\0';
    }
    else{
        memmove(str->data + index + newLen, str->data + index + oldLen, strlen(str->data) - index - oldLen + 1);
        memcpy(str->data + index, newSubstr, newLen);
    }
    
    return JSTRING_SUCCESS;
}


void jreverse(JString *str) {
    if (!str || !str->data) return;
    int len = jlength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str->data[i];
        str->data[i] = str->data[len - i - 1];
        str->data[len - i - 1] = temp;
    }
}

void jstrip(JString *str) {
    if (!str || !str->data) return;
    char *start = str->data;
    while (isspace((unsigned char)*start)) start++;
    char *end = str->data + jlength(str) - 1;
    while (end > start && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    memmove(str->data, start, end - start + 2);
}

int jscan(JString *str) {
    char buffer[32];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
        if (jappendc(str, buffer) != JSTRING_SUCCESS) return JSTRING_ALLOC_FAILED;
        if (strlen(buffer) < sizeof(buffer) - 1) break;
    }
    return JSTRING_SUCCESS;
}

void jprint(JString *str) {
    if (str && str->data) {
        printf("%s\n", str->data);
    } else {
        printf("JString is empty\n");
    }
}


