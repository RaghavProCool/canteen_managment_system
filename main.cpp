#include<iostream>
#include<map>
using namespace std;
map<int,float> roll_borrow; //Map that contain borrow as value and roll no as key
class student{
	int ID;
	float borrow_amount;
	public:
		student(){
			borrow_amount=0;
		}
		void newAccount(){
			cout<<"Enter Your Roll No. :";cin>>ID;cout<<endl;
			if(newUser(ID)){
				roll_borrow.insert(pair<int,int> (ID,borrow_amount));
				logedIn(ID);
			}else{
				cout<<"This ID is already registed!"<<endl;
			}
		}
		void show_borrow(){
			cout<<borrow_amount<<endl;
		}
		bool newUser(int key){
			if (roll_borrow.find(key) == roll_borrow.end()) 
                return true; 
  
              return false; 
		}
		void checkUser(){
             cout<<"Enter you ID"<<endl;
			 int tempID;
			 cin>>tempID;
			 if(newUser(tempID)){
				cout<<"No account exist with this ID"<<endl;
			}else{
				logedIn(tempID);
			}

		}
		void logedIn(int ID){
			cout<<"Welcome "<<ID<<endl;
		}
};
int main(){
	student s;
	int count=0;
    cout<<"Already have an account ? y/n";
	char ans;
	cin>>ans;
	if(ans=='n' || ans=='N'){
		s.newAccount();
	}else{
		s.checkUser();
	}
	return 0;
}