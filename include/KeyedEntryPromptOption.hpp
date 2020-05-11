// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_entities.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class KeyedEntryPromptOption : int {
    /** Disables CVV prompt */
    NOCVV,
    /**
     * Requires the region-relevant zip code. The result of the AVS
     * will be returned in AVS_Code
     */
    ZIP,
};

constexpr std::string_view toString(const KeyedEntryPromptOption& arg) {
    switch(arg) {
        case KeyedEntryPromptOption::NOCVV: return "NOCVV";
        case KeyedEntryPromptOption::ZIP: return "ZIP";
        default: return "KeyedEntryPromptOption enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::KeyedEntryPromptOption> {
    size_t operator()(::verifone_sdk::KeyedEntryPromptOption type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
