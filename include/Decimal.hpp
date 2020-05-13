/*
 * Copyright (c) 2020 by VeriFone, Inc.
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

#include "Decimal_base.hpp"

#ifdef _WIN32
//Disable windows compiler reporting warning for multiple copy constructors
#pragma warning(disable : 4521)
#endif

namespace verifone_sdk {

struct Decimal : DecimalBase {
 public:
  static std::optional<Decimal> FromDecimalWithScale(const Decimal& other, int32_t scale1);
  static std::optional<Decimal> FromDouble(double value1);
  static std::optional<Decimal> FromDoubleWithScale(int32_t scale1, double value1);
  static std::optional<Decimal> Parse(const std::string value, const bool locale_dependent = false);
  static bool SetLocale(std::string locale_name);

  Decimal();
  Decimal(int64_t value1);
  Decimal(int32_t value1);
  Decimal(int32_t scale1, int64_t value1);
  Decimal(int32_t scale1, int32_t value1);
  Decimal(const Decimal& other);
  ~Decimal() override = default;

  double GetValue() const;
  int32_t GetScale() const;
  int64_t GetUnscaledValue() const;

  bool IsZero() const;
  bool operator==(const Decimal& other) const;

  friend std::ostream& operator<<(std::ostream& strm, const Decimal& a);
  friend std::optional<Decimal> operator+(const Decimal& lhs, const Decimal& rhs);
  friend std::optional<Decimal> operator*(const Decimal& lhs, const Decimal& rhs);
  friend std::optional<Decimal> operator-(const Decimal& lhs, const Decimal& rhs);
  friend std::optional<Decimal> operator/(const Decimal& lhs, const Decimal& rhs);
  std::string ToString(const uint32_t display_precision = 2, const bool trim_zeros = false) const;
  std::string ToLocalizedString(const uint32_t display_precision = 2) const;
  std::string ToLocalizedCurrencyString() const;

 private:
  static std::unique_ptr<std::locale> locale_instance_;
  static const char* kDecimalChars;
  static const int kMaxScale;
  static const int kThousandsGrouping;

  static int64_t AbsolutePowerOf10(int32_t x);
  static bool Convert(const double& d, int64_t& i64);
  static std::locale& GetLocale();
  static double ScaleValue(const double& value1, int32_t scale1);
  static std::optional<int64_t> ScaleValue(const int64_t& value1, int32_t scale1);
  static int64_t ScaleDown(const int64_t& value1, int32_t scale1);
  static double UnscaleValue(const int64_t value1, int32_t scale1);
  std::string ToStringPriv(const uint32_t display_precision = 2, const bool trim_zeros = false,
                           const char decimal_separator = '.') const;
  bool SetValue(double value1);
};

}  // namespace verifone_sdk

#endif // VERIFONE_SDK_SDK_ENTITIES_DECIMAL_H_
