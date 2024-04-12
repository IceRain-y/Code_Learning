    #include<iostream>
    #include<Manager.h>
    using namespace std;
    
    //默认构造
    Manager::Manager()
    {

    }

    //有参构造
    Manager::Manager(string m_Name, String pwd)
    {
        this -> m_Name = name;
        this -> m_Pwd = pwd;

        //初始化容器 获取到所有文件中学生，老师的信息
        this -> initVector();

        //初始化机房信息
        ifstream ifs;
        ifs.open(COMPUTER_FILE, ios::in);

        computerRoom com;
        while(ifs >> com.m_ComId && ifs >> com.m_MaxNum)
        {
            vCom.push_back(com);
        }
        ifs.close();

        cout << "机房的数量为：" << v.Com.size() << endl;


    }

    //选择菜单
    void Manager::operMenu()
    {
        cout << "欢迎管理员： " << this -> m_Name << "登录！" << endl;
        cout << "\t\t -------------------------------------------------- |\n";
        cout << "\t\t |                                                  |\n";
        cout << "\t\t |                                                  |\n";
        cout << "\t\t |                 1.添加账号                        |\n";
        cout << "\t\t |                                                  |\n";
        cout << "\t\t |                 2.查看账号                        |\n";
        cout << "\t\t |                                                  |\n";
        cout << "\t\t |                 3.查看机房                        |\n";
        cout << "\t\t |                                                  |\n";
        cout << "\t\t |                 4.清空预约                        |\n";
        cout << "\t\t |                                                  |\n";
        cout << "\t\t |                 0.注销登录                        |\n";
        cout << "\t\t |                                                  |\n";
        cout << "\t\t --------------------------------------------------- \n";
        cout << "输入您的选择： " ;

    }

    //添加账号
    void Manager::addPerson()
    {
        cout << "请输入添加的账号类型" << endl;
        cout << "1.添加学生" << endl;
        cout << "2.添加老师" << endl;

        string fileName;    //操作文件名
        string tip;         //提示Id号
        string errorTip;    //重复错误提示

        ofstream ofs;       //文件操作对象

        int select = 0;
        cin >> select;      //接收用户的选项

        if(select == 1)
        {
            //添加的是学生
            fileName = STUDENT_FILE;
            tip = "请输入学号： "; 
            errorTip = "学号重复，请重新输入";
        }
        else
        {
            fileName = TEACHER_FILE;
            tip = "请输入职工号： "
            errorTip = "职工号重复，请重新输入";
        }

        //利用追加的方式 写文件
        ofs.open(fileName, ios::out | ios::app);

        int id;     //学号 / 职工号
        string name;    //姓名
        string pwd;     //密码


        cout << tip << endl;
        while(true)
        {
            cin >> id;
            //bool checkRepeat(id, select);
            bool ret = this -> checkRepeat(id, 1);
            if(ret)    //有重复内容
            {
                cout << errorTip <<endl;
            }
            else
            {
                break;
            }
        }

       
        cin >> id;

        cout << "请输入姓名是： " << endl;
        cin >> name;

        cout << "请输入密码是： " << endl;
        cin >> pwd;

        //向文件中添加数据
        ofs << id << "  " << name << " " << pwd << "  " << endl;
        cout << "添加成功" << endl;

        system("pause");
        system("cls");

        ofs.close();

        //调用初始化容器接口，重新获取文件中的数据
        this -> initVector();

    }

    void printStudent(Student & s)
    {
        cout << "学号： " << s.m_Id << "姓名" << s.m_Name << "密码： " << s.m_Pwd << endl;

    }

    void printTeacher(Teacher & s)
    {
        cout << "职工号： " << s.m_empId << "姓名" << s.m_Name << "密码： " << s.m_Pwd << endl;

    }


    //查看账号
    void Manager::showPerson()
    {
        cout << "请选择查看的内容: " << endl;
        cout << "1.查看所有学生" << endl;
        cout << "2.查看所有老师" << endl;

        int select = 0; //接收用户的选择
        cin >> select;

        if(select == 1)
        {
            //查看学生
            cout << "所有学生信息如下：" << endl;
            for_each(vStu.begin(),vStu.end(),printStudent);
        }
        else
        {
            //查看老师
            cout << "所有老师信息如下：" << endl;
            for_each(vTea.begin(),vTea.end(),printTeacher);
        }

        system("pause");
        system("cls");
    }

    //查看机房信息
    void Manager::showComputer()
    {
        cout << "机房信息如下： " << endl;

        for(vector<computerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
        {
            cout << "机房编号： " << it -> m_ComId << "机房的最大容量： " << it -> m_MaxNum << endl;
        }
        system("pause");
        system("cls");

    }

    //清空预约记录
    void Manager::clearFile()
    {
        ofstream ofs(ORDER_FLIE, ios::trunc);
        ofs.close();

        cout << "清空成功！" << endl;
        system("pause");
        system("cls");

    }

    //初始化容器
    void Manager::initVector()
    {
        //确保容器是清空的状态
        vStu.clear();
        vTea.clear();

        //读取信息  学生，老师
        ifstream ifs;
        ifs.open(STUDENT_FILE, ios::in);
        if(if.is_open())
        {
            cout << "文件读取失败" << endl;
            return;
        }

        Student s;
        while(ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_pwd)
        {
            vStu.push_back(s);
        }

        cout << "当前学生数量为： " << vStu.size() << endl;

        ifs.close();

        //读取信息  老师
        ifs.open(TEACHER_FILE, ios::in);
        Teacher t;
        while(ifs >> t.m_empId && ifs >> t.m_Name && ifs >> t.m_Pwd)
        {
            vTea.push_back(t);
        }

        cout << "当前老师数量为： " << vTea.size() << endl;
        ifs.close();

    }

    //检测重复  参数1 检测学号/职工号  参数2 检测类型
    bool Manager::checkRepeat(int id, int type)
    {
        if(type == 1)
        {
            //检测学生
            for(vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
            {
                if(id == it -> m_Id)
                {
                    return true;
                }
            }
        }
        else
        {
            //检测老师
            for(vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
            {
                if(id == it -> m_empId)
                {
                    return true;
                }
            }

        }

        return false;
    }