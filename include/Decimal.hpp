/*
 * Copyright (c) 2021 by VeriFone, Inc.
 * All Rights Reserved.
 * THIS FILE CONTAINS PROPRIETARY INFORMATION
 * AND REMAINS THE PROPERTY OF VERIFONE, INC.
 *
 * Use, disclosure, or reproduction is prohibited
 * without prior written approval from VeriFone, Inc.
 */

#ifndef VERIFONE_SDK_SDK_ENTITIES_DECIMAL_H_
#define VERIFONE_SDK_SDK_ENTITIES_DECIMAL_H_

#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <psdk/export.h>

#include "Decimal_base.hpp"

#ifdef _WIN32
// Disable windows compiler reporting warning for multiple copy constructors
#pragma warning(disable : 4521)
#endif

namespace verifone_sdk {

struct PSDK_EXPORT Decimal : DecimalBase {
 public:
  static const int kMaxScale;
  static std::optional<Decimal> FromDecimalWithScale(const Decimal& other, int32_t scale1);
  static std::optional<Decimal> FromDouble(double value1);
  static std::optional<Decimal> FromDoubleWithScale(int32_t scale1, double value1);
  static std::optional<Decimal> Parse(const std::string value, const bool locale_dependent = false);
  static bool SetLocale(std::string locale_name);

  Decimal();
  Decimal(int64_t value1);
  Decimal(int32_t value1);
  Decimal(uint32_t value1);
  Decimal(int32_t scale1, int64_t value1);
  Decimal(int32_t scale1, int32_t value1);
  Decimal(int32_t scale1, uint32_t value1);
#ifdef __APPLE__
  Decimal(long value1);
  Decimal(int32_t scale1, long value1);
#endif
  Decimal(const Decimal& other);
  ~Decimal() override = default;

  double GetValue() const;
  int32_t GetScale() const;
  int64_t GetUnscaledValue() const;

  bool IsZero() const;
  bool operator==(const Decimal& other) const;

  PSDK_EXPORT friend std::ostream& operator<<(std::ostream& strm, const Decimal& a);
  PSDK_EXPORT friend std::optional<Decimal> operator+(const Decimal& lhs, const Decimal& rhs);
  PSDK_EXPORT friend std::optional<Decimal> operator*(const Decimal& lhs, const Decimal& rhs);
  PSDK_EXPORT friend std::optional<Decimal> operator-(const Decimal& lhs, const Decimal& rhs);
  PSDK_EXPORT friend std::optional<Decimal> operator/(const Decimal& lhs, const Decimal& rhs);
  // negtive trim_zeros_count will trim all zeros
  std::string ToString(const uint32_t display_precision = 2, const int trim_zeros_count = 0) const;
  std::string ToLocalizedString(const uint32_t display_precision = 2,
                                const bool currency = false) const;
  std::string ToLocalizedCurrencyString(const bool use_currency_precision = false,
                                        const bool drop_symbol = false) const;

 private:

#if defined(ANDROID)
  struct AndroidLocaleData {
    char dec_sep_;
    char group_sep_;
    int digits_;
    std::string currency_symbol_;
    std::string pos_suffix_;
    std::string pos_prefix_;
    std::string neg_suffix_;
    std::string neg_prefix_;
  };
  static std::unique_ptr<AndroidLocaleData> android_locale_;
  static void PopulateAndroidLocale();
#endif  // (ANDROID)
  static std::unique_ptr<std::locale> locale_instance_;
  static const char* kDecimalChars;
  static const int kThousandsGrouping;

  static int64_t AbsolutePowerOf10(int32_t x);
  static bool Convert(const double& d, int64_t& i64);
  static std::locale& GetLocale();
  static double ScaleValue(const double& value1, int32_t scale1);
  static std::optional<int64_t> ScaleValue(const int64_t& value1, int32_t scale1);
  static int64_t ScaleDown(const int64_t& value1, int32_t scale1);
  static double UnscaleValue(const int64_t value1, int32_t scale1);

  std::string ToStringPriv(const uint32_t display_precision,
                           const int trim_zeros_count,
                           const bool absolute = false,
                           const char decimal_separator = '.') const;
  bool SetValue(double value1);
};

}  // namespace verifone_sdk

#endif  // VERIFONE_SDK_SDK_ENTITIES_DECIMAL_H_
