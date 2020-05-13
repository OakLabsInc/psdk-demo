// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace verifone_sdk {

class BasketManager;
class CommerceListener;
class CommerceResponse;
class LoginCredentials;
class Payment;
class ReportManager;
class Status;
class StoredValueCardInformation;
class Transaction;
class UserInputEventResponse;
enum class ContentType;
enum class DeliveryMethod;
enum class DeviceManagementAction;
enum class HostDecisionType;
enum class InputType;
enum class PresentationMethod;
enum class ReceiptType;
enum class TransactionManagerState;

/**
 * The service handle for performing transactions. Generally, only the 
 * static getTransactionManager methods should be used to obtain an 
 * instance of this class, ensuring
 * that the proper service and binder are wrapped by this class.
 */
class TransactionManager {
public:
    virtual ~TransactionManager() {}

    /**
     * Configures the debug mode of the device. Must be one of
     * {@link com.verifone.commerce.CommerceConstants#MODE_DEVICE},
     * {@link com.verifone.commerce.CommerceConstants#MODE_SIMULATOR},
     * {@link com.verifone.commerce.CommerceConstants#MODE_STUBS_DEBUG},
     * or 0 to remove any preference.
     */
    static std::string const DEBUG_MODE_KEY;

    /**
     * The debug parameters key to set how long the service should 
     * arbitrarily delay the response. This is particularly helpful when testing 
     * in STUB mode for some use cases.
     */
    static std::string const DEBUG_DELAY_IN_MS_KEY;

    /**
     * The debug parameters key to set which types of events should be 
     * arbitrarily returned as failed. This is particularly helpful when testing 
     * in STUB mode for some use cases.
     */
    static std::string const DEBUG_FAIL_EVENT_TYPES_KEY;

    /**
     * The device parameters key to set which port to use when connecting 
     * to the payment application on the payment terminal. This is useful if 
     * integrating with a payment application that uses a non-standard port for 
     * the messages, and should only be set in specific regions.
     */
    static std::string const DEVICE_PORT_KEY;

    /**
     * The device parameters key to require the POS to listen for connections 
     * from the payment terminal. The default is to connect outwards towards the 
     * terminal. Set this to the #ENABLED_VALUE to enable.
     */
    static std::string const DEVICE_LISTEN_KEY;

    /**
     * The device parameters key to set training mode for the device. This 
     * should generally be left unset, unless testing in the 
     * simulator or some other environment. Set this to the #ENABLED_VALUE to 
     * enable.
     */
    static std::string const DEVICE_TRAINING_MODE_KEY;

    /**
     * The device parameters key to set if specifying a specific protocol 
     * to use when communicating with the payment application. This is 
     * generally discovered, though some regions may require this parameter to be 
     * set explicitly.
     */
    static std::string const DEVICE_PROTOCOL_KEY;

    /**
     * The protocol value when communicating using EPAS, supported for 
     * multiple regions.
     */
    static std::string const DEVICE_PROTOCOL_EPAS;

    /**
     * The protocol value when communicating using NEXO, supported for 
     * multiple regions. EPAS changed its name to NEXO when moving to 
     * version 3.0.
     */
    static std::string const DEVICE_PROTOCOL_NEXO;

    /**
     * The protocol value when communicating using the general SCI 
     * protocol, without region-specific modifications.
     */
    static std::string const DEVICE_PROTOCOL_SCI;

    /** The protocol value for Israel. */
    static std::string const DEVICE_PROTOCOL_IL;

    /** The protocol value for the CM5 Payment App when running locally. */
    static std::string const DEVICE_PROTOCOL_LOCAL;

    /** The protocol value for CRS. */
    static std::string const DEVICE_PROTOCOL_CRS;

    /** The protocol value for SDI. */
    static std::string const DEVICE_PROTOCOL_SDI;

    /**
     * Allows the calling POS application to provide an application name, 
     * sometimes used for certification or to meet other requirements.
     */
    static std::string const DEVICE_APPLICATION_NAME_KEY;

    /**
     * Allows the calling POS application to provide an application 
     * version, sometimes used for certification or to meet other 
     * requirements.
     */
    static std::string const DEVICE_APPLICATION_VERSION_KEY;

