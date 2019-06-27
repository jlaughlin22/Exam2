#include "EsportsTicket.h"
#include "EsportsEvent.h"

/**
* Implements the leave method
*/
void EsportsTicket::leave() {
	EsportsEvent * actual_event = dynamic_cast<EsportsEvent *>(the_event);
	actual_event->remove(me);
}