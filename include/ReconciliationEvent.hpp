// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment_reports.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace verifone_sdk {

class Receipt;
class ReconciliationTotal;
class Transaction;
class TransactionEventResponse;

/** Sent to the appropriate listener in response to reconciliation requests. */
class ReconciliationEvent {
public:
    virtual ~ReconciliationEvent() {}

    /** The event type */
    static std::string const TYPE;

    static std::string const ACTIVE_TOTALS_TYPE;

    static std::string const GROUP_TOTALS_TYPE;

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

    /** The ID for this reconciliation, or null if not relevant. */
    virtual std::optional<std::string> getReconciliationId() const = 0;

    /**
     * The reconciliation totals, useful for generating a Z report when the type is {@link #TYPE},
     * or an X report when the type is {@link #ACTIVE_TOTALS_TYPE}.
     */
    virtual std::optional<std::vector<std::shared_ptr<ReconciliationTotal>>> getReconciliationTotals() const = 0;

    /**
     * In some cases, the terminal will generate this report in an easily-printed fashion. Use
     * the {@link Receipt#getAsHtml()} to obtain an HTML document that can be easily printed.
     */
    virtual std::shared_ptr<Receipt> getReport() const = 0;
};

}  // namespace verifone_sdk
