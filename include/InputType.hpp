// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class InputType : int {
    /**
     * This is input type const for 
     * {@link #requestUserInput(InputType, String, String)} method.
     */
    SIGNATURE,
    /**
     * This is input type const for 
     * {@link #requestUserInput(InputType, String, String)} method.
     */
    EMAIL,
    /**
     * This is input type const for 
     * {@link #requestUserInput(InputType, String, String)} method.
     */
    NUMBER,
    /**
     * This is input type const for 
     * {@link #requestUserInput(InputType, String, String)} method.
     */
    DECIMAL,
    /**
     * This is input type const for 
     * {@link #requestUserInput(InputType, String, String)} method.
     */
    TEXT,
    /**
     * This is input type const for 
     * {@link #requestUserInput(InputType, String, String)} method.
     */
    PASSWORD,
    /**
     * This is input type const for 
     * {@link #requestUserInput(InputType, String, String)} method.
     */
    CONFIRMATION,
    /**
     * This is input type const for 
     * {@link #requestUserInput(InputType, String, String)} method.
     */
    MANAGER_APPROVAL,
    /**
     * Input type requiring any key to proceed. Used for
     * {@link #requestUserInput(InputType, String, String)}.
     */
    ANY_KEY,
    /**
     * Input type to present multiple options in a menu. Used for
     * {@link #requestUserInput(InputType, String, String)}.     
     */
    MENU_OPTIONS,
    /** MAX_COUNT */
    MAX_COUNT,
};

constexpr std::string_view toString(const InputType& arg) {
    switch(arg) {
        case InputType::SIGNATURE: return "SIGNATURE";
        case InputType::EMAIL: return "EMAIL";
        case InputType::NUMBER: return "NUMBER";
        case InputType::DECIMAL: return "DECIMAL";
        case InputType::TEXT: return "TEXT";
        case InputType::PASSWORD: return "PASSWORD";
        case InputType::CONFIRMATION: return "CONFIRMATION";
        case InputType::MANAGER_APPROVAL: return "MANAGER_APPROVAL";
        case InputType::ANY_KEY: return "ANY_KEY";
        case InputType::MENU_OPTIONS: return "MENU_OPTIONS";
        case InputType::MAX_COUNT: return "MAX_COUNT";
        default: return "InputType enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::InputType> {
    size_t operator()(::verifone_sdk::InputType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
