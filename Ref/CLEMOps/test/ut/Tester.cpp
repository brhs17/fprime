// ====================================================================== 
// \title  CLEMOps.hpp
// \author bhs
// \brief  cpp file for CLEMOps test harness implementation class
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

#include "Tester.hpp"

#define INSTANCE 0
#define MAX_HISTORY_SIZE 10
#define QUEUE_DEPTH 10

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction and destruction 
  // ----------------------------------------------------------------------

  Tester ::
    Tester(void) : 
#if FW_OBJECT_NAMES == 1
      CLEMOpsGTestBase("Tester", MAX_HISTORY_SIZE),
      component("CLEMOps")
#else
      CLEMOpsGTestBase(MAX_HISTORY_SIZE),
      component()
#endif
  {
    this->initComponents();
    this->connectPorts();
  }

  Tester ::
    ~Tester(void) 
  {
    
  }

  // ----------------------------------------------------------------------
  // Tests 
  // ----------------------------------------------------------------------

void Tester ::
testGyroXCommand(void) 
{
	this->sendCmd_OPS_Get_Data(0,10,CLEMOpsComponentBase::GyroX);
	this->component.doDispatch();
	ASSERT_FROM_PORT_HISTORY_SIZE(1);
	ASSERT_from_dataRequest_SIZE(1);
	ASSERT_from_dataRequest(0,OPS_GyroX);
	ASSERT_TLM_SIZE(3);
	ASSERT_TLM_OPS_TLM_SIZE(1);
	ASSERT_TLM_OPS_TLM(0,CLEMOpsComponentBase::GyroX_TLM);
	ASSERT_EVENTS_SIZE(1);
	ASSERT_EVENTS_OPS_CMD_RECV_SIZE(1);
	ASSERT_EVENTS_OPS_CMD_RECV(0,CLEMOpsComponentBase::GyroX_EV);
	ASSERT_CMD_RESPONSE_SIZE(1);
	ASSERT_CMD_RESPONSE(0,CLEMOpsComponentBase::OPCODE_OPS_GET_DATA,10,Fw::COMMAND_OK);

	this->clearHistory();
	this->invoke_to_dataResult(0,10.0);
	this->component.doDispatch();
	ASSERT_TLM_SIZE(1);
	ASSERT_TLM_OPS_Result_SIZE(1);
	ASSERT_TLM_OPS_Result(0,10.0);
	ASSERT_EVENTS_SIZE(1);
	ASSERT_EVENTS_OPS_Result_SIZE(1);
	ASSERT_EVENTS_OPS_Result(0,10.0);
}

void Tester ::
testGyroYCommand(void)
{
	this->sendCmd_OPS_Get_Data(0,10,CLEMOpsComponentBase::GyroY);
}

void Tester::
testGyroZCommand(void)
{
	this->sendCmd_OPS_Get_Data(0,10,CLEMOpsComponentBase::GyroZ);
}

void Tester::
testRTCTimeCommand(void)
{
	this->sendCmd_OPS_Get_Data(0,10,CLEMOpsComponentBase::RTCTime);
}


  // ----------------------------------------------------------------------
  // Handlers for typed from ports
  // ----------------------------------------------------------------------

  void Tester ::
    from_dataRequest_handler(
        const NATIVE_INT_TYPE portNum,
        DataRequestPortZ data
    )
  {
    this->pushFromPortEntry_dataRequest(data);
  }

  // ----------------------------------------------------------------------
  // Helper methods 
  // ----------------------------------------------------------------------

  void Tester ::
    connectPorts(void) 
  {

    // dataResult
    this->connect_to_dataResult(
        0,
        this->component.get_dataResult_InputPort(0)
    );

    // CmdDisp
    this->connect_to_CmdDisp(
        0,
        this->component.get_CmdDisp_InputPort(0)
    );

    // dataRequest
    this->component.set_dataRequest_OutputPort(
        0, 
        this->get_from_dataRequest(0)
    );

    // CmdStatus
    this->component.set_CmdStatus_OutputPort(
        0, 
        this->get_from_CmdStatus(0)
    );

    // CmdReg
    this->component.set_CmdReg_OutputPort(
        0, 
        this->get_from_CmdReg(0)
    );

    // Tlm
    this->component.set_Tlm_OutputPort(
        0, 
        this->get_from_Tlm(0)
    );

    // Time
    this->component.set_Time_OutputPort(
        0, 
        this->get_from_Time(0)
    );

    // Log
    this->component.set_Log_OutputPort(
        0, 
        this->get_from_Log(0)
    );

    // LogText
    this->component.set_LogText_OutputPort(
        0, 
        this->get_from_LogText(0)
    );

  }

  void Tester ::
    initComponents(void) 
  {
    this->init();
    this->component.init(
        QUEUE_DEPTH, INSTANCE
    );
  }

} // end namespace Ref
