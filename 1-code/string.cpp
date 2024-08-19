#include "String.hpp"
#include <iostream>

String::String(const char *s)
{
    if (s == nullptr)
    {
        _data = new char[1];
        _data[0] = '\0';
    }
    else
    {
        int len = 0;
        while (s[len++] != '\0');
        _data = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            _data[i] = s[i];
        }
        _data[len] = '\0';
    }
}

String::~String()
{
    if (_data != nullptr)
        delete[] _data;
}

String::String(const String &str)
{
    this->_data = new char[strlen(str._data) + 1];
    for (int i = 0; i < strlen(str); i++)
    {
        this->_data[i] = str._data[i];
    }
    this->_data[strlen(str)] = '\0';
}

String &String::operator=(const char *s)
{
    if (this->_data != nullptr)
        delete[] _data;
    if (s == nullptr)
    {
        _data = nullptr;
    }
    else
    {
        int len = 0;
        while (s[len++] != '\0')
            ;

        _data = new char[len + 1];
        for (int i = 0; i < len; i++)
        {
            _data[i] = s[i];
        }
        _data[len] = '\0';
    }
    return *this;
}

String &String::operator=(const String &str)
{
    if (this == &str)
        return *this;
    delete[] _data;
    this->_data = new char[strlen(str) + 1];
    for (int i = 0; i < strlen(str); i++)
    {
        this->_data[i] = str._data[i];
    }
    this->_data[strlen(str)] = '\0';
    return *this;
}

String String::operator+(const String &str) const
{
    String result(this->_data);
    result += str;
    return result;
}

String &String::operator+=(const String &str)
{
    int len1 = strlen(*this);
    int len2 = strlen(str);
    char *new_data = new char[len1 + len2 + 1];
    for (int i = 0; i < len1; i++)
    {
        new_data[i] = this->_data[i];
    }
    for (int i = 0; i < len2; i++)
    {
        new_data[len1 + i] = str._data[i];
    }
    new_data[len1 + len2] = '\0';
    delete this->_data;
    this->_data = new_data;
    return *this;
}

bool String::operator==(const String &str)
{
    if (strlen(*this) == strlen(str))
    {
        for (int i = 0; i < strlen(*this); i++)
        {
            if (this->_data[i] != str._data[i])
                return false;
        }
        return true;
    }
    return false;
}

bool String::operator>(const String &str)
{
    int len1 = strlen(*this);
    int len2 = strlen(str);
    if (len1 > len2)
        return true;
    else if (len1 < len2)
        return false;
    else
    {
        for (int i = 0; i < len1; i++)
        {
            if (this->_data[i] - str._data[i] > 0)
                return true;
            else if (this->_data[i] - str._data[i] < 0)
                return false;
        }
        return false;
    }
}

bool String::operator<(const String &str)
{
    int len1 = strlen(*this);
    int len2 = strlen(str);
    if (len1 < len2)
        return true;
    else if (len1 > len2)
        return false;
    else
    {
        for (int i = 0; i < len1; i++)
        {
            if (this->_data[i] - str._data[i] < 0)
                return true;
            else if (this->_data[i] - str._data[i] > 0)
                return false;
        }
        return false;
    }
}

char String::operator[](int index)
{
    if (index >= strlen(*this) || index < 0)
        throw "Index out of range";
    return this->_data[index];
}

char String::at(int index)
{
    if (index >= strlen(*this) || index < 0)
        throw std::out_of_range("Index out of range");
    return this->_data[index];
}

std::ostream &operator<<(std::ostream &out, const String &str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        out << str._data[i];
    }
    // out << std::endl;
    return out;
}

void swap(String &str1, String &str2)
{
    String temp = std::move(str1);
    str1 = std::move(str2);
    str2 = std::move(temp);
}

int strlen(const String &str)
{
    int i = 0;
    while (str._data[i] != '\0')
    {
        i++;
    }
    return i;
}

int strlen(const char *s)
{
    int len = 0;
        while (s[len++] != '\0');
    return len;
}

bool empty(const String &str)
{
    if (strlen(str) == 0)
        return true;
    return false;
}
