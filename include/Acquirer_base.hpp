// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from Acquirer.djinni

#pragma once

#include <optional>
#include <psdk/export.h>
#include <string>
#include <utility>

namespace verifone_sdk {

struct Acquirer; // Requiring extended class

/** Represents a PaymentAcquirerData. */
struct PSDK_EXPORT AcquirerBase {
    /** Key in the Acquirer Table */
    std::optional<std::string> acquirerId;
    /** The name of the acquirer, used for display to the cashier. */
    std::optional<std::string> acquirerName;
    /** The CAID, aka Merchant ID, aka MID */
    std::optional<std::string> merchantId;
    /** The CATID, aka TID or terminal Identifier of the terminal */
    std::optional<std::string> acquirerPoiid;

    AcquirerBase(std::optional<std::string> acquirerId_,
                 std::optional<std::string> acquirerName_,
                 std::optional<std::string> merchantId_,
                 std::optional<std::string> acquirerPoiid_)
    : acquirerId(std::move(acquirerId_))
    , acquirerName(std::move(acquirerName_))
    , merchantId(std::move(merchantId_))
    , acquirerPoiid(std::move(acquirerPoiid_))
    {}

    virtual ~AcquirerBase() = default;

protected:
    AcquirerBase(const AcquirerBase&) = default;
    AcquirerBase(AcquirerBase&&) = default;
    AcquirerBase& operator=(const AcquirerBase&) = default;
    AcquirerBase& operator=(AcquirerBase&&) = default;
};

}  // namespace verifone_sdk