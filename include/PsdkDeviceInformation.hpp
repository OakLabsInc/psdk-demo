// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from PaymentSdk.djinni

#pragma once

#include "PaymentDeviceState.hpp"
#include <optional>
#include <string>
#include <utility>

namespace verifone_sdk {

/**
 * User-displayable information about the connected device and the SDK. 
 * Some values may not be available depending on the connection type and the 
 * messages that have been sent up to this point.
 */
struct PsdkDeviceInformation final {

    /** The key to store connection type of the saved device. */
    static std::string const DEVICE_CONNECTION_TYPE_KEY;

    /** The key to store serial number of the saved device. */
    static std::string const DEVICE_SERIAL_NUMBER_KEY;

    /** The key to store device model of the saved device. */
    static std::string const DEVICE_MODEL_KEY;

    /** The key to store if has navigator support of the saved device. */
    static std::string const DEVICE_HAS_NAVIGATOR_KEY;

    /** The key to store logical id of the saved device. */
    static std::string const DEVICE_LOGICAL_ID_KEY;

    /**
     * The key to store device address of the saved device. Used during 
     * initialization to select a specific device at a specific address.
     */
    static std::string const DEVICE_ADDRESS_KEY;

    /** The key to store the state of the device */
    static std::string const DEVICE_STATE_KEY;
    /** Connection type, e.g., TCP/IP, Bluetooth or USB. */
    std::string connectionType;
    /**
     * The address used for the connection, e.g. IP Address for network 
     * connections, MAC address for Bluetooth, or COM port for USB.
     */
    std::string address;
    /** The serial number or hardware device ID associated with the device. */
    std::string serialNumber;
    /** The model of the device, e.g., M440.  */
    std::string model;
    /**
     * Whether or not Navigator is available on the current device. If Navigator 
     * is not available, any related operations will return with the 
     * NAVIGATOR_NOT_AVAILABLE status code.
     */
    std::optional<bool> hasNavigator;
    /** The Payment Protocol in use for payment operations. */
    std::string paymentProtocol;
    /** The name of the payment app, generally specific to the region. */
    std::string paymentAppName;
    /**
     * The version of the payment app, generally specific to the region, and may 
     * or may not follow a normal versioning convention.
     */
    std::string paymentAppVersion;
    /**
     * The device ID assigned by the terminal management system or some similar 
     * system. Useful for support.
     */
    std::string logicalDeviceId;
    /** The current or most recently known state of the payment device */
    PaymentDeviceState state;
    /**
     * Set to false if the device connects to us, or true if we connect to it.
     * If this is false, then it is equivalent to setting TransactionManager::DEVICE_LISTEN_KEY to 
     * the ENABLED_VALUE, because if this is false, then the PSDK must listen for the device.
     */
    bool isListening;

    PsdkDeviceInformation(std::string connectionType_,
                          std::string address_,
                          std::string serialNumber_,
                          std::string model_,
                          std::optional<bool> hasNavigator_,
                          std::string paymentProtocol_,
                          std::string paymentAppName_,
                          std::string paymentAppVersion_,
                          std::string logicalDeviceId_,
                          PaymentDeviceState state_,
                          bool isListening_)
    : connectionType(std::move(connectionType_))
    , address(std::move(address_))
    , serialNumber(std::move(serialNumber_))
    , model(std::move(model_))
    , hasNavigator(std::move(hasNavigator_))
    , paymentProtocol(std::move(paymentProtocol_))
    , paymentAppName(std::move(paymentAppName_))
    , paymentAppVersion(std::move(paymentAppVersion_))
    , logicalDeviceId(std::move(logicalDeviceId_))
    , state(std::move(state_))
    , isListening(std::move(isListening_))
    {}
};

}  // namespace verifone_sdk
