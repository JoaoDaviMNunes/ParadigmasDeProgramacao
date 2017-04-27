#include <iostream>
#include <cmath>

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

        void distanceTo(Point* p, Point* p2){
            auto hip = pow((p->x - p2->x), 2.0) + pow((p->y - p2->y), 2.0);
            std::cout << "A distancia entre (" << p->x << ","<< p->y << ") e (" << p2->x << ","<< p2->y << ") eh de " << sqrt(hip) << std::endl;
        }

};

int main(){
    Point p;
    Point* p2[5];

    for(auto i=0; i<5; i++){
        p2[i] = new Point(i*5, i*2);
    }

    for(auto i=0; i<5; i++){
        p.distanceTo(&p, p2[i]);
    }

    for(auto i=0; i<5; i++){
        delete(p2[i]);
    }

    return 0;
}
