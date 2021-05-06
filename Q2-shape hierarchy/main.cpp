#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Shape
{
private:
    vector <Shape*> listOfShape;
public:
    Shape(){}
    virtual void draw(){}
    virtual double area(){}
    virtual void print(){}

    void addShape(Shape* shape) {
		listOfShape.push_back(shape);
	}

    int countShape()
    {
        int count = 0;
        for(int i =0; i<listOfShape.size(); i++)
        {
            count++;
        }
        return count;
    }
};

class Circle : public Shape
{
private:
    double radius;
public:
    Circle(){}
    Circle(double radius)
    {
        this->radius = radius;
    }

    void draw()
    {
        cout << "Draw a circle" << endl;
    }

    double area()
    {
        return radius*radius*3.14;
    }

    void print()
    {
        cout << "Area of the circle: " << area() << endl;
    }
};

class Square : public Shape
{
private:
    double side;
public:
    Square(){}
    Square(double side)
    {
        this->side = side;
    }

    void draw()
    {
        cout << "Draw a square" << endl;
    }

    double area()
    {
        return side*side;
    }

    void print()
    {
        cout << "Area of the square: " << area() << endl;
    }
};

class Triangle : public Shape
{
private:
    double side;
public:
    Triangle(){}
    Triangle(double side)
    {
        this->side = side;
    }

    void draw()
    {
        cout << "Draw a triangle" << endl;
    }

    double area()
    {
        return side*side*sqrt(3)/4;
    }

    void print()
    {
        cout << "Area of the triangle: " << area() << endl;
    }
};

int main()
{
    Shape s;
    Shape* circle = new Circle(3.0);
    circle->draw();
    Shape* square = new Square(5.0);
    square->draw();
    Shape* triangle = new Triangle(9.0);
    triangle->draw();

    s.addShape(circle);
    s.addShape(triangle);
    s.addShape(square);
    int n = s.countShape();
    cout << "Number of shapes: " << n << endl;

    double A1 = circle->area(), A2 = square->area(), A3 = triangle->area();



    circle->print();
    square->print();
    triangle->print();

    double arr[n] = {A1,A2,A3};

    for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]<arr[j])
			{
				double temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	//print sorted array elements
	cout << "Print area in decreasing order: " << endl;
	for(int i=0;i<n;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;

}
