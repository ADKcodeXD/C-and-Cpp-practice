#include <iostream>
#include <cstring>
using namespace std;
class A{
	public:
	A(char *b){cout<<"A()"<<endl;
	name=new char[strlen(b)+1];
	strcpy(name,b);}
	A(const A &a){cout << "A(a)"<<endl;
	name=new char[strlen(a.name)+1];
	strcpy(name,a.name);
	}
	~A(){delete []name;
    cout<<"~A()"<<endl;}
	void print(){
		cout<<"name= "<<name<<endl;
	}
	void printp(){
		printf("name=%p\n",name);
	}
	private:
		char *name;
};
int main(){
	char h[]="nihao";
	char j[]="xiexie";
	A a(h);
	A b(j);
	a.print();
	b.print();
	a.printp();
	b.printp();
	A c=b;
	a.print();
	b.print();
	c.print();
	a.printp();
	b.printp();
	c.printp();
	return 0;
}
