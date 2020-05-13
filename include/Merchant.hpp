/*
 * Copyright (c) 2020 by VeriFone, Inc.
 * All Rights Reserved.
 * THIS FILE CONTAINS PROPRIETARY INFORMATION
 * AND REMAINS THE PROPERTY OF VERIFONE, INC.
 *
 * Use, disclosure, or reproduction is prohibited
 * without prior written approval from VeriFone, Inc.
 */
#ifndef VERIFONE_SDK_SDK_ENTITIES_MERCHANT_H_
#define VERIFONE_SDK_SDK_ENTITIES_MERCHANT_H_

#include "Merchant_base.hpp"

#include <optional>
#include <string>

namespace verifone_sdk {

struct Merchant : MerchantBase {
public:
  Merchant();
  Merchant(std::optional<std::string> record_id,
           std::optional<std::string> merchant_name,
           std::optional<std::string> merchant_address);
  Merchant(const Merchant& merchant);
  ~Merchant() override = default;
};

} // namespace verifone_sdk

#endif // VERIFONE_SDK_SDK_ENTITIES_MERCHANT_H_
