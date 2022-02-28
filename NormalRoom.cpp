#include "NormalRoom.h"

int NormalRoom::getRoomNumber() const {
    return m_roomNumber;
}

NormalRoom::NormalRoom(int mCapacity, bool mIsReserved, int mRoomNumber) : HotelRooms(mCapacity, mIsReserved),
                                                                           m_roomNumber(mRoomNumber) {}