    /**
     * Allows the calling POS application to provide a manufacturer ID, 
     * sometimes used for certification or to meet other requirements.
     */
    static std::string const DEVICE_APPLICATION_MANUFACTURER_ID_KEY;

    /**
     * Allows the calling POS application to provide a certification 
     * code, sometimes used for certification or to meet other requirements.
     */
    static std::string const DEVICE_APPLICATION_CERTIFICATION_CODE_KEY;

    /**
     * Allows the calling POS application to define which CP Triggers 
     * it can support. When passed, this expects an array of the 
     * corresponding event types, e.g., if Amount Adjustment
     * is supported, include the value from 
     * {@link AmountAdjustedEvent#TYPE} in the array. Refer to
     * {@link #enableCpTriggerHandling()} for more information.
     */
    static std::string const DEVICE_SUPPORTED_CP_TRIGGERS_KEY;

    /**
     * Informs the payment terminal that the POS application should or should not perform the 
     * host authentication. Terminal must be configured for this or initialization will fail.
     */
    static std::string const DEVICE_HOST_AUTHENTICATION_KEY;

    /** This indicates that the terminal is expected to send authentication request events */
    static std::string const DEVICE_HOST_AUTHENTICATION_ENABLED;

    /**
     * The value used when enabling a specific key. Generally disabling that 
     * value can be performed by leaving it unset or setting it to an empty value.
     */
    static std::string const ENABLED_VALUE;

    /** Please use {@link #STATE_LOGGING_IN}. */
    static constexpr int32_t SESSION_SERVICE_CONNECTING = -4;

    /** Please use {@link #STATE_NOT_LOGGED_IN}. */
    static constexpr int32_t SESSION_CLOSED = 1;

    /** Please use {@link #STATE_LOGGED_IN}. */
    static constexpr int32_t SESSION_OPEN = 3;

    /** Please use {@link #STATE_SESSION_OPEN}. */
    static constexpr int32_t TRANSACTION_PROCESSING = 5;

    /**
     * Starts a session. This reserves the terminal for this application, preventing conflicts
     * with other apps.
     * @param listener The first listener for the session events. There may be more listeners added,
     * but there must always be at least one registered.
     * @param transaction The transaction for this session.  Please note
     * that this parameter may be null if a transaction is not required 
     * for the session.
     * @return True if the session opening message was submitted successfully. The SessionListener
     * will receive the start event if the session is created, or will receive the appropriate
     * message if the session is not able to be created.
     */
    virtual bool startSession(const std::shared_ptr<CommerceListener> & listener, const std::shared_ptr<Transaction> & transaction) = 0;

    /**
     * Not currently supported. Attempts to resume a session in the case of
     * a Session Closed event or an application crash. If it is not 
     * possible to resume, this may return immediately or
     * may send a Session Resume Failed event to the listener.
     * @param listener The first listener for the session events. There may 
     * be more listeners added, but there must always be at least one 
     * registered. @return True if the session opening message was 
     * submitted successfully. The listener will
     * receive the start event if the session is created, or will receive 
     * the appropriate message if the session is not able to be created.
     */
    virtual bool resumeSession(const std::shared_ptr<CommerceListener> & listener, const std::string & sessionId) = 0;

    /**
     * Allows adding new listeners for session events.
     * @param listener A listener for session events. There may be more 
     * listeners added, but there must always be at least one registered.
     * @return True if the listener was not already registered.
     */
    virtual bool addSessionListener(const std::shared_ptr<CommerceListener> & listener) = 0;

    /**
     * Removes a session listener. The last session listener cannot be 
     * removed through this method, as there must always be a listener 
     * until the session ends. 
     * @param listener A registered listener for the session events. 
     * @return True if the listener exists.
     */
    virtual bool removeSessionListener(const std::shared_ptr<CommerceListener> & listener) = 0;

    /**
     * Get the set of currently registered listeners.
     * @return The set of ICommerceListeners that are currently registered. 
     * This set is independent of the internal set, and should only used 
     * as a reference for the current listeners, and
     * not be expected to update with the addition or removal of listeners.
     */
    virtual std::vector<std::shared_ptr<CommerceListener>> getListeners() = 0;

