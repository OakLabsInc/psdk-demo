/*
 * Copyright (c) 2020 by VeriFone, Inc.
 * All Rights Reserved.
 * THIS FILE CONTAINS PROPRIETARY AND CONFIDENTIAL INFORMATION
 * AND REMAINS THE UNPUBLISHED PROPERTY OF VERIFONE, INC.
 * Use, disclosure, or reproduction is prohibited
 * without prior written approval from VeriFone, Inc.
 */

#ifndef VERIFONE_SDK_SDK_PLATFORM_CONTEXT_LINUX_H_
#define VERIFONE_SDK_SDK_PLATFORM_CONTEXT_LINUX_H_

#include "PlatformContextInterface.hpp"

#include <memory>

namespace verifone_sdk {

/**
 * Create file-based platform context. If file_name parameter value is
 * set to std::nullopt the filename defaults to settings.json
 */
std::shared_ptr<PlatformContextInterface> CreatePlatformContextLinux(
    const std::optional<std::string>& file_name);

}  // namespace verifone_sdk

#endif  // VERIFONE_SDK_SDK_PLATFORM_CONTEXT_LINUX_H_
