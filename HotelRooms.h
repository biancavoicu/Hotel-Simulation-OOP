class HotelRooms {
    int m_capacity;

    bool m_isReserved;
public:
    int getCapacity() const;

    void setCapacity(int mCapacity);

    HotelRooms(int mCapacity, bool mIsReserved);

    HotelRooms();

    bool getIsReserved() const;

    void setIsReserved(bool mIsReserved);
};


