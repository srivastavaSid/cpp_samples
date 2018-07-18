#include <string>
#include <utility>

#ifndef globalDef_h
#define globalDef_h
    class parkingSlot;
    enum class type {
        small,
        medium,
        large,
        xLarge
    };

    using slotInfo    = std::pair <parkingSlot*, int>;
    using vehicleInfo = std::pair <type, std::string>;
#endif