#include<iostream>
using namespace std;
class cube{
	public:
		int c,k,g;
		void input(float c1,float k1,float g1);
		float tiji();
};
void cube::input(float c1,float k1,float g1){
	c=c1;
	k=k1;
	g=g1;
}
float cube::tiji(){
	return c*k*g;
}
int main(){
	float c,k,g;
	cube a;
	cout<<"请输入长宽高（用空格隔开）"<<endl;
	cin>>c>>k>>g;
	a.input(c,k,g);
	cout<<"你要求的长方体体积为:"<<a.tiji()<<endl;
	return 0; 
}
