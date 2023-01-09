// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from Tokens.djinni

#pragma once

#include "TokenType.hpp"
#include <optional>
#include <psdk/export.h>
#include <string>
#include <unordered_map>
#include <utility>

namespace verifone_sdk {

/** Represents a credit card or similar payment method for a particular account. */
struct PSDK_EXPORT Token final {

    /** Scope of organization of the token. */
    static std::string const ORGANIZATION_SCOPE;

    /** Scope of merchant of the token. */
    static std::string const MERCHANT_SCOPE;

    /** Scope of Venue of the token. */
    static std::string const VENUE_SCOPE;
    /** The token value. */
    std::string value;
    /** The scheme for tokens with type REUSE_WITH_SCHEME. */
    std::optional<std::string> scheme;
    /** Either a scope constant as listed above or a custom value as defined for this estate. */
    std::string scope;
    /** The enumerated type of token returned. */
    TokenType tokenType;
    /** Datetime when the token expires if provided by the host. */
    std::optional<std::string> expiry;
    /** For VAS information and other relevant information. */
    std::optional<std::unordered_map<std::string, std::string>> data;
    /** True if it was just created, or false if it was retrieved. */
    bool isCreated;

    Token(std::string value_,
          std::optional<std::string> scheme_,
          std::string scope_,
          TokenType tokenType_,
          std::optional<std::string> expiry_,
          std::optional<std::unordered_map<std::string, std::string>> data_,
          bool isCreated_)
    : value(std::move(value_))
    , scheme(std::move(scheme_))
    , scope(std::move(scope_))
    , tokenType(std::move(tokenType_))
    , expiry(std::move(expiry_))
    , data(std::move(data_))
    , isCreated(std::move(isCreated_))
    {}
};

}  // namespace verifone_sdk