#include <stdio.h>
#include <math.h>
#define PI 3.14

typedef struct {

    float radius;
}Circle;

typedef struct {

    float width;
    float height;

}Rectangle;

typedef struct {

    float side1;
    float side2;
    float side3;

}Triangle;

union VehicleData{

    struct{
        int door;
        int seat;
    }car;

    struct{
        int wheels;
        int power;
    }motorcycle;

    struct{
        int wheels;
    }bicycle;
};

typedef struct{
    int type;
    union VehicleData data;

}Vehicle;

void calculate_area(Rectangle rectangle, Triangle triangle, Circle circle, double areas[3]){

    printf("Area of rectangle is: ");
    float area;
    area = rectangle.width * rectangle.height;
    areas[0] = area;
    printf("%.2f\n",areas[0]);
    printf("Area of Triangle is: ");
    float s;
    s = (triangle.side1 + triangle.side2 + triangle.side3) / 2.0;
    area = sqrt(s * (s - triangle.side1) * (s - triangle.side2) * (s - triangle.side3));
    areas[1] = area;
    printf("%.2f\n",areas[1]);
    area = circle.radius * circle.radius * PI;
    areas[2] = area;
    printf("Area of Circle is: ");
    printf("%.2f\n",areas[2]);

}

int calculate_maxspeed(Vehicle v){

    int maxspeed;

    switch(v.type){

        case 1:
            maxspeed = v.data.car.door * 20;
        break;
        case 2:
            maxspeed  = v.data.motorcycle.power / 2;
        break;
        case 3:
            maxspeed = 30;
        break;
        default:
        printf("ERROR");
    }
    return maxspeed;
}

void modify_car_doors(Vehicle* car, int num){
    
    car->data.car.door = num;
}

int main(){

    Triangle a;
    Rectangle b;
    Circle c;
    a.side1 = 3;
    a.side2 = 4;
    a.side3 = 5;
    b.height = 3;
    b.width = 5;
    c.radius = 2;
    double arr[3];
    calculate_area(b,a,c,arr);
    printf("\n===== PART2 ======\n\n\n");
    Vehicle veh;
    int temp;
    veh.type = 1;
    veh.data.car.door = 4;
    veh.data.car.seat = 5;
    temp = calculate_maxspeed(veh);
    printf("Maximum Speed of Car: %d\n",temp);
    veh.type = 2;
    veh.data.motorcycle.wheels = 2;
    veh.data.motorcycle.power = 250;
    temp = calculate_maxspeed(veh);
    printf("Maximum Speed of Motorcycle: %d\n",temp);
    veh.type = 3;
    veh.data.bicycle.wheels = 2;
    temp = calculate_maxspeed(veh);
    printf("Maximum Speed of Bicycle: %d\n",temp);
    veh.type = 1;
    Vehicle* ptr;
    *ptr = veh;
    modify_car_doors(ptr,2);
    temp = calculate_maxspeed(veh);
    printf("Maximum Speed of Car: %d\n",temp);
    return 0;
}