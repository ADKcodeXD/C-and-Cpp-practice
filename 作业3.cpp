#include <iostream>
using namespace std;
class juzheng{
	public:
		juzheng(int i,int j){hang=i;lie=j;}
		void putin(){
			for(int i=0;i<hang;i++){
				for(int j=0;j<lie;j++){
					cin>>shuzu[i][j];
				}
			}
		}
//		juzheng operator+(const juzheng&)
        void out(){
        		for(int i=0;i<hang;i++){
				for(int j=0;j<lie;j++){
					cout<<shuzu[i][j]<<"  ";
					if(j==2){
						cout <<endl;
					}
				}
			}
		};
	juzheng operator +(const juzheng&b){
		juzheng c(2,3);
		for(int i=0;i<hang;i++){
				for(int j=0;j<lie;j++){
					c.shuzu[i][j]=this->shuzu[i][j]+b.shuzu[i][j];
				}
			}
			return c; 
	}
	private:
		int hang;
		int lie;
		int shuzu[2][3];
};

int main(){
	juzheng a(2,3),b(2,3),c(2,3);
	cout<<"please type in a:"<<endl;
	a.putin();
	cout<<"plezse type in b"<<endl;
	b.putin();
	c=a+b;
	cout<<"the result is:"<<endl;
	c.out();
	return 0; 
}
