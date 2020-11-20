#include<iostream>
#include<map>
#include<fstream>
#include<sstream>  
#include<cstring>
using namespace std;
map<int,float> roll_borrow; //Map that contain borrow as value and roll no as key
char listofitems[8][20]={"paneer prantha","aloo prantha","burgur","cold drink","red bull","maggie","egg","bread"};
    int price[8] = {30,20,30,10,20,20,8,10};
    class items{
	
	public:
		void showHistory(int ID){
			stringstream ss;  
            ss<<ID;  
            char name_of_file[20]={0}; 
            ss>>name_of_file;
            strcat(name_of_file,".txt");
			ifstream history_file;
			history_file.open(name_of_file,ios::in); 
            if (history_file.is_open()){ 
            string tp;
            while(getline(history_file, tp)){ 
            cout << tp << "\n";
        }
        history_file.close(); //close the file object.
        }
		}
		int showList(int ID){
			map<int,int> current_order;
			for(int i=0;i<8;i++){
				cout<<"Type "<<i+1<<" for "<<listofitems[i]<<" : "<<price[i]<<"/-"<<endl;
			}
			int orderNo=-1;
			while(orderNo){
				cout<<"Enter next choice or 0 ,nagetive no to Stop entering data"<<endl;
				cin>>orderNo;
				if(orderNo<1){
					break;
				}
				cout<<"How mush unit of "<<listofitems[orderNo -1]<<endl<<"Enter in minus if you want to decrease the selected content"<<endl;
				int times;
				cin>>times;			
					if (current_order.find(orderNo) == current_order.end()) 
                        {
                        	if(times>0){
                        		current_order.insert(pair<int,int> (orderNo,times));
							} else{
								cout<<"Seems like you came from another planet . Pls enter a valid choose!"<<endl;
							}
						}else{
							if(times>0){
								current_order[orderNo]+=times;
							}else{
								if(current_order[orderNo]>=(times*-1)){
									current_order[orderNo]+=times;
								}else{
									cout<<"Hey previously you order for "<<current_order[orderNo]<<" "<<listofitems[orderNo-1]<<" now u want to minus "<<times<<" Pls take it serious"<<endl;
								}
							}
						}
			}
			stringstream ss;  
            ss<<ID;  
            char name_of_file[20]; 
            ss>>name_of_file;
            strcat(name_of_file,".txt");
			ofstream orders;
			orders.open(name_of_file,ios::app);
			cout<<"This is your final order"<<endl;
			map<int,int>::iterator it;
			int current_bill=0;
			orders<<"\n";
			for(it = current_order.begin(); it != current_order.end(); ++it)
            {  
			    if(it->second){
			    	
            	cout << listofitems[(it->first)-1] << " ,units: " << it->second<<endl;
            	orders<<listofitems[(it->first)-1];
            	orders<<" ,units: ";
            	orders<<it->second;
            	orders<<"\n";
            	current_bill+=price[(it->first)-1]*it->second;
			    }
			    
            }
            orders<<"Bill of above is ";
            orders<<current_bill;
            orders<<"\n";
            orders.close();
            cout<<"This is total amount of bill added to your account "<<current_bill<<endl<<"Have a good day :)"<<endl;
			return current_bill;
		}
};
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
				roll_borrow.insert(pair<int,float> (ID,borrow_amount));
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
			items i ;
	        while(1){
	        	cout<<"Enter 1 to order food"<<endl<<"Enter 2 to view history"<<endl<<"Enter 3 to pay bill"<<endl<<"Enter 0 to logout"<<endl;
			    int choice;
		     	cin>>choice;
	        	switch(choice){
	        		case 0:
	        			break; //make user logout here pending
	        		case 1:
					    {
					    	int current_bill = i.showList(ID);
		          	        roll_borrow[ID] +=current_bill;	
		          	    break;
						}
		          	case 2:
		          		i.showHistory(ID);
		          		break;
		          	case 3:
					    break;	
				}
			}
			
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