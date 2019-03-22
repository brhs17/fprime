/*
 * DataRequest.hpp
 *
 *  Created on: Thursday, 21 March 2019
 *  Author:     bhs
 *
 */
#ifndef DATAREQUEST_HPP_
#define DATAREQUEST_HPP_

#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/StringType.hpp>
#include <stdio.h> // snprintf
#ifdef BUILD_UT
#include <iostream>
#include <Fw/Types/EightyCharString.hpp>
#endif
#endif

namespace Ref {

    typedef enum {
        GyroX,
        GyroY,
        GyroZ,
        RTCTime,
        type_MAX
    } type;

class DataRequest : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(FwEnumStoreType) +                
        sizeof(F32)
    }; //!< serializable size of DataRequest

    DataRequest(void); //!< Default constructor
    DataRequest(const DataRequest* src); //!< pointer copy constructor
    DataRequest(const DataRequest& src); //!< reference copy constructor
    DataRequest(type target, F32 result); //!< constructor with arguments
    const DataRequest& operator=(const DataRequest& src); //!< equal operator
    bool operator==(const DataRequest& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const DataRequest& obj);
#endif

    void set(type target, F32 result); //!< set values
    
    type gettarget(void); //!< get member target
    F32 getresult(void); //!< get member result

    void settarget(type val); //!< set member target
    void setresult(F32 val); //!< set member result


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0xC2351F67 //!< type id
    };

    type m_target; //<! target - 
    F32 m_result; //<! result - 
private:

};
} // end namespace Ref
#endif /* DATAREQUEST_HPP_ */

