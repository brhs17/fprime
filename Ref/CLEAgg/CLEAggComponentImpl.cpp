// ====================================================================== 
// \title  CLEAggImpl.cpp
// \author bhs
// \brief  cpp file for CLEAgg component implementation class
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


#include <Ref/CLEAgg/CLEAggComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction 
  // ----------------------------------------------------------------------

  CLEAggComponentImpl ::
#if FW_OBJECT_NAMES == 1
    CLEAggComponentImpl(
        const char *const compName
    ) :
      CLEAggComponentBase(compName)
#else
    CLEAggImpl(void)
#endif  
	,ops_gyroX(0.0) 
	,ops_gyroXs(0)
	,ops_gyroY(0.0) 
	,ops_gyroYs(0)
	,ops_gyroZ(0.0) 
	,ops_gyroZs(0)
	,ops_RTCTime(0.0) 
	,ops_RTCTimes(0)
  {
	
  }

  void CLEAggComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    ) 
  {
    CLEAggComponentBase::init(queueDepth, instance);
  }

  CLEAggComponentImpl ::
    ~CLEAggComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void CLEAggComponentImpl ::
    RequestIn_handler(
        const NATIVE_INT_TYPE portNum,
        DataRequestPortZ data
    )
  {
	Ref::DataRequest dr;
	F32 res = 0.0;
	switch(data){
		case OPS_GyroX:
			res = ops_gyroX;
			dr.settarget(GyroXSer);
			break;
		case OPS_GyroY:
			res = ops_gyroY;
			dr.settarget(GyroYSer);
			break;
		case OPS_GyroZ:
			res = ops_gyroZ;
			dr.settarget(GyroZSer);
			break;
		case OPS_RTCTime:
			res = ops_RTCTime;
			dr.settarget(RTCTimeSer);
			break;
		default:
			FW_ASSERT(0,data);
			break;
	}
	dr.setresult(res);
	this->log_ACTIVITY_HI_CLEAgg_REQUEST_COMPLETED(dr);
	this->tlmWrite_CLEAgg_DATA_REQUEST(dr);
	this->ResponseOut_out(0,res);
	
	
  }

  void CLEAggComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
	QueuedComponentBase::MsgDispatchStatus stat = QueuedComponentBase::MSG_DISPATCH_OK;
	while(stat != MSG_DISPATCH_EMPTY) {
		stat = this->doDispatch();
	}
  }

  // ----------------------------------------------------------------------
  // Command handler implementations 
  // ----------------------------------------------------------------------

  void CLEAggComponentImpl ::
    CLEAgg_SET_GYROX_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 val
    )
  {
	this->ops_gyroX = val;
	this->log_ACTIVITY_HI_CLEAgg_SET_GYROX(val);
	this->tlmWrite_CLEAgg_GYROX(val);
	this->tlmWrite_CLEAgg_GYROXS(++this->ops_gyroXs);
	this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void CLEAggComponentImpl ::
    CLEAgg_SET_GYROY_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 val
    )
  {
	this->ops_gyroY = val;
	this->log_ACTIVITY_HI_CLEAgg_SET_GYROY(val);
	this->tlmWrite_CLEAgg_GYROY(val);
	this->tlmWrite_CLEAgg_GYROYS(++this->ops_gyroYs);
	this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void CLEAggComponentImpl ::
    CLEAgg_SET_GYROZ_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 val
    )
  {
	this->ops_gyroZ = val;
	this->log_ACTIVITY_HI_CLEAgg_SET_GYROZ(val);
	this->tlmWrite_CLEAgg_GYROZ(val);
	this->tlmWrite_CLEAgg_GYROZS(++this->ops_gyroZs);
	this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void CLEAggComponentImpl ::
    CLEAgg_SET_RTC_TIME_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 val
    )
  {
	this->ops_RTCTime = val;
	this->log_ACTIVITY_HI_CLEAgg_SET_RTC_TIME(val);
	this->tlmWrite_CLEAgg_RTC_TIME(val);
	this->tlmWrite_CLEAgg_RTC_TIMES(++this->ops_RTCTimes);
	this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void CLEAggComponentImpl ::
    CLEAgg_CLEAR_EVENT_THROTTLE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
	this->log_ACTIVITY_HI_CLEAgg_SET_GYROX_ThrottleClear();
	this->log_ACTIVITY_HI_CLEAgg_SET_GYROY_ThrottleClear();
	this->log_ACTIVITY_HI_CLEAgg_SET_GYROZ_ThrottleClear();
	this->log_ACTIVITY_HI_CLEAgg_SET_RTC_TIME_ThrottleClear();
	this->log_ACTIVITY_HI_CLEAgg_THROTTLE_CLEARED();
	this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref
