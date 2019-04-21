// ======================================================================
// \title  CLEAgg/test/ut/TesterBase.cpp
// \author Auto-generated
// \brief  cpp file for CLEAgg component test harness base class
//
// \copyright
// Copyright 2009-2016, by the California Institute of Technology.
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

#include <stdlib.h>
#include <string.h>
#include "TesterBase.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  CLEAggTesterBase ::
    CLEAggTesterBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) :
#if FW_OBJECT_NAMES == 1
      Fw::PassiveComponentBase(compName)
#else
      Fw::PassiveComponentBase()
#endif
  {
    // Initialize command history
    this->cmdResponseHistory = new History<CmdResponse>(maxHistorySize);
    // Initialize telemetry histories
    this->tlmHistory_CLEAgg_DATA_REQUEST = 
      new History<TlmEntry_CLEAgg_DATA_REQUEST>(maxHistorySize);
    this->tlmHistory_CLEAgg_GYROXS = 
      new History<TlmEntry_CLEAgg_GYROXS>(maxHistorySize);
    this->tlmHistory_CLEAgg_GYROYS = 
      new History<TlmEntry_CLEAgg_GYROYS>(maxHistorySize);
    this->tlmHistory_CLEAgg_GYROZS = 
      new History<TlmEntry_CLEAgg_GYROZS>(maxHistorySize);
    this->tlmHistory_CLEAgg_RTC_TIMES = 
      new History<TlmEntry_CLEAgg_RTC_TIMES>(maxHistorySize);
    this->tlmHistory_CLEAgg_GYROX = 
      new History<TlmEntry_CLEAgg_GYROX>(maxHistorySize);
    this->tlmHistory_CLEAgg_GYROY = 
      new History<TlmEntry_CLEAgg_GYROY>(maxHistorySize);
    this->tlmHistory_CLEAgg_GYROZ = 
      new History<TlmEntry_CLEAgg_GYROZ>(maxHistorySize);
    this->tlmHistory_CLEAgg_RTC_TIME = 
      new History<TlmEntry_CLEAgg_RTC_TIME>(maxHistorySize);
    // Initialize event histories
#if FW_ENABLE_TEXT_LOGGING
    this->textLogHistory = new History<TextLogEntry>(maxHistorySize);
#endif
    this->eventHistory_CLEAgg_SET_GYROX =
      new History<EventEntry_CLEAgg_SET_GYROX>(maxHistorySize);
    this->eventHistory_CLEAgg_SET_GYROY =
      new History<EventEntry_CLEAgg_SET_GYROY>(maxHistorySize);
    this->eventHistory_CLEAgg_SET_GYROZ =
      new History<EventEntry_CLEAgg_SET_GYROZ>(maxHistorySize);
    this->eventHistory_CLEAgg_SET_RTC_TIME =
      new History<EventEntry_CLEAgg_SET_RTC_TIME>(maxHistorySize);
    this->eventHistory_CLEAgg_REQUEST_COMPLETED =
      new History<EventEntry_CLEAgg_REQUEST_COMPLETED>(maxHistorySize);
    // Initialize histories for typed user output ports
    this->fromPortHistory_ResponseOut =
      new History<FromPortEntry_ResponseOut>(maxHistorySize);
    // Clear history
    this->clearHistory();
  }

  CLEAggTesterBase ::
    ~CLEAggTesterBase(void) 
  {
    // Destroy command history
    delete this->cmdResponseHistory;
    // Destroy telemetry histories
    delete this->tlmHistory_CLEAgg_DATA_REQUEST;
    delete this->tlmHistory_CLEAgg_GYROXS;
    delete this->tlmHistory_CLEAgg_GYROYS;
    delete this->tlmHistory_CLEAgg_GYROZS;
    delete this->tlmHistory_CLEAgg_RTC_TIMES;
    delete this->tlmHistory_CLEAgg_GYROX;
    delete this->tlmHistory_CLEAgg_GYROY;
    delete this->tlmHistory_CLEAgg_GYROZ;
    delete this->tlmHistory_CLEAgg_RTC_TIME;
    // Destroy event histories
#if FW_ENABLE_TEXT_LOGGING
    delete this->textLogHistory;
#endif
    delete this->eventHistory_CLEAgg_SET_GYROX;
    delete this->eventHistory_CLEAgg_SET_GYROY;
    delete this->eventHistory_CLEAgg_SET_GYROZ;
    delete this->eventHistory_CLEAgg_SET_RTC_TIME;
    delete this->eventHistory_CLEAgg_REQUEST_COMPLETED;
  }

  void CLEAggTesterBase ::
    init(
        const NATIVE_INT_TYPE instance
    )
  {

    // Initialize base class

		Fw::PassiveComponentBase::init(instance);

    // Attach input port ResponseOut

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_ResponseOut();
        ++_port
    ) {

      this->m_from_ResponseOut[_port].init();
      this->m_from_ResponseOut[_port].addCallComp(
          this,
          from_ResponseOut_static
      );
      this->m_from_ResponseOut[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_ResponseOut[%d]",
          this->m_objName,
          _port
      );
      this->m_from_ResponseOut[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdStatus

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdStatus();
        ++_port
    ) {

      this->m_from_CmdStatus[_port].init();
      this->m_from_CmdStatus[_port].addCallComp(
          this,
          from_CmdStatus_static
      );
      this->m_from_CmdStatus[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdStatus[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdStatus[_port].setObjName(_portName);
#endif

    }

    // Attach input port CmdReg

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_CmdReg();
        ++_port
    ) {

      this->m_from_CmdReg[_port].init();
      this->m_from_CmdReg[_port].addCallComp(
          this,
          from_CmdReg_static
      );
      this->m_from_CmdReg[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_CmdReg[%d]",
          this->m_objName,
          _port
      );
      this->m_from_CmdReg[_port].setObjName(_portName);
#endif

    }

    // Attach input port Tlm

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Tlm();
        ++_port
    ) {

      this->m_from_Tlm[_port].init();
      this->m_from_Tlm[_port].addCallComp(
          this,
          from_Tlm_static
      );
      this->m_from_Tlm[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Tlm[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Tlm[_port].setObjName(_portName);
#endif

    }

    // Attach input port Time

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Time();
        ++_port
    ) {

      this->m_from_Time[_port].init();
      this->m_from_Time[_port].addCallComp(
          this,
          from_Time_static
      );
      this->m_from_Time[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Time[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Time[_port].setObjName(_portName);
#endif

    }

    // Attach input port Log

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_Log();
        ++_port
    ) {

      this->m_from_Log[_port].init();
      this->m_from_Log[_port].addCallComp(
          this,
          from_Log_static
      );
      this->m_from_Log[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_Log[%d]",
          this->m_objName,
          _port
      );
      this->m_from_Log[_port].setObjName(_portName);
#endif

    }

    // Attach input port LogText

#if FW_ENABLE_TEXT_LOGGING == 1
    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_from_LogText();
        ++_port
    ) {

      this->m_from_LogText[_port].init();
      this->m_from_LogText[_port].addCallComp(
          this,
          from_LogText_static
      );
      this->m_from_LogText[_port].setPortNum(_port);

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      (void) snprintf(
          _portName,
          sizeof(_portName),
          "%s_from_LogText[%d]",
          this->m_objName,
          _port
      );
      this->m_from_LogText[_port].setObjName(_portName);
#endif

    }
#endif

    // Initialize output port RequestIn

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_RequestIn();
        ++_port
    ) {
      this->m_to_RequestIn[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_RequestIn[%d]",
          this->m_objName,
          _port
      );
      this->m_to_RequestIn[_port].setObjName(_portName);
#endif

    }

    // Initialize output port SchedIn

    for (
        NATIVE_INT_TYPE _port = 0;
        _port < this->getNum_to_SchedIn();
        ++_port
    ) {
      this->m_to_SchedIn[_port].init();

#if FW_OBJECT_NAMES == 1
      char _portName[80];
      snprintf(
          _portName,
          sizeof(_portName),
          "%s_to_SchedIn[%d]",
          this->m_objName,
          _port
      );
      this->m_to_SchedIn[_port].setObjName(_portName);
#endif

    }

  }

  // ----------------------------------------------------------------------
  // Getters for port counts
  // ----------------------------------------------------------------------

  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_to_RequestIn(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_RequestIn);
  }

  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_from_ResponseOut(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_ResponseOut);
  }

  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_to_SchedIn(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_SchedIn);
  }

  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_to_CmdDisp(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_to_CmdDisp);
  }

  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_from_CmdStatus(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdStatus);
  }

  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_from_CmdReg(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_CmdReg);
  }

  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_from_Tlm(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Tlm);
  }

  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_from_Time(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Time);
  }

  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_from_Log(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_Log);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  NATIVE_INT_TYPE CLEAggTesterBase ::
    getNum_from_LogText(void) const
  {
    return (NATIVE_INT_TYPE) FW_NUM_ARRAY_ELEMENTS(this->m_from_LogText);
  }
