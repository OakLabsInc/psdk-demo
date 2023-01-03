// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from ConnectionInterface.djinni

#pragma once

#include <cstdint>
#include <optional>
#include <psdk/export.h>
#include <vector>

namespace verifone_sdk {

enum class ConnectionStatus;

/**
 * A callback in the library to be notified by the connection owner for specific 
 * events.
 */
class PSDK_EXPORT ConnectionCallback {
public:
    virtual ~ConnectionCallback() {}

    /** Called when the status of the connection changes. */
    virtual void statusChanged(int32_t connectionId, ConnectionStatus newStatus) = 0;

    /** Notifies the callback that bytes have been written to the connection.  */
    virtual void bytesWritten(int32_t statusCode, int64_t byteCount) = 0;

    /**
     * Sends the bytes read to the callback. The status code should be set to 
     * some value besides {@link StatusCode#SUCCESS} if an error happened, and it's
     * best if the code can be one of the constants from {@link StatusCode}. 
     */
    virtual void bytesRead(int32_t statusCode, const std::optional<std::vector<uint8_t>> & bytes) = 0;
};

}  // namespace verifone_sdk
