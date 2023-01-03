// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from AccessibilityManager.djinni

#pragma once

#include <memory>
#include <psdk/export.h>

namespace verifone_sdk {

class AccessibilityModeStatus;

class PSDK_EXPORT AccessibilityListener {
public:
    virtual ~AccessibilityListener() {}

    /**
     * If the terminal has changed mode, create an event to update the control panel with the appropriate screen.
     * @param mode object that contains a compelte information of the accessibility mode 
     */
    virtual void handleEvent(const std::shared_ptr<AccessibilityModeStatus> & mode) = 0;
};

}  // namespace verifone_sdk
