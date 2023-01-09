// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from HostStatus.djinni

#pragma once

#include <optional>
#include <psdk/export.h>
#include <string>
#include <utility>

namespace verifone_sdk {

/** Represents HostStatus */
struct PSDK_EXPORT HostStatus final {
    /** The identification of the Acquirer */
    std::optional<std::string> acquirerId;
    /** Indicates the reachability of the host by the terminal */
    std::optional<bool> isReachable;

    HostStatus(std::optional<std::string> acquirerId_,
               std::optional<bool> isReachable_)
    : acquirerId(std::move(acquirerId_))
    , isReachable(std::move(isReachable_))
    {}
};

}  // namespace verifone_sdk