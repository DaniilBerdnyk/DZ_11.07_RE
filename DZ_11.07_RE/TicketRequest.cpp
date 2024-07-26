#include "TicketRequest.h"

int TicketRequest::count = 0;

TicketRequest::TicketRequest(string dest, string name, string date) : destination(dest), passengerName(name), departureDate(date) {
    requestNumber = ++count;
}

bool TicketRequest::operator<(const TicketRequest& other) const {
    if (destination == other.destination)
        return departureDate < other.departureDate;
    return destination < other.destination;
}
