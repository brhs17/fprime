// ====================================================================== 
// \title  MathSenderComponentAc.hpp
// \author Auto-generated
// \brief  hpp file for MathSender component base class
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

#ifndef MATHSENDER_COMP_HPP_
#define MATHSENDER_COMP_HPP_

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
#include <Ref/MathPorts/MathOpPortAc.hpp>
#include <Ref/MathPorts/MathResultPortAc.hpp>
#include <Fw/Cmd/CmdPortAc.hpp>
#include <Fw/Cmd/CmdResponsePortAc.hpp>
#include <Fw/Cmd/CmdRegPortAc.hpp>
#include <Fw/Tlm/TlmPortAc.hpp>
#include <Fw/Time/TimePortAc.hpp>
#include <Fw/Log/LogPortAc.hpp>
#if FW_ENABLE_TEXT_LOGGING == 1
#include <Fw/Log/LogTextPortAc.hpp>
#endif

namespace Ref {

  //! \class MathSenderComponentBase
  //! \brief Auto-generated base for MathSender component
  //!
  class MathSenderComponentBase :
    public Fw::ActiveComponentBase
  {

    // ----------------------------------------------------------------------
    // Friend classes
    // ----------------------------------------------------------------------

    //! Friend class for white-box testing
    //!
    friend class MathSenderComponentBaseFriend;

  public:

    // ----------------------------------------------------------------------
    // Getters for typed input ports
    // ----------------------------------------------------------------------

    //! Get input port at index
    //!
    //! \return mathIn[portNum]
    //!
    Ref::InputMathResultPort* get_mathIn_InputPort(
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

    //! Connect port to mathOut[portNum]
    //!
    void set_mathOut_OutputPort(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        Ref::InputMathOpPort *port /*!< The port*/
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

    //! Connect port to mathOut[portNum]
    //!
    void set_mathOut_OutputPort(
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
    //! Construct a MathSenderComponentBase object
    //!
    MathSenderComponentBase(
        const char* compName /*!< Component name*/
    );
#else
    //! Construct a MathSenderComponentBase object
    //!
    MathSenderComponentBase(void);
#endif

    //! Initialize a MathSenderComponentBase object
    //!
    void init(
        NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
        NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
    );

    //! Destroy a MathSenderComponentBase object
    //!
    virtual ~MathSenderComponentBase(void);

  PROTECTED:

    // ----------------------------------------------------------------------
    // Handlers to implement for typed input ports
    // ----------------------------------------------------------------------

    //! Handler for input port mathIn
    //
    virtual void mathIn_handler(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        F32 result 
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Port handler base-class functions for typed input ports.
    // ----------------------------------------------------------------------
    // Call these functions directly to bypass the corresponding ports.
    // ----------------------------------------------------------------------

    //! Handler base-class function for input port mathIn
    //!
    void mathIn_handlerBase(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        F32 result 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for typed async input ports.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing a message
    // on the corresponding port. By default they do nothing. You can
    // override them to provide specific pre-message behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for async input port mathIn
    //!
    virtual void mathIn_preMsgHook(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        F32 result 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Invocation functions for typed output ports
    // ----------------------------------------------------------------------

    //! Invoke output port mathOut
    //!
    void mathOut_out(
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        F32 val1, 
        F32 val2, 
        MathOperation operation 
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of input ports
    // ----------------------------------------------------------------------

    //! Get the number of mathIn input ports
    //!
    //! \return The number of mathIn input ports
    //!
    NATIVE_INT_TYPE getNum_mathIn_InputPorts(void);

    //! Get the number of CmdDisp input ports
    //!
    //! \return The number of CmdDisp input ports
    //!
    NATIVE_INT_TYPE getNum_CmdDisp_InputPorts(void);

  
    // ----------------------------------------------------------------------
    // Enumerations for number of ports
    // ----------------------------------------------------------------------
    
    enum {
       NUM_MATHIN_INPUT_PORTS = 1,
       NUM_CMDDISP_INPUT_PORTS = 1,
    };
  
  PROTECTED:

    // ----------------------------------------------------------------------
    // Getters for numbers of output ports
    // ----------------------------------------------------------------------

    //! Get the number of mathOut output ports
    //!
    //! \return The number of mathOut output ports
    //!
    NATIVE_INT_TYPE getNum_mathOut_OutputPorts(void);

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
       NUM_MATHOUT_OUTPUT_PORTS = 1,
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

    //! Check whether port mathOut is connected
    //!
    //! \return Whether port mathOut is connected
    //!
    bool isConnected_mathOut_OutputPort(
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
    // Command enums
    // ----------------------------------------------------------------------

    typedef enum {
      ADD, /*  */
      SUBTRACT, /*  */
      MULTIPLY, /*  */
      DIVIDE, /*  */
      MathOp_MAX
    } MathOp;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command opcodes
    // ----------------------------------------------------------------------

    enum {
      OPCODE_MS_DO_MATH = 0, /* Do a math operation */
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handlers to implement
    // ----------------------------------------------------------------------

    //! Handler for command MS_DO_MATH
    /* Do a math operation */
    virtual void MS_DO_MATH_cmdHandler(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq, /*!< The command sequence number*/
        F32 val1, /*!< The first value*/
        F32 val2, /*!< The second value*/
        MathOp operation /*!< The operation to perform*/
    ) = 0;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Pre-message hooks for async commands.
    // ----------------------------------------------------------------------
    // Each of these functions is invoked just before processing the
    // corresponding command. By default they do nothing. You can
    // override them to provide specific pre-command behavior.
    // ----------------------------------------------------------------------

    //! Pre-message hook for command MS_DO_MATH
    //!
    virtual void MS_DO_MATH_preMsgHook(
        FwOpcodeType opCode, /*!< The opcode*/
        U32 cmdSeq /*!< The command sequence number*/
    );

  PROTECTED:

    // ----------------------------------------------------------------------
    // Command handler base-class functions.
    // Call these functions directly to bypass the command input port.
    // ----------------------------------------------------------------------

    //! Base-class handler function for command MS_DO_MATH
    //! 
    void MS_DO_MATH_cmdHandlerBase( 
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
      EVENTID_MS_COMMAND_RECV = 0, /* Math command received */
      EVENTID_MS_RESULT = 1, /* Received math result */
    };
    
  PROTECTED:

    // ----------------------------------------------------------------------
    // Event enums
    // ----------------------------------------------------------------------

    typedef enum {
      ADD_EV, /*  */
      SUB_EV, /*  */
      MULT_EV, /*  */
      DIV_EV, /*  */
      MathOpEv_MAX
    } MathOpEv;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Event logging functions
    // ----------------------------------------------------------------------

    //! Log event MS_COMMAND_RECV
    //!
    /* Math command received */
    void log_ACTIVITY_LO_MS_COMMAND_RECV(
        F32 val1, /*!< The val1 argument*/
        F32 val2, /*!< The val2 argument*/
        MathOpEv op /*!< The requested operation*/
    );
    

    //! Log event MS_RESULT
    //!
    /* Received math result */
    void log_ACTIVITY_HI_MS_RESULT(
        F32 result /*!< The math result*/
    );
    

  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel IDs
    // ----------------------------------------------------------------------

    enum {
      CHANNELID_MS_VAL1 = 0, //!< Channel ID for MS_VAL1
      CHANNELID_MS_VAL2 = 1, //!< Channel ID for MS_VAL2
      CHANNELID_MS_OP = 2, //!< Channel ID for MS_OP
      CHANNELID_MS_RES = 3, //!< Channel ID for MS_RES
    };

  PROTECTED:

    // ----------------------------------------------------------------------
    // Channel enums
    // ----------------------------------------------------------------------

    typedef enum {
      ADD_TLM, /*  */
      SUB_TLM, /*  */
      MULT_TLM, /*  */
      DIV_TLM, /*  */
      MathOpTlm_MAX
    } MathOpTlm;

  PROTECTED:

    // ----------------------------------------------------------------------
    // Telemetry write functions
    // ----------------------------------------------------------------------

    //! Write telemetry channel MS_VAL1
    //!
    /* The first value */
    void tlmWrite_MS_VAL1(
        F32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel MS_VAL2
    //!
    /* The second value */
    void tlmWrite_MS_VAL2(
        F32 arg /*!< The telemetry value*/
    );

    //! Write telemetry channel MS_OP
    //!
    /* The operation */
    void tlmWrite_MS_OP(
        MathOpTlm arg /*!< The telemetry value*/
    );

    //! Write telemetry channel MS_RES
    //!
    /* The result */
    void tlmWrite_MS_RES(
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

    //! Input port mathIn
    //!
    Ref::InputMathResultPort m_mathIn_InputPort[NUM_MATHIN_INPUT_PORTS];

    //! Input port CmdDisp
    //!
    Fw::InputCmdPort m_CmdDisp_InputPort[NUM_CMDDISP_INPUT_PORTS];

  PRIVATE:

    // ----------------------------------------------------------------------
    // Typed output ports
    // ----------------------------------------------------------------------

    //! Output port mathOut
    //!
    Ref::OutputMathOpPort m_mathOut_OutputPort[NUM_MATHOUT_OUTPUT_PORTS];

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

    //! Callback for port mathIn
    //!
    static void m_p_mathIn_in(
        Fw::PassiveComponentBase* callComp, /*!< The component instance*/
        NATIVE_INT_TYPE portNum, /*!< The port number*/
        F32 result 
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
    // Message dispatch functions
    // ----------------------------------------------------------------------

    //! Called in the message loop to dispatch a message from the queue
    //!
    virtual MsgDispatchStatus doDispatch(void);


  PRIVATE:
    // ----------------------------------------------------------------------
    // Counter values for event throttling
    // ----------------------------------------------------------------------

  };  

} // end namespace Ref
#endif
