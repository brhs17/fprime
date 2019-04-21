// ====================================================================== 
// \title  CLEAggComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for CLEAgg component base class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the Office
// of Technology Transfer at the California Institute of Technology.
// 
// This software may be subject to U.S. export control laws and
// regulations.  By accepting this document, the user agrees to comply
// with all U.S. export laws and regulations.  User has the
// responsibility to obtain export licenses, or other export authority
// as may be required before exporting such information to foreign
// countries or providing access to foreign persons.
// ====================================================================== 

#ifndef CLEAGG_COMP_HPP_
#define CLEAGG_COMP_HPP_

#include <Fw/Cfg/Config.hpp>
#include <Fw/Port/InputSerializePort.hpp>
#include <Fw/Port/OutputSerializePort.hpp>
#include <Fw/Comp/ActiveComponentBase.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Tlm/TlmString.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogString.hpp>
#include <Fw/Cmd/CmdArgBuffer.hpp>
#include <Fw/Tlm/TlmBuffer.hpp>
#include <Fw/Time/Time.hpp>
#include <Fw/Log/LogBuffer.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Ref/CLEPorts/DataRequestPortAc.hpp>
#include <Ref/CLEPorts/DataResultPortAc.hpp>
#include <Svc/Sched/SchedPortAc.hpp>
#include <Fw/Cmd/CmdPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Cmd/CmdRegPortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif
#include <Ref/CLETypes/CLERequestSerializableAc.hpp>

namespace Ref {

  //! \class CLEAggComponentBase
  //! \brief Auto-generated base for CLEAgg component
  //!
  class CLEAggComponentBase :
    public Fw::QueuedComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class CLEAggComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return RequestIn[portNum]
    //!
    Ref::InputDataRequestPort* get_RequestIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return SchedIn[portNum]
    //!
    Svc::InputSchedPort* get_SchedIn_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Get input port at index
    //!
    //! \return CmdDisp[portNum]
    //!
    Fw::InputCmdPort* get_CmdDisp_InputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

  public:

    // ----------------------------------------------------------------------
    // Connect typed input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to ResponseOut[portNum]
    //!
    void set_ResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::InputDataResultPort *port /*!< The port*/
    );

    //! Connect port to CmdStatus[portNum]
    //!
    void set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdResponsePort *port /*!< The port*/
    );

    //! Connect port to CmdReg[portNum]
    //!
    void set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputCmdRegPort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTlmPort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputTimePort *port /*!< The port*/
    );

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogPort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputLogTextPort *port /*!< The port*/
    );
#endif

#if FW_PORT_SERIALIZATION

  public:

    // ----------------------------------------------------------------------
    // Connect serialization input ports to typed output ports
    // ----------------------------------------------------------------------

    //! Connect port to ResponseOut[portNum]
    //!
    void set_ResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to CmdStatus[portNum]
    //!
    void set_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to CmdReg[portNum]
    //!
    void set_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Tlm[portNum]
    //!
    void set_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Time[portNum]
    //!
    void set_Time_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

    //! Connect port to Log[portNum]
    //!
    void set_Log_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Connect port to LogText[portNum]
    //!
    void set_LogText_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Fw::InputSerializePort *port /*!< The port*/
    );
#endif

#endif

  public:

    // ----------------------------------------------------------------------
    // Command registration
    // ----------------------------------------------------------------------

    //! \brief Register commands with the Command Dispatcher
    //!
    //! Connect the dispatcher first
    //!
    void regCommands(void);

  PROTECTED:

    // ----------------------------------------------------------------------
    // Component construction, initialization, and destruction
    // ----------------------------------------------------------------------

#if FW_OBJECT_NAMES == 1
    //! Construct a CLEAggComponentBase object
    //!
    CLEAggComponentBase(
        const char* compName /*!< Component name*/
    );
#else
    //! Construct a CLEAggComponentBase object
    //!
    CLEAggComponentBase(void);
