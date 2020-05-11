// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class TransactionResult : int {
    /** The transaction achieved the desired result. */
    SUCCESS,
    /** The transaction was cancelled. */
    CANCELLED,
    /** The transaction did not accomplish the desired goal. */
    FAILED,
};

constexpr std::string_view toString(const TransactionResult& arg) {
    switch(arg) {
        case TransactionResult::SUCCESS: return "SUCCESS";
        case TransactionResult::CANCELLED: return "CANCELLED";
        case TransactionResult::FAILED: return "FAILED";
        default: return "TransactionResult enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::TransactionResult> {
    size_t operator()(::verifone_sdk::TransactionResult type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
