//WAP to remove duplicate numbers from the list

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

    void removeDup()
    {
        node *curr=head;
        while(curr!=NULL && curr->link!=NULL)
        {
            if(curr->data == curr->link->data)
            {
                node *temp=curr->link;
                curr->link=curr->link->link;
                delete temp;
            }
            else
            {
                curr=curr->link;
            }
        }
    }
    
};    

int main(void)
{
    linkedlist LL;
    LL.insertBeg(40);
    LL.insertBeg(30);
    LL.insertBeg(30);
    LL.insertBeg(20);
    LL.insertBeg(20);
    LL.insertBeg(20);
    LL.insertBeg(10);
    cout<<"INTIALLY LINKED LIST IS\n";
    LL.display();
    cout<<"AFTER\n";
    LL.removeDup();
    LL.display();
    
}

