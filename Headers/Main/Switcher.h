#ifndef SWITCHER_H_INCLUDED
#define SWITCHER_H_INCLUDED

#endif // SWITCHER_H_INCLUDED

#include<bits/stdc++.h>
//定义一个hash函数，计算出字符串的hash值，将字符串转换为1个整数
typedef std::uint64_t hash_t;

constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;

hash_t hash_(char const* str)
{
    hash_t ret{basis};

    while(*str){
        ret ^= *str;
        ret *= prime;
        str++;
    }

    return ret;
}
//=============================================================
//利用c++11自定义文字常量的语法，定义一个constexpr函数，switch的case标签处调用这个constexpr函数
constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
{
    return *str ? hash_compile_time(str+1, (*str ^ last_value) * prime) : last_value;
}
//=============================================================
//利用自定义文字常量，重载一个operator,用“_hash”作为自定义文字常量的后缀
constexpr unsigned long long operator "" _hash(char const* p, size_t)
{
    return hash_compile_time(p);
}
//==============================================
 void switcher(const char* str,const char* head)
{
    using namespace std;
    switch(hash_(str)){
    case "?"_hash:
        cout << head << "Noting" << endl;
        break;
    case "help"_hash:
        cout << head << "Noting" << endl;
        break;
    case "exit"_hash:
        exit(0);
    }
}


