// ======================================================================
// \title  CLEAgg/test/ut/TesterBase.hpp
// \author Auto-generated
// \brief  hpp file for CLEAgg component test harness base class
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

#ifndef CLEAgg_TESTER_BASE_HPP
#define CLEAgg_TESTER_BASE_HPP

#include <Ref/CLEAgg/CLEAggComponentAc.hpp>
#include <Fw/Types/Assert.hpp>
#include <Fw/Comp/PassiveComponentBase.hpp>
#include <stdio.h>
#include <Fw/Port/InputSerializePort.hpp>

namespace Ref {

  //! \class CLEAggTesterBase
  //! \brief Auto-generated base class for CLEAgg component test harness
  //!
  class CLEAggTesterBase :
    public Fw::PassiveComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Initialization
      // ----------------------------------------------------------------------

      //! Initialize object CLEAggTesterBase
      //!
      virtual void init(
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

    public:

      // ----------------------------------------------------------------------
      // Connectors for 'to' ports
      // Connect these output ports to the input ports under test
      // ----------------------------------------------------------------------

      //! Connect RequestIn to to_RequestIn[portNum]
      //!
      void connect_to_RequestIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Ref::InputDataRequestPort *const RequestIn /*!< The port*/
      );

      //! Connect SchedIn to to_SchedIn[portNum]
      //!
      void connect_to_SchedIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Svc::InputSchedPort *const SchedIn /*!< The port*/
      );

      //! Connect CmdDisp to to_CmdDisp[portNum]
      //!
      void connect_to_CmdDisp(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::InputCmdPort *const CmdDisp /*!< The port*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for 'from' ports
      // Connect these input ports to the output ports under test
      // ----------------------------------------------------------------------

      //! Get the port that receives input from ResponseOut
      //!
      //! \return from_ResponseOut[portNum]
      //!
      Ref::InputDataResultPort* get_from_ResponseOut(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from CmdStatus
      //!
      //! \return from_CmdStatus[portNum]
      //!
      Fw::InputCmdResponsePort* get_from_CmdStatus(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from CmdReg
      //!
      //! \return from_CmdReg[portNum]
      //!
      Fw::InputCmdRegPort* get_from_CmdReg(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Tlm
      //!
      //! \return from_Tlm[portNum]
      //!
      Fw::InputTlmPort* get_from_Tlm(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Time
      //!
      //! \return from_Time[portNum]
      //!
      Fw::InputTimePort* get_from_Time(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Get the port that receives input from Log
      //!
      //! \return from_Log[portNum]
      //!
      Fw::InputLogPort* get_from_Log(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the port that receives input from LogText
      //!
      //! \return from_LogText[portNum]
      //!
      Fw::InputLogTextPort* get_from_LogText(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );
#endif

    protected:

      // ----------------------------------------------------------------------
      // Construction and destruction
      // ----------------------------------------------------------------------

      //! Construct object CLEAggTesterBase
      //!
      CLEAggTesterBase(
#if FW_OBJECT_NAMES == 1
          const char *const compName, /*!< The component name*/
          const U32 maxHistorySize /*!< The maximum size of each history*/
#else
          const U32 maxHistorySize /*!< The maximum size of each history*/
#endif
      );

      //! Destroy object CLEAggTesterBase
      //!
      virtual ~CLEAggTesterBase(void);

      // ----------------------------------------------------------------------
      // Test history
      // ----------------------------------------------------------------------

    protected:

      //! \class History
      //! \brief A history of port inputs
      //!
      template <typename T> class History {

        public:

          //! Create a History
          //!
          History(
              const U32 maxSize /*!< The maximum history size*/
          ) : 
              numEntries(0), 
              maxSize(maxSize) 
          { 
            this->entries = new T[maxSize];
          }

          //! Destroy a History
          //!
          ~History() {
            delete[] this->entries;
          }

          //! Clear the history
          //!
          void clear() { this->numEntries = 0; }

          //! Push an item onto the history
          //!
          void push_back(
              T entry /*!< The item*/
          ) {
            FW_ASSERT(this->numEntries < this->maxSize);
            entries[this->numEntries++] = entry;
          }

          //! Get an item at an index
          //!
          //! \return The item at index i
          //!
          T at(
              const U32 i /*!< The index*/
          ) const {
            FW_ASSERT(i < this->numEntries);
            return entries[i];
          }

          //! Get the number of entries in the history
          //!
          //! \return The number of entries in the history
          //!
          U32 size(void) const { return this->numEntries; }

        private:

          //! The number of entries in the history
          //!
          U32 numEntries;

          //! The maximum history size
          //!
          const U32 maxSize;

          //! The entries
          //!
          T *entries;

      };

      //! Clear all history
      //!
      void clearHistory(void);

    protected:

      // ----------------------------------------------------------------------
      // Handler prototypes for typed from ports
      // ----------------------------------------------------------------------

      //! Handler prototype for from_ResponseOut
      //!
      virtual void from_ResponseOut_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 result 
      ) = 0;

      //! Handler base function for from_ResponseOut
      //!
      void from_ResponseOut_handlerBase(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 result 
      );

    protected:

      // ----------------------------------------------------------------------
      // Histories for typed from ports
      // ----------------------------------------------------------------------

      //! Clear from port history
      //!
      void clearFromPortHistory(void);

      //! The total number of from port entries
      //!
      U32 fromPortHistorySize;

      //! Push an entry on the history for from_ResponseOut
      void pushFromPortEntry_ResponseOut(
          F32 result 
      );

      //! A history entry for from_ResponseOut
      //!
      typedef struct {
        F32 result;
      } FromPortEntry_ResponseOut;

      //! The history for from_ResponseOut
      //!
      History<FromPortEntry_ResponseOut> 
        *fromPortHistory_ResponseOut;

    protected:

      // ----------------------------------------------------------------------
      // Invocation functions for to ports
      // ----------------------------------------------------------------------

      //! Invoke the to port connected to RequestIn
      //!
      void invoke_to_RequestIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          DataRequestPortZ data /*!< Possible data types to be requested*/
      );

      //! Invoke the to port connected to SchedIn
      //!
      void invoke_to_SchedIn(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for port counts
      // ----------------------------------------------------------------------

      //! Get the number of to_RequestIn ports
      //!
      //! \return The number of to_RequestIn ports
      //!
      NATIVE_INT_TYPE getNum_to_RequestIn(void) const;

      //! Get the number of from_ResponseOut ports
      //!
      //! \return The number of from_ResponseOut ports
      //!
      NATIVE_INT_TYPE getNum_from_ResponseOut(void) const;

      //! Get the number of to_SchedIn ports
      //!
      //! \return The number of to_SchedIn ports
      //!
      NATIVE_INT_TYPE getNum_to_SchedIn(void) const;

      //! Get the number of to_CmdDisp ports
      //!
      //! \return The number of to_CmdDisp ports
      //!
      NATIVE_INT_TYPE getNum_to_CmdDisp(void) const;

      //! Get the number of from_CmdStatus ports
      //!
      //! \return The number of from_CmdStatus ports
      //!
      NATIVE_INT_TYPE getNum_from_CmdStatus(void) const;

      //! Get the number of from_CmdReg ports
      //!
      //! \return The number of from_CmdReg ports
      //!
      NATIVE_INT_TYPE getNum_from_CmdReg(void) const;

      //! Get the number of from_Tlm ports
      //!
      //! \return The number of from_Tlm ports
      //!
      NATIVE_INT_TYPE getNum_from_Tlm(void) const;

      //! Get the number of from_Time ports
      //!
      //! \return The number of from_Time ports
      //!
      NATIVE_INT_TYPE getNum_from_Time(void) const;

      //! Get the number of from_Log ports
      //!
      //! \return The number of from_Log ports
      //!
      NATIVE_INT_TYPE getNum_from_Log(void) const;

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Get the number of from_LogText ports
      //!
      //! \return The number of from_LogText ports
      //!
      NATIVE_INT_TYPE getNum_from_LogText(void) const;
#endif

    protected:

      // ----------------------------------------------------------------------
      // Connection status for to ports
      // ----------------------------------------------------------------------

      //! Check whether port is connected
      //!
      //! Whether to_RequestIn[portNum] is connected
      //!
      bool isConnected_to_RequestIn(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_SchedIn[portNum] is connected
      //!
      bool isConnected_to_SchedIn(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      //! Check whether port is connected
      //!
      //! Whether to_CmdDisp[portNum] is connected
      //!
      bool isConnected_to_CmdDisp(
          const NATIVE_INT_TYPE portNum /*!< The port number*/
      );

      // ----------------------------------------------------------------------
      // Functions for sending commands
      // ----------------------------------------------------------------------

    protected:
    
      // send command buffers directly - used for intentional command encoding errors
      void sendRawCmd(FwOpcodeType opcode, U32 cmdSeq, Fw::CmdArgBuffer& args); 

      //! Send a CLEAgg_SET_GYROX command
      //!
      void sendCmd_CLEAgg_SET_GYROX(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 val 
      );

      //! Send a CLEAgg_SET_GYROY command
      //!
      void sendCmd_CLEAgg_SET_GYROY(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 val 
      );

      //! Send a CLEAgg_SET_GYROZ command
      //!
      void sendCmd_CLEAgg_SET_GYROZ(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 val 
      );

      //! Send a CLEAgg_SET_RTC_TIME command
      //!
      void sendCmd_CLEAgg_SET_RTC_TIME(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 val 
      );

      //! Send a CLEAgg_CLEAR_EVENT_THROTTLE command
      //!
      void sendCmd_CLEAgg_CLEAR_EVENT_THROTTLE(
          const NATIVE_INT_TYPE instance, /*!< The instance number*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

    protected:

      // ----------------------------------------------------------------------
      // Command response handling
      // ----------------------------------------------------------------------

      //! Handle a command response
      //!
      virtual void cmdResponseIn(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          const Fw::CommandResponse response /*!< The command response*/
      );

      //! A type representing a command response
      //!
      typedef struct {
        FwOpcodeType opCode;
        U32 cmdSeq;
        Fw::CommandResponse response;
      } CmdResponse;

      //! The command response history
      //!
      History<CmdResponse> *cmdResponseHistory;

    protected:

      // ----------------------------------------------------------------------
      // Event dispatch
      // ----------------------------------------------------------------------

      //! Dispatch an event
      //!
      void dispatchEvents(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::LogSeverity severity, /*!< The severity*/
          Fw::LogBuffer& args /*!< The serialized arguments*/
      );

      //! Clear event history
      //!
      void clearEvents(void);

      //! The total number of events seen
      //!
      U32 eventsSize;

#if FW_ENABLE_TEXT_LOGGING

    protected:

      // ----------------------------------------------------------------------
      // Text events
      // ----------------------------------------------------------------------

      //! Handle a text event
      //!
      virtual void textLogIn(
          const FwEventIdType id, /*!< The event ID*/
          Fw::Time& timeTag, /*!< The time*/
          const Fw::TextLogSeverity severity, /*!< The severity*/
          const Fw::TextLogString& text /*!< The event string*/
      );

      //! A history entry for the text log
      //!
      typedef struct {
        U32 id;
        Fw::Time timeTag;
        Fw::TextLogSeverity severity;
        Fw::TextLogString text;
      } TextLogEntry;

      //! The history of text log events
      //!
      History<TextLogEntry> *textLogHistory;

      //! Print a text log history entry
      //!
      static void printTextLogHistoryEntry(
          const TextLogEntry& e,
          FILE* file
      );

      //! Print the text log history
      //!
      void printTextLogHistory(FILE *const file);

#endif

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_SET_GYROX
      // ----------------------------------------------------------------------

      //! Handle event CLEAgg_SET_GYROX
      //!
      virtual void logIn_ACTIVITY_HI_CLEAgg_SET_GYROX(
          F32 val 
      );

      //! A history entry for event CLEAgg_SET_GYROX
      //!
      typedef struct {
        F32 val;
      } EventEntry_CLEAgg_SET_GYROX;

      //! The history of CLEAgg_SET_GYROX events
      //!
      History<EventEntry_CLEAgg_SET_GYROX> 
        *eventHistory_CLEAgg_SET_GYROX;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_SET_GYROY
      // ----------------------------------------------------------------------

      //! Handle event CLEAgg_SET_GYROY
      //!
      virtual void logIn_ACTIVITY_HI_CLEAgg_SET_GYROY(
          F32 val 
      );

      //! A history entry for event CLEAgg_SET_GYROY
      //!
      typedef struct {
        F32 val;
      } EventEntry_CLEAgg_SET_GYROY;

      //! The history of CLEAgg_SET_GYROY events
      //!
      History<EventEntry_CLEAgg_SET_GYROY> 
        *eventHistory_CLEAgg_SET_GYROY;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_SET_GYROZ
      // ----------------------------------------------------------------------

      //! Handle event CLEAgg_SET_GYROZ
      //!
      virtual void logIn_ACTIVITY_HI_CLEAgg_SET_GYROZ(
          F32 val 
      );

      //! A history entry for event CLEAgg_SET_GYROZ
      //!
      typedef struct {
        F32 val;
      } EventEntry_CLEAgg_SET_GYROZ;

      //! The history of CLEAgg_SET_GYROZ events
      //!
      History<EventEntry_CLEAgg_SET_GYROZ> 
        *eventHistory_CLEAgg_SET_GYROZ;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_SET_RTC_TIME
      // ----------------------------------------------------------------------

      //! Handle event CLEAgg_SET_RTC_TIME
      //!
      virtual void logIn_ACTIVITY_HI_CLEAgg_SET_RTC_TIME(
          F32 val 
      );

      //! A history entry for event CLEAgg_SET_RTC_TIME
      //!
      typedef struct {
        F32 val;
      } EventEntry_CLEAgg_SET_RTC_TIME;

      //! The history of CLEAgg_SET_RTC_TIME events
      //!
      History<EventEntry_CLEAgg_SET_RTC_TIME> 
        *eventHistory_CLEAgg_SET_RTC_TIME;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_REQUEST_COMPLETED
      // ----------------------------------------------------------------------

      //! Handle event CLEAgg_REQUEST_COMPLETED
      //!
      virtual void logIn_ACTIVITY_HI_CLEAgg_REQUEST_COMPLETED(
          Ref::DataRequest val 
      );

      //! A history entry for event CLEAgg_REQUEST_COMPLETED
      //!
      typedef struct {
        Ref::DataRequest val;
      } EventEntry_CLEAgg_REQUEST_COMPLETED;

      //! The history of CLEAgg_REQUEST_COMPLETED events
      //!
      History<EventEntry_CLEAgg_REQUEST_COMPLETED> 
        *eventHistory_CLEAgg_REQUEST_COMPLETED;

    protected:

      // ----------------------------------------------------------------------
      // Event: CLEAgg_THROTTLE_CLEARED
      // ----------------------------------------------------------------------

      //! Handle event CLEAgg_THROTTLE_CLEARED
      //!
      virtual void logIn_ACTIVITY_HI_CLEAgg_THROTTLE_CLEARED(
          void
      );

      //! Size of history for event CLEAgg_THROTTLE_CLEARED
      //!
      U32 eventsSize_CLEAgg_THROTTLE_CLEARED;

    protected:

      // ----------------------------------------------------------------------
      // Telemetry dispatch
      // ----------------------------------------------------------------------

      //! Dispatch telemetry
      //!
      void dispatchTlm(
          const FwChanIdType id, /*!< The channel ID*/
          const Fw::Time& timeTag, /*!< The time*/
          Fw::TlmBuffer& val /*!< The channel value*/
      );

      //! Clear telemetry history
      //!
      void clearTlm(void);

      //! The total number of telemetry inputs seen
      //!
      U32 tlmSize;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_DATA_REQUEST
      // ----------------------------------------------------------------------

      //! Handle channel CLEAgg_DATA_REQUEST
      //!
      virtual void tlmInput_CLEAgg_DATA_REQUEST(
          const Fw::Time& timeTag, /*!< The time*/
          const Ref::DataRequest& val /*!< The channel value*/
      );

      //! A telemetry entry for channel CLEAgg_DATA_REQUEST
      //!
      typedef struct {
        Fw::Time timeTag;
        Ref::DataRequest arg;
      } TlmEntry_CLEAgg_DATA_REQUEST;

      //! The history of CLEAgg_DATA_REQUEST values
      //!
      History<TlmEntry_CLEAgg_DATA_REQUEST> 
        *tlmHistory_CLEAgg_DATA_REQUEST;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROXS
      // ----------------------------------------------------------------------

      //! Handle channel CLEAgg_GYROXS
      //!
      virtual void tlmInput_CLEAgg_GYROXS(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel CLEAgg_GYROXS
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_CLEAgg_GYROXS;

      //! The history of CLEAgg_GYROXS values
      //!
      History<TlmEntry_CLEAgg_GYROXS> 
        *tlmHistory_CLEAgg_GYROXS;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROYS
      // ----------------------------------------------------------------------

      //! Handle channel CLEAgg_GYROYS
      //!
      virtual void tlmInput_CLEAgg_GYROYS(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel CLEAgg_GYROYS
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_CLEAgg_GYROYS;

      //! The history of CLEAgg_GYROYS values
      //!
      History<TlmEntry_CLEAgg_GYROYS> 
        *tlmHistory_CLEAgg_GYROYS;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROZS
      // ----------------------------------------------------------------------

      //! Handle channel CLEAgg_GYROZS
      //!
      virtual void tlmInput_CLEAgg_GYROZS(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel CLEAgg_GYROZS
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_CLEAgg_GYROZS;

      //! The history of CLEAgg_GYROZS values
      //!
      History<TlmEntry_CLEAgg_GYROZS> 
        *tlmHistory_CLEAgg_GYROZS;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_RTC_TIMES
      // ----------------------------------------------------------------------

      //! Handle channel CLEAgg_RTC_TIMES
      //!
      virtual void tlmInput_CLEAgg_RTC_TIMES(
          const Fw::Time& timeTag, /*!< The time*/
          const U32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel CLEAgg_RTC_TIMES
      //!
      typedef struct {
        Fw::Time timeTag;
        U32 arg;
      } TlmEntry_CLEAgg_RTC_TIMES;

      //! The history of CLEAgg_RTC_TIMES values
      //!
      History<TlmEntry_CLEAgg_RTC_TIMES> 
        *tlmHistory_CLEAgg_RTC_TIMES;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROX
      // ----------------------------------------------------------------------

      //! Handle channel CLEAgg_GYROX
      //!
      virtual void tlmInput_CLEAgg_GYROX(
          const Fw::Time& timeTag, /*!< The time*/
          const F32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel CLEAgg_GYROX
      //!
      typedef struct {
        Fw::Time timeTag;
        F32 arg;
      } TlmEntry_CLEAgg_GYROX;

      //! The history of CLEAgg_GYROX values
      //!
      History<TlmEntry_CLEAgg_GYROX> 
        *tlmHistory_CLEAgg_GYROX;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROY
      // ----------------------------------------------------------------------

      //! Handle channel CLEAgg_GYROY
      //!
      virtual void tlmInput_CLEAgg_GYROY(
          const Fw::Time& timeTag, /*!< The time*/
          const F32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel CLEAgg_GYROY
      //!
      typedef struct {
        Fw::Time timeTag;
        F32 arg;
      } TlmEntry_CLEAgg_GYROY;

      //! The history of CLEAgg_GYROY values
      //!
      History<TlmEntry_CLEAgg_GYROY> 
        *tlmHistory_CLEAgg_GYROY;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_GYROZ
      // ----------------------------------------------------------------------

      //! Handle channel CLEAgg_GYROZ
      //!
      virtual void tlmInput_CLEAgg_GYROZ(
          const Fw::Time& timeTag, /*!< The time*/
          const F32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel CLEAgg_GYROZ
      //!
      typedef struct {
        Fw::Time timeTag;
        F32 arg;
      } TlmEntry_CLEAgg_GYROZ;

      //! The history of CLEAgg_GYROZ values
      //!
      History<TlmEntry_CLEAgg_GYROZ> 
        *tlmHistory_CLEAgg_GYROZ;

    protected:

      // ----------------------------------------------------------------------
      // Channel: CLEAgg_RTC_TIME
      // ----------------------------------------------------------------------

      //! Handle channel CLEAgg_RTC_TIME
      //!
      virtual void tlmInput_CLEAgg_RTC_TIME(
          const Fw::Time& timeTag, /*!< The time*/
          const F32& val /*!< The channel value*/
      );

      //! A telemetry entry for channel CLEAgg_RTC_TIME
      //!
      typedef struct {
        Fw::Time timeTag;
        F32 arg;
      } TlmEntry_CLEAgg_RTC_TIME;

      //! The history of CLEAgg_RTC_TIME values
      //!
      History<TlmEntry_CLEAgg_RTC_TIME> 
        *tlmHistory_CLEAgg_RTC_TIME;

    protected:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Set the test time for events and telemetry
      //!
      void setTestTime(
          const Fw::Time& timeTag /*!< The time*/
      );

    private:

      // ----------------------------------------------------------------------
      // To ports
      // ----------------------------------------------------------------------

      //! To port connected to RequestIn
      //!
      Ref::OutputDataRequestPort m_to_RequestIn[1];

      //! To port connected to SchedIn
      //!
      Svc::OutputSchedPort m_to_SchedIn[1];

      //! To port connected to CmdDisp
      //!
      Fw::OutputCmdPort m_to_CmdDisp[1];

    private:

      // ----------------------------------------------------------------------
      // From ports
      // ----------------------------------------------------------------------

      //! From port connected to ResponseOut
      //!
      Ref::InputDataResultPort m_from_ResponseOut[1];

      //! From port connected to CmdStatus
      //!
      Fw::InputCmdResponsePort m_from_CmdStatus[1];

      //! From port connected to CmdReg
      //!
      Fw::InputCmdRegPort m_from_CmdReg[1];

      //! From port connected to Tlm
      //!
      Fw::InputTlmPort m_from_Tlm[1];

      //! From port connected to Time
      //!
      Fw::InputTimePort m_from_Time[1];

      //! From port connected to Log
      //!
      Fw::InputLogPort m_from_Log[1];

#if FW_ENABLE_TEXT_LOGGING == 1
      //! From port connected to LogText
      //!
      Fw::InputLogTextPort m_from_LogText[1];
#endif

    private:

      // ----------------------------------------------------------------------
      // Static functions for output ports
      // ----------------------------------------------------------------------

      //! Static function for port from_ResponseOut
      //!
      static void from_ResponseOut_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 result 
      );

      //! Static function for port from_CmdStatus
      //!
      static void from_CmdStatus_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode, /*!< Command Op Code*/
          U32 cmdSeq, /*!< Command Sequence*/
          Fw::CommandResponse response /*!< The command response argument*/
      );

      //! Static function for port from_CmdReg
      //!
      static void from_CmdReg_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwOpcodeType opCode /*!< Command Op Code*/
      );

      //! Static function for port from_Tlm
      //!
      static void from_Tlm_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwChanIdType id, /*!< Telemetry Channel ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TlmBuffer &val /*!< Buffer containing serialized telemetry value*/
      );

      //! Static function for port from_Time
      //!
      static void from_Time_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          Fw::Time &time /*!< The U32 cmd argument*/
      );

      //! Static function for port from_Log
      //!
      static void from_Log_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::LogSeverity severity, /*!< The severity argument*/
          Fw::LogBuffer &args /*!< Buffer containing serialized log entry*/
      );

#if FW_ENABLE_TEXT_LOGGING == 1
      //! Static function for port from_LogText
      //!
      static void from_LogText_static(
          Fw::PassiveComponentBase *const callComp, /*!< The component instance*/
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          FwEventIdType id, /*!< Log ID*/
          Fw::Time &timeTag, /*!< Time Tag*/
          Fw::TextLogSeverity severity, /*!< The severity argument*/
          Fw::TextLogString &text /*!< Text of log message*/
      );
#endif

    private:

      // ----------------------------------------------------------------------
      // Test time
      // ----------------------------------------------------------------------

      //! Test time stamp
      //!
      Fw::Time m_testTime;

  };

} // end namespace Ref

#endif
