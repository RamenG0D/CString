#ifndef STRING_H
#define STRING_H

#include <string.h>

/// @brief A macro that takes 2 char pointers and concats them together
/// @attention concats them together at Runtime
#define CONCAT(str1, str2) \
({ \
    char tmp[(strlen(str1) + strlen(str2) + 1)]; \
    strcpy_s(tmp, sizeof(tmp), str1); \
    strcat_s(tmp, sizeof(tmp), str2); \
    tmp; \
})

/// @brief A struct that holds a char* and its length (General purpose string struct)
/// @note This is a custom string type that is used to make appending to strings easier
/// @author RamenGod(drplague)
typedef struct String String;

/// @brief A function that creates a new String
/// @param str the char* to create the String from
/// @return String* the new String
String* StringNew(const char* str);

/// @brief A function that appends a char* to the custom String
/// @param string the String to append to
/// @param str the char* to append to the String
void StringAppendStr(String* string, char* str);

/// @brief A function that appends a char to the ``` END ``` of the String
/// @param string the String to append to
/// @param ch the char to append to the String
void StringAppendChar(String* string, char ch);

/// @brief A function that returns the char* from the String
/// @param string the String to get the char* from
/// @return char* the char* from the String
char* StringGetText(String* string);

/// @brief A function that returns the length of the char* from the String
/// @param string the String to get the length of
/// @return int the length of the char* from the String
int StringGetLength(String* string);

/// @brief A function that destroys the String
/// @param string the String to destroy
void StringDestroy(String* string);

/// @brief A function that clears the String
/// @param string the String to clear
void StringClear(String* string);

/// @brief A function that sets the char in the string at the given index to the given char
/// @param string the String to set
/// @param ch the char to set the char in the string to
void StringSetChar(String* string, int index, char ch);

/// @brief A function that removes all instances of a char from a String
/// @param string the String to remove chars from
/// @param ch the char to remove from the String
void StringRemoveChars(String* string, const char* chars);

/// @brief A function that removes all char data from a String
/// @param string the String to clear data from
void StringClear(String* string);

/// @brief A function that overites the ```WHOLE``` String text with the given char* text
/// @param string the String to set
/// @param str the char* to set the String to
void StringSet(String* string, char* str);

#endif