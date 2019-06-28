//Exam 2
//CS273
//Edited by: Jonathan Laughlin
//last edited: 6/28/19

#ifndef _ESPORTS_TICKET_H_
#define _ESPORTS_TICKET_H_

#include <list>
#include <string>
#include "Event.h"
#include "EventTicket.h"

class EsportsTicket : public EventTicket
{
private:
	Event * the_event; // the event this ticket is associated with
	std::list<std::string>::iterator me; // an iterator containing the event goer this ticket is associated with

public:

	/**
	* Constructor for creating a BaseballTicket.  
	* @param the_event	event to which this ticket belongs
	* @param me			event goer to which this ticket is associated with
	*/
	EsportsTicket(Event *the_event, std::list<std::string>::iterator &me) :
		the_event(the_event), me(me) {}

	/**
	* Allows the event goer, "me", to leave the event, "the_event"
	* The implementation for this is in BaseballTicket.cpp
	*/
	void leave();
};

#endif