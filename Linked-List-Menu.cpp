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
        cout<<x<<" HAS BEEN INSERTED AT THE BEGINING OF THE LIST\n";
    }

    void insertEnd(int x)
    {
        node *temp=new node(x);
        if(head==NULL)
        {
            head=temp;
            return ;
        }
        node *curr=head;
        while(curr->link!=NULL)
        {
            curr=curr->link;
        }
        curr->link=temp;
        cout<<x<<" HAS BEEN INSERTED AT THE END OF THE LIST\n";
    }

    void deleteBeg()
    {
        if(head==NULL)
        {
            cout<<"LIST IS EMPTY\n";
        }
        else
        {
            node *temp=head->link;
            head->link=NULL;
            delete head;
            head=temp;
            cout<<"FIRST ELEMENT OF THE LIST HAS BEEN DELETED\n";
        }
    }

    void deleteEnd()
    {
        if(head==NULL)
        {
            cout<<"LIST IS EMPTY\n";
            return ;
        }
        else
        {
            node *curr=head;
            while(curr->link!=NULL)
            {
                curr=curr->link;
            }
            delete curr->link;
            curr->link=NULL;
        }
    }

    void insertPos(int x,int pos)
    {
        node *temp=new node(x);
        if(pos==1)
        {
            temp->link=head;
            head= temp;
            return ;
        }
        node *curr=head;
        for(int i=1;i<=pos-2 && curr!=NULL;i++)
        {
            curr=curr->link;
        }
        if(curr==NULL)
        {
            return ;
        }
        temp->link=curr->link;
        curr->link=temp;
    }

    void insert_after(int x,int pos)
    {
        int i=search(pos);
        if(i==-1)
        {
            return;
        }
        else if(i==0)
        {
            cout<<"ELEMENT IS NOT IN THE LIST\n";    
        }
        else
        {
            insertPos(x,i);
        }
    }

    void deletePos(int pos)
    {
        if(pos==1)
        {
            deleteBeg();
            return ;
        }
        node *curr=head;
        for(int i=1;i<pos-1 && curr!=NULL;i++)
        {
            curr=curr->link;
        }
        if(curr==NULL)
        {
            return ;
        }
        node *temp=curr->link;
        curr->link=temp->link;
        temp->link=NULL;
        delete temp;
        temp=NULL;
    }

    int totalE()
    {
        if(head==NULL)
        {
            return 0;
        }
        node *curr=head;
        int i=0;
        while(curr!=NULL)
        {
            curr=curr->link;
            i++;
        }
        return i;
    }
    
    int search(int x)
    {
        if(head==NULL)
        {
            return -1;
        }
        int i=1;
        node *curr=head;
        while(curr!=NULL)
        {
            if(curr->data==x)
            {
                return i+1;
            }
            else
            {
                i=i+1;
                curr=curr->link;
            }
        }
        return 0;
    }
};

int main(void)
{
    linkedlist LL;
    int ch,x,pos,i;
   do
   {
       cout<<"**********MENU**************"<<endl;
        cout<<"| PRESS 0: TO PRINT LIST   |\n| PRESS 1: TO INSERT BEG   |\n| PRESS 2: TO INSERT END   |\n| PRESS 3: TO DELETE BEG   |\n| PRESS 4: TO DELETE END   |\n| PRESS 5: TO INSERT AT    |\n| PRESS 6: TO SEARCH       |\n| PRESS 7: TO DELETE AT    |\n| PRESS 8: TO TOTAL NODES  |\n| PRESS 9: TO EXIT         |\n";
        cout<<"****************************"<<endl;
        cout<<"Enter: ";
        cin>>ch;
        switch (ch)
        {
        case 0:
            LL.printlist();
            break;
        case 1:
            cout<<"ENTER THE VALUE THAT YOU WANT TO INSERT AT BEGIN\n";
            cin>>x;
            LL.insertBeg(x);
            break;    
        case 2:
            cout<<"ENTER THE VALUE THAT YOU WANT TO INSERT AT END\n";
            cin>>x;
            LL.insertEnd(x);
            break;
        case 3:
            LL.deleteBeg();
            break;            
        case 4:
            LL.deleteEnd();
            break;
        case 5:
            cout<<"ENTER THE VALUE THAT YOU WANT TO INSERT AT \n";
            cin>>x;
            cout<<"ENTER THE VALUE OF NODE\n";
            cin>>pos;
            LL.insert_after(x,pos);
            break; 
        case 6:
            cout<<"ENTER THE ELEMENT THAT YOU WANT TO SEARCH FROM THE LIST\n";
            cin>>x;
            i=LL.search(x);
            if(i==-1)
        {
            cout<<"LIST IS EMPTY\n";
        }
        else if(i==0)
        {
            cout<<"ELEMENT IS NOT IN THE LIST\n";    
        }
        else
        {
            LL.insertPos(x,i);
        }
            break;
        case 7:
            cout<<"ENTER THE POSTION OF NODE THAT YOU WANT TO DELETE FROM THE LIST\n";
            cin>>x;
            LL.deletePos(x);
            break; 
        case 8:
            x=LL.totalE();
            cout<<"TOTAL ELEMENTS IN YOUR LINKED LIST ARE "<<x<<endl;;
            break;             
        }
   } while (ch!=9);
   
}
