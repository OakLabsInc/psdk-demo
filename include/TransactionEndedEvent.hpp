// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class Transaction;
class TransactionEventResponse;
enum class TransactionResult;

/** The event received when the transaction is completed or cancelled. */
class TransactionEndedEvent {
public:
    virtual ~TransactionEndedEvent() {}

    /**
     * A user-readable message.
     * This message may not be localized, in which case the type field should be used for
     * determining a localized message.
     */
    virtual std::optional<std::string> getMessage() const = 0;

    /** Get the session ID for the session which triggered this event. */
    virtual std::optional<std::string> getSessionId() const = 0;

    /**
     * The type of status. This will generally be SUCCESS for a status of 0, and contain a different
     * type for other errors.
     */
    virtual std::optional<std::string> getType() const = 0;

    /** Get the status for this particular event. A status of 0 means success, any other status is a failure. */
    virtual int32_t getStatus() const = 0;

    /**
     * Returns the event ID associated with this event. Useful for matching the event received by
     * the listener to the original status returned when issuing the call, for example, calling
     * {@link com.verifone.commerce.payment.TransactionManager#reprintReceipt(Payment)} returns a
     * CommerceEvent containing an event ID, which will match the event ID received by the
     * CommerceListener when the receipt reprint is complete.
     */
    virtual std::optional<std::string> getEventId() const = 0;

    /** The invoice ID for the transaction as a reference. */
    virtual std::optional<std::string> getInvoiceId() const = 0;

    /** The transaction associated with this event. */
    virtual std::shared_ptr<Transaction> getTransaction() const = 0;

    /** Generate the TransactionEventResponse associated with this transaction. */
    virtual std::shared_ptr<TransactionEventResponse> generateTransactionEventResponse() const = 0;

    /** Get the final result of the transaction. */
    virtual TransactionResult getTransactionResult() const = 0;
};

}  // namespace verifone_sdk