    /**
     * Ends a session. This releases the terminal reservation for this 
     * application, allowing other applications to open sessions. This 
     * sends a stop message to the terminal to exit the
     * terminal application if launched by this app. The internal service 
     * may send this on behalf of this POS application if this application 
     * crashes or exits without closing the session. This method should be 
     * called prior to the release of the final reference to the
     * Commerce Manager. Once the session is ended, references to any 
     * registered listeners are removed once the Session End event is 
     * properly reported. 
     * @return True if the session end message was  submitted successfully. 
     * The listener will receive the end event if the session is ended 
     * properly, or will receive the appropriate message if the session is
     * not able to be ended.
     */
    virtual bool endSession() = 0;

    /**
     * Gets the most recent transaction. This transaction may still be in 
     * progress, and should be treated accordingly. 
     * @return The most recent transaction.
     */
    virtual std::shared_ptr<Transaction> getTransaction() = 0;

    /**
     * The method to get an appropriate concrete implementation of the 
     * Basket Manager. 
     * @return A concrete implementation of the basket manager.
     */
    virtual std::shared_ptr<BasketManager> getBasketManager() = 0;

    /**
     * Starts a payment for the current transaction. 
     * @param payment The payment object to use. Use
     * {@link Payment#setRequestedPaymentAmount(BigDecimal)} to define the 
     * amount for a single payment if it should be different than the 
     * current transaction total. Use
     * {@link Payment#setAuthorizationMethod(Payment.AuthorizationMethod)} 
     * to define the required authorization method for this payment.
     */
    virtual std::shared_ptr<Status> startPayment(const std::shared_ptr<Payment> & payment) = 0;

    /**
     * Attempts to void the transaction.
     * @param payment The payment to void.
     * @return A status object indicating if the void command was issued 
     * properly. Events regarding the void itself are sent to the 
     * registered listener(s).
     */
    virtual std::shared_ptr<Status> processVoid(const std::shared_ptr<Payment> & payment) = 0;

    /**
     * Attempts to refund the specific payment. If multiple payments were 
     * accepted in a transaction, this method will need to be called 
     * individually for each payment, allowing the listener(s)
     * to better respond to the related events.
     * @param payment  The payment to refund.
     * @return The status object indicating if the refund command was 
     * issued properly. Events regarding the refund itself are sent to the 
     * registered listener(s).
     */
    virtual std::shared_ptr<Status> processRefund(const std::shared_ptr<Payment> & payment) = 0;

    /**
     * Activates a stored value card. Fires a {@link StoredValueCardEvent} 
     * to the listeners.
     * @param payment A payment object to provide the information needed. 
     * Use {@link Payment#setRequestedPaymentAmount(BigDecimal)} to define 
     * the amount to load, optionally use 
     * {@link Payment#setAuthCode(String)} to provide a
     * reference auth code, and optionally use
     * {@link Payment#setCardInformation(CardInformation)} to
     * provide a {@link StoredValueCardInformation} object to provide 
     * further information about the stored value card.
     */
    virtual std::shared_ptr<Status> activateStoredValueCard(const std::shared_ptr<Payment> & payment) = 0;

    /**
     * Loads an amount on to an existing stored value card. Refer to
     * {@link #activateStoredValueCard(Payment)}.
     */
    virtual std::shared_ptr<Status> loadStoredValueCard(const std::shared_ptr<Payment> & payment) = 0;

    /**
     * Removes the requested amount from the stored value card. Refer to
     * {@link #activateStoredValueCard(Payment)}.
     * @param payment If this is null or 
     * {@link Payment#getRequestedPaymentAmount()} is not set,
     * The entire available balance will be removed from the card, sometimes
     * requiring a balance inquiry before performing the unload. If
     * {@link Payment#getRequestedPaymentAmount()} is set to an amount, 
     * attempts to remove that amount from the card.
     */
    virtual std::shared_ptr<Status> unloadStoredValueCard(const std::shared_ptr<Payment> & payment) = 0;

