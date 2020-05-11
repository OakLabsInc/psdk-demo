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

class EventListener : public verifone_sdk::CommerceListener {
 public:
  std::shared_ptr<verifone_sdk::UserInputEventResponse> handleUserInputEvent (const std::shared_ptr<verifone_sdk::UserInputEvent>& event) override {

    if (event->getType() == verifone_sdk::UserInputEvent::RECEIVED_TYPE && event->getInputType() == verifone_sdk::InputType::CONFIRMATION) {
      if (event->getValues()->isConfirmed()) {
        // Received confirmation.
      } else {
        // User canceled.
      }
    }

    if (event->getType() == verifone_sdk::TransactionEvent::LOGIN_COMPLETED) {
      if (event->getStatus() == verifone_sdk::StatusCode::SUCCESS) {
        // Login is complete.
      } else {
        // Handle failure by examining the status code and message.
      }
    }
    
/*
    if (event->getType() == verifone_sdk::TransactionEvent::SESSION_STARTED) {
      if (event->getStatus() == verifone_sdk::StatusCode::SUCCESS) {
        // Session is started
      } else {
        // Handle failure by examining the status code and message.
      }
    }
*/

    if (event->getType() == verifone_sdk::UserInputEvent::RECEIVED_TYPE) {
      auto values = event->getValues();
      if (event->getInputType() == verifone_sdk::InputType::MENU_OPTIONS) {
        if (event->getStatus() == verifone_sdk::StatusCode::SUCCESS) {
          auto selected_indices = event->getValues()->getSelectedIndices();
          // Use selected indices to determine which button they selected.
          // In this example, index 0 is Print, 1 is Email, etc.
        } // else handle error
      } // else handle other input response
    } // else handle input request from POI

    return nullptr;
  }

};



// Converts a listener class to using lambdas
class StatusListener : public verifone_sdk::PsdkStatusListener {
 public:
  typedef std::function<void(const std::shared_ptr<verifone_sdk::Status>&)> HandleEventListener;

  StatusListener(HandleEventListener listener) : listener_(listener) {}
  void handleEvent(const std::shared_ptr<verifone_sdk::Status>& status) override {
    listener_(status);
  }

 private:
  HandleEventListener listener_;
};


int main() {


// std::unordered_map<std::string, std::string> param_map{
//     {verifone_sdk::TransactionManager::DEVICE_LISTEN_KEY,
//      verifone_sdk::TransactionManager::ENABLED_VALUE},
//      {verifone_sdk::PsdkDeviceInformation::DEVICE_CONNECTION_TYPE_KEY, "tcpip"}
//  };

    std::unordered_map<std::string, std::string> param_map {
      {verifone_sdk::PsdkDeviceInformation::DEVICE_ADDRESS_KEY, "192.168.255.35"},
      {verifone_sdk::PsdkDeviceInformation::DEVICE_CONNECTION_TYPE_KEY, "tcpip"}
    };

  int last_status;
  auto psdk = verifone_sdk::PaymentSdkInterface::create(verifone_sdk::CreatePlatformContextLinux(std::nullopt));
  auto listener = std::make_shared<StatusListener>([&](const std::shared_ptr<verifone_sdk::Status>& status) {
   last_status = status->getStatus();
  });

  psdk->initializeFromValues(listener, param_map);



//  auto status = psdk->getTransactionManager()->requestUserInput(verifone_sdk::InputType::CONFIRMATION, "Message to display", "BLOW ME");
  auto status = psdk->getTransactionManager()->requestUserInput(verifone_sdk::InputType::CONFIRMATION, "Message to display", "");

// SPENCERFOO
//  if (status->getStatus() == verifone_sdk::StatusCode::SUCCESS) {
//    std::cout << "\n\nSPENCERFOO1: getStatus was a SUCCESS\n\n";

   if (auto transaction_manager = psdk->getTransactionManager()) {

     std::cout << "\n\nSPENCERFOO2: requestUserInput was a SUCCESS\n\n";

     auto login_status = transaction_manager->login(NULL, std::nullopt, std::nullopt, std::nullopt);

   } else {
     std::cout << "\n\nSPENCERFOO2: requestUserInput was NOT A SUCCESS\n\n";   
   }

   auto transaction_manager = psdk->getTransactionManager();
   if (transaction_manager && transaction_manager->startSession(NULL, verifone_sdk::Transaction::create())) {

    std::cout << "\n\nSPENCERFOO3: transaction_manager->startSession was a SUCCESS\n\n";

    auto payment = verifone_sdk::Payment::create();
    payment->getRequestedAmounts()->setSubtotal(verifone_sdk::Decimal(8,00));
    payment->getRequestedAmounts()->setTax(verifone_sdk::Decimal(1,00));
    payment->getRequestedAmounts()->setGratuity(verifone_sdk::Decimal(2,00));
    payment->getRequestedAmounts()->setTotal(verifone_sdk::Decimal(11,00));

    psdk->getTransactionManager()->startPayment(payment);

   } else {
    std::cout << "\n\nSPENCERFOO3: transaction_manager->startSession was NOT A SUCCESS\n\n";
   }


// SPENCERFOO
//  } else {
//      std::cout << "\n\nSPENCERFOO1: getStatus was NOT A SUCCESS\n\n";
//  }


}

