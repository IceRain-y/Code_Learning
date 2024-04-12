#pragma once
#include<iostream>
using namespace std;
#include<Identity.h>
#include<string>
#include<vector>
#include<computerRoom.h>
#include<fstream>
#include<globalFile.h>
#include<orderFile.h>


//学生类
class Student : public Identity
{
public:
    //默认构造
    Student();

    //有参构造（学号，姓名，密码）
    Student(int id, string name, string pwd);

    //菜单界面
    virtual void opermenu();

    //申请预约
    void applyOrder();

    //查看预约
    void showmyOrder();

    //查看所有预约
    void showAllOrder();

    //取消预约
    void cancelOrder();

    //学生学号
    int m_Id;

    //机房容器
    vector<computerRoom> vCom;
    
}