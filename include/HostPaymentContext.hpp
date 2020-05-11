// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_host_adapter.djinni

#pragma once

#include "AccountType.hpp"
#include "CmvAuthenticationMethod.hpp"
#include "FallbackCode.hpp"
#include "MerchantPresent.hpp"
#include "PresentationMethod.hpp"
#include <optional>
#include <string>
#include <utility>

namespace verifone_sdk {

/**
 * These properties will refer to the context by which a Payment was received associated
 * with the transaction event.
 */
struct HostPaymentContext final {
    /** Was a card physically present during transaction. */
    std::optional<bool> cardPresent;
    /** See {@link MerchantPresent} */
    std::optional<MerchantPresent> merchantPresent;
    /**
     * The Cardholder authentication method employed for this transaction.
     *   {@link #CmvAuthenticationMethod()}
     */
    std::optional<CmvAuthenticationMethod> authenticationMethod;
    /**
     * The entry mode for the payment instrument where card is presented at a PED.
     * {@link CardInformation.PresentationMethod },
     */
    std::optional<PresentationMethod> entryMode;
    /** See {@link AccountType} */
    std::optional<AccountType> accountType;
    /** See {@link FallbackCode} */
    std::optional<FallbackCode> fallbackCode;
    /**
     * Application Specific Data
     * This object may contain additional parameters specific to the client. These values must be
     * expected by the underlying PIM otherwise they will be discarded.
     */
    std::optional<std::string> metadata;

    HostPaymentContext(std::optional<bool> cardPresent_,
                       std::optional<MerchantPresent> merchantPresent_,
                       std::optional<CmvAuthenticationMethod> authenticationMethod_,
                       std::optional<PresentationMethod> entryMode_,
                       std::optional<AccountType> accountType_,
                       std::optional<FallbackCode> fallbackCode_,
                       std::optional<std::string> metadata_)
    : cardPresent(std::move(cardPresent_))
    , merchantPresent(std::move(merchantPresent_))
    , authenticationMethod(std::move(authenticationMethod_))
    , entryMode(std::move(entryMode_))
    , accountType(std::move(accountType_))
    , fallbackCode(std::move(fallbackCode_))
    , metadata(std::move(metadata_))
    {}
};

}  // namespace verifone_sdk
