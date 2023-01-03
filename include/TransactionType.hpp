// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from TransactionType.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class TransactionType : int {
    /** A direct payment, attempting to collect the funds in full at once */
    PAYMENT,
    /** A refund for a specific payment */
    REFUND,
    /** Used to void a transaction */
    VOID_TYPE,
    /** Authorizes an amount to be completed at a later time */
    PRE_AUTHORIZATION,
    /** Updates  pre-authorization */
    PRE_AUTHORIZATION_UPDATE,
    /** Completes a pre-authorisation */
    PRE_AUTHORIZATION_COMPLETION,
    /** Not currently supported. Begin or continue a deferred payment plan */
    DEFERRED_PAYMENT,
    /** Not currently supported. Finish a deferred payment plan */
    DEFERRED_PAYMENT_COMPLETION,
    /** Installment based payment plan */
    INSTALLMENT,
    /**
     * Deposit funds into an account.  This differs from refund in that the funds are
     * transferred (credited) immediately to the cardholder account, rather than upon settlement
     */
    DEPOSIT,
    /**
     * Gratuity adjustment. Used when we need to enable adjusting the gratuity
     * amount of a payment which is already captured / completed.
     */
    GRATUITY_ADJUSTMENT,
    /** Delayed charge to perform Pre-auth delayed charge transactions. */
    DELAYED_CHARGE,
    /** Perform cash advance transactions. */
    CASH_ADVANCE,
    /** Stored value to perform gift card payment transactions. */
    STORED_VALUE,
    /**
     * A recurring payment. The first recurring payment must have the card present, or sometimes
     * a token might be used, depending on the payment host. This can only be used with PaymentType
     * of CREDIT (default) or ALTERNATE_TYPE.
     */
    RECURRING,
};

constexpr std::string_view toString(const TransactionType& arg) {
    switch(arg) {
        case TransactionType::PAYMENT: return "PAYMENT";
        case TransactionType::REFUND: return "REFUND";
        case TransactionType::VOID_TYPE: return "VOID_TYPE";
        case TransactionType::PRE_AUTHORIZATION: return "PRE_AUTHORIZATION";
        case TransactionType::PRE_AUTHORIZATION_UPDATE: return "PRE_AUTHORIZATION_UPDATE";
        case TransactionType::PRE_AUTHORIZATION_COMPLETION: return "PRE_AUTHORIZATION_COMPLETION";
        case TransactionType::DEFERRED_PAYMENT: return "DEFERRED_PAYMENT";
        case TransactionType::DEFERRED_PAYMENT_COMPLETION: return "DEFERRED_PAYMENT_COMPLETION";
        case TransactionType::INSTALLMENT: return "INSTALLMENT";
        case TransactionType::DEPOSIT: return "DEPOSIT";
        case TransactionType::GRATUITY_ADJUSTMENT: return "GRATUITY_ADJUSTMENT";
        case TransactionType::DELAYED_CHARGE: return "DELAYED_CHARGE";
        case TransactionType::CASH_ADVANCE: return "CASH_ADVANCE";
        case TransactionType::STORED_VALUE: return "STORED_VALUE";
        case TransactionType::RECURRING: return "RECURRING";
        default: return "TransactionType enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::TransactionType> {
    size_t operator()(::verifone_sdk::TransactionType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
