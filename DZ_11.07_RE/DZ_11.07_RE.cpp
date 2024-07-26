#include <iostream>
#include <set>
#include "TicketRequest.h"

using namespace std;

typedef multiset<TicketRequest> TicketSet;

void addRequest(TicketSet& tickets) {
    string destination, name, date;
    cout << "Enter destination: ";
    cin >> destination;
    cout << "Enter passenger name: ";
    cin >> name;
    cout << "Enter departure date: ";
    cin >> date;
    tickets.insert(TicketRequest(destination, name, date));
}

void removeRequest(TicketSet& tickets, int requestNumber) {
    for (auto it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->requestNumber == requestNumber) {
            tickets.erase(it);
            break;
        }
    }
}

void printRequests(const TicketSet& tickets, const string& destination) {
    for (const auto& ticket : tickets) {
        if (ticket.destination == destination) {
            cout << "Request Number: " << ticket.requestNumber << "\nDestination: " << ticket.destination << "\nPassenger Name: " << ticket.passengerName << "\nDeparture Date: " << ticket.departureDate << "\n\n";
        }
    }
}

int countRequests(const TicketSet& tickets, const string& destination, const string& startDate, const string& endDate) {
    int count = 0;
    for (const auto& ticket : tickets) {
        if (ticket.destination == destination && ticket.departureDate >= startDate && ticket.departureDate <= endDate) {
            ++count;
        }
    }
    return count;
}

void printAllRequests(const TicketSet& tickets) {
    for (const auto& ticket : tickets) {
        cout << "Request Number: " << ticket.requestNumber << "\nDestination: " << ticket.destination << "\nPassenger Name: " << ticket.passengerName << "\nDeparture Date: " << ticket.departureDate << "\n\n";
    }
}

int main() {
    TicketSet tickets;
    int choice;
    int requestNumber;
    string destination;
    string startDate, endDate;
    while (true) {
        cout << "1. Add request\n2. Remove request\n3. Print requests by destination\n4. Count requests by date and destination\n5. Print all requests\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            addRequest(tickets);
            break;
        case 2:
            cout << "Enter request number to remove: ";
            cin >> requestNumber;
            removeRequest(tickets, requestNumber);
            break;
        case 3:
            cout << "Enter destination: ";
            cin >> destination;
            printRequests(tickets, destination);
            break;
        case 4:
            cout << "Enter destination: ";
            cin >> destination;
            cout << "Enter start date: ";
            cin >> startDate;
            cout << "Enter end date: ";
            cin >> endDate;
            cout << "Number of requests: " << countRequests(tickets, destination, startDate, endDate) << "\n";
            break;
        case 5:
            printAllRequests(tickets);
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
