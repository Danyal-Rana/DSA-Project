#include <iostream>
using namespace std;

class tree{
	public:
	double num;
	string name;
	string contactnum;
	string Location;
	int Callnum1;
	tree *left;
	tree *right;
	tree *root;
	tree(){
		 num=0;
		 name="";
		 contactnum="";
		 Location="";
		 Callnum1=0;
		 left = NULL;
		 right = NULL;
		 root = NULL;
	}

	void insert(string l,int c){
		tree *curr = new tree;
		cout<<"Enter your name\n";
		cin>>curr->name;
		cout<<"Enter your CNIC\n";
		cin>>curr->num;
		cout<<"Enter your Contact number\n";
		cin>>curr->contactnum;
		curr->Location=l;
		curr->Callnum1=c;
		if(root==NULL){
			root = curr;
		}else{
			tree *p = root;
			tree *k = p;
			while(p!=NULL){
				k=p;
				if(curr->num < p->num){
					p=p->left;
				}else{
					p=p->right;
				}
			}
			if(curr->num < k->num){
					k->left  = curr;
				}else{
					k->right = curr;
				}
			}
	
	}//when root has one branch
	void deletenode(int key){
		tree *p = root;
		tree *k = p;
			while(p->num!=key && p!=NULL){
				k=p;
				if(key<p->num){
					p=p->left;
				}else{
					p=p->right;
				}
			}
			if(p->left==NULL && p->right==NULL){
				if(k->left=p){
					k->left=NULL;
				}else{
					k->right=NULL;
				}
			}else if(p->left==NULL or p->right==NULL){
				if(k->left==p && p->right==NULL){
					k->left=p->left;
				}else if(k->left==p && p->left==NULL){
					k->left = p->right;
				}else if(k->right==p && p->left==NULL){
					k->right = p->right;
				}else if(k->right==p && p->right==NULL){
					k->right = p->left;
				}
			}else{
				tree *p2 = p->right;
				if(p2->left==NULL){
					p->num=p2->num;
					p->right=p2->right;
				}else{
					while(p2->left!=NULL){
						k=p2;
						p2=p2->left;
					}
					p->num=p2->num;
					k->left=NULL;
				}
			
			}
	}
	void inorder(tree *p){
		if(p!=0){
			inorder(p->left);
			cout<<"Call Number "<<p->Callnum1<<endl;
			cout<<"Name "<<p->name<<endl;
			cout<<"Location "<<p->Location<<endl;
			cout<<"Contact Number "<<p->contactnum<<endl;
			inorder(p->right);
		}
	}
	int search(tree *p,string loc){
		if(p!=0){
			inorder(p->left);
			if(p->Location==loc){
				return 1;
			}
			inorder(p->right);
		}return 0;
	}
};

//int main(){
//	insert();
//	inorder(root);
//	int num;
//	cout<<"\nEnter num to delete";
//	cin>>num;
//	deletenode(num);
//	inorder(root);
//}