#include<iostream>
using namespace std;



struct node{
	int data;
	node* next;
};



node* top=NULL;
node* bottom=NULL;
int size=0;



//Checking Linked List is Empty or Not
bool empty(bool toPrint){
	if(top==NULL){
	cout<<"Linked List Is Empty"<<endl;
	return true ;
	}
	else{
	if(toPrint) cout<<"Linked List Is Not Empty"<<endl;
	return false ;
	}
	}



//Pushing New Element Into The Linked List
void push(int val){
	node* new_node=new node();
	new_node->data=val;
	new_node->next=top;
	
	if(bottom==NULL){
	bottom=new_node;
	}
	top=new_node;
	size++;
	return ;
	}



//Deleting Top Eelement
void pop(){
	if(empty(false))
	return ;
	node* temp=top;
	top=top->next;
	int value=temp->data;
	
	
	/*if(top==NULL){
	bottom=NULL;
	}*/
	
	cout<<"The Poped Element Is : "<<value<<endl;
	delete temp;
	size--;
	return ;
	}



//Deleting Bottom Element
void deleteBottom(){
	if(empty(false))
	return ;
	
	if(top==bottom){
	delete top;
	top=bottom=NULL;
	size--;
	return;
	}
	
	node* temp=top;
	while(temp->next!=bottom){
	temp=temp->next;
	}
	
	delete bottom;
	bottom=temp;
	bottom->next=NULL;
	size--;
	cout<<"Bottom Has Been Deleted Successfully"<<endl;
	return ;
	}
	



//Delete At The  Specific Index
void deleteAtIndex(int index){
	if(empty(false))
	return ;
	
	if(index<1 || index>size){
	cout<<"No Element Found At This Index"<<endl;
	return ;
	}
	
	if(index==1){
	pop();
	return ;
	}
	
	if(index==size){
	deleteBottom();
	return ;
	}
	
	node* temp=top;
	for(int i=1; i<index-1; i++){
	temp=temp->next;
	}
	
	node* delete_index=temp->next;
	temp->next=delete_index->next;
	int val=delete_index->data;
	delete delete_index;

	cout<<"The Element "<<val<<" At The Index "<<index<<" Has Been Deleted Successfully"<<endl;
}



//Element At The Top
void peek(){
	if(empty(false))
	return ;
	
	cout<<"Top Element Is : "<<top->data<<endl;
	}



//Display and size of the Linked List
void displaySize(){
	if(empty(false))
	return ;
	
	node* curr=top;
	cout<<"Elements Of The Linked List Are : "<<endl;
	while(curr){
	cout<<curr->data<<" ";	
	curr=curr->next;
	}
	cout<<endl;
	cout<<"The Size Or Total Elements in the Linked List  Are :"<<size<<endl;
	}




//Displaying Even And Odd Elements
void evenOdd(){
	if(empty(false))
	return ;
	
	node* curr=top;
	cout<<"Even Elements Are : "<<endl;
	while(curr){
	if(curr->data%2==0){
	cout<<curr->data<<" ";
	}
	curr=curr->next;
	}
	cout<<endl;
	
	node* cur=top;
	cout<<"Odd Elements Are : "<<endl;
	while(cur){
	if(cur->data%2!=0){
	cout<<cur->data<<" ";
	}
	cur=cur->next;
	}
	cout<<endl;
}




//Sorting In Ascending Order 
void asc(){
	if(empty(false))
	return ;
	node* curr=top;
	node* i;
	node* j;
	int temp;
	
	for(i=curr; i!=NULL; i=i->next){
	for(j=i->next; j!=NULL; j=j->next){
	if(i->data>j->data){
	temp=i->data;
	i->data=j->data;
	j->data=temp;
	}
	}
	}
	cout<<"After Sorting Ascending Order:"<<endl;
	while(curr){
	cout<<curr->data<<" ";
	curr=curr->next;
	}
	cout<<endl;
	}




//Sorting in Descending Order 
void dsc(){
	if(empty(false))
	return ;
	node* curr=top;
	node* i;
	node* j;
	int temp;
	
	for(i=curr; i!=NULL; i=i->next){
	for(j=i->next; j!=NULL; j=j->next){
	if(i->data<j->data){
	temp=i->data;
	i->data=j->data;
	j->data=temp;
	}
	}
	}
	cout<<"After Sorting in Descending Order: "<<endl;
	while(curr){
	cout<<curr->data<<" ";
	curr=curr->next;
	}
	cout<<endl;
	}




int main(){
	int val,n,index;
	
	cout<<"************************************************"<<endl;
	cout<<"1. Push Elements Into The Linked List"<<endl;
	cout<<"2. Pop Elements Into From Linked List"<<endl;
	cout<<"3. Delete Bottom The Linked List"<<endl;
	cout<<"4. Delete Element At The Index"<<endl;
	cout<<"5. Display Elements and Size Of The Linked List"<<endl;
	cout<<"6. Display Peek or Top Element"<<endl;
	cout<<"7. Display Even And Odd  Elements"<<endl;
	cout<<"8. Sort The Linked list in Asecnding Order"<<endl;
	cout<<"9. Sort The Linked list in Desecnding Order"<<endl;
	cout<<"10. Check Linked List Is Empty or Not"<<endl;
	cout<<"11. Exit"<<endl;
	cout<<"************************************************"<<endl;
	
	do{
		
	cout<<"Enter Operation To PerForm"<<endl;
	cin>>n;
	
	switch(n){
		
	case 1 :{
	cout<<"Enter Value To Push"<<endl;
	cin>>val;
	push(val);	
	break;
	}
		
	
	case 2 :{
	pop();	
	break;
	}
	
	
	case 3 :{
	deleteBottom();	
	break;
	}
	
	
	case 4 :{
	cout<<"Enter The Index To Delete The Value"<<endl;
	cin>>index;
	deleteAtIndex(index);	
	break;
	}
	
	
	case 5 :{
	displaySize();	
	break;
	}
	
	
	case 6 :{
	peek();	
	break;
	}
	
	
	case 7 :{
	evenOdd();	
	break;
	}
	
	
	case 8 :{
	asc();	
	break;
	}
	
	
	case 9 :{
	dsc();	
	break;
	}
	
	
	case 10 :{
	empty(true);	
	break;
	}
	
	
	case 11 :{
	cout<<"****************************"<<endl;
	cout<<"    Thanks For Compiling    "<<endl;
	cout<<"****************************"<<endl;
	exit(0);	
	break;
	}
	
	
	default:
	cout<<"Invalid Character"<<endl;
	}	
	}while(n!=11);


	return 0;
}






