#ifndef TRAIN
#define TRAIN

class waggon; //forward declaration of class waggon because we 
			 //use it as a member in the class train

class train{
	
	private:
		int totalWaggons; //the total waggons that has the train
		int N; //the number of the stations 
		int money; //the money that the train collects
		waggon **array; //array of pointers to store the waggons
		
	public:
		train(int ,int ,int ); //constructor
		~train(); //destructor
		void printStatistics(void); //prints the statistics for the train
		void inStation(int ,int ); //the train has stopped in a station
		void betweenStation(int ); //the train is between two stations
		void addFine(void); //adds the fine for the violation
		int randomCheck(int*&); //determines which waggons are going to be checked
		waggon** getWaggon(void); //returns the waggon's array
		void operate(void); //the operation of train
		int getMoney(void); // return the money member
};
#endif