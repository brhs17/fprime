/*
 * MathResultPort.hpp
 *
 *  Created on: Wednesday, 06 March 2019
 *  Author:     bhs
 *
 */
#ifndef MATHRESULTPORT_HPP_
#define MATHRESULTPORT_HPP_

#include <cstring>
#include <cstdio>
#include <Fw/Cfg/Config.hpp>
#include <Fw/Port/InputPortBase.hpp>
#include <Fw/Port/OutputPortBase.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Serializable.hpp>
#include <Fw/Types/StringType.hpp>


namespace Ref {

    /// Input MathResult port description
    /// 

    class InputMathResultPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(F32) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, F32 result); //!< port callback definition

        InputMathResultPort(void); //!< constructor
        void init(void); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(F32 result); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        void invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Input MathResult port description
    /// 
    
    class OutputMathResultPort : public Fw::OutputPortBase {
      public: 
        OutputMathResultPort(void);
        void init(void);
        void addCallPort(InputMathResultPort* callPort);
        void invoke(F32 result);
      protected:
      private:
        InputMathResultPort* m_port;
    };
} // end namespace Ref
#endif /* MATHRESULT_HPP_ */

