#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>

#include "PaymentSdkInterface.hpp"
#include "PlatformContextLinux.hpp"
#include "PsdkDeviceInformation.hpp"
#include "PsdkStatusListener.hpp"
#include "Status.hpp"
#include "StatusCode.hpp"
#include "TransactionManager.hpp"
#include "Transaction.hpp"
#include "TransactionEvent.hpp"
#include "Payment.hpp"
#include "AmountTotals.hpp"
#include "Decimal.hpp"
#include "PaymentType.hpp"
#include "UserInputEventResponse.hpp"
#include "UserInputEvent.hpp"
#include "InputType.hpp"
#include "CommerceListener.hpp"
#include "Values.hpp"
#include "BasketAdjustedEvent.hpp"
#include "HostAuthorizationEvent.hpp"
#include "PaymentCompletedEvent.hpp"

class FooListener : public verifone_sdk::CommerceListener
{

public:
  ~FooListener() override = default;

  std::shared_ptr<verifone_sdk::CommerceResponse> handleCommerceEvent(const std::shared_ptr<verifone_sdk::CommerceEvent> &event) override
  {

    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleTransactionEvent(const std::shared_ptr<verifone_sdk::TransactionEvent> &event) override
  {

    if (event->getType() == verifone_sdk::TransactionEvent::LOGIN_COMPLETED)
    {

      if (event->getStatus() == verifone_sdk::StatusCode::SUCCESS)
      {
        // Login is complete.
      }
      else
      {
        // Handle failure by examining the status code and message.
      }
    }

    return nullptr;
  }

  std::shared_ptr<verifone_sdk::AmountAdjustedEventResponse> handleAmountAdjustedEvent(const std::shared_ptr<verifone_sdk::AmountAdjustedEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::BasketAdjustedEventResponse> handleBasketAdjustedEvent(const std::shared_ptr<verifone_sdk::BasketAdjustedEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleBasketEvent(const std::shared_ptr<verifone_sdk::BasketEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleCardInformationReceivedEvent(const std::shared_ptr<verifone_sdk::CardInformationReceivedEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleDeviceInformationReceivedEvent(const std::shared_ptr<verifone_sdk::DeviceInformationReceivedEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleDeviceManagementEvent(const std::shared_ptr<verifone_sdk::DeviceManagementEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::LoyaltyReceivedEventResponse> handleLoyaltyReceivedEvent(const std::shared_ptr<verifone_sdk::LoyaltyReceivedEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handlePaymentCompletedEvent(const std::shared_ptr<verifone_sdk::PaymentCompletedEvent> &event) override
  {

    if (event->getType() == verifone_sdk::TransactionEvent::TRANSACTION_PAYMENT_COMPLETED)
    {

      if (event->getStatus() == verifone_sdk::StatusCode::SUCCESS)
      {
        //     std::cout << "SPENCERFOO: getStatus is SUCCESS" << std::endl;
        //     auto payment = event->getPayment();
        //     auto auth_result = payment->getAuthResult();
        // Confirm the authorization result is AUTHORIZED instead
        // of DECLINED or some other result.
      }
      // Else handle failure by examining the status code and message.
    }

    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleReceiptDeliveryMethodEvent(const std::shared_ptr<verifone_sdk::ReceiptDeliveryMethodEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleStoredValueCardEvent(const std::shared_ptr<verifone_sdk::StoredValueCardEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::UserInputEventResponse> handleUserInputEvent(const std::shared_ptr<verifone_sdk::UserInputEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleReconciliationEvent(const std::shared_ptr<verifone_sdk::ReconciliationEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::CommerceResponse> handleReconciliationsListEvent(const std::shared_ptr<verifone_sdk::ReconciliationsListEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleTransactionQueryEvent(const std::shared_ptr<verifone_sdk::TransactionQueryEvent> &event) override
  {
    return nullptr;
  }

  std::shared_ptr<verifone_sdk::TransactionEventResponse> handleNotificationEvent(const std::shared_ptr<verifone_sdk::NotificationEvent> &event) override
  {
    return nullptr;
  }

  void handleHostAuthorizationEvent(const std::shared_ptr<verifone_sdk::HostAuthorizationEvent> &event) override
  {
  }

  void handleHostFinalizeTransactionEvent(const std::shared_ptr<verifone_sdk::HostFinalizeTransactionEvent> &event) override
  {
  }
};

class StatusListener : public verifone_sdk::PsdkStatusListener
{

public:
  typedef std::function<void(const std::shared_ptr<verifone_sdk::Status> &)> HandleEventListener;

  StatusListener(HandleEventListener listener) : listener_(listener) {}
  void handleEvent(const std::shared_ptr<verifone_sdk::Status> &status) override
  {
    listener_(status);
  }

private:
  HandleEventListener listener_;
};

int main()
{

  // std::unordered_map<std::string, std::string> param_map{
  //     {verifone_sdk::TransactionManager::DEVICE_LISTEN_KEY,
  //      verifone_sdk::TransactionManager::ENABLED_VALUE},
  //      {verifone_sdk::PsdkDeviceInformation::DEVICE_CONNECTION_TYPE_KEY, "tcpip"}
  //  };

  std::unordered_map<std::string, std::string> param_map{
      {verifone_sdk::PsdkDeviceInformation::DEVICE_ADDRESS_KEY, "192.168.255.35"},
      {verifone_sdk::PsdkDeviceInformation::DEVICE_CONNECTION_TYPE_KEY, "tcpip"}};

  int last_status;
  auto psdk = verifone_sdk::PaymentSdkInterface::create(verifone_sdk::CreatePlatformContextLinux(std::nullopt));
  auto listener = std::make_shared<StatusListener>([&](const std::shared_ptr<verifone_sdk::Status> &status) {
    last_status = status->getStatus();
  });

  psdk->initializeFromValues(listener, param_map);

  std::shared_ptr<verifone_sdk::CommerceListener> foo_listener = std::make_shared<FooListener>();

  if (auto transaction_manager = psdk->getTransactionManager())
  {

    auto login_status = transaction_manager->login(foo_listener, std::nullopt, std::nullopt, std::nullopt);

    if (transaction_manager && transaction_manager->startSession(foo_listener, verifone_sdk::Transaction::create()))
    {

      std::cout << "Session start was sent successfully" << std::endl;

      auto payment = verifone_sdk::Payment::create();

      payment->getRequestedAmounts()->setSubtotal(verifone_sdk::Decimal(2, 25));
      payment->getRequestedAmounts()->setTax(verifone_sdk::Decimal(2, 25));
      payment->getRequestedAmounts()->setGratuity(verifone_sdk::Decimal(2, 25));
      payment->getRequestedAmounts()->setTotal(verifone_sdk::Decimal(2, 100));

      //    auto payment_amount_totals = verifone_sdk::AmountTotals::create(true);
      //    payment_amount_totals->setWithAmounts({{2, 2000}}, {{2, 200}}, {{2, 200}}, {}, {}, {}, {{2, 2400}});
      //    payment->setRequestedAmounts(payment_amount_totals);

      /*
      subtotal
      tax
      gratuity
      fees
      cashback
      donation
      total
    */
      //    auto amount_totals = verifone_sdk::AmountTotals::create(true);
      //    amount_totals->setWithAmounts(
      //      verifone_sdk::Decimal(2,200),
      //      verifone_sdk::Decimal(2,300),
      //      verifone_sdk::Decimal(2,400),
      //      verifone_sdk::Decimal(2,500),
      //      verifone_sdk::Decimal(2,600),
      //      verifone_sdk::Decimal(2,700),
      //      verifone_sdk::Decimal(2,800)
      //    );
      //    payment->setRequestedAmounts(amount_totals);
      //    payment->setRequestedPaymentType(verifone_sdk::PaymentType::DEBIT);
      //    payment->setRequestedPaymentType(verifone_sdk::PaymentType::CREDIT);

      transaction_manager->startPayment(payment);
      //    psdk->getTransactionManager()->startPayment(payment);
      transaction_manager->endSession();
      //     transaction_manager->logout();
    }
    else
    {
      // Session start failed to send
      std::cout << "Session start failed to send" << std::endl;
    }
  }
  else
  {
  }
}
