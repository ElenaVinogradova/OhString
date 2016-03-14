#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class String {
private:
    unsigned int size_st;
    char * str_;
    static char pos_;
public:
    String();
    String(const char *str);
    String(const char *str, unsigned count);
    String(char ch, unsigned count);
    String(const String &other);
    String(String &&other);
    ~String();
    String & operator=(const String &other);
    String & operator=(String &&other);

    String & operator+=(const String &suffix);
    String & operator+=(const char *suffix);
    String & operator+=(char suffix);
    void swap(String &other);
    char & operator[](unsigned pos);
    const char operator[](unsigned pos) const;

    char & at(unsigned int pos);
    const char  at (unsigned int pos)const ;

    const char * data() const;

    unsigned int size() const;

    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator<(const String &lhs, const String &rhs);
};
String operator+(const String &lhs, const String &rhs);
String operator+(const String &lhs, const char *rhs);
String operator+(const char *lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
#endif




