#include "Serializer.hpp"
#include <iostream>
#include "Data.h"

int main()
{
	Data data;
    data.id = 42;
    data.name = "Hello";
    data.boolean = true;
    std::cout << "ID: " << data.id << ", Name: " << data.name << "\n";
    std::cout << "Original pointer: " << &data << "\n";

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialize : " << raw << "\n";

    Data* ptr = Serializer::deserialize(raw);
    std::cout << "Deserialize pointer: " << ptr << "\n";

    std::cout << "ID: " << ptr->id << ", Name: " << ptr->name << ", Bool: " << ptr->boolean << "\n";
    return 0;
}
