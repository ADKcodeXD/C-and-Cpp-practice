#include <iostream>
#include<windows.h> 
using namespace std;
class time{
	public:
		void timedisplay()
		{
			cout<<"hour:  "<<hour<<"  mins:  "<<min<<endl;
		}
//		bool timebool(){
//			if (min>60){
//				return 1;
//			}
//			return 0;
//		}
		void minplus(){
			Sleep(100);
			min++;
		}
		void hourplus(){
			if(min>60){
				hour++;
				min=0;
			} else if(hour>24){
				hour=0;
			}
		}
	private :
		int hour;
		int min;
};
int main(){
	time q;
	while(1){
		q.timedisplay();
		q.minplus();
		q.hourplus();
//		q.timebool();
		system("cls");
			}
	return 0;
}
