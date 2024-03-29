// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_entities.djinni

#pragma once

#include <optional>
#include <string>
#include <utility>

namespace verifone_sdk {

struct Merchant; // Requiring extended class

/** Represents a merchant. */
struct MerchantBase {

    /** name of the merchant */
    static std::string const MERCHANT_NAME_COLUMN;

    /** address of the merchant */
    static std::string const MERCHANT_ADDRESS_COLUMN;
    /** record id of the merchant */
    std::optional<std::string> recordId;
    /** The name of the merchant as set by the merchant. */
    std::optional<std::string> merchantName;
    /** The address of the merchant */
    std::optional<std::string> merchantAddress;

    MerchantBase(std::optional<std::string> recordId_,
                 std::optional<std::string> merchantName_,
                 std::optional<std::string> merchantAddress_)
    : recordId(std::move(recordId_))
    , merchantName(std::move(merchantName_))
    , merchantAddress(std::move(merchantAddress_))
    {}

    virtual ~MerchantBase() = default;

protected:
    MerchantBase(const MerchantBase&) = default;
    MerchantBase(MerchantBase&&) = default;
    MerchantBase& operator=(const MerchantBase&) = default;
    MerchantBase& operator=(MerchantBase&&) = default;
};

}  // namespace verifone_sdk
