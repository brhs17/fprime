// ====================================================================== 
// \title  CLEMOpsImpl.cpp
// \author bhs
// \brief  cpp file for CLEMOps component implementation class
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


#include <Ref/CLEMOps/CLEMOpsComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction 
  // ----------------------------------------------------------------------

  CLEMOpsComponentImpl ::
#if FW_OBJECT_NAMES == 1
    CLEMOpsComponentImpl(
        const char *const compName
    ) :
      CLEMOpsComponentBase(compName)
#else
    CLEMOpsImpl(void)
#endif
  {

  }

  void CLEMOpsComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    ) 
  {
    CLEMOpsComponentBase::init(queueDepth, instance);
  }

  CLEMOpsComponentImpl ::
    ~CLEMOpsComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void CLEMOpsComponentImpl ::
    dataResult_handler(
        const NATIVE_INT_TYPE portNum,
        F32 result
    )
  {
	this->tlmWrite_OPS_Result(result);
	this->log_ACTIVITY_HI_OPS_Result(result);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations 
  // ----------------------------------------------------------------------

  void CLEMOpsComponentImpl ::
    OPS_Get_Data_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        DataRequest data
    )
  {
    	dataTlm dTlm;
	MathOpEv dEv;
	DataRequestPortZ dPort;
    	switch(data){
		case GyroX:
		dTlm=GyroX_TLM;
		dEv=GyroX_EV;
		dPort=OPS_GyroX;
		break;
		
		case GyroY:
		dTlm=GyroY_TLM;
		dEv=GyroY_EV;
		dPort=OPS_GyroY;
		break;
		
		case GyroZ:
		dTlm=GyroZ_TLM;
		dEv=GyroZ_EV;
		dPort=OPS_GyroZ;
		break;

		case RTCTime:
		dTlm=RTCTime_TLM;
		dEv=RTCTime_EV;
		dPort=OPS_RTCTime;
		break;
		
		default:
		FW_ASSERT(0,data);
		break;
	}
	
	this->tlmWrite_OPS_TLM(dTlm);
	this->log_ACTIVITY_LO_OPS_CMD_RECV(dEv);
	this->dataRequest_out(0,dPort);
	this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
