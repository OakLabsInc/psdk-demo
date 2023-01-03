/*
 * Copyright (c) 2021 by VeriFone, Inc.
 * All Rights Reserved.
 * THIS FILE CONTAINS PROPRIETARY INFORMATION
 * AND REMAINS THE PROPERTY OF VERIFONE, INC.
 *
 * Use, disclosure, or reproduction is prohibited
 * without prior written approval from VeriFone, Inc.
 */

#ifndef VERIFONE_SDK_SDK_NATIVE_PLATFORM_CONTEXT_H_
#define VERIFONE_SDK_SDK_NATIVE_PLATFORM_CONTEXT_H_

#include "PlatformContextInterface.hpp"

#include <memory>
#include <psdk/export.h>

namespace verifone_sdk {

/**
 * Create file-based platform context. If file_name parameter value is
 * set to std::nullopt the filename defaults to settings.json
 */
PSDK_EXPORT std::shared_ptr<PlatformContextInterface> CreateNativePlatformContext(
    const std::optional<std::string>& file_name);

}  // namespace verifone_sdk

#endif  // VERIFONE_SDK_SDK_NATIVE_PLATFORM_CONTEXT_H_
