/*
 * Copyright (c) 2021 by VeriFone, Inc.
 * All Rights Reserved.
 * THIS FILE CONTAINS PROPRIETARY INFORMATION
 * AND REMAINS THE PROPERTY OF VERIFONE, INC.
 *
 * Use, disclosure, or reproduction is prohibited
 * without prior written approval from VeriFone, Inc.
 */

#ifndef VERIFONE_SDK_SDK_UTILITY_UUID_H_
#define VERIFONE_SDK_SDK_UTILITY_UUID_H_

#include <string>
#include <psdk/export.h>

namespace verifone_sdk {

class PSDK_EXPORT Uuid {
 public:
 static const char* kUuidRegexStr;
 static const std::string Generate();
};

} // namespace verifone_sdk
#endif // VERIFONE_SDK_SDK_UTILITY_UUID_H_
