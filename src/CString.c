#include "CString.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct String {
    char* str;
    int length;
} String;

String* StringNew(const char* str) {
    String* string = (String*)malloc(sizeof(String));
    if (string == NULL) {
        printf("Error: Memory allocation failed for String struct.\n");
        exit(1);
    }

    if (str != NULL) {
        string->length = strlen(str);
        string->str = (char*)malloc(sizeof(char) * (string->length + 1));
        if (string->str == NULL) {
            printf("Error: Memory allocation failed for string data.\n");
            free(string);
            exit(1);
        }
        strcpy_s(string->str, sizeof(string->str), str); // Changed strcpy_s to strcpy
    } else {
        string->length = 0;
        string->str = (char*)malloc(sizeof(char));
        if (string->str == NULL) {
            printf("Error: Memory allocation failed for string data.\n");
            free(string);
            exit(1);
        }
        string->str[0] = '\0';
    }
    return string;
}

void StringAppendChar(String* string, char ch) {
    // check if input string* is NULL
    if(string == NULL) {
        printf("INPUT:[string] is NULL, please provide a valid String*\n");
        exit(1);
    }
    
    int new_length = string->length + 1;
    string->str = (char*)realloc(string->str, sizeof(char) * new_length);

    // check if the realloc was successful
    if(string->str == NULL) {
        printf("ERROR: StringAppendChar failed to allocate memory for string\n");
        exit(1);
    }

    if(new_length > 0 || new_length > string->length) {
        string->str[new_length-1] = ch;
        string->str[new_length] = '\0';
        string->length = new_length;
    } else {
        printf("ERROR: StringAppendChar { Inderx Range Out of Bounds Exception }\n");
        exit(1);
    }
}

void StringAppendStr(String* string, char* str) {
    int new_length = string->length + strlen(str);
    string->str = (char*)realloc(string->str, sizeof(char) * new_length);
    strcat_s(string->str, sizeof(string->str), str);
    string->length = new_length;
}

char* StringGetText(String* string) {
    return string->str;
}

int StringGetLength(String* string) {
    return string->length;
}

void StringDestroy(String* string) {
    if(NULL == string) return;
    free(string->str);
    free(string);
}

void StringClear(String* string) {
    string->str = (char*)realloc(string->str, sizeof(char)); // resize the string to be 1 char

    // check if the realloc was successful
    if(string->str == NULL) {
        printf("Error: On Buffer Variable: string->str is NULL, which means it failed to allocate its memory, most likely\n");
        exit(1);
    }

    // Reset the string to be empty (1 char long) -> (always '\0')
    string->str[0] = '\0';
    string->length = 0;
}

void StringSet(String* string, char* str) {
    free(string->str);
    
    string->str = (char*)malloc(sizeof(char) * strlen(str));
    string->length = strlen(str);

    strcpy_s(string->str, sizeof(string->str), str);
}

void StringSetChar(String* string, int index, char ch) {
    if(index > string->length || index < 0) {
        printf("ERROR: StringSetChar { Index Out of Bounds Exception }\n");
        exit(1);
    }
    string->str[index] = ch;
}

static inline void removeChar(char* str, char garbage) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src; if (*dst != garbage) dst++;
    } *dst = '\0';
}

void StringRemoveChars(String* string, const char* chars) {
    for(int i = 0; i < (int)strlen(chars); ++i) {
        removeChar(string->str, chars[i]);
    }
}
