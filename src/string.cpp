#include <cstring>
#include <stdexcept>
#include "MyString.h"
char String :: pos_ = '\0';

// конец строки
String::String():size_st(0),str_(&pos_){
};
String::String(const char *str):size_st(std::strlen(str)){
    str_ = new char[size_st + 1];
    std ::strcpy(str_,str);
};
String::String(const char *str, unsigned count){
    str_ = new char[count + 1];
    for (unsigned i = 0; i < count; ++i ){
        str_[i] = *str;
        ++str;
    }
    str_[count] = '\0';
    size_st = count;
};
String :: String(char ch, unsigned count){
    str_ = new char[count + 1];
    for (unsigned i = 0; i < count; ++i ){
        str_[i] = ch;
    }
    str_[count] = '\0';
    size_st = count;
};
String::String(const String &other):size_st(other.size_st){
    str_ = new char (size_st +1);
    std :: strcpy(str_,other.str_);
};
String::String(String &&other):size_st(other.size_st),str_(other.str_){
    other.size_st = 0;
    other.str_ = &pos_;
};
String :: ~String(){
        if(str_!= &pos_){
            delete[] str_;
        }
};
String &String :: operator=(const String &other) {
    String temp (other);
    this-> swap(temp);
    return *this;
}
String &String :: operator=(String &&other){
    String temp (other);
    this-> swap(temp);
    other.str_ = &pos_;
    other.size_st = 0;
    return *this;

}
String &String :: operator+=(const String &suffix){
    String a(str_);
    std :: strcat(a.str_,suffix.str_);
    String temp(a.str_);
    this->swap(temp);
    return  *this;
}
String &String :: operator+=(const char *suffix){
    String a(str_);
    std :: strcat(a.str_,suffix);
    String temp(a.str_);
    this->swap(temp);
    return  *this;
}
String &String:: operator+=(char suffix){
    String a (suffix,1);
    String b (str_);
    std :: strcat(b.str_,a.str_);
    String temp(b.str_);
    this->swap(temp);
    return  *this;
}
void String :: swap(String &other){
    std :: swap (str_,other.str_);
    std :: swap (size_st,other.size_st);
}
char &String :: operator[](unsigned pos){
    return str_[pos];
}
const char String ::operator[](unsigned pos) const{
    return str_[pos];
}
char &String::at(unsigned int pos) {
    if (pos >= size_st) {
        throw std::out_of_range("");
    }
    return str_[pos];
}
const char String::at(unsigned int pos) const {
    if (pos >= size_st) {
        throw std::out_of_range("");
    }
    return str_[pos];
}
const char *String:: data() const{
    return str_;
};
unsigned int String::size() const{
    return size_st;
};
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




























