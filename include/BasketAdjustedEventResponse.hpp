// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class AmountTotals;
class Basket;
class BasketAdjustment;
class CommerceResponse;
class Transaction;
class TransactionEventResponse;

/**
 * Allows editing the adjustments that will be applied to the basket. The initial object
 * rejects all adjustments, use {@link #setFinalAdjustments(BasketAdjustment, AmountTotals)} or
 * {@link #setFinalBasket(Basket, AmountTotals)} with the adjustments to allow any of them to
 * be included. When this response is sent, the
 * {@link com.verifone.commerce.triggers.BasketFinalizedNotification} will be sent, and the
 * listener will receive the {@link BasketEvent} with the
 * {@link BasketEvent.BasketAction#FINALIZED} action.
 */
class BasketAdjustedEventResponse {
public:
    virtual ~BasketAdjustedEventResponse() {}

    /** Return TransactionEventResponse from the provided response */
    static std::shared_ptr<TransactionEventResponse> asTransactionEventResponse(const std::shared_ptr<BasketAdjustedEventResponse> & basketAdjustedEventResponse);

    /** Generate CommerceResponse from the provided response */
    static std::shared_ptr<CommerceResponse> asCommerceResponse(const std::shared_ptr<BasketAdjustedEventResponse> & basketAdjustedEventResponse);

    /**
     * Set the adjustments that should be applied, and the appropriate running total. Use either this
     * method or use {@link #setFinalBasket(Basket, AmountTotals)}, not both.
     */
    virtual void setFinalAdjustments(const std::shared_ptr<BasketAdjustment> & adjustments, const std::shared_ptr<AmountTotals> & amountTotals) = 0;

    /** Returns the value that was set for the final adjustments. */
    virtual std::shared_ptr<BasketAdjustment> getFinalAdjustments() const = 0;

    virtual void setFinalBasket(const std::shared_ptr<Basket> & basket, const std::shared_ptr<AmountTotals> & amountTotals) = 0;

    /** Returns final basket */
    virtual std::shared_ptr<Basket> getFinalBasket() const = 0;

    /** Returns final totals */
    virtual std::shared_ptr<AmountTotals> getFinalTotals() const = 0;

    /** Returns true if this object has been updated with changes, otherwise false. */
    virtual bool hasAdjustment() const = 0;

    /** Returns invoice id from event */
    virtual std::optional<std::string> getInvoiceId() const = 0;

    /** Return Transaction from event */
    virtual std::shared_ptr<Transaction> getTransaction() const = 0;

    /** Update transaction from response */
    virtual void updateTransaction(const std::shared_ptr<Transaction> & transaction) = 0;
};

}  // namespace verifone_sdk