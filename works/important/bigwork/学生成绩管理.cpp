#include<iostream>                            
#include<string>           // GBK���� 
#include<fstream>
#include<cstring>
using namespace std; 
void showmenu(void) ;        // �˵�
#define max 1000        // �������ѧ����
class CStudent
{
public:
void save_data(const CStudent& student);
int addstudent(void);
int student_num[max];
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
int CStudent::addstudent(void)        // ����ѧ������
{
    cout<<"1:������һ��\n2:����ѧ������\n";
    int num1 ;
    cin>>num1;
    if(num1==1)
    {
        return 0;
    }
    else if(num1==2)
    {
    for(int i=0;i<max;i++)
    {
        student_num[i];
    }
    cout<<"������ѧ����������";
    cin>>name;
    cout<<"������ѧ����ѧ�ţ�";
    cin>>stu_num;
    cout<<"������ѧ�����Ա�";
    cin>>gender;
    cout<<"������ѧ�������䣺";
    cin>>age;
    cout<<"������ѧ���ļ��᣺";
    cin>>native_place;
    cout<<"������ѧ����רҵ��";
    cin>>major;
    cout<<"������ѧ���İ༶��";
    cin>>class_num;     
    cout<<"������ѧ������ѧ�ɼ���";
    cin>>math_grade;
    cout<<"������ѧ���ļ�����ɼ���";
    cin>>cs_grade;
    cout<<"������ѧ����Ӣ��ɼ���";
    cin>>eng_grade;
    cout<<"������ѧ��������ɼ���";
    cin>>py_grade;     
    cout<<"������ѧ����˼������뷨�γɼ���";
    cin>>df_grade;
    cout<<"������ѧ���Ľ��ͼ�¼��";
    cin>>record;
    cout<<"ѧ��������ӳɹ���\n";
    save_data(*this);
    }
    else
    {
        cout<<"�������\n";
        return 0;
    }
    return 0;
}
void len_string(ofstream& outfile, const string& st)        // д���ַ�������
{
    size_t length = st.size(); // ��ȡ�ַ�������
    outfile.write(reinterpret_cast<const char*>(&length), sizeof(length)); // д�볤��
    outfile.write(st.c_str(), length); // д���ַ�������
}
void save_data(const CStudent& student)         // ����ѧ������ 
{
    CStudent student;
    ofstream ofs;
    ofs.open("student.dat",ios::binary|ios::app);
    if(!ofs)
    {
        cout<<"�ļ���ʧ�ܣ�\n";
        return;
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
    return;
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
        case 1 :
            a.addstudent();
            break;
        case 2 :

            break;
        case 3 :

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