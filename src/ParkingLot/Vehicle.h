#ifndef vehicle_h
#define vehicle_h

#include <iostream>
#include <string>
#include <utility>
#include "GlobalDef.h"
#include "ParkingSlot.h"

class vehicle {
    public:
        vehicle(const type& vehType, const std::string& licNum) {
            vehicleDetail = std::make_pair(vehType, licNum);
            slotDetail = std::make_pair(nullptr, 0);
        }
        vehicle(const vehicle& rhs) = delete;
        vehicle& operator=(const vehicle& rhs) = delete;
        vehicle(vehicle&& rhs) = delete;
        vehicle& operator=(vehicle&& rhs) = delete;

        void park(const slotInfo& slInfo) {
            if (slInfo.first != nullptr)
                slotDetail = slInfo;
            else
                std::cout << "No space left to park" << std::endl;
        }
        void remove() {
            auto pSlot = slotDetail.first;
            if (pSlot != nullptr)
                pSlot->freeSlot(slotDetail.second);
        }
    private:
        vehicleInfo vehicleDetail;
        slotInfo slotDetail;
};
#endif