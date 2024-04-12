#pragma once
#include<iostream>
#include<Identity>
#include<string>
#include<fstream>
#include<globalFile.h>
#include<Student.h>
#include<Teacher.h>
#include<vector>
#include<algorithm>

using namespace std;

class Manager : public Identity
{
    //默认构造
    Manager();

    //有参构造
    Manager(string m_Name, String pwd);

    //选择菜单
    virtual void operMenu();

    //添加账号
    void addPerson();

    //查看账号
    void showPerson();

    //查看机房信息
    void showComputer();

    //清空预约记录
    void clearFile();

    //初始化容器
    void initVector();

    //检测重复
    bool checkRepeat(int id, int type);

    //学生容器
    vector<Student> vStu;

    //老师容器
    vector<Teacher> vTea;

    //机房信息
    vector<computerRoom>vCom;


}