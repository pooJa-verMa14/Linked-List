//WAP to reverse a linked list

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *link;
    node(int x)  //constructor
    {
        data = x;
        link =NULL;
    }
};

class linkedlist
{
    private:
    node *head;

    public:
    linkedlist()
    {
        head =NULL;
    }

    void display()
    {
        if(head==NULL) return;
        node *curr=head;
        while(curr!=NULL)
        {
            cout<<curr->data<<" ";
            curr=curr->link;
        }
        cout<<endl;
    }

    void insertBeg(int x)
    {
        node *temp=new node(x);
        temp->link=head;
        head=temp;
    }

    void reverse()
    {
        node *curr=head;
        node *prev=NULL;
        while(curr!=NULL)
        {
            node *next=curr->link;
            curr->link=prev;
            prev=curr;
            curr=next;
        }
        head=prev;
    }

    
};    

int main(void)
{
    linkedlist LL;
    LL.insertBeg(1);
    LL.insertBeg(3);
    LL.insertBeg(1);
    LL.insertBeg(2);
    LL.insertBeg(1);
    LL.insertBeg(2);
    LL.insertBeg(1);
    cout<<"INTIALLY LINKED LIST IS\n";
    LL.display();
    LL.reverse();
    cout<<"AFTER REVERSING THE LINKED LIST\n";
    LL.display();
    
}

