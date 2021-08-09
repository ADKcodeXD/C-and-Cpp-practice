#include <iostream>
using namespace std;
class person{
	public:
		void input();
		void display();
	private:
		char name[10];
		int no;
};
class student: public person{
	public:
		void Inaddressandresult();
		void studisplay();
	private:
		char address[10];
		int result;
};
class teacher: public person{
	public:
		void Inwageanddepartment();
		void teadisplay();
	private:
		int wage;
		char department[10];
};
void person::input(){
	cout<<"please type in name"<<endl;
	cin>>name;
	cout<<"please type in number"<<endl;
	cin>>no;
}
void person::display(){
	cout<<"name:"<<name<<endl<<"number:"<<no<<endl;
}
void student::Inaddressandresult() {
	cout<<"please type in address"<<endl;
	cin>>address;
	cout<<"please type in result"<<endl;
	cin>>result;
}
void student::studisplay() {
	cout<<"address:"<<address<<endl<<"result:"<<result<<endl<<endl;
}
void teacher::Inwageanddepartment(){
	cout<<"please type in wage"<<endl;
	cin>>wage;
	cout<<"please type in department"<<endl;
	cin>>department;
}
void teacher::teadisplay(){
    cout<<"wage:"<<wage<<endl<<"department:"<<department<<endl<<endl;
}
int main(){
	const int q=2;
	student a[q];
	teacher b[q];
	for(int i=1;i<=q;i++){
	cout<<"no."<<i<< " student"<<endl;
	a[i-1].input();
	a[i-1].Inaddressandresult();
	}
	for(int i=1;i<=q;i++){
	cout<<"no."<<i<< " teacher"<<endl;
	b[i-1].input();
	b[i-1].Inwageanddepartment();
	}
	for(int i=1;i<=q;i++){
		cout<<"no."<<i<<" student"<<endl;
		a[i-1].display();
		a[i-1].studisplay();
	}
	for(int i=1;i<=q;i++){
		cout<<"no."<<i<<" teacher"<<endl;
		b[i-1].display();
		b[i-1].teadisplay();
	}
	return 0;
}

