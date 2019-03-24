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
    // TODO
  }

  // ----------------------------------------------------------------------
  // Command handler implementations 
  // ----------------------------------------------------------------------

  void CLEMOpsComponentImpl ::
    Ops_Get_Data_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        options data
    )
  {
    // TODO
  }

} // end namespace Ref
