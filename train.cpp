#include "train.h"
#include <iostream>
#include "waggon.h"
#include <ctime>
#include <cstdlib>

using namespace std;

/*addFine*/
void train::addFine(void){
	money+=1; //add 1 euro if the fine is 1 euro
}

/*constructor*/ 
train::train(int n,int waggons,int numberOfMaxPeople){
	int i;
	N=n;
	totalWaggons=waggons;
	money=0;
    array=new waggon*[totalWaggons]; //make an array of pointers to waggons
    for(i=0;i<totalWaggons;i++) //for every pointer 
     array[i]=new waggon(numberOfMaxPeople); //make a waggon 
    cout<<"A metro train with "<<totalWaggons<<" waggons, was created."<<endl; 
}

/*destructor*/
train::~train(){
	int i;
	for(i=0;i<totalWaggons;i++) //for every waggon in the array
     delete array[i]; //delete the waggon
    delete[] array; 
    array=NULL; //make array point to null
    cout<<"A metro train was destroyed."<<endl;
}

/*randomcheck*/
int train::randomCheck(int*& waggons){
  int randomNumber=rand()%(totalWaggons+1); //the number of waggons that will be checked
  waggons=new int[randomNumber];
  int i;
   for(i=0;i<randomNumber;i++){
     waggons[i]=rand()%totalWaggons; //the indexes of the waggons that will be checked
   }
   /*cout<<"The indexes of the waggons that will be checked are: ";
    for(i=0;i<randomNumber;i++){
     cout<<waggons[i]<<" "; //the indexes of the waggons that will be checked
   }
   cout<<endl;
   */
   return(randomNumber); 
}

/*getWaggon*/
waggon** train::getWaggon(void){
	return(array); //return the array of waggons
}

/*operate*/
void train::operate(void){
	int i,j,k;
	int *AllWaggons; //a pointer to the array of waggons in the train that will be checked (which waggons)
	int randomNumber; //the size of the waggon array (how many waggons)
	
	for(i=0;i<N;i++){ //for every station we should: 
	  randomNumber=randomCheck(AllWaggons); //determine which waggons are going to be checked
	 //we have to mark the waggons as "chosen"
	  for(k=0;k<randomNumber;k++){
	   if(array[AllWaggons[k]]->getChosen()==1) //if the waggon that has been chosen has chosen=1
	     continue; 						  //continue to the next loop
	   else
	     array[AllWaggons[k]]->setChosen(); //set the member chosen to 1
       }
		for(j=0;j<totalWaggons;j++){ 
		 inStation(i,j);
		}
	}
	delete[] AllWaggons;
	AllWaggons=NULL;
	printStatistics();
}

/*inStation*/
void train::inStation(int station,int j){ 
	cout<<endl<<"<---In station "<<station<<" waggon "<<j<<"-->"<<endl;
	if(station==0){ //if it is the first station
	array[j]->getOn(); //get on
	cout<<"The number of passengers who got on are:"<<array[j]->getNumberOfPassengers()<<endl; //debug
	betweenStation(j); //check for tickets	
	array[j]->kickOff(); //get the violators off 
	array[j]->getOff(); //get off
	cout<<"The number of passengers now are:"<<array[j]->getNumberOfPassengers()<<endl;
	
   }
   else if(station==N-1) //if it is the last station
   { 
   	cout<<"Last station. All passengers will get off."<<endl; 
    array[j]->getAllOff(); //get all the passenger off
  }
   else { //if it is a middle station then
   cout<<"The number of passengers are:"<<array[j]->getNumberOfPassengers()<<endl; //debug
   	array[j]->kickOff(); //get the violators off
   	array[j]->getOff(); //get off
	array[j]->getOn(); //get on 
	 cout<<"The number of passengers now are:"<<array[j]->getNumberOfPassengers()<<endl; //debug
	betweenStation(j); //check for tickets
   }
}

/*betweenStation*/
void train::betweenStation(int j){ //checks the passengers in waggon j for tickets
	array[j]->check(*this);
}

/*getMoney*/
int train::getMoney(void){
	return(money); //return the money member
}

/*printStatistics*/
void train::printStatistics(void){
	int i;
	cout<<endl;
	for(i=0;i<totalWaggons;i++){
		cout<<"For the waggon "<<i+1<<":"<<endl;
		array[i]->printStatistics();
		cout<<endl;
	}
	cout<<"The total money that the train collected were:"<<money<<endl<<endl;
}





