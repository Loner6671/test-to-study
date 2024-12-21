#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class CStudent {
public:
    int num; // 编号
    string name; // 姓名
    char gender; // 性别
    int age; // 年龄
    int mathScore; // 数学成绩
    int compScore; // 计算机成绩
    int langScore; // 外语成绩
    // 构造函数
    CStudent() : num(0), name(""), gender('m'), age(0), mathScore(0), compScore(0), langScore(0) {}
    CStudent(int n, const string& nm, char g, int a, int ms, int cs, int ls)
        : num(n), name(nm), gender(g), age(a), mathScore(ms), compScore(cs), langScore(ls) {}
    // 重载输出运算符
    friend ostream& operator<<(ostream& os, const CStudent& student) {
        os << "编号: " << student.num << ", 姓名: " << student.name << ", 性别: " << student.gender
           << ", 年龄: " << student.age << ", 数学: " << student.mathScore
           << ", 计算机: " << student.compScore << ", 外语: " << student.langScore;
        return os;
    }
};
void addStudent(const string& filename) {
    CStudent student;
    cout << "输入学生编号: ";
    cin >> student.num;
    cout << "输入姓名: ";
    cin >> student.name;
    cout << "输入性别 (m/f): ";
    cin >> student.gender;
    cout << "输入年龄: ";
    cin >> student.age;
    cout << "输入数学成绩: ";
    cin >> student.mathScore;
    cout << "输入计算机成绩: ";
    cin >> student.compScore;
    cout << "输入外语成绩: ";
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
    cout << "输入要查询的学生编号: ";
    cin >> num;
    ifstream inFile(filename, ios::binary);
    if (!inFile) 
    {
        cerr << "文件不存在!" << endl;
        return;
    }
    inFile.seekg((num - 1) * sizeof(CStudent));
    CStudent student;
    inFile.read(reinterpret_cast<char*>(&student), sizeof(CStudent));
    if (inFile.eof() || student.num != num) {
        cerr << "学生不存在!" << endl;
    } else {
        cout << student << endl;
    }
    inFile.close();
}
void searchByName(const string& filename) {
    string name;
    cout << "输入要查询的姓名: ";
    cin >> name;
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "文件不存在!" << endl;
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
        cerr << "未找到学生!" << endl;
    }
    inFile.close();
}
void calculateScores(const string& filename) {
    int num;
    cout << "输入要计算总分和平均分的学生编号: ";
    cin >> num;
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "文件不存在!" << endl;
        return;
    }
    inFile.seekg((num - 1) * sizeof(CStudent));
    CStudent student;
    inFile.read(reinterpret_cast<char*>(&student), sizeof(CStudent));
    if (inFile.eof() || student.num != num) {
        cerr << "学生不存在!" << endl;
    } else {
        int total = student.mathScore + student.compScore + student.langScore;
        double average = total / 3.0;
        cout << "总成绩: " << total << ", 平均成绩: " << average << endl;
    }
    inFile.close();
}
void listStudentsByCriteria(const string& filename) {
    int threshold;
    char gender;
    cout << "输入成绩阈值: ";
    cin >> threshold;
    cout << "输入性别 (m/f): ";
    cin >> gender;
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "文件不存在!" << endl;
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
        cerr << "未找到符合条件的学生!" << endl;
    }
    inFile.close();
}
int main() {
    string filename = "students.dat";
    int choice;
    while (true) {
        cout << "\n=== 学生信息管理系统 ===\n";
        cout << "1. 添加学生\n";
        cout << "2. 按编号查询学生\n";
        cout << "3. 按姓名查询学生\n";
        cout << "4. 计算学生总分与平均分\n";
        cout << "5. 列出符合条件的学生\n";
        cout << "0. 退出\n";
        cout << "选择操作: ";
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
                cout << "无效的选择!" << endl;
        }
    }
}