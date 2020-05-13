// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from SdiManager.djinni

#pragma once

#include <cstdint>

namespace verifone_sdk {

/** Navigator callback interface. */
class SdiNavigatorCallback {
public:
    virtual ~SdiNavigatorCallback() {}

    /**
     * param status navigator status:
     *   - 00 Digit selected
     *   - 01 OK selected
     *   - 02 Cancel selected
     *   - 03 Backspace/Clear selected
     *   - 04 Multiple touches detected
     *   - 05 Pin digit underflow
     *   - 06 Pin digit overflow
     *   - 10 Selection confirmed
     * note Important: The callback function must not invoke any method of the
     * same SDIClient object or a deadlock may occur.
     */
    virtual void callback(int32_t status) = 0;
};

}  // namespace verifone_sdk
