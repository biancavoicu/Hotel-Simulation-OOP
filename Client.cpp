#include "Client.h"

int Client::getRoomNr() const {
    return m_roomNr;
}

void Client::setRoomNr(int mRoomNr) {
    m_roomNr = mRoomNr;
}

bool Client::isBreakfastInRestaurant() const {
    return m_breakfastInRestaurant;
}

void Client::setBreakfastInRestaurant(bool mBreakfastInRestaurant) {
    m_breakfastInRestaurant = mBreakfastInRestaurant;
}

bool Client::isBreakfastInRoom() const {
    return m_breakfastInRoom;
}

void Client::setBreakfastInRoom(bool mBreakfastInRoom) {
    m_breakfastInRoom = mBreakfastInRoom;
}

Client::Client() {
    m_firstName = "";
    m_lastName = "";
    m_roomNr = 0;
    m_breakfastInRestaurant = false;
    m_breakfastInRoom = false;
}

const string &Client::getFirstName() const {
    return m_firstName;
}

void Client::setFirstName(const string &mFirstName) {
    m_firstName = mFirstName;
}

const string &Client::getLastName() const {
    return m_lastName;
}

void Client::setLastName(const string &mLastName) {
    m_lastName = mLastName;
}

Client::Client(const string &mFirstName, const string &mLastName, int mRoomNr, bool mBreakfastInRestaurant,
               bool mBreakfastInRoom) : m_firstName(mFirstName), m_lastName(mLastName), m_roomNr(mRoomNr),
                                        m_breakfastInRestaurant(mBreakfastInRestaurant),
                                        m_breakfastInRoom(mBreakfastInRoom) {}
