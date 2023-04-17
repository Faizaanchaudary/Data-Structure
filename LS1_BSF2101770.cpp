#include<iostream>
using namespace std;

//Initializing stack and top
int stack[5];
int n=5;
int top=-1;

//For Adding Elements In Stack
 void push(int val){
	if(top >=n-1)
	cout<<"Stack Overflow"<<endl;
	else 
	{
	top++;
	stack[top]=val;
	}
	}


//For Deleting Elements In Stack
 void pop(){
	if(top<=-1)
	cout<<"Stack Underflow"<<endl;
	else
	{
	cout<<"The Popped Element is "<<stack[top]<<endl;
	top--;
	}
	}
 
 //For Checking Stack Is Empty Or Not
 bool isempty(){
 	if (top==-1){
 		cout<<"Stack Is Empty"<<endl;
	 }
	 else 
	 cout<<"Stack Is Not Empty"<<endl; 
 	}
 	
 	
//For Checkig Stck Is Full
 bool isfull(){
 	if (top==n-1){
 		cout<<"Stack Is Full"<<endl;
	 }
	 else 
	 cout<<"Stack Is Not Full"<<endl;
 	}


//Displaying Stack Elements
	void display (){
	if(top>=0){
	cout<<"Stack Elements are :";
	for(int i=top; i>=0; i--)
	cout<<stack[i]<<" ";
	cout<<endl;
	}
	
	else
	cout<<"Stack is Empty";
	}

//Printing Even Elements 
 int even(){
 	cout<<"Even Numbers are :"<<endl;
	for(int i=top; i>=0; i--)
 	 if(stack[i]%2==0){
 		cout<<stack[i]<<" ";
 		cout<<endl;
	 }
 }


int main(){
	
	
	int ch, val;
	cout<<"*****************"<<endl;
	cout<<"1) Push In stack"<<endl;
	cout<<"2) Pop From stack"<<endl;
	cout<<"3) Dispaly stack"<<endl;
	cout<<"4) Check stack is empty "<<endl;
	cout<<"5) Check stack is Full"<<endl;
	cout<<"6) Even"<<endl;
	cout<<"7) Exit"<<endl;
	cout<<"*****************"<<endl;

do{
	cout<<" Please Enter Choice To Perform Operation:"<<endl;
	cin>>ch;
	switch(ch){
		
	case 1:
		{
		cout<<"Please Enter Value To Be Pushed"<<endl;
		cin>>val;
		push(val);
		break;
		
		}
	
	case 2:{
		pop();
		break;
	}
	
		
	case 3:{
		display();
		break;
	}
	
	
	case 4:
		{
		isempty();
		break;
		}
	
		
	case 5:
		{
		isfull();
		break;
		}
	
		
	case 6:{
		even();
		break;
	}
	
		
	case 7:{
	cout<<"***********"<<endl;
	cout<<"  THANKS "<<endl;
	cout<<"***********"<<endl;
	exit (0);
	break;
	}
	
	
	default:
		{
			cout<<"Invalid Character"<<endl;
			break;
		}
	
        }
	}
	
	while(ch!=4);
	return 0;
}



