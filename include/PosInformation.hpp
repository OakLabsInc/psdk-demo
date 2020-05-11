// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from PaymentSdk.djinni

#pragma once

#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class PlatformContextInterface;

/**
 * Information about the system that is currently using the PSDK. This is different from the 
 * PsdkDeviceInformation, which provides information about the Payment Terminal.
 */
class PosInformation {
public:
    virtual ~PosInformation() {}

    /** The key to store the applicationCertificationCode field. */
    static std::string const APPLICATION_CERTIFICATION_CODE_KEY;

    /** The key to store the applicationName field. */
    static std::string const APPLICATION_NAME_KEY;

    /** The key to store the applicationPublisher field. */
    static std::string const APPLICATION_PUBLISHER_KEY;

    /** The key to store the applicationVersion field. */
    static std::string const APPLICATION_VERSION_KEY;

    /** The key to store the deviceId field. */
    static std::string const DEVICE_ID_KEY;

    /** The key to store the deviceManufacturer field. */
    static std::string const DEVICE_MANUFACTURER_KEY;

    /** The key to store the deviceModel field. */
    static std::string const DEVICE_MODEL_KEY;

    /** The key to store the deviceOsName field. */
    static std::string const DEVICE_OS_NAME_KEY;

    /** The key to store the deviceOsVersion field. */
    static std::string const DEVICE_OS_VERSION_KEY;

    /** The key to store the deviceSerialNumber field. */
    static std::string const DEVICE_SERIAL_NUMBER_KEY;

    /** The key to store the address field. */
    static std::string const ADDRESS_KEY;

    /** The key to store the freeMemory field. */
    static std::string const FREE_MEMORY_KEY;

    /** The key to store the totalMemory field. */
    static std::string const TOTAL_MEMORY_KEY;

    /** The key to store the screenHeight field. */
    static std::string const SCREEN_HEIGHT_KEY;

    /** The key to store the screenWidth field. */
    static std::string const SCREEN_WIDTH_KEY;

    /** The key to store the supportsBluetooth field. */
    static std::string const SUPPORTS_BLUETOOTH_KEY;

    static std::shared_ptr<PosInformation> create();

    /** Populates the values in a platform-independent manner. */
    virtual void load(const std::shared_ptr<PlatformContextInterface> & platformContext) = 0;

    /** Stores all of the values in a platform-independent manner. */
    virtual void store(const std::shared_ptr<PlatformContextInterface> & platformContext) const = 0;

    /** The code that is granted to some applications after certifying with a specific host. */
    virtual std::optional<std::string> getApplicationCertificationCode() const = 0;

    /** Refer to {@link #getApplicationCertificationCode()}. */
    virtual void setApplicationCertificationCode(const std::optional<std::string> & code) = 0;

    /** The name of the application that is using the PSDK. */
    virtual std::optional<std::string> getApplicationName() const = 0;

    /** Refer to {@link #getApplicationName()}. */
    virtual void setApplicationName(const std::optional<std::string> & name) = 0;

    /** The name of the person or company that builds the application that is using the PSDK. */
    virtual std::optional<std::string> getApplicationPublisher() const = 0;

    /** Refer to {@link #getApplicationPublisher()}. */
    virtual void setApplicationPublisher(const std::optional<std::string> & publisher) = 0;

    /** The version of the application that is using the PSDK. */
    virtual std::optional<std::string> getApplicationVersion() const = 0;

    /** Refer to {@link #getApplicationVersion()}. */
    virtual void setApplicationVersion(const std::optional<std::string> & version) = 0;

    /** The logical ID of the device. */
    virtual std::optional<std::string> getDeviceId() const = 0;

    /** Refer to {@link #getDeviceId()}. */
    virtual void setDeviceId(const std::optional<std::string> & deviceId) = 0;

    /** The hardware manufacturer of the device. */
    virtual std::optional<std::string> getDeviceManufacturer() const = 0;

    /** Refer to {@link #getDeviceManufacturer()}. */
    virtual void setDeviceManufacturer(const std::optional<std::string> & manufacturer) = 0;

    /** The hardware model of the device. */
    virtual std::optional<std::string> getDeviceModel() const = 0;

    /** Refer to {@link #getDeviceModel()}. */
    virtual void setDeviceModel(const std::optional<std::string> & model) = 0;

    /** The name of the operating system. */
    virtual std::optional<std::string> getDeviceOsName() const = 0;

    /** Refer to {@link #getDeviceOsName()}. */
    virtual void setDeviceOsName(const std::optional<std::string> & name) = 0;

    /** The version of the operating system. */
    virtual std::optional<std::string> getDeviceOsVersion() const = 0;

    /** Refer to {@link #getDeviceOsVersion()}. */
    virtual void setDeviceOsVersion(const std::optional<std::string> & version) = 0;

    /** The hardware serial number. */
    virtual std::optional<std::string> getDeviceSerialNumber() const = 0;

    /** Refer to {@link #getDeviceSerialNumber()}. */
    virtual void setDeviceSerialNumber(const std::optional<std::string> & number) = 0;

    /** The POS address used for the connection to the terminal. */
    virtual std::optional<std::string> getAddress() const = 0;

    /** Refer to {@link #getAddress()}. */
    virtual void setAddress(const std::optional<std::string> & address) = 0;

    /** The available memory at the time of the call. */
    virtual std::optional<std::string> getFreeMemory() const = 0;

    /** Refer to {@link #getFreeMemory()}. */
    virtual void setFreeMemory(const std::optional<std::string> & memory) = 0;

    /** The total memory built into the system. */
    virtual std::optional<std::string> getTotalMemory() const = 0;

    /** Refer to {@link #getTotalMemory()}. */
    virtual void setTotalMemory(const std::optional<std::string> & memory) = 0;

    /** The height of the screen in pixels, if a screen is available. */
    virtual std::optional<std::string> getScreenHeight() const = 0;

    /** Refer to {@link #getScreenHeight()}. */
    virtual void setScreenHeight(const std::optional<std::string> & height) = 0;

    /** The width of the screen in pixels, if a screen is available. */
    virtual std::optional<std::string> getScreenWidth() const = 0;

    /** Refer to {@link #getScreenWidth()}. */
    virtual void setScreenWidth(const std::optional<std::string> & width) = 0;

    /**
     * True if the system has bluetooth, false if it is verified that the current 
     * system cannot do bluetooth, or empty if unknown.
     */
    virtual std::optional<bool> isBluetoothSupported() const = 0;

    /** Refer to {@link #isBluetoothSupported()}. */
    virtual void setBluetoothSupported(std::optional<bool> isSupported) = 0;
};

}  // namespace verifone_sdk
