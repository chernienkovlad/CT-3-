#include <iostream>
#include <string>

using namespace std;

class animal
{
    public:
        int getAge() { return age; }
        string getName() { return name; }
        void setAge(int newAge)
        {
            if (newAge > 50)
            age = newAge;
        }
        animal(int age_, string name_)
        {
            age = age_;
            name = name_;
            cout << "'" << name << "'" << " was born!" << endl;
        }
        animal()
        {
            age = 4;
            name = "nan";
        }
        void makesound() { cout << "meow" << endl; }
        // -animal()
        // {
        //     cout << "I am dead" << endl;
        // }

    private:
        int age = 3;
        string name = "name";
};

int main()
{
    animal A(2, "A");
    A.makesound();

    cout << A.getName() << " – " << A.getAge() << endl;

    return 0;
}
