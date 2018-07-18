#include <iostream>
#include <vector>
#include <utility>
#include "GlobalDef.h"

#ifndef parkingSlot_h
#define parkingSlot_h
    class parkingSlot {
        public:
            parkingSlot(const type tp, const std::vector<int> slotNums)
                : slotType(tp), emptySlots(slotNums) {}
            slotInfo blockSlot() {
                int slotNum(0);
                parkingSlot* pSlot = nullptr;
                if (! emptySlots.empty()) {
                    slotNum = emptySlots.back();
                    emptySlots.pop_back();
                    pSlot = this;
                }
                return std::make_pair(pSlot, slotNum);
            }
            void freeSlot(int slotNum) {
                emptySlots.push_back(slotNum);
            }
        private:
            type slotType;
            std::vector<int> emptySlots;
    };
#endif