    /**
     * Retrieves the current balance for a stored value card. Fires a
     * {@link StoredValueCardEvent} to the listeners.
     * @param cardInformation Optionally pass card information to use when 
     * fetching the balance.  
     * Use {@link StoredValueCardInformation#setType(String)} to define
     * the type of card for which we are checking the balance. Use
     * {@link StoredValueCardInformation#setCardPan(String)} or
     * {@link StoredValueCardInformation#setCardToken(String)} to pass in
     * the information about the card to be checked.
     */
    virtual std::shared_ptr<Status> getStoredValueCardBalance(const std::shared_ptr<StoredValueCardInformation> & cardInformation) = 0;

    /**
     * Presents either HTML or Text content to the customer using the customer-facing display. The
     * content will be displayed until some other request is sent to display different content, or
     * something on the device controlling the display decides that it must be updated, depending on
     * the minimum display time.
     * @param content The actual content to be presented.
     * @param contentType The type of content to be presented, either
     *                    {@link ContentType#HTML} or {@link ContentType#TEXT}
     * @param minimumDisplayTime The minimum amount of time to display this content before the
     *                           customer display can update itself to different content. Any
     *                           following request, such as starting a payment or presenting
     *                           additional content, will override the current displayed content
     *                           regardless of this time, but the device controlling the display
     *                           will not update it without a specific command before this time is
     *                           expired. Defaults to 0. Values less than 0 are undefined.
     * @return The status of the request to the terminal. There is no other event returned to the caller.
     */
    virtual std::shared_ptr<Status> presentCustomerContent(const std::string & content, ContentType contentType, int32_t minimumDisplayTime) = 0;

    /**
     * Use {@link #presentUserOptions(String header, ArrayList<String> buttonLabels)} 
     * instead.
     */
    virtual std::shared_ptr<Status> presentReceiptDeliveryOptions(const std::vector<DeliveryMethod> & availableDeliveryMethods, const std::string & customerPhone, const std::string & customerEmail) = 0;

    /**
     * Presents button options to the user and relaying the 
     * selected option back to the listener. This does not 
     * automatically include a back/exit/cancel option.
     *
     * EPAS reference 4.5.3 Input, 4.5.3.1 Processing Overview. 
     * For #1 Reading Confirmation (“GetAnyKey”), pass a header 
     * with a null or empty array of button labels. For #2 Asks a
     * Question (“GetConfirmation”, “SiteManager”), pass two 
     * buttons with the appropriate values. For #4 Select an 
     * item in a Menu (“GetMenuEntry”), pass any number of buttons.
     *
     * SCA reference Customer Buttons. Automatically breaks the 
     * header into the appropriate maximum lengths using word 
     * wrapping. Supports up to 6 header lines followed by 6 
     * buttons.
     *
     * @param header The message to be displayed to the user, 
     * preferably providing context for the user to select the 
     * correct option. This is optional.
     * @param buttonLabels An array of button labels presented 
     * to the user. The corresponding event returns the index of 
     * the button selected based on this array. This is required.
     * @return The status of the request to the payment 
     * terminal. The selected option is returned in the appropriate 
     * {@link UserInputEvent.Values#getSelectedIndices()}.
     */
    virtual std::shared_ptr<Status> presentUserOptions(const std::string & header, const std::vector<std::string> & buttonLabels) = 0;

    /**
     * Presents the user with a screen to collect information, 
     * specially formatting the keyboard and display based on 
     * the input type.
     * @param inputType The type of input requested from the 
     * user. This is required.
     * @param message The message to display to the user to 
     * provide context for the input. This is optional.
     * @param defaultValue The default value for the input 
     * field. This is optional.
     * @return The status of the request to the payment 
     * terminal. The input value is returned in the appropriate 
     * {@link UserInputEvent UserInputEvent}.
     */
    virtual std::shared_ptr<Status> requestUserInput(InputType inputType, const std::string & message, const std::string & defaultValue) = 0;

