#include<iostream>
using namespace std;
class A{
	public:
		A():i(5),b(10){cout<<"A::()"<<endl;}
		~A(){cout<<"~A::()"<<endl;}
		void set(int ii){i=ii,b=(ii/2);}
	    void print(){
			cout<<"i= "<<i<<endl<<"b= "<<b<<endl;
		}
	private:
		int i;
		int b;
};
class B: public  A{
};
int main(){
	B a;
	a.print();
	a.set(20);
	a.print();
	return 0;
}
