#include <Fw/Cfg/Config.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Types/Serializable.hpp>

#include <Ref/MathPorts/MathOpPortAc.hpp>
namespace Ref {


    namespace {

        class MathOpPortBuffer : public Fw::SerializeBufferBase {

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

            U8 m_buff[InputMathOpPort::SERIALIZED_SIZE];

        };

    }
    InputMathOpPort::InputMathOpPort(void) : 
        Fw::InputPortBase(), 
        m_func(0) {
    }
    
    void InputMathOpPort::init(void) {
        Fw::InputPortBase::init();
    }

    void InputMathOpPort::addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr) {
        FW_ASSERT(callComp);
        FW_ASSERT(funcPtr);

        this->m_comp = callComp;
        this->m_func = funcPtr;
        this->m_connObj = callComp;
    }

    // call virtual logging function for component
    void InputMathOpPort::invoke(F32 val1, F32 val2, MathOperation operation) {

#if FW_PORT_TRACING == 1        
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);
        this->m_func(this->m_comp, this->m_portNum, val1, val2, operation);
    }

#if FW_PORT_SERIALIZATION == 1    
    void InputMathOpPort::invokeSerial(Fw::SerializeBufferBase &buffer) {
        Fw::SerializeStatus _status;
#if FW_PORT_TRACING == 1
        this->trace();
#endif
        FW_ASSERT(this->m_comp);
        FW_ASSERT(this->m_func);


        F32 val1;
        _status = buffer.deserialize(val1);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));

        F32 val2;
        _status = buffer.deserialize(val2);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
        FwEnumStoreType operation_val;
        _status = buffer.deserialize(operation_val);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == _status,static_cast<AssertArg>(_status));
        MathOperation operation = static_cast<MathOperation>(operation_val);

        this->m_func(this->m_comp, this->m_portNum, val1, val2, operation);
    }
#endif

OutputMathOpPort::OutputMathOpPort(void) :
            Fw::OutputPortBase(),
    m_port(0) {
}

void OutputMathOpPort::init(void) {
    Fw::OutputPortBase::init();
}

void OutputMathOpPort::addCallPort(InputMathOpPort* callPort) {
    FW_ASSERT(callPort);
    
    this->m_port = callPort;
    this->m_connObj = callPort;
#if FW_PORT_SERIALIZATION == 1
    this->m_serPort = 0;
#endif
}

void OutputMathOpPort::invoke(F32 val1, F32 val2, MathOperation operation) {
#if FW_PORT_TRACING == 1
    this->trace();
#endif

#if FW_PORT_SERIALIZATION            
    FW_ASSERT(this->m_port||this->m_serPort);
#else
    FW_ASSERT(this->m_port);
#endif

    if (this->m_port) {
        this->m_port->invoke(val1, val2, operation);
#if FW_PORT_SERIALIZATION            
    } else if (this->m_serPort) {
        Fw::SerializeStatus status;
        MathOpPortBuffer _buffer;
        status = _buffer.serialize(val1);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(val2);
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        status = _buffer.serialize(static_cast<NATIVE_INT_TYPE>(operation));
        FW_ASSERT(Fw::FW_SERIALIZE_OK == status,static_cast<AssertArg>(status));

        this->m_serPort->invokeSerial(_buffer);
    }
#else
    }    
#endif

} // end OutputMathOpPort::invoke(...)

} // end namespace Ref
