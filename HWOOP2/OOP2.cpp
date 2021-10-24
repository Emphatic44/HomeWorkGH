#include <iostream>

using namespace std;

enum Gender
{
    MALE,
    FEMALE
};

class Person
{
private:
    string m_name;
    int m_age;
    Gender m_gender;
    int m_weight;
public:
    Person(string name, int age, Gender gender, int weight) :
        m_name(name), m_age(age), m_gender(gender), m_weight(weight) {}

    void setName(string name = "")
    {
       m_name = name;
    }

    void setAge(int age = 0)
    {
            m_age = age;
    }

    void setWeight(int weight = 0)
    {
            m_weight = weight;
    }

    void printInfo() const
    {
        cout << "Name: " << m_name << endl
            << "Age: " << m_age << endl
            << "Sex: " << (m_gender == MALE ? "male" : "female") << endl
            << "Weight: " << m_weight << endl;
    }
};


class Student : public Person
{
protected:
    static int count;
    int m_course;

public:
    Student(string name, int age, Gender gender, int weight, int course) :
        Person(name, age, gender, weight), m_course(course)
    {
        count++;
    }

    static void PrintCount()
    {
        cout << "Number of Students: " << count << endl;
    }

    void setYearStudy(int course = 0)
    {
        m_course = course;
    }

    void RiseCourse()
    {
        m_course++;
    }

    void printInfo() const
    {
        Person::printInfo();
        cout << "Your Course: " << m_course << endl;
    }

    ~Student()
    {
        count--;
    }

};
int Student::count = 0;

int main()
{
    //Task1
    Student Andrey("Andrey", 26, MALE, 90, 4);
    Andrey.printInfo();
    Student Oleg("Oleg", 22, MALE, 74, 2);
    Oleg.printInfo();
    Student Anastasia("Anastatisa", 24, FEMALE, 57, 3);
    Anastasia.printInfo();
    Student::PrintCount();

    return 0;

}


/*Task3

1) Поле (участники,карты на поле или у участников, стадия игры).
2) Колода карт( масти и номиналы карт)
3) Ход игры (начало игры, раздача, пасс/сет, конец игры).

Для удобства, некоторые значения можно добавить в виде перечислений или массивов. */