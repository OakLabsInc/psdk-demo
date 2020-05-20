#include <functional>
#include <iostream>
#include <string>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

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
#include "PsdkLogLevel.hpp"

#include "nlohmann/json.hpp"

using json = nlohmann::json;

std::shared_ptr<verifone_sdk::TransactionManager> transaction_manager;

json response_json;

void handle_response(std::string in_status, std::string in_message)
{

  // in_status should be SUCCESS or FAILED
  // print response
  // { status: in_status, message: in_message }

  response_json["status"] = in_status;
  response_json["message"] = in_message;
  
  std::cout << response_json << std::endl;
  
}

class ComListener : public verifone_sdk::CommerceListener
{

public:
  ~ComListener() override = default;

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
        auto payment = event->getPayment();
        auto auth_result = payment->getAuthResult();
        handle_response("SUCCESS", "");
      }
      else
      {
         std::optional<std::string> message = event->getMessage();
         if( message.has_value() ) {
           handle_response("ERROR", message.value());
        } else {
          handle_response("ERROR", "");
        }
      }
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


verifone_sdk::Decimal string_to_decimal(std::string in_string)
{

  std::vector<std::string> split_string;
  std::istringstream in_string_stream(in_string);
  std::string string_token;
  while (getline(in_string_stream, string_token, '.'))
  {
    split_string.push_back(string_token);
  }

  int64_t value;
  std::istringstream iss(split_string[0].append(split_string[1]));
  iss >> value;

  return verifone_sdk::Decimal(split_string[1].length(), value);
}

verifone_sdk::Decimal sub_total;
verifone_sdk::Decimal tax_rate;
verifone_sdk::Decimal tax;
verifone_sdk::Decimal gratuity;
verifone_sdk::Decimal donation;
verifone_sdk::Decimal net_total;

void parse_json_payload(std::string in_json_string)
{

  json json_payload = json::parse(in_json_string);
  sub_total = string_to_decimal(json_payload["total"]);
  tax_rate = string_to_decimal(json_payload["taxRate"]);
  tax = string_to_decimal(json_payload["tax"]);
  //  gratuity = string_to_decimal(json_payload["gratuity"]);
  //  donation = string_to_decimal(json_payload["donation"]);
  net_total = string_to_decimal(json_payload["grandTotal"]);
}

std::string terminal_ip;
int main(int argc, char **argv)
{

  // '{ "total": 20.2, "taxRate": 0.085, "tax": 1.717, "grandTotal": 21.916999999999998 }' '192.168.255.35'

  if (argc != 3)
  {
    std::cout << "argc != 3: " << argc << std::endl;
    return 1;
  }

  std::string json_string = argv[1];
  terminal_ip = argv[2];

  parse_json_payload(json_string);

  // std::unordered_map<std::string, std::string> param_map{
  //     {verifone_sdk::TransactionManager::DEVICE_LISTEN_KEY,
  //      verifone_sdk::TransactionManager::ENABLED_VALUE},
  //      {verifone_sdk::PsdkDeviceInformation::DEVICE_CONNECTION_TYPE_KEY, "tcpip"}
  //  };

  std::unordered_map<std::string, std::string> param_map{
      {verifone_sdk::PsdkDeviceInformation::DEVICE_ADDRESS_KEY, terminal_ip},
      {verifone_sdk::PsdkDeviceInformation::DEVICE_CONNECTION_TYPE_KEY, "tcpip"}};

  int last_status;
  std::shared_ptr<verifone_sdk::PaymentSdkInterface> psdk = verifone_sdk::PaymentSdkInterface::create(verifone_sdk::CreatePlatformContextLinux(std::nullopt));
  psdk->configureLogLevel(verifone_sdk::PsdkLogLevel::LOG_NONE);

  auto listener = std::make_shared<StatusListener>([&](const std::shared_ptr<verifone_sdk::Status> &status) {
    last_status = status->getStatus();
  });

  psdk->initializeFromValues(listener, param_map);

  std::shared_ptr<verifone_sdk::CommerceListener> com_listener = std::make_shared<ComListener>();


//  if (transaction_manager = psdk->getTransactionManager().setDebugMode() )
  if (transaction_manager = psdk->getTransactionManager() )
  {

    auto login_status = transaction_manager->login(com_listener, std::nullopt, std::nullopt, std::nullopt);

    if (transaction_manager && transaction_manager->startSession(com_listener, verifone_sdk::Transaction::create()))
    {

//      std::cout << "Session start was sent successfully" << std::endl;

      auto payment = verifone_sdk::Payment::create();

      payment->getRequestedAmounts()->setSubtotal(sub_total);
      payment->getRequestedAmounts()->setTax(tax);
      //      payment->getRequestedAmounts()->setGratuity(gratuity);
      //      payment->getRequestedAmounts()->setDonation(donation);
      payment->getRequestedAmounts()->setTotal(net_total);

      transaction_manager->startPayment(payment);
      transaction_manager->endSession();
      transaction_manager->logout();
  psdk->tearDown();
    }
    else
    {
      // Session start failed to send
      std::cout << "Session start failed to send" << std::endl;
      transaction_manager->endSession();
      transaction_manager->logout();
  psdk->tearDown();
    }
  }
  else
  {
  }


//  std::cout << response_json << std::endl;
  exit(0); 

}
