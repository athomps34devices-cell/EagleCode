#include "string.h"

String::String()
{
    size = 0;
    data = new char[1];
    data[0] = '\0';
}

String::String(const char* text)
{
    size = 0;

    if (text != nullptr)
    {
        while (text[size] != '\0')
        {
            size++;
        }
    }

    data = new char[size + 1];

    for (unsigned long long i = 0; i < size; i++)
    {
        data[i] = text[i];
    }

    data[size] = '\0';
}

String::String(const String& other)
{
    size = other.size;
    data = new char[size + 1];

    for (unsigned long long i = 0; i < size; i++)
    {
        data[i] = other.data[i];
    }

    data[size] = '\0';
}

String::~String()
{
    delete[] data;
}

String& String::operator=(const String& other)
{
    if (this == &other)
    {
        return *this;
    }

    char* newData = new char[other.size + 1];

    for (unsigned long long i = 0; i < other.size; i++)
    {
        newData[i] = other.data[i];
    }

    newData[other.size] = '\0';

    delete[] data;

    data = newData;
    size = other.size;

    return *this;
}

void String::append(const char* text)
{
    if (text == nullptr)
    {
        return;
    }

    unsigned long long addedSize = 0;

    while (text[addedSize] != '\0')
    {
        addedSize++;
    }

    char* newData = new char[size + addedSize + 1];

    for (unsigned long long i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }

    for (unsigned long long i = 0; i < addedSize; i++)
    {
        newData[size + i] = text[i];
    }

    size += addedSize;
    newData[size] = '\0';

    delete[] data;
    data = newData;
}

void String::append(const String& other)
{
    append(other.data);
}

unsigned long long String::length() const
{
    return size;
}

bool String::empty() const
{
    return size == 0;
}

const char* String::c_str() const
{
    return data;
}