/*
 * Copyright (c) 2021 by VeriFone, Inc.
 * All Rights Reserved.
 * THIS FILE CONTAINS PROPRIETARY INFORMATION
 * AND REMAINS THE PROPERTY OF VERIFONE, INC.
 *
 * Use, disclosure, or reproduction is prohibited
 * without prior written approval from VeriFone, Inc.
 */
#ifndef VERIFONE_SDK_SDK_ENTITIES_ALTERNATIVE_PAYMENT_METHOD_H_
#define VERIFONE_SDK_SDK_ENTITIES_ALTERNATIVE_PAYMENT_METHOD_H_

#include "AlternativePaymentMethod_base.hpp"

#include <optional>
#include <string>
#include <psdk/export.h>

namespace verifone_sdk {

struct PSDK_EXPORT AlternativePaymentMethod : AlternativePaymentMethodBase {
public:
  AlternativePaymentMethod()
        : AlternativePaymentMethod(std::nullopt,std::nullopt) {};
  AlternativePaymentMethod(std::optional<std::string> apm_id,
           std::optional<std::string> apm_display_name) 
        : AlternativePaymentMethodBase(apm_id, apm_display_name) {};
  AlternativePaymentMethod(const AlternativePaymentMethod& alternative_payment_method) = default;
  ~AlternativePaymentMethod() override = default;
};

} // namespace verifone_sdk

#endif // VERIFONE_SDK_SDK_ENTITIES_ALTERNATIVE_PAYMENT_METHOD_H_
