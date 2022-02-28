#include "Apartment.h"

int Apartment::getApartmentNumber() const {
    return m_apartmentNumber;
}

Apartment::Apartment(int mCapacity, bool mIsReserved, int mApartmentNumber) : HotelRooms(mCapacity, mIsReserved),
                                                                              m_apartmentNumber(mApartmentNumber) {}
