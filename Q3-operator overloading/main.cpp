#include <iostream>

using namespace std;

class Person
{
private:
    int height;
    int weight;
public:
    Person(){}
    Person(int h, int w)
    {
        height = h;
        weight = w;
    }

    void printInfo()
    {
        cout << "H: " << height << " W: " << weight;
    }

    Person operator+ (const Person& p)
    {
        Person person;
        person.height = height + p.height;
        person.weight = weight + p.weight;
        return person;
    }

    Person operator- (Person p)
    {
        Person person;
        person.height = height - p.height;
        person.weight = weight - p.weight;
        return person;
    }

    void operator=(Person p)
    {
        height = p.height;
        weight = p.weight;
    }

    // overloaded pre-incrementing
    Person operator++()
    {
        ++height;
        ++weight;
        return Person(height,weight);
    }

    //overloaded post-incrementing
    Person operator++(int)
    {
        Person p(height, weight);
        height++;
        weight++;
        return p;
    }

    //overloaded pre-decrementing
    Person operator--()
    {
        --height;
        --weight;
        return Person(height,weight);
    }

    Person operator--(int)
    {
        Person p(height,weight);
        height--;
        weight--;
        return p;
    }
};

int main()
{
    Person p1(156,80);
    Person p2(160,50);
    Person p3(130,40);
    Person p4(145, 59);
    Person p5;
    Person p6;
    Person p7;
    Person p8;
    Person p9;

    cout << "Person 1: " << endl;
    p1.printInfo();

    cout << "\nPerson 2: " << endl;
    p2.printInfo();

    cout << "\nPerson 3: " << endl;
    p3.printInfo();

    cout << "\nPerson 4: " << endl;
    p4.printInfo();

    p9 = p1+p2-p3;
    cout << "\n---------------\ncomplex operation: " << endl;
    p9.printInfo();

    p5 = ++p1;
    p6 = p2++;

    cout << "\n----------------\npre-incrementing:\nPerson 1: " << endl;
    p5.printInfo();

    cout << "\n----------------\npost-incrementing\nPerson 2: " << endl;
    p6.printInfo();

    p7 = --p3;
    p8 = p4--;

    cout << "\n----------------\npre-decrementing:\nPerson 3: " << endl;
    p7.printInfo();

    cout << "\n----------------\npost-decrementing\nPerson 4: " << endl;
    p8.printInfo();



    return 0;
}
