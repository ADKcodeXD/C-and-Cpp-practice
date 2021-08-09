#include <iostream>
using namespace std;
class osuability{
public:
osuability(){
cout<<"please type in your aim ,acc ,speed ,flow£¨In sequence£©"<<endl;
cin>>aim>>acc>>speed>>flow;
}
void Calculationyourability(){
ability=aim*0.4+speed*0.6+acc*0.3+flow*0.8;
}
void display(){
if (ability<1000)
cout<<"your ability is "<<ability<<endl<<"you are very good !Please continue refueling."<<endl;
else if(ability>=1000 && ability<=1500)
cout<<"your ability is "<<ability<<endl<<"You are normal! More room for improvement."<<endl;
else if(ability>1500 && ability<=2500)
cout<<"your ability is "<<ability<<endl<<"You're getting started."<<endl;
else if(ability>2500 && ability<=3200)
cout<<"your ability is "<<ability<<endl<<"You're already a very strong player." <<endl;
else if(ability>3200 && ability<=5000)
cout<<"your ability is "<<ability<<endl<<"You are too strong to be described in words." <<endl;
else if(ability>5000 && ability<=8000)
cout<<"your ability is "<<ability<<endl<<"You're already at the top."<<endl;
else if(ability>8000 && ability<=10000)
cout<<"your ability is "<<ability<<endl<<"Oh My God"<<endl;
else if(ability>10000)
cout<<"your ability is "<<ability<<endl<<"Nathan on osu"<<endl;
}
private:
int acc;
int speed;
int aim;
int flow;
float ability;
};
int main(){
osuability a;
a.Calculationyourability();
a.display();
return 0;
}
