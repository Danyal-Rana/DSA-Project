#include <iostream>
#include "convert.h"
using namespace std;

class Path{
	public:
	int v;
	int cost[100][100]={{0,2,3,999,999,995,996,997,998,999,9910,9911,912,913,914,915,916,917,918,919,920},
						{2,0,3,4,5,6,996,997,989,999,910,911,912,913,914,915,916,917,918,919,920},
						{3,3,0,4,999,995,5,2,998,999,910,911,912,913,914,915,916,917,918,919,920},
						{999,4,4,0,4,999,999,1,3,3,990,911,912,913,914,915,916,917,918,919,920},
						{999,5,999,4,0,7,999,999,999,1,3,1,912,913,914,915,916,917,918,919,920},
						{999,6,999,993,7,0,996,9997,989,999,999,2,912,913,914,915,916,917,918,919,920},
						{999,991,5,939,994,995,0,2,998,999,991,911,8,913,914,915,916,917,918,919,920},
						{999,991,2,1,994,995,2,0,3,6,919,911,4,9,914,915,916,917,918,919,920},
						{999,991,992,3,994,995,996,3,0,9,910,911,4,5,1,915,916,917,918,919,920},
						{999,991,992,3,1,995,996,6,9,0,4,911,912,913,1,4,916,917,918,919,920},
						{999,991,992,993,3,995,996,997,998,4,0,3,912,913,914,9,9,917,918,7,920},
						{999,991,992,939,1,2,996,979,998,999,3,0,912,913,914,915,1,917,918,919,920},
						{990,9991,992,993,994,959,8,4,4,999,910,911,0,9,914,915,916,1,918,919,920},
						{999,919,992,993,994,995,996,9,5,999,910,911,9,0,2,915,916,3,3,919,920},
						{999,919,992,993,994,995,996,997,1,1,910,911,912,2,0,3,916,917,4,919,2},
						{999,991,992,993,994,995,996,997,998,4,9,911,912,913,3,0,3,999,918,1,9},
						{999,991,992,993,994,995,996,997,998,999,9,1,999,913,914,3,0,917,918,5,999},
						{999,991,992,993,994,995,996,997,998,999,910,911,1,3,914,915,916,0,2,919,920},
						{990,991,992,993,994,995,996,997,998,999,991,911,912,3,4,915,916,2,0,919,1},
						{999,991,992,993,994,995,996,997,998,999,7,911,912,913,914,1,5,917,918,0,4},
						{999,991,992,993,994,959,999,999,998,999,991,911,912,913,2,9,916,917,1,4,0}
						};
	int src;
	int dist[100];
	int parent[100];
	bool visited[100]={0};
	
	Path(int src){
		v=21;
		src = src;
		
		for(int i=0;i<v;i++){
			parent[i]=i;
			dist[i] = 999;
		}
		dist[src]=0;
		parent[src]=-1;		
	}
	int getnearest(){
		int minvalue = 999;
		int minnode = 0;
		for(int i=0;i<v;i++){
			if(!visited[i] and dist[i]<minvalue){
				minvalue=dist[i];
				minnode=i;
			}
		}return minnode;
	}
	void dijkstra(){
		//int end =3;
		for(int i=0;i<v;i++){
			int nearest=getnearest();
			visited[nearest]=true;
			for(int adj = 0;adj<v;adj++){
				if(cost[nearest][adj]!=999 and dist[adj]>dist[nearest]+cost[nearest][adj]){
					dist[adj]=dist[nearest]+cost[nearest][adj];
					parent[adj]=nearest;
				}
			}
		}
	}
	void prims(){
		int total=0;
		for(int k=0;k<v;k++){
			int nearest=getnearest();
			visited[nearest]=true;
			for(int adj = 0;adj<v;adj++){
				if(cost[nearest][adj]!=999 and dist[adj]>dist[nearest]+cost[nearest][adj]){
					dist[adj]=cost[nearest][adj];
					parent[adj]=nearest;
				}
			}
		}for(int i =0 ;i < v ;i++){
	     //  int temp = parent[i] ; 
	       cout<<i << " -> "<< parent[i];
	    //   while(temp!=-1)
	//       {
	//           cout<< temp << " <- " ;
	//           temp = parent[temp] ; 
	//       }
	       cout<<endl; 
	       cout<<i << " -> "<< parent[i];
	       cout<<endl; 
	       total=total+dist[i];
	   }cout<<"Total "<<total; 
	}
	
	void display(int end){
			convert c ;
	       int temp = parent[end] ; 
	       cout<<c.intconversion(end) << " -> " ;
	       while(temp!=-1)
	       {
			   cout<< c.intconversion(temp) << " -> " ;
	           temp = parent[temp] ; 
	       }
	       cout<<endl; 
	       cout<<"::::Distance = " << dist[end] <<" KM " ; 
	       cout<<endl;  
	}
};
