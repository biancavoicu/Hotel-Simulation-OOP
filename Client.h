#include <string>

using namespace std;

class Client {
    string m_firstName;

    string m_lastName;

    int m_roomNr;

    bool m_breakfastInRestaurant;

    bool m_breakfastInRoom;

public:
    const string &getFirstName() const;

    void setFirstName(const string &mFirstName);

    const string &getLastName() const;

    void setLastName(const string &mLastName);

    int getRoomNr() const;

    void setRoomNr(int mRoomNr);

    bool isBreakfastInRestaurant() const;

    void setBreakfastInRestaurant(bool mBreakfastInRestaurant);

    bool isBreakfastInRoom() const;

    void setBreakfastInRoom(bool mBreakfastInRoom);

    Client(const string &mFirstName, const string &mLastName, int mRoomNr, bool mBreakfastInRestaurant,
           bool mBreakfastInRoom);

    Client();
};


