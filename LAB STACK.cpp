#include<iostream>
using namespace std;

int stack[100],n=100,top=-1;

void push(int val){
	if(top >=n-1)
	cout<<"Stack Overflow"<<endl;
	else 
	{

	top++;
	stack[top]=val;
}
	
}

void pop()
{
	if(top<=-1)
	cout<<"Stack Underflow"<<endl;
	else
	{
		cout<<"The Popped Element is "<<stack[top]<<endl;
		top--;
	}
}

	void display (){
if(top>=0)
{
	cout<<"Stack Elements are :";
	for(int i=top; i>=0; i--)
	cout<<stack[i]<<" ";
	cout<<endl;
	}
	
	else
	cout<<"Stack is Empty";
}




int main(){
	
	
	int ch, val;
	cout<<"1) Push In stack"<<endl;
	cout<<"2) Pop From stack"<<endl;
	cout<<"3) Dispaly stack"<<endl;
	cout<<"4) Exit"<<endl;

do{
	
	cout<<"Enter Choice"<<endl;
	cin>>ch;
	switch(ch){
		case 1:
			{
				cout<<"Enter Value To Be Pushed"<<endl;
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
	
	case 4:{
		cout<<"Exit"<<endl;
		break;
	}
	
	default:
		{
			cout<<"Invalid Character"<<endl;
		}
	
        }
	}
	
	while(ch!=4);
	return 0;
}



