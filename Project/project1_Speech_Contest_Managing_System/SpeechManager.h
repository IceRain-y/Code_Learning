#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<speaker>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<string>
#include<fstream>

using namespace std;

//设计演讲管理类
class SpeechManager
{
public:
    //构造函数
    SpeechManager();


    //菜单功能
    void SpeechManager::show_menu();

    //退出系统
    void exitSystem();

    //析构函数
    ~SpeechManager();

    //初始化容器和属性
    void initSpeech();

    //创建12名选手
    void createSpeaker();

    //开始比赛 比赛整个流程控制函数
    void startSpeech();

    //抽签
    void speechDraw();

    //比赛
    void speechContest();

    //显示得分
    void showScore();

    //保存分数
    void saveRecord();

    //读取记录
    void loadRecord();

    //显示往届记录
    void shouwRecord();

    //清空文件
    void clearRecord();

    //判断文件是否为空
    bool fileIsEmpty;

    map<int,vector<string>>m_Record;

    //成员属性
    //保存第一轮比赛比赛选手编号
    vector<int>v1;

    //第一轮晋级的选手编号容器
    vector<int>v2;

    //胜出前三名选手编号容器
    vector<int>vVectory;

    //存放编号以及对应具体选手容器
    map<int,Speaker>m_Speaker;

    //存放比赛轮数
    int m_Index;

};
