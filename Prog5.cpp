#include <iostream>

using namespace std;


class Shape {
public:
    
    const double PI = 3.14;
    const int Max_Movie = 5;
    virtual double calculateArea() const = 0;
    virtual void draw() const = 0;

    virtual ~Shape() {} 
};

// Concrete Class 1: Circle
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}

    double calculateArea() const override {
        return PI * radius * radius;
    }

    void draw() const override {
        cout << "  Drawing a Circle with radius " << radius << endl;
    }
};

// Concrete Class 2: Rectangle
class Rectangle : public Shape {
private:
    double length;
    double width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double calculateArea() const override {
        return length * width;
    }

    void draw() const override {
        cout << "  Drawing a Rectangle with length " << length << " and width " << width << endl;
    }
};

void Que5_demo() {
    cout << "---  Task 5: Abstract Class (Shape) & Polymorphism ---" << endl;

    Shape* shapes[Max_Movie]; 
    int count = 0;
    
    shapes[count++] = new Circle(5.0);
    shapes[count++] = new Rectangle(4.0, 6.0);
    shapes[count++] = new Circle(2.5);


    cout << "Calling functions on Shape pointers:" << endl;
    for (int i = 0; i < count; ++i) {
        shapes[i]->draw();
        cout << "  Area: " << shapes[i]->calculateArea() << endl;
    }


    for (int i = 0; i < count; ++i) {
        delete shapes[i];
    }
    cout << endl;
}

int main() {
    
    Que5_demo(); 
    return 0;

}