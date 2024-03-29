// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace verifone_sdk {

struct HostPaymentContext;
struct HostPaymentData;
struct HostSalesData;
struct HostTransaction;

class HostFinalizeTransactionEvent {
public:
    virtual ~HostFinalizeTransactionEvent() {}

    /** The event type */
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
     * The type of status. This will generally be SUCCESS for a status of 0, and contain a different
     * type for other errors.
     */
    virtual std::optional<std::string> getType() const = 0;

    /** Get the status for this particular event. A status of 0 means success, any other status is a failure. */
    virtual int32_t getStatus() const = 0;

    /** Returns an optional event ID as copied from the originating event. */
    virtual std::optional<std::string> getEventId() const = 0;

    /**
     * Returns the Host Payment Context
     *  See {@link HostPaymentContext}
     */
    virtual std::optional<HostPaymentContext> getHostPaymentContext() const = 0;

    /**
     * Returns the Host Payment Data
     *  See {@link HostPaymentData}
     */
    virtual std::optional<HostPaymentData> getHostPaymentData() const = 0;

    /**
     * Returns the Host Transaction Data
     *  See {@link HostTransaction}
     */
    virtual std::optional<HostTransaction> getHostTransaction() const = 0;

    /**
     * Returns the Host Sales Data
     *  See {@link HostSalesData}
     */
    virtual std::optional<HostSalesData> getHostSalesData() const = 0;
};

}  // namespace verifone_sdk
