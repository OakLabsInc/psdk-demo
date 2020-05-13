// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from SdiTlv.djinni

#pragma once

#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace verifone_sdk {

/** Class for handling X690 BER TLV encoding */
class SdiTlv {
public:
    virtual ~SdiTlv() {}

    /** Creates an empty SdiTlv object */
    static std::shared_ptr<SdiTlv> create();

    /**
     * Determine the number of tags matching tagId
     *
     * param tagId tag ID as number
     * return number of tags
     */
    virtual int32_t count(int32_t tagId) = 0;

    /**
     * Obtain tag having tag value tagId. If the tag is not found, it is created.
     *
     * param tagId tag ID as number
     * return reference to tag object
     */
    virtual std::shared_ptr<SdiTlv> obtain(int32_t tagId) = 0;

    /**
     * Obtain index-th tag having tag value tagId. If the tag is not found, it is created.
     *
     * param tagId tag ID as number
     * param index index of tag
     * return reference to tag object
     */
    virtual std::shared_ptr<SdiTlv> obtainIndex(int32_t tagId, int32_t index) = 0;

    /**
     * Assign string value
     *
     * param string to assign
     */
    virtual void assignString(const std::string & data) = 0;

    /**
     * Assign int value
     *
     * param int to assign
     */
    virtual void assignInt(int32_t data) = 0;

    /**
     * Assign byte array value
     *
     * param byte array to assign
     */
    virtual void assignBinary(const std::vector<uint8_t> & data) = 0;

    /** Return value of primitive tag as a string */
    virtual std::string getString() = 0;

    /** Return value of primitive tag as a number */
    virtual int32_t getNumber() = 0;

    /**
     * Load binary TLV buffer into internal representation
     *
     * param data buffer containing TLV data
     * param indefinite if true stop loading at terminating tag (00 00).
     */
    virtual bool load(const std::vector<uint8_t> & data, bool indefinite) = 0;

    /**
     * Store internal representation to binary TLV buffer
     *
     * param use_indefinite if true use indefinite length form, else use definite form
     * return data output buffer
     */
    virtual std::vector<uint8_t> store(bool use_indefinite) = 0;
};

}  // namespace verifone_sdk
