#include <iostream>
#include "Array.hpp"
#include <cstdlib>

#define MAX_VAL 10
int main(int, char**)
{
    
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    Array<int> numbers(MAX_VAL);
    std::cout << "Array with " << MAX_VAL << " elements size: " << numbers.size() << std::endl;
    
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = i * 10;
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    Array<int> copy_test(numbers);
    std::cout << "Copy array contents: ";
    for (unsigned int i = 0; i < copy_test.size(); i++) {
        std::cout << copy_test[i] << " ";
    }
    std::cout << std::endl;
    
    Array<int> assign_test;
    assign_test = numbers;
    std::cout << "Assigned array contents: ";
    for (unsigned int i = 0; i < assign_test.size(); i++) {
        std::cout << assign_test[i] << " ";
    }
    std::cout << std::endl;
    
    numbers[0] = 99;
    std::cout << "Original[0] = " << numbers[0] << std::endl;
    std::cout << "Copy[0] = " << copy_test[0] << " (should remain 0)" << std::endl;
    
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "Template";
    for (unsigned int i = 0; i < strings.size(); i++) {
        std::cout << "strings[" << i << "] = " << strings[i] << std::endl;
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
