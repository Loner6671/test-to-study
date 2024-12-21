#include<iostream>                            
#include<string>           // GBK编码 
#include<fstream>
#include<limits>
using namespace std;
void showmenu(void) ;        // 菜单
class CStudent
{
public:
void save_data(const CStudent& student);
int add_student(void);
int search_student(void);
int student_num;
string name;
int stu_num;
string gender;
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
CStudent():student_num(0),name(""),stu_num(0),gender(""),age(0),native_place(""),major(""),class_num(0),math_grade(0),
cs_grade(0),eng_grade(0),py_grade(0),df_grade(0),record(""){}

CStudent(int student_num,string name,int stu_num,string gender,int age,string native_place,string major,int class_num,int math_grade,
int cs_grade,int eng_grade,int py_grade,int df_grade,string record)
:student_num(student_num),name(name),stu_num(stu_num),gender(gender),age(age),native_place(native_place),major(major),
class_num(class_num),math_grade(math_grade),cs_grade(cs_grade),eng_grade(eng_grade),py_grade(py_grade),df_grade(df_grade),record(record){}

friend ostream& operator<<(ostream& os, const CStudent& student)
{
    os<<"编号"<<student.student_num<<"\t姓名"<<student.name<<"\t学号"<<student.stu_num<<"\t性别"<<student.gender<<"\t年龄"<<student.age<<
    "\t籍贯"<<student.native_place<<"\t专业"<<student.major<<"\t班级"<<student.class_num<<"\t数学成绩"<<student.math_grade<<"\t计算机成绩"<<
    student.cs_grade<<"\t英语成绩"<<student.eng_grade<<"\t物理成绩"<<student.py_grade<<"\t思想道德与法治成绩"<<student.df_grade<<"\t奖惩记录"<<
    student.record<<endl;
    return os;
}
}; 
int add_student(const string& filename)        // 新增学生数据
{
    CStudent student;
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
        while(true)
        {
            cout<<"请输入学生的编号：";
            cin>>student.student_num;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "输入错误！请输入数字。\n";
            }
            else if(student.student_num<0 || student.student_num>1000)
            {
                cout<<"输入错误！编号超出范围！\n";
                num1=-1;
                return 0;
            }
            else
            {
                break;
            }
        }
        cout<<"请输入学生的姓名：";
        cin>>student.name;
        while(true)
        {
            cout<<"请输入学生的学号：";
            cin>>student.stu_num;
            if (cin.fail())             // 检测输入是否失败
            {  
                cin.clear();        // 清除错误标志
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // 忽略错误输入
                cout << "输入错误！请输入数字。\n";
            } 
            else
                break;
        }
        cout<<"请输入学生的性别(m/f): ";
        cin>>student.gender;
        while(true)
        {
            cout<<"请输入学生的年龄：";
            cin>>student.age;
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
        cin>>student.native_place;
        cout<<"请输入学生的专业：";
        cin>>student.major;
        while(true)
        {
            cout<<"请输入学生的班级：";
            cin>>student.class_num;
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
            cin>>student.math_grade;
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
            cin>>student.cs_grade;
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
            cin>>student.eng_grade;
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
            cin>>student.py_grade;
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
            cin>>student.df_grade;
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
        cin>>student.record;
        ofstream ofs;
        ofs.open("student.dat",ios::binary|ios::app);
        if(!ofs)
        {
            cout<<"文件打开失败！\n";
            num1=-1;
            return 0;
        }   
        else
        {
            fstream ofs;
            ofs.open("student.dat",ios::binary|ios::in|ios::out);
            if(!ofs)
            {
                cout<<"文件打开失败！\n";
                num1=-1;
                return 0;
            }
            else
            {
                ofs.seekp((student.student_num-1)*sizeof(CStudent));
                ofs.write((char*)&student,sizeof(CStudent));
                cout<<"学生数据添加成功！\n";
            }
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
int search_student(const string& filename)        // 查找学生数据
{
    CStudent student;
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
        else if(num2<0 || num2> 1000)
        {
            cout<<"输入错误！编号超出范围！\n"; 
            num1=-1;
            return 0;
        }   
        else
        {
        
            ifstream ifs;
            ifs.open("student.dat",ios::binary|ios::in);
            if(!ifs)
            {
                cout<<"文件打开失败！\n";                    num1=-1;
                return 0;
            }
            else
            {
                ifs.seekg((num2-1)*sizeof(CStudent));
                ifs.read(reinterpret_cast<char*>(&student),sizeof(CStudent));
                if(ifs.eof()||student.student_num!=0)    
                {
                    cerr<<"学生数据不存在！\n";
                }            
                else
                {
                    cout<<student;
                }
                ifs.close();
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
                add_student("student.dat");
                break;
            case 2 :
                break;
            case 3 :
                search_student("student.dat");
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