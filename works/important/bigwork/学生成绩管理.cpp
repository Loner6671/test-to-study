#include<iostream>                            
#include<string>           // GBK���� 
#include<fstream>
#include<limits>
using namespace std;
void showmenu(void) ;        // �˵�
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
    os<<"���"<<student.student_num<<"\t����"<<student.name<<"\tѧ��"<<student.stu_num<<"\t�Ա�"<<student.gender<<"\t����"<<student.age<<
    "\t����"<<student.native_place<<"\tרҵ"<<student.major<<"\t�༶"<<student.class_num<<"\t��ѧ�ɼ�"<<student.math_grade<<"\t������ɼ�"<<
    student.cs_grade<<"\tӢ��ɼ�"<<student.eng_grade<<"\t����ɼ�"<<student.py_grade<<"\t˼������뷨�γɼ�"<<student.df_grade<<"\t���ͼ�¼"<<
    student.record<<endl;
    return os;
}
}; 
int add_student(const string& filename)        // ����ѧ������
{
    CStudent student;
    cout<<"1:������һ��\n2:����ѧ������\n";
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
            cout<<"������ѧ���ı�ţ�";
            cin>>student.student_num;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������������֡�\n";
            }
            else if(student.student_num<0 || student.student_num>1000)
            {
                cout<<"������󣡱�ų�����Χ��\n";
                num1=-1;
                return 0;
            }
            else
            {
                break;
            }
        }
        cout<<"������ѧ����������";
        cin>>student.name;
        while(true)
        {
            cout<<"������ѧ����ѧ�ţ�";
            cin>>student.stu_num;
            if (cin.fail())             // ��������Ƿ�ʧ��
            {  
                cin.clear();        // ��������־
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ���Դ�������
                cout << "����������������֡�\n";
            } 
            else
                break;
        }
        cout<<"������ѧ�����Ա�(m/f): ";
        cin>>student.gender;
        while(true)
        {
            cout<<"������ѧ�������䣺";
            cin>>student.age;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������������֡�\n";
            }
            else
                break;
        }
        cout<<"������ѧ���ļ��᣺";
        cin>>student.native_place;
        cout<<"������ѧ����רҵ��";
        cin>>student.major;
        while(true)
        {
            cout<<"������ѧ���İ༶��";
            cin>>student.class_num;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������������֡�\n";
            }
            else
                break;
        }    
        while(true)
        {
            cout<<"������ѧ������ѧ�ɼ���";
            cin>>student.math_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������������֡�\n";
            }
            else
                break;
        }
        while(true)
        {
            cout<<"������ѧ���ļ�����ɼ���";
            cin>>student.cs_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������������֡�\n";
            }
            else
                break;
        }
        while(true)
        {
            cout<<"������ѧ����Ӣ��ɼ���";
            cin>>student.eng_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������������֡�\n";
            }
            else
                break;
        }
        while(true)
        {
            cout<<"������ѧ��������ɼ���";
            cin>>student.py_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������������֡�\n";
            }
            else
                break;
        }
        while(true)
        {
            cout<<"������ѧ����˼������뷨�γɼ���";
            cin>>student.df_grade;
            if(cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "����������������֡�\n";
            }
            else
                break;
        }
        cout<<"������ѧ���Ľ��ͼ�¼��";
        cin>>student.record;
        ofstream ofs;
        ofs.open("student.dat",ios::binary|ios::app);
        if(!ofs)
        {
            cout<<"�ļ���ʧ�ܣ�\n";
            num1=-1;
            return 0;
        }   
        else
        {
            fstream ofs;
            ofs.open("student.dat",ios::binary|ios::in|ios::out);
            if(!ofs)
            {
                cout<<"�ļ���ʧ�ܣ�\n";
                num1=-1;
                return 0;
            }
            else
            {
                ofs.seekp((student.student_num-1)*sizeof(CStudent));
                ofs.write((char*)&student,sizeof(CStudent));
                cout<<"ѧ��������ӳɹ���\n";
            }
        }
        ofs.close();
        return 0;
    }
    else
    {
        cout<<"�������\n";
        num1=-1;
        return 0;
    }
    return 0;
}
int search_student(const string& filename)        // ����ѧ������
{
    CStudent student;
    int num1,num2=0;
    cout<<"1:������һ��\n2:����ѧ������\n";
    cin>>num1;
    if(num1==1)
    {
        num1=-1;
        return 0;
    }
    else if(num1==2)
    {
        cout<<"������ѧ���ı�ţ�";
        cin>>num2;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "����������������֡�\n";
        }
        else if(num2<0 || num2> 1000)
        {
            cout<<"������󣡱�ų�����Χ��\n"; 
            num1=-1;
            return 0;
        }   
        else
        {
        
            ifstream ifs;
            ifs.open("student.dat",ios::binary|ios::in);
            if(!ifs)
            {
                cout<<"�ļ���ʧ�ܣ�\n";                    num1=-1;
                return 0;
            }
            else
            {
                ifs.seekg((num2-1)*sizeof(CStudent));
                ifs.read(reinterpret_cast<char*>(&student),sizeof(CStudent));
                if(ifs.eof()||student.student_num!=0)    
                {
                    cerr<<"ѧ�����ݲ����ڣ�\n";
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
        cout<<"�������\n";
        num1=-1;
        return 0;
    }
    return 0;
}
void showmenu(void)        // �˵�
{
    cout<<"******************************************************************************\n";
    cout<<"************______________________________________________________************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|***************��ӭ����ѧ��ѧ������ϵͳ*************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************1������ѧ������*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************2������ѧ������*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************3������ѧ������*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************4��ɾ��ѧ������*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************5��ѧ���ɼ�����*********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************6���˳�ϵͳ*************************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************������������������������������������������������������������������������������������������������������������************\n";
    cout<<"******************************************************************************\n";
    cout<<"******************************************************************************\n";
    return;
}
void grademanage()        // ѧ���ɼ�����
{
    int s_num;
    cout<<"������ѧ����ѧ�ţ�";
    cin>>s_num;
    cout<<"******************************************************************************\n";
    cout<<"************______________________________________________________************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************1���г�ѧ���ĳɼ�********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************2������ѧ��ƽ����********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************3������ѧ�����Ƽ��ܳɼ�����***********|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************4������ѧ��GPA������*****************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************5���г��ܳɼ�����n�ֵ��ض��Ա�ѧ��****|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************|****************6��������һ��***********************|************\n";
    cout<<"************|****************************************************|************\n";
    cout<<"************������������������������������������������������������������������������������������������������������������************\n";
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
        cout<<"����������ѡ��";
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
                    cout<<"�������\n";
                    break;
                }
                break;
            case 6 :
                return 0;
                break;
            default :
                cout<<"�������\n";
                break;
        }
    }
}