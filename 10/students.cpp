#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

class student
{
    public:
        string getName() { return name; }
        int getAge() { return age; }
        int getAv_mark() { return av_mark; }
        void setName(string newName) { name = newName; }
        void setAge(int newAge) { if (newAge <= 50) age = newAge; }
        void setAv_mark(double newAv_mark) 
        { 
            if (newAv_mark >= 2) 
                av_mark = newAv_mark;
            else 
                cout << "Pathetic." << endl;
        }
        void botat()
        {
            cout << name << " ботает матан." << endl;
            av_mark++;
        }

        student()
        {
            name = "Vova";
            age = 18;
            av_mark = 4;

            cout << "Студент " << name << " родился." << endl;
        }
        student(string name_, int age_, double av_mark_)
        {
            name = name_;
            age = age_;
            av_mark = av_mark_;

            cout << "Студент " << name << " родился." << endl;
        }
        ~student()
        {
            cout << "Студент " << name << " сдох." << endl;
        }
    private:
        string name;
        int age;
        double av_mark;
};

double get_av_mark(vector<student*>& students);

int main()
{
    student A("John", 20, 3.5);
    student B("Johnny", 35, 4.99);
    student C("Billy", 19, 5);
    student D("Bob", 25, 2.01);
    student E;

    vector<student*> students;

    students.push_back(&A);
    students.push_back(&B);
    students.push_back(&C);
    students.push_back(&D);
    students.push_back(&E);

    srand(time(0));
    int random = 0;

    for (auto student : students)
    {
        random = rand() % 3;
        for (int i = 0; i < random; i++)
            student->botat();
    }
    
    cout << "Средняя оценка за семестр: " << get_av_mark(students) << endl;

    return 0;
}

double get_av_mark(vector<student*>& students)
{
    double av = 0;
    for (auto student : students)
        av += student->getAv_mark();
    
    av /= students.size();

    return av;
}
