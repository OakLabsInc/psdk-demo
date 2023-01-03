// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from PaymentOperationHistory.djinni

#pragma once

#include "Decimal.hpp"
#include "PaymentOperation.hpp"
#include <optional>
#include <psdk/export.h>
#include <string>
#include <utility>

namespace verifone_sdk {

/**
 * Represents an operation performed on a payment to modify it. Generally used with
 * pre-authorizations
 */
struct PSDK_EXPORT PaymentOperationHistory final {
    /** The operation amount */
    std::optional<Decimal> amount;
    /** Whether operation was authorized */
    std::optional<bool> authorized;
    /** Operation timestamp */
    std::string timestamp;
    /** Operation type */
    PaymentOperation payment_operation;

    PaymentOperationHistory(std::optional<Decimal> amount_,
                            std::optional<bool> authorized_,
                            std::string timestamp_,
                            PaymentOperation payment_operation_)
    : amount(std::move(amount_))
    , authorized(std::move(authorized_))
    , timestamp(std::move(timestamp_))
    , payment_operation(std::move(payment_operation_))
    {}
};

}  // namespace verifone_sdk