#pragma once        //防止头文件重复包含
#include<iostream>
using namespace std;

//身份抽象基类
class Indentity
{
public:

    //操作菜单，纯虚函数
    virtual void opermenu() = 0;        //多态，子类必须重写父类中的虚函数

    string m_Name;      //用户名
    string m_Pwd;       //密码
    
};