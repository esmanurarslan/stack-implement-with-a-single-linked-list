#include<iostream>
#include<ostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

class Stack{
    public:
    Node* head;
    
    public:
        Stack(){
            head=NULL;
        }
    void pop();
    void push(int data);
    int top();
    int size();
    void isEmpty();
    Stack stackSorter(Stack stack1, Stack stack2);
    void printStackItems();
};

void Stack::pop(){
    Node* node=head;
    if(head==NULL){
        cout<<"ERROR"<<endl;
    }else if(head->next!=NULL){
        while(node->next->next!=NULL){
        node=node->next;}  
    node->next=NULL;
    int data=node->data;}
    else{ 
        head=NULL;
    }    
}

void Stack::push(int data){
   Node* temp= new Node();
    temp->data=data;
    temp->next=NULL;
    if(head==NULL){
        head=temp;  
    }else{
        Node* node=head;
        while(node->next!=NULL)
        node=node->next;
    node->next=temp;
   }
}
      
int Stack::top(){
    int x;
    Node* node=head;
    if(head==NULL){
       // cout<<"ERROR"<<endl;
    }else {
    while(node->next!=NULL){
        node=node->next;
    }
    x=node->data;
    //cout<<x<<endl;
    }
   return x;
}

int Stack::size(){
    int count=0;
    Node* node=head;
    if(head==NULL){
        //cout<<"size:"<<count<<endl;
        return count;
    }else{
        while(node->next!=NULL){
        count++;
        node=node->next;
    }
    //cout<<"size:"<<count+1<<endl;
    return count+1;
    }  
}

void Stack::isEmpty(){
   if(head==NULL){
    cout<<"true"<<endl;
   }else{
    cout<<"false"<<endl;
   }
}

void Stack::printStackItems(){
    Node* node=head;
    while(node->next!=NULL){
        cout<<node->data<<" ";node=node->next;
    }
    cout<<node->data<<endl;
}

Stack Stack::stackSorter(Stack S,Stack X){
    Stack s=S;
    Stack x=X;
    int newS;
    Stack merge;
while(s.size()!=0 | x.size()!=0){
if(s.top()<x.top()){
    newS= s.top();
    s.pop();
    merge.push(newS);
}else if(s.top()>x.top()){
    newS= x.top();
    x.pop();    
    merge.push(newS); 
}else if(s.top()==0 && x.top()>0){
    newS= x.top();
    x.pop();
    merge.push(newS);
}else{
    newS= s.top();
    s.pop();
    merge.push(newS);
    }}
cout<<"max element is on the top"<<endl;
merge.printStackItems(); //this stack is MAX ON TOP
Stack sorted;
int mobil;
while(merge.size()!=0){
    int mobil=merge.top();
    merge.pop();
    sorted.push(mobil);
}
cout<<"min element is on the top"<<endl;
sorted.printStackItems(); //this stac is MIN on top
cout<<"Sorted stack's size :"<<sorted.size()<<endl;
cout<<"Sorted stack's top element is "<<sorted.top()<<endl;
return sorted;
}

int main(){
    Stack newStack1;
    newStack1.push(15);
    newStack1.push(9);
    newStack1.push(4);
    
    Stack newStack2;
    newStack2.push(6);
    newStack2.push(5);
    
    newStack1.printStackItems();
    newStack2.printStackItems();
    Stack mergeStack;
    mergeStack.stackSorter(newStack1,newStack2);
    return 0;
}