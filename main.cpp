#include<bits/stdc++.h>
#include "Headers/Main/Switcher.h"
#include "Headers/json/json.h"
using namespace std;

void loop();

string inputValue;
string head;

int main()
{
	head = "[Studio]";
	cout << head << "Hello! This is a console application." << endl;
    cout << head << "Welcome to Minetest Studio!" << endl;
    cout << head << "Please input '?' or 'help' to get commmand list,input 'exit' to exit." << endl;
    loop();
    return 0;
}

void loop()
{
    cout << head ;
    cin >> inputValue;
    switcher(inputValue.c_str(),head.c_str());
    loop();
}
