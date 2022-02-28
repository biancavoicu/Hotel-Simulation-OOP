#include <iostream>
#include "GroupRequest.h"
#include "Apartment.h"
#include "Client.h"
#include "ConferenceRoom.h"
#include "HotelRooms.h"
#include "NormalRoom.h"
#include "Restaurant.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

// Functie pentru anularea unei rezervari

void cancelReservation(int id, vector<GroupRequest> &requests) {
    requests.erase(requests.begin() + id - 1);
}

// Functie pentru printarea rezervarilor

void printReservations(int id, vector<GroupRequest> requests, vector<ConferenceRoom> conferenceRooms) {
    int i, j;
    cout << "Rezervare confirmata pentru cererea cu id-ul " << id << ". Au fost rezervate urmatoarele: " << '\n';
    for (i = 0; i < conferenceRooms.size(); i++) {
        if (conferenceRooms[i].getReservedByGroup() == id)
            cout << "Sala " << conferenceRooms[i].getConferenceRoomNumber() << '\n';
    }

    vector<Client> persons;
    vector<int> rooms;
    int number;

    persons = requests[id - 1].getGroupParticipants();

    for (i = 0; i < persons.size(); i++) {
        number = persons[i].getRoomNr();
        if (!(find(rooms.begin(), rooms.end(), number) != rooms.end()) && number != 0) {
            rooms.push_back(number);
        }
    }

    cout << "Camere: ";
    for (i = 0; i < rooms.size() - 1; i++)
        cout << rooms[i] << " ";

    i = rooms.size() - 1;
    cout << rooms[i] << "." << '\n';
}

// Functie pentru a afla daca se poate realiza rezervarea

bool makeReservation(GroupRequest &request, vector<NormalRoom> &normalRooms, vector<Apartment> &apartments,
                     vector<ConferenceRoom> &conferenceRooms) {
    int i, j;
    ROOMTYPE roomType;
    int personsNumber;

    GroupRequest copyRequest = request;
    vector<NormalRoom> copyNormalRooms = normalRooms;
    vector<Apartment> copyApartments = apartments;
    vector<ConferenceRoom> copyConferenceRooms = conferenceRooms;

    // Caut o sala de tipul dorit suficient de mare pentru tot grupul

    int okConferenceRoom = 0, okRooms = 0;
    roomType = request.getReserveGroupRoom();
    if (roomType != none) {
        for (j = 0; j < conferenceRooms.size(); j++) {
            if (conferenceRooms[j].getIsIndividualType() == true && roomType == conferenceRoomIndividual &&
                conferenceRooms[j].getIsReserved() == false &&
                conferenceRooms[j].getCapacity() >= request.getParticipantsNumber()) {
                conferenceRooms[j].setReservedByGroup(request.getRequestId());
                conferenceRooms[j].setIsReserved(true);
                okConferenceRoom = 1;
                break;
            }

            if (conferenceRooms[j].getIsSceneType() == true && roomType == conferenceRoomScene &&
                conferenceRooms[j].getIsReserved() == false &&
                conferenceRooms[j].getCapacity() >= request.getParticipantsNumber()) {
                conferenceRooms[j].setReservedByGroup(request.getRequestId());
                conferenceRooms[j].setIsReserved(true);
                okConferenceRoom = 1;
                break;
            }
        }
    } else okConferenceRoom = 1;

    // Daca se gaseste o sala disponibila, incepe cazarea intai in apartamente, apoi in camere

    vector<Client> persons = request.getGroupParticipants();
    if (okConferenceRoom == 1) {

        personsNumber = request.getParticipantsNumber();

        auto iterator = apartments.begin();
        int k = 0;
        int cntPers = 0;

        while (personsNumber > 3 && iterator != apartments.end()) {
            iterator++;
            if (apartments[k].getIsReserved() == false) {
                personsNumber -= 4;
                apartments[k].setIsReserved(true);
                for (i = 0; i < 4; i++) {
                    persons[cntPers++].setRoomNr(apartments[k].getApartmentNumber());
                }
            }
            k++;
        }


        k = 0;
        auto it = normalRooms.begin();

        if (personsNumber < 4) {
            switch (personsNumber) {
                case 0:
                    okRooms = 1;
                    break;
                case 1:
                    k = 0;
                    while (it != normalRooms.end()) {
                        it++;
                        if (normalRooms[k].getIsReserved() == false) {
                            personsNumber -= 1;
                            normalRooms[k].setIsReserved(true);
                            persons[cntPers++].setRoomNr(normalRooms[k].getRoomNumber());
                            break;
                        }
                        k++;
                    }
                    break;
                case 2:
                    k = 0;
                    while (it != normalRooms.end()) {
                        it++;
                        if (normalRooms[k].getIsReserved() == false) {
                            personsNumber -= 2;
                            normalRooms[k].setIsReserved(true);
                            persons[cntPers++].setRoomNr(normalRooms[k].getRoomNumber());
                            persons[cntPers++].setRoomNr(normalRooms[k].getRoomNumber());
                            break;
                        }
                        k++;
                    }
                    break;
                case 3:
                    k = 0;
                    while (it != normalRooms.end()) {
                        it++;
                        if (normalRooms[k].getIsReserved() == false) {
                            personsNumber -= 2;
                            normalRooms[k].setIsReserved(true);
                            persons[cntPers++].setRoomNr(normalRooms[k].getRoomNumber());
                            persons[cntPers++].setRoomNr(normalRooms[k].getRoomNumber());
                            break;
                        }
                        k++;
                    }
                    k = 0;
                    while (it != normalRooms.end()) {
                        it++;
                        if (normalRooms[k].getIsReserved() == false) {
                            personsNumber -= 1;
                            normalRooms[k].setIsReserved(true);
                            persons[cntPers++].setRoomNr(normalRooms[k].getRoomNumber());
                            break;
                        }
                        k++;
                    }
                    break;
            }
        }

        k = 0;
        it = normalRooms.begin();
        while (personsNumber > 1 && it != normalRooms.end()) {
            it++;
            if (normalRooms[k].getIsReserved() == false) {
                personsNumber -= 2;
                normalRooms[k].setIsReserved(true);
                for (i = 0; i < 2; i++) {
                    persons[cntPers++].setRoomNr(normalRooms[k].getRoomNumber());
                }
            }
            k++;
        }


        if (personsNumber < 2) {
            switch (personsNumber) {
                case 0:
                    okRooms = 1;
                    break;
                case 1:
                    k = 0;
                    while (it != normalRooms.end()) {
                        it++;
                        if (normalRooms[k].getIsReserved() == false) {
                            personsNumber -= 1;
                            normalRooms[k].setIsReserved(true);
                            persons[cntPers++].setRoomNr(normalRooms[k].getRoomNumber());
                            break;
                        }
                        k++;
                    }
                    break;
            }
        }

        if (personsNumber == 0)
            okRooms = 1;
    }
    if (okConferenceRoom == 1 && okRooms == 1) {
        request.setGroupParticipants(persons);
        return true;
    } else {
        request = copyRequest;
        normalRooms = copyNormalRooms;
        apartments = copyApartments;
        conferenceRooms = copyConferenceRooms;
        return false;
    }
}


