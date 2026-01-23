//Linked List to implement stack 
#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
Node* top=nullptr;

//push
void push(int x){
    Node* newNode=new Node();
    newNode->data=x;
    newNode->next=top;
    top=newNode;
    cout<<x<<" pushed to stack.\n";

}

//pop
void pop(){
    if(top==nullptr){
        cout<<"stack is empty!!\n";
        return;
    }
    Node* temp=top;
    top=top->next;
    cout<<temp->data<<" popped from stack.\n";
    delete temp;
}
//display
void display(){
    if(top==nullptr){
        cout<<"No thing to display!!\n";
        return;
    }
    Node*temp=top;
    cout<<"stack element(top to bottom are:\n ";
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    cout<<"\n------------Implementation of stack using linked list-----------\n";
    int x,choice;
    do{
      cout<<"\n------------MENU DRIVEN-----------\n";
      cout<<"\n 1.push \n 2.pop \n 3.display. \n 4.Exit \n";
      cin>>choice;
      switch(choice){
        case 1:
           cout<<"\nEnter value to push: ";
           cin>>x;
           push(x);
           break;
        case 2:
           pop();
           break;
        case 3:
           display();
           break;
        case 4:
          cout<<"Exitng........\n";
           break;
        default:
           cout<<"invalid choice!!!!\n";
      }

    }while(choice!=4);
   
    
    return 0;
}