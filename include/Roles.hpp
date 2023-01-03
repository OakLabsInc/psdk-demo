// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from Roles.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class Roles : int {
    /** Merchant Admin */
    ADMIN,
    /** Merchant Manager */
    MANAGER,
    /** Merchant Cashier */
    CASHIER,
    /** Merchant Staff */
    STAFF,
};

constexpr std::string_view toString(const Roles& arg) {
    switch(arg) {
        case Roles::ADMIN: return "ADMIN";
        case Roles::MANAGER: return "MANAGER";
        case Roles::CASHIER: return "CASHIER";
        case Roles::STAFF: return "STAFF";
        default: return "Roles enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::Roles> {
    size_t operator()(::verifone_sdk::Roles type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
