#include <iostream>
using namespace std;
class BASE {

public:  void show( ) { cout<<"BASE\n";}

};

class FIRST_D:public BASE {

public: void show ( ) { cout<<"First Derivation\n";}

};

class SECOND_D:public BASE {

public: void show ( ) { cout<<"Second Derivation\n";}

};

int main( )

{ BASE b_obj; FIRST_D f_obj; SECOND_D s_obj;

BASE *p;                   

p= &b_obj; p-> show ();

p= &f_obj; p-> show ();    

p= &s_obj; p-> show ();    

return 0;
}
