// ======================================================================
// \title  CLEAgg/test/ut/GTestBase.hpp
// \author Auto-generated
// \brief  hpp file for CLEAgg component Google Test harness base class
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

#ifndef CLEAgg_GTEST_BASE_HPP
#define CLEAgg_GTEST_BASE_HPP

#include "TesterBase.hpp"
#include "gtest/gtest.h"

// ----------------------------------------------------------------------
// Macros for command history assertions
// ----------------------------------------------------------------------

#define ASSERT_CMD_RESPONSE_SIZE(size) \
  this->assertCmdResponse_size(__FILE__, __LINE__, size)

#define ASSERT_CMD_RESPONSE(index, opCode, cmdSeq, response) \
  this->assertCmdResponse(__FILE__, __LINE__, index, opCode, cmdSeq, response)

// ----------------------------------------------------------------------
// Macros for telemetry history assertions
// ----------------------------------------------------------------------

#define ASSERT_TLM_SIZE(size) \
  this->assertTlm_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_DATA_REQUEST_SIZE(size) \
  this->assertTlm_CLEAgg_DATA_REQUEST_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_DATA_REQUEST(index, value) \
  this->assertTlm_CLEAgg_DATA_REQUEST(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_CLEAgg_GYROXS_SIZE(size) \
  this->assertTlm_CLEAgg_GYROXS_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_GYROXS(index, value) \
  this->assertTlm_CLEAgg_GYROXS(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_CLEAgg_GYROYS_SIZE(size) \
  this->assertTlm_CLEAgg_GYROYS_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_GYROYS(index, value) \
  this->assertTlm_CLEAgg_GYROYS(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_CLEAgg_GYROZS_SIZE(size) \
  this->assertTlm_CLEAgg_GYROZS_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_GYROZS(index, value) \
  this->assertTlm_CLEAgg_GYROZS(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_CLEAgg_RTC_TIMES_SIZE(size) \
  this->assertTlm_CLEAgg_RTC_TIMES_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_RTC_TIMES(index, value) \
  this->assertTlm_CLEAgg_RTC_TIMES(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_CLEAgg_GYROX_SIZE(size) \
  this->assertTlm_CLEAgg_GYROX_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_GYROX(index, value) \
  this->assertTlm_CLEAgg_GYROX(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_CLEAgg_GYROY_SIZE(size) \
  this->assertTlm_CLEAgg_GYROY_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_GYROY(index, value) \
  this->assertTlm_CLEAgg_GYROY(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_CLEAgg_GYROZ_SIZE(size) \
  this->assertTlm_CLEAgg_GYROZ_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_GYROZ(index, value) \
  this->assertTlm_CLEAgg_GYROZ(__FILE__, __LINE__, index, value)

#define ASSERT_TLM_CLEAgg_RTC_TIME_SIZE(size) \
  this->assertTlm_CLEAgg_RTC_TIME_size(__FILE__, __LINE__, size)

#define ASSERT_TLM_CLEAgg_RTC_TIME(index, value) \
  this->assertTlm_CLEAgg_RTC_TIME(__FILE__, __LINE__, index, value)

// ----------------------------------------------------------------------
// Macros for event history assertions 
// ----------------------------------------------------------------------

#define ASSERT_EVENTS_SIZE(size) \
  this->assertEvents_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_CLEAgg_SET_GYROX_SIZE(size) \
  this->assertEvents_CLEAgg_SET_GYROX_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_CLEAgg_SET_GYROX(index, _val) \
  this->assertEvents_CLEAgg_SET_GYROX(__FILE__, __LINE__, index, _val)

#define ASSERT_EVENTS_CLEAgg_SET_GYROY_SIZE(size) \
  this->assertEvents_CLEAgg_SET_GYROY_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_CLEAgg_SET_GYROY(index, _val) \
  this->assertEvents_CLEAgg_SET_GYROY(__FILE__, __LINE__, index, _val)

#define ASSERT_EVENTS_CLEAgg_SET_GYROZ_SIZE(size) \
  this->assertEvents_CLEAgg_SET_GYROZ_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_CLEAgg_SET_GYROZ(index, _val) \
  this->assertEvents_CLEAgg_SET_GYROZ(__FILE__, __LINE__, index, _val)

#define ASSERT_EVENTS_CLEAgg_SET_RTC_TIME_SIZE(size) \
  this->assertEvents_CLEAgg_SET_RTC_TIME_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_CLEAgg_SET_RTC_TIME(index, _val) \
  this->assertEvents_CLEAgg_SET_RTC_TIME(__FILE__, __LINE__, index, _val)

#define ASSERT_EVENTS_CLEAgg_REQUEST_COMPLETED_SIZE(size) \
  this->assertEvents_CLEAgg_REQUEST_COMPLETED_size(__FILE__, __LINE__, size)

#define ASSERT_EVENTS_CLEAgg_REQUEST_COMPLETED(index, _val) \
  this->assertEvents_CLEAgg_REQUEST_COMPLETED(__FILE__, __LINE__, index, _val)

#define ASSERT_EVENTS_CLEAgg_THROTTLE_CLEARED_SIZE(size) \
  this->assertEvents_CLEAgg_THROTTLE_CLEARED_size(__FILE__, __LINE__, size)

// ----------------------------------------------------------------------
// Macros for typed user from port history assertions
// ----------------------------------------------------------------------

#define ASSERT_FROM_PORT_HISTORY_SIZE(size) \
  this->assertFromPortHistory_size(__FILE__, __LINE__, size)

#define ASSERT_from_ResponseOut_SIZE(size) \
  this->assert_from_ResponseOut_size(__FILE__, __LINE__, size)

#define ASSERT_from_ResponseOut(index, _result) \
  { \
    ASSERT_GT(this->fromPortHistory_ResponseOut->size(), static_cast<U32>(index)) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Index into history of from_ResponseOut\n" \
    << "  Expected: Less than size of history (" \
    << this->fromPortHistory_ResponseOut->size() << ")\n" \
    << "  Actual:   " << index << "\n"; \
    const FromPortEntry_ResponseOut& _e = \
      this->fromPortHistory_ResponseOut->at(index); \
    ASSERT_EQ(_result, _e.result) \
    << "\n" \
    << "  File:     " << __FILE__ << "\n" \
    << "  Line:     " << __LINE__ << "\n" \
    << "  Value:    Value of argument result at index " \
    << index \
    << " in history of from_ResponseOut\n" \
    << "  Expected: " << _result << "\n" \
    << "  Actual:   " << _e.result << "\n"; \
  }

namespace Ref {

  //! \class CLEAggGTestBase
  //! \brief Auto-generated base class for CLEAgg component Google Test harness
  //!
  class CLEAggGTestBase :
    public CLEAggTesterBase
  {

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object CLEAggGTestBase
      //!
      CLEAggGTestBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object CLEAggGTestBase
      //!
      virtual ~CLEAggGTestBase(void);

    protected:

      // ----------------------------------------------------------------------
      // Commands
      // ----------------------------------------------------------------------

      //! Assert size of command response history
      //!
      void assertCmdResponse_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      //! Assert command response in history at index
      //!
      void assertCmdResponse(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CommandResponse response /*!< The command response*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Telemetry
      // ----------------------------------------------------------------------

      //! Assert size of telemetry history
      //!
      void assertTlm_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_DATA_REQUEST
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_CLEAgg_DATA_REQUEST_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_CLEAgg_DATA_REQUEST(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const Ref::DataRequest& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROXS
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_CLEAgg_GYROXS_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_CLEAgg_GYROXS(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const U32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROYS
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_CLEAgg_GYROYS_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_CLEAgg_GYROYS(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const U32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROZS
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_CLEAgg_GYROZS_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_CLEAgg_GYROZS(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const U32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_RTC_TIMES
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_CLEAgg_RTC_TIMES_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_CLEAgg_RTC_TIMES(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const U32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROX
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_CLEAgg_GYROX_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_CLEAgg_GYROX(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROY
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_CLEAgg_GYROY_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_CLEAgg_GYROY(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROZ
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_CLEAgg_GYROZ_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_CLEAgg_GYROZ(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_RTC_TIME
      // ----------------------------------------------------------------------

      //! Assert telemetry value in history at index
      //!
      void assertTlm_CLEAgg_RTC_TIME_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertTlm_CLEAgg_RTC_TIME(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32& val /*!< The channel value*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Events
      // ----------------------------------------------------------------------

      void assertEvents_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_SET_GYROX
      // ----------------------------------------------------------------------

      void assertEvents_CLEAgg_SET_GYROX_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_CLEAgg_SET_GYROX(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32 val 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_SET_GYROY
      // ----------------------------------------------------------------------

      void assertEvents_CLEAgg_SET_GYROY_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_CLEAgg_SET_GYROY(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32 val 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_SET_GYROZ
      // ----------------------------------------------------------------------

      void assertEvents_CLEAgg_SET_GYROZ_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_CLEAgg_SET_GYROZ(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32 val 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_SET_RTC_TIME
      // ----------------------------------------------------------------------

      void assertEvents_CLEAgg_SET_RTC_TIME_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_CLEAgg_SET_RTC_TIME(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const F32 val 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_REQUEST_COMPLETED
      // ----------------------------------------------------------------------

      void assertEvents_CLEAgg_REQUEST_COMPLETED_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

      void assertEvents_CLEAgg_REQUEST_COMPLETED(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 index, /*!< The index*/
          const Ref::DataRequest val 
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_THROTTLE_CLEARED
      // ----------------------------------------------------------------------

      void assertEvents_CLEAgg_THROTTLE_CLEARED_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From ports 
      // ----------------------------------------------------------------------

      void assertFromPortHistory_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

    protected:

      // ----------------------------------------------------------------------
      // From port: ResponseOut 
      // ----------------------------------------------------------------------

      void assert_from_ResponseOut_size(
          const char *const __callSiteFileName, /*!< The name of the file containing the call site*/
          const U32 __callSiteLineNumber, /*!< The line number of the call site*/
          const U32 size /*!< The asserted size*/
      ) const;

  };

} // end namespace Ref

#endif
