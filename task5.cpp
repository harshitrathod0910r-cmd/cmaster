#include <iostream>
using namespace std;

class Shape {
public:
   
    virtual float calculateArea() = 0;
    virtual void draw() = 0;
};


class Circle : public Shape {
    float radius;
public:
    Circle(float r) {
        radius = r;
    }

    float calculateArea() {
        return 3.14 * radius * radius;   
    }

    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    float calculateArea() {
        return length * width;   
    }

    void draw() {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {

    Shape* s[2];   

    s[0] = new Circle(5);      
    s[1] = new Rectangle(4,6); 
    for (int i = 0; i < 2; i++) {
        s[i]->draw();                             
        cout << "Area = " << s[i]->calculateArea() << endl;  
    }

    return 0;
}