//WAP to reverse the ll in block of k nodes

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

void revGroup(int k)
    {
        node *curr=head;
        node *prevfirst=NULL;
        int flag=0;
        while(curr!=NULL)
        {
            node *first=curr;
            node *prev=NULL;
            int count =0;
            while(curr!=NULL && count<k)
            {
                node *next=curr->link;
                curr->link=prev;
                prev=curr;
                curr=next;
                count++;
            }
            if(flag==0)
            {
                head=prev;
                flag=1;
            }
            else
            {
                prevfirst->link=prev;
            }
            prevfirst=first;
        }
    }
};

int main(void)
{
    linkedlist LL;
    LL.insertBeg(50);
    LL.insertBeg(40);
    LL.insertBeg(30);
    LL.insertBeg(20);
    LL.insertBeg(10);
    LL.printlist();
    LL.revGroup(3);
    LL.printlist();
}
