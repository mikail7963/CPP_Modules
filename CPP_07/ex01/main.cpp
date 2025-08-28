#include "iter.hpp"
#include <iostream>
#include <string>

template<typename T>
void print(T& x)
{
	std::cout << x << " ";
}

void printConstInt(const int& x)
{
	std::cout << "(const)" << x << " ";      
}

template<typename T>
void printConst(const T& x)
{
	std::cout << x << " ";
}

void increment(int& x)
{
    x *= 2;
}

void uppercase(char& c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}

void addExclamation(std::string& str)
{
    str += "!";
}

int main(void)
{
    std::cout << "int array:" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    iter(intArray, intSize, increment);
    std::cout << "After increment: ";
    iter(intArray, intSize, print<int>);
    std::cout << std::endl;
    
    std::cout << "\nCONST int array:" << std::endl;
    const int constIntArray[] = {10, 20, 30, 40, 50};
    size_t constIntSize = sizeof(constIntArray) / sizeof(constIntArray[0]);
    
    std::cout << "Const array with const function: ";
    iter(constIntArray, constIntSize, printConst<int>);
    std::cout << std::endl;
    
    std::cout << "Const array with specific const function: ";
    iter(constIntArray, constIntSize, printConstInt);
    std::cout << std::endl;
    
    std::cout << "\nChar array:" << std::endl;
    char charArray[] = {'h', 'e', 'l', 'l', 'o'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
    
    std::cout << "Original: ";
    iter(charArray, charSize, print<char>);
    std::cout << std::endl;
    
    iter(charArray, charSize, uppercase);
    std::cout << "After uppercase: ";
    iter(charArray, charSize, print<char>);
    std::cout << std::endl;
    
    const char constCharArray[] = {'W', 'O', 'R', 'L', 'D'};
    size_t constCharSize = sizeof(constCharArray) / sizeof(constCharArray[0]);
    
    std::cout << "Const char array: ";
    iter(constCharArray, constCharSize, printConst<char>);
    std::cout << std::endl;
    
    std::cout << "\nString array:" << std::endl;
    std::string stringArray[] = {"Hello", "World", "Test"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "Original: ";
    iter(stringArray, stringSize, print<std::string>);
    std::cout << std::endl;
    
    iter(stringArray, stringSize, addExclamation);
    std::cout << "After adding exclamation: ";
    iter(stringArray, stringSize, print<std::string>);
    std::cout << std::endl;

    const std::string constStringArray[] = {"Const", "String", "Array"};
    size_t constStringSize = sizeof(constStringArray) / sizeof(constStringArray[0]);

    std::cout << "Const string array: ";
    iter(constStringArray, constStringSize, printConst<std::string>);
    std::cout << std::endl;
    return 0;
}
