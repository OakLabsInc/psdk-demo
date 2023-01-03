// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from DeviceVitals.djinni

#pragma once

#include "HostStatus.hpp"
#include "PrinterStatus.hpp"
#include <cstdint>
#include <optional>
#include <psdk/export.h>
#include <utility>
#include <vector>

namespace verifone_sdk {

/** Represents DeviceVitals. */
struct PSDK_EXPORT DeviceVitals final {
    /** The overall status of the terminal. Possible values are SUCCESS/BUSY/UNAVAILABLE */
    int32_t globalStatus;
    /** Indicates if the printer is working and usable. {@link #PrinterStatus} */
    std::optional<PrinterStatus> printerStatus;
    /** Indicates if the security module of the terminal is working and usable. */
    std::optional<bool> isSecurityOk;
    /** Indicates if the PIN-entry device is working and usable. */
    std::optional<bool> isPedOk;
    /** Indicates if the card reader is working and usable. */
    std::optional<bool> isCardReaderOk;
    /** Indicates if the communication infrastructure is working and usable. */
    std::optional<bool> isCommunicationOk;
    /** Indicates a suspicion of fraud detected by the terminal. */
    std::optional<bool> isFraudPreventionDetected;
    /** List of hosts connected to the terminal and their reachability status. */
    std::vector<HostStatus> hostStatus;

    DeviceVitals(int32_t globalStatus_,
                 std::optional<PrinterStatus> printerStatus_,
                 std::optional<bool> isSecurityOk_,
                 std::optional<bool> isPedOk_,
                 std::optional<bool> isCardReaderOk_,
                 std::optional<bool> isCommunicationOk_,
                 std::optional<bool> isFraudPreventionDetected_,
                 std::vector<HostStatus> hostStatus_)
    : globalStatus(std::move(globalStatus_))
    , printerStatus(std::move(printerStatus_))
    , isSecurityOk(std::move(isSecurityOk_))
    , isPedOk(std::move(isPedOk_))
    , isCardReaderOk(std::move(isCardReaderOk_))
    , isCommunicationOk(std::move(isCommunicationOk_))
    , isFraudPreventionDetected(std::move(isFraudPreventionDetected_))
    , hostStatus(std::move(hostStatus_))
    {}
};

}  // namespace verifone_sdk
