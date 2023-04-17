#include<iostream>
using namespace std;


struct node{
	int data;
	node* next;
};



int size=0;
node*head=NULL;
node*front=NULL;
node*rear=NULL;



//Check Linked List is Empty or Not
bool isEmpty(bool toPrint){
	if(front==NULL){
	cout<<"Linked List Is Empty"<<endl;
	return true;
	}
	else{
	if (toPrint) cout<<"Linked List Is Not Empty"<<endl;
	return false;
	}
	}



//Enqueue or Insert value at the Front
 void enqueue(int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;    
	 
    if (rear == NULL) {
	front = rear = new_node;
    size++;
    return;
    }
         
    rear->next = new_node;
    rear = new_node;
    size++;
    }



//Dequeue or Deleting Front value
void dequeue(){
	if(isEmpty(false))
	return ;
	
	node* temp =front;
	front=front->next;
	delete temp;
	size--;
	cout<<"The Value At The Front Has Been Deleted"<<endl;
	return ;
	}




//Display Elements and the size 
void displaySize(){
	if(isEmpty(false))
	return ;
	
	node* curr=front;
	cout<<"The Elements Of The Linked List Are : "<<endl;
	while(curr){
	cout<<curr->data<<" ";
	curr=curr->next;
	}
	cout<<endl;
	cout<<"The Size Of The Linked List is : "<<size<<endl;	
	}



//Display Front Value Of the Linked List
void frontData(){
	if(isEmpty(false))
	return ;
	
	cout<<"The Value At The Front is : "<<front->data<<endl;
	}



//Dequeue or Deleting Rear value
void dequeueRear(){
	if(isEmpty(false))
	return ;
	
	if(rear==front){
	delete rear;
	rear=front=NULL;
	size--;
	return ;
	}
	
	node* prev =front;
	while(prev->next!=rear){
	prev=prev->next;
	}
	
	delete rear;
	rear=prev;
	rear->next=NULL;
	size--;
	cout<<"Rear Has Been Deleted Successfully"<<endl;
	return ;
	}



//Displaying Even and Odd Elements
void evenOdd(){
	if(isEmpty(false))
	return ;
	
	node* curr=front;
	cout<<"Even Elements Are : "<<endl;
	while(curr){
	if(curr->data%2==0){
	cout<<curr->data<<" ";
	}
	curr=curr->next;
	}
	cout<<endl;
	
	
	
	node* cur=front;
	cout<<"Odd Elements Are : "<<endl;
	while(cur){
	if(cur->data%2!=0){
	cout<<cur->data<<" ";
	}
	cur=cur->next;
	}
	cout<<endl;
	}



//Sorting the elements in Ascenidng Order
void asc(){
	if(isEmpty(false))
	return ;
	
	node* curr=front;
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
	cout<<"After Sorting in Ascending Order : "<<endl;
	while(curr){
	cout<<curr->data<<" ";
	curr=curr->next;
	}
	cout<<endl;
	}



//Sorting the elements in Ascenidng Order
void dsc(){
	if(isEmpty(false))
	return ;
	node* curr=front;
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
	cout<<"After Sorting in Descending Order :  "<<endl;
	while(curr){
	cout<<curr->data<<" ";
	curr=curr->next;
	}
	cout<<endl;
	}






int main(){
	int val,n;
	
	cout<<"********************************************"<<endl;
	cout<<"1. Enqueue Elements Into The Linked List"<<endl;
	cout<<"2. Dequeue Elements From The Linked List"<<endl;
	cout<<"3. Display Elements and Size of The Linked List"<<endl;
	cout<<"4. Dequeue Rear of The Linked List"<<endl;
	cout<<"5. Display Front of The Linked List"<<endl;
	cout<<"6. Display Even And Odd Elements"<<endl;
	cout<<"7. Sort The Linked list in Asecnding Order"<<endl;
	cout<<"8. Sort The Linked list in Desecnding Order"<<endl;
	cout<<"9. Check Linked List Is Empty Or Not"<<endl;
	cout<<"10.Exit"<<endl;
	cout<<"********************************************"<<endl;
	
	do{
	
	cout<<"Enter Operation To Perform"<<endl;
	cin>>n;
	
	switch(n){
		
	case 1 :{
	cout<<"Please Enter Value To Enqueue"<<endl;
	cin>>val;
	enqueue(val);
	break;
	}
	
	
	case 2 :{
	dequeue();
	break;
	}
	
	
	case 3 :{
	displaySize();
	break;
	}
	
	
	case 4 :{
	dequeueRear();
	break;
	}
	
	
	case 5 :{
	frontData();
	break;
	}
		
		
	case 6 :{
	evenOdd();
	break;
	}	
	
	
	case 7 :{
	asc();
	break;
	}	
	
	
	case 8 :{
	dsc();
	break;
	}	
		
	
	case 9 :{
	isEmpty(true);
	break;
	}
	
	
	case 10 :{
	cout<<"*******************************"<<endl;
	cout<<"      Thanks For Compiling      "<<endl;
	cout<<"*******************************"<<endl;
	exit(0);
	break;
	}
	
	
	default :{
	cout<<"Invalid Character"<<endl;
	break;
	}
	
	
	}	
	}while(n!=10);
	
	
	
	return 0;
	}








