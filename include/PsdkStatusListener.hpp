// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from PaymentSdk.djinni

#pragma once

#include <memory>

namespace verifone_sdk {

class Status;

class PsdkStatusListener {
public:
    virtual ~PsdkStatusListener() {}

    virtual void handleEvent(const std::shared_ptr<Status> & status) = 0;
};

}  // namespace verifone_sdk