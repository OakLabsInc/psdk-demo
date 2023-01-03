/*
 * Copyright (c) 2021 by VeriFone, Inc.
 * All Rights Reserved.
 * THIS FILE CONTAINS PROPRIETARY INFORMATION
 * AND REMAINS THE PROPERTY OF VERIFONE, INC.
 *
 * Use, disclosure, or reproduction is prohibited
 * without prior written approval from VeriFone, Inc.
 */

#ifndef VERIFONE_SDK_COMMERCE_LISTENER_ADAPTER_H
#define VERIFONE_SDK_COMMERCE_LISTENER_ADAPTER_H

#include <chrono>
#include <optional>
#include <string>
#include <unordered_set>

#include "AmountAdjustedEvent.hpp"
#include "BasketAdjustedEvent.hpp"
#include "BasketEvent.hpp"
#include "CardInformationReceivedEvent.hpp"
#include "DeviceInformationReceivedEvent.hpp"
#include "DeviceManagementEvent.hpp"
#include "DeviceVitalsInformationEvent.hpp"
#include "HostAuthorizationEvent.hpp"
#include "HostFinalizeTransactionEvent.hpp"
#include "LoginCredentials.hpp"
#include "LoyaltyReceivedEvent.hpp"
#include "NotificationEvent.hpp"
#include "PaymentCompletedEvent.hpp"
#include "PrintEvent.hpp"
#include "ReceiptDeliveryMethodEvent.hpp"
#include "ReconciliationEvent.hpp"
#include "ReconciliationsListEvent.hpp"
#include "StoredValueCardEvent.hpp"
#include "TransactionEvent.hpp"
#include "TransactionQueryEvent.hpp"
#include "UserInputEvent.hpp"

#include "CommerceEvent.hpp"
#include "CommerceListener2.hpp"
#include "Status.hpp"

#include "common/logging.h"

namespace verifone_sdk {

/**
 * The CommerceListenerAdapter is the adapter for the CommerceListener2
 * with all default implementations in the event handlers.
 */
class CommerceListenerAdapter : public CommerceListener2 {
 public:
  ~CommerceListenerAdapter() override = default;
  void handleCommerceEvent(const std::shared_ptr<CommerceEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleTransactionEvent(const std::shared_ptr<TransactionEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleAmountAdjustedEvent(const std::shared_ptr<AmountAdjustedEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleBasketAdjustedEvent(const std::shared_ptr<BasketAdjustedEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleBasketEvent(const std::shared_ptr<BasketEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleCardInformationReceivedEvent(
      const std::shared_ptr<CardInformationReceivedEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleDeviceManagementEvent(const std::shared_ptr<DeviceManagementEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleLoyaltyReceivedEvent(const std::shared_ptr<LoyaltyReceivedEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handlePaymentCompletedEvent(const std::shared_ptr<PaymentCompletedEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleReceiptDeliveryMethodEvent(
      const std::shared_ptr<ReceiptDeliveryMethodEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleStoredValueCardEvent(const std::shared_ptr<StoredValueCardEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleUserInputEvent(const std::shared_ptr<UserInputEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleReconciliationEvent(const std::shared_ptr<ReconciliationEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleReconciliationsListEvent(
      const std::shared_ptr<ReconciliationsListEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleTransactionQueryEvent(const std::shared_ptr<TransactionQueryEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleHostAuthorizationEvent(const std::shared_ptr<HostAuthorizationEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleHostFinalizeTransactionEvent(
      const std::shared_ptr<HostFinalizeTransactionEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleNotificationEvent(const std::shared_ptr<NotificationEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handlePrintEvent(const std::shared_ptr<PrintEvent> &event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
  void handleStatus(const std::shared_ptr<Status> &status) override {
    Log(status->getType(), status->getStatus(), status->getMessage());
  };
  void handleDeviceVitalsInformationEvent(const std::shared_ptr<DeviceVitalsInformationEvent> & event) override {
    Log(event->getType(), event->getStatus(), event->getMessage());
  };
 private:
  static void Log(
      std::optional<std::string> type, int32_t status, std::optional<std::string> message);
};
}  // namespace verifone_sdk

#endif  // VERIFONE_SDK_COMMERCE_LISTENER_ADAPTER_H
