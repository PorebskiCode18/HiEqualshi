#include <iostream>
#include <cctype>
#include <cassert>

int strcmp_case_insensitive(const char* str1, const char* str2,bool skipSpaces = false, int maxLength = -1) {
    int compared = 0;
    if (maxLength == 0) {
        return 0;
    }
    while (*str1 && *str2) {
        if (skipSpaces){
            while (*str1 == ' ') {
                ++str1;
            }
            while (*str2 == ' ') {
                ++str2;
            }    
        }
        char c1 = std::tolower(*str1);
        char c2 = std::tolower(*str2);
        
        if (c1 != c2) {
            return c1 - c2;
        }
        
        ++str1;
        ++str2;
        compared++;
        if (maxLength > 0 && compared >= maxLength) {
            return 0;
        }
    }
    
    return std::tolower(*str1) - std::tolower(*str2);
}

int main() {
    assert(strcmp_case_insensitive("Hello", "hello") == 0);

    assert(strcmp_case_insensitive("apple", "banana") < 0);

    assert(strcmp_case_insensitive("zebra", "apple") > 0);

    assert(strcmp_case_insensitive("", "") == 0);

    assert(strcmp_case_insensitive("cat", "cats") < 0);

    assert(strcmp_case_insensitive("my cool string","mycoolstring",true) == 0);

    assert(strcmp_case_insensitive("My Cool String","MyCoolString",true) == 0);

    assert(strcmp_case_insensitive("My Cool String","mycoolstring",true) == 0);

    assert(strcmp_case_insensitive(" My Cool String","mycoolstring",true) == 0);

    assert(strcmp_case_insensitive("Another string","mycoolstring",true) != 0);

    assert(strcmp_case_insensitive("apple", "apply", false, 4) == 0);

    assert(strcmp_case_insensitive("apple", "banana", false, 1) != 0);

    assert(strcmp_case_insensitive("cat", "cats", false, 100) < 0);

    assert(strcmp_case_insensitive("banana", "apple", false, 0) == 0);

    assert(strcmp_case_insensitive("Hello", "hello", false, -1) == 0);

    assert(strcmp_case_insensitive("Hello", "hello", false) == 0);
    std::cout << "All tests passed!" << std::endl;

    return 0;
}