void Checkout(GroupRequest request, vector<NormalRoom> &normalRooms, vector<Apartment> &apartments,
              vector<ConferenceRoom> &conferenceRooms) {
    int i, j;
    for (j = 0; j < conferenceRooms.size(); j++) {
        if (conferenceRooms[j].getReservedByGroup() == request.getRequestId()) {
            conferenceRooms[j].setIsReserved(false);
            conferenceRooms[j].setReservedByGroup(0);
            break;
        }
    }

    vector<Client> persons = request.getGroupParticipants();

    for (i = 0; i < normalRooms.size(); i++)
        for (j = 0; j < persons.size(); j++) {
            if (normalRooms[i].getRoomNumber() == persons[j].getRoomNr()) {
                normalRooms[i].setIsReserved(false);
            }
        }

    for (i = 0; i < apartments.size(); i++)
        for (j = 0; j < persons.size(); j++) {
            if (apartments[i].getApartmentNumber() == persons[j].getRoomNr()) {
                apartments[i].setIsReserved(false);
            }
        }

}


int main() {
    ifstream f("nume.in");

    // Pentru generarea numelelor clientilor

    srand(time(0));

    vector<string> firstName;
    vector<string> lastName;
    int i, j;
    string name;

    for (i = 0; i < 30; i++) {
        f >> name;
        firstName.push_back(name);
    }

    for (i = 0; i < 50; i++) {
        f >> name;
        lastName.push_back(name);
    }


    int normalRoomsNumber, apartmentsNumber, conferenceRoomsNumber, restaurantCapacity;
    int requestsNumber;
    int totalCapacity = 0, reservationId;

    vector<NormalRoom> normalRooms;
    vector<Apartment> apartments;
    vector<ConferenceRoom> conferenceRooms;
    vector<GroupRequest> groupRequests;
    vector<Client> clients;

    cout << "Cate camere normale are hotelul?" << '\n';
    cin >> normalRoomsNumber;

    cout << "Cate apartamente are hotelul?" << '\n';
    cin >> apartmentsNumber;

    cout << "Cate sali de conferinta are hotelul?" << '\n';
    cin >> conferenceRoomsNumber;


    // Crearea camerelor normale
    for (i = 1; i <= normalRoomsNumber; i++) {
        int cap = 1 + rand() % 2;
        totalCapacity += cap;
        NormalRoom r(cap, false, i);
        normalRooms.push_back(r);
    }

    // Crearea apartamentelor
    for (i = normalRoomsNumber + 1; i <= normalRoomsNumber + apartmentsNumber; i++) {
        totalCapacity += 4;
        Apartment a(4, false, i);
        apartments.push_back(a);
    }

    // Crearea salilor de conferinta
    for (i = normalRoomsNumber + apartmentsNumber + 1;
         i <= normalRoomsNumber + apartmentsNumber + conferenceRoomsNumber; i++) {
        if (i % 2) {
            ConferenceRoom c(16 + rand() % 9, false, i, true, true, false, 0);
            conferenceRooms.push_back(c);
        } else {
            ConferenceRoom c(16 + rand() % 9, false, i, false, false, true, 0);
            conferenceRooms.push_back(c);
        }
    }

    cout << "Ce capacitate are restaurantul hotelului? Aceasta nu trebuie sa depaseasca " << totalCapacity << "."
         << '\n';
    cin >> restaurantCapacity;


    // Crearea restaurantului
    Restaurant hotelRestaurant(restaurantCapacity, false);

    // Crearea cererilor de cazare si a grupurilor de persoane
    cout << "Cate cereri de cazare are hotelul?" << '\n';
    cin >> requestsNumber;

    for (j = 1; j <= requestsNumber; j++) {
        int participantsNumber = 4 + rand() % (totalCapacity / 5);

        for (i = 1; i <= participantsNumber; i++) {
            Client c;
            if (i % 2) c.setBreakfastInRestaurant(true);
            else c.setBreakfastInRoom(true);
            c.setFirstName(firstName[rand() % 30]);
            c.setLastName(lastName[rand() % 50]);
            clients.push_back(c);
        }

        GroupRequest GR;

        if (j % 3 == 0) {
            GR.setRequestId(j);
            GR.setParticipantsNumber(participantsNumber);
            GR.setStayPeriod(1 + rand() % 10);
            GR.setReserveGroupRoom(none);
            GR.setGroupParticipants(clients);
        } else if (j % 3 == 1) {
            GR.setRequestId(j);
            GR.setParticipantsNumber(participantsNumber);
            GR.setStayPeriod(1 + rand() % 10);
            GR.setReserveGroupRoom(conferenceRoomScene);
            GR.setGroupParticipants(clients);
        } else {
            GR.setRequestId(j);
            GR.setParticipantsNumber(participantsNumber);
            GR.setStayPeriod(1 + rand() % 10);
            GR.setReserveGroupRoom(conferenceRoomIndividual);
            GR.setGroupParticipants(clients);
        }
        groupRequests.push_back(GR);
    }


//    // Anularea unei rezervari
//    cout << "Introduceti id-ul rezervarii pe care doriti sa o anulati: " << '\n';
//    cin >> reservationId;
//    cancelReservation(reservationId, groupRequests);

    // Cazarea grupurilor

    int day = 1;
    int personsInRestaurant = 0;
    vector<Client> clientss;

    for (i = 0; i < groupRequests.size(); i++) {
        int stayPeriod = groupRequests[i].getStayPeriod();
        clientss = groupRequests[i].getGroupParticipants();
        for (j = 0; j < clientss.size(); j++) {
            if (clientss[j].isBreakfastInRestaurant())
                personsInRestaurant++;
        }

        if (makeReservation(groupRequests[i], normalRooms, apartments, conferenceRooms) == true &&
            personsInRestaurant <= restaurantCapacity) {
            printReservations(groupRequests[i].getRequestId(), groupRequests, conferenceRooms);
            cout << "Ziua de cazare: " << day << '\n';
            cout << '\n';
        }

        day += stayPeriod;
        Checkout(groupRequests[i], normalRooms, apartments, conferenceRooms);
        clientss.clear();
        personsInRestaurant = 0;
    }


    return 0;
}
