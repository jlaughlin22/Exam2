#include "BaseballTicket.h"
#include "BaseballEvent.h"

/**
* Implements the leave method
*/
void BaseballTicket::leave() {
	BaseballEvent * actual_event = dynamic_cast<BaseballEvent *>(the_event); // Down cast to the derived class
	actual_event->remove(me); // call the baseballevent remove method
}