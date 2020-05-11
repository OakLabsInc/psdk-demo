// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace verifone_sdk {

class Image;
class MenuEntry;
enum class ContentType;
enum class InputType;

/** RequestParameters for UserInputEvents */
class RequestParameters {
public:
    virtual ~RequestParameters() {}

    /** Creates an instance of RequestParameters */
    static std::shared_ptr<RequestParameters> create();

    /** Refer to {@link UserInputEvent#getInputType()}. */
    virtual InputType getInputType() const = 0;

    /** Configures the input type for the request. Refer to {@link UserInputEvent#getInputType()}. */
    virtual void setInputType(InputType inputType) = 0;

    /** Refer to {@link UserInputEvent#getDefaultValue()}. */
    virtual std::optional<std::string> getDefaultValue() const = 0;

    /** Configures the default for the request. Refer to {@link UserInputEvent#getDefaultValue()}. */
    virtual void setDefaultValue(const std::optional<std::string> & defaultValue) = 0;

    /**
     * If the input type is {@link InputType#MENU_OPTIONS}, and the event type is
     * {@link #REQUEST_TYPE}, then this contains the menu options that should be offered to the
     * cashier.
     */
    virtual std::vector<std::shared_ptr<MenuEntry>> getMenuEntries() const = 0;

    /**
     * Adds a menu entry to the list of entries.
     * Refer to {@link #getMenuEntries()} for more information.
     */
    virtual void addMenuEntry(const std::shared_ptr<MenuEntry> & menuEntry) = 0;

    /**
     * Sets all of the menu entries at once.
     * Refer to {@link #getMenuEntries()} for more information.
     */
    virtual void setMenuEntries(const std::vector<std::shared_ptr<MenuEntry>> & menuEntries) = 0;

    /**
     * Returns the content type, either {@link ContentType#HTML} or
     * {@link ContentType#TEXT}.
     */
    virtual ContentType getContentType() const = 0;

    /**
     * Sets the content type, either {@link ContentType#HTML} or
     * {@link ContentType#TEXT}.
     */
    virtual void setContentType(ContentType contentType) = 0;

    /**
     * Sets the content that should be displayed to the cashier according to the type. If
     * the type is {@link InputType#MENU_OPTIONS}, then this should be
     * displayed as a header above the menu options.
     */
    virtual void setContent(const std::optional<std::string> & content) = 0;

    /**
     * Returns the content that should be displayed to the cashier according to the type. If
     * the type is {@link InputType#MENU_OPTIONS}, then this should be
     * displayed as a header above the menu options.
     */
    virtual std::optional<std::string> getContent() const = 0;

    /**
     * Returns true if this event requires a response, otherwise this is false and everything
     * will continue without a response.
     */
    virtual bool isResponseRequired() const = 0;

    /** Refer to {@link #isResponseRequired()}. */
    virtual void setResponseRequired(bool responseRequired) = 0;

    /** Time limit in seconds to send the response, or 0 if unlimited. */
    virtual std::optional<int32_t> getMaximumInputTime() const = 0;

    /** Sets the Time limit in seconds to send the response. */
    virtual void setMaximumInputTime(std::optional<int32_t> maximumInputTime) = 0;

    /**
     * Returns true if setShouldRespondImmediately is set for an UserInputEvent.
     * {@link setShouldRespondImmediately}
     */
    virtual bool shouldRespondImmediately() const = 0;

    /** Sets shouldRespondImmediately for UserInputEvent. */
    virtual void setShouldRespondImmediately(bool shouldRespondImmediately) = 0;

    /**
     * Minimum length of an entered string, or minimum number of entries that can be selected
     * in a menu. Null if not specified. Lower or equal to MaxLength. InputCommand must be
     * {@link InputType#TEXT}, {@link InputType#NUMBER},
     * {@link InputType#DECIMAL},
     * {@link InputType#PASSWORD} or
     * {@link InputType#MENU_OPTIONS}.
     */
    virtual std::optional<int32_t> getMinimumLength() const = 0;

    /**
     * Sets the Minimum length of an entered string, or minimum number of entries that can be
     * selected in a menu. Refer to {@link #getMinimumLength()}.
     */
    virtual void setMinimumLength(std::optional<int32_t> minimumLength) = 0;