#endif

  // ----------------------------------------------------------------------
  // Connectors for to ports 
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    connect_to_RequestIn(
        const NATIVE_INT_TYPE portNum,
        Ref::InputDataRequestPort *const RequestIn
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_RequestIn(),static_cast<AssertArg>(portNum));
    this->m_to_RequestIn[portNum].addCallPort(RequestIn);
  }

  void CLEAggTesterBase ::
    connect_to_SchedIn(
        const NATIVE_INT_TYPE portNum,
        Svc::InputSchedPort *const SchedIn
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_SchedIn(),static_cast<AssertArg>(portNum));
    this->m_to_SchedIn[portNum].addCallPort(SchedIn);
  }

  void CLEAggTesterBase ::
    connect_to_CmdDisp(
        const NATIVE_INT_TYPE portNum,
        Fw::InputCmdPort *const CmdDisp
    ) 
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(),static_cast<AssertArg>(portNum));
    this->m_to_CmdDisp[portNum].addCallPort(CmdDisp);
  }


  // ----------------------------------------------------------------------
  // Invocation functions for to ports
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    invoke_to_RequestIn(
        const NATIVE_INT_TYPE portNum,
        DataRequestPortZ data
    )
  {
    FW_ASSERT(portNum < this->getNum_to_RequestIn(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_RequestIn(),static_cast<AssertArg>(portNum));
    this->m_to_RequestIn[portNum].invoke(
        data
    );
  }

  void CLEAggTesterBase ::
    invoke_to_SchedIn(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    FW_ASSERT(portNum < this->getNum_to_SchedIn(),static_cast<AssertArg>(portNum));
    FW_ASSERT(portNum < this->getNum_to_SchedIn(),static_cast<AssertArg>(portNum));
    this->m_to_SchedIn[portNum].invoke(
        context
    );
  }

  // ----------------------------------------------------------------------
  // Connection status for to ports
  // ----------------------------------------------------------------------

  bool CLEAggTesterBase ::
    isConnected_to_RequestIn(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_RequestIn(), static_cast<AssertArg>(portNum));
    return this->m_to_RequestIn[portNum].isConnected();
  }

  bool CLEAggTesterBase ::
    isConnected_to_SchedIn(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_SchedIn(), static_cast<AssertArg>(portNum));
    return this->m_to_SchedIn[portNum].isConnected();
  }

  bool CLEAggTesterBase ::
    isConnected_to_CmdDisp(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_to_CmdDisp(), static_cast<AssertArg>(portNum));
    return this->m_to_CmdDisp[portNum].isConnected();
  }

  // ----------------------------------------------------------------------
  // Getters for from ports
  // ----------------------------------------------------------------------
 
  Ref::InputDataResultPort *CLEAggTesterBase ::
    get_from_ResponseOut(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_ResponseOut(),static_cast<AssertArg>(portNum));
    return &this->m_from_ResponseOut[portNum];
  }

  Fw::InputCmdResponsePort *CLEAggTesterBase ::
    get_from_CmdStatus(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdStatus(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdStatus[portNum];
  }

  Fw::InputCmdRegPort *CLEAggTesterBase ::
    get_from_CmdReg(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_CmdReg(),static_cast<AssertArg>(portNum));
    return &this->m_from_CmdReg[portNum];
  }

  Fw::InputTlmPort *CLEAggTesterBase ::
    get_from_Tlm(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Tlm(),static_cast<AssertArg>(portNum));
    return &this->m_from_Tlm[portNum];
  }

  Fw::InputTimePort *CLEAggTesterBase ::
    get_from_Time(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Time(),static_cast<AssertArg>(portNum));
    return &this->m_from_Time[portNum];
  }

  Fw::InputLogPort *CLEAggTesterBase ::
    get_from_Log(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_Log(),static_cast<AssertArg>(portNum));
    return &this->m_from_Log[portNum];
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  Fw::InputLogTextPort *CLEAggTesterBase ::
    get_from_LogText(const NATIVE_INT_TYPE portNum)
  {
    FW_ASSERT(portNum < this->getNum_from_LogText(),static_cast<AssertArg>(portNum));
    return &this->m_from_LogText[portNum];
  }
