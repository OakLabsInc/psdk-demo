// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace verifone_sdk {

class CommerceResponse;
class LoyaltyIdentifier;
class Offer;
class Payment;
class Transaction;
class TransactionEventResponse;

/**
 * Allows the POS application to edit the loyalty offers and accounts after they were 
 * linked by other applications.
 */
class LoyaltyReceivedEventResponse {
public:
    virtual ~LoyaltyReceivedEventResponse() {}

    /** Return TransactionEventResponse from the provided response */
    static std::shared_ptr<TransactionEventResponse> asTransactionEventResponse(const std::shared_ptr<LoyaltyReceivedEventResponse> & loyaltyReceivedEventResponse);

    /** Generate CommerceResponse from the provided response */
    static std::shared_ptr<CommerceResponse> asCommerceResponse(const std::shared_ptr<LoyaltyReceivedEventResponse> & loyaltyReceivedEventResponse);

    /** Set the loyalty offers that are accepted and applicable for this transaction. */
    virtual void setLoyaltyOffers(const std::vector<std::shared_ptr<Offer>> & loyaltyOffers) = 0;

    /**
     * Sets the offers and performs the calculations to change the appropriate amounts.
     * Please note, this does not change the tax amount, only the total amounts for both the
     * transaction and the current payment.
     */
    virtual void applyLoyaltyOffers(const std::vector<std::shared_ptr<Offer>> & loyaltyOffers) = 0;

    /** Returns the offers that will be applied to the cart. */
    virtual std::vector<std::shared_ptr<Offer>> getLoyaltyOffers() const = 0;

    /**
     * Applies the information from the loyalty identifier to the overall transaction. Only one
     * should be used per transaction.
     */
    virtual void selectLoyaltyIdentifier(const std::shared_ptr<LoyaltyIdentifier> & loyaltyIdentifier) = 0;

    /**
     * Returns the payment object that started the amount adjustment process. To update this,
     * either update this object directly or use {@link #updatePayment(Payment)};
     */
    virtual std::shared_ptr<Payment> getResponsePayment() const = 0;

    /** Update the payment object with the appropriate amounts and set it here. */
    virtual void updatePayment(const std::shared_ptr<Payment> & payment) = 0;

    /** Returns invoice id from event */
    virtual std::optional<std::string> getInvoiceId() const = 0;

    /** Return Transaction from event */
    virtual std::shared_ptr<Transaction> getTransaction() const = 0;

    /** Update transaction from response */
    virtual void updateTransaction(const std::shared_ptr<Transaction> & transaction) = 0;
};

}  // namespace verifone_sdk
