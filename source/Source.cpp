//Exam 2
//CS273
//Edited by: Jonathan Laughlin
//last edited: 6/28/19

/**
* CS-273 Exam 2 Summer 2018
* Who doesn't like sports ?!
*
* @authors Everyone!
*/
#include <iostream>
#include <string>
#include <typeinfo>
#include "Event.h"
#include "EventTicket.h"
#include "EventFactory.h"
#include <ctime>

using std::cout;
using std::endl;

const int EVENT_COUNT = 3;

int main()
{
	srand(time(NULL));
	Event* events[EVENT_COUNT]; //Create a worldcup match and a baseball game
	events[0] = EventFactory::factory("worldcup", "germany", "mexico"); // Create a worldcup match with the event factory
	events[1] = EventFactory::factory("baseball", "everett", "spokane"); // Creates a baseball game with the event factory
	events[2] = EventFactory::factory("esport", "TSM", "EnVyUs"); // Create a esports game with the event factory

	//Let's go through and test each one
	for (int i=0; i<EVENT_COUNT; i++) {
		// Let's add a couple of people to the match, and store their tickets in variables
		EventTicket *ticket1 = events[i]->add("Mike");
		EventTicket *ticket2 = events[i]->add("Jane");
		EventTicket *ticket3 = events[i]->add("Antonio");
		EventTicket *ticket4 = events[i]->add("Sue");
		EventTicket *ticket5 = events[i]->add("Emma");
		EventTicket *ticket6 = events[i]->add("Jake");

		if (typeid(WorldcupEvent) == typeid(*events[i]))
			cout << "\n\tThe following event is a Worldcup match." << endl; // display what event type it is
		if (typeid(BaseballEvent) == typeid(*events[i]))
			cout << "\n\tThe following event is a Baseball game." << endl; // display what event type it is
		if (typeid(EsportsEvent) == typeid(*events[i]))
			cout << "\n\tThe following event is an Esports game." << endl; // display what event type it is

		cout << "\nEvent before Jane leaves\n";
		events[i]->list(); // List the people currently at the event

		// Jane decides to leave the event. Darn! She was really fun to have around!
		ticket2->leave();

		if (typeid(WorldcupEvent) == typeid(*events[i]))
			dynamic_cast<WorldcupEvent*>(events[i])->chant(); // if event is worldcup game everyone chant
		
		if (typeid(BaseballEvent) == typeid(*events[i]))
			dynamic_cast<BaseballEvent *>(events[i])->stretch(); // if event is baseball everyone stretch
		
		if (typeid(EsportsEvent) == typeid(*events[i]))
			dynamic_cast<EsportsEvent *>(events[i])->cheer(); // if event is esports everyone cheers

		cout << "\nEvent after Jane leaves:\n";
		events[i]->list(); // List the people remaining
	}
}