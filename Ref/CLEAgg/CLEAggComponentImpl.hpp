// ====================================================================== 
// \title  CLEAggImpl.hpp
// \author bhs
// \brief  hpp file for CLEAgg component implementation class
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

#ifndef CLEAgg_HPP
#define CLEAgg_HPP

#include "Ref/CLEAgg/CLEAggComponentAc.hpp"

namespace Ref {

  class CLEAggComponentImpl :
    public CLEAggComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object CLEAgg
      //!
      CLEAggComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object CLEAgg
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object CLEAgg
      //!
      ~CLEAggComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for RequestIn
      //!
      void RequestIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          DataRequestPortZ data /*!< Possible data types to be requested*/
      );

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations 
      // ----------------------------------------------------------------------

      //! Implementation for CLEAgg_SET_GYROX command handler
      //! 
      void CLEAgg_SET_GYROX_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 val 
      );

      //! Implementation for CLEAgg_SET_GYROY command handler
      //! 
      void CLEAgg_SET_GYROY_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 val 
      );

      //! Implementation for CLEAgg_SET_GYROZ command handler
      //! 
      void CLEAgg_SET_GYROZ_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 val 
      );

      //! Implementation for CLEAgg_SET_RTC_TIME command handler
      //! 
      void CLEAgg_SET_RTC_TIME_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 val 
      );

      //! Implementation for CLEAgg_CLEAR_EVENT_THROTTLE command handler
      //! 
      void CLEAgg_CLEAR_EVENT_THROTTLE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );
	F32 ops_gyroX;
	F32 ops_gyroY;
	F32 ops_gyroZ;
	F32 ops_RTCTime;

	U32 ops_gyroXs;
	U32 ops_gyroYs;
	U32 ops_gyroZs;
	F32 ops_RTCTimes;
	


    };

} // end namespace Ref

#endif
