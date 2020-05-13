// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_entities.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class AmountTotals;
enum class OfferType;
struct Decimal;

/**
 * This represents the data that is shared between the terminal and the Android application. Setting
 * the fields is only relevant when sending the data to the terminal, and conversely, getting the
 * fields is only relevant when receiving this object from the terminal.
 */
class Offer {
public:
    virtual ~Offer() {}

    /** create Offer */
    static std::shared_ptr<Offer> create();

    /**
     * The unique ID for this merchandise item as it exists in the basket. If multiple items with
     * the same SKU/UPC are added individually to the basket, this basket item ID will be used to
     * distinguish between them. This will be generated by the service if not provided.
     */
    virtual std::optional<std::string> getBasketItemId() const = 0;

    /**
     * The sequence for this item. This is generally auto-incremented as items are added to the
     * basket. This is generally set by the underlying service, but can be set manually if required.
     */
    virtual int32_t getSequence() const = 0;

    /**
     * The display order for this item. This is generally auto-incremented as items are added to
     * the basket, using a gap value to allow insertion between items at a later time.
     */
    virtual int32_t getDisplayOrder() const = 0;

    /**
     * The line to display to the customer. This may include standard tab and line break characters
     * if desired for normal text, or this may use HTML formatting. This will be generated by the
     * service if not provided.
     */
    virtual std::optional<std::string> getDisplayLine() const = 0;

    /** A human-readable name. This is optional. */
    virtual std::optional<std::string> getName() const = 0;

    /** A human-readable description. This is optional. */
    virtual std::optional<std::string> getDescription() const = 0;

    /** SKU of the item. This is optional. */
    virtual std::optional<std::string> getSku() const = 0;

    /** EAN / UPC of the item. This is optional. */
    virtual std::optional<std::string> getUpc() const = 0;

    /**
     * The final total amount for this item as a GAAP-standard BigDecimal, including the
     * extendedPrice, tax, and discount. This is required.
     */
    virtual std::optional<Decimal> getAmount() const = 0;

    /**
     * The tax for this merchandise based on total quantity as a GAAP-standard BigDecimal. This
     * is optional.
     */
    virtual std::optional<Decimal> getTax() const = 0;

    /**
     * Set to true if this item was removed from the basket, useful for business analytics.
     * Removed items do not contribute to the total transaction amount, and are not displayed nor
     * on the receipt. This is set by the service.
     */
    virtual bool getRemoved() const = 0;

    /**
     * The unique ID for this merchandise item as it exists in the basket. If multiple items with
     * the same SKU/UPC are added individually to the basket, this basket item ID will be used to
     * distinguish between them. This will be generated by the service if not provided.
     */
    virtual void setBasketItemId(const std::optional<std::string> & itemId) = 0;

    /**
     * The sequence for this item. This is generally auto-incremented as items are added to the
     * basket. This is generally set by the underlying service, but can be set manually if required.
     */
    virtual void setSequence(int32_t sequence) = 0;

    /**
     * The display order for this item. This is generally auto-incremented as items are added to
     * the basket, using a gap value to allow insertion between items at a later time.
     */
    virtual void setDisplayOrder(int32_t displayOrder) = 0;

    /**
     * The line to display to the customer. This may include standard tab and line break characters
     * if desired for normal text, or this may use HTML formatting. This will be generated by the
     * service if not provided.
     */
    virtual void setDisplayLine(const std::optional<std::string> & displayLine) = 0;

    /** A human-readable name. This is optional. */
    virtual void setName(const std::optional<std::string> & name) = 0;

    /** A human-readable description. This is optional. */
    virtual void setDescription(const std::optional<std::string> & description) = 0;

    /** SKU of the item. This is optional. */
    virtual void setSku(const std::optional<std::string> & sku) = 0;

    /** EAN / UPC of the item. This is optional. */
    virtual void setUpc(const std::optional<std::string> & upc) = 0;

    /**
     * The final total amount for this item as a GAAP-standard BigDecimal, including the
     * extendedPrice, tax, and discount. This is required.
     */
    virtual void setAmount(const std::optional<Decimal> & amount) = 0;

    /**
     * The tax for this merchandise based on total quantity as a GAAP-standard BigDecimal. This
     * is optional.
     */
    virtual void setTax(const std::optional<Decimal> & tax) = 0;

    /**
     * Set to true if this item was removed from the basket, useful for business analytics.
     * Removed items do not contribute to the total transaction amount, and are not displayed nor
     * on the receipt. This is set by the service.
     */
    virtual void setRemoved(bool removed) = 0;

    /** Returns the amounts for this item in the basket. */
    virtual std::shared_ptr<AmountTotals> getAmounts() const = 0;

    /** Set the amounts for this item. */
    virtual void setAmounts(const std::shared_ptr<AmountTotals> & amounts) = 0;

    /**
     * Alphanumeric offer reference. May be multiple offers in the same transaction. Could be a back
     * end loaded offer that the POS will redeem or a manufacturer coupon code. This is required.
     */
    virtual std::optional<std::string> getOfferId() const = 0;

    /** The type of the offer. This is required. */
    virtual std::optional<OfferType> getOfferType() const = 0;

    /** Indicates if the purchase is returnable. This is optional. */
    virtual bool getOfferRefundable() const = 0;

    /** Indicates if the offer may combined with other combinable offers. This is optional. */
    virtual bool getOfferCombinable() const = 0;

    /**
     * Percentage discount associated with the offer as a BigInteger(13,2). Either this or
     * offerDiscount is required, setting one will override the other.
     */
    virtual std::optional<Decimal> getOfferPercentDiscount() const = 0;

    /**
     * Discount as a GAAP-standard BigDecimal in the transaction currency. This is represented as
     * negative amount. Either this or offerPercentDiscount is required, setting one will override
     * the other.
     */
    virtual std::optional<Decimal> getOfferDiscount() const = 0;

    /** Unique reference to identify the Loyalty Program. This is required. */
    virtual std::optional<std::string> getProgramId() const = 0;

    /** Field for merchant specific offers. This is optional. */
    virtual std::optional<std::string> getMerchantOfferCode() const = 0;

    /** Represented as SKU or UPC. This is optional. */
    virtual std::optional<std::string> getProductCode() const = 0;

    /** Only applies to special product offers. This is optional. */
    virtual std::optional<std::string> getAssociatedProductCode() const = 0;

    /**
     * E.g., BOGO (Buy One Get One) using productCode and associatedProductCode. BOGOH (Buy One Get
     * One Half Off) using productCode, percentageDiscount and associatedProductCode. This is
     * optional.
     */
    virtual std::optional<std::string> getSpecialProductCode() const = 0;

    /** Reserved for future use. This is ignored. */
    virtual std::optional<std::string> getQrCode() const = 0;

    /**
     * The ID of the basket line if this is applied to a specific item in the basket.
     * This is optional.
     */
    virtual std::optional<std::string> getReferenceBasketLineItemId() const = 0;

    /** Refer to {@link #getOfferId()}. */
    virtual void setOfferId(const std::optional<std::string> & offerId) = 0;

    /** Refer to {@link #getOfferType()}. */
    virtual void setOfferType(std::optional<OfferType> offerType) = 0;

    /** Refer to {@link #getOfferRefundable()}. */
    virtual void setOfferRefundable(bool offerRefundable) = 0;

    /** Refer to {@link #getOfferCombinable()}. */
    virtual void setOfferCombinable(bool offerCombinable) = 0;

    /** Refer to {@link #getOfferPercentDiscount()}. */
    virtual void setOfferPercentDiscount(const std::optional<Decimal> & percentDiscount) = 0;

    /** Refer to {@link #getOfferDiscount()}. */
    virtual void setOfferDiscount(const std::optional<Decimal> & offerDiscount) = 0;

    /** Refer to {@link #getProgramId()}. */
    virtual void setProgramId(const std::optional<std::string> & programId) = 0;

    /** Refer to {@link #getMerchantOfferCode()}. */
    virtual void setMerchantOfferCode(const std::optional<std::string> & offerCode) = 0;

    /** Refer to {@link #getProductCode()}. */
    virtual void setProductCode(const std::optional<std::string> & productCode) = 0;

    /** Refer to {@link #getAssociatedProductCode()}. */
    virtual void setAssociatedProductCode(const std::optional<std::string> & productCode) = 0;

    /** Refer to {@link #getSpecialProductCode()}. */
    virtual void setSpecialProductCode(const std::optional<std::string> & productCode) = 0;

    /** Refer to {@link #getQrCode()}. */
    virtual void setQrCode(const std::optional<std::string> & qrCode) = 0;

    /** Refer to {@link #getReferenceBasketLineItemId()}. */
    virtual void setReferenceBasketLineItemId(const std::optional<std::string> & basketLineItemId) = 0;

    /**
     * Someday, implement to allow in basket updates to make it easier when sending items between
     * the service and back.
     */
    virtual void update(const std::shared_ptr<Offer> & offer) = 0;
};

}  // namespace verifone_sdk
