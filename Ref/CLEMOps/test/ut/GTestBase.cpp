// ======================================================================
// \title  CLEMOps/test/ut/GTestBase.cpp
// \author Auto-generated
// \brief  cpp file for CLEMOps component Google Test harness base class
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

  CLEMOpsGTestBase ::
    CLEMOpsGTestBase(
#if FW_OBJECT_NAMES == 1
        const char *const compName,
        const U32 maxHistorySize
#else
        const U32 maxHistorySize
#endif
    ) : 
        CLEMOpsTesterBase (
#if FW_OBJECT_NAMES == 1
            compName,
#endif
            maxHistorySize
        )
  {

  }

  CLEMOpsGTestBase ::
    ~CLEMOpsGTestBase(void)
  {

  }

  // ----------------------------------------------------------------------
  // Commands
  // ----------------------------------------------------------------------

  void CLEMOpsGTestBase ::
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

  void CLEMOpsGTestBase ::
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

  void CLEMOpsGTestBase ::
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
  // Channel: OPS_TLM
  // ----------------------------------------------------------------------

  void CLEMOpsGTestBase ::
    assertTlm_OPS_TLM_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_OPS_TLM->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel OPS_TLM\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_OPS_TLM->size() << "\n";
  }

  void CLEMOpsGTestBase ::
    assertTlm_OPS_TLM(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const CLEMOpsComponentBase::dataTlm& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_OPS_TLM->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel OPS_TLM\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_OPS_TLM->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_OPS_TLM& e =
      this->tlmHistory_OPS_TLM->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel OPS_TLM\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Channel: OPS_Result
  // ----------------------------------------------------------------------

  void CLEMOpsGTestBase ::
    assertTlm_OPS_Result_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(this->tlmHistory_OPS_Result->size(), size)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for telemetry channel OPS_Result\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->tlmHistory_OPS_Result->size() << "\n";
  }

  void CLEMOpsGTestBase ::
    assertTlm_OPS_Result(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32& val
    )
    const
  {
    ASSERT_LT(index, this->tlmHistory_OPS_Result->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of telemetry channel OPS_Result\n"
      << "  Expected: Less than size of history (" 
      << this->tlmHistory_OPS_Result->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const TlmEntry_OPS_Result& e =
      this->tlmHistory_OPS_Result->at(index);
    ASSERT_EQ(val, e.arg)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value at index "
      << index
      << " on telmetry channel OPS_Result\n"
      << "  Expected: " << val << "\n"
      << "  Actual:   " << e.arg << "\n";
  }

  // ----------------------------------------------------------------------
  // Events
  // ----------------------------------------------------------------------

  void CLEMOpsGTestBase ::
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
  // Event: OPS_CMD_RECV
  // ----------------------------------------------------------------------

  void CLEMOpsGTestBase ::
    assertEvents_OPS_CMD_RECV_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_OPS_CMD_RECV->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event OPS_CMD_RECV\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_OPS_CMD_RECV->size() << "\n";
  }

  void CLEMOpsGTestBase ::
    assertEvents_OPS_CMD_RECV(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        CLEMOpsComponentBase::MathOpEv dataEv
    ) const
  {
    ASSERT_GT(this->eventHistory_OPS_CMD_RECV->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event OPS_CMD_RECV\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_OPS_CMD_RECV->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_OPS_CMD_RECV& e =
      this->eventHistory_OPS_CMD_RECV->at(index);
    ASSERT_EQ(dataEv, e.dataEv)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument dataEv at index "
      << index
      << " in history of event OPS_CMD_RECV\n"
      << "  Expected: " << dataEv << "\n"
      << "  Actual:   " << e.dataEv << "\n";
  }

  // ----------------------------------------------------------------------
  // Event: OPS_Result
  // ----------------------------------------------------------------------

  void CLEMOpsGTestBase ::
    assertEvents_OPS_Result_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->eventHistory_OPS_Result->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for event OPS_Result\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->eventHistory_OPS_Result->size() << "\n";
  }

  void CLEMOpsGTestBase ::
    assertEvents_OPS_Result(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 index,
        const F32 result
    ) const
  {
    ASSERT_GT(this->eventHistory_OPS_Result->size(), index)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Index into history of event OPS_Result\n"
      << "  Expected: Less than size of history (" 
      << this->eventHistory_OPS_Result->size() << ")\n"
      << "  Actual:   " << index << "\n";
    const EventEntry_OPS_Result& e =
      this->eventHistory_OPS_Result->at(index);
    ASSERT_EQ(result, e.result)
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Value of argument result at index "
      << index
      << " in history of event OPS_Result\n"
      << "  Expected: " << result << "\n"
      << "  Actual:   " << e.result << "\n";
  }

  // ----------------------------------------------------------------------
  // From ports
  // ----------------------------------------------------------------------

  void CLEMOpsGTestBase ::
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
  // From port: dataRequest
  // ----------------------------------------------------------------------

  void CLEMOpsGTestBase ::
    assert_from_dataRequest_size(
        const char *const __callSiteFileName,
        const U32 __callSiteLineNumber,
        const U32 size
    ) const
  {
    ASSERT_EQ(size, this->fromPortHistory_dataRequest->size())
      << "\n"
      << "  File:     " << __callSiteFileName << "\n"
      << "  Line:     " << __callSiteLineNumber << "\n"
      << "  Value:    Size of history for from_dataRequest\n"
      << "  Expected: " << size << "\n"
      << "  Actual:   " << this->fromPortHistory_dataRequest->size() << "\n";
  }

} // end namespace Ref
