// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from com_verifone_commerce_entities.djinni

#pragma once

#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace verifone_sdk {

enum class Roles;

/** Represents an employee. */
class Employee {
public:
    virtual ~Employee() {}

    static std::shared_ptr<Employee> create();

    /**
     * A unique, logical ID for the employee. This is consistent across devices,
     * and is separate from the internal _ID.
     */
    virtual std::optional<std::string> getRecordId() const = 0;

    /** The full name of the employee. */
    virtual std::optional<std::string> getName() const = 0;

    /**
     * The name for display or printing on the receipt.
     * This will generally be a shortened version of the full name.
     */
    virtual std::optional<std::string> getDisplayName() const = 0;

    /** The roles associated with this employee. */
    virtual std::vector<Roles> getRoles() const = 0;

    /** The timestamp of most recent login to this device */
    virtual std::optional<std::string> getLastLoggedInTime() const = 0;

    /**
     * The timestamp of most recent logout out of this device
     * This may have been due to inactivity or explicitly logging out.
     */
    virtual std::optional<std::string> getLastLoggedOutTime() const = 0;

    /**
     * The email address of the employee. This will return null if the employee does
     * not have an email address or if the requester does not have permission to read
     * the email address
     */
    virtual std::optional<std::string> getEmailAddress() const = 0;

    /**
     * The phone number of the employee. This will return null if the employee does
     * not have a phone number or if the requester does not have permission to read
     * the phone number.
     */
    virtual std::optional<std::string> getPhoneNumber() const = 0;

    /** Returns true if this employee is currently logged in. */
    virtual bool isCurrentEmployee() const = 0;

    /** Performs login */
    virtual bool login() = 0;

    /** Performs logout */
    virtual bool logout() = 0;
};

}  // namespace verifone_sdk
