#include "EsportsTicket.h"
#include "EsportsEvent.h"

/**
* Implements the leave method
*/
void EsportsTicket::leave() {
	EsportsEvent * actual_event = dynamic_cast<EsportsEvent *>(the_event); // Downcast to the serived class
	actual_event->remove(me); // call the esportsevent remove method
}