#pragma once
#include<iostream>
using namespace std;
#include<Identity.h>
#include<string>
#include<OrderFile.h>

class Teacher : public Identity
{
public:
    //默认构造
    Teacher();

    //有参构造（职工编号，姓名，密码）
    Teacher(int empId, string name, string pwd);

    //菜单界面
    virtual void opermenu();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void ValidOrder();

    //学生学号
    int m_empId;    //教师编号
    
}