#include <iostream>

class Shape {
public:
    virtual double area() const = 0; // 纯虚函数
};

class Rect : public Shape {
public:
    Rect(double width, double height) : width_(width), height_(height) {}
    double area() const{
        return width_ * height_;
    }
private:
    double width_;
    double height_;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius_(radius) {}
    double area() const{
        return 3.14 * radius_ * radius_;
    }
private:
    double radius_;
};

void foo(Shape *s) {
    std::cout << "Area: " << s->area() << std::endl;
}

int main() {
    foo(new Rect(100, 200));
    foo(new Circle(10));
    return 0;
}
