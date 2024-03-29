// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from SdiManager.djinni

#pragma once

#include <cstdint>
#include <memory>

namespace verifone_sdk {

class SdiTlv;

/** Control callback interface. */
class SdiControlCallback {
public:
    virtual ~SdiControlCallback() {}

    /**
     * param t TLV data received from SDI server
     * return
     *    - 1: continue (perform next step)
     *    - 2: reenter last value (input field is cleared)
     *    - 3: abort
     * note Important: The callback function must not invoke any method of the
     * same SDIClient object or a deadlock may occur.
     */
    virtual int32_t callback(const std::shared_ptr<SdiTlv> & tlvData) = 0;
};

}  // namespace verifone_sdk
