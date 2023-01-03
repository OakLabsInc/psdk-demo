// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from DeviceManagementCommand.djinni

#pragma once

#include "DeviceManagementAction.hpp"
#include <optional>
#include <psdk/export.h>
#include <string>
#include <unordered_map>
#include <utility>

namespace verifone_sdk {

/** Device Management Command with associated parameters */
struct PSDK_EXPORT DeviceManagementCommand final {
    DeviceManagementAction deviceManagementAction;
    std::optional<std::unordered_map<std::string, std::string>> params;

    DeviceManagementCommand(DeviceManagementAction deviceManagementAction_,
                            std::optional<std::unordered_map<std::string, std::string>> params_)
    : deviceManagementAction(std::move(deviceManagementAction_))
    , params(std::move(params_))
    {}
};

}  // namespace verifone_sdk