#endif

  // ----------------------------------------------------------------------
  // Static functions for from ports
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    from_ResponseOut_static(
        Fw::PassiveComponentBase *const callComp,
        const NATIVE_INT_TYPE portNum,
        F32 result
    )
  {
    FW_ASSERT(callComp);
    CLEAggTesterBase* _testerBase = 
      static_cast<CLEAggTesterBase*>(callComp);
    _testerBase->from_ResponseOut_handlerBase(
        portNum,
        result
    );
  }

  void CLEAggTesterBase ::
    from_CmdStatus_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CommandResponse response
    )
  {
    CLEAggTesterBase* _testerBase =
      static_cast<CLEAggTesterBase*>(component);
    _testerBase->cmdResponseIn(opCode, cmdSeq, response);
  }

  void CLEAggTesterBase ::
    from_CmdReg_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        const FwOpcodeType opCode
    )
  {

  }

  void CLEAggTesterBase ::
    from_Tlm_static(
        Fw::PassiveComponentBase *const component,
        NATIVE_INT_TYPE portNum,
        FwChanIdType id,
        Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {
    CLEAggTesterBase* _testerBase =
      static_cast<CLEAggTesterBase*>(component);
    _testerBase->dispatchTlm(id, timeTag, val);
  }

  void CLEAggTesterBase ::
    from_Log_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {
    CLEAggTesterBase* _testerBase =
      static_cast<CLEAggTesterBase*>(component);
    _testerBase->dispatchEvents(id, timeTag, severity, args);
  }

#if FW_ENABLE_TEXT_LOGGING == 1
  void CLEAggTesterBase ::
    from_LogText_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        FwEventIdType id,
        Fw::Time &timeTag,
        Fw::TextLogSeverity severity,
        Fw::TextLogString &text
    )
  {
    CLEAggTesterBase* _testerBase =
      static_cast<CLEAggTesterBase*>(component);
    _testerBase->textLogIn(id,timeTag,severity,text);
  }