#endif

    //! Initialize a CLEAggComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a CLEAggComponentBase object
    //!
    virtual ~CLEAggComponentBase(void);

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port RequestIn
    //
    virtual void RequestIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        DataRequestPortZ data /*!< Possible data types to be requested*/
    ) = 0;

    //! Handler for input port SchedIn
    //
    virtual void SchedIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port RequestIn
    //!
    void RequestIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        DataRequestPortZ data /*!< Possible data types to be requested*/
    );

    //! Handler base-class function for input port SchedIn
    //!
    void SchedIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for typed async input ports.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port RequestIn
    //!
    virtual void RequestIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        DataRequestPortZ data /*!< Possible data types to be requested*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port ResponseOut
    //!
    void ResponseOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        F32 result 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of RequestIn input ports
    //!
    //! \return The number of RequestIn input ports
    //!
    NATIVE_INT_TYPE getNum_RequestIn_InputPorts(void);

    //! Get the number of SchedIn input ports
    //!
    //! \return The number of SchedIn input ports
    //!
    NATIVE_INT_TYPE getNum_SchedIn_InputPorts(void);

    //! Get the number of CmdDisp input ports
    //!
    //! \return The number of CmdDisp input ports
    //!
    NATIVE_INT_TYPE getNum_CmdDisp_InputPorts(void);

  
    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------
    
    enum {
       NUM_REQUESTIN_INPUT_PORTS = 1,
       NUM_SCHEDIN_INPUT_PORTS = 1,
       NUM_CMDDISP_INPUT_PORTS = 1,
    };
  
  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of ResponseOut output ports
    //!
    //! \return The number of ResponseOut output ports
    //!
    NATIVE_INT_TYPE getNum_ResponseOut_OutputPorts(void);

    //! Get the number of CmdStatus output ports
    //!
    //! \return The number of CmdStatus output ports
    //!
    NATIVE_INT_TYPE getNum_CmdStatus_OutputPorts(void);

    //! Get the number of CmdReg output ports
    //!
    //! \return The number of CmdReg output ports
    //!
    NATIVE_INT_TYPE getNum_CmdReg_OutputPorts(void);

    //! Get the number of Tlm output ports
    //!
    //! \return The number of Tlm output ports
    //!
    NATIVE_INT_TYPE getNum_Tlm_OutputPorts(void);

    //! Get the number of Time output ports
    //!
    //! \return The number of Time output ports
    //!
    NATIVE_INT_TYPE getNum_Time_OutputPorts(void);

    //! Get the number of Log output ports
    //!
    //! \return The number of Log output ports
    //!
    NATIVE_INT_TYPE getNum_Log_OutputPorts(void);

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Get the number of LogText output ports
    //!
    //! \return The number of LogText output ports
    //!
    NATIVE_INT_TYPE getNum_LogText_OutputPorts(void);
#endif

  
    enum {
       NUM_RESPONSEOUT_OUTPUT_PORTS = 1,
       NUM_CMDSTATUS_OUTPUT_PORTS = 1,
       NUM_CMDREG_OUTPUT_PORTS = 1,
       NUM_TLM_OUTPUT_PORTS = 1,
       NUM_TIME_OUTPUT_PORTS = 1,
       NUM_LOG_OUTPUT_PORTS = 1,
       NUM_LOGTEXT_OUTPUT_PORTS = 1,
    };
  
  PROTECTED:

    // ----------------------------------------------------------------------
    // Connection status queries for output ports
    // ----------------------------------------------------------------------

    //! Check whether port ResponseOut is connected
    //!
    //! \return Whether port ResponseOut is connected
    //!
    bool isConnected_ResponseOut_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port CmdStatus is connected
    //!
    //! \return Whether port CmdStatus is connected
    //!
    bool isConnected_CmdStatus_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port CmdReg is connected
    //!
    //! \return Whether port CmdReg is connected
    //!
    bool isConnected_CmdReg_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Tlm is connected
    //!
    //! \return Whether port Tlm is connected
    //!
    bool isConnected_Tlm_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Time is connected
    //!
    //! \return Whether port Time is connected
    //!
    bool isConnected_Time_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

    //! Check whether port Log is connected
    //!
    //! \return Whether port Log is connected
    //!
    bool isConnected_Log_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Check whether port LogText is connected
    //!
    //! \return Whether port LogText is connected
    //!
    bool isConnected_LogText_OutputPort(
        NATIVE_INT_TYPE portNum /*!< The port number*/
    );
