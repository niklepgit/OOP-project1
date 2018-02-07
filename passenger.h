#ifndef PASSENGER
#define PASSENGER

class passenger{
	
	private:
		int ticket; //1 if the passenger has ticket else 0
		int lowTicket; //1 if the passenger should has low ticket else 0
		int Kickoff; //1 if the passenger should get off the train else 0
	public:
		passenger(); //constructor

	
		int getTicket(void); //returns the ticket member
		int getLowTicket(void); //returns the lowTicket member
		int getKickOff(void); //return the Kickoff member
		void setKickOff(void); //set the Kickoff member to 1
		void printPassenger(void);
};
#endif