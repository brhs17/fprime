/*
 * DataRequestPort.hpp
 *
 *  Created on: Wednesday, 27 March 2019
 *  Author:     bhs
 *
 */
#ifndef DATAREQUESTPORT_HPP_
#define DATAREQUESTPORT_HPP_

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

    typedef enum {
        OPS_GyroX,
        OPS_GyroY,
        OPS_GyroZ,
        OPS_RTCTime,
        DataRequestPortZ_MAX
    } DataRequestPortZ; //!< DataRequestPortZ enumeration argument

    /// Input DataRequest port description
    /// 

    class InputDataRequestPort : public Fw::InputPortBase  {
    public:
        enum {
            SERIALIZED_SIZE = sizeof(NATIVE_INT_TYPE) //!< serialized size of port arguments
        };
        typedef void (*CompFuncPtr)(Fw::PassiveComponentBase* callComp, NATIVE_INT_TYPE portNum, DataRequestPortZ data); //!< port callback definition

        InputDataRequestPort(void); //!< constructor
        void init(void); //!< initialization function
        void addCallComp(Fw::PassiveComponentBase* callComp, CompFuncPtr funcPtr); //!< call to register a component
        void invoke(DataRequestPortZ data); //!< invoke port interface
    protected:
    private:
        CompFuncPtr m_func; //!< pointer to port callback function
#if FW_PORT_SERIALIZATION == 1        
        void invokeSerial(Fw::SerializeBufferBase &buffer); //!< invoke the port with serialized arguments
#endif
};
    /// Input DataRequest port description
    /// 
    
    class OutputDataRequestPort : public Fw::OutputPortBase {
      public: 
        OutputDataRequestPort(void);
        void init(void);
        void addCallPort(InputDataRequestPort* callPort);
        void invoke(DataRequestPortZ data);
      protected:
      private:
        InputDataRequestPort* m_port;
    };
} // end namespace Ref
#endif /* DATAREQUEST_HPP_ */

