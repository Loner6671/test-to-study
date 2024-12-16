#include<iostream>                            
#include<string>           // GBK编码 
#include<fstream>
#include<cstring>
#include<limits>
using namespace std;
void showmenu(void) ;        // 菜单
void len_string(ofstream& outfile, const string& st);       // 写入字符串长度
#define max_stu 1000        // 定义最大学生数
class CStudent
{
public:
void save_data(const CStudent& student);
int add_student(void);
int search_student(void);
int student_num[max_stu];
string name;
int stu_num;
char gender[2];
int age;
string native_place;
string major;
int class_num;
int math_grade;
int cs_grade;
int eng_grade;
int py_grade;
int df_grade;
string record;
};
int CStudent::add_student(void)        // 新增学生数据
{
    cout<<"1:返回上一级\n2:新增学生数据\n";
    int num1 ;
    cin>>num1;
    if(num1==1)
    {
        num1=-1;    
        return 0;
    }
    else if(num1==2)
    {
        num1=-1;
        for(int i=0;i<max_stu;i++)
        {
            student_num[i];
        }
        cout<<"请输入学生的姓名：";
        cin>>name;
        while(true)
        {
            cout<<"请输入学生的学号：";
            cin>>stu_num;
            if (cin.fail())             // 检测输入是否失败
            {  
                cin.clear();        // 清除错误标志
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 忽略错误输入
                cout << "输入错误！请输入数字。\n";
            } 
            else
                break;
        }
        cout<<"请输入学生的性别：";
        cin>>gender;
        while(true)
        {
            cout<<"请输入学生的年龄：";
            cin>>age;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入错误！请输入数字。\n";
            }
            else
                break;
        }
        cout<<"请输入学生的籍贯：";
        cin>>native_place;
        cout<<"请输入学生的专业：";
        cin>>major;
        while(true)
        {
            cout<<"请输入学生的班级：";
            cin>>class_num;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入错误！请输入数字。\n";
            }
            else
                break;
        }    
        while(true)
        {
            cout<<"请输入学生的数学成绩：";
            cin>>math_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入错误！请输入数字。\n";
            }
            else
                break;
        }
        while(true)
        {
            cout<<"请输入学生的计算机成绩：";
            cin>>cs_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入错误！请输入数字。\n";
            }
            else
                break;
        }
        while(true)
        {
            cout<<"请输入学生的英语成绩：";
            cin>>eng_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入错误！请输入数字。\n";
            }
            else
                break;
        }
        while(true)
        {
            cout<<"请输入学生的物理成绩：";
            cin>>py_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入错误！请输入数字。\n";
            }
            else
                break;
        }
        while(true)
        {
            cout<<"请输入学生的思想道德与法治成绩：";
            cin>>df_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入错误！请输入数字。\n";
            }
            else
                break;
        }
        cout<<"请输入学生的奖惩记录：";
        cin>>record;
        cout<<"学生数据添加成功！\n";
        CStudent student;
        ofstream ofs;
        ofs.open("student.txt",ios::binary|ios::app);
        if(!ofs)
        {
            cout<<"文件打开失败！\n";
            num1=-1;
            return 0;
        }   
        else
        {
            ofs.write((const char*)&student.student_num, sizeof(student.student_num));
            len_string(ofs, student.name);
            ofs.write((const char*)&student.stu_num, sizeof(student.stu_num));
            len_string(ofs, student.gender);
            ofs.write((const char*)&student.age, sizeof(student.age));
            len_string(ofs, student.native_place);
            len_string(ofs, student.major);
            ofs.write((const char*)&student.class_num, sizeof(student.class_num));
            ofs.write((const char*)&student.math_grade, sizeof(student.math_grade));
            ofs.write((const char*)&student.cs_grade, sizeof(student.cs_grade));
            ofs.write((const char*)&student.eng_grade, sizeof(student.eng_grade));
            ofs.write((const char*)&student.py_grade, sizeof(student.py_grade));
            ofs.write((const char*)&student.df_grade, sizeof(student.df_grade));
            len_string(ofs, student.record);
        }
        ofs.close();
        return 0;
    }
    else
    {
        cout<<"输入错误！\n";
        num1=-1;
        return 0;
    }
    return 0;
}
void len_string(ofstream& outfile, const string& st)        // 写入字符串长度
{
    size_t length = st.size();          // 获取字符串长度
    outfile.write(reinterpret_cast<const char*>(&length), sizeof(length));          //转换指针类型并写入字符串长度 
    outfile.write(st.c_str(), length);              // 写入字符串数据
}
void read_string(ifstream& infile, string& st)        // 读取字符串
{
    size_t length = st.size();
    infile.read(reinterpret_cast<char*>(&length), sizeof(length));
    char* buffer = new char[length];
    infile.read(buffer, length);
    st.assign(buffer, length);
    delete[] buffer;
}
int CStudent::search_student(void)        // 查找学生数据
{
    int num1,num2=0;
    cout<<"1:返回上一级\n2:查找学生数据\n";
    cin>>num1;
    if(num1==1)
    {
        num1=-1;
        return 0;
    }
    else if(num1==2)
    {
        cout<<"请输入学生的编号：";
        cin>>num2;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入错误！请输入数字。\n";
        }
        else if(num2<0 || num2>max_stu)
        {
            cout<<"输入错误！编号超出范围！\n"; 
            num1=-1;
            return 0;
        }   
        else
        {
            for(int i=0;i<=num2;i++)
            {
                ifstream ifs;
                ofstream ofs;
                ifs.open("student.txt",ios::binary|ios::in);
                if(!ifs)
                {
                    cout<<"文件打开失败！\n";
                    num1=-1;
                    return 0;
                }
                else
                {
                    for(int i=0;i<=num2;i++)
                    {
                        ifs.seekg(i*sizeof(CStudent),ios::beg);
                        if(i==num2)
                        {
                            CStudent student;
                            ifs.read((char*)&student.student_num, sizeof(student.student_num));
                            cout<<student.student_num<<"\t";
                            read_string(ifs,student.name);
                            cout<<student.name<<"\t";
                            read_string(ifs,student.gender);
                            cout<<student.gender<<"\t";
                            ifs.read((char*)&student.age, sizeof(student.age));
                            cout<<student.age<<"\t";
                            read_string(ifs,student.native_place);
                            cout<<student.native_place<<"\t";
                            read_string(ifs,student.major);
                            cout<<student.major<<"\t";
                            ifs.read((char*)&student.class_num, sizeof(student.class_num));
                            cout<<student.class_num<<"\t";
                            ifs.read((char*)&student.math_grade, sizeof(student.math_grade));
                            cout<<student.math_grade<<"\t";
                            ifs.read((char*)&student.cs_grade, sizeof(student.cs_grade));
                            cout<<student.cs_grade<<"\t";
                            ifs.read((char*)&student.eng_grade, sizeof(student.eng_grade));
                            cout<<student.eng_grade<<"\t";
                            ifs.read((char*)&student.py_grade, sizeof(student.py_grade));       
                            cout<<student.py_grade<<"\t";
                            ifs.read((char*)&student.df_grade, sizeof(student.df_grade));
                            cout<<student.df_grade<<"\t";
                            read_string(ifs, student.record);
                            cout<<student.record<<"\n";
                            ifs.close();
                        }
                    } 
                }
            }    
        }
    }
    else
    {
        cout<<"输入错误！\n";
        num1=-1;
        return 0;
    }
    return 0;
}
void showmenu(void)        // 菜单
{
    cout<<"******************************************************************************\n";
    cout<<"************______________________________________________________************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|***************欢迎来到学生学籍管理系统*************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************1、新增学生数据*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************2、更改学生数据*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************3、查找学生数据*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************4、删除学生数据*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************5、学生成绩处理*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************6、退出系统*************************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************——————————————————————————————————————————————————————************\n";
    cout<<"******************************************************************************\n";
    cout<<"******************************************************************************\n";
    return;
}
void grademanage()        // 学生成绩处理
{
    int s_num;
    cout<<"请输入学生的学号：";
    cin>>s_num;
    cout<<"******************************************************************************\n";
    cout<<"************______________________________________________________************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************1、列出学生的成绩********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************2、计算学生平均分********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************3、计算学生各科及总成绩排名***********|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************4、计算学生GPA及排名*****************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************5、列出总成绩超过n分的特定性别学生****|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************6、返回上一级***********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************——————————————————————————————————————————————————————************\n";
    cout<<"******************************************************************************\n";
    cout<<"******************************************************************************\n";
    return;
}
int main()
{
    int num;
    CStudent a;
    while(true)
    {
        showmenu();
        cout<<"请输入您的选择：";
        cin>>num;
        switch (num)
        {
            num=-1;
            case 1 :
                a.add_student();
                break;
            case 2 :
                break;
            case 3 :
                a.search_student();
                break;
            case 4 :
                break;
            case 5 :
                grademanage();
                cin>>num;
                switch (num)
                {
                case 1 :
                    break;
                case 2 :        
                    break;
                case 3 :        
                    break;
                case 4 :        
                    break;
                case 5 :        
                    break;
                case 6 : 
                    showmenu();
                    break;
                default :        
                    cout<<"输入错误！\n";
                    break;
                }
                break;
            case 6 :
                return 0;
                break;
            default :
                cout<<"输入错误！\n";
                break;
        }
    }
}