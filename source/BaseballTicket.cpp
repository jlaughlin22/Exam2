#include "BaseballTicket.h"
#include "BaseballEvent.h"

/**
* Implements the leave method
*/
void BaseballTicket::leave() {
	BaseballEvent * actual_event = dynamic_cast<BaseballEvent *>(the_event);
	actual_event->remove(me);
}