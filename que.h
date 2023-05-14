#include <iostream>
using namespace std;

class que{
	public:
		int size;
		int *q;
		string *s;
		int front;
		int rear;
		int sfront;
		int srear;

	que(){
		size = 10;
		q = new int[size];
		s = new string[size];
		front =-1;
		rear = -1;
		sfront =-1;
		srear = -1;
	}
	que(int x){
		size =x;
		q = new int[size];
		s = new string[size];
		front = -1;
		rear = -1;
		sfront =-1;
		srear = -1;
	}
	bool is_empty(){
		if(rear==-1 && front == -1)
			return true;
		else
			return false;
	}
	bool is_sempty(){
		if(srear==-1 && sfront == -1)
			return true;
		else
			return false;
	}
	bool is_full(){
		if((rear+1)%size == front){
			return true;
		}else 
			return false;
	}
	bool is_sfull(){
		if((srear+1)%size == sfront){
			return true;
		}else 
			return false;
	}
	void display(){
		if(is_empty()){
			cout<<"\nQueue Empty"<<endl;
		}else {
			int r = front;
			while(r!=rear){
				cout<<"call at index "<<r<<" is "<<q[r]<<endl;
				r=(r+1)%size;
			}cout<<"Call at index "<<r<<" is "<<q[r]<<endl;
		}
	}
	int search(int key,string loc){
		if(is_sempty()){
			return 0;
		}else {
			int r = sfront;
			while(r!=srear){
			if(q[r]==key && s[r]==loc){
				return 1;
			}
			r=(r+1)%size;
			}
		}return 0;
	}
	void sdisplay(){
		if(is_sempty()){
			cout<<"";
		}else {
			int r = sfront;
			while(r!=srear){
				cout<<"Value at index "<<s[r];
				r=(r+1)%size;
			}
		}
	}
	void enqueue(int x){
		if(is_full()){
			cout<<"\nQueue is full";
		}
		else{
			if(is_empty()){
			front=rear=0;
			}else{
				rear = (rear + 1) % size;
			}q[rear] = x;
		}
	}
	void senqueue(string x){
		if(is_sfull()){
			cout<<"\nQueue is full";
		}
		else{
			if(is_sempty()){
			sfront=srear=0;
			}else{
				srear = (srear + 1) % size;
			}s[srear] = x;
		}
	}
	int dequeue(){
		if(is_empty()){
			cout<<"\n";
			return -1;
		}else{
			int x = q[front];
			if(front==rear){
				front=rear=-1;
			}else{
				front=(front+1) % size;
			}
			return x;
		}
	}
	string sdequeue(){
		if(is_sempty()){
			cout<<"\n";
			return "";
		}else{
			string x = s[sfront];
			if(sfront==srear){
				sfront=srear=-1;
			}else{
				sfront=(sfront+1) % size;
			}
			return x;
		}
	}
};



