#include <string>

using namespace std;

class TicketRequest {
public:
    static int count;
    int requestNumber;
    string destination;
    string passengerName;
    string departureDate;

    TicketRequest(string dest, string name, string date);
    bool operator<(const TicketRequest& other) const;
};
