#include<iostream>
using namespace std;
#define MAX_SIZE 5

int queue[MAX_SIZE];
int front=-1,rear=-1;

bool isEmpty(){
    return (front==-1 || front>rear);
}

bool isFull(){
    return (rear==MAX_SIZE-1);
}

void enqueue(int x){
    if(isFull()){
        cout<<"Queue overflow\n";
        return;
    }
    else if (isEmpty()){
        front=0;
    }
    rear++;
    queue[rear]=x;
    cout<<"Added successfull\n";
}

void dequeue(){
    if(isEmpty()){
        cout<<"Queue underflow\n";
        return;
    }
    front++;
    cout<<"\ndeleted successfully\n";
}

void display(){
    if(isEmpty()){
        cout<<"Queue is Empty\n";
    }
    else{
        cout<<"Queue Elements: ";
    for (int i=front;i<=rear;i++){
        cout<<queue[i]<<" ";
        
    }
    cout<<endl;
    }
}

int main(){
    int choice ,x;
   do{
    cout<<"\n Lineat Queue Implementation Program \n";
    cout<<"\n 1.Enqueue \n 2.Dequeue \n 3.Display \n 4.Exit\n";
    cin>>choice;

    switch(choice){
        case 1:
          cout<<"Enter value:";
          cin>>x;
          enqueue(x);
         
          break;
        case 2:
           dequeue();
           break;
        case 3:
           display();
           break;
        case 4:
          cout<<"Exiting program......\n";
          break;
        default:
           cout<<"invalid choice!!!!\n";
    }
   }while(choice!=4);
return 0;
}