#endif

  PROTECTED:

    // ----------------------------------------------------------------------
    // Message dispatch
    // ----------------------------------------------------------------------

    //! Dispatch a message on the queue
    //!
    virtual MsgDispatchStatus doDispatch(void);

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command opcodes
    // ----------------------------------------------------------------------

    enum {
      OPCODE_CLEAGG_SET_GYROX = 100, /*  */
      OPCODE_CLEAGG_SET_GYROY = 101, /*  */
      OPCODE_CLEAGG_SET_GYROZ = 102, /*  */
      OPCODE_CLEAGG_SET_RTC_TIME = 103, /*  */
      OPCODE_CLEAGG_CLEAR_EVENT_THROTTLE = 104, /*  */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command CLEAgg_SET_GYROX
    /*  */
    virtual void CLEAgg_SET_GYROX_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        F32 val 
    ) = 0;

    //! Handler for command CLEAgg_SET_GYROY
    /*  */
    virtual void CLEAgg_SET_GYROY_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        F32 val 
    ) = 0;

    //! Handler for command CLEAgg_SET_GYROZ
    /*  */
    virtual void CLEAgg_SET_GYROZ_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        F32 val 
    ) = 0;

    //! Handler for command CLEAgg_SET_RTC_TIME
    /*  */
    virtual void CLEAgg_SET_RTC_TIME_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        F32 val 
    ) = 0;

    //! Handler for command CLEAgg_CLEAR_EVENT_THROTTLE
    /*  */
    virtual void CLEAgg_CLEAR_EVENT_THROTTLE_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for async commands.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing the
    // corresponding command. By default they do nothing. You can
    // override them to provide specific pre-command behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for command CLEAgg_SET_GYROX
    //!
    virtual void CLEAgg_SET_GYROX_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CLEAgg_SET_GYROY
    //!
    virtual void CLEAgg_SET_GYROY_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CLEAgg_SET_GYROZ
    //!
    virtual void CLEAgg_SET_GYROZ_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CLEAgg_SET_RTC_TIME
    //!
    virtual void CLEAgg_SET_RTC_TIME_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

    //! Pre-message hook for command CLEAgg_CLEAR_EVENT_THROTTLE
    //!
    virtual void CLEAgg_CLEAR_EVENT_THROTTLE_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions.
    // Call these functions directly to bypass the command input port.
    // ----------------------------------------------------------------------

    //! Base-class handler function for command CLEAgg_SET_GYROX
    //! 
    void CLEAgg_SET_GYROX_cmdHandlerBase( 
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CLEAgg_SET_GYROY
    //! 
    void CLEAgg_SET_GYROY_cmdHandlerBase( 
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CLEAgg_SET_GYROZ
    //! 
    void CLEAgg_SET_GYROZ_cmdHandlerBase( 
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CLEAgg_SET_RTC_TIME
    //! 
    void CLEAgg_SET_RTC_TIME_cmdHandlerBase( 
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

    //! Base-class handler function for command CLEAgg_CLEAR_EVENT_THROTTLE
    //! 
    void CLEAgg_CLEAR_EVENT_THROTTLE_cmdHandlerBase( 
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CmdArgBuffer &args /*!< The command argument buffer*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command response
    // ----------------------------------------------------------------------

    //! Emit command response
    //!
    void cmdResponse_out(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        Fw::CommandResponse response /*!< The command response*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event IDs
    // ----------------------------------------------------------------------

    enum {
      EVENTID_CLEAGG_SET_GYROX = 100, /*  */
      EVENTID_CLEAGG_SET_GYROY = 101, /*  */
      EVENTID_CLEAGG_SET_GYROZ = 102, /*  */
      EVENTID_CLEAGG_SET_RTC_TIME = 103, /*  */
      EVENTID_CLEAGG_REQUEST_COMPLETED = 104, /*  */
      EVENTID_CLEAGG_THROTTLE_CLEARED = 105, /*  */
    };
    
    // ----------------------------------------------------------------------
    // Event Throttle values - sets initial value of countdown variable
    // ----------------------------------------------------------------------

    enum {
      EVENTID_CLEAGG_SET_GYROX_THROTTLE = 3, /*!< Throttle reset count for CLEAgg_SET_GYROX*/
      EVENTID_CLEAGG_SET_GYROY_THROTTLE = 3, /*!< Throttle reset count for CLEAgg_SET_GYROY*/
      EVENTID_CLEAGG_SET_GYROZ_THROTTLE = 3, /*!< Throttle reset count for CLEAgg_SET_GYROZ*/
      EVENTID_CLEAGG_SET_RTC_TIME_THROTTLE = 3, /*!< Throttle reset count for CLEAgg_SET_RTC_TIME*/
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event CLEAgg_SET_GYROX
    //!
    void log_ACTIVITY_HI_CLEAgg_SET_GYROX(
        F32 val 
    );
    
    // reset throttle value for CLEAgg_SET_GYROX
    void log_ACTIVITY_HI_CLEAgg_SET_GYROX_ThrottleClear(void);

    //! Log event CLEAgg_SET_GYROY
    //!
    void log_ACTIVITY_HI_CLEAgg_SET_GYROY(
        F32 val 
    );
    
    // reset throttle value for CLEAgg_SET_GYROY
    void log_ACTIVITY_HI_CLEAgg_SET_GYROY_ThrottleClear(void);

    //! Log event CLEAgg_SET_GYROZ
    //!
    void log_ACTIVITY_HI_CLEAgg_SET_GYROZ(
        F32 val 
    );
    
    // reset throttle value for CLEAgg_SET_GYROZ
    void log_ACTIVITY_HI_CLEAgg_SET_GYROZ_ThrottleClear(void);

    //! Log event CLEAgg_SET_RTC_TIME
    //!
    void log_ACTIVITY_HI_CLEAgg_SET_RTC_TIME(
        F32 val 
    );
    
    // reset throttle value for CLEAgg_SET_RTC_TIME
    void log_ACTIVITY_HI_CLEAgg_SET_RTC_TIME_ThrottleClear(void);

    //! Log event CLEAgg_REQUEST_COMPLETED
    //!
    void log_ACTIVITY_HI_CLEAgg_REQUEST_COMPLETED(
        Ref::DataRequest val 
    );
    

    //! Log event CLEAgg_THROTTLE_CLEARED
    //!
    void log_ACTIVITY_HI_CLEAgg_THROTTLE_CLEARED(
        void
    );
    

  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_CLEAGG_DATA_REQUEST = 100, //!< Channel ID for CLEAgg_DATA_REQUEST
      CHANNELID_CLEAGG_GYROXS = 101, //!< Channel ID for CLEAgg_GYROXS
      CHANNELID_CLEAGG_GYROYS = 102, //!< Channel ID for CLEAgg_GYROYS
      CHANNELID_CLEAGG_GYROZS = 103, //!< Channel ID for CLEAgg_GYROZS
      CHANNELID_CLEAGG_RTC_TIMES = 104, //!< Channel ID for CLEAgg_RTC_TIMES
      CHANNELID_CLEAGG_GYROX = 105, //!< Channel ID for CLEAgg_GYROX
      CHANNELID_CLEAGG_GYROY = 106, //!< Channel ID for CLEAgg_GYROY
      CHANNELID_CLEAGG_GYROZ = 107, //!< Channel ID for CLEAgg_GYROZ
      CHANNELID_CLEAGG_RTC_TIME = 108, //!< Channel ID for CLEAgg_RTC_TIME
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel CLEAgg_DATA_REQUEST
    //!
    void tlmWrite_CLEAgg_DATA_REQUEST(
        Ref::DataRequest& arg /*!< The telemetry value*/
    );

    //! Write telemetry channel CLEAgg_GYROXS
    //!
    void tlmWrite_CLEAgg_GYROXS(
        U32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel CLEAgg_GYROYS
    //!
    void tlmWrite_CLEAgg_GYROYS(
        U32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel CLEAgg_GYROZS
    //!
    void tlmWrite_CLEAgg_GYROZS(
        U32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel CLEAgg_RTC_TIMES
    //!
    void tlmWrite_CLEAgg_RTC_TIMES(
        U32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel CLEAgg_GYROX
    //!
    void tlmWrite_CLEAgg_GYROX(
        F32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel CLEAgg_GYROY
    //!
    void tlmWrite_CLEAgg_GYROY(
        F32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel CLEAgg_GYROZ
    //!
    void tlmWrite_CLEAgg_GYROZ(
        F32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel CLEAgg_RTC_TIME
    //!
    void tlmWrite_CLEAgg_RTC_TIME(
        F32 arg /*!< The telemetry value*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Time
    // ----------------------------------------------------------------------

    //! Get the time
    //!
    //! \return The current time
    //!
    Fw::Time getTime(void);


  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed input ports
    // ----------------------------------------------------------------------

    //! Input port RequestIn
    //!
    Ref::InputDataRequestPort m_RequestIn_InputPort[NUM_REQUESTIN_INPUT_PORTS];

    //! Input port SchedIn
    //!
    Svc::InputSchedPort m_SchedIn_InputPort[NUM_SCHEDIN_INPUT_PORTS];

    //! Input port CmdDisp
    //!
    Fw::InputCmdPort m_CmdDisp_InputPort[NUM_CMDDISP_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port ResponseOut
    //!
    Ref::OutputDataResultPort m_ResponseOut_OutputPort[NUM_RESPONSEOUT_OUTPUT_PORTS];

    //! Output port CmdStatus
    //!
    Fw::OutputCmdResponsePort m_CmdStatus_OutputPort[NUM_CMDSTATUS_OUTPUT_PORTS];

    //! Output port CmdReg
    //!
    Fw::OutputCmdRegPort m_CmdReg_OutputPort[NUM_CMDREG_OUTPUT_PORTS];

    //! Output port Tlm
    //!
    Fw::OutputTlmPort m_Tlm_OutputPort[NUM_TLM_OUTPUT_PORTS];

    //! Output port Time
    //!
    Fw::OutputTimePort m_Time_OutputPort[NUM_TIME_OUTPUT_PORTS];

    //! Output port Log
    //!
    Fw::OutputLogPort m_Log_OutputPort[NUM_LOG_OUTPUT_PORTS];

#if FW_ENABLE_TEXT_LOGGING == 1
    //! Output port LogText
    //!
    Fw::OutputLogTextPort m_LogText_OutputPort[NUM_LOGTEXT_OUTPUT_PORTS];
#endif

  PRIVATE:

    // ----------------------------------------------------------------------
    // Calls for messages received on typed input ports
    // ----------------------------------------------------------------------

    //! Callback for port RequestIn
    //!
    static void m_p_RequestIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        DataRequestPortZ data /*!< Possible data types to be requested*/
    );

    //! Callback for port SchedIn
    //!
    static void m_p_SchedIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        NATIVE_UINT_TYPE context /*!< The call order*/
    );

    //! Callback for port CmdDisp
    //!
    static void m_p_CmdDisp_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        FwOpcodeType opCode, /*!< Command Op Code*/
        U32 cmdSeq, /*!< Command Sequence*/
        Fw::CmdArgBuffer &args /*!< Buffer containing arguments*/
    );


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------
    NATIVE_UINT_TYPE m_CLEAgg_SET_GYROXThrottle; //!< throttle for CLEAgg_SET_GYROX
    NATIVE_UINT_TYPE m_CLEAgg_SET_GYROYThrottle; //!< throttle for CLEAgg_SET_GYROY
    NATIVE_UINT_TYPE m_CLEAgg_SET_GYROZThrottle; //!< throttle for CLEAgg_SET_GYROZ
    NATIVE_UINT_TYPE m_CLEAgg_SET_RTC_TIMEThrottle; //!< throttle for CLEAgg_SET_RTC_TIME

  };  

} // end namespace Ref
#endif
