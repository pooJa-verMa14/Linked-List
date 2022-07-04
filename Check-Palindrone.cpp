//WAP to check if LL is palindrome or not

#include<iostream>
using namespace std;

struct node
{
    char data;
    node *link; 
    node (char x) //constructor for struct
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

    bool pallindrom()
    {
        if(head==NULL)
        {
            return true;
        }
        node *slow=head;
        node *fast=head;
        while(fast!=NULL && fast->link!=NULL)
        {
            slow=slow->link;
            fast=fast->link->link;
        }
        node *curr=slow->link;
        node *prev=NULL;
        while(curr!=NULL)
        {
            node *next=curr->link;
            curr->link=prev;
            prev=curr;
            curr=next;
        }
        slow->link=prev;
        node *curr1=head;
        node *check=slow->link;
        while(check!=NULL)
        {
            if(curr1->data!=check->data)
            {
                return false;
            }
            curr1=curr1->link;
            check=check->link;
        }
        return true;

    }
};

int main(void)
{
    linkedlist LL;
    LL.insertBeg('G');
    LL.insertBeg('F');
    LL.insertBeg('G');
    if(LL.pallindrom())
    {
        cout<<"YES PALLINDROME\n";
    }
}
