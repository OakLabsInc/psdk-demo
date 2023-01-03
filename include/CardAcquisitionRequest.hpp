// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <memory>
#include <optional>
#include <psdk/export.h>
#include <string>
#include <vector>

namespace verifone_sdk {

class CardInformation;
enum class EarlyCaptureOperationType;
enum class PresentationMethod;
struct Decimal;

/** Card acquisition interface */
class PSDK_EXPORT CardAcquisitionRequest {
public:
    virtual ~CardAcquisitionRequest() {}

    /**
     * Creates an instance of CardAcquisitionRequest
     * @param if true, requests to collect card token 
     * @param the message to be displayed in terminal
     * @param inputMethods array of {@link com.verifone.commerce.entities.CardInformation.PresentationMethod}
     * @param optional list of AID(Application ID) strings
     * @param optional list of allowed payment brand names
     * @param optional list of allowed loyalty brand names
     * @param optional, if true, card reading from the background without any display to enable a more seamless
     * present-ahead experience, also enabling infinite timeout
     */
    static std::shared_ptr<CardAcquisitionRequest> create(bool isTokenRequest, const std::string & message, const std::vector<PresentationMethod> & presentationMethodNames, const std::optional<std::vector<std::string>> & aidList, const std::optional<std::vector<std::string>> & allowedPaymentBrand, const std::optional<std::vector<std::string>> & allowedLoyaltyBrand, std::optional<bool> isBackground);

    /**
     * Creates an instance of CardAcquisitionRequest for single tap payment functionality
     * @param the message to be displayed in terminal
     * @param inputMethods array of {@link com.verifone.commerce.entities.CardInformation.PresentationMethod}
     * @param amount optional for getting card data with SCA payment application
     * @param earlyCaptureOperationType required for the operation type on which Early Card Capture needs to be performed
     */
    static std::shared_ptr<CardAcquisitionRequest> createEarlyCardCapture(const std::string & message, const std::vector<PresentationMethod> & presentationMethodNames, const std::optional<Decimal> & reservedAmount, EarlyCaptureOperationType earlyCaptureOperationType);

    /**
     * Creates an instance of CardAcquisitionRequest for Token request with card information details
     * @param the message to be displayed in terminal
     * @param cardInformation details. Required for calls subsequesnt to createEarlyCardCapture
     * and constrains the presented card to values set in this parameter. Should be omitted otherwise.
     */
    static std::shared_ptr<CardAcquisitionRequest> createTokenRequest(const std::string & message, const std::shared_ptr<CardInformation> & cardInformation);
};

}  // namespace verifone_sdk
