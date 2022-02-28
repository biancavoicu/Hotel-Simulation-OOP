#include "HotelRooms.h"

class ConferenceRoom : public HotelRooms {
    int m_conferenceRoomNumber;

    bool m_hasProjector;

    bool m_isSceneType;

    bool m_isIndividualType;

    int m_reservedByGroup;
public:
    bool getHasProjector() const;

    void setHasProjector(bool mHasProjector);

    bool getIsSceneType() const;

    void setIsSceneType(bool mIsSceneType);

    bool getIsIndividualType() const;

    void setIsIndividualType(bool mIsIndividualType);

    int getConferenceRoomNumber() const;

    int getReservedByGroup() const;

    void setReservedByGroup(int mReservedByGroup);

    ConferenceRoom(int mCapacity, bool mIsReserved, int mConferenceRoomNumber, bool mHasProjector, bool mIsSceneType,
                   bool mIsIndividualType, int mReservedByGroup);
};


