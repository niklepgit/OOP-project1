
#ifndef LIST
#define LIST

#include <iostream>
#include "passenger.h"
#include "waggon.h"

using namespace std;

class listNode{ 
	private:
		passenger Passenger;
	    listNode *next;
	public:
		listNode(); //constructor
		~listNode(); //destructor
		/*accessors*/
		listNode* getNext(void); //return the next member of class listNode
		passenger& getPassenger(void); //return the passenger member
		/*mutators*/
		void setNext(listNode*); //set the next member
};								
#endif