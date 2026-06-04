#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>

struct Data;

class Serializer {
private:
    // ------------------ OCF ------------------

    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();

public:
    // ------------------ Methods ------------------

    static uintptr_t serialize(Data* ptr);
    static Data*     deserialize(uintptr_t raw);
};

#endif
