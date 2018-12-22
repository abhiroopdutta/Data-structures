#include<iostream>
#include<queue>
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;

};

queue<node*> s; 

class bst
{

	public:
		node *root;

	bst()
	{
		root = NULL;
	}

	//insertion
	node *newnode(int n)
	{
		
		node *temp = new node;
		temp->data = n;
		temp->left = NULL;
		temp->right = NULL; 
		return temp;
	}


	node *insert(node *p, int n)
	{
	
		if(p == NULL)
		{	
			
			p = newnode(n); 
			

		}
 
		else if(n <= p->data)
			 p->left = insert(p->left, n);
			


		else if(n > p->data)
			 p->right = insert(p->right, n);
			
		
		return p;	
	}


	//searching
	bool search(node *p, int n)
	{
		
		if(p == NULL)
		{
			cout<<"empty tree"<<endl;
			return false;
		}

		else if(p->data == n)
			return true;
		

		else if( n > p->data)
				return search(p->right, n);
			

		else if( n <= p->data)
			return search(p->left, n);
			
	}

	//minimum element in bst
	int recursive_min(node *p)
	{
		if(p == NULL)
		{
			cout<<"tree is empty"<<endl;
			return -1;
		}

		else if(p->left == NULL)
		return p->data;

		else
		return recursive_min(p->left) ;

	}


	int min(node *p)
	{

		if( p== NULL)
		{
			cout<<"tree is empty"<<endl;
			return -1;
		}


		while( p->left != NULL)
		p = p->left;

		return p->data;
	}

	
	//height of bst
	int max(int a, int b)
	{
		return (a>=b?a:b) ;
	}

	int height(node *p)
	{
		if( p == NULL)
		{
			
			return -1;
			
		}
		else
		{
			int h = max( height(p->left), height(p->right) ) + 1 ;
			return h;
		}
	}

	//traversal
	void bfs(node *p)
	{	
		if(p == NULL)
		{
			cout<<"empty tree"<<endl;
			return;
		}

		queue<node*> q;

		q.push(p);

		while(!q.empty())
		{
			node *temp = q.front();
			cout<< temp->data <<endl;

			if(temp->left != NULL) 
			q.push(temp->left);
			if(temp->right != NULL) 
			q.push(temp->right);
			q.pop();

		}


		

	}
	
	void dfs(node *p)
	{
		if(p == NULL)
		return;

		cout<<p->data<<endl;
		dfs(p->left);
		dfs(p->right);
	}
	

	//check if bt is bst or not
	bool is_subtree_lesser(node *p, int n)
	{
		if(p == NULL)
		return true;

		else if
		(
			(p->data <= n) &&
			is_subtree_lesser(p->left, n) &&
			is_subtree_lesser(p->right, n)
			
		)
		return true;

		else
		return false;	

	}


	bool is_subtree_greater(node *p, int n)
	{
		if(p == NULL)
		return true;

		else if
		(
			(p->data > n) &&
			is_subtree_greater(p->left, n) &&
			is_subtree_greater(p->right, n)
			
		)
		return true;

		else
		return false;	

	}

	bool is_bst(node *p) //not efficient
	{
		if(p == NULL)
		return true;

		else if
		(
			is_subtree_lesser(p->left, p->data) && 
			is_subtree_greater(p->right, p->data) &&
			is_bst(p->left) &&
			is_bst(p->right)
		
		)	
		return true;


		else
		return false;

	}


	bool is_bst_1(int min, int max, node *p) //efficient
	{
		if(p == NULL)
		return true;

		else if
		( 
			(p->data <= max && p->data > min) &&
			is_bst_1(min, p->data, p->left) &&
			is_bst_1(p->data, max, p->right) 
		)
		return true;

		else
		return false;

	}


	//deleting a node
	node *find_min(node *p)//returns a pointer to the minimum node 
	{
		if(p->left == NULL)
		return p;

		else
		return find_min(p->left);

	}


	node *delete_node(node *p, int data)
	{
		if(p == NULL)
		return p;

		else if(data > p->data)
		p->right = delete_node(p->right,data); //as p->right may get changed
		//but delete node returns pointer to the new node or NULL, which is in the place of the deleted node
		//so we update p->right with this new pointer returned by delete_node

		else if(data < p->data)
		p->left = delete_node(p->left,data);

		else if(data == p->data)
		{
			//case 1: if node doesn't have any children
			if( (p->left == NULL) && (p->right == NULL) )
				{
					delete p;
					p = NULL;
					return p;
				}

			//case 2: if node has one child, either left or right
			else if(p->left == NULL)
				{
					node *temp = p;
					p = p->right;	
					delete temp;

				}

			else if(p->right == NULL)
				{
					node *temp = p;
					p = p->left;
					delete temp;

				}	
		
		//case 3: if node has both children, then we dont delete the node,
		//instead we replace the data in the node with 
		//the minimum element from the right subtree of the node to be deleted
		//and delete the duplicate node in the right subtree
		//this is done to maintain the bst
		//instead of minimum of right subtree, maximum of left sub tree could also be used
		else 
			{
				node *temp = find_min(p->right); 
				//this function should return the pointer to the minimum node

				p->data = temp->data;
				 //replace the data in the node to be deleted with the min of right subtree

				p->right = delete_node(p->right, p->data);
				//delete the duplicate node in the right sub tree 
			}


		}	



	}


	//inorder successor
	node *find_node(node *p, int n)
	{
		
		if(p == NULL)
		{
			cout<<"empty tree"<<endl;
			return NULL;
		}

		else if(p->data == n)
			return p;
		

		else if( n > p->data)
			return find_node(p->right, n);
			

		else if( n <= p->data)
			return find_node(p->left, n);
			
	}

	//this should take O(h), h is height of tree
	node *inorder_successor(node *p, int data)
	{
		//first we need to find the node for which we have to find inorder successor
		node *current = find_node(p, data); //find_node returns a pointer to that node

		if(current == NULL)
		return NULL;

		//Case 1:if node has right subtree, inorder successor will be the minimum of the right subtree	
		if(current->right != NULL)
		return find_min(current->right);

		//Case 2:if node doesnt have a right subtree, inorder successor will be the nearest ancestor
		//for which the given node is in left subtree
		else
		{
			node *ancestor = p;
			node *successor = NULL;
			while(ancestor != current)
			{
				if(current->data < ancestor->data) //for this ancestor, the given node is in left subtree
					{
						successor = ancestor;   //so this ancestor could be the inorder successor
						ancestor = ancestor->left; //but we need the nearest ancestor, so keep searching
					}

				else
					ancestor = ancestor->right;	//	
			}


		}



	}

};


int main()
{

	bst object;
	node *root = NULL;
	
	root = object.insert(root,6);
	 
	object.insert(root,3);

	object.insert(root,8);
	 
	object.insert(root,2);

	object.insert(root,4);
	 
	object.insert(root,7);

	object.insert(root,9);

	root = object.delete_node(root, 4);

	object.dfs(root);
	

	
	if( object.search(root,5) == true )
		cout<<"element found"<<endl;
	else
		cout<<"element not found"<<endl;

	cout<<"the min element is "<< object.recursive_min(root)<<endl;	


	cout<<"the height of the tree is : " << object.height(root)<<endl;

	object.dfs(root);

	cout<<"1 for yes, 0 for no  "<< object.is_bst_1(-1000,1000,root)<<endl;
	
	return 0;
}