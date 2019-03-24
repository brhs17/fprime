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
    // TODO
  }

  void CLEAggComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
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
    // TODO
  }

  void CLEAggComponentImpl ::
    CLEAgg_SET_GYROY_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 val
    )
  {
    // TODO
  }

  void CLEAggComponentImpl ::
    CLEAgg_SET_GYROZ_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 val
    )
  {
    // TODO
  }

  void CLEAggComponentImpl ::
    CLEAgg_SET_RTC_TIME_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 val
    )
  {
    // TODO
  }

  void CLEAggComponentImpl ::
    CLEAgg_CLEAR_EVENT_THROTTLE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    // TODO
  }

} // end namespace Ref