#endif

  void CLEAggTesterBase ::
    from_Time_static(
        Fw::PassiveComponentBase *const component,
        const NATIVE_INT_TYPE portNum,
        Fw::Time& time
    )
  {
    CLEAggTesterBase* _testerBase =
      static_cast<CLEAggTesterBase*>(component);
    time = _testerBase->m_testTime;
  }

  // ----------------------------------------------------------------------
  // Histories for typed from ports
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    clearFromPortHistory(void)
  {
    this->fromPortHistorySize = 0;
    this->fromPortHistory_ResponseOut->clear();
  }

  // ---------------------------------------------------------------------- 
  // From port: ResponseOut
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    pushFromPortEntry_ResponseOut(
        F32 result
    )
  {
    FromPortEntry_ResponseOut _e = {
      result
    };
    this->fromPortHistory_ResponseOut->push_back(_e);
    ++this->fromPortHistorySize;
  }

  // ----------------------------------------------------------------------
  // Handler base functions for from ports
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    from_ResponseOut_handlerBase(
        const NATIVE_INT_TYPE portNum,
        F32 result
    )
  {
    FW_ASSERT(portNum < this->getNum_from_ResponseOut(),static_cast<AssertArg>(portNum));
    this->from_ResponseOut_handler(
        portNum,
        result
    );
  }

  // ----------------------------------------------------------------------
  // Command response handling
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    cmdResponseIn(
        const FwOpcodeType opCode,
        const U32 seq,
        const Fw::CommandResponse response
    )
  {
    CmdResponse e = { opCode, seq, response };
    this->cmdResponseHistory->push_back(e);
  }

  // ---------------------------------------------------------------------- 
  // Command: CLEAgg_SET_GYROX
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    sendCmd_CLEAgg_SET_GYROX(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        F32 val
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(val);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = CLEAggComponentBase::OPCODE_CLEAGG_SET_GYROX + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ---------------------------------------------------------------------- 
  // Command: CLEAgg_SET_GYROY
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    sendCmd_CLEAgg_SET_GYROY(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        F32 val
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(val);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = CLEAggComponentBase::OPCODE_CLEAGG_SET_GYROY + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ---------------------------------------------------------------------- 
  // Command: CLEAgg_SET_GYROZ
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    sendCmd_CLEAgg_SET_GYROZ(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        F32 val
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(val);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = CLEAggComponentBase::OPCODE_CLEAGG_SET_GYROZ + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ---------------------------------------------------------------------- 
  // Command: CLEAgg_SET_RTC_TIME
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    sendCmd_CLEAgg_SET_RTC_TIME(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq,
        F32 val
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;
    Fw::SerializeStatus _status;
    _status = buff.serialize(val);
    FW_ASSERT(_status == Fw::FW_SERIALIZE_OK,static_cast<AssertArg>(_status));

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = CLEAggComponentBase::OPCODE_CLEAGG_SET_RTC_TIME + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  // ---------------------------------------------------------------------- 
  // Command: CLEAgg_CLEAR_EVENT_THROTTLE
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    sendCmd_CLEAgg_CLEAR_EVENT_THROTTLE(
        const NATIVE_INT_TYPE instance,
        const U32 cmdSeq
    )
  {

    // Serialize arguments

    Fw::CmdArgBuffer buff;

    // Call output command port
    
    FwOpcodeType _opcode;
    const U32 idBase = this->getIdBase();
    _opcode = CLEAggComponentBase::OPCODE_CLEAGG_CLEAR_EVENT_THROTTLE + idBase;

    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          buff
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }

  }

  
  void CLEAggTesterBase ::
    sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args) {
       
    const U32 idBase = this->getIdBase();   
    FwOpcodeType _opcode = opcode + idBase;
    if (this->m_to_CmdDisp[0].isConnected()) {
      this->m_to_CmdDisp[0].invoke(
          _opcode,
          cmdSeq,
          args
      );
    }
    else {
      printf("Test Command Output port not connected!\n");
    }
        
  }
  
  // ----------------------------------------------------------------------
  // History 
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    clearHistory()
  {
    this->cmdResponseHistory->clear();
    this->clearTlm();
    this->textLogHistory->clear();
    this->clearEvents();
    this->clearFromPortHistory();
  }

  // ----------------------------------------------------------------------
  // Time
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    setTestTime(const Fw::Time& time)
  {
    this->m_testTime = time;
  }

  // ----------------------------------------------------------------------
  // Telemetry dispatch
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    dispatchTlm(
        const FwChanIdType id,
        const Fw::Time &timeTag,
        Fw::TlmBuffer &val
    )
  {

    val.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);

    switch (id - idBase) {

      case CLEAggComponentBase::CHANNELID_CLEAGG_DATA_REQUEST:
      {
        Ref::DataRequest arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CLEAgg_DATA_REQUEST: %d\n", _status);
          return;
        }
        this->tlmInput_CLEAgg_DATA_REQUEST(timeTag, arg);
        break;
      }

      case CLEAggComponentBase::CHANNELID_CLEAGG_GYROXS:
      {
        U32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CLEAgg_GYROXS: %d\n", _status);
          return;
        }
        this->tlmInput_CLEAgg_GYROXS(timeTag, arg);
        break;
      }

      case CLEAggComponentBase::CHANNELID_CLEAGG_GYROYS:
      {
        U32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CLEAgg_GYROYS: %d\n", _status);
          return;
        }
        this->tlmInput_CLEAgg_GYROYS(timeTag, arg);
        break;
      }

      case CLEAggComponentBase::CHANNELID_CLEAGG_GYROZS:
      {
        U32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CLEAgg_GYROZS: %d\n", _status);
          return;
        }
        this->tlmInput_CLEAgg_GYROZS(timeTag, arg);
        break;
      }

      case CLEAggComponentBase::CHANNELID_CLEAGG_RTC_TIMES:
      {
        U32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CLEAgg_RTC_TIMES: %d\n", _status);
          return;
        }
        this->tlmInput_CLEAgg_RTC_TIMES(timeTag, arg);
        break;
      }

      case CLEAggComponentBase::CHANNELID_CLEAGG_GYROX:
      {
        F32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CLEAgg_GYROX: %d\n", _status);
          return;
        }
        this->tlmInput_CLEAgg_GYROX(timeTag, arg);
        break;
      }

      case CLEAggComponentBase::CHANNELID_CLEAGG_GYROY:
      {
        F32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CLEAgg_GYROY: %d\n", _status);
          return;
        }
        this->tlmInput_CLEAgg_GYROY(timeTag, arg);
        break;
      }

      case CLEAggComponentBase::CHANNELID_CLEAGG_GYROZ:
      {
        F32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CLEAgg_GYROZ: %d\n", _status);
          return;
        }
        this->tlmInput_CLEAgg_GYROZ(timeTag, arg);
        break;
      }

      case CLEAggComponentBase::CHANNELID_CLEAGG_RTC_TIME:
      {
        F32 arg;
        const Fw::SerializeStatus _status = val.deserialize(arg);
        if (_status != Fw::FW_SERIALIZE_OK) {
          printf("Error deserializing CLEAgg_RTC_TIME: %d\n", _status);
          return;
        }
        this->tlmInput_CLEAgg_RTC_TIME(timeTag, arg);
        break;
      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void CLEAggTesterBase ::
    clearTlm(void)
  {
    this->tlmSize = 0;
    this->tlmHistory_CLEAgg_DATA_REQUEST->clear();
    this->tlmHistory_CLEAgg_GYROXS->clear();
    this->tlmHistory_CLEAgg_GYROYS->clear();
    this->tlmHistory_CLEAgg_GYROZS->clear();
    this->tlmHistory_CLEAgg_RTC_TIMES->clear();
    this->tlmHistory_CLEAgg_GYROX->clear();
    this->tlmHistory_CLEAgg_GYROY->clear();
    this->tlmHistory_CLEAgg_GYROZ->clear();
    this->tlmHistory_CLEAgg_RTC_TIME->clear();
  }

  // ---------------------------------------------------------------------- 
  // Channel: CLEAgg_DATA_REQUEST
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    tlmInput_CLEAgg_DATA_REQUEST(
        const Fw::Time& timeTag,
        const Ref::DataRequest& val
    )
  {
    TlmEntry_CLEAgg_DATA_REQUEST e = { timeTag, val };
    this->tlmHistory_CLEAgg_DATA_REQUEST->push_back(e);
    ++this->tlmSize;
  }

  // ---------------------------------------------------------------------- 
  // Channel: CLEAgg_GYROXS
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    tlmInput_CLEAgg_GYROXS(
        const Fw::Time& timeTag,
        const U32& val
    )
  {
    TlmEntry_CLEAgg_GYROXS e = { timeTag, val };
    this->tlmHistory_CLEAgg_GYROXS->push_back(e);
    ++this->tlmSize;
  }

  // ---------------------------------------------------------------------- 
  // Channel: CLEAgg_GYROYS
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    tlmInput_CLEAgg_GYROYS(
        const Fw::Time& timeTag,
        const U32& val
    )
  {
    TlmEntry_CLEAgg_GYROYS e = { timeTag, val };
    this->tlmHistory_CLEAgg_GYROYS->push_back(e);
    ++this->tlmSize;
  }

  // ---------------------------------------------------------------------- 
  // Channel: CLEAgg_GYROZS
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    tlmInput_CLEAgg_GYROZS(
        const Fw::Time& timeTag,
        const U32& val
    )
  {
    TlmEntry_CLEAgg_GYROZS e = { timeTag, val };
    this->tlmHistory_CLEAgg_GYROZS->push_back(e);
    ++this->tlmSize;
  }

  // ---------------------------------------------------------------------- 
  // Channel: CLEAgg_RTC_TIMES
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    tlmInput_CLEAgg_RTC_TIMES(
        const Fw::Time& timeTag,
        const U32& val
    )
  {
    TlmEntry_CLEAgg_RTC_TIMES e = { timeTag, val };
    this->tlmHistory_CLEAgg_RTC_TIMES->push_back(e);
    ++this->tlmSize;
  }

  // ---------------------------------------------------------------------- 
  // Channel: CLEAgg_GYROX
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    tlmInput_CLEAgg_GYROX(
        const Fw::Time& timeTag,
        const F32& val
    )
  {
    TlmEntry_CLEAgg_GYROX e = { timeTag, val };
    this->tlmHistory_CLEAgg_GYROX->push_back(e);
    ++this->tlmSize;
  }

  // ---------------------------------------------------------------------- 
  // Channel: CLEAgg_GYROY
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    tlmInput_CLEAgg_GYROY(
        const Fw::Time& timeTag,
        const F32& val
    )
  {
    TlmEntry_CLEAgg_GYROY e = { timeTag, val };
    this->tlmHistory_CLEAgg_GYROY->push_back(e);
    ++this->tlmSize;
  }

  // ---------------------------------------------------------------------- 
  // Channel: CLEAgg_GYROZ
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    tlmInput_CLEAgg_GYROZ(
        const Fw::Time& timeTag,
        const F32& val
    )
  {
    TlmEntry_CLEAgg_GYROZ e = { timeTag, val };
    this->tlmHistory_CLEAgg_GYROZ->push_back(e);
    ++this->tlmSize;
  }

  // ---------------------------------------------------------------------- 
  // Channel: CLEAgg_RTC_TIME
  // ---------------------------------------------------------------------- 

  void CLEAggTesterBase ::
    tlmInput_CLEAgg_RTC_TIME(
        const Fw::Time& timeTag,
        const F32& val
    )
  {
    TlmEntry_CLEAgg_RTC_TIME e = { timeTag, val };
    this->tlmHistory_CLEAgg_RTC_TIME->push_back(e);
    ++this->tlmSize;
  }

  // ----------------------------------------------------------------------
  // Event dispatch
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    dispatchEvents(
        const FwEventIdType id,
        Fw::Time &timeTag,
        const Fw::LogSeverity severity,
        Fw::LogBuffer &args
    )
  {

    args.resetDeser();

    const U32 idBase = this->getIdBase();
    FW_ASSERT(id >= idBase, id, idBase);
    switch (id - idBase) {

      case CLEAggComponentBase::EVENTID_CLEAGG_SET_GYROX: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        F32 val;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(val);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_CLEAgg_SET_GYROX(val);

        break;

      }

      case CLEAggComponentBase::EVENTID_CLEAGG_SET_GYROY: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        F32 val;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(val);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_CLEAgg_SET_GYROY(val);

        break;

      }

      case CLEAggComponentBase::EVENTID_CLEAGG_SET_GYROZ: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        F32 val;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(val);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_CLEAgg_SET_GYROZ(val);

        break;

      }

      case CLEAggComponentBase::EVENTID_CLEAGG_SET_RTC_TIME: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        F32 val;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(F32),_argSize,sizeof(F32));
        }