    /**
     * Asks the terminal to collect card information from the user and 
     * return a token for the information. In some regions, this can also 
     * be called after the payment has started to generate a token for the 
     * card that is currently being used for payment, instead of requiring 
     * a separate card entry action.
     * @return The status of the request to the terminal.
     */
    virtual std::shared_ptr<Status> requestCardToken() = 0;

    /**
     * Allows the service to be set to a different mode, allowing automated 
     * testing and other similar tasks.
     * @param mode One of the debug modes from the CommerceConstants.
     */
    virtual void setDebugMode(int32_t mode) = 0;

    /**
     * A map of recognized debug parameters. Reference the DEBUG constants 
     * for more information. Some regions may include additional constants 
     * not defined in this file, but these may be recognized by the 
     * underlying service as appropriate. Any unrecognized keys will be 
     * ignored.
     */
    virtual void setDebugParams(const std::unordered_map<std::string, std::string> & debugParams) = 0;

    /**
     * Please use {@link #setDeviceParams(Map)} instead, using the 
     * appropriate DEVICE key constants.
     */
    virtual void setDeviceParams(const std::unordered_map<std::string, std::string> & deviceParams) = 0;

    /**
     * Adds a listener for events that occur without an active session. For 
     * example, a
     * {@link com.verifone.commerce.payment.reports.ReconciliationEvent} is 
     * sent outside of a session, as the reconciliation commands are not 
     * issued within the context of a session. Returns success if the 
     * listener was added or is already registered, and false if the 
     * listener was not registered.
     */
    virtual bool addGeneralListener(const std::shared_ptr<CommerceListener> & listener) = 0;

    /**
     * Removes a listener for events that occur without an active session. 
     * Refer to
     * {@link #addGeneralListener(CommerceListener)} for more information.
     * Returns success if the listener was removed or is not registered, 
     * and false if the listener was not able to be removed.
     */
    virtual bool removeGeneralListener(const std::shared_ptr<CommerceListener> & listener) = 0;

    /**
     * The method to get an appropriate concrete implementation of the 
     * Report Manager.
     * @return A concrete implementation of the report manager.
     */
    virtual std::shared_ptr<ReportManager> getReportManager() = 0;

    /**
     * Aborts the most recent command, but does not reset the session 
     * unless aborting the startSession call. If a new invoice ID is 
     * needed, or a new cart, end the session or purge the basket, 
     * respectively.
     * @return A status object indicating if the command was issued 
     * properly. Events regarding the effect of the command are sent to the 
     * registered listener(s).
     */
    virtual std::shared_ptr<Status> abort() = 0;

    /**
     * Checks if the current terminal implementation allows handling of a 
     * specific command, as listed in the constants above. Returns true if 
     * the interface can handle the command, or false if not.
     */
    virtual bool isCapable(const std::string & capability) = 0;

    /**
     * Logs in through the payment terminal, possibly synchronizing 
     * information from the host to the terminal and performing other 
     * similar setup/configuration steps. Also used for following
     * transactions, allowing them to be tracked by user and/or according 
     * to the shift. Notifies all general listeners with a 
     * {@link TransactionEvent} of type
     * {@link TransactionEvent#LOGIN_COMPLETED}. Use the status from this 
     * event to determine the success or failure of the request, using any 
     * of the constant error codes to determine the nature of the failure 
     * if not successful.
     * @param listener Optional. A commerce listener that is attached to the general events.
     * @param userId Optional. The username / operator ID of the cashier, 
     * used by the payment terminal or the host to group transactions together. 
     * If the host requires login by a specific known cashier/user, then this field is required, 
     * but normally this field is optional and only used for reporting and transaction queries.
     * @param password Optional. Only required when the host must authenticate the current operator,
     *  otherwise this should be unset.
     * @param shiftNumber: Optional. The current shift ID, sometimes used by the payment
     * terminal or the host to group transactions together. This can be used later to query 
     * the transactions performed during this shift.
     * @return A status code. Returns success or failure of sending the request to the terminal. 
     * The actual result will be sent using the notification described 
     * earlier.
     */
    virtual std::shared_ptr<Status> login(const std::shared_ptr<CommerceListener> & listener, const std::optional<std::string> & userId, const std::optional<std::string> & password, const std::optional<std::string> & shiftNumber) = 0;

