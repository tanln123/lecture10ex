#include <iostream>

using namespace std;

class Complex
{
private:
    double real;
    double imaginary;
public:
    Complex(){}
    Complex(double r, double i)
    {
        real = r;
        imaginary = i;
    }

    void displayInfo()
    {
        cout << "Real part: " << real << " Imaginary part: " << imaginary << endl;
    }

    //overloaded comparison operator (>)
    bool operator>(const Complex& c)
    {
        if (real > c.real)
            return true;
        if (real == c.real && imaginary > c.imaginary)
            return true;
        return false;
    }

    //overloaded assignment operator
    void operator=(const Complex& c)
    {
        real = c.real;
        imaginary = c.imaginary;
    }

    //overloaded addition operator
    Complex operator+(const Complex& c)
    {
        Complex complex;
        complex.real = real+ c.real;
        complex.imaginary = imaginary + c.imaginary;
        return complex;
    }

    //overloaded subtraction operator
    Complex operator-(const Complex& c)
    {
        Complex complex;
        complex.real = real - c.real;
        complex.imaginary = imaginary - c.imaginary;
        return complex;
    }
};


int main()
{
    Complex C1(3.5, 4.0);
    cout << "C1: ";
    C1.displayInfo();
    Complex C2(2.4, 3.8);
    cout << "C2: ";
    C2.displayInfo();

    if (C1>C2)
        cout << "C1 is larger than C2" << endl;
    else
        cout << "C1 is not larger than C2" << endl;

    Complex C3;
    C3 = C1+C2;
    cout << "------------------\nSum of C1 and C2: ";
    C3.displayInfo();

    if (C1>C2)
        C3 = C1 - C2;
    else
        C3 = C2 - C1;
    cout << "------------------\nSubtraction of C1 and C2: ";
    C3.displayInfo();

    C1 = C2;
    cout << "------------------\nC1 after assigned C2: " << endl;
    C1.displayInfo();


    return 0;
}
