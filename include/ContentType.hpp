// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_payment.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class ContentType : int {
    /**
     * HTML format of the display/message content, used when sending 
     * content to be displayed to the customer or handling requests to 
     * display or get input from the cashier.
     */
    HTML,
    /**
     * Simple text format of the display/message content, used when sending 
     * content to be displayed to the customer or handling requests to 
     * display or get input from the cashier.
     */
    TEXT,
    /**MAX_COUNT */
    MAX_COUNT,
};

constexpr std::string_view toString(const ContentType& arg) {
    switch(arg) {
        case ContentType::HTML: return "HTML";
        case ContentType::TEXT: return "TEXT";
        case ContentType::MAX_COUNT: return "MAX_COUNT";
        default: return "ContentType enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::ContentType> {
    size_t operator()(::verifone_sdk::ContentType type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
