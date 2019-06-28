#ifndef _WORLDCUP_EVENT_H_
#define _WORLDCUP_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "WorldcupTicket.h"

/**
* WorldcupEvent is derived from Event
*/
class WorldcupEvent : public Event
{
private:
	std::list<std::string> stadium; // Data structure for containing the event goers in this worldcup event
	std::string hometeam; // Contains the name of the home team 
	std::string visitingteam; // Contains the name of the visiting team 

	/**
	* Constructor for creating a WorldcupEvent
	*/
	WorldcupEvent(std::string home, std::string visiting): hometeam(home), visitingteam(visiting){}

	friend class EventFactory;

public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket * add(std::string name) {
		stadium.push_front(name); // Adds the name to the front of the stadium
		std::list<std::string>::iterator eventGoer = stadium.begin(); // Sets an iterator that points the the front of the stadium list
		return new WorldcupTicket(this, eventGoer); // Creates a new WorldcupTicket and returns it
	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		std::cout << "Home Team: " << hometeam << "\n"; // Displays the name of the home team
		std::cout << "Visiting Team: " << visitingteam << "\n"; // Displays the name of the visiting team
		std::cout << "List of eventGoers: \n"; // Displays eventgoers
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++){ // Iterates through the stadium list
			std::cout << *i << std::endl; // Displays the name of the person the iterator is pointing at
		}
	}

	/**
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it) {
		//std::cout << *it << " has been asked to leave.\n";
		stadium.remove(*it); // removes the person iterator it is pointing at
	}

	/**
	 * Have world cup attendees chant
	 */
	void chant() {
		std::cout << "\tThe crowd has started to chant!" << std::endl;
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) { // Iterates through the stadium list
			std::cout << "\t\t" << *i << " says 'boom boom clap!'" << std::endl; // Displays what the person does
		}
	}
};
#endif