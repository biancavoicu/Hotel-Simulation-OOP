#include "Client.h"
#include <vector>

using namespace std;

enum ROOMTYPE {
    conferenceRoomScene, conferenceRoomIndividual, none
};

class GroupRequest {
    int m_requestId;

    int m_participantsNumber;

    int m_stayPeriod;

    ROOMTYPE m_reserveGroupRoom;

    vector<Client> m_groupParticipants;

public:
    int getParticipantsNumber() const;

    void setParticipantsNumber(int mParticipantsNumber);

    int getStayPeriod() const;

    void setStayPeriod(int mStayPeriod);

    ROOMTYPE getReserveGroupRoom() const;

    void setReserveGroupRoom(ROOMTYPE mReserveGroupRoom);

    const vector<Client> &getGroupParticipants() const;

    void setGroupParticipants(const vector<Client> &mGroupParticipants);

    int getRequestId() const;

    void setRequestId(int mRequestId);

    GroupRequest(int mRequestId, int mParticipantsNumber, int mStayPeriod, ROOMTYPE mReserveGroupRoom,
                 const vector<Client> &mGroupParticipants);

    GroupRequest();
};

