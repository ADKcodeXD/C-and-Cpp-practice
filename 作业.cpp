#include <iostream>
using namespace std;
class box{
	public:
		box(int a,float b){
			quantity=a;
			price=b;
		}
	void total(){
		if(quantity>10){
		sum+=quantity*price*discount*discount2;}
		else
		sum+=quantity*price*discount;
		n+=quantity;
		
	}
	static float average(){
		return sum/n; 
	}
	static void display(){
		cout<<"today total quantity is "<<n<<endl;
		cout<<"today average is "<<average()<<endl;
	}
	private:
		int quantity;
		float price;
		static float sum;
		static int n;
		static float discount;
		static float discount2;
};
float box::discount=0.8;
float box::discount2=0.98;
int box::n=0;
float box::sum=0.8;
int main(){
	box A[3]={
		box(5,23.5),
		box(12,24.56),
		box(100,21.5)
	};
	int n=3;
	for (int i=0;i<n;i++){
		A[i].total();
	}
	box::display();
	return 0;
}
