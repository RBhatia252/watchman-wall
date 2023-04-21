#include<iostream>
#include<fstream>   // files 
#include<sstream> //strings
#include<string>
using namespace std;
int main()
{
   int a,i=0;
   string text,old,pass1,pass2,pass,name,pass0,age,user,sp,sp1;
   string creds[2],cp[2];
 
 cout<<"Security System"<<endl;
 
 cout<<"---------------------------------------------------------"<<endl<<endl;
 cout<<"		        1. Register			        	"<<endl;
 cout<<"			2. Login			           	"<<endl;
 cout<<"			3. Change Password	        	"<<endl;
 cout<<"------------------------4. End Program------------------ "<<endl<<endl;
 
 do{
 	cout<<endl<<endl;
 	cout<<"Enter your choice:"<<endl;
 	cin>>a;
 	switch(a)
 	{
 		case 1:{
 			cout<<"---------------------------------------"<<endl<<endl;
 			cout<<"--------------Register-----------------"<<endl;
 			cout<<"---------------------------------------"<<endl<<endl;
 			cout<<"Please Enter username: ";
 			cin>>name;
 			cout<<"Please Enter Password: ";
 			cin>>pass0;
 			cout<<"Please Enter your age: ";
 			cin>>age;
 			
 			ofstream of1; // used to open a file to write something in it (ifstream is used for read something)
 			of1.open("file.txt");   // object of ofstream class
			 if(of1.is_open()){
			  of1<<name<<"\n";
			  of1<<pass0<<"\n";
			  cout<<"Registration Completed "<<endl;
		}

			break;
		 }
		 case 2:{
		 	i=0;
		 	cout<<"---------------------------------------"<<endl<<endl;
 			cout<<"--------------Login-----------------"<<endl;
 			cout<<"---------------------------------------"<<endl<<endl;
 			ifstream of2;
 			of2.open("file.txt");
 			cout<<"Please Enter the username: ";
 			cin>>name;
 			cout<<"Please Enter Password: ";
 			cin>>pass0;
 		    if(of2.is_open())
 		    {
 		    	while(!of2.eof()){                               //eof means end of file
 		    		while(getline (of2, text)){ 				//read file line by line
 		    			istringstream iss(text);               // stream the string and store it extraction operator
 		    			iss>>sp;
 		    			creds[i]==sp; 						  //store the values 
						 i++; 
					 }
					 if(user==creds[0] && pass==creds[1]){
					 	cout<<"---Login Sucessfully!!---"<<endl<<endl;
					 	cout<<"Details: "<<endl;
					 	
					 	cout<<"Username: "+ name<<endl;
					 	cout<<"Passwords: "+ name<<endl;
						cout<<"Age: "+ name<<endl;
					 }
					 else{
					 	cout<<endl<<endl;
					 	cout<<"Incorrect value"<<endl;
					 	cout<<"			1. Press 2 to Login       "<<endl;
					 	cout<<"			2. Press 3 to Change Password       "<<endl;
					 	cout<<"			3. Press 2 to Login       "<<endl;
						break;
					 }
				 }
			 }
		 	
			break;
		 }
		 case 3:{
		 	i=0;
		 	cout<<"----------------Change Password--------------"<<endl;
		 	
		 	ifstream of0;
		 	of0.open("file.txt");
		 	cout<<"Enter the previous Password: ";
		 	cin>>old;
		 	if(of0.is_open())
		 	{
		 		while(of0.eof())
		 		{
		 			while(getline(of0,text)){
		 				istringstream iss(text);
		 				iss>>sp1;
		 				cp[i]=sp1;
		 				i++;
					 }
					 if(old==cp[1])
					 {
					 	of0.close();    // close the file for free space
					 	ofstream of1;
					 	if(of1.is_open())
					 	{
					 		cout<<"Enter your new Password: ";
					 		cin>>pass1;
					 		cout<<"Enter your password again: ";
					 		cin>>pass2;
					 		if(pass1==pass2)
							 {
							 	of1<<cp[0]<<"\n";
							 	of1<<pass1;
							 	cout<<"Pssword changed sucessfully!"<<endl;
							 }
							 else{
							 	of1<<cp[0]<<"\n";
							 	of1<<old;
							 	cout<<"Password do not match"<<endl;
							 }
						 }
					 }
					 else{
					 	cout<<"Please enter valid password"<<endl;
					 	break;
					 }
				 }
			 }
			break;
		 }
		 case 4:{
		 	cout<<"--------------THANKYOU--------------";
			break;
		 }
		 	default:
		 		cout<<"Enter a Valid choice";
	 }
 }
 while(a!=4);
 return 0;
 
}
