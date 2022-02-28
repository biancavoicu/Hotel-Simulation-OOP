#include "HotelRooms.h"

class NormalRoom : public HotelRooms {
    int m_roomNumber;

public:
    int getRoomNumber() const;

    NormalRoom(int mCapacity, bool mIsReserved, int mRoomNumber);
};


