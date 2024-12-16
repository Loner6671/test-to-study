#include<iostream>                            
#include<string>           // GBK���� 
#include<fstream>
#include<cstring>
#include<limits>
using namespace std;
void showmenu(void) ;        // �˵�
void len_string(ofstream& outfile, const string& st);       // д���ַ�������
#define max_stu 1000        // �������ѧ����
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
int CStudent::add_student(void)        // ����ѧ������
{
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
        for(int i=0;i<max_stu;i++)
        {
            student_num[i];
        }
        cout<<"������ѧ����������";
        cin>>name;
        while(true)
        {
            cout<<"������ѧ����ѧ�ţ�";
            cin>>stu_num;
            if (cin.fail())             // ��������Ƿ�ʧ��
            {  
                cin.clear();        // ��������־
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ���Դ�������
                cout << "����������������֡�\n";
            } 
            else
                break;
        }
        cout<<"������ѧ�����Ա�";
        cin>>gender;
        while(true)
        {
            cout<<"������ѧ�������䣺";
            cin>>age;
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
        cin>>native_place;
        cout<<"������ѧ����רҵ��";
        cin>>major;
        while(true)
        {
            cout<<"������ѧ���İ༶��";
            cin>>class_num;
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
            cin>>math_grade;
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
            cin>>cs_grade;
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
            cin>>eng_grade;
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
            cin>>py_grade;
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
            cin>>df_grade;
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
        cin>>record;
        cout<<"ѧ��������ӳɹ���\n";
        CStudent student;
        ofstream ofs;
        ofs.open("student.txt",ios::binary|ios::app);
        if(!ofs)
        {
            cout<<"�ļ���ʧ�ܣ�\n";
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
        cout<<"�������\n";
        num1=-1;
        return 0;
    }
    return 0;
}
void len_string(ofstream& outfile, const string& st)        // д���ַ�������
{
    size_t length = st.size();          // ��ȡ�ַ�������
    outfile.write(reinterpret_cast<const char*>(&length), sizeof(length));          //ת��ָ�����Ͳ�д���ַ������� 
    outfile.write(st.c_str(), length);              // д���ַ�������
}
void read_string(ifstream& infile, string& st)        // ��ȡ�ַ���
{
    size_t length = st.size();
    infile.read(reinterpret_cast<char*>(&length), sizeof(length));
    char* buffer = new char[length];
    infile.read(buffer, length);
    st.assign(buffer, length);
    delete[] buffer;
}
int CStudent::search_student(void)        // ����ѧ������
{
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
        else if(num2<0 || num2>max_stu)
        {
            cout<<"������󣡱�ų�����Χ��\n"; 
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
                    cout<<"�ļ���ʧ�ܣ�\n";
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