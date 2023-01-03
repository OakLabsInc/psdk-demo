// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from PaymentSdk.djinni

#pragma once

#include <memory>
#include <psdk/export.h>

namespace verifone_sdk {

class Status;

/**
 * Add imports for the different djinni files to generate, or add the IDL interfaces directly.
 * Refer to https://github.com/dropbox/djinni for more information on the IDL structure.
 * @import "other_file.djinni"
 * Deprecated on 2020-06-01.
 * Please use {@link #CommerceListener2}.
 */
class PSDK_EXPORT PsdkStatusListener {
public:
    virtual ~PsdkStatusListener() {}

    virtual void handleEvent(const std::shared_ptr<Status> & status) = 0;
};

}  // namespace verifone_sdk
