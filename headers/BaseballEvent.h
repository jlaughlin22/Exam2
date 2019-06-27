#ifndef _BASEBALL_EVENT_H_
#define _BASEBALL_EVENT_H_

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "Event.h"
#include "BaseballTicket.h"

// FIXME 2: Create BaseballEvent and BaseballTicket to for good baseball games!
// FIXME 2a: Create a function stretch so that the attendees can stand up an stretch for the 7th inning
// FIXME 3: Update EventFactory::factory() to allow it to be the ONLY method for creating a BaseballEvent
/**
* BaseballEvent is derived from Event
*/
class BaseballEvent : public Event
{
    private:
	std::list<std::string> stadium; // Data structure for containing the event goers in this baseball event
	std::string hometeam;
	std::string visitingteam;

	/**
	* Constructor for creating a BaseballEvent
	*/
	BaseballEvent(std::string home, std::string visiting): hometeam(home), visitingteam(visiting){}
		/**
		 *  FIXME 1a:
		 *    store the home team and visiting team names
		 */
	friend class EventFactory;

public:

	/**
	* Add a person to the event
	* @param name the name of the event goer
	*/
	EventTicket * add(std::string name) {
		
		//* FIXME 1b:
		//*   Pseudo-code
		//*    1. add name to the front of stadium
		stadium.push_front(name);
		//*    2. get iterator to the front of the stadium (this points to the recently added event goer)
		std::list<std::string>::iterator eventGoer = stadium.begin();
		//*    3. create a new baseball ticket (BaseballTicket) with its constructor
		//*            Pass to the constructor "this" event, and the iterator from step 2
		//*    4. return this new event ticket
		return new BaseballTicket(this, eventGoer);

	}

	/**
	* Show the event's home team and visiting team, then list all the persons currently in the event
	*/
	void list() {
		// FIXME 1c: Show the event's home team and visiting team, then iterate through all the persons here.
		std::cout << "Home Team: " << hometeam << "\n";
		std::cout << "Visiting Team: " << visitingteam << "\n";
		std::cout << "List of eventGoers: \n";
        for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++){
			std::cout << *i << std::endl;
		}
	}

	/**
	* Remove the person identified by the iterator from the event
	*/
	void remove(std::list<std::string>::iterator it) {
		//FIXME 1d: someone's getting out of hand. Ushers have asked them to leave.
		stadium.remove(*it);
	}

	/**
	 * Have world cup attendees chant
	 */
	void stretch() {
        std::cout << "\tThe announcers has asked everyone to stand up and take a strech break.\n";
		for (std::list<std::string>::iterator i = stadium.begin(); i != stadium.end(); i++) {
			std::cout << '\t' << *i << " stands up and stretches." << std::endl;
		}
	}
};

#endif