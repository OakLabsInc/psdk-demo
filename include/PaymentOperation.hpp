// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from PaymentOperationHistory.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class PaymentOperation : int {
    /** payment created */
    CREATED,
    /** Increase pre-authorization amount */
    PRE_AUTHORIZATION_INCREASE_AMOUNT,
    /** Complete pre-authorization transaction */
    PRE_AUTHORIZATION_COMPLETION,
    /** Void a transaction */
    VOID_TYPE,
    /** Partial void a transaction */
    PARTIAL_VOID,
    /** Extend pre-authorization */
    PRE_AUTHORIZATION_EXTEND,
    /** Gratuity adjustment on completed payment. */
    GRATUITY_ADJUSTMENT,
    /** Delayed charge to perform  Pre-auth delayed charge transactions. */
    DELAYED_CHARGE,
};

constexpr std::string_view toString(const PaymentOperation& arg) {
    switch(arg) {
        case PaymentOperation::CREATED: return "CREATED";
        case PaymentOperation::PRE_AUTHORIZATION_INCREASE_AMOUNT: return "PRE_AUTHORIZATION_INCREASE_AMOUNT";
        case PaymentOperation::PRE_AUTHORIZATION_COMPLETION: return "PRE_AUTHORIZATION_COMPLETION";
        case PaymentOperation::VOID_TYPE: return "VOID_TYPE";
        case PaymentOperation::PARTIAL_VOID: return "PARTIAL_VOID";
        case PaymentOperation::PRE_AUTHORIZATION_EXTEND: return "PRE_AUTHORIZATION_EXTEND";
        case PaymentOperation::GRATUITY_ADJUSTMENT: return "GRATUITY_ADJUSTMENT";
        case PaymentOperation::DELAYED_CHARGE: return "DELAYED_CHARGE";
        default: return "PaymentOperation enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::PaymentOperation> {
    size_t operator()(::verifone_sdk::PaymentOperation type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
