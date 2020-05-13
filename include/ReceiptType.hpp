// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_entities.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class ReceiptType : int {
    /** receipt for the customer */
    CUSTOMER,
    /** receipt for the merchant */
    MERCHANT,
};

constexpr std::string_view toString(const ReceiptType& arg) {
    switch(arg) {
        case ReceiptType::CUSTOMER: return "CUSTOMER";
        case ReceiptType::MERCHANT: return "MERCHANT";
        default: return "ReceiptType enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::ReceiptType> {
    size_t operator()(::verifone_sdk::ReceiptType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
