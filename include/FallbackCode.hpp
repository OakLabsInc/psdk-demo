// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_host_adapter.djinni

#pragma once

#include <functional>
#include <string>

namespace verifone_sdk {

enum class FallbackCode : int {
    /** ICC read failed using mag strip instead */
    ICC_TO_MAG_STRIPE,
    /** ICC Contactless read failed using mag strip instead */
    ICC_CONTACTLESS_TO_MAG_STRIPE,
    /** ICC Contactless read failed using manual entry instead */
    ICC_CONTACTLESS_TO_MANUAL,
    /** ICC read failed using manual entry instead */
    ICC_TO_MANUAL,
    /** Mag stripe read failed using manual instead */
    MAG_STRIPE_TO_MANUAL,
    /** Mag stripe read failed using ICC */
    MAG_STRIPE_TO_ICC,
};

constexpr std::string_view toString(const FallbackCode& arg) {
    switch(arg) {
        case FallbackCode::ICC_TO_MAG_STRIPE: return "ICC_TO_MAG_STRIPE";
        case FallbackCode::ICC_CONTACTLESS_TO_MAG_STRIPE: return "ICC_CONTACTLESS_TO_MAG_STRIPE";
        case FallbackCode::ICC_CONTACTLESS_TO_MANUAL: return "ICC_CONTACTLESS_TO_MANUAL";
        case FallbackCode::ICC_TO_MANUAL: return "ICC_TO_MANUAL";
        case FallbackCode::MAG_STRIPE_TO_MANUAL: return "MAG_STRIPE_TO_MANUAL";
        case FallbackCode::MAG_STRIPE_TO_ICC: return "MAG_STRIPE_TO_ICC";
        default: return "FallbackCode enum value not supported";
    }
}

}  // namespace verifone_sdk

namespace std {

template <>
struct hash<::verifone_sdk::FallbackCode> {
    size_t operator()(::verifone_sdk::FallbackCode type) const {
        return std::hash<int>()(static_cast<int>(type));
    }
};

}  // namespace std
