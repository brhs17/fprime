#include <Ref/MathTypes/MathOpSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/EightyCharString.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

MathOp::MathOp(void): Serializable() {

}

MathOp::MathOp(const MathOp& src) : Serializable() {
    this->set(src.m_val1, src.m_val2, src.m_op, src.m_result);
}

MathOp::MathOp(const MathOp* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_val1, src->m_val2, src->m_op, src->m_result);
}

MathOp::MathOp(F32 val1, F32 val2, Operation op, F32 result) : Serializable() {
    this->set(val1, val2, op, result);
}

const MathOp& MathOp::operator=(const MathOp& src) {
    this->set(src.m_val1, src.m_val2, src.m_op, src.m_result);
    return src;
}

bool MathOp::operator==(const MathOp& src) const {
    return (
        (src.m_val1 == this->m_val1) &&
        (src.m_val2 == this->m_val2) &&
        (src.m_op == this->m_op) &&
        (src.m_result == this->m_result) &&
        true);
}

void MathOp::set(F32 val1, F32 val2, Operation op, F32 result) {
    this->m_val1 = val1;
    this->m_val2 = val2;
    this->m_op = op;
    this->m_result = result;
}

F32 MathOp::getval1(void) {
    return this->m_val1;
}

F32 MathOp::getval2(void) {
    return this->m_val2;
}

Operation MathOp::getop(void) {
    return this->m_op;
}

F32 MathOp::getresult(void) {
    return this->m_result;
}

void MathOp::setval1(F32 val) {
    this->m_val1 = val;
}
void MathOp::setval2(F32 val) {
    this->m_val2 = val;
}
void MathOp::setop(Operation val) {
    this->m_op = val;
}
void MathOp::setresult(F32 val) {
    this->m_result = val;
}
Fw::SerializeStatus MathOp::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID    
    // serialize type ID
    stat = buffer.serialize((U32)MathOp::TYPE_ID);
#endif    

    stat = buffer.serialize(this->m_val1);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_val2);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize((FwEnumStoreType)this->m_op);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_result);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus MathOp::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID    
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != MathOp::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif    

    stat = buffer.deserialize(this->m_val1);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_val2);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    FwEnumStoreType intop;
    stat = buffer.deserialize(intop);
    this->m_op = static_cast<Operation>(intop);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.deserialize(this->m_result);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

#if FW_SERIALIZABLE_TO_STRING  || BUILD_UT

void MathOp::toString(Fw::StringBase& text) const {
    
    static const char * formatString = 
       "("
       "val1 = %g, "
       "val2 = %g, "
       "op = %d, "
       "result = %g"
       ")";
       
    // declare strings to hold any serializable toString() arguments

       
    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_val1
       ,this->m_val2
       ,this->m_op
       ,this->m_result
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
    
    text = outputString;           
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const MathOp& obj) {
        Fw::EightyCharString str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
