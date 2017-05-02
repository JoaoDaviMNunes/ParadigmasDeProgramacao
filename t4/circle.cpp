#include <iostream>
#include <cmath>

const double PI = 3.14159;

class Point{
    private:
        double x;
        double y;

    public:
        Point(){
            x = y = 0.0;
        }

        Point(double x1, double y1){
            x = x1;
            y = y1;
        }

        void move(double dx, double dy){
            x += dx;
            y += dy;
        }

        double distanceTo(Point* p2){
            auto hip = pow((p2->x - x), 2.0) + pow((p2->y - y), 2.0);
            return sqrt(hip);
        }

};

class Circle {
    private:
        Point p;
        double r;

    public:
        Circle() {
            p = Point(0.0,0.0);
            r = 0.0;
        }

        Circle(double x1, double y1, double raio){
            p = Point(x1, y1);
            r = raio;
        }

        double area() {
            return PI * r * r;
        }

        void setRadius(double radius){
            r = radius;
        }

        Point ret_Point(){
            return p;
        }

        double ret_raio(){
            return r;
        }

        void distanceTo(Circle* c2){
            Point p2 = c2->ret_Point();
            double dist = p.distanceTo(&p2) - (r + c2->ret_raio());
            std::cout << "A distancia do circulo c ate o circulo c2 eh de " << dist << std::endl;
        }

};

int main() {
    Circle* c = new Circle (0, 0, 0);
    Circle* c2 = new Circle(10, 10, 1);

    c->distanceTo(c2);

    delete (c);
    delete (c2);
}

