// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment_reports.djinni

#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace verifone_sdk {

enum class PaymentType;
enum class TransactionType;
struct Decimal;

/**
 * The Reconciliation total is useful for generating a Z report when the type is {@link #TYPE},
 * or an X report when the type is {@link #ACTIVE_TOTALS_TYPE}.
 */
class ReconciliationTotal {
public:
    virtual ~ReconciliationTotal() {}

    /**
     * Gets the transation type. It can be one of the following:
     * {@link Transaction#PAYMENT_TYPE}
     * {@link Transaction#REFUND_TYPE}
     * {@link Transaction#VOID_TYPE}
     * {@link Transaction#PRE_AUTHORISATION_TYPE}
     * {@link Transaction#PRE_AUTHORISATION_COMPLETION_TYPE}
     * {@link Transaction#DEFERRED_PAYMENT_TYPE}
     * {@link Transaction#DEFERRED_PAYMENT_COMPLETION_TYPE}
     * {@link Transaction#INSTALLMENT_TYPE}
     */
    virtual std::optional<TransactionType> getTransactionType() const = 0;

    /**
     * Gets the type/method of payment. It can be one of the following.
     * {@link PaymentType#CASH}
     * {@link PaymentType#CREDIT}
     * {@link PaymentType#DEBIT}
     * {@link PaymentType#STORED_VALUE}
     * {@link PaymentType#EBT}
     * {@link PaymentType#ALTERNATE}
     * {@link PaymentType#CHECK}
     * {@link PaymentType#MOBILE}
     */
    virtual std::optional<PaymentType> getPaymentType() const = 0;

    /**
     * The final total amount for this item as a GAAP-standard BigDecimal, including the
     * extendedPrice, tax, and discount. This is required.
     */
    virtual Decimal getAmount() const = 0;

    /** Returns the count of transactions. */
    virtual int32_t getCount() const = 0;

    /** Get the status for this particular event. */
    virtual int32_t getStatus() const = 0;

    /**
     * A user-readable message.
     * This message may not be localized, in which case the type field should be used for
     * determining a localized message.
     */
    virtual std::optional<std::string> getMessage() const = 0;

    /** Returns the TotalsGroupId of transactions. */
    virtual std::optional<std::string> getTotalsGroupId() const = 0;
};

}  // namespace verifone_sdk
