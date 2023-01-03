// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from PaymentSdk.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <psdk/export.h>
#include <string>
#include <unordered_map>

namespace verifone_sdk {

class AccessibilityManager;
class CommerceListener2;
class ConnectionInterface;
class PlatformContextInterface;
class TransactionManager;
enum class PsdkLogLevel;
struct PsdkDeviceInformation;

/**
 * The PaymentSdk is the main entry point for the SDK.
 * Connection management is handled by this component.
 */
class PSDK_EXPORT PaymentSdkInterface {
public:
    virtual ~PaymentSdkInterface() {}

    static std::shared_ptr<PaymentSdkInterface> create(const std::shared_ptr<PlatformContextInterface> & platformContext);

    static std::string getVersion();

    /**
     * Sets the filename (including path) and maximum size (in KiB) for the log.
     * The log will be truncated on reaching maximum size. Can be called before Initialize().
     */
    static bool configureLogFile(const std::string & filename, int64_t size);

    /**
     * Sets the filename (including path), maximum size (in KiB) and number of rotated files for the log.
     * On reaching maximum size the current log file will be renamed to .1 index moving the existing .1 file
     * to .2 index and so on, up to the number supplied as rotate parameter
     */
    static bool configureLogFileWithRotation(const std::string & filename, int64_t size, int64_t rotate);

    /** Sets the log verbosity to desired level */
    static void configureLogLevel(PsdkLogLevel level);

    /**
     * Initializes the SDK, checking that the configuration is correct and the 
     * Engage device is configured and reachable. The listener receives a Status 
     * with type Status.STATUS_INITIALIZED. Expect StatusCode.SetupRequired 
     * to be sent if the device is not configured. Internally, create the platform 
     * context, coordinator, load the configuration, and initialize the various 
     * modules such as transport, payment adapter, and navigator.
     */
    virtual void initialize(const std::shared_ptr<CommerceListener2> & listener) = 0;

    /**
     * Initializes the SDK using the values read from the file combined with the 
     * values configured by the user and detected by the system. It's important 
     * that the application already has the necessary permissions to read this 
     * file, the SDK will only try to read it directly. The file must be configured 
     * according to the configuration file documentation.
     */
    virtual void initializeFromFile(const std::shared_ptr<CommerceListener2> & listener, const std::string & path) = 0;

    /** Initializes the SDK using a parameter map passed into the method. */
    virtual void initializeFromValues(const std::shared_ptr<CommerceListener2> & listener, const std::unordered_map<std::string, std::string> & config) = 0;

    /**
     * Initializes the SDK using a parameter map passed into the method and using 
     * the provided connection.
     */
    virtual void initializeWithConnection(const std::shared_ptr<CommerceListener2> & listener, const std::unordered_map<std::string, std::string> & config, const std::shared_ptr<ConnectionInterface> & connection) = 0;

    /**
     * Displays the current configuration, or launches the setup wizard if setup is
     * required. This is useful both when handling StatusCode.SetupRequired and
     * displaying a general settings screen. This should be overridden by a method
     * that also accepts the appropriate context/controller to display the setup
     * screens, or returns the controller to be pushed onto the stack, this method
     * is only provided to require subclasses to implement the necessary command,
     * and should be hidden or restricted from being called directly.
     */
    virtual void displayConfiguration(const std::shared_ptr<CommerceListener2> & listener) = 0;

    /**
     * Allows adding new listeners for events.
     * @param listener A listener for events.
     */
    virtual void addListener(const std::shared_ptr<CommerceListener2> & listener) = 0;

    /**
     * Removes a listener. The last listener cannot be removed through this method,
     * as there must always be a listener until the PSDK is torn down.
     * @param listener A registered listener for the session events.
     */
    virtual void removeListener(const std::shared_ptr<CommerceListener2> & listener) = 0;

    /**
     * Simply returns the cached information about the device, does not perform 
     * any type of query to the device. 
     */
    virtual std::optional<PsdkDeviceInformation> getDeviceInformation() = 0;

    /**
     * Teardown the session and all associated connections. Any objects that were 
     * returned from methods like getTransactionManager() will also be torn down 
     * after this call and any remaining references should not be used.
     */
    virtual void tearDown() = 0;

    /**
     * Get AccessibilityManager for this session.
     * Must have called setupSession successfully prior to making this call
     */
    virtual std::shared_ptr<AccessibilityManager> getAccessibilityManager() = 0;

    /**
     * Get TransactionManager for this session
     * Must have called setupSession successfully prior to making this call
     */
    virtual std::shared_ptr<TransactionManager> getTransactionManager() = 0;

    /** Sets/Removes this device as the one to use for future connections. */
    virtual void UseDevice(const PsdkDeviceInformation & device, bool saveDevice) = 0;
};

}  // namespace verifone_sdk
