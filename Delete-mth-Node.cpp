//WAP to delete mth node from the last

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

    void del(int x)
    {
        node *frwd=head;
        node *curr=head;
        for(int i=0;i<=x;i++)
        {
            frwd=frwd->link;
            if(frwd==NULL)
            {
                return;
            }
        }
        while(frwd!=NULL)
        {
            curr=curr->link;
            frwd=frwd->link;
        }
        node *temp=curr->link;
        curr->link=temp->link;
        temp->link=NULL;
        delete temp;
        temp=NULL;

    }


    
};    

int main(void)
{
    int m;
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
    cout<<"ENTER THE VALUE OF m\n";
    cin>>m;
    LL.del(m);
    cout<<"AFTER REVERSING THE LINKED LIST\n";
    LL.display();
    
}

