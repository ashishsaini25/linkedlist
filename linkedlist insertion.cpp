#include<bits/stdc++.h>
using namespace std ;
class node{
    public:
    int value;
    node *next;
    node(int data){
        value=data;
        next=NULL;

    }
};
int len(node *head){
    node *temp=head;
    int l=0;
    while(temp){
        l++;
        temp=temp->next;
    }
    return l;

}
void insertAtHead(node *&head,int data){
    node *n=new node(data);
    n->next=head;
    head=n;
}
void insertAttail(node *&head,int data){
    if(head==NULL){
        insertAtHead(head,data);
    }
    else{
    node *tmp=head;
    while(tmp->next!=NULL)tmp=tmp->next;
    tmp->next=new node(data);
    }
}

// insert after the required position.
void insertAtmiddle(node *&head,int data,int pos ){
    int l=len(head);
    if(l==0){
        insertAtHead(head,data);
    }
    else if(pos>l){
        insertAttail(head,data);
    }
    else{
        int j=0;
        node *temp=head;
        while(j<pos){
            j++;
            temp=temp->next;
        }
        node *n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
}
// insert after the required number.
void insertAfterElement(node *&head,int data,int element){
    bool found=false;
    node *temp=head;
    while(temp&&!found){
        if(temp->value==element){found=true;
        continue;
        }
        temp=temp->next;
       
    }
     if(found){
            node *n=new node(data);
            n->next=temp->next;
            temp->next=n;
        }
}
void print(node *head){                             
    node *temp=head;
    while(temp){
        cout<<temp->value<<" ";
        temp=temp->next;
    }
}

int main(){
    node *head=NULL;
    insertAttail(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAfterElement(head,40,50);
    //insertAtHead(head,50);
    insertAttail(head,100);
 //   insertAttail(head,500);
    print(head);


}