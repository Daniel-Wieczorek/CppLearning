#include <iostream>
#include <vector>

class Shape
{
private:
    // atributes
public:
    virtual void draw() = 0;   // pure virtual function
    virtual void rotate() = 0; // pure virtual function
    virtual ~Shape() { }

};

class OpenShape :public Shape
{
public:
    virtual ~OpenShape() { }

};

class Line : public Shape
{
public:
    virtual void draw() override
    {
        std::cout<<"Method draw called from class Line\n";
    }

    virtual void rotate() override
    {
        std::cout<<"Method rotate called from class Line\n";
    }

    virtual ~Line() { }
};

class Circle : public Shape
{
public:
    virtual void draw() override
    {
        std::cout<<"Method draw called from class Circle\n";
    }

    virtual void rotate() override
    {
        std::cout<<"Method rotate called from class Circle\n";
    }

    virtual ~Circle() { }
};

int main()
{
    // Shape shapeObj; --> it will produce an error. Object of abstract class is not allowed!

    Shape *objLine = new Line();
    Shape *objCircle = new Circle();
    
    std::vector<Shape*> shapesVec {objLine, objCircle};

    for(const auto &object:shapesVec)
    {
        object->draw();
    }
    
    delete objLine;
    delete objCircle;


}