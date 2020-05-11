// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_entities.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>

namespace verifone_sdk {

class AmountTotals;
struct Decimal;

/** Allows attaching a modifier to an existing merchandise object. */
class Modifier {
public:
    virtual ~Modifier() {}

    /** create Modifier */
    static std::shared_ptr<Modifier> create();

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

    /** Refer to {@link #setQuantity(Decimal quantity)}. */
    virtual std::optional<Decimal> getQuantity() const = 0;

    /** return The unit of Measurement for Quantity value */
    virtual std::optional<std::string> getUnitOfMeasurement() const = 0;

    /** return basket item id attached */
    virtual std::optional<std::string> getAttachedToBasketItemId() const = 0;

    /** Refer to {@link #setQuantity(Decimal quantity)}. */
    virtual void setQuantity(const std::optional<Decimal> & quantity) = 0;

    /** The unit of Measurement for Quantity value */
    virtual void setUnitOfMeasurement(const std::optional<std::string> & unitOfMeasurement) = 0;

    /**
     * Set the basket item ID for the item to which this modifier is attached. If not set,
     * this will be set automatically.
     */
    virtual void setAttachedToBasketItemId(const std::optional<std::string> & attachedToBasketItemId) = 0;
};

}  // namespace verifone_sdk
