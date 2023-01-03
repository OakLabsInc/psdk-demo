// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class CharacterMaskType : int {
    /** mask on screen entry */
    MASKED,
    /** unmasked (default) */
    UNMASKED,
    /** delayed masking on screen entry */
    DELAYED,
};

constexpr std::string_view toString(const CharacterMaskType& arg) {
    switch(arg) {
        case CharacterMaskType::MASKED: return "MASKED";
        case CharacterMaskType::UNMASKED: return "UNMASKED";
        case CharacterMaskType::DELAYED: return "DELAYED";
        default: return "CharacterMaskType enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::CharacterMaskType> {
    size_t operator()(::verifone_sdk::CharacterMaskType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
