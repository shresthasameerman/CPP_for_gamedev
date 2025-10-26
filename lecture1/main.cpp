#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Student {

    private:
        std::string m_first ="first";
        std::string m_last = "last";
        int m_id= 0;
        float m_gpa = 0.0f;
    public:
        Student() {}
        Student(std::string first,std::string last,int id, float gpa)
            : m_first(first), m_last(last), m_id(id), m_gpa(gpa) {}

        float getavg() const
        {
            return m_gpa;
        }
        int getid() const
        {
            return m_id;
        }
        std::string getname() const
        {
            return m_first + " " + m_last;
        }

        void print() const
        {
            std::cout << "Name: " << m_first << " " << m_last << "\n";
            std::cout << "ID: " << m_id << "\n";
            std::cout << "GPA: " << m_gpa << "\n";
        }

};

class Course
{
    std::string m_name = "Course";
    std::vector<Student> m_students;
public:
    Course() {}
    Course(const std::string& name) : m_name(name) {}

    void addStudent(const Student& student)
    {
        m_students.push_back(student);
    }

    const std::vector<Student>& getStudents() const
    {
        return m_students;
    }

    void loadfromfile(const std::string& filename)
    {
        std::ifstream file(filename);
        if (!file) return;

        std::string first, last;
        int id;
        float gpa;
        while (file >> first >> last >> id >> gpa)
        {
            addStudent(Student(first, last, id, gpa));
        }
    }

    void print() const
    {
        for (const auto& student : m_students)
        {
            student.print();
        }
    }
};

int main(int argc, char* argv[])
{
   Course C("Computer Science 101");
    C.loadfromfile("students.txt");
    C.print();

    return 0;
}