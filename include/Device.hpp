/*
 * Copyright (c) 2018 by VeriFone, Inc.
 * All Rights Reserved.
 * THIS FILE CONTAINS PROPRIETARY AND CONFIDENTIAL INFORMATION
 * AND REMAINS THE UNPUBLISHED PROPERTY OF VERIFONE, INC.
 *
 * Use, disclosure, or reproduction is prohibited
 * without prior written approval from VeriFone, Inc.
 */

#ifndef VERIFONE_SDK_SDK_ENTITIES_DEVICE_H_
#define VERIFONE_SDK_SDK_ENTITIES_DEVICE_H_

#include "Device_base.hpp"

#include <optional>
#include <string>

namespace verifone_sdk {

struct Device : DeviceBase {
 public:
  Device();
  Device(const Device& device);
  Device(std::optional<std::string> device_id,
         std::optional<std::string> device_name);
  ~Device() override = default;
};

} // namespace verifone_sdk

#endif // VERIFONE_SDK_SDK_ENTITIES_DEVICE_H_
