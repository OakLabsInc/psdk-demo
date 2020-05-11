// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_entities.djinni

#pragma once

#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class Image;
enum class ReceiptSection;
enum class ReceiptType;

/**
 * Provided as a part of the Payment object when a payment is received. This object cannot be
 * retrieved at a later time, and should be stored if re-printing may be required.
 */
class Receipt {
public:
    virtual ~Receipt() {}

    /** Factory methord to create Receipt object */
    static std::shared_ptr<Receipt> create();

    /**
     * Allows additional customization of the receipt at specific compliant sections of the
     * receipt.
     */
    virtual std::optional<std::string> getTextAtSection(ReceiptSection section) const = 0;

    /**
     * Returns true if the merchant has decided to include their logo, or false otherwise.
     * Defaults to false.
     */
    virtual bool isLogoIncluded() const = 0;

    /**
     * Returns true if the merchant has decided to include a custom header, or false otherwise.
     * Defaults to false.
     */
    virtual bool hasCustomHeader() const = 0;

    /**
     * Returns true if the merchant has decided to include the cashier's name, or false otherwise.
     * Defaults to false.
     */
    virtual bool isCashierNameIncluded() const = 0;

    /**
     * Returns true if the merchant has decided to include a custom mFooter, or false otherwise.
     * Defaults to false.
     */
    virtual bool hasCustomFooter() const = 0;

    /**
     * Returns true if the merchant has decided to include an online url for the receipt, or false
     * otherwise. Defaults to false.
     */
    virtual bool isOnlineUrlIncluded() const = 0;

    /**
     * Returns true if the merchant has decided to include the QR Code with the online url,
     * or false otherwise. Defaults to false.
     */
    virtual bool isQrCodeIncluded() const = 0;

    /** The type of receipt, generally either for the customer or for the merchant. */
    virtual ReceiptType getReceiptType() const = 0;

    /**
     * The Business Info section of the receipt, as customized by the merchant in the receipt
     * settings for this venue.
     */
    virtual std::optional<std::string> getBusinessInfo() const = 0;

    /** Return custom greeting message */
    virtual std::optional<std::string> getCustomGreeting() const = 0;

    /** The footer as defined by the merchant in receipt settings. */
    virtual std::optional<std::string> getCustomFooter() const = 0;

    /** Return Cashier name */
    virtual std::optional<std::string> getCashierName() const = 0;

    /**
     * The transaction information, including basket, adjustments, offers, donations, taxes, and
     * totals, as provided by the payment application.
     */
    virtual std::optional<std::string> getTransactionInformation() const = 0;

    /**
     * The payment information, in particular, the EMV fields or other relevant lines
     * necessary for legal compliance, as provided by the payment application.
     */
    virtual std::optional<std::string> getPaymentInformation() const = 0;

    /**
     * The mFooter as modified by other applications in response to the REQUEST_APPEND_RECEIPT
     * API. Returns the online URL in an HTML-formatted string, including a QR code image if
     * entered by the merchant.
     */
    virtual std::optional<std::string> getOnlineUrl() const = 0;

    /** Return the Qr code image */
    virtual std::optional<std::string> getQrCodeImage() const = 0;

    /** The footer as modified by other applications in response to the REQUEST_APPEND_RECEIPT API. */
    virtual std::optional<std::string> getFooter() const = 0;

    /** Returns the original HTML of the receipt as received from the payment application */
    virtual std::optional<std::string> getOriginalHtml() const = 0;

    /** Convenience method to get the original receipt from the payment application as an image. */
    virtual std::shared_ptr<Image> getOriginalImage() const = 0;

    /** Returns the final receipt as HTML. */
    virtual std::optional<std::string> getAsHtml() const = 0;

    /** Refer to {@link #getTextAtSection} */
    virtual bool insertTextAtSection(const std::optional<std::string> & text, ReceiptSection receiptSection) = 0;
};

}  // namespace verifone_sdk
