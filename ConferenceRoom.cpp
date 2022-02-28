//
// Created by Bianca on 25/04/2021.
//

#include "ConferenceRoom.h"

bool ConferenceRoom::getHasProjector() const {
    return m_hasProjector;
}

void ConferenceRoom::setHasProjector(bool mHasProjector) {
    m_hasProjector = mHasProjector;
}

bool ConferenceRoom::getIsSceneType() const {
    return m_isSceneType;
}

void ConferenceRoom::setIsSceneType(bool mIsSceneType) {
    m_isSceneType = mIsSceneType;
}

bool ConferenceRoom::getIsIndividualType() const {
    return m_isIndividualType;
}

void ConferenceRoom::setIsIndividualType(bool mIsIndividualType) {
    m_isIndividualType = mIsIndividualType;
}

int ConferenceRoom::getConferenceRoomNumber() const {
    return m_conferenceRoomNumber;
}

ConferenceRoom::ConferenceRoom(int mCapacity, bool mIsReserved, int mConferenceRoomNumber, bool mHasProjector,
                               bool mIsSceneType, bool mIsIndividualType, int mReservedByGroup) : HotelRooms(mCapacity,
                                                                                                             mIsReserved),
                                                                                                  m_conferenceRoomNumber(
                                                                                                          mConferenceRoomNumber),
                                                                                                  m_hasProjector(
                                                                                                          mHasProjector),
                                                                                                  m_isSceneType(
                                                                                                          mIsSceneType),
                                                                                                  m_isIndividualType(
                                                                                                          mIsIndividualType),
                                                                                                  m_reservedByGroup(
                                                                                                          mReservedByGroup) {}

int ConferenceRoom::getReservedByGroup() const {
    return m_reservedByGroup;
}

void ConferenceRoom::setReservedByGroup(int mReservedByGroup) {
    m_reservedByGroup = mReservedByGroup;
}
