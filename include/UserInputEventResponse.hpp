// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class CommerceResponse;
class Transaction;
class TransactionEventResponse;
class Values;
enum class InputType;

/** Contains the response for an UserInputEvent */
class UserInputEventResponse {
public:
    virtual ~UserInputEventResponse() {}

    /** Return TransactionEventResponse from the provided response */
    static std::shared_ptr<TransactionEventResponse> asTransactionEventResponse(const std::shared_ptr<UserInputEventResponse> & userInputEventResponse);

    /** Generate CommerceResponse from the provided response */
    static std::shared_ptr<CommerceResponse> asCommerceResponse(const std::shared_ptr<UserInputEventResponse> & userInputEventResponse);

    /** Returns the Response Input types */
    virtual InputType getResponseInputType() const = 0;

    /** Returns the Response values */
    virtual std::shared_ptr<Values> getResponseValues() const = 0;

    /** Sets the Response values */
    virtual void setValues(const std::shared_ptr<Values> & values) = 0;

    /**
     * The status to mark it as failed for some specific reason. Common failed statuses include 
     * StatusCode::CANCELLED, StatusCode::COMMAND_TIMED_OUT, and StatusCode::UNSUPPORTED_COMMAND.
     */
    virtual int32_t getStatus() const = 0;

    /**
     * See {@link #getStatus()}. Set this status when responding to an input event request if the 
     * user cancels or if there is some error.
     */
    virtual void setStatus(int32_t status) = 0;

    /**
     * The message in case of a failure. Primarily used for logging, though it can be displayed 
     * to the cashier to allow them to better respond to the specific error scenario.
     */
    virtual std::optional<std::string> getMessage() const = 0;

    /**
     * See {@link #getMessage()}. Set this value when responding to an input event request and there
     * is some error, otherwise leave it empty.
     */
    virtual void setMessage(const std::optional<std::string> & message) = 0;

    /** Returns invoice id from event */
    virtual std::optional<std::string> getInvoiceId() const = 0;

    /** Return Transaction from event */
    virtual std::shared_ptr<Transaction> getTransaction() const = 0;

    /** Update transaction from response */
    virtual void updateTransaction(const std::shared_ptr<Transaction> & transaction) = 0;
};

}  // namespace verifone_sdk
