#include "MyString.h"
#include <cstring>
#include <stdexcept>
#define __STDC_WANT_LIB_EXT1__ 1


char String::npos = '\0';

String::String() : str_(&npos), size_(0) {}

String::String(const char *str) : size_(std::strlen(str)) {
    str_=new char[size_+1];
    std::strcpy(str_, str);
}

String::String(const char *str, unsigned count) : size_(count) {
    str_= new char[size_+1];
    std::strcpy(str_, str);
}

String::String(char ch, unsigned count) : size_(count) {
    str_ = new char[count + 1];
    for (unsigned i = 0; i < count; ++i ){
        str_[i] = ch;
    }
    str_[count] = '\0';
    size_ = count;
}

String::String(const String &other) : size_(other.size_) {
    str_ = new char[size_+1];
    std::strcpy(str_, other.str_);
}

String::String(String &&other) : str_(other.str_), size_(other.size_) {
    other.str_ = &npos;
    other.size_ = 0;
}

String::~String() {
    if (str_ != &npos) {
        delete[] str_;
    }
}

String &String::operator=(const String &other){
    String b(other);
    this->swap(b);
    return *this;
}

String &String::operator=(String &&other){
    String b(other);
    this->swap(b);
    return *this;
}

String &String::operator+=(const String &suffix) {
    char *str = new char[size_+suffix.size_+1];
    std::strcpy(str, str_);
    std::strcpy((str+size_), suffix.str_);
    if (str_ != &npos) {
        delete[] str_;
    }
    str_ = str;
    size_+= suffix.size_;
    /*char *a = new char(size_);
    std::strcpy(a,str_);
    std::strcat(a,suffix.str_);
    String temp (a);
    this->swap(temp);*/
    return *this;
}

String &String::operator+=(const char *suffix) {
    unsigned int size = std::strlen(suffix);
    char *str = new char[size_+size+1];
    std::strcpy(str, str_);
    std::strcpy((str+size_), suffix);
    if (str_ != &npos) {
        delete[] str_;
    }
    size_+= size;
    str_ = str;
    return *this;
    /*char a [size_];
    std::strcat (a,size_,str_);
    std::strcat(a,suffix);
    String temp (a);
    this->swap(temp);*/
    return *this;
}

String &String::operator+=(char suffix) {
    char *str = new char[size_+2];
    std::strcpy(str, str_);
    *(str+size_) = suffix;
    *(str+size_+1) = npos;
    if (str_ != &npos) {
        delete[] str_;
    }
    size_= size_ + 1;
    str_ = str;
    /*String b(suffix,1);
    char *a = new char(size_);
    std::strcpy(a,str_);
    std::strcat(a,b.str_);
    String temp (a);
    this->swap(temp);*/
    return *this;
}

void String::swap(String &other) {
    std::swap(str_, other.str_);
    std::swap(size_, other.size_);
}

char &String::operator[](unsigned pos) {
    return str_[pos];
}

const char String::operator[](unsigned pos) const {
    return str_[pos];
}

char &String::at(unsigned int pos) {
    if (pos >= size_) {
        throw std::out_of_range("");
    }
    return str_[pos];
}
const char String::at(unsigned int pos) const {
    if (pos >= size_) {
        throw std::out_of_range("");
    }
    return str_[pos];
}

const char *String::data() const {
    return str_;
}

unsigned String::size() const {
    return size_;
}

bool operator==(const String &lhs, const String &rhs){
    int k = std :: strcmp(lhs.str_,rhs.str_);
    if (k == 0){
        return true;
    }
    else {return false;}
}
bool operator<(const String &lhs, const String &rhs) {
    int k = std :: strcmp(lhs.str_,rhs.str_);
    if (k < 0){
        return true;
    }
    else {return false;}
}
String operator+(const String &lhs, const String &rhs) {
    return String(lhs) += rhs;
}
String operator+(const String &lhs, const char *rhs) {
    return String(lhs) += rhs;
}
String operator+(const char *lhs, const String &rhs) {
    String B(rhs);
    B += lhs;
    return B;
}
bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}
bool operator<=(const String &lhs, const String &rhs) {
    return (lhs == rhs) || (lhs < rhs);
}
bool operator>(const String &lhs, const String &rhs) {
    return !(lhs <= rhs);
}
bool operator>=(const String &lhs, const String &rhs) {
    return !(lhs < rhs);
}
std::ostream &operator<<(std::ostream &stream, const String &A) {
    return stream << A.data();
}