
#include<iostream>
using namespace std;

struct tbt
{
	int data;
	int lbit,rbit;
	struct tbt *left,*right;
	friend class thread;
};


class thread
{
	private:
		tbt *headernode, *root, *temp;
	public:
		thread()
		{
			root=headernode=temp=NULL;
		}
	void create();  
	tbt* createNode(); 
	void display();
	void insert(tbt*,tbt*);  
	void inorder(tbt*,tbt* ); 
	void preorder(tbt*,tbt* ); 
 };




tbt * thread::createNode()
{
	tbt* tmpNode =NULL;	
	tmpNode=new tbt;
	tmpNode->left= tmpNode->right=NULL;
	tmpNode->lbit= tmpNode->rbit=1;
	cout<<"\n Enter Data ";
	cin>>tmpNode->data;

	return tmpNode;
}




void thread::create() 
{
	tbt* temp = createNode();
	if(root==NULL)
	{
		root=temp;
		headernode=new tbt;
		headernode->data = -999;
		headernode->left=root;
		headernode->right = headernode;
		root->left=headernode;
		root->right=headernode;
	}
	else
		insert(root,temp);
}



void thread::display()
{
	if(root==NULL)
		cout<<"Tree is Empty";
	else
	{
		cout<<"\n The Tree is : ";
		cout <<"\n Inorder :";
		inorder(root,headernode);
		cout <<"\n Preorder :";
		preorder(root,headernode);

	}
}



void thread::insert(tbt *Lroot,tbt *temp)
{
	if(temp->data<Lroot->data)//Left Subtree
	{
		if(Lroot->lbit==1)
		{
			temp->left=Lroot->left;
			temp->right=Lroot;
			Lroot->left=temp;
			Lroot->lbit=0;
		}
		else
			insert(Lroot->left,temp); 
	}

	if(temp->data>Lroot->data)//Right Subtree
	{
		if(Lroot->rbit==1)
		{
			temp->right=Lroot->right;
			temp->left=Lroot;
			Lroot->rbit=0;
			Lroot->right=temp;
		}
		else
			insert(Lroot->right,temp);
	}
}


void thread :: inorder(tbt *temp,tbt *headernode){
	while(temp!=headernode)
	{
		while(temp->lbit==0) { temp=temp->left; }
		cout<<"  "<<temp->data;   
		while(temp->rbit==1)
		{
			temp=temp->right;   	
			if(temp==headernode) return;
			cout<<"  "<<temp->data;
		}
		temp=temp->right;     		
	}
}



void thread :: preorder(tbt *temp,tbt *headernode)
{
	while(temp!=headernode)
	{
		cout<<"  "<<temp->data;  
		while(temp->lbit==0) { temp=temp->left; cout << "  "<<temp->data; }
							
		while(temp->rbit==1)
		{
			temp=temp->right;   	
			if(temp==headernode)
				return;
		}
		temp=temp->right;     	
	}
}

int main()
{
   int choice;
   char ch='y';
   int n;
   thread th; 
   do
   {
            cout<<"\n\t Threaded Binary Tree";
            cout<<"\n1.Create \n2.Display \n";
            cin>>choice;
            switch(choice)
            {
              case 1:do
                                    {
                                      th.create();
                                       cout<<"\n Enter more data:(y/n) ";
                                       cin>>ch;
                                       }while(ch=='y');

                                    break;
             case 2:
            	 	 	 th.display();
                                    break;

            }
   cout<<"\n\n Do you want to continue with main menu?(y/n)";
   cin>>ch;
   }while(ch=='y');
}