#endif      
        _status = args.deserialize(val);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_CLEAgg_SET_RTC_TIME(val);

        break;

      }

      case CLEAggComponentBase::EVENTID_CLEAGG_REQUEST_COMPLETED: 
      {

        Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;
#if FW_AMPCS_COMPATIBLE
        // Deserialize the number of arguments.
        U8 _numArgs;
        _status = args.deserialize(_numArgs);
        FW_ASSERT(
          _status == Fw::FW_SERIALIZE_OK,
          static_cast<AssertArg>(_status)
        );
        // verify they match expected.
        FW_ASSERT(_numArgs == 1,_numArgs,1);
        
#endif    
        Ref::DataRequest val;
#if FW_AMPCS_COMPATIBLE
        {
          // Deserialize the argument size
          U8 _argSize;
          _status = args.deserialize(_argSize);
          FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
          );
          FW_ASSERT(_argSize == sizeof(Ref::DataRequest),_argSize,sizeof(Ref::DataRequest));
        }
#endif      
        _status = args.deserialize(val);
        FW_ASSERT(
            _status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_status)
        );

        this->logIn_ACTIVITY_HI_CLEAgg_REQUEST_COMPLETED(val);

        break;

      }

      case CLEAggComponentBase::EVENTID_CLEAGG_THROTTLE_CLEARED: 
      {

#if FW_AMPCS_COMPATIBLE
        // For AMPCS, decode zero arguments
        Fw::SerializeStatus _zero_status = Fw::FW_SERIALIZE_OK;
        U8 _noArgs;
        _zero_status = args.deserialize(_noArgs);
        FW_ASSERT(
            _zero_status == Fw::FW_SERIALIZE_OK,
            static_cast<AssertArg>(_zero_status)
        );
#endif    
        this->logIn_ACTIVITY_HI_CLEAgg_THROTTLE_CLEARED();

        break;

      }

      default: {
        FW_ASSERT(0, id);
        break;
      }

    }

  }

  void CLEAggTesterBase ::
    clearEvents(void)
  {
    this->eventsSize = 0;
    this->eventHistory_CLEAgg_SET_GYROX->clear();
    this->eventHistory_CLEAgg_SET_GYROY->clear();
    this->eventHistory_CLEAgg_SET_GYROZ->clear();
    this->eventHistory_CLEAgg_SET_RTC_TIME->clear();
    this->eventHistory_CLEAgg_REQUEST_COMPLETED->clear();
    this->eventsSize_CLEAgg_THROTTLE_CLEARED = 0;
  }

