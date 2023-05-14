#include <iostream>
#include <time.h>
#include "Path.h"
#include "hospital.h"
#include "que.h"
#include "Firebrigade.h"
#include "policestation.h"
#include "tree.h"
#include "SSg.h"
using namespace std;

void handlecall();
void adminmenu();
void Call();
void Firebrig(string Sloc);
void policestat(string Sloc);
void SSgcalling(string Sloc);
void response();
void available();

hospital shifa;hospital medcentre;hospital rawal;hospital quaid;
Firebrigade fbrigade;Firebrigade pindifbrigade;
policestation islamabad;policestation sadaqabad;
que line;que type;
tree database;
SSg zarrar;

void Ambulance(string Sloc){
	convert w;
	cout<<"\nAmbulance needed at "<<Sloc<<endl;
	cout<<"\nSuggestion for Road ways to Hospital\n";
	int location =w.stringconversion(Sloc);
	Path p(location);
	p.dijkstra();
	p.display(0);
	p.display(15);
	p.display(11);
	p.display(20);
	string hospitalname;
	bool success = false;
	while(!success){
		cout<<"\nEnter Hospital to respond\n";
		cin>>hospitalname;
		int hospitalnum = w.stringconversion(hospitalname);
		if(hospitalnum==0){
			if(shifa.ambulance!=0){
				shifa.ambulance--;
				cout<<"\nAmbulance sended successfully\n";
				success = true;
			}else{
				cout<<"\nAll Ambulances are out for service\nSelect an other hospital\n";
				success = false;
			}
			
		}else if(hospitalnum==11){
			if(medcentre.ambulance!=0){
				medcentre.ambulance--;
				cout<<"\nAmbulance sended successfully\n";
				success = true;
			}else{
				cout<<"\nAll Ambulances are out for service\nSelect an other hospital\n";
				success = false;
			}
			
		}else if(hospitalnum==15){
			if(rawal.ambulance!=0){
				rawal.ambulance--;
				cout<<"\nAmbulance sended successfully\n";
				success = true;
			}else{
				cout<<"\nAll Ambulances are out for service\nSelect an other hospital\n";
				success = false;
			}
			
		}else if(hospitalnum==20){
			if(quaid.ambulance!=0){
				quaid.ambulance--;
				cout<<"\nAmbulance sended successfully\n";
				success = true;
			}else{
				cout<<"\nAll Ambulances are out for service\nSelect an other hospital\n";
				success = false;
			}
			
		}
	}
	handlecall();
}
void Firebrig(string Sloc){
	convert w;
	int typenumber = type.dequeue();
	if(typenumber==0){
		cout<<"\nFire brigade needed at "<<Sloc<<" Fire is local\n";
	}else{
		cout<<"\n03 Fire brigades needed at "<<Sloc<<" Fire is high\n";
	}
	int location =w.stringconversion(Sloc);
	Path p(location);
	p.dijkstra();
	p.display(9);
	p.display(19);
	string fstationname;
	bool success = false;
	while(!success){
		cout<<"\nEnter Firebrigade station to respond\n";
		cin>>fstationname;
		int fstationnum = w.stringconversion(fstationname);
		if(fstationnum==9){
			if(typenumber==0){
				if(fbrigade.firebrigade!=0){
					fbrigade.firebrigade--;
					cout<<"\n1 Firebrigade sended successfully";
					success = true;
				}else{
					cout<<"\nAll Firebrigade are out for service\nSelect an other Station\n";
					success = false;
				}
			}else{
				if(fbrigade.firebrigade!=0){
					int a=fbrigade.firebrigade;
					fbrigade.firebrigade=fbrigade.firebrigade-a;
					cout<<a<<" Firebrigade available are sended successfully";
					success = true;
				}else{
					cout<<"\nAll Firebrigade are out for service\nSelect an other Station\n";
					success = false;
				}
			}
			
			
		}else if(fstationnum==19){
			if(typenumber==0){
				if(pindifbrigade.firebrigade!=0){
					pindifbrigade.firebrigade--;
					cout<<"\n1 Firebrigade sended successfully\n";
					success = true;
				}else{
					cout<<"\nAll Firebrigade are out for service\nSelect an other Station\n";
					success = false;
				}
			}else{
				if(pindifbrigade.firebrigade!=0){
					int a=pindifbrigade.firebrigade;
					pindifbrigade.firebrigade=pindifbrigade.firebrigade-a;
					cout<<a<<" Firebrigade available are sended successfully";
					success = true;
				}else{
					cout<<"\nAll Firebrigade are out for service\nSelect an other Station\n";
					success = false;
				}
			}
		}
	}
	handlecall();
}
void policestat(string Sloc){
	convert w;
	int typenumber = type.dequeue();
	if(typenumber==0){
		cout<<"\n Police Bike squad needed at "<<Sloc<<endl;
	}else{
		cout<<"\n Police Mobile needed at "<<Sloc<<endl;
	}
	
	cout<<"\n Suggestion for Road ways to Police station\n";
	int location =w.stringconversion(Sloc);
	Path p(location);
	p.dijkstra();
	p.display(10);
	p.display(12);
	string pstationname;
	bool success = false;
	while(!success){
		cout<<"\nEnter Police station to respond\n";
		cin>>pstationname;
		int pstationnum = w.stringconversion(pstationname);
		if(pstationnum==10){
			if(typenumber==0){
				if(islamabad.bikesquad!=0){
				islamabad.bikesquad--;
				cout<<"\nBike squad sended successfully\n";
				success = true;
				}
				else{
					cout<<"\nBike squads  are out for service\nSelect an other Station\n";
					success = false;
				}
			}else{
				if(islamabad.pmobile!=0){
				islamabad.pmobile--;
				cout<<"Police mobile sended successfully\n";
				success = true;

				int  num;
				cout<<"\nEnter choices::\n 1 :SSGs needed\n 2 :SSGs not needed\n";
				cin>>num;
				if(num==1){
					SSgcalling(Sloc);
					
				}


				
				}else{
					cout<<"Police mobile are out for service\nSelect an other Station\n";
					success = false;
				}
			}
		}
		else if(pstationnum==12){
			if(typenumber==0){
				if(sadaqabad.bikesquad!=0){
				sadaqabad.bikesquad--;
				cout<<"\nBike squad sended successfully\n";
				success = true;
				}
				else{
					cout<<"\nBike squads  are out for service\nSelect an other Station\n";
					success = false;
				}
			}else{
				if(sadaqabad.pmobile!=0){
				sadaqabad.pmobile--;
				cout<<"\nPolice mobile sended successfully\n";
				success = true;
				int  num;
				cout<<"\nEnter choices::\n 1 :ssgs needed\n 2 : ssgs not needed";
				cin>>num;
				if(num==1){
					SSgcalling(Sloc);
					
				}
				}else{
					cout<<"\nPolice mobile are out for service\nSelect an other Station\n";
					success = false;
				}
			}
		}
	}
	handlecall();
}
void SSgcalling(string Sloc){
	convert w;
	cout<<"\n Suggestion for Road ways to SSG Unit\n";
	int location =w.stringconversion(Sloc);
	Path p(location);
	p.dijkstra();
	p.display(5);
	int ssgmen;
	cout<<"\nHow many ssgs  required :? \n";
	cin>>ssgmen;
	int a = zarrar.men;
	if(zarrar.men!=0){
		if(zarrar.men<ssgmen){
			zarrar.men = zarrar.men-a;
			cout<<"\n"<<a<<"Available ssg commandoes are sended succesfully: \n";
		}
		else {
		zarrar.men=zarrar.men-ssgmen;
		cout<<"\n"<< ssgmen <<"Available ssg commandoes are sended succesfully: \n";
		}
	}
	else {
		cout<<"\nNo ssgs avaliable all are out for operations\n";
	}
		handlecall();
}
void response(){
	cout<<"\n1:Check Ambulance\n2:Check FireBrigade\n3:Check PoliceAutomobiles\n4:Check SSG commadoes\n5:Admin menu\n";
	int ver;
	cin>>ver;
	switch(ver){
		case 1:
			if(shifa.ambulance!=3){
				cout<<3-shifa.ambulance<<"\nAmbulances of Shifa Hospital were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					shifa.ambulance=3;
					cout<<"\nReturned\n";
				}
			}
			if(medcentre.ambulance!=3){
				cout<<3-medcentre.ambulance<<"\nAmbulances of Medcentre Hospital were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					medcentre.ambulance=3;
					cout<<"\nReturned\n";
				}
			}
			if(rawal.ambulance!=3){
				cout<<3-rawal.ambulance<<"\nAmbulances of Rawal Hospital were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					rawal.ambulance=3;
					cout<<"\nReturned\n";
				}
			}
			if(quaid.ambulance!=3){
				cout<<3-quaid.ambulance<<"\nAmbulances of Shifa Hospital were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					quaid.ambulance=3;
					cout<<"\nReturned\n";
				}
			}response();
			break;
		case 2:
			if(fbrigade.firebrigade!=3){
				cout<<3-fbrigade.firebrigade<<"\nFirebrigade of Fbrigade were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					fbrigade.firebrigade=3;
					cout<<"\nReturned\n";
				}
			}
			if(pindifbrigade.firebrigade!=3){
				cout<<3-pindifbrigade.firebrigade<<"\nFirebrigade of Pindi were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					pindifbrigade.firebrigade=3;
					cout<<"\nReturned\n";
				}
			}response();
			break;
		case 3:
			if(islamabad.bikesquad!=3){
				cout<<3-islamabad.bikesquad<<"\nBikesquad of Islamabad policestation were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					islamabad.bikesquad=3;
					cout<<"\nReturned\n";
				}
			}
			if(islamabad.pmobile!=3){
				cout<<3-islamabad.bikesquad<<"\nPolice mobile of Islamabad policestation were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					islamabad.pmobile=3;
					cout<<"\nReturned\n";
				}
			}
			if(sadaqabad.bikesquad!=3){
				cout<<3-sadaqabad.bikesquad<<"\nBikesquad of sadaqabad policestation were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					sadaqabad.bikesquad=3;
					cout<<"\nReturned\n";
				}
			}
			if(sadaqabad.pmobile!=3){
				cout<<3-sadaqabad.bikesquad<<"\nPolice mobile of sadaqabad policestation were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					sadaqabad.pmobile=3;
					cout<<"\nReturned\n";
				}
			}response();
			break;
		case 4:
			if(zarrar.men!=20){
				cout<<3-sadaqabad.bikesquad<<"\nZarrar Commandoes were out for service and\n";
				srand( time(NULL) );
				int randNum = rand() % 2;
				if(randNum==0){
					cout<<"\nNot returned yet\n";
				}else{
					zarrar.men=20;
					cout<<"\nReturned\n";
				}
			}response();
			break;
		case 5:
			adminmenu();
			break;			
	}
}
void handlecall(){
	line.display();
	while(line.is_empty()!=true){
		int value = line.dequeue();
		if(value==1122){
			Ambulance(line.sdequeue());
		}else if(value==101){
			Firebrig(line.sdequeue());
		}else if(value==15){
			policestat(line.sdequeue());
		}
	}
	cout<<" \nAll Peace! No call!\n";
	adminmenu();
}
void available(){
	cout<<"Ambulances at Shifa hospital "<<shifa.ambulance<<endl;
	cout<<"Ambulances at Medical centre hospital "<<medcentre.ambulance<<endl;
	cout<<"Ambulances at Rawal hospital "<<rawal.ambulance<<endl;
	cout<<"Ambulances at Quaid e Azam hospital "<<quaid.ambulance<<endl;
	cout<<endl;
	cout<<"Firebrigade at Fbrigade "<<fbrigade.firebrigade<<endl;
	cout<<"Firebrigade at Pindi firebrigade "<<pindifbrigade.firebrigade<<endl;
	cout<<endl;
	cout<<"Police bikeSqaud at Islamabad PoliceStation "<<islamabad.bikesquad<<endl;
	cout<<"Police Mobile at Islamabad PoliceStation "<<islamabad.pmobile<<endl;
	cout<<"Police bikeSqaud at Sadaqabad PoliceStation "<<sadaqabad.bikesquad<<endl;
	cout<<"Police Mobile at Sadaqabad PoliceStation "<<sadaqabad.pmobile<<endl;
	cout<<endl;
	cout<<"SSGs commandos at station are "<<zarrar.men<<endl;
	adminmenu();
}

