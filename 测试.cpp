#include<iostream>
using namespace std;
class Shape{
	public:
		virtual int get_area(){
			return 0;
		};
}; 
class Square:public Shape{
	public:
		Square(int i,int j):x(i),y(j){}
		virtual int get_area(){return x*y;};
	private:
		int x;
		int y;
};
class Triangle:public Shape{
	public:
		Triangle(int i,int j):x(i),y(j){}
		virtual int get_area(){return (x*y)/2;};
	private:
		int x;
		int y;
};

int main(){
	Shape *A=new Square (10,10);
	Shape *B=new Triangle(5,8);
	cout <<"�����ε�����ǣ�"<<A->get_area()<<endl;
	cout <<"�����ε�����ǣ�"<<B->get_area()<<endl;
	return 0;
}
