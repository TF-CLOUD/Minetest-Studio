#ifndef SWITCHER_H_INCLUDED
#define SWITCHER_H_INCLUDED

#endif // SWITCHER_H_INCLUDED

#include<bits/stdc++.h>
//����һ��hash������������ַ�����hashֵ�����ַ���ת��Ϊ1������
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
//����c++11�Զ������ֳ������﷨������һ��constexpr������switch��case��ǩ���������constexpr����
constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
{
    return *str ? hash_compile_time(str+1, (*str ^ last_value) * prime) : last_value;
}
//=============================================================
//�����Զ������ֳ���������һ��operator,�á�_hash����Ϊ�Զ������ֳ����ĺ�׺
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


