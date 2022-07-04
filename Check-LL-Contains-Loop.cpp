// WAP to determine whether the LL is null terminate 

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
    private:
    node *head;

    public:
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

    void detectRemoveLoop()
    {
        node *slow=head;
        node *fast=head;
        while(fast!=NULL && fast->link!=NULL)
        {
            slow=slow->link;
            fast=fast->link->link;
            if(fast==slow)
            {
                cout<<"LOOP HAS BEEN DETECTED\n";
                break;
            }
        }
        if(slow!=fast)
        {
            cout<<"THERE IS NO LOOP\n";
            return;
        }
        slow=head;
        while(slow->link!=fast->link)
        {
            slow=slow->link;
            fast=fast->link;
        }
        fast->link=NULL;
        cout<<"LOOP HAS BEEN REMOVED\n";

    }
    void makeLoop()
    {
        node *slow=head;
        node *fast=head;
        while(fast->link!=NULL)
        {
            fast=fast->link;
        }
        int i=0;
        while(i<=3)
        {
            slow=slow->link;
            i++;
        }
        fast->link=slow;
    }
};

int main(void)
{
    linkedlist LL;
    LL.insertBeg(30);
    LL.insertBeg(40);
    LL.insertBeg(80);
    LL.insertBeg(10);
    LL.insertBeg(20);
    LL.insertBeg(40);
    cout<<"INTIALLY\n ";
    LL.detectRemoveLoop();
    LL.makeLoop();
    cout<<"AFTER\n";
    LL.detectRemoveLoop();

}
