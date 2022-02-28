#include "HotelRooms.h"

class Apartment: public HotelRooms {
    int m_apartmentNumber;

public:
    int getApartmentNumber() const;

    Apartment(int mCapacity, bool mIsReserved, int mApartmentNumber);
};

