// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from AccessibilityManager.djinni

#pragma once

#include <cstdint>
#include <optional>
#include <string>

namespace verifone_sdk {

class AccessibilityModeStatus {
public:
    virtual ~AccessibilityModeStatus() {}

    virtual int32_t getCode() = 0;

    virtual std::optional<std::string> getMessage() = 0;

    virtual bool isResponseMessage() = 0;

    virtual bool isNotificationMessage() = 0;

    virtual bool isAssistanceModeActive() = 0;

    virtual bool isAccessibilityModeActive() = 0;

    virtual bool isShortTrainingActive() = 0;

    virtual bool isExplorationTrainingActive() = 0;

    virtual bool isDoubleTapTrainingActive() = 0;

    virtual bool isEdgesTrainingActive() = 0;

    virtual bool isNavigationTrainingActive() = 0;

    virtual bool isSubmitDigitTrainingActive() = 0;

    virtual bool isEnterPinTrainingActive() = 0;

    virtual bool isVoiceActivationEnabled() = 0;

    virtual bool isColorSelectionActive() = 0;

    virtual bool isAssistanceModeAllowed() = 0;

    virtual bool isAccessibilityModeAllowed() = 0;

    virtual bool wasColorSelected() = 0;

    virtual std::optional<std::string> getSelectedColor() = 0;
};

}  // namespace verifone_sdk
