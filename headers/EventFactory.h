//Exam 2
//CS273
//Edited by: Jonathan Laughlin
//last edited: 6/28/19

#ifndef _EVENT_FACTORY_H_
#define _EVENT_FACTORY_H_

#include <stdexcept>
#include <string>
#include "BaseballEvent.h"
#include "WorldcupEvent.h"
#include "EsportsEvent.h"

/**
* The Event Factory
* This class is used for making events!
*/
class EventFactory
{
public:

	/**
	* The factory method is the only way of making an event
	* Please see the main() function to understand how it works!
	*/
	static Event *factory(std::string type, std::string hometeam, std::string visitingteam) {
		if (type == "worldcup") {
			return new WorldcupEvent(hometeam, visitingteam); // Creates a worldcup match
		} 
		else if (type == "baseball") { 
			return new BaseballEvent(hometeam, visitingteam); // Creates a baseball game
		}
		else if (type == "esport") {
			return new EsportsEvent(hometeam, visitingteam); // Creates an esports game
		}  
		else
			throw std::invalid_argument("unknown type of event");
	}
};
#endif