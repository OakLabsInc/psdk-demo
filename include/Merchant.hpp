/*
 * Copyright (c) 2021 by VeriFone, Inc.
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
#include <unordered_map>
#include <vector>
#include <psdk/export.h>

namespace verifone_sdk {

struct PSDK_EXPORT Merchant : MerchantBase {
public:
  Merchant();
  Merchant(std::optional<std::string> record_id,
           std::optional<std::string> merchant_name,
           std::optional<std::string> merchant_address,
           std::optional<std::string> country_code,
           std::optional<std::string> merchant_category_code,
           std::optional<bool> is_primary_flag,
           std::optional<bool> is_balance_enquiry,
           std::optional<Decimal> cashout_ceiling,
           std::optional<bool> is_cashout_only_enabled,
           std::optional<bool> is_force_offline_enabled,
           std::optional<bool> is_manual_preauth_enabled,
           std::optional<bool> is_manual_purchase_enabled,
           std::optional<bool> is_manual_refund_enabled,
           std::optional<Decimal> max_purchase_amount,
           std::optional<bool> is_moto_payment_enabled,
           std::optional<bool> is_moto_refund_enabled,
           std::optional<std::string> phone_number,
           std::optional<bool> is_preauth_enabled,
           std::optional<bool> is_purchase_and_cashout_enabled,
           std::optional<bool> is_purchase_enabled,
           std::optional<bool> is_refund_enabled,
           std::optional<bool> is_tip_prompt_enabled,
           std::optional<bool> is_void_enabled,
           std::vector<Acquirer> acquirers,
           std::vector<std::string> currencies,
           std::unordered_map<std::string, std::string> config,
           std::vector<AlternativePaymentMethod> alternative_payment_methods);
  Merchant(const Merchant& merchant) = default;
  ~Merchant() override = default;
};

} // namespace verifone_sdk

#endif // VERIFONE_SDK_SDK_ENTITIES_MERCHANT_H_
