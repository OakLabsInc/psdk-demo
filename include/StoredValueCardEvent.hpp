// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class Payment;
class StoredValueCardInformation;
class Transaction;
class TransactionEventResponse;
struct Decimal;

/** An event fired for all interactions with a stored value card. */
class StoredValueCardEvent {
public:
    virtual ~StoredValueCardEvent() {}

    /** A stored value card has been successfully activated. */
    static std::string const STORED_VALUE_CARD_ACTIVATED;

    /** A stored value card has been successfully reloaded. */
    static std::string const STORED_VALUE_CARD_RELOADED;

    /** A stored value card has been successfully unloaded. */
    static std::string const STORED_VALUE_CARD_UNLOADED;

    /** A stored value card balance has been successfully retrieved. */
    static std::string const STORED_VALUE_CARD_BALANCE_RETRIEVED;

    /**
     * Deprecated on 2018-11-01.
     * Please use {@link #STORED_VALUE_CARD_ACTIVATED} with a non-zero status code instead.
     * A stored value card has failed to activate.
     */
    static std::string const STORED_VALUE_CARD_ACTIVATION_FAILED;

    /**
     * Deprecated on 2018-11-01.
     * Please use {@link #STORED_VALUE_CARD_RELOADED} with a non-zero status code instead.
     * A stored value card has failed to reload.
     */
    static std::string const STORED_VALUE_CARD_RELOAD_FAILED;

    /**
     * Deprecated on 2018-11-01.
     * Please use {@link #STORED_VALUE_CARD_UNLOADED} with a non-zero status code instead.
     * A stored value card has failed to unload.
     */
    static std::string const STORED_VALUE_CARD_UNLOAD_FAILED;

    /**
     * Deprecated on 2018-11-01.
     * Please use {@link #STORED_VALUE_CARD_BALANCE_RETRIEVED} with a non-zero status code instead.
     * A stored value card balance has not been retrieved.
     */
    static std::string const STORED_VALUE_CARD_BALANCE_RETRIEVAL_FAILED;

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

    /**
     * Returns the payment object associated with this StoredValueCardEvent
     * {@link StoredValueCardInformation}.
     */
    virtual std::shared_ptr<Payment> getPayment() const = 0;

    /** A convenient method to retrieve the {@link StoredValueCardInformation} from the Payment. */
    virtual std::shared_ptr<StoredValueCardInformation> getStoredValueCardInformation() const = 0;

    /** A convenient method to retrieve the available balance from the card information, if available. */
    virtual std::optional<Decimal> getAvailableBalance() const = 0;

    /** A convenient method to retrieve the amount due back to the customer. */
    virtual std::optional<Decimal> getCashbackAmount() const = 0;
};

}  // namespace verifone_sdk