    /**
     * Maximum input length of the decimal part (without decimal point). Null if not specified.
     * Greater than MinLength, lower than MaxLength. Not allowed if InputCommand is not
     * {@link InputType#DECIMAL}.
     */
    virtual std::optional<int32_t> getMaximumLength() const = 0;

    /**
     * Sets the Maximum length of an entered string, or maximum number of entries that can be
     * selected in a menu.# Refer to {@link #getMaximumLength()}.
     */
    virtual void setMaximumLength(std::optional<int32_t> maximumLength) = 0;

    /**
     * Maximum length of an entered string, or maximum number of entries that can be selected
     * in a menu. Null if not specified. Greater or equal to MinLength. InputCommand must be
     * {@link InputType#TEXT}, {@link InputType#NUMBER},
     * {@link InputType#DECIMAL},
     * {@link InputType#PASSWORD} or
     * {@link InputType#MENU_OPTIONS}.
     */
    virtual std::optional<int32_t> getMaximumDecimalLength() const = 0;

    /** Refer to {@link #getMaximumDecimalLength()}. */
    virtual void setMaximumDecimalLength(std::optional<int32_t> maximumDecimalLength) = 0;

    /**
     * Indicates that the user must confirm the entered characters when the maximum allowed
     * length is reached. InputCommand must be {@link InputType#TEXT},
     * {@link InputType#NUMBER} or
     * {@link InputType#DECIMAL} with {@link #setMaximumLength(Integer)} or
     * {@link #setMaximumDecimalLength(Integer)}. Default False.
     */
    virtual bool shouldWaitForUserValidation() const = 0;

    /** Refer to {@link #shouldWaitForUserValidation()}. */
    virtual void setShouldWaitForUserValidation(bool wait) = 0;

    /**
     * String mask to get information according to a specific format. Supports symbols '\d' for
     * digits 0-9, '\w' for case insensitive letters (e.g. [a-zA-Z]), and '\.' for any
     * printable character. Any other characters should be preserved as-is. Example: Setting
     * the mask to "(\d\d\d) \d\d\d-\d\d\d\d" will collect a US-style phone number, where the
     * user will be prompted to input 9 digits, and the returned value will look like
     * "(626) 555-5555". InputCommand must be {@link InputType#TEXT},
     * {@link InputType#NUMBER},
     * {@link InputType#DECIMAL} or
     * {@link InputType#PASSWORD}.
     */
    virtual std::optional<std::string> getStringMask() const = 0;

    /** Refer to {@link #getStringMask()}. */
    virtual void setStringMask(const std::optional<std::string> & stringMask) = 0;

    /**
     * Indicates if the entered character has to be displayed from the right to the left of the
     * display field. Useful when entering amounts for a language that normally reads from left
     * to right. Not allowed if InputCommand is not {@link InputType#TEXT},
     * {@link InputType#NUMBER},
     * {@link InputType#DECIMAL} or
     * {@link InputType#PASSWORD}. Default False for locales that read
     * left-to-right, default True when the current locale reads right-to-left.
     */
    virtual bool isFromRightToLeft() const = 0;

    /** Refer to {@link #isFromRightToLeft()}. */
    virtual void setIsFromRightToLeft(bool fromRightToLeft) = 0;

    /**
     * Indicates that the entry should be masked with an '#' or similar character while being
     * entered. InputCommand must be {@link InputType#TEXT},
     * {@link InputType#NUMBER} or
     * {@link InputType#PASSWORD}. Default False.
     */
    virtual bool shouldMaskCharacters() const = 0;

    /** Refer to {@link #shouldMaskCharacters()}. */
    virtual void setShouldMaskCharacters(bool shouldMaskCharacters) = 0;

    /**
     * Returns a bitmap that is to be displayed below the content to the recipient of the
     * request. Generally used for confirming a customer's signature.
     */
    virtual std::shared_ptr<Image> getImage() const = 0;

    /** Refer to {@link #getImage()}. */
    virtual void setImage(const std::shared_ptr<Image> & image) = 0;
};

}  // namespace verifone_sdk
