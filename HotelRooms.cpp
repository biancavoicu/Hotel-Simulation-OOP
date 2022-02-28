#include "HotelRooms.h"

int HotelRooms::getCapacity() const {
    return m_capacity;
}

void HotelRooms::setCapacity(int mCapacity) {
    m_capacity = mCapacity;
}

HotelRooms::HotelRooms(int mCapacity, bool mIsReserved) : m_capacity(mCapacity), m_isReserved(mIsReserved) {}

HotelRooms::HotelRooms() : m_capacity(0), m_isReserved(false) {}

bool HotelRooms::getIsReserved() const {
    return m_isReserved;
}

void HotelRooms::setIsReserved(bool mIsReserved) {
    m_isReserved = mIsReserved;
}