#if FW_ENABLE_TEXT_LOGGING

  // ----------------------------------------------------------------------
  // Text events 
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    textLogIn(
        const U32 id,
        Fw::Time &timeTag,
        const Fw::TextLogSeverity severity,
        const Fw::TextLogString &text
    )
  {
    TextLogEntry e = { id, timeTag, severity, text };
    textLogHistory->push_back(e);
  }

  void CLEAggTesterBase ::
    printTextLogHistoryEntry(
        const TextLogEntry& e,
        FILE* file
    )
  {
    const char *severityString = "UNKNOWN";
    switch (e.severity) {
      case Fw::LOG_FATAL:
        severityString = "FATAL";
        break;
      case Fw::LOG_WARNING_HI:
        severityString = "WARNING_HI";
        break;
      case Fw::LOG_WARNING_LO:
        severityString = "WARNING_LO";
        break;
      case Fw::LOG_COMMAND:
        severityString = "COMMAND";
        break;
      case Fw::LOG_ACTIVITY_HI:
        severityString = "ACTIVITY_HI";
        break;
      case Fw::LOG_ACTIVITY_LO:
        severityString = "ACTIVITY_LO";
        break;
      case Fw::LOG_DIAGNOSTIC:
       severityString = "DIAGNOSTIC";
        break;
      default:
        severityString = "SEVERITY ERROR";
        break;
    }

    fprintf(
        file,
        "EVENT: (%d) (%d:%d,%d) %s: %s\n",
        e.id,
        const_cast<TextLogEntry&>(e).timeTag.getTimeBase(),
        const_cast<TextLogEntry&>(e).timeTag.getSeconds(),
        const_cast<TextLogEntry&>(e).timeTag.getUSeconds(),
        severityString,
        e.text.toChar()
    );

  }

  void CLEAggTesterBase ::
    printTextLogHistory(FILE *file) 
  {
    for (U32 i = 0; i < this->textLogHistory->size(); ++i) {
      this->printTextLogHistoryEntry(
          this->textLogHistory->at(i), 
          file
      );
    }
  }

