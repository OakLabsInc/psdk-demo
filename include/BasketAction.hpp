// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class BasketAction : int {
    /** The items were added to the basket. */
    ADDED,
    /** The items were modified in the basket */
    MODIFIED,
    /** The items were removed from the basket */
    REMOVED,
    /** Only used during error cases. */
    UNKNOWN,
    /** Sent in response to the {@link BasketManager#finalizeBasket()} command. */
    FINALIZED,
};

constexpr std::string_view toString(const BasketAction& arg) {
    switch(arg) {
        case BasketAction::ADDED: return "ADDED";
        case BasketAction::MODIFIED: return "MODIFIED";
        case BasketAction::REMOVED: return "REMOVED";
        case BasketAction::UNKNOWN: return "UNKNOWN";
        case BasketAction::FINALIZED: return "FINALIZED";
        default: return "BasketAction enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::BasketAction> {
    size_t operator()(::verifone_sdk::BasketAction type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
