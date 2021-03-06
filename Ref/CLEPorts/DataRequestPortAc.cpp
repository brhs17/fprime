#include <Fw/Cfg/Config.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>

#include <Ref/CLEPorts/DataRequestPortAc.hpp>
namespace Ref {


    namespace {

        class DataRequestPortBuffer : public Fw::SerializeBufferBase {

            public:
                NATIVE_UINT_TYPE getBuffCapacity(void) const {
                    return sizeof(m_buff);
                }

                U8* getBuffAddr(void) {
                    return m_buff;
                }

                const U8* getBuffAddr(void) const {
                    return m_buff;
                }

        private:

            U8 m_buff[InputDataRequestPort::SERIALIZED_SIZE];

        };

    }
    InputDataRequestPort::InputDataRequestPort(void) : 
        Fw::InputPortBase(), 
        m_func(0) {
    }
    
    void InputDataRequestPort::init(void) {
        Fw::InputPortBase::init();
    }

    void InputDataRequestPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputDataRequestPort::invoke(DataRequestPortZ data) {

#if FW_PORT_TRACING == 1        
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, data);
    }

#if FW_PORT_SERIALIZATION == 1    
    void InputDataRequestPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);

        FwEnumStoreType data_val;
        _status = buffer.deserialize(data_val);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
        DataRequestPortZ data = static_cast<DataRequestPortZ>(data_val);

        this->m_func(this->m_comp, this->m_portNum, data);
    }
#endif

OutputDataRequestPort::OutputDataRequestPort(void) :
            Fw::OutputPortBase(),
    m_port(0) {
}

void OutputDataRequestPort::init(void) {
    Fw::OutputPortBase::init();
}

void OutputDataRequestPort::addCallPort(InputDataRequestPort* callPort) {
    FW_ASSERT(callPort);
    
    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = 0;
#endif
}

void OutputDataRequestPort::invoke(DataRequestPortZ data) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION            
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(data);
#if FW_PORT_SERIALIZATION            
    } else if (this->m_serPort) {
        Fw::SerializeStatus status;
        DataRequestPortBuffer _buffer;
        status = _buffer.serialize(static_cast<NATIVE_INT_TYPE>(data));
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        this->m_serPort->invokeSerial(_buffer);
    }
#else
    }    
#endif

} // end OutputDataRequestPort::invoke(...)

} // end namespace Ref
