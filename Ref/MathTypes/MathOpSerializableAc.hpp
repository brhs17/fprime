/*
 * MathOp.hpp
 *
 *  Created on: Wednesday, 06 March 2019
 *  Author:     bhs
 *
 */
#ifndef MATHOP_HPP_
#define MATHOP_HPP_

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
        ADD,
        SUB,
        MULT,
        DIVIDE,
        Operation_MAX
    } Operation;

class MathOp : public Fw::Serializable {


public:

    enum {
        SERIALIZED_SIZE =
        sizeof(F32) +
        sizeof(F32) +
        sizeof(FwEnumStoreType) +                
        sizeof(F32)
    }; //!< serializable size of MathOp

    MathOp(void); //!< Default constructor
    MathOp(const MathOp* src); //!< pointer copy constructor
    MathOp(const MathOp& src); //!< reference copy constructor
    MathOp(F32 val1, F32 val2, Operation op, F32 result); //!< constructor with arguments
    const MathOp& operator=(const MathOp& src); //!< equal operator
    bool operator==(const MathOp& src) const; //!< equality operator
#ifdef BUILD_UT
    // to support GoogleTest framework in unit tests
    friend std::ostream& operator<<(std::ostream& os, const MathOp& obj);
#endif

    void set(F32 val1, F32 val2, Operation op, F32 result); //!< set values
    
    F32 getval1(void); //!< get member val1
    F32 getval2(void); //!< get member val2
    Operation getop(void); //!< get member op
    F32 getresult(void); //!< get member result

    void setval1(F32 val); //!< set member val1
    void setval2(F32 val); //!< set member val2
    void setop(Operation val); //!< set member op
    void setresult(F32 val); //!< set member result


    Fw::SerializeStatus serialize(Fw::SerializeBufferBase& buffer) const; //!< serialization function
    Fw::SerializeStatus deserialize(Fw::SerializeBufferBase& buffer); //!< deserialization function
#if FW_SERIALIZABLE_TO_STRING || BUILD_UT
    void toString(Fw::StringBase& text) const; //!< generate text from serializable
#endif
protected:

    enum {
        TYPE_ID = 0x6E862295 //!< type id
    };

    F32 m_val1; //<! val1 - 
    F32 m_val2; //<! val2 - 
    Operation m_op; //<! op - 
    F32 m_result; //<! result - 
private:

};
} // end namespace Ref
#endif /* MATHOP_HPP_ */