    /**
     * Logs in through the payment terminal, possibly synchronizing 
     * information from the host to the terminal and performing other 
     * similar setup/configuration steps. Also used for following
     * transactions, allowing them to be tracked by user and/or according 
     * to the shift. Notifies all general listeners with a 
     * {@link TransactionEvent} of type
     * {@link TransactionEvent#LOGIN_COMPLETED}. Use the status from this 
     * event to determine the success or failure of the request, using any 
     * of the constant error codes to determine the nature of the failure 
     * if not successful.
     * @param LoginCredentials.
     * @return A status code. Returns success or failure of sending the request to the terminal. 
     * The actual result will be sent using the notification described 
     * earlier.
     */
    virtual std::shared_ptr<Status> loginWithCredentials(const std::shared_ptr<LoginCredentials> & credentials) = 0;

    /**
     * Logs out through the payment terminal. This must always be used in 
     * conjunction with the
     * {@link #login(CommerceListener, String, String, String)} method. 
     * Returns the success or failure of sending the request to the 
     * terminal. The actual result will be sent to the general
     * listeners with a 
     * {@link TransactionEvent} of type 
     * {@link TransactionEvent#LOGOUT_COMPLETED}.
     * Use the status from this event to determine the success or failure 
     * of the request, using any of the constant error codes to determine 
     * the nature of the failure if not successful.
     */
    virtual std::shared_ptr<Status> logout() = 0;

    /**
     * Immediately returns the current state of the communication between
     * the POS device and the payment terminal. This may change based 
     * on messages already sent but not yet handled.
     */
    virtual TransactionManagerState getState() = 0;

    /**
     * Returns the information requested from the terminal, such as 
     * updating configuration options or performing similar administrative 
     * tasks.
     */
    virtual std::shared_ptr<Status> sendInputResponse(const std::shared_ptr<UserInputEventResponse> & user_input_event_response) = 0;

    /**
     * Formerly returned the status when printing something on behalf of 
     * the terminal.
     */
    virtual std::shared_ptr<Status> sendPrintResponse(const std::string & result) = 0;

    /**
     * Request information about card data from terminal
     * @param message The message to be displayed in terminal
     * @param inputMethods array of 
     * {@link 
     * com.verifone.commerce.entities.CardInformation.PresentationMethod}, 
     * optional
     * @return The status of the request to the terminal.
     */
    virtual std::shared_ptr<Status> requestCardData(const std::string & message, const std::vector<PresentationMethod> & presentationMethodNames) = 0;

    /**
     * Sends back the response to a specific event, allowing the POS to 
     * asynchronously respond to received events.
     */
    virtual std::shared_ptr<Status> sendEventResponse(const std::shared_ptr<CommerceResponse> & response) = 0;

    /**
     * Retrieves information on the device, sending a 
     * DeviceInformationReceivedEvent to the listener.
     */
    virtual std::shared_ptr<Status> getDeviceInformation() = 0;

    /**
     * Convenient method to reprint the customer receipt using
     * {@link com.verifone.commerce.entities.Receipt#DELIVERY_METHOD_PRINT}.
     */
    virtual std::shared_ptr<Status> reprintReceipt(const std::shared_ptr<Payment> & payment, ReceiptType receiptType, DeliveryMethod receiptDeliveryMethod, const std::optional<std::string> & deliveryAddress) = 0;

    /** Sends back the response to a host authorization request */
    virtual std::shared_ptr<Status> respondToHostAuthorization(const std::string & authorizationCode, HostDecisionType hostDecision, const std::unordered_map<std::string, std::string> & emvTags) = 0;

    /** Sends back the response to a finalize transaction request */
    virtual std::shared_ptr<Status> respondToHostFinalizeTransaction(const std::string & authorizationCode, HostDecisionType hostDecision, const std::unordered_map<std::string, std::string> & emvTags) = 0;

    /** Perform device management action */
    virtual std::shared_ptr<Status> performDeviceManagement(DeviceManagementAction deviceManagementAction) = 0;
};

}  // namespace verifone_sdk