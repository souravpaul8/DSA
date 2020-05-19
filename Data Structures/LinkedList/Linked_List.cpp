#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *next;
};

class LinkedList{
    private:
       
    public:
         Node *head;
        LinkedList(){
            head=NULL;
        }
    
    void addNode(int n,int pos){       
        Node* temp1 = new Node ;
        temp1->data = n;
        temp1->next = NULL;
        
        if(pos==1){
            temp1->next=head;
            head = temp1;
            return;
        }
            Node* temp2 = head;
            for(int i=0;i<pos-2;i++){
                temp2=temp2->next;
            }
            temp1->next = temp2->next;
            temp2->next = temp1;
        }
    
    void deleteNode(int n){
        Node* temp = head;
        
        if(n==1){
            head = temp->next;
            delete temp;
            return;
        }
        
        for(int i=0;i<n-2;i++){
            temp = temp->next;
        }
        
        Node* temp1=temp->next;
        temp->next = temp1->next;
        delete temp1;
    }
    
    void printList(){
        Node* temp = head;
        while(temp!=NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void reverseListIter(){
        Node *curr,*prev,*next;
        curr = head;
        prev = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head = prev;
    }
    
    void reverseRecursive(Node* p){
        if(p->next==NULL){
            head=p;
            return;
        }
        reverseRecursive(p->next);
        Node* q = p->next;
        q->next = p;
        p->next=NULL;
    }
    
    void printMiddle(){
        Node *temp1 = head;
        Node *temp2 = head;
        
        while(temp1 != NULL && temp1->next!=NULL){
            temp1 = temp1->next->next;
            temp2 = temp2->next;
        }
        
        cout << "Middle Element is : " << temp2->data << endl;
    }
    void detectLoop(){
        Node *walker, *runner;
        while(walker!=NULL && runner!=NULL && runner->next!=NULL){
            if(walker==runner){
                cout << "Loop is Detected" << endl;
                return;
            }
        }
        
        cout << "Loop doesn't exist" << endl;
    }
};

int main() {
    LinkedList a;
    a.addNode(4,1);
    a.addNode(2,2);
    a.addNode(10,1);
    a.addNode(6,1);
    a.addNode(8,2);
    a.deleteNode(3);
    a.printList();
    a.reverseRecursive(a.head);
    a.printList();
    a.reverseListIter();
    a.printList();
    a.printMiddle();
    a.detectLoop();
    
    return 0;
}
