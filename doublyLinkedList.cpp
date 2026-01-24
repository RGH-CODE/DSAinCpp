//operation to perform on doubly linked list 
/*
1.Insertion: from front ,at end and in specific position
2.Deletion: from front ,from end and from specific position 

*/
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

};
Node* head=NULL;
Node* tail=NULL;
void insertionAtFront(int value){
    Node* newNode=new Node();
    newNode->data=value;
    newNode->prev=NULL;
    newNode->next=head;
    if(head!=NULL){
        head->prev=newNode;
    }
    else{
        tail=head=newNode;
    }
    head=newNode;
    cout<<"\n"<<value<< " is inserted at front";
    cout<<endl;

}
void insertionAtEnd(int value){
Node* newNode=new Node();
newNode->data=value;
newNode->next=NULL;
if(tail==NULL){
    newNode->prev=NULL;
    head=tail=newNode;
    return;
}else{
    newNode->prev=tail;
    tail->next=newNode;
    tail=newNode;
}
cout<<"\n"<<value<<" inserted at end";
cout<<endl;
}

void insertionAtSpecific(int pos,int value){
    int position=pos;
    if(position==1){
        insertionAtFront(value);
        return;
    }
   
   Node* current=head;
   for(int i=1;i<position-1 && current!=NULL;i++){
    current=current->next;
   }
   if(current==NULL)
{
    cout<<"invalid position\n";
}  
if(current==tail){
    insertionAtEnd(value);
    return;
} 
Node* newNode=new Node();
   newNode->data=value;
   newNode->next=current->next;
   newNode->prev=current;
   current->next->prev=newNode;
   current->next=newNode;
   cout<<"\n"<<value <<" is inserted at position \n"<<pos;
}


void deletionFromFront(){
    if(head==NULL){
        cout<<"List is empty!!\n";
        return;
    }
    Node* temp=head;
    head=head->next;
    if(head!=NULL){
        head->prev=NULL;
    }
    else{
        tail=NULL;
    }
    cout<<"\n"<<temp->data<<" is deleted!!\n";
    delete temp;
    
}

void deletionFromEnd(){
    if(tail==NULL){
       cout<<"List is empty!!!\n";
       return;
    }
    Node*temp=tail;
    tail=tail->prev;
    if(tail!=NULL){
        tail->next=NULL;
    }
    else{
      head=NULL;
    }
    cout<<"\n"<<temp->data<<" is deleted end!!\n";
    delete temp;

}

void deletionFromSpecificPosition(int pos){
    int position=pos;
    if(position==1){
        deletionFromFront();
        return;
    }

Node* current=head;
for(int i=1;i<=position-1 && current!=NULL;i++){
    current=current->next;
}
if(current==NULL){
    cout<<"Invalid position!!\n";
}
if(current==tail){
    deletionFromEnd();
    return;
}
current->prev->next=current->next;
current->next->prev=current->prev;
cout<<"\n"<<current->data<<" is deleted from postion "<<pos;
delete current;
    
}

void display(){
    if(head==NULL){
        cout<<"\nNothing to display\n";
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    int choice, x,position;
    cout<<"----------MENU DRIVEN FOR DOUBLY LINKED LIST--------\n";
    do{
    cout<<"\n 1.Insertion at Front \n 2.Insertion at End \n 3.Insertion At Specific Position \n 4.Deletion From Front \n 5.Deletion From End \n 6.Deletion FromSpecific Position \n  7.Display \n 8.Exit\n";
    cin>>choice;
    switch(choice){
        case 1:
           cout<<"Enter the value to insert: ";
           cin>>x;
           insertionAtFront(x);
           break;
        case 2:
           cout<<"Enter the value to insert: ";
           cin>>x;
           insertionAtEnd(x);
           break;
        case 3:
            cout<<"Enter the postion: ";
            cin>>position;
            cout<<"Enter the value: ";
            cin>>x;
            insertionAtSpecific(position,x);
            break;
        case 4:
            deletionFromFront();
            break;

        case 5:
            deletionFromEnd();
            break;
        
        case 6:
        cout<<"Enter the postion to delete: ";
        cin>>position;
        deletionFromSpecificPosition(position);
        break;

        case 7:
           cout<<"\n-----displaying the current elements----\n";
           display();
           break;
        
        case 8:
           cout<<"\nExiting...........\n";
           break;
        default:
           cout<<"\nInvalid choice!!!!!!\n";
    }
}while(choice!=8);

    return 0;
}