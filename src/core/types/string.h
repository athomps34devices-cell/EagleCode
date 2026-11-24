#ifndef EAGLE_STRING_H
#define EAGLE_STRING_H

class String
{
public:
    String();
    String(const char* text);
    String(const String& other);
    ~String();

    String& operator=(const String& other);

    void append(const char* text);
    void append(const String& other);

    unsigned long long length() const;
    bool empty() const;
    const char* c_str() const;

private:
    char* data;
    unsigned long long size;
};
#endif