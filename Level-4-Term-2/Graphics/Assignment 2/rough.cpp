#include <iostream>
#include <string>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int>a;
    a.push(4);
    a.push(5);
    a.push(6);
    int l=a.size();
    for(int i=l;i>1;i--)
    {
        a.pop();
    }
    cout<<a.top();
}
