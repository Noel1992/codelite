#ifndef LLDB_ENUMS_H
#define LLDB_ENUMS_H

// defines the various reasons why the debugger
// was inerrupted / stopped
enum eInterruptReason {
    kInterruptReasonNone,
    kInterruptReasonApplyBreakpoints,
    kInterruptReasonDeleteAllBreakpoints,
    kInterruptReasonDeleteBreakpoint,
};

// the various network LLDBReply type
enum eReplyType {
    kReplyTypeInvalid,
    kReplyTypeDebuggerStartedSuccessfully,
    kReplyTypeDebuggerStopped,
    kReplyTypeDebuggerStoppedOnFirstEntry,
    kReplyTypeDebuggerExited,
    kReplyTypeDebuggerRunning,
    kReplyTypeBacktraceReceived,
    kReplyTypeAllBreakpointsDeleted,
    kReplyTypeBreakpointsUpdated,
    kReplyTypeLocalsUpdated,
    kReplyTypeVariableExpanded,
    kReplyTypeExprEvaluated,
};

// LLDBCommand types
enum eCommandType {
    kCommandInvalid = -1,
    kCommandStart,
    kCommandRun,
    kCommandStop,
    kCommandApplyBreakpoints,
    kCommandDeleteBreakpoint,
    kCommandDeleteAllBreakpoints,
    kCommandContinue,
    kCommandNext,
    kCommandStepIn,
    kCommandStepOut,
    kCommandInterrupt,
    kCommandGetLocals,
    kCommandExpandVariable,
    kCommandSelectFrame,
    kCommandSelectThread,
    kCommandEvalExpression,
    kCommandDebugCoreFile,
};

enum eLLDBOptions {
    kLLDBOptionRaiseCodeLite = 0x00000001,
};

enum eLLDBDebugSessionType {
    kDebugSessionTypeNormal,
    kDebugSessionTypeCore,
    kDebugSessionTypeAttach,
};
#endif
