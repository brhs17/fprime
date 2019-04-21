// ======================================================================
// \title  CLEAgg/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for CLEAgg component Google Test harness base class
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

#include "GTestBase.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction and destruction
  // ----------------------------------------------------------------------

  CLEAggGTestBase ::
    CLEAggGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) : 
        CLEAggTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  CLEAggGTestBase ::
    ~CLEAggGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // Commands
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertCmdResponse_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ((unsigned long) size, this->cmdResponseHistory->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of command response history\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->cmdResponseHistory->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertCmdResponse(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        const Fw::CommandResponse response
    )
    const
  {
    ASSERT_LT(index, this->cmdResponseHistory->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into command response history\n"
      << "  Expected: Less than size of command response history (" 
      << this->cmdResponseHistory->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const CmdResponse& e = this->cmdResponseHistory->at(index);
    ASSERT_EQ(opCode, e.opCode)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Opcode at index "
      << index
      << " in command response history\n"
      << "  Expected: " << opCode << "\n"
      << "  Actual:   " << e.opCode << "\n";
    ASSERT_EQ(cmdSeq, e.cmdSeq)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Command sequence number at index "
      << index
      << " in command response history\n"
      << "  Expected: " << cmdSeq << "\n"
      << "  Actual:   " << e.cmdSeq << "\n";
    ASSERT_EQ(response, e.response)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Command response at index "
      << index
      << " in command resopnse history\n"
      << "  Expected: " << response << "\n"
      << "  Actual:   " << e.response << "\n";
  }

  // ----------------------------------------------------------------------
  // Telemetry
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->tlmSize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all telemetry histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: CLEAgg_DATA_REQUEST
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_DATA_REQUEST_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_CLEAgg_DATA_REQUEST->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel CLEAgg_DATA_REQUEST\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_CLEAgg_DATA_REQUEST->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_DATA_REQUEST(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const Ref::DataRequest& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_CLEAgg_DATA_REQUEST->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel CLEAgg_DATA_REQUEST\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_CLEAgg_DATA_REQUEST->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_CLEAgg_DATA_REQUEST& e =
      this->tlmHistory_CLEAgg_DATA_REQUEST->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel CLEAgg_DATA_REQUEST\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: CLEAgg_GYROXS
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROXS_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_CLEAgg_GYROXS->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel CLEAgg_GYROXS\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_CLEAgg_GYROXS->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROXS(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const U32& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_CLEAgg_GYROXS->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel CLEAgg_GYROXS\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_CLEAgg_GYROXS->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_CLEAgg_GYROXS& e =
      this->tlmHistory_CLEAgg_GYROXS->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel CLEAgg_GYROXS\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: CLEAgg_GYROYS
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROYS_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_CLEAgg_GYROYS->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel CLEAgg_GYROYS\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_CLEAgg_GYROYS->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROYS(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const U32& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_CLEAgg_GYROYS->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel CLEAgg_GYROYS\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_CLEAgg_GYROYS->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_CLEAgg_GYROYS& e =
      this->tlmHistory_CLEAgg_GYROYS->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel CLEAgg_GYROYS\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: CLEAgg_GYROZS
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROZS_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_CLEAgg_GYROZS->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel CLEAgg_GYROZS\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_CLEAgg_GYROZS->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROZS(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const U32& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_CLEAgg_GYROZS->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel CLEAgg_GYROZS\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_CLEAgg_GYROZS->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_CLEAgg_GYROZS& e =
      this->tlmHistory_CLEAgg_GYROZS->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel CLEAgg_GYROZS\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: CLEAgg_RTC_TIMES
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_RTC_TIMES_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_CLEAgg_RTC_TIMES->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel CLEAgg_RTC_TIMES\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_CLEAgg_RTC_TIMES->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_RTC_TIMES(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const U32& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_CLEAgg_RTC_TIMES->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel CLEAgg_RTC_TIMES\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_CLEAgg_RTC_TIMES->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_CLEAgg_RTC_TIMES& e =
      this->tlmHistory_CLEAgg_RTC_TIMES->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel CLEAgg_RTC_TIMES\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: CLEAgg_GYROX
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROX_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_CLEAgg_GYROX->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel CLEAgg_GYROX\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_CLEAgg_GYROX->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROX(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_CLEAgg_GYROX->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel CLEAgg_GYROX\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_CLEAgg_GYROX->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_CLEAgg_GYROX& e =
      this->tlmHistory_CLEAgg_GYROX->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel CLEAgg_GYROX\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: CLEAgg_GYROY
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROY_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_CLEAgg_GYROY->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel CLEAgg_GYROY\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_CLEAgg_GYROY->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROY(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_CLEAgg_GYROY->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel CLEAgg_GYROY\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_CLEAgg_GYROY->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_CLEAgg_GYROY& e =
      this->tlmHistory_CLEAgg_GYROY->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel CLEAgg_GYROY\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: CLEAgg_GYROZ
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROZ_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_CLEAgg_GYROZ->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel CLEAgg_GYROZ\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_CLEAgg_GYROZ->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_GYROZ(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_CLEAgg_GYROZ->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel CLEAgg_GYROZ\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_CLEAgg_GYROZ->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_CLEAgg_GYROZ& e =
      this->tlmHistory_CLEAgg_GYROZ->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel CLEAgg_GYROZ\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: CLEAgg_RTC_TIME
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_RTC_TIME_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_CLEAgg_RTC_TIME->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel CLEAgg_RTC_TIME\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_CLEAgg_RTC_TIME->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertTlm_CLEAgg_RTC_TIME(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_CLEAgg_RTC_TIME->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel CLEAgg_RTC_TIME\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_CLEAgg_RTC_TIME->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_CLEAgg_RTC_TIME& e =
      this->tlmHistory_CLEAgg_RTC_TIME->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel CLEAgg_RTC_TIME\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertEvents_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventsSize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all event histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventsSize << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_SET_GYROX
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_SET_GYROX_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_CLEAgg_SET_GYROX->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event CLEAgg_SET_GYROX\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_CLEAgg_SET_GYROX->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_SET_GYROX(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32 val
    ) const
  {
    ASSERT_GT(this->eventHistory_CLEAgg_SET_GYROX->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event CLEAgg_SET_GYROX\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_CLEAgg_SET_GYROX->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_CLEAgg_SET_GYROX& e =
      this->eventHistory_CLEAgg_SET_GYROX->at(index);
    ASSERT_EQ(val, e.val)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument val at index "
      << index
      << " in history of event CLEAgg_SET_GYROX\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.val << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_SET_GYROY
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_SET_GYROY_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_CLEAgg_SET_GYROY->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event CLEAgg_SET_GYROY\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_CLEAgg_SET_GYROY->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_SET_GYROY(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32 val
    ) const
  {
    ASSERT_GT(this->eventHistory_CLEAgg_SET_GYROY->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event CLEAgg_SET_GYROY\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_CLEAgg_SET_GYROY->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_CLEAgg_SET_GYROY& e =
      this->eventHistory_CLEAgg_SET_GYROY->at(index);
    ASSERT_EQ(val, e.val)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument val at index "
      << index
      << " in history of event CLEAgg_SET_GYROY\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.val << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_SET_GYROZ
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_SET_GYROZ_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_CLEAgg_SET_GYROZ->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event CLEAgg_SET_GYROZ\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_CLEAgg_SET_GYROZ->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_SET_GYROZ(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32 val
    ) const
  {
    ASSERT_GT(this->eventHistory_CLEAgg_SET_GYROZ->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event CLEAgg_SET_GYROZ\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_CLEAgg_SET_GYROZ->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_CLEAgg_SET_GYROZ& e =
      this->eventHistory_CLEAgg_SET_GYROZ->at(index);
    ASSERT_EQ(val, e.val)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument val at index "
      << index
      << " in history of event CLEAgg_SET_GYROZ\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.val << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_SET_RTC_TIME
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_SET_RTC_TIME_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_CLEAgg_SET_RTC_TIME->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event CLEAgg_SET_RTC_TIME\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_CLEAgg_SET_RTC_TIME->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_SET_RTC_TIME(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32 val
    ) const
  {
    ASSERT_GT(this->eventHistory_CLEAgg_SET_RTC_TIME->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event CLEAgg_SET_RTC_TIME\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_CLEAgg_SET_RTC_TIME->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_CLEAgg_SET_RTC_TIME& e =
      this->eventHistory_CLEAgg_SET_RTC_TIME->at(index);
    ASSERT_EQ(val, e.val)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument val at index "
      << index
      << " in history of event CLEAgg_SET_RTC_TIME\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.val << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_REQUEST_COMPLETED
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_REQUEST_COMPLETED_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_CLEAgg_REQUEST_COMPLETED->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event CLEAgg_REQUEST_COMPLETED\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_CLEAgg_REQUEST_COMPLETED->size() << "\n";
  }

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_REQUEST_COMPLETED(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const Ref::DataRequest val
    ) const
  {
    ASSERT_GT(this->eventHistory_CLEAgg_REQUEST_COMPLETED->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event CLEAgg_REQUEST_COMPLETED\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_CLEAgg_REQUEST_COMPLETED->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_CLEAgg_REQUEST_COMPLETED& e =
      this->eventHistory_CLEAgg_REQUEST_COMPLETED->at(index);
    ASSERT_EQ(val, e.val)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument val at index "
      << index
      << " in history of event CLEAgg_REQUEST_COMPLETED\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.val << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: CLEAgg_THROTTLE_CLEARED
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertEvents_CLEAgg_THROTTLE_CLEARED_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventsSize_CLEAgg_THROTTLE_CLEARED)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event CLEAgg_THROTTLE_CLEARED\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventsSize_CLEAgg_THROTTLE_CLEARED << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assertFromPortHistory_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistorySize)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Total size of all from port histories\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistorySize << "\n";
  }

  // ----------------------------------------------------------------------
  // From port: ResponseOut
  // ----------------------------------------------------------------------

  void CLEAggGTestBase ::
    assert_from_ResponseOut_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_ResponseOut->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_ResponseOut\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_ResponseOut->size() << "\n";
  }

} // end namespace Ref
