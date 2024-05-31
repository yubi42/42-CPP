#pragma once

#include <stdint.h>
#include <string>
#include <iostream>

struct Data
{
	int age;
	float height;
};

struct AnotherData 
{
    int n;
    float f;
    double d;
};

class Serializer
{
private:
	Serializer(void);
	Serializer(const Serializer &);
	Serializer &operator=(const Serializer &);

public:
    virtual ~Serializer(void);

	static uintptr_t serialize(Data *ptr);
    static uintptr_t anotherSerialize(AnotherData *ptr);
	static Data *deserialize(uintptr_t raw);
    static AnotherData *anotherDeserialize(uintptr_t raw);
};