#include<iostream>
using namespace std;
class student{
	string name;
	int ID,borrow_amount;
	public:
		student(){
			borrow_amount=0;
		}
		void getInput(){
			cout<<"Enter Name :";cin>>name;cout<<endl;
			cout<<"Enter Your Roll No. :";cin>>ID;cout<<endl;
		}
		void show_borrow(){
			cout<<borrow_amount<<endl;
		}
};
int main(){
	student s;//this is version-2 
    s.getInput();
	return 0;
}