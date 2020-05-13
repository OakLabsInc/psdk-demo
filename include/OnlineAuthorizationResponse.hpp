// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class CommerceResponse;
class Transaction;
class TransactionEventResponse;

/** Response for online authorization */
class OnlineAuthorizationResponse {
public:
    virtual ~OnlineAuthorizationResponse() {}

    /** Return TransactionEventResponse from the provided response */
    static std::shared_ptr<TransactionEventResponse> asTransactionEventResponse(const std::shared_ptr<OnlineAuthorizationResponse> & onlineAuthorizationResponse);

    /** Generate CommerceResponse from the provided response */
    static std::shared_ptr<CommerceResponse> asCommerceResponse(const std::shared_ptr<OnlineAuthorizationResponse> & onlineAuthorizationResponse);

    /**
     * Gets the online result.
     * @return whether or not an online dialog was successful
     */
    virtual bool getOnlineResult() = 0;

    /**
     * Sets the online result to the requested value
     * @param onlineResult whether or not an online dialog was successful
     */
    virtual void setOnlineResult(bool result) = 0;

    /**
     * Gets the authorization code (EMV tag 89)
     * @return hex string representing the value generated by the authorization authority for an
     * approved transaction
     */
    virtual std::string getAuthorizationCode() = 0;

    /**
     * Sets the authorization code (EMV tag 89) to the requested value
     * @param authorizationCode hex string representing the value generated by the authorization
     * authority for an approved transaction
     */
    virtual void setAuthorizationCode(const std::string & authorizationCode) = 0;

    /**
     * Gets the authorization response code (EMV tag 8A)
     * @return hex string representing code that defines the disposition of a message
     */
    virtual std::string getAuthorizationResponseCode() = 0;

    /**
     * Sets the authorization response code (EMV tag 8A) to the requested value
     * @param authorizationResponseCode hex string representing code that defines 
     * the disposition of a message
     */
    virtual void setAuthorizationResponseCode(const std::string & code) = 0;

    /**
     * Gets the issuer authentication data (EMV tag 91)
     * @return hex string representing data sent to the ICC for online issuer 
     * authentication
     */
    virtual std::string getIssuerAuthenticationData() = 0;

    /**
     * Sets the issuer authentication data (EMV tag 91) to the requested value
     * @param issuerAuthenticationData hex string representing data sent to the ICC for online
     * issuer authentication
     */
    virtual void setIssuerAuthenticationData(const std::string & data) = 0;

    /** Returns invoice id from event */
    virtual std::optional<std::string> getInvoiceId() const = 0;

    /** Return Transaction from event */
    virtual std::shared_ptr<Transaction> getTransaction() const = 0;

    /** Update transaction from response */
    virtual void updateTransaction(const std::shared_ptr<Transaction> & transaction) = 0;
};

}  // namespace verifone_sdk