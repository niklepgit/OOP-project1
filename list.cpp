#include "list.h"
#include "waggon.h"
#include <cstdlib>

/*----------ListNode----------*/

/*constructor*/
listNode::listNode(void){
	next=NULL;
}

/*destructor*/
listNode::~listNode(){
	next=NULL;
}

/*setNext*/
void listNode::setNext(listNode* node){
	next=node; //set the next member in listNode
}

/*getNext*/
listNode* listNode::getNext(void){
	return(next);
}

/*getPassenger*/
passenger& listNode::getPassenger(void){
	return(Passenger); //return the Passenger member
}






