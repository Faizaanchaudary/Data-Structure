#include<iostream>
using namespace std;


struct node {
	int data;
	node* next;
};



node* head=0;

//Empty Function
bool  empty(bool toPrint){
	if (head==0) {
	cout<<"Linked List Is Empty "<<endl;
 	return true;
	} else {
		if (toPrint) cout<<"Linked List Is Not Empty "<<endl;
		return false;	
	} 	
}



//Inserting At the Begining
void insertBegin(int val){
	node* new_node=new node();
	new_node->data=val;
	new_node->next=head;
	head=new_node;
}



//Inserting At the Specific Position
void insertAtPosition(int val , int position){
	node* new_node= new node();
	new_node->data=val;
	
	if(position==1){
		new_node->next=head;
		head=new_node;
	}
	
	else{
		node* prev= head;
		for(int i=1; i<position-1; i++){
			prev=prev->next;
		}
		new_node->next=prev->next;
		prev->next=new_node;
	}
}




//Inserting At the End
void insertEnd(int value){
	node* one= new node();
	one->data=value;
	one->next=0;
	
	if(head==0){
		head=one;	
	}
	else {
		node* curr=head;
		while(curr->next){
		curr=curr->next;
		}
		curr->next=one;
	}
}


//Deleting First Node 
void deleteFirst(){
	if (empty(false)) 
	return;
	
	node* temp =head;
	head=head->next;
	delete temp;
	cout<<"First Node Has Been Deleted Successfully"<<endl;
}



// Deletion at a specific position
    void deleteAtPosition(int position) {
    if (empty(false)) 
	return;
	if (position == 1) {
 	node* temp = head;
    head = head->next;
    delete temp;
    }
	 else {
    node* prev = head;
   for (int i = 1; i < position - 1; i++) {
    prev = prev->next;
    }
    node* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    cout<<"The Element At The "<<position<<" Position Has Been Deleted"<<endl;
    }
    }


//Deleting Last Node 
void deleteLast(){
if (empty(false)) 
	return;
	 node* last = head;
	 node* prev = NULL;
	while(last->next){
		prev=last;
		last=last->next;
	}
	prev->next=NULL;
	cout<<"Last Node Has Been Deleted Successfully"<<endl;
	
}           
 
 

//Display Function
void show(){
	if (empty(false)) 
	return;
	int count=0;
	cout<<"Elements In The Linked List Are :"<<endl;
	node* curr =head;
	while(curr){
		count++;
		cout<<curr->data<<" ";
		curr=curr->next;
	}
		cout<<endl;
	cout<<"Total Elements In The Linked List Are : "<<count;
	cout<<endl;
}



//Sorting in ascending order
void sortAsc(){
	if (empty(false)) 
	return;
	
	node* list= head;
	node *i , *j;
	int temp;
	for(i=head; i!=NULL; i=i->next){
		for(j=i->next; j!=NULL; j=j->next){
			if(i->data>j->data){
			temp=i->data;
			i->data=j->data;
			j->data=temp;
		}
		}
	}
	cout<<"After Sorting Ascending Order : "<<endl;
	while(list){
		cout<<list->data<<" ";
		list=list->next;
	}
	cout<<endl;
}




//Soritng in Descending
void sortDsc(){
	if (empty(false)) 
	return;
	node* list = head;
	node *i , *j;
	int temp;
	for(i=head; i!=NULL; i=i->next){
		for(j=i->next; j!=NULL; j=j->next){
			if(i->data<j->data){
			temp=i->data;
			i->data=j->data;
			j->data=temp;
			}
		}
	}	
	cout<<"After Sorting in Descending Order : "<<endl;
	while(list){
		cout<<list->data<<" ";
		list=list->next;
	}
	cout<<endl;
}



//Displaying Even and Odd
void evenOdd(){
	if (empty(false)) 
	return;
	cout<<"Even Numbers In The Linked List Are : "<<endl;
	node* curr =head;
	while(curr){
		if(curr->data%2==0){
			cout<<curr->data<<" ";
		}
		curr=curr->next;
	}
	cout<<endl;
	cout<<"Odd Numbers In The Linked List Are : "<<endl;
	node* cur=head;
	while(cur){
		if(cur->data%2!=0){
			cout<<cur->data<<" ";
		}
		cur=cur->next;
	}
	cout<<endl;
}



int main(){
	
	int op,val,value,position;
	cout<<"*******************************************"<<endl;
	cout<<"1. Insert Elements At The Begining"<<endl;
	cout<<"2. Insert Elements At The Specific Position"<<endl;
	cout<<"3. Insert Elements At The End"<<endl;
	cout<<"4. Delete The First Node Of The Linked List"<<endl;
	cout<<"5. Delete Elements At The Specific Position"<<endl;
	cout<<"6. Delete The last Node Of The Linked List"<<endl;
	cout<<"7. Dispaly Elements Of The Linked List"<<endl;
	cout<<"8. Sort Linked List In Ascending Order"<<endl;
	cout<<"9. Sort Linked List In Descending Order"<<endl;
	cout<<"10. Display Even  and Odd Numbers"<<endl;
	cout<<"11. Check Linked List Is Empty or Not"<<endl;
	cout<<"12. Exit"<<endl;
	cout<<"*******************************************"<<endl;
	
	do{
	cout<<"Please Enter Operation Number : "<<endl;
	cin>>op;
		
	switch(op){
		
		
		case 1:
		{
		cout<<"Please Enter Value To Add The Begining: "<<endl;
		cin>>val;
		insertBegin(val);
		break;
		}             
		
		
		case 2:
		{
		cout<<"Please Enter The Position"<<endl;
		cin>>position;
		cout<<"Please Enter Value To Add At This Position"<<endl;
		cin>>val;
		insertAtPosition(val , position);
		break;
		}   
		
		case 3:
		{
		cout<<"Please Enter Value To Add The End: "<<endl;
		cin>>value;
		insertEnd(value);
		break;
		}    
		
		
		case 4 :
		{
		deleteFirst();
		break;
		}
		
		
		case 5:
		{
		cout<<"Please Enter The Position To Delete That Value : "<<endl;
		cin>>position;
		deleteAtPosition(position);
		break;
		}   
		    
		
		case 6 :
		{
		deleteLast();
		break;
		}   
		
		
		case 7 :
		{
		show();
		break;
		}   
		
	
		
		case 8 :
		{
		sortAsc();
		break;
		}
		  
		
		
		case 9 :
		{
		sortDsc();
		break;
		}    
		
			
		case 10 :
		{
		evenOdd();
		break;
		}    
		
		
		case 11 :
		{
		empty(true);
		break;
		}    
		
		
		
		case 12 :
		{
		cout<<"**************************"<<endl;
		cout<<"   Thanks For Compiling  "<<endl;
		cout<<"**************************"<<endl;
		exit(0);
		break;
		}    
		
		
		
		default :	
		cout<<"Sorry Invalid Character"<<endl;
		break;
	    }
	
		
	    }while(op!=12);
	    return 0;
		}