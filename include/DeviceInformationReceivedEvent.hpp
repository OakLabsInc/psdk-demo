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
enum class PaymentDeviceState;
struct PsdkDeviceInformation;

/**
 * Contains information on the device. Sent in response to the
 * {@link TransactionManager#getDeviceInformation()} method.
 */
class DeviceInformationReceivedEvent {
public:
    virtual ~DeviceInformationReceivedEvent() {}

    /** Device information received event type */
    static std::string const TYPE;

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

    /** The merchant ID according to the primary acquirer. */
    virtual std::optional<std::string> getAcquirerMerchantId() const = 0;

    /** The terminal ID according to the primary acquirer. */
    virtual std::optional<std::string> getAcquirerTerminalId() const = 0;

    /**
     * The Device ID, as assigned by the device management system. 
     * Useful when matching this device to the cloud APIs.
     */
    virtual std::optional<std::string> getLogicalDeviceId() const = 0;

    /**
     * The Device ID, as determined by the hardware. This may be different than the hardware ID as
     * returned by the current OS, as it is generally tied to the PCI-PTS device.
     */
    virtual std::optional<std::string> getHardwareDeviceId() const = 0;

    /** The payment application name. */
    virtual std::optional<std::string> getPaymentApplicationName() const = 0;

    /** The software version of the payment application. */
    virtual std::optional<std::string> getPaymentApplicationVersion() const = 0;

    /** The current or most recently known state of the payment device */
    virtual PaymentDeviceState getState() const = 0;

    /** Get device debug mode */
    virtual int32_t getDebugMode() const = 0;

    /** Get the device information as a whole */
    virtual std::optional<PsdkDeviceInformation> getDeviceInformation() const = 0;
};

}  // namespace verifone_sdk
