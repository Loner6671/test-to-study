#include <iostream>
#include <fstream>
#include <string>
#include <cstring> // 用于处理 C 风格字符串
class CStudent {
public:
    int num;                   // 学生编号
    std::string name;         // 学生姓名
    std::string stu_num;     // 学生学号
    char gender;             // 性别 'M' 或 'F'
    int age;                 // 年龄
    std::string native_place; // 籍贯
    std::string major;       // 专业
    std::string class_num;   // 班级编号
    double math_grade;       // 数学成绩
    double cs_grade;         // 计算机成绩
    double eng_grade;        // 英语成绩
    double py_grade;         // Python成绩
    double df_grade;         // 数据科学成绩
    std::string record;      // 其他记录
};
// 将字符串写入二进制文件的辅助函数
void write_string(std::ofstream& outfile, const std::string& str) {
    size_t length = str.size(); // 获取字符串长度
    outfile.write(reinterpret_cast<const char*>(&length), sizeof(length)); // 写入长度
    outfile.write(str.c_str(), length); // 写入字符串数据
}
// 保存学生数据到文件的函数（使用二进制格式）
void save_data(const CStudent& student) {
    std::ofstream outfile("student.dat", std::ios::binary | std::ios::app); // 以二进制追加模式打开文件
    // 检查文件是否成功打开
    if (!outfile) {
        std::cerr << "打开文件时出错！" << std::endl;
        return;
    }
    // 写入基本数据类型
    outfile.write(reinterpret_cast<const char*>(&student.num), sizeof(student.num));
    write_string(outfile, student.name); // 写入字符串
    write_string(outfile, student.stu_num);
    outfile.write(reinterpret_cast<const char*>(&student.gender), sizeof(student.gender));
    outfile.write(reinterpret_cast<const char*>(&student.age), sizeof(student.age));
    write_string(outfile, student.native_place);
    write_string(outfile, student.major);
    write_string(outfile, student.class_num);
    outfile.write(reinterpret_cast<const char*>(&student.math_grade), sizeof(student.math_grade));
    outfile.write(reinterpret_cast<const char*>(&student.cs_grade), sizeof(student.cs_grade));
    outfile.write(reinterpret_cast<const char*>(&student.eng_grade), sizeof(student.eng_grade));
    outfile.write(reinterpret_cast<const char*>(&student.py_grade), sizeof(student.py_grade));
    outfile.write(reinterpret_cast<const char*>(&student.df_grade), sizeof(student.df_grade));
    write_string(outfile, student.record);
    // 关闭文件
    outfile.close();
}
int main() {
    // 创建并初始化学生对象
    CStudent student = {1, "John Doe", "S12345678", 'M', 20, "New York", "Computer Science", "CS101", 
                        90.5, 85.0, 88.0, 92.0, 87.0, "优秀学生"};
    // 保存学生数据到文件
    save_data(student);
    return 0;
}
void read_data() {
    std::ifstream infile("student.dat", std::ios::binary); // 打开二进制文件
    if (!infile) {
        std::cerr << "打开文件时出错！" << std::endl;
        return;
    }
    // 读取并解析数据
    while (infile.peek() != EOF) { // 检查是否到文件末尾
        CStudent student;
        infile.read(reinterpret_cast<char*>(&student.num), sizeof(student.num));
        size_t length;
        infile.read(reinterpret_cast<char*>(&length), sizeof(length));
        char* buffer = new char[length + 1];
        infile.read(buffer, length);
        buffer[length] = '\0';
        student.name = buffer;
        delete[] buffer;
        // 依次读取其他字段，类似写入时的顺序
        // ...
    }
    infile.close();
}