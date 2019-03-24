#include <Ref/CLETypes/CLERequestSerializableAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/BasicTypes.hpp>
#if FW_SERIALIZABLE_TO_STRING
#include <Fw/Types/EightyCharString.hpp>
#endif
#include <cstring>
namespace Ref {
// public methods

DataRequest::DataRequest(void): Serializable() {

}

DataRequest::DataRequest(const DataRequest& src) : Serializable() {
    this->set(src.m_target, src.m_result);
}

DataRequest::DataRequest(const DataRequest* src) : Serializable() {
    FW_ASSERT(src);
    this->set(src->m_target, src->m_result);
}

DataRequest::DataRequest(type target, F32 result) : Serializable() {
    this->set(target, result);
}

const DataRequest& DataRequest::operator=(const DataRequest& src) {
    this->set(src.m_target, src.m_result);
    return src;
}

bool DataRequest::operator==(const DataRequest& src) const {
    return (
        (src.m_target == this->m_target) &&
        (src.m_result == this->m_result) &&
        true);
}

void DataRequest::set(type target, F32 result) {
    this->m_target = target;
    this->m_result = result;
}

type DataRequest::gettarget(void) {
    return this->m_target;
}

F32 DataRequest::getresult(void) {
    return this->m_result;
}

void DataRequest::settarget(type val) {
    this->m_target = val;
}
void DataRequest::setresult(F32 val) {
    this->m_result = val;
}
Fw::SerializeStatus DataRequest::serialize(Fw::SerializeBufferBase& buffer) const {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID    
    // serialize type ID
    stat = buffer.serialize((U32)DataRequest::TYPE_ID);
#endif    

    stat = buffer.serialize((FwEnumStoreType)this->m_target);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    stat = buffer.serialize(this->m_result);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }
    return stat;
}

Fw::SerializeStatus DataRequest::deserialize(Fw::SerializeBufferBase& buffer) {
    Fw::SerializeStatus stat;

#if FW_SERIALIZATION_TYPE_ID    
    U32 typeId;

    stat = buffer.deserialize(typeId);
    if (stat != Fw::FW_SERIALIZE_OK) {
        return stat;
    }

    if (typeId != DataRequest::TYPE_ID) {
        return Fw::FW_DESERIALIZE_TYPE_MISMATCH;
    }
#endif    

    FwEnumStoreType inttarget;
    stat = buffer.deserialize(inttarget);
    this->m_target = static_cast<type>(inttarget);
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

void DataRequest::toString(Fw::StringBase& text) const {
    
    static const char * formatString = 
       "("
       "target = %d, "
       "result = %g"
       ")";
       
    // declare strings to hold any serializable toString() arguments

       
    char outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE];
    (void)snprintf(outputString,FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE,formatString
       ,this->m_target
       ,this->m_result
    );
    outputString[FW_SERIALIZABLE_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
    
    text = outputString;           
}

#endif

#ifdef BUILD_UT
    std::ostream& operator<<(std::ostream& os, const DataRequest& obj) {
        Fw::EightyCharString str;
        obj.toString(str);
        os << str.toChar();
        return os;
    }
#endif
} // end namespace Ref
