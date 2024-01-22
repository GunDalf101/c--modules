#include "serialize.hpp"

Serializer::Serializer(std::string const &str) : _str(str) {
}

Serializer::Serializer(Serializer const &copy) : _str(copy.getStr()) {
}

Serializer::~Serializer() {
}

Serializer &Serializer::operator=(Serializer const &copy) {
    if (this != &copy)
        *this = copy;
    return *this;
}

std::string const &Serializer::getStr() const {
    return _str;
}

uintptr_t Serializer::serialize(Data *ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data *>(raw);
}