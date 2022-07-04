//WAP to merge two sorted LL

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *link; 
    node (int x) //constructor for struct
    {
        data = x;
        link = NULL;
    }
};

class linkedlist
{
    public:
    node *head;
    linkedlist() // constructor for class
    {
        head = NULL;
    }

    void printlist()
    {
        if(head==NULL)
        {
            cout<<"LIST IS EMPTY\n";
            return ;
        }
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
        node *temp = new node(x);
        temp->link=head;
        head=temp;
    }
};

int main(void)
{
    node *a,*b;
    linkedlist LL1;
    LL1.insertBeg(40);
    LL1.insertBeg(15);
    LL1.insertBeg(10);
    LL1.insertBeg(4);
    LL1.printlist();
    linkedlist LL2;
    LL2.insertBeg(20);
    LL2.insertBeg(3);
    LL2.insertBeg(2);
    
    LL2.printlist();
    linkedlist merge;
    a=LL1.head;
    b=LL2.head;
    if(a==NULL)
    {
        merge.head=b;
    }
    if(b==NULL)
    {
        merge.head=a;
    }
    node *tail=NULL;
    if(a->data<=b->data)
    {
        merge.head=a;
        tail=a;
        a=a->link;
    }
    else
    {
        merge.head=b;
        tail=b;
        b=b->link;
    }
    while(a!=NULL && b!=NULL)
    {
        if(a->data<=b->data)
        {
            tail->link=a; //to attach tail with a;
            tail=a; // to increment tail
            a=a->link; //to increment a
        }
        else
        {
            tail->link=b;
            tail=b;
            b=b->link;
        }
    }
    if(a==NULL)
    {
        tail->link=b;
    }
    else
    {
        tail->link=a;
    }

    merge.printlist();




}


