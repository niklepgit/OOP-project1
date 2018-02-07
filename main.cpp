#include <iostream>
#include <cstdlib> //because i need rand();
#include <ctime> //because we need time();
#include "train.h"
#include "passenger.h"
#include "waggon.h"
#include "list.h"

using namespace std;


int main(int argc, char** argv){
	
	int numberOfStations=atoi(argv[1]); //number of stations given by the command line
	int numberOfWaggons=atoi(argv[2]); //the number of waggons that will have the train
	int numberOfMaxPeople=atoi(argv[3]); //the max number of people in every waggon
	srand(time(NULL));

	
	train *Train=new train(numberOfStations,numberOfWaggons,numberOfMaxPeople); //make the train dynamically and call the constructor
	Train->operate();
	delete Train;

	
	return 0;
}
