#include <cstdlib> //because we need rand();
#include <ctime> //because we need time();
#include "passenger.h"

#include <iostream> //debug

using namespace std; //debug

//passenger's constructor
passenger::passenger(void){
	ticket=rand()%2; //initalize with a random 0 or 1
	lowTicket=rand()%2; //initalize with a random 0 or 1
	Kickoff=0; //initialize Kickoff with zero
}

/*accessors*/

/*getTicket*/
int passenger::getTicket(void){
	return(ticket); //returns the ticket member
}

/*getLowTicket*/
int passenger::getLowTicket(void){
	return(lowTicket); //returns the lowTicket member
}

/*getKickOff*/
int passenger::getKickOff(void){
	return(Kickoff); //return the Kickoff member
}

/*mutators*/

/*setKickOff*/
void passenger::setKickOff(void){
	Kickoff=1;
}

/*printPassenger*/
void passenger::printPassenger(void){
	cout<<ticket<<" "<<lowTicket<<" "<<Kickoff<<" "<<endl;
}