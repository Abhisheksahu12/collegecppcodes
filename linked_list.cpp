#include <iostream>
using namespace std;

class  node{
    public :
    int data ;
      node *next ;
      node (int val){
          data = val;
          next = NULL;
          
      }
     };
        
        void insertAtHead(node*  &head, int val){
         node* n = new node(val);
         n->next=head;
         head=n;
        }
     
     
     
     void insertAtTail(node*  &head, int val){
         node* n = new node(val);
         if (head ==NULL) {
             head=n;
             return;
         }
         node * temp=head;
         while (temp->next!=NULL){
             temp=temp->next;
             
         }
         temp->next=n;
     }
     
       //node* head =NULL;
     //void insert (int temp){
        // node* next = (node*) malloc (sizeof(node));
       // next->data=temp;
      //  next->next = head;
      //  head=next; 
     //}
     void display(node * head){
        node* ptr=head;
        while (ptr!=NULL){
            cout<<ptr->data<< "->";
  
            ptr=ptr->next;

        }
        cout<<"NULL"<<endl;
     }
     node* reverse(node* head){
         node* prevptr=NULL;
         node* currptr=head;
         node* nextptr;
         
         while (currptr!=NULL){
             nextptr=currptr->next;
             currptr->next=prevptr;
             
             prevptr=currptr;
             currptr=nextptr;
         }
         return prevptr;
         
         
     }
     bool search(node*  &head, int key ){
         node* ptr=head;
        while (ptr!=NULL){
            if (ptr->data==key){
                return true;
            }
        ptr = ptr->next;
            
     }
     return false;
     }
 int main(){
     node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    cout<<" linked list is :  ";
    display(head);
    insertAtHead(head,4);
    cout<< "Element added to head : " ;
    display(head);
     node* newhead = reverse(head);
     cout<<"Reverse linked list : ";
    display (newhead);
    cout<<"Searched Element's position in the list : "<<search(head,5);
 }
 

