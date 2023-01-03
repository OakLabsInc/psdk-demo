// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class EarlyCaptureOperationType : int {
    /** A direct payment, attempting to collect the funds in full at once */
    PAYMENT,
    /** A refund for a specific payment */
    REFUND,
    /** Authorizes an amount to be completed at a later time */
    PRE_AUTHORIZATION,
    /** Token */
    TOKEN,
    /** Activate a gift card */
    ACTIVATE,
    /** add value to the Gift cards */
    ADD_VALUE,
    /** balance of the gift card/prepaid cards */
    BALANCE,
    /** close out a gift card */
    GIFT_CLOSE,
};

constexpr std::string_view toString(const EarlyCaptureOperationType& arg) {
    switch(arg) {
        case EarlyCaptureOperationType::PAYMENT: return "PAYMENT";
        case EarlyCaptureOperationType::REFUND: return "REFUND";
        case EarlyCaptureOperationType::PRE_AUTHORIZATION: return "PRE_AUTHORIZATION";
        case EarlyCaptureOperationType::TOKEN: return "TOKEN";
        case EarlyCaptureOperationType::ACTIVATE: return "ACTIVATE";
        case EarlyCaptureOperationType::ADD_VALUE: return "ADD_VALUE";
        case EarlyCaptureOperationType::BALANCE: return "BALANCE";
        case EarlyCaptureOperationType::GIFT_CLOSE: return "GIFT_CLOSE";
        default: return "EarlyCaptureOperationType enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::EarlyCaptureOperationType> {
    size_t operator()(::verifone_sdk::EarlyCaptureOperationType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
