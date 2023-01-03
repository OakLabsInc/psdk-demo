/*
 * Copyright (c) 2021 by VeriFone, Inc.
 * All Rights Reserved.
 * THIS FILE CONTAINS PROPRIETARY INFORMATION
 * AND REMAINS THE PROPERTY OF VERIFONE, INC.
 *
 * Use, disclosure, or reproduction is prohibited
 * without prior written approval from VeriFone, Inc.
 */
#ifndef VERIFONE_SDK_SDK_ENTITIES_ACQUIRER_H_
#define VERIFONE_SDK_SDK_ENTITIES_ACQUIRER_H_

#include "Acquirer_base.hpp"

#include <optional>
#include <string>
#include <psdk/export.h>

namespace verifone_sdk {

struct PSDK_EXPORT Acquirer : AcquirerBase {
 public:
  Acquirer();
  Acquirer(std::optional<std::string> acquirer_id,
           std::optional<std::string> acquirer_name,
           std::optional<std::string> merchant_id,
           std::optional<std::string> acquirer_poiid);
  Acquirer(const Acquirer& acquirer) = default;
  ~Acquirer() override = default;
};

}  // namespace verifone_sdk

#endif  // VERIFONE_SDK_SDK_ENTITIES_ACQUIRER_H_
