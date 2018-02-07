#ifndef WAGGON
#define WAGGON
class listNode;
class train;   //forward declaration of class train because we 
			  //use it in method check
			  
class waggon{
	
	private:
		int maxCapacity; //the max capacity of the passengers
		int numberOfPassengers; //the number of passengers who are in the waggon
		int violators; //the number of passengers who didn't have a ticket and got caught
		int lucky; //the number of passengers who didn't have a ticket but didn't get caught
		char chosen; //1 if the waggon has been chosen for the check else 0 
		char checked; //1 if the waggon is checked else 
	    listNode *Info; //pointer to the first node of the list
		
	public:
		waggon(int); //constructor
		~waggon(); //destructor
		
		void printStatistics(void); //prints the statistics of the waggon
		void getOn(void); //how many people get on the waggon
		void getOff(void); //how many people get off the waggon
		void getAllOff(void); //get all the people off the waggon
		void kickOff(void); //get the violators off the waggon
		void check(train&); //checks the passengers for their tickets
		
		/*accessors*/
		void setChosen(void); //set the chosen member
				
		/*mutators*/
		int getChecked(void); //return the checked member
		int getChosen(void); //return the chosen member
		int getViolators(void); //return the violators member
		int getLucky(void); //return the lucky member
		int getNumberOfPassengers(void); //return the number of passengers in the waggon
		
		void listDelete(listNode*& ptr,listNode* nodePointer=NULL); //delete the random passengers that will get off
		void listAddAtStart(listNode *&ptr); //new the passengers that will get on 
		
};
#endif