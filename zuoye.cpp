#include<iostream>
#define PI 3.14
using namespace std;
class Firgure {
public:
	virtual float get_area()=0;
protected:
	int x_size;
	int y_size;
};
class Triangle: public Firgure{
public:
	Triangle(int i,int j){
	x_size=i;
	y_size=j;
	}
	virtual float get_area(){
	return ((x_size*y_size)/2);
	}
};
class Rectangle: public Firgure{
public:
	Rectangle(int i,int j){
	x_size=i;
	y_size=j;
	}
	virtual float get_area(){
	return (x_size*y_size);
	}
};
class Circle: public Firgure{
public:
	Circle(int i){
	x_size=i;
	}
	virtual float get_area(){
	return (PI*x_size*x_size);
	}
};
int main(){
	Firgure *a=new Triangle(3,6);
	Firgure *b=new Rectangle(5,8);
	Firgure *c=new Circle(2);
	cout<<a->get_area()<<endl;
	cout<<b->get_area()<<endl;
	cout<<c->get_area()<<endl;
}

