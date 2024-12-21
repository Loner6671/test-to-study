#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class CStudent {
public:
    int num; // ���
    string name; // ����
    char gender; // �Ա�
    int age; // ����
    int mathScore; // ��ѧ�ɼ�
    int compScore; // ������ɼ�
    int langScore; // ����ɼ�
    // ���캯��
    CStudent() : num(0), name(""), gender('m'), age(0), mathScore(0), compScore(0), langScore(0) {}
    CStudent(int n, const string& nm, char g, int a, int ms, int cs, int ls)
        : num(n), name(nm), gender(g), age(a), mathScore(ms), compScore(cs), langScore(ls) {}
    // ������������
    friend ostream& operator<<(ostream& os, const CStudent& student) {
        os << "���: " << student.num << ", ����: " << student.name << ", �Ա�: " << student.gender
           << ", ����: " << student.age << ", ��ѧ: " << student.mathScore
           << ", �����: " << student.compScore << ", ����: " << student.langScore;
        return os;
    }
};
void addStudent(const string& filename) {
    CStudent student;
    cout << "����ѧ�����: ";
    cin >> student.num;
    cout << "��������: ";
    cin >> student.name;
    cout << "�����Ա� (m/f): ";
    cin >> student.gender;
    cout << "��������: ";
    cin >> student.age;
    cout << "������ѧ�ɼ�: ";
    cin >> student.mathScore;
    cout << "���������ɼ�: ";
    cin >> student.compScore;
    cout << "��������ɼ�: ";
    cin >> student.langScore;
    fstream outFile(filename, ios::binary | ios::in | ios::out);
    if (!outFile) 
    {
        outFile.open(filename, ios::binary | ios::out);
    }
    outFile.seekp((student.num - 1) * sizeof(CStudent));
    outFile.write(reinterpret_cast<char*>(&student), sizeof(CStudent));
    outFile.close();
}
void searchByNumber(const string& filename) {
    int num;
    cout << "����Ҫ��ѯ��ѧ�����: ";
    cin >> num;
    ifstream inFile(filename, ios::binary);
    if (!inFile) 
    {
        cerr << "�ļ�������!" << endl;
        return;
    }
    inFile.seekg((num - 1) * sizeof(CStudent));
    CStudent student;
    inFile.read(reinterpret_cast<char*>(&student), sizeof(CStudent));
    if (inFile.eof() || student.num != num) {
        cerr << "ѧ��������!" << endl;
    } else {
        cout << student << endl;
    }
    inFile.close();
}
void searchByName(const string& filename) {
    string name;
    cout << "����Ҫ��ѯ������: ";
    cin >> name;
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "�ļ�������!" << endl;
        return;
    }
    CStudent student;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(CStudent))) {
        if (student.name == name) {
            cout << student << endl;
            found = true;
        }
    }
    if (!found) {
        cerr << "δ�ҵ�ѧ��!" << endl;
    }
    inFile.close();
}
void calculateScores(const string& filename) {
    int num;
    cout << "����Ҫ�����ֺܷ�ƽ���ֵ�ѧ�����: ";
    cin >> num;
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "�ļ�������!" << endl;
        return;
    }
    inFile.seekg((num - 1) * sizeof(CStudent));
    CStudent student;
    inFile.read(reinterpret_cast<char*>(&student), sizeof(CStudent));
    if (inFile.eof() || student.num != num) {
        cerr << "ѧ��������!" << endl;
    } else {
        int total = student.mathScore + student.compScore + student.langScore;
        double average = total / 3.0;
        cout << "�ܳɼ�: " << total << ", ƽ���ɼ�: " << average << endl;
    }
    inFile.close();
}
void listStudentsByCriteria(const string& filename) {
    int threshold;
    char gender;
    cout << "����ɼ���ֵ: ";
    cin >> threshold;
    cout << "�����Ա� (m/f): ";
    cin >> gender;
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "�ļ�������!" << endl;
        return;
    }
    CStudent student;
    bool found = false;
    while (inFile.read(reinterpret_cast<char*>(&student), sizeof(CStudent))) {
        int total = student.mathScore + student.compScore + student.langScore;
        if (total > threshold && student.gender == gender) {
            cout << student << endl;
            found = true;
        }
    }
    if (!found) {
        cerr << "δ�ҵ�����������ѧ��!" << endl;
    }
    inFile.close();
}
int main() {
    string filename = "students.dat";
    int choice;
    while (true) {
        cout << "\n=== ѧ����Ϣ����ϵͳ ===\n";
        cout << "1. ���ѧ��\n";
        cout << "2. ����Ų�ѯѧ��\n";
        cout << "3. ��������ѯѧ��\n";
        cout << "4. ����ѧ���ܷ���ƽ����\n";
        cout << "5. �г�����������ѧ��\n";
        cout << "0. �˳�\n";
        cout << "ѡ�����: ";
        cin >> choice;
        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                searchByNumber(filename);
                break;
            case 3:
                searchByName(filename);
                break;
            case 4:
                calculateScores(filename);
                break;
            case 5:
                listStudentsByCriteria(filename);
                break;
            case 0:
                return 0;
            default:
                cout << "��Ч��ѡ��!" << endl;
        }
    }
}