#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
    Data      data;
    uintptr_t raw;
    Data*     ptr;

    data.name = "example data";
    data.id = 42;
    data.value = 21.5;

    raw = Serializer::serialize(&data);
    ptr = Serializer::deserialize(raw);

    std::cout << "Original pointer:     " << &data << std::endl;
    std::cout << "Serialized value:     " << raw << std::endl;
    std::cout << "Deserialized pointer: " << ptr << std::endl;

    if (ptr == &data) {
        std::cout << "Pointers are equal" << std::endl;
        std::cout << "Data: " << ptr->name << ", " << ptr->id << ", " << ptr->value << std::endl;
    } else {
        std::cout << "Pointers are different" << std::endl;
    }
    return 0;
}
