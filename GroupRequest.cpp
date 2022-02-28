#include "GroupRequest.h"

int GroupRequest::getParticipantsNumber() const {
    return m_participantsNumber;
}

void GroupRequest::setParticipantsNumber(int mParticipantsNumber) {
    m_participantsNumber = mParticipantsNumber;
}

int GroupRequest::getStayPeriod() const {
    return m_stayPeriod;
}

void GroupRequest::setStayPeriod(int mStayPeriod) {
    m_stayPeriod = mStayPeriod;
}

ROOMTYPE GroupRequest::getReserveGroupRoom() const {
    return m_reserveGroupRoom;
}

void GroupRequest::setReserveGroupRoom(ROOMTYPE mReserveGroupRoom) {
    m_reserveGroupRoom = mReserveGroupRoom;
}

const vector<Client> &GroupRequest::getGroupParticipants() const {
    return m_groupParticipants;
}

void GroupRequest::setGroupParticipants(const vector<Client> &mGroupParticipants) {
    m_groupParticipants = mGroupParticipants;
}

int GroupRequest::getRequestId() const {
    return m_requestId;
}

void GroupRequest::setRequestId(int mRequestId) {
    m_requestId = mRequestId;
}

GroupRequest::GroupRequest(int mRequestId, int mParticipantsNumber, int mStayPeriod, ROOMTYPE mReserveGroupRoom,
                           const vector<Client> &mGroupParticipants) : m_requestId(mRequestId),
                                                                       m_participantsNumber(mParticipantsNumber),
                                                                       m_stayPeriod(mStayPeriod),
                                                                       m_reserveGroupRoom(mReserveGroupRoom),
                                                                       m_groupParticipants(mGroupParticipants) {}


GroupRequest::GroupRequest() {
    m_requestId = 0;
    m_participantsNumber = 0;
    m_stayPeriod = 0;
    m_reserveGroupRoom = none;
}