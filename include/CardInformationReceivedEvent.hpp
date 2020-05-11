// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class CardInformation;
class Transaction;
class TransactionEventResponse;

/** Contains the value from customer input on the terminal. */
class CardInformationReceivedEvent {
public:
    virtual ~CardInformationReceivedEvent() {}

    /** Token query event type */
    static std::string const TYPE_TOKEN_QUERY;

    /** Card data event type */
    static std::string const TYPE_CARD_DATA;

    /** Status code indicating that the card data was received successfully */
    static constexpr int32_t SUCCESS = 0;

    /** Status code indicating that the card needs to be removed from the chip card reader */
    static constexpr int32_t REMOVE_CARD = 1;

    /** Status code indicating that the card was removed from the chip card reader */
    static constexpr int32_t CARD_REMOVED = 2;

    /**
     * Status code indicating that there was a timeout and no card was detected.
     * {@link TransactionManager#requestCardData(String, CardInformation.PresentationMethod[])} must
     * be called again after receiving an event with this status code to attempt detecting a card
     * again.
     */
    static constexpr int32_t TIMEOUT_NO_CARD_DETECTED = -1;

    /**
     * Status code indicating that there was an error and the card should be presented again.
     * There is no need to call {@link TransactionManager#requestCardData(String, CardInformation.PresentationMethod[])}
     * again after receiving an event with this status code.
     */
    static constexpr int32_t PLEASE_TRY_AGAIN = -2;

    /**
     * Status code indicating that the card should be presented in the chip card reader instead
     * There is no need to call {@link TransactionManager#requestCardData(String, CardInformation.PresentationMethod[])}
     * again after receiving an event with this status code.
     */
    static constexpr int32_t USE_CHIP_INSTEAD = -3;

    /**
     * Status code indicating that the card should be presented in the magnetic stripe reader instead
     * There is no need to call {@link TransactionManager#requestCardData(String, CardInformation.PresentationMethod[])}
     * again after receiving an event with this status code.
     */
    static constexpr int32_t USE_MSR_INSTEAD = -4;

    /**
     * A user-readable message.
     * This message may not be localized, in which case the type field should be used for
     * determining a localized message.
     */
    virtual std::optional<std::string> getMessage() const = 0;

    /** Get the session ID for the session which triggered this event. */
    virtual std::optional<std::string> getSessionId() const = 0;

    /**
     * The type of status. This will generally be SUCCESS for a status of 0, and contain a
     * different type for other errors. For example, in a refund or void, it is possible to
     * receive type TRANSACTION_NOT_FOUND. This may be used for localizing the specific
     * messages as needed
     */
    virtual std::optional<std::string> getType() const = 0;

    /**
     * Get the status for this particular event. A status of 0 means success,
     * any other status is a failure.
     */
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

    /**
     * Generate transaction event response for the current event.
     * @return empty response when a standard transaction event. Child classes may implement
     * appropriate responses as needed.
     */
    virtual std::shared_ptr<TransactionEventResponse> generateTransactionEventResponse() const = 0;

    /** Returns full object with all available card information encapsulated. */
    virtual std::shared_ptr<CardInformation> getCardInformation() const = 0;
};

}  // namespace verifone_sdk
