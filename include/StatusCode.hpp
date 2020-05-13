// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce.djinni

#pragma once

#include <cstdint>
#include <utility>

namespace verifone_sdk {

/**
 * Known status codes. 
 * Purposes of a predefined status code:
 *   - The error can be handled heuristically by the POS, e.g., recieving 
 *     device_not_ready should retry the command after a short delay without user 
 *     input.
 *   - The POS may want to translate the error message itself, instead of the 
 *     localized prompts that we provide.
 *   - The POS might need to display a different prompt than the normal error 
 *     message, e.g., show a "Display Configuration" button in addition to the 
 *     standard "Cancel" and "Retry" buttons for the other error prompts.
 */
struct StatusCode final {

    /** The constant status code for success. */
    static constexpr int32_t SUCCESS = 0;

    /**
     * An error code that is not defined elsewhere. The message should be displayed 
     * to the user with options to retry, abort, or wait.
     */
    static constexpr int32_t GENERAL_ERROR = -1;

    /**
     * A device is configured but could not be found using the known connections. 
     * The message should be displayed to the current user so that they can make 
     * sure that the device is turned on, connected, and ready.
     */
    static constexpr int32_t DEVICE_NOT_FOUND = -2;

    /**
     * The device can be contacted, but it is still loading or otherwise preparing. 
     * Resend the command after a brief delay to allow it to finish preparing.
     */
    static constexpr int32_t DEVICE_NOT_READY = -3;

    /**
     * The connection was not able to be established with the device. This can 
     * happen because the device cannot pair with another device, or the network 
     * fails, or a variety of reasons. This should include an option to launch 
     * DeviceConfiguration() for more information.
     */
    static constexpr int32_t DEVICE_CONNECTION_FAILED = -4;

    /** The connection to the device has been lost unexpectedly. */
    static constexpr int32_t DEVICE_CONNECTION_LOST = -5;

    /**
     * The device is currently handling other commands or interacting with other 
     * devices and cannot perform the request. The request should be retried after 
     * a period of time, and it might be helpful to display the error to the user.
     */
    static constexpr int32_t DEVICE_BUSY = -6;

    /**
     * A general warning about the device, such as a low battery, with a message 
     * that should be displayed to the user, but does not require input.
     */
    static constexpr int32_t DEVICE_WARNING = -7;

    /**
     * A general error has occurred with the device, such as powering off due to 
     * insufficient battery. The message should be displayed to the user, and 
     * should include an option to launch DeviceConfiguration() for more 
     * information.
     */
    static constexpr int32_t DEVICE_ERROR = -8;

    /**
     * Unable to pair, unexpected server response to request. Only occurs when the 
     * host or a server decides which devices are allowed to connect to this 
     * terminal. This is rare. This cannot be retried, and generally implies that 
     * tech support should be contacted.
     */
    static constexpr int32_t DEVICE_REJECTED_PAIRING = -9;

    /**
     * The command requested is not allowed, most likely due to the permission 
     * granted to the application or the user.
     */
    static constexpr int32_t NOT_ALLOWED = -10;

    /** The operation was cancelled on the customer-facing display. */
    static constexpr int32_t CANCELLED = -11;

    /** The operation was aborted by using the abort command. */
    static constexpr int32_t ABORTED = -12;

    /**
     * Reauthenticaton required. This can occur when the current configuration is 
     * now out-of-date and must be updated, or the terminal must reauthenticate 
     * with the host to continue working. The POS can either call Login() 
     * automatically, or prompt the user to login.
     */
    static constexpr int32_t REAUTHENTICATION_REQUIRED = -13;

    /**
     * Contact acquirer. Terminal should provide any relevant details for the 
     * merchant when contacting the acquirer, including phone #, account 
     * information, and the reason.
     */
    static constexpr int32_t CONTACT_ACQUIRER = -14;

    /**
     * The current state cannot process the command. This refers to the state as 
     * returned by TransactionManager.getState(). The state should be retrieved, 
     * and the proper steps taken to enter the desired state.
     */
    static constexpr int32_t INVALID_STATE = -20;

    /**
     * Returned when the internal configuration of the SDK is invalid. This should 
     * generally be resolved during development, and should not occur in 
     * production. This command cannot be retried, the configuration should be 
     * fixed before proceeding.
     */
    static constexpr int32_t INVALID_CONFIGURATION = -21;

    /**
     * Returned when the command is missing some required field. This should 
     * generally be resolved during development, though it might occur in 
     * production when moving to a different region without testing.
     */
    static constexpr int32_t INVALID_ARGUMENTS = -22;

    /**
     * Command is already in progress. For example, when a payment is currently in 
     * progress and another payment is started. The current payment must be 
     * completed before another payment can be started. This can occur for other 
     * similar commands as well.
     */
    static constexpr int32_t COMMAND_IN_PROGRESS = -23;

    /**
     * Invalid command. Occurs when the current device does not support the 
     * requested command. Please use the isCapable() methods to determine if the 
     * action can be performed before calling the API to avoid this error.
     */
    static constexpr int32_t UNSUPPORTED_COMMAND = -24;

    /**
     * A response was not received from the terminal in time. If this happens 
     * during a payment, querying the last transaction status can help recover. 
     * For most other operations, the command can simply be reissued.
     */
    static constexpr int32_t COMMAND_TIMED_OUT = -25;

    /**
     * The SDK requires configuration, generally because no devices have been paired. 
     * This generally happens during the first time the app is being used, and will 
     * not happen on subsequent launches, unless the persistent app data is lost. 
     * Please use the DisplayConfiguration method when this is encountered.
     */
    static constexpr int32_t CONFIGURATION_REQUIRED = -30;

    /** Missing listener. Please attach a listener to perform any actions. */
    static constexpr int32_t MISSING_LISTENER = -31;

    /**
     * Must Support Receipt Printing. 
     * TODO: Indicate if the POS that it can handle the receipt
     */
    static constexpr int32_t RECEIPT_SUPPORT_REQUIRED = -32;
};

}  // namespace verifone_sdk