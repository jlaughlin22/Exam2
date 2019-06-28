#ifndef _BASEBALL_EVENT_H_
#define _BASEBALL_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "BaseballTicket.h"

/**
* BaseballEvent is derived from Event
*/
class BaseballEvent : public Event
{
private:
	std::list<std::string> stadium; // Data structure for containing the event goers in this baseball event
	std::string hometeam; // contains the home teams name
	std::string visitingteam; // contains the visiting teams name

	/**
	* Constructor for creating a BaseballEvent
	*/
	BaseballEvent(std::string home, std::string visiting): hometeam(home), visitingteam(visiting){}

	friend class EventFactory;

public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket * add(std::string name) {
		stadium.push_front(name); // add name to the front of the stadium
		std::list<std::string>::iterator eventGoer = stadium.begin(); // sets an iterator pointer to the front of the stadium
		return new BaseballTicket(this, eventGoer); // creates a new baseballTicket and retruns the new ticket
	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		std::cout << "Home Team: " << hometeam << "\n"; // Displays the home teams name
		std::cout << "Visiting Team: " << visitingteam << "\n"; // Displays the visiting teams name
		std::cout << "List of eventGoers: \n"; // Lists the people attending the event
        for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++){ // Iterate through the stadium list
			std::cout << *i << std::endl; // Displays name of person in list
		}
	}

	/**
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it) {
		stadium.remove(*it); //remove person from list of attendees
	}

	/**
	 * Have baseball game attendees stretch
	*/
	void stretch() {
        std::cout << "\tDue to it being the 7th inning, the announcers have asked everyone to stand up and take a strech break.\n";
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) { // Iterate through the list of people attending
			std::cout << "\t\t" << *i << " stands up and stretches." << std::endl; // Displays what person does
		}
	}
};

#endif