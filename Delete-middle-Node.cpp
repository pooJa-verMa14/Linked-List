//WAP to delete the middle node of the linked list without counting the nodes of the linkedlist

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

    void delMid()
    {
        node *curr=head;
        node *curr1=head;
        node *prev=NULL;
        while(curr1->link!=NULL)
        {
            curr1=curr1->link->link;
            prev=curr;
            curr=curr->link;
            if(curr1==NULL)
            {
                break;
            }
        }
        prev->link=curr->link;
        curr->link=NULL;
        delete curr;
    }

    
    
};    

int main(void)
{
    linkedlist LL;
    LL.insertBeg(6);
    LL.insertBeg(5);
    LL.insertBeg(4);
    LL.insertBeg(3);
    LL.insertBeg(2);
    LL.insertBeg(1);
    cout<<"INTIALLY LINKED LIST IS\n";
    LL.display();
    cout<<"AFTER\n";
    LL.delMid();
    LL.display();
    
}