#endif

  // ----------------------------------------------------------------------
  // Event: CLEAgg_SET_GYROX 
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    logIn_ACTIVITY_HI_CLEAgg_SET_GYROX(
        F32 val
    )
  {
    EventEntry_CLEAgg_SET_GYROX e = {
      val
    };
    eventHistory_CLEAgg_SET_GYROX->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_SET_GYROY 
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    logIn_ACTIVITY_HI_CLEAgg_SET_GYROY(
        F32 val
    )
  {
    EventEntry_CLEAgg_SET_GYROY e = {
      val
    };
    eventHistory_CLEAgg_SET_GYROY->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_SET_GYROZ 
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    logIn_ACTIVITY_HI_CLEAgg_SET_GYROZ(
        F32 val
    )
  {
    EventEntry_CLEAgg_SET_GYROZ e = {
      val
    };
    eventHistory_CLEAgg_SET_GYROZ->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_SET_RTC_TIME 
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    logIn_ACTIVITY_HI_CLEAgg_SET_RTC_TIME(
        F32 val
    )
  {
    EventEntry_CLEAgg_SET_RTC_TIME e = {
      val
    };
    eventHistory_CLEAgg_SET_RTC_TIME->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_REQUEST_COMPLETED 
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    logIn_ACTIVITY_HI_CLEAgg_REQUEST_COMPLETED(
        Ref::DataRequest val
    )
  {
    EventEntry_CLEAgg_REQUEST_COMPLETED e = {
      val
    };
    eventHistory_CLEAgg_REQUEST_COMPLETED->push_back(e);
    ++this->eventsSize;
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_THROTTLE_CLEARED 
  // ----------------------------------------------------------------------

  void CLEAggTesterBase ::
    logIn_ACTIVITY_HI_CLEAgg_THROTTLE_CLEARED(
        void
    )
  {
    ++this->eventsSize_CLEAgg_THROTTLE_CLEARED;
    ++this->eventsSize;
  }

} // end namespace Ref
