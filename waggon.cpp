#include <cstdlib> //because we need rand();
#include <ctime> //because we need time();
#include "waggon.h"
#include <iostream>
#include "passenger.h"
#include "train.h"
#include "list.h"

using namespace std;

/*getOn*/
void waggon::getOn(void){
	int i;
	int number=rand()%(maxCapacity-numberOfPassengers+1); //the number of people who get on
	numberOfPassengers+=number; //add the passengers
	for(i=0;i<number;i++){ //do the following number times
	 listAddAtStart(Info); //create the passenger and add them to the waggon
	}
}

/*getOff*/
void waggon::getOff(void){

	int i;
	if(numberOfPassengers==0)
	 return;
	int number=rand()%numberOfPassengers; //the number of people who get off
    cout<<"The number of the people that randomly will get off the waggon are:"<<number<<endl;
	numberOfPassengers-=number; //take away the passengers
	int cc=0; //counter debug
	for(i=0;i<number;i++){      /////////number
	 cc++;
     listDelete(Info,NULL);//delete the people
	}
		//cout<<"in GetOff "<<cc<<" people got off."<<endl;
		
}

/*getAllOff*/
void waggon::getAllOff(void){

	int i;
	if(numberOfPassengers==0)
	 return;
	for(i=0;i<numberOfPassengers;i++){
	 listDelete(Info,NULL);//delete the people
	}
}

/*kickOff*/
void waggon::kickOff(void){

	int i,counter=0;
	listNode *ptr,*temp;
	int kick;
	ptr=Info;
	for(i=0;i<numberOfPassengers;i++){ //for every passenger
	 passenger& pass=ptr->getPassenger(); //get passenger
	 kick=pass.getKickOff(); //take the kick member
	  if(kick==1){ //if kick==1
	  	temp=ptr->getNext(); //save the address of the next passenger
	   listDelete(Info,ptr);//delete the current pasenger
	   counter++; //increase the counter
	   ptr=temp; //ptr now points to temp passenger
	   }
	   else //if kick==0
	  	ptr=ptr->getNext(); //get next listNode(passenger)
	}
	cout<<"The people that were caught and got off are "<<counter<<endl;
	numberOfPassengers-=counter; //decrease the number of passengers
}

/*check*/
void waggon::check(train& Train){
		//cout<<"The waggon is being Checked."<<endl;
	int i;    
	passenger temp;
    listNode* pass=Info;
	for(i=0;i<numberOfPassengers;i++){ //for every passenger
		passenger& Passenger=pass->getPassenger(); //take the passenger
		if(Passenger.getTicket()==0) //if the passenger doesn't have ticket
		 if(chosen==0) //if the waggon hasn't been chosen for ckeck
		 {
		  lucky++; //increase the lucky people of the waggon	 
	     }
		 else{      //if the waggon has been chosen for check		 
		  Train.addFine(); //add the money to the train
		  violators++; //increase violators by one
		  Passenger.setKickOff(); //in the next stop he has to get off
	     }
	 pass=pass->getNext(); //get next passenger	  
	}
	cout<<"The train has stopped."<<endl;
}

/*constructor*/
waggon::waggon(int maxcapacity){
	chosen=0;
	numberOfPassengers=0;
	violators=0;
	lucky=0;
	maxCapacity=maxcapacity;
	checked=0;
	Info=NULL;
	cout<<"A waggon with capacity for "<<maxCapacity<<" passengers, was created."<<endl;
}

/*destructor*/
waggon::~waggon(){
	if(Info!=NULL)
		delete Info;
	Info=NULL;
	cout<<"A waggon was destroyed."<<endl;
}

/*accessors*/
void waggon::setChosen(void){
	chosen=1; //set chosen member to 1
}

/*mutators*/

/*getChecked*/
int waggon::getChecked(void){
	return(checked); //return the checked member
}

/*getChosen*/
int waggon::getChosen(void){
	return(chosen); //return the chosen member
}

/*getLucky*/
int waggon::getLucky(void){
	return(lucky); //return the lucky member
}

/*getViolators*/
int waggon::getViolators(void){
	return(violators); //return the violators member
}

/*printStatistics*/
void waggon::printStatistics(void){
	cout<<"The violators were:"<<violators<<endl;
	cout<<"The lucky ones were:"<<lucky<<endl;
}

/*getNumberOfPassengers*/
int waggon::getNumberOfPassengers(void){
	return(numberOfPassengers);
}

/*ADD AT START*/

void waggon::listAddAtStart(listNode *&pointer){
	listNode *temp;
	
	if(pointer==NULL) //if the list is empty
	 pointer=new listNode; //make a listNode
	else{				 //else 
	 temp=new listNode; //make a temporary listNode
	 temp->setNext(pointer); //make this temp listNode points to the first listNode
	 pointer=temp; //change the pointer in the infoNode to point to temp listNode
    }
}

/*LIST DELETE*/

void waggon::listDelete(listNode*& ptr,listNode* nodePointer){
	listNode *temp=ptr,*start=ptr; 
	int flag=0;
	if(nodePointer!=NULL){
		while(ptr!=nodePointer){
			temp=ptr;
			ptr=ptr->getNext();
			flag=1;	
		}
		if(!flag){
			temp=ptr->getNext();
			delete ptr;
			ptr=temp;
		}
		else{
		
		temp->setNext(ptr->getNext());
		delete ptr;
		ptr=start;
		}
	}
	else{
		temp=ptr->getNext(); //temp pointer points to the second listNode
	    delete ptr; //delete the first listNode
	    ptr=temp; //pointer in the infoNode now points to the new first listNode
	}
}
