// ====================================================================== 
// \title  CLEMOpsImpl.hpp
// \author bhs
// \brief  hpp file for CLEMOps component implementation class
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

#ifndef CLEMOps_HPP
#define CLEMOps_HPP

#include "Ref/CLEMOps/CLEMOpsComponentAc.hpp"

namespace Ref {

  class CLEMOpsComponentImpl :
    public CLEMOpsComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object CLEMOps
      //!
      CLEMOpsComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object CLEMOps
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object CLEMOps
      //!
      ~CLEMOpsComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for dataResult
      //!
      void dataResult_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 result 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations 
      // ----------------------------------------------------------------------

      //! Implementation for Ops_Get_Data command handler
      //! 
      void Ops_Get_Data_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          options data 
      );


    };

} // end namespace Ref

#endif
