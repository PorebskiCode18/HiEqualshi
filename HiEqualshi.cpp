#include <iostream>
#include <cctype>
#include <cassert>

int strcmp_case_insensitive(const char* str1, const char* str2) {
    while (*str1 && *str2) {
        char c1 = std::tolower(*str1);
        char c2 = std::tolower(*str2);
        
        if (c1 != c2) {
            return c1 - c2;
        }
        
        ++str1;
        ++str2;
    }
    
    return std::tolower(*str1) - std::tolower(*str2);
}

int main() {
    assert(strcmp_case_insensitive("Hello", "hello") == 0);

    assert(strcmp_case_insensitive("apple", "banana") < 0);

    assert(strcmp_case_insensitive("zebra", "apple") > 0);

    assert(strcmp_case_insensitive("", "") == 0);

    assert(strcmp_case_insensitive("cat", "cats") < 0);

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
