#ifndef _ESPORTS_EVENT_H_
#define _ESPORTS_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "EsportsTicket.h"

/**
* EsportsEvent is derived from Event
*/
class EsportsEvent : public Event
{
    private:
	std::list<std::string> arena; // Data structure for containing the event goers in this baseball event
	std::string Team1; // Contains the name of team1
	std::string Team2; // Contains the name of team2

	/**
	* Constructor for creating an EsportsEvent
	*/
	EsportsEvent(std::string TeamOne, std::string TeamTwo): Team1(TeamOne), Team2(TeamTwo){}

	friend class EventFactory;

public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket * add(std::string name) {

		arena.push_front(name); // Adds name of person to front of arena list
		std::list<std::string>::iterator eventGoer = arena.begin(); // Creates and sets an iterator pointer to the front of arena list
		return new EsportsTicket(this, eventGoer); // Creates new EsportsTicket and returns it
	}

	/**
	* Shows the event's Team One and Team Two, then lists all the persons currently attending the event
	*/
	void list() {
		std::cout << "Team One: " << Team1 << "\n"; // Displays team one's name
		std::cout << "Team Two: " << Team2 << "\n"; // Displays team two's name
		std::cout << "List of eventGoers: \n"; // List of people attending
        for (std::list<std::string>::iterator i = arena.begin(); i != arena.end(); i++){ // Iterates through the arena list
			std::cout << *i << std::endl; // Displays the name of the person at the iterator location
		}
	}

	/**
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it) {
		arena.remove(*it); // Person at iterator location is removed from arena list
	}

	/**
	 * Have Esports game attendees cheer for thier team
	 */
	void cheer() {
		std::cout << "\tThere was just an amazing play!" << std::endl;
		for (std::list<std::string>::iterator i = arena.begin(); i != arena.end(); i++) {
			std::cout << "\t\t" << *i << " stands up and cheers for their team!" << std::endl;
		}
	}
};

#endif