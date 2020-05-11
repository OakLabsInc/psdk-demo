// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_entities.djinni

#pragma once

#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

namespace verifone_sdk {

enum class PresentationMethod;
enum class TokenizationMethod;
struct Decimal;

/**
 * This represents the data that is shared between the terminal and the Android application
 * Setting the fields is only relevant when sending the data to the terminal, and conversely,
 * getting the fields is only relevant when receiving this object from the terminal.
 */
class CardInformation {
public:
    virtual ~CardInformation() {}

    /** The default constant value for the payment brand, instead of null. */
    static std::string const UNSET_PAYMENT_BRAND;

    /** The constant value when the payment brand is not recognized but present. */
    static std::string const UNKNOWN_PAYMENT_BRAND;

    /** The constant value for the American Express Payment Brand. */
    static std::string const AMEX;

    /** The constant value for the Discover Payment Brand. */
    static std::string const DISCOVER;

    /** The constant value for the Master Card Payment Brand. */
    static std::string const MASTER_CARD;

    /** The constant value for the Visa Payment Brand. */
    static std::string const VISA;

    /** The constant value for the JCB Payment Brand. */
    static std::string const JCB;

    /** The constant value for the Interac Payment Brand. */
    static std::string const INTERAC;

    /** The card status for a card that must be treated according to PCI regulations. */
    static std::string const PCI_CARD;

    /**
     * The card status for a card that is not regulated, often times a loyalty card or membership
     * card.
     */
    static std::string const NON_PCI_CARD_STATUS;

    /** create CardInformation */
    static std::shared_ptr<CardInformation> create();

    /** The method used to obtain the card data */
    virtual PresentationMethod getPresentationMethod() const = 0;

    /** Present only with EMV cards and is representation of EMV Tag9F42. */
    virtual std::optional<std::string> getCardCurrency() const = 0;

    /** Present only with EMV cards and is representation of EMV Tag5F28. */
    virtual std::optional<std::string> getCardCountry() const = 0;

    /** Present only with EMV cards and is representation of EMV Tag5F2D. */
    virtual std::optional<std::string> getCardPreferredLanguages() const = 0;

    /** The token representation of the card. */
    virtual std::optional<std::string> getCardToken() const = 0;

    /** Depending on the host, sometimes specific user data is provided to supplement the token. */
    virtual std::optional<std::string> getBankUserData() const = 0;

    /** The method by which the card was tokenized. */
    virtual TokenizationMethod getCardTokenizationMethod() const = 0;

    /**
     * A reference returned by the Payment Application to refer to the PAN in question.
     * A Commerce Application may choose to use PAN_Handle to request an encrypted PAN
     * via API CP_APP_REQUESTS_ENCRYPTED_CARD.
     */
    virtual std::optional<std::string> getPanHandle() const = 0;

    /** The last four digits of the card holder PAN. This might not be provided. */
    virtual std::optional<std::string> getPanLast4() const = 0;

    /** The first two digits of the card holder PAN. This might not be provided. */
    virtual std::optional<std::string> getPanFirst2() const = 0;

    /**
     * Present only with EMV cards, this is the relevant EMV Tags necessary for record keeping.
     * The key is the tag, e.g. "9F26", and the value is a string encoding of the EMV value.
     */
    virtual std::unordered_map<std::string, std::string> getEmvTags() const = 0;

    /** The first six digits of the card holder PAN. This might not be provided. */
    virtual std::optional<std::string> getBin() const = 0;

    /** This is included only when specifically requested. */
    virtual std::optional<std::string> getEncryptedTracks() const = 0;

    /** This is included only when specifically requested. */
    virtual std::optional<std::string> getEncryptedTracksKsn() const = 0;

    /** This is included only when specifically requested. */
    virtual std::optional<std::string> getEncryptedPan() const = 0;

    /** This is included only when specifically requested. */
    virtual std::optional<std::string> getEncryptedPanKsn() const = 0;

    /** This is included only when specifically requested. */
    virtual std::optional<std::string> getCardHolderName() const = 0;

    /** Card track1. This value is only populated when the payment terminal is explicitly configured to pass back this information. */
    virtual std::optional<std::string> getCardTrack1() const = 0;

    /** Card track2. This value is only populated when the payment terminal is explicitly configured to pass back this information. */
    virtual std::optional<std::string> getCardTrack2() const = 0;

    /** Card track3. This value is only populated when the payment terminal is explicitly configured to pass back this information. */
    virtual std::optional<std::string> getCardTrack3() const = 0;

    /** Returns the masked PAN when the card status is PCI_CARD or the clear PAN if the card status is NON_PCI_CARD. */
    virtual std::optional<std::string> getCardPan() const = 0;

    /** The card expiry when specifically requested. */
    virtual std::optional<std::string> getCardExpiry() const = 0;

    /** The status of the card when the card data is requested specifically. */
    virtual std::optional<std::string> getCardStatus() const = 0;

    /**
     * Returns an ID for this issuer, as assigned by the host or payment application.
     * Generally null, since it's normally enough to refer to the payment brand.
     */
    virtual std::optional<std::string> getIssuerId() const = 0;

    /**
     * The brand for the card. Returns a constant value, see {@link #VISA} as an example, or
     * the literal string received from the terminal if the constant is unrecognized.
     */
    virtual std::optional<std::string> getPaymentBrand() const = 0;

    /** The balance remaining on the card. */
    virtual std::optional<Decimal> getAvailableBalance() const = 0;

    /**
     * Reference of the PAN, which identifies the PAN or the card uniquely, named also PAR (Payment
     * Account Reference). This reference may be defined by the card issuer or by a token service
     * provider under the control of the card issuer, and cannot be used for a payment transaction.
     */
    virtual std::optional<std::string> getAccountReference() const = 0;

    /** Set the presentation method. The method used to set the card data */
    virtual void setPresentationMethod(PresentationMethod presentationMethod) = 0;

    /** Set the card currency. Set only with EMV cards and is representation of EMV Tag9F42. */
    virtual void setCardCurrency(const std::optional<std::string> & cardCurrency) = 0;

    /** Set the card country. Set only with EMV cards and is representation of EMV Tag5F28. */
    virtual void setCardCountry(const std::optional<std::string> & cardCountry) = 0;

    /** Set the card preferred languages. Set only with EMV cards and is representation of EMV Tag5F2D. */
    virtual void setCardPreferredLanguages(const std::optional<std::string> & languages) = 0;

    /**
     * Set the token representation of the payment method. This is required if starting a payment
     * that should use an existing token, otherwise this should not be set.
     */
    virtual void setCardToken(const std::optional<std::string> & cardToken) = 0;

    /** Set the bank user data for the token. */
    virtual void setBankUserData(const std::optional<std::string> & bankUserData) = 0;

    /**
     * Set the card tokenization method that was used for the current token. To
     * request a specific tokenization method, please use
     * {@link com.verifone.payment_sdk.Payment#setRequestedTokenizationMethod}.
     */
    virtual void setCardTokenizationMethod(TokenizationMethod tokenizationMethod) = 0;

    /**
     * A reference set by the Payment Application to refer to a specific PAN, only used while
     * processing CP Triggers. A Commerce Application may choose to use PAN_Handle to request an
     * encrypted PAN via API CP_APP_REQUESTS_ENCRYPTED_CARD.
     */
    virtual void setPanHandle(const std::optional<std::string> & panHandle) = 0;

    /** Set the last four digits of the PAN */
    virtual void setPanLast4(const std::optional<std::string> & panLast4) = 0;

    /** Set the first two digits of the PAN. */
    virtual void setPanFirst2(const std::optional<std::string> & panFirst2) = 0;

    /** Set the Emv Tags for the current card. */
    virtual void setEmvTags(const std::unordered_map<std::string, std::string> & emvTags) = 0;

    /** Set the first six digits of the PAN. */
    virtual void setBin(const std::optional<std::string> & bin) = 0;

    /** This is included only when specifically requested. */
    virtual void setEncryptedTracks(const std::optional<std::string> & encryptedTracks) = 0;

    /** This is included only when specifically requested. */
    virtual void setEncryptedTracksKsn(const std::optional<std::string> & encryptedTracksKsn) = 0;

    /** This is included only when specifically requested. */
    virtual void setEncryptedPan(const std::optional<std::string> & encryptedPan) = 0;

    /** This is included only when specifically requested. */
    virtual void setEncryptedPanKsn(const std::optional<std::string> & encryptedPanKsn) = 0;

    /** This is included only when specifically requested. */
    virtual void setCardHolderName(const std::optional<std::string> & cardHolderName) = 0;

    /** Card track1. This value is only populated when the payment terminal is explicitly configured to pass back this information. */
    virtual void setCardTrack1(const std::optional<std::string> & cardTrack1) = 0;

    /** Card track2. This value is only populated when the payment terminal is explicitly configured to pass back this information. */
    virtual void setCardTrack2(const std::optional<std::string> & cardTrack2) = 0;

    /** Card track3. This value is only populated when the payment terminal is explicitly configured to pass back this information. */
    virtual void setCardTrack3(const std::optional<std::string> & cardTrack3) = 0;

    /** Sets the masked PAN when the card status is PCI_CARD or the clear PAN if the card status is NON_PCI_CARD. */
    virtual void setCardPan(const std::optional<std::string> & cardPan) = 0;

    /** The card expiry when specifically requested. */
    virtual void setCardExpiry(const std::optional<std::string> & cardExpiry) = 0;

    /** The status of the card when the card data is requested specifically. */
    virtual void setCardStatus(const std::optional<std::string> & cardStatus) = 0;

    /** The issuer id of the card */
    virtual void setIssuerId(const std::optional<std::string> & issuerId) = 0;

    /** The brand for the card. A constant value, see {@link #VISA VISA} as an example, or the literal string received from the terminal if the constant is unrecognized. */
    virtual void setPaymentBrand(const std::optional<std::string> & paymentBrand) = 0;

    /** The balance remaining on the card. */
    virtual void setAvailableBalance(const std::optional<Decimal> & availableBalance) = 0;

    /**
     * Reference of the PAN,  which identifies the PAN or the card uniquely, named also PAR (Payment
     * Account Reference). This reference may be defined by the card issuer or by a token service
     * provider under the control of the card issuer, and cannot be used for a payment transaction.
     */
    virtual void setAccountReference(const std::optional<std::string> & accountReference) = 0;
};

}  // namespace verifone_sdk
