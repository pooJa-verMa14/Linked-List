//WAP to remove all prime numbers from the list

#include<iostream>
#include<cmath>
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

    bool isprime(int n)
    {

        if (n <= 1)
            return false;
    
        if (n <= 3)
            return true;
    
        // This is checked so that we can skip
        // middle five numbers in below loop
        if (n % 2 == 0 || n % 3 == 0)
            return false;
    
        for (int i = 5; i * i <= n; i = i + 6)
            if (n % i == 0 || n % (i + 2) == 0)
                return false;
    
        return true;

    }

    void delete_prime()
    {
        node *curr=head;
        node *prev=head;
        while(curr!=NULL)
        {
            if(isprime(curr->data))
            {
                node *temp=curr;
                prev->link=curr->link;
                curr=curr->link;
                delete temp;
            }
            else
            {
                prev=curr;
                curr=curr->link;
            }
    
        }
    }

    

    
};    

int main(void)
{
    linkedlist LL;
    LL.insertBeg(10);
    LL.insertBeg(3);
    LL.insertBeg(16);
    LL.insertBeg(20);
    LL.insertBeg(4);
    LL.insertBeg(2);
    LL.insertBeg(1);
    cout<<"INTIALLY LINKED LIST IS\n";
    LL.display();
    cout<<"AFTER\n";
    LL.delete_prime();
    LL.display();
    
}

