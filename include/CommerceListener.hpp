// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce.djinni

#pragma once

#include <memory>

namespace verifone_sdk {

class AmountAdjustedEvent;
class AmountAdjustedEventResponse;
class BasketAdjustedEvent;
class BasketAdjustedEventResponse;
class BasketEvent;
class CardInformationReceivedEvent;
class CommerceEvent;
class CommerceResponse;
class DeviceInformationReceivedEvent;
class DeviceManagementEvent;
class HostAuthorizationEvent;
class HostFinalizeTransactionEvent;
class LoyaltyReceivedEvent;
class LoyaltyReceivedEventResponse;
class NotificationEvent;
class PaymentCompletedEvent;
class ReceiptDeliveryMethodEvent;
class ReconciliationEvent;
class ReconciliationsListEvent;
class StoredValueCardEvent;
class TransactionEvent;
class TransactionEventResponse;
class TransactionQueryEvent;
class UserInputEvent;
class UserInputEventResponse;

/**
 * The listener interface for session events. More than one listener may be registered with a
 * session, but there must always be at least one listener.
 */
class CommerceListener {
public:
    virtual ~CommerceListener() {}

    /** Return CommerceResponse after handle CommerceEvent */
    virtual std::shared_ptr<CommerceResponse> handleCommerceEvent(const std::shared_ptr<CommerceEvent> & event) = 0;

    /** Return TransactionEventResponse after handle TransactionEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleTransactionEvent(const std::shared_ptr<TransactionEvent> & event) = 0;

    /** Return AmountAdjustedEventResponse after handle AmountAdjustedEvent */
    virtual std::shared_ptr<AmountAdjustedEventResponse> handleAmountAdjustedEvent(const std::shared_ptr<AmountAdjustedEvent> & event) = 0;

    /** Return BasketAdjustedEventResponse after handle BasketAdjustedEvent */
    virtual std::shared_ptr<BasketAdjustedEventResponse> handleBasketAdjustedEvent(const std::shared_ptr<BasketAdjustedEvent> & event) = 0;

    /** Return TransactionEventResponse after handle BasketEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleBasketEvent(const std::shared_ptr<BasketEvent> & event) = 0;

    /** Return TransactionEventResponse after handle CardInformationReceivedEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleCardInformationReceivedEvent(const std::shared_ptr<CardInformationReceivedEvent> & event) = 0;

    /** Return TransactionEventResponse after handle DeviceInformationReceivedEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleDeviceInformationReceivedEvent(const std::shared_ptr<DeviceInformationReceivedEvent> & event) = 0;

    /** Return TransactionEventResponse after handle DeviceManagementEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleDeviceManagementEvent(const std::shared_ptr<DeviceManagementEvent> & event) = 0;

    /** Return LoyaltyReceivedEventResponse after handle LoyaltyReceivedEvent */
    virtual std::shared_ptr<LoyaltyReceivedEventResponse> handleLoyaltyReceivedEvent(const std::shared_ptr<LoyaltyReceivedEvent> & event) = 0;

    /** Return TransactionEventResponse after handle PaymentCompletedEvent */
    virtual std::shared_ptr<TransactionEventResponse> handlePaymentCompletedEvent(const std::shared_ptr<PaymentCompletedEvent> & event) = 0;

    /** Return TransactionEventResponse after handle ReceiptDeliveryMethodEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleReceiptDeliveryMethodEvent(const std::shared_ptr<ReceiptDeliveryMethodEvent> & event) = 0;

    /** Return TransactionEventResponse after handle StoredValueCardEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleStoredValueCardEvent(const std::shared_ptr<StoredValueCardEvent> & event) = 0;

    /** Return UserInputEventResponse after handle UserInputEvent */
    virtual std::shared_ptr<UserInputEventResponse> handleUserInputEvent(const std::shared_ptr<UserInputEvent> & event) = 0;

    /** Return TransactionEventResponse after handle ReconciliationEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleReconciliationEvent(const std::shared_ptr<ReconciliationEvent> & event) = 0;

    /** Return CommerceResponse after handle ReconciliationsListEvent */
    virtual std::shared_ptr<CommerceResponse> handleReconciliationsListEvent(const std::shared_ptr<ReconciliationsListEvent> & event) = 0;

    /** Return TransactionEventResponse after handle TransactionQueryEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleTransactionQueryEvent(const std::shared_ptr<TransactionQueryEvent> & event) = 0;

    /** Handle HostAuthorizationEvent */
    virtual void handleHostAuthorizationEvent(const std::shared_ptr<HostAuthorizationEvent> & event) = 0;

    /** Handle HostFinalizeTransactionEvent */
    virtual void handleHostFinalizeTransactionEvent(const std::shared_ptr<HostFinalizeTransactionEvent> & event) = 0;

    /** Handle NotificationEvent */
    virtual std::shared_ptr<TransactionEventResponse> handleNotificationEvent(const std::shared_ptr<NotificationEvent> & event) = 0;
};

}  // namespace verifone_sdk