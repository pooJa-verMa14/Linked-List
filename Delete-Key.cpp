//Write a program to count the number of occurrences of a given key in a singly linkedlist and then 
//delete all the occurrences. For example, if given linked list is 1->2->1->2->1->3->1 and given key 
//is 1, then output should be 4. After deletion of all the occurrences of 1, the linked list is 2->2->3

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

    void search(int x)
    {
        if(head==NULL)
        {
            cout<<"LIST IS EMPTY\n";
            return;
        }
        int count=0;
        node *curr=head->link;
        node *prev=NULL;
        while(curr!=NULL)
        {
            if(curr->data==x)
            {
                node *temp=curr;
                prev->link=curr->link;
                curr=curr->link;
                delete temp;
                count++;
            }
            else if(head->data==x)
            {
                node *temp=head->link;
                head->link=NULL;
                delete head;
                head=temp;
                count++;
            }
            
            
            else
            {
                prev=curr;
                curr=curr->link;
            }
        }
        cout<<x<<" OCCOURS "<<count<<" TIMES IN THE LIST\n";
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
    LL.display();
    int key;
    cout<<"ENTER THE VALUE OF KEY\n";
    cin>>key;
    LL.search(key);
    cout<<"AFTER DELETING\n";
    LL.display();
    
    
}




