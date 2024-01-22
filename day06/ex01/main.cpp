#include "serialize.hpp"

int main() {
    Serializer serializer("Hello World!");
    Data *data = new Data();
    std::cout << "Data: " << data << std::endl;
    uintptr_t raw;
    raw = serializer.serialize(data);
    std::cout << raw << std::endl;
    data = serializer.deserialize(raw);
    std::cout << data << std::endl;
    delete data;
    return 0;
}