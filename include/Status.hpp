// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce.djinni

#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace verifone_sdk {

/**
 * The foundational Status class.
 * This provides the structure for the return values of many of the API calls
 */
class Status {
public:
    virtual ~Status() {}

    /** The constant status type for success. */
    static std::string const STATUS_SUCCESS;

    /** The constant status type for a general error. */
    static std::string const STATUS_ERROR;

    /** The constant status type for initialized. */
    static std::string const STATUS_INITIALIZED;

    /** The constant status type for setup complete. */
    static std::string const STATUS_SETUP_COMPLETE;

    /**
     * A user-readable message.
     * This message may not be localized, in which case the type field should be used for
     * determining a localized message.
     */
    virtual std::optional<std::string> getMessage() const = 0;

    /**
     * TODO(RobertF8): Move session ID to CommerceEvent, it's not relevant here.
     * Get the session ID for the session which triggered this event.
     */
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
};

}  // namespace verifone_sdk