void adminmenu(){
	int num;
	cout<<"\n1:Handle calls\n2:See Operation response\n3:See all Calling record\n4:Check Available services\n5:Switch to User to side\n";
	cin>>num;
	switch(num){
		case 1:
			handlecall();
			break;
		case 2:
			response();
			break;
		case 3:
			database.inorder(database.root);
			adminmenu();
			break;
		case 4:
			available();
			break;
		case 5:
			Call();
			break;
	}
}
void Call(){
	int callnum;
	string Sloc;
	int typenum;
	cout<<"\nCALL \n1122 Ambulance\n101 Firebrigade\n15 Police station\n1:Switch to Admin portal\n";
	cin>>callnum;
	switch(callnum){
		case 1:
			adminmenu();
			break;
		case 15:
			cout<<"\nEnter accident location\n";
			cin>>Sloc;
			cout<<"\nChoose Seriousness\n0:City crime like Thief,Street fights\n1:High profile Crime like Terrorism\n";
			cin>>typenum;
			database.insert(Sloc,callnum);
			type.enqueue(typenum);
			cout<<"\nHelp is on the way\n";
			line.enqueue(15);
			line.senqueue(Sloc);
			Call();
			break;
		case 101:
			cout<<"\nEnter accident location\n";
			cin>>Sloc;
			cout<<"\nChoose Seriousness\n0:Home Fire,appartment fire\n1:High flames/ Buildings on fire\n";
			cin>>typenum;
			database.insert(Sloc,callnum);
			type.enqueue(typenum);
			cout<<"\nHelp is on the way\n";
			line.enqueue(101);
			line.senqueue(Sloc);
			Call();
			break;
		case 1122:
			cout<<"\nEnter accident location\n";
			cin>>Sloc;
			database.insert(Sloc,callnum);
			cout<<"\nHelp is on the way\n";
			line.enqueue(1122);
			line.senqueue(Sloc);
			Call();
			break;
		
	}	
}
int main(){
	Call();
}