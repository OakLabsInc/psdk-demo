// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_host_adapter.djinni

#pragma once

#include "TransactionType.hpp"
#include <optional>
#include <psdk/export.h>
#include <string>
#include <utility>

namespace verifone_sdk {

/**
 * The transaction information. This will have multiple components describing the payment,
 * instrument/source, merchant and the sales context.
 */
struct PSDK_EXPORT HostTransaction final {
    /**
     * A client (user friendly) identifier for the transaction generated at the outset of a business
     * event. The format will be dependent on the calling system.
     *
     * A reference supplied by the system retaining the original source information and used to
     * assist in locating that transaction or a copy of the transaction. This value is critical in
     * matching values that are sent to other Payment processors or Acquirers. This value would
     * correspond to the ISO8583 specification as RRN in attribute DE 37, which limits the value to
     * being an alphanumeric value 12 characters.
     */
    std::optional<std::string> referenceId;
    /**
     * A type indicator for the main operation or service that was performed as part of the
     * transaction event.
     *
     * See {@link #TransactionType}
     */
    std::optional<TransactionType> transactionType;
    /** Three-letter ISO 4217 alphabetical currency code. e.g. USD. Values correspond to ISO 4217. */
    std::optional<std::string> currencyCode;
    /**
     * A amount type represented as money for all financial-related fields, such as balance,
     * payment due...
     */
    std::optional<std::string> totalAmount;
    /** The amount of gratuity or Tip if applicable. */
    std::optional<std::string> gratuityAmount;
    /** The amount of cashback. This is optional. */
    std::optional<std::string> cashbackAmount;
    /** The discount amount for the total quantity. */
    std::optional<std::string> discountAmount;
    /** The tax for this merchandise based on total quantity. */
    std::optional<std::string> taxAmount;
    /**
     * The time that the transaction occured at the POI/Terminal, this is referred to as the
     * acceptor datetime in ISO8583 specification DE 12. In some cases this may reflect the date
     * time when the transaction was received at a client Gateway or Switch where this is not
     * managed by Verifone. This format should include the necessary timezone information
     */
    std::optional<std::string> createdDateTime;
    /**
     * The Code identifying the card acceptor as issued by the Acquiring Institution. This may not
     * be unique across institutions. Also referred to as the MID. ISO8583 - DE 42
     */
    std::optional<std::string> merchantId;
    /**
     * The Code identifying the card accepting device as issued by the Acquiring Institution. This
     * may not be unique across institutions hence the use of a unique surrogate key. Also referred
     * to as the TID. ISO8583 - DE 41 or Terminal ID.
     *
     * This value will be validated against the authenticated Identity. So must match the range of
     * identifiers that have been allocated to the Merchant Entity who authenticates to the API.
     */
    std::optional<std::string> poiId;
    /**
     * The identifier used to represent this POI from an estate management perspective. This is not
     * the same as the TID which will be derived from the relationship with an Acquirer Agreement.
     */
    std::optional<std::string> poiName;
    /** A value to indicate the device serial number where known. */
    std::optional<std::string> poiSerialNumber;
    /**
     * The device type where transaction was captured, if known. This could be a model number or
     * other description e.g. VX690.
     */
    std::optional<std::string> poiDeviceType;

    HostTransaction(std::optional<std::string> referenceId_,
                    std::optional<TransactionType> transactionType_,
                    std::optional<std::string> currencyCode_,
                    std::optional<std::string> totalAmount_,
                    std::optional<std::string> gratuityAmount_,
                    std::optional<std::string> cashbackAmount_,
                    std::optional<std::string> discountAmount_,
                    std::optional<std::string> taxAmount_,
                    std::optional<std::string> createdDateTime_,
                    std::optional<std::string> merchantId_,
                    std::optional<std::string> poiId_,
                    std::optional<std::string> poiName_,
                    std::optional<std::string> poiSerialNumber_,
                    std::optional<std::string> poiDeviceType_)
    : referenceId(std::move(referenceId_))
    , transactionType(std::move(transactionType_))
    , currencyCode(std::move(currencyCode_))
    , totalAmount(std::move(totalAmount_))
    , gratuityAmount(std::move(gratuityAmount_))
    , cashbackAmount(std::move(cashbackAmount_))
    , discountAmount(std::move(discountAmount_))
    , taxAmount(std::move(taxAmount_))
    , createdDateTime(std::move(createdDateTime_))
    , merchantId(std::move(merchantId_))
    , poiId(std::move(poiId_))
    , poiName(std::move(poiName_))
    , poiSerialNumber(std::move(poiSerialNumber_))
    , poiDeviceType(std::move(poiDeviceType_))
    {}
};

}  // namespace verifone_sdk
