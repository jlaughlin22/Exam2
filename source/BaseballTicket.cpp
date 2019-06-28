//Exam 2
//CS273
//Edited by: Jonathan Laughlin
//last edited: 6/28/19

#include "BaseballTicket.h"
#include "BaseballEvent.h"

/**
* Implements the leave method
*/
void BaseballTicket::leave() {
	BaseballEvent * actual_event = dynamic_cast<BaseballEvent *>(the_event); // Down cast to the derived class
	actual_event->remove(me); // call the baseballevent remove method
}