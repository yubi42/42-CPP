#include "Serializer.hpp"


int main()
{
    Data data;
    data.age = 42;
    data.height = 1.42;

    std::cout << "Init Data: age = " << data.age
          << ", height = " << data.height << std::endl;

    AnotherData anotherData;
    anotherData.f = 1.0;
    anotherData.n = 1;
    anotherData.d = 1.0;

    AnotherData *deserializedAnotherData = &anotherData;

    std::cout << "Init deserializedAnotherData: n = " << deserializedAnotherData->n
          << ", f = " << deserializedAnotherData->f
          << ", d = " << deserializedAnotherData->d << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    deserializedAnotherData = Serializer::anotherDeserialize(raw);

    std::cout << "Set data address of data to deserializedAnotherData" << std::endl;

    std::cout << "Deserialized AnotherData: n = " << deserializedAnotherData->n
              << ", f = " << deserializedAnotherData->f
              << ", d = " << deserializedAnotherData->d << std::endl
              << "Memory address data: "<< &data << std::endl 
              << "Memory address deserializedAnotherData: " << deserializedAnotherData << std::endl;

    deserializedAnotherData->n = 1;
    
    std::cout << "After changing deserializedAnotherData's n(int) to: " << deserializedAnotherData->n
              << " data.age(int) is: " << data.age << std::endl;

}