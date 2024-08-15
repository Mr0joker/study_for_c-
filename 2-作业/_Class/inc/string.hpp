#include <ostream>
#ifndef STRING_HPP
#define STRING_HPP

class String
{
private:
    char *_data;

public:
    String(const char *s = nullptr);
    ~String();
    String(const String &str);
    String& operator=(const char *s);
    String& operator=(const String &str); // 接受一个String对象的引用

    friend std::ostream &operator<<(std::ostream &out, const String &str); // 输出String对象
    friend int strlen(const String &str);                                  // 计算并返回String对象的长度
    friend bool empty(const String &str);                                  // 判断String对象是否为空
    friend void swap(String &str1, String &str2);                           // 交换两个String对象的内容

    String operator+(const String &str) const; // 连接两个String对象
    String &operator+=(const String &str);     // 将一个String对象连接到当前对象
    bool operator==(const String &str);        // 比较两个String对象是否相等
    bool operator>(const String &str);         // 比较两个String对象的大小
    bool operator<(const String &str);         // 比较两个String对象的大小
    char operator[](int index);                // 访问String对象中的特定字符
    char at(int index);                        // 访问String对象中的特定字符，提供边界检查
};

int strlen(const String &str);
bool empty(const String &str);
std::ostream &operator<<(std::ostream &out, const String &str);
void swap(String &str1, String &str2);

#endif // STRING_HPP