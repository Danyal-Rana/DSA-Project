#include <iostream>
using namespace std;

class que{
	public:
		int size;
		int *q;
		int front;
		int rear;

	que(){
		size = 10;
		q = new int[size];
		front =-1;
		rear = -1;
	}
	que(int x){
		size =x;
		q = new int[size];
		front = -1;
		rear = -1;
	}
	bool is_empty(){
		if(front == -1)
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
	void display(){
		if(is_empty()){
			cout<<"\n queue is empty";
		}else {
			for(int i=front;i<=rear;i++){
				cout<<"\n Value at index "<<i<< " is: "<<q[i];
			}
		}
	}
	void enqueue_rear(int x){
		if(is_full()){
			cout<<"\nQueue is full";
		}
		else{
			if(is_empty()){
				front=rear=0;
				q[rear]=x;
			}else{	
				
				int mrear=rear;
				if(q[mrear]>x){
					while(q[mrear]>x){
					q[mrear+1]=q[mrear];
					mrear=mrear-1;	
						if(mrear ==-1){
							break;
						}
					}
					q[mrear+1]=x;
					rear = rear + 1;
				}else{
				rear = rear+1;
				q[rear]=x;
				}
			}
			
		}
}

	int dequeue(){
		if(is_empty()){
			cout<<"\nQueue is empty";
			return -1;
		}else{
			int x = q[front];
			if(front==rear){
				front=rear=-1;
			}else
				front=(front+1) % size;
			return x;
		}
	}
};




