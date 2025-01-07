#include <iostream>
using namespace std;

class shape
{
public:
    virtual void draw()
    {
        cout << "Drawing shape" << endl;
    }

    virtual void area() = 0;
};

class circle : public shape
{
public:
    void draw() override
    {
        cout << "Drawing circle" << endl;
    }

    void area() override
    {
        cout << "Area of circle" << endl;
    }
};

int main()
{
    shape *shape = new circle();
    shape->draw();
    shape->area();

    return 0;
}