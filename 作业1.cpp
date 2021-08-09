#include<iostream>

using namespace std;

class T

{ public:

  T(int x){

a = x;  

b += x; 

};

  static void display (T c){

         cout<<"a="<<c.a<<'\t'<<"b="<<c.b<<endl;

}

  private:

     int a;

     static  int  b;

} ;

int T::b=5;

int main()

{ T A(3), B(5);

  T::display(A);

  T::display(B);
return 0;
}
