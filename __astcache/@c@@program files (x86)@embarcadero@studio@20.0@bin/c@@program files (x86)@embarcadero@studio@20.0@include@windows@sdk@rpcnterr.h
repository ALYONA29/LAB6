#pragma option push -b -a8 -pc -A- -w-pun /*P_O_Push*/
#include <winapifamily.h>

/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    rpcnterr.h

Abstract:

    Rpc Error Codes from the compiler and runtime

--*/

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef __RPCNTERR_H__
#define __RPCNTERR_H__

#if _MSC_VER >= 1200
#pragma warning(push)
#pragma warning(disable:4668) // #if not_defined treated as #if 0
#endif

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#if !defined(_KRPCENV_)

#define RPC_S_OK                          ERROR_SUCCESS
#define RPC_S_INVALID_ARG                 ERROR_INVALID_PARAMETER
#define RPC_S_OUT_OF_MEMORY               ERROR_OUTOFMEMORY
#define RPC_S_OUT_OF_THREADS              ERROR_MAX_THRDS_REACHED
#define RPC_S_INVALID_LEVEL               ERROR_INVALID_PARAMETER
#define RPC_S_BUFFER_TOO_SMALL            ERROR_INSUFFICIENT_BUFFER
#define RPC_S_INVALID_SECURITY_DESC       ERROR_INVALID_SECURITY_DESCR
#define RPC_S_ACCESS_DENIED               ERROR_ACCESS_DENIED
#define RPC_S_SERVER_OUT_OF_MEMORY        ERROR_NOT_ENOUGH_SERVER_MEMORY
#define RPC_S_ASYNC_CALL_PENDING          ERROR_IO_PENDING
#define RPC_S_UNKNOWN_PRINCIPAL           ERROR_NONE_MAPPED
#define RPC_S_TIMEOUT                     ERROR_TIMEOUT
#if (NTDDI_VERSION >= NTDDI_VISTA)
#define RPC_S_NOT_ENOUGH_QUOTA            ERROR_NOT_ENOUGH_QUOTA
#endif // (NTDDI_VERSION >= NTDDI_VISTA)

#define RPC_X_NO_MEMORY                   RPC_S_OUT_OF_MEMORY
#define RPC_X_INVALID_BOUND               RPC_S_INVALID_BOUND
#define RPC_X_INVALID_TAG                 RPC_S_INVALID_TAG
#define RPC_X_ENUM_VALUE_TOO_LARGE        RPC_X_ENUM_VALUE_OUT_OF_RANGE
#define RPC_X_SS_CONTEXT_MISMATCH         ERROR_INVALID_HANDLE
#define RPC_X_INVALID_BUFFER              ERROR_INVALID_USER_BUFFER
#define RPC_X_PIPE_APP_MEMORY             ERROR_OUTOFMEMORY
#define RPC_X_INVALID_PIPE_OPERATION      RPC_X_WRONG_PIPE_ORDER

#else   // _KRPCENV_

#define RPC_S_OK                            STATUS_SUCCESS

#if defined(RPC_S_INVALID_STRING_BINDING)
#undef RPC_S_INVALID_STRING_BINDING
#endif
#define RPC_S_INVALID_STRING_BINDING        RPC_NT_INVALID_STRING_BINDING

#if defined(RPC_S_WRONG_KIND_OF_BINDING)
#undef RPC_S_WRONG_KIND_OF_BINDING
#endif
#define RPC_S_WRONG_KIND_OF_BINDING         RPC_NT_WRONG_KIND_OF_BINDING

#if defined(RPC_S_INVALID_BINDING)
#undef RPC_S_INVALID_BINDING
#endif
#define RPC_S_INVALID_BINDING               RPC_NT_INVALID_BINDING

#if defined(RPC_S_PROTSEQ_NOT_SUPPORTED)
#undef RPC_S_PROTSEQ_NOT_SUPPORTED
#endif
#define RPC_S_PROTSEQ_NOT_SUPPORTED         RPC_NT_PROTSEQ_NOT_SUPPORTED

#if defined(RPC_S_INVALID_RPC_PROTSEQ)
#undef RPC_S_INVALID_RPC_PROTSEQ
#endif
#define RPC_S_INVALID_RPC_PROTSEQ           RPC_NT_INVALID_RPC_PROTSEQ

#if defined(RPC_S_INVALID_STRING_UUID)
#undef RPC_S_INVALID_STRING_UUID
#endif
#define RPC_S_INVALID_STRING_UUID           RPC_NT_INVALID_STRING_UUID

#if defined(RPC_S_INVALID_ENDPOINT_FORMAT)
#undef RPC_S_INVALID_ENDPOINT_FORMAT
#endif
#define RPC_S_INVALID_ENDPOINT_FORMAT       RPC_NT_INVALID_ENDPOINT_FORMAT

#if defined(RPC_S_INVALID_NET_ADDR)
#undef RPC_S_INVALID_NET_ADDR
#endif
#define RPC_S_INVALID_NET_ADDR              RPC_NT_INVALID_NET_ADDR

#if defined(RPC_S_NO_ENDPOINT_FOUND)
#undef RPC_S_NO_ENDPOINT_FOUND
#endif
#define RPC_S_NO_ENDPOINT_FOUND             RPC_NT_NO_ENDPOINT_FOUND

#if defined(RPC_S_INVALID_TIMEOUT)
#undef RPC_S_INVALID_TIMEOUT
#endif
#define RPC_S_INVALID_TIMEOUT               RPC_NT_INVALID_TIMEOUT

#if defined(RPC_S_OBJECT_NOT_FOUND)
#undef RPC_S_OBJECT_NOT_FOUND
#endif
#define RPC_S_OBJECT_NOT_FOUND              RPC_NT_OBJECT_NOT_FOUND

#if defined(RPC_S_ALREADY_REGISTERED)
#undef RPC_S_ALREADY_REGISTERED
#endif
#define RPC_S_ALREADY_REGISTERED            RPC_NT_ALREADY_REGISTERED

#if defined(RPC_S_TYPE_ALREADY_REGISTERED)
#undef RPC_S_TYPE_ALREADY_REGISTERED
#endif
#define RPC_S_TYPE_ALREADY_REGISTERED       RPC_NT_TYPE_ALREADY_REGISTERED

#if defined(RPC_S_ALREADY_LISTENING)
#undef RPC_S_ALREADY_LISTENING
#endif
#define RPC_S_ALREADY_LISTENING             RPC_NT_ALREADY_LISTENING

#if defined(RPC_S_NO_PROTSEQS_REGISTERED)
#undef RPC_S_NO_PROTSEQS_REGISTERED
#endif
#define RPC_S_NO_PROTSEQS_REGISTERED        RPC_NT_NO_PROTSEQS_REGISTERED

#if defined(RPC_S_NOT_LISTENING)
#undef RPC_S_NOT_LISTENING
#endif
#define RPC_S_NOT_LISTENING                 RPC_NT_NOT_LISTENING

#if defined(RPC_S_UNKNOWN_MGR_TYPE)
#undef RPC_S_UNKNOWN_MGR_TYPE
#endif
#define RPC_S_UNKNOWN_MGR_TYPE              RPC_NT_UNKNOWN_MGR_TYPE

#if defined(RPC_S_UNKNOWN_IF)
#undef RPC_S_UNKNOWN_IF
#endif
#define RPC_S_UNKNOWN_IF                    RPC_NT_UNKNOWN_IF

#if defined(RPC_S_NO_BINDINGS)
#undef RPC_S_NO_BINDINGS
#endif
#define RPC_S_NO_BINDINGS                   RPC_NT_NO_BINDINGS

#if defined(RPC_S_NO_MORE_BINDINGS)
#undef RPC_S_NO_MORE_BINDINGS
#endif
#define RPC_S_NO_MORE_BINDINGS              RPC_NT_NO_MORE_BINDINGS

#if defined(RPC_S_NO_PROTSEQS)
#undef RPC_S_NO_PROTSEQS
#endif
#define RPC_S_NO_PROTSEQS                   RPC_NT_NO_PROTSEQS

#if defined(RPC_S_CANT_CREATE_ENDPOINT)
#undef RPC_S_CANT_CREATE_ENDPOINT
#endif
#define RPC_S_CANT_CREATE_ENDPOINT          RPC_NT_CANT_CREATE_ENDPOINT

#if defined(RPC_S_OUT_OF_RESOURCES)
#undef RPC_S_OUT_OF_RESOURCES
#endif
#define RPC_S_OUT_OF_RESOURCES              RPC_NT_OUT_OF_RESOURCES

#if defined(RPC_S_SERVER_UNAVAILABLE)
#undef RPC_S_SERVER_UNAVAILABLE
#endif
#define RPC_S_SERVER_UNAVAILABLE            RPC_NT_SERVER_UNAVAILABLE

#if defined(RPC_S_SERVER_TOO_BUSY)
#undef RPC_S_SERVER_TOO_BUSY
#endif
#define RPC_S_SERVER_TOO_BUSY               RPC_NT_SERVER_TOO_BUSY

#if defined(RPC_S_INVALID_NETWORK_OPTIONS)
#undef RPC_S_INVALID_NETWORK_OPTIONS
#endif
#define RPC_S_INVALID_NETWORK_OPTIONS       RPC_NT_INVALID_NETWORK_OPTIONS

#if defined(RPC_S_NO_CALL_ACTIVE)
#undef RPC_S_NO_CALL_ACTIVE
#endif
#define RPC_S_NO_CALL_ACTIVE                RPC_NT_NO_CALL_ACTIVE

#if defined(RPC_S_CALL_FAILED)
#undef RPC_S_CALL_FAILED
#endif
#define RPC_S_CALL_FAILED                   RPC_NT_CALL_FAILED

#if defined(RPC_S_CALL_CANCELLED)
#undef RPC_S_CALL_CANCELLED
#endif
#define RPC_S_CALL_CANCELLED                RPC_NT_CALL_CANCELLED

#if defined(RPC_S_CALL_FAILED_DNE)
#undef RPC_S_CALL_FAILED_DNE
#endif
#define RPC_S_CALL_FAILED_DNE               RPC_NT_CALL_FAILED_DNE

#if defined(RPC_S_PROTOCOL_ERROR)
#undef RPC_S_PROTOCOL_ERROR
#endif
#define RPC_S_PROTOCOL_ERROR                RPC_NT_PROTOCOL_ERROR

#if defined(RPC_S_UNSUPPORTED_TRANS_SYN)
#undef RPC_S_UNSUPPORTED_TRANS_SYN
#endif
#define RPC_S_UNSUPPORTED_TRANS_SYN         RPC_NT_UNSUPPORTED_TRANS_SYN

#if defined(RPC_S_SERVER_OUT_OF_MEMORY)
#undef RPC_S_SERVER_OUT_OF_MEMORY
#endif
#define RPC_S_SERVER_OUT_OF_MEMORY          STATUS_INSUFF_SERVER_RESOURCES

#if defined(RPC_S_UNSUPPORTED_TYPE)
#undef RPC_S_UNSUPPORTED_TYPE
#endif
#define RPC_S_UNSUPPORTED_TYPE              RPC_NT_UNSUPPORTED_TYPE

#if defined(RPC_S_INVALID_TAG)
#undef RPC_S_INVALID_TAG
#endif
#define RPC_S_INVALID_TAG                   RPC_NT_INVALID_TAG

#if defined(RPC_S_INVALID_BOUND)
#undef RPC_S_INVALID_BOUND
#endif
#define RPC_S_INVALID_BOUND                 RPC_NT_INVALID_BOUND

#if defined(RPC_S_NO_ENTRY_NAME)
#undef RPC_S_NO_ENTRY_NAME
#endif
#define RPC_S_NO_ENTRY_NAME                 RPC_NT_NO_ENTRY_NAME

#if defined(RPC_S_INVALID_NAME_SYNTAX)
#undef RPC_S_INVALID_NAME_SYNTAX
#endif
#define RPC_S_INVALID_NAME_SYNTAX           RPC_NT_INVALID_NAME_SYNTAX

#if defined(RPC_S_UNSUPPORTED_NAME_SYNTAX)
#undef RPC_S_UNSUPPORTED_NAME_SYNTAX
#endif
#define RPC_S_UNSUPPORTED_NAME_SYNTAX       RPC_NT_UNSUPPORTED_NAME_SYNTAX

#if defined(RPC_S_UUID_NO_ADDRESS)
#undef RPC_S_UUID_NO_ADDRESS
#endif
#define RPC_S_UUID_NO_ADDRESS               RPC_NT_UUID_NO_ADDRESS

#if defined(RPC_S_DUPLICATE_ENDPOINT)
#undef RPC_S_DUPLICATE_ENDPOINT
#endif
#define RPC_S_DUPLICATE_ENDPOINT            RPC_NT_DUPLICATE_ENDPOINT

#if defined(RPC_S_UNKNOWN_AUTHN_TYPE)
#undef RPC_S_UNKNOWN_AUTHN_TYPE
#endif
#define RPC_S_UNKNOWN_AUTHN_TYPE            RPC_NT_UNKNOWN_AUTHN_TYPE

#if defined(RPC_S_MAX_CALLS_TOO_SMALL)
#undef RPC_S_MAX_CALLS_TOO_SMALL
#endif
#define RPC_S_MAX_CALLS_TOO_SMALL           RPC_NT_MAX_CALLS_TOO_SMALL

#if defined(RPC_S_STRING_TOO_LONG)
#undef RPC_S_STRING_TOO_LONG
#endif
#define RPC_S_STRING_TOO_LONG               RPC_NT_STRING_TOO_LONG

#if defined(RPC_S_PROTSEQ_NOT_FOUND)
#undef RPC_S_PROTSEQ_NOT_FOUND
#endif
#define RPC_S_PROTSEQ_NOT_FOUND             RPC_NT_PROTSEQ_NOT_FOUND

#if defined(RPC_S_PROCNUM_OUT_OF_RANGE)
#undef RPC_S_PROCNUM_OUT_OF_RANGE
#endif
#define RPC_S_PROCNUM_OUT_OF_RANGE          RPC_NT_PROCNUM_OUT_OF_RANGE

#if defined(RPC_S_BINDING_HAS_NO_AUTH)
#undef RPC_S_BINDING_HAS_NO_AUTH
#endif
#define RPC_S_BINDING_HAS_NO_AUTH           RPC_NT_BINDING_HAS_NO_AUTH

#if defined(RPC_S_UNKNOWN_AUTHN_SERVICE)
#undef RPC_S_UNKNOWN_AUTHN_SERVICE
#endif
#define RPC_S_UNKNOWN_AUTHN_SERVICE         RPC_NT_UNKNOWN_AUTHN_SERVICE

#if defined(RPC_S_UNKNOWN_AUTHN_LEVEL)
#undef RPC_S_UNKNOWN_AUTHN_LEVEL
#endif
#define RPC_S_UNKNOWN_AUTHN_LEVEL           RPC_NT_UNKNOWN_AUTHN_LEVEL

#if defined(RPC_S_INVALID_AUTH_IDENTITY)
#undef RPC_S_INVALID_AUTH_IDENTITY
#endif
#define RPC_S_INVALID_AUTH_IDENTITY         RPC_NT_INVALID_AUTH_IDENTITY

#if defined(RPC_S_UNKNOWN_AUTHZ_SERVICE)
#undef RPC_S_UNKNOWN_AUTHZ_SERVICE
#endif
#define RPC_S_UNKNOWN_AUTHZ_SERVICE         RPC_NT_UNKNOWN_AUTHZ_SERVICE

#if defined(EPT_S_INVALID_ENTRY)
#undef EPT_S_INVALID_ENTRY
#endif
#define EPT_S_INVALID_ENTRY                 EPT_NT_INVALID_ENTRY

#if defined(EPT_S_CANT_PERFORM_OP)
#undef EPT_S_CANT_PERFORM_OP
#endif
#define EPT_S_CANT_PERFORM_OP               EPT_NT_CANT_PERFORM_OP

#if defined(EPT_S_NOT_REGISTERED)
#undef EPT_S_NOT_REGISTERED
#endif
#define EPT_S_NOT_REGISTERED                EPT_NT_NOT_REGISTERED

#if defined(RPC_S_NOTHING_TO_EXPORT)
#undef RPC_S_NOTHING_TO_EXPORT
#endif
#define RPC_S_NOTHING_TO_EXPORT             RPC_NT_NOTHING_TO_EXPORT

#if defined(RPC_S_INCOMPLETE_NAME)
#undef RPC_S_INCOMPLETE_NAME
#endif
#define RPC_S_INCOMPLETE_NAME               RPC_NT_INCOMPLETE_NAME

#if defined(RPC_S_INVALID_VERS_OPTION)
#undef RPC_S_INVALID_VERS_OPTION
#endif
#define RPC_S_INVALID_VERS_OPTION           RPC_NT_INVALID_VERS_OPTION

#if defined(RPC_S_NO_MORE_MEMBERS)
#undef RPC_S_NO_MORE_MEMBERS
#endif
#define RPC_S_NO_MORE_MEMBERS               RPC_NT_NO_MORE_MEMBERS

#if defined(RPC_S_NOT_ALL_OBJS_UNEXPORTED)
#undef RPC_S_NOT_ALL_OBJS_UNEXPORTED
#endif
#define RPC_S_NOT_ALL_OBJS_UNEXPORTED       RPC_NT_NOT_ALL_OBJS_UNEXPORTED

#if defined(RPC_S_INTERFACE_NOT_FOUND)
#undef RPC_S_INTERFACE_NOT_FOUND
#endif
#define RPC_S_INTERFACE_NOT_FOUND           RPC_NT_INTERFACE_NOT_FOUND

#if defined(RPC_S_ENTRY_ALREADY_EXISTS)
#undef RPC_S_ENTRY_ALREADY_EXISTS
#endif
#define RPC_S_ENTRY_ALREADY_EXISTS          RPC_NT_ENTRY_ALREADY_EXISTS

#if defined(RPC_S_ENTRY_NOT_FOUND)
#undef RPC_S_ENTRY_NOT_FOUND
#endif
#define RPC_S_ENTRY_NOT_FOUND               RPC_NT_ENTRY_NOT_FOUND

#if defined(RPC_S_NAME_SERVICE_UNAVAILABLE)
#undef RPC_S_NAME_SERVICE_UNAVAILABLE
#endif
#define RPC_S_NAME_SERVICE_UNAVAILABLE      RPC_NT_NAME_SERVICE_UNAVAILABLE

#if defined(RPC_S_INVALID_NAF_ID)
#undef RPC_S_INVALID_NAF_ID
#endif
#define RPC_S_INVALID_NAF_ID                RPC_NT_INVALID_NAF_ID

#if defined(RPC_S_CANNOT_SUPPORT)
#undef RPC_S_CANNOT_SUPPORT
#endif
#define RPC_S_CANNOT_SUPPORT                RPC_NT_CANNOT_SUPPORT

#if defined(RPC_S_NO_CONTEXT_AVAILABLE)
#undef RPC_S_NO_CONTEXT_AVAILABLE
#endif
#define RPC_S_NO_CONTEXT_AVAILABLE          RPC_NT_NO_CONTEXT_AVAILABLE

#if defined(RPC_S_INTERNAL_ERROR)
#undef RPC_S_INTERNAL_ERROR
#endif
#define RPC_S_INTERNAL_ERROR                RPC_NT_INTERNAL_ERROR

#if defined(RPC_S_ZERO_DIVIDE)
#undef RPC_S_ZERO_DIVIDE
#endif
#define RPC_S_ZERO_DIVIDE                   RPC_NT_ZERO_DIVIDE

#if defined(RPC_S_ADDRESS_ERROR)
#undef RPC_S_ADDRESS_ERROR
#endif
#define RPC_S_ADDRESS_ERROR                 RPC_NT_ADDRESS_ERROR

#if defined(RPC_S_FP_DIV_ZERO)
#undef RPC_S_FP_DIV_ZERO
#endif
#define RPC_S_FP_DIV_ZERO                   RPC_NT_FP_DIV_ZERO

#if defined(RPC_S_FP_UNDERFLOW)
#undef RPC_S_FP_UNDERFLOW
#endif
#define RPC_S_FP_UNDERFLOW                  RPC_NT_FP_UNDERFLOW

#if defined(RPC_S_FP_OVERFLOW)
#undef RPC_S_FP_OVERFLOW
#endif
#define RPC_S_FP_OVERFLOW                   RPC_NT_FP_OVERFLOW

#if defined(RPC_S_PROXY_ACCESS_DENIED)
#undef RPC_S_PROXY_ACCESS_DENIED
#endif
#define RPC_S_PROXY_ACCESS_DENIED           RPC_NT_PROXY_ACCESS_DENIED

#if defined(RPC_X_NO_MORE_ENTRIES)
#undef RPC_X_NO_MORE_ENTRIES
#endif
#define RPC_X_NO_MORE_ENTRIES               RPC_NT_NO_MORE_ENTRIES

#if defined(RPC_X_SS_CHAR_TRANS_OPEN_FAIL)
#undef RPC_X_SS_CHAR_TRANS_OPEN_FAIL
#endif
#define RPC_X_SS_CHAR_TRANS_OPEN_FAIL       RPC_NT_SS_CHAR_TRANS_OPEN_FAIL

#if defined(RPC_X_SS_CHAR_TRANS_SHORT_FILE)
#undef RPC_X_SS_CHAR_TRANS_SHORT_FILE
#endif
#define RPC_X_SS_CHAR_TRANS_SHORT_FILE      RPC_NT_SS_CHAR_TRANS_SHORT_FILE

#if defined(RPC_X_SS_IN_NULL_CONTEXT)
#undef RPC_X_SS_IN_NULL_CONTEXT
#endif
#define RPC_X_SS_IN_NULL_CONTEXT            RPC_NT_SS_IN_NULL_CONTEXT

#if defined(RPC_X_SS_CONTEXT_MISMATCH)
#undef RPC_X_SS_CONTEXT_MISMATCH
#endif
#define RPC_X_SS_CONTEXT_MISMATCH           RPC_NT_SS_CONTEXT_MISMATCH

#if defined(RPC_X_SS_CONTEXT_DAMAGED)
#undef RPC_X_SS_CONTEXT_DAMAGED
#endif
#define RPC_X_SS_CONTEXT_DAMAGED            RPC_NT_SS_CONTEXT_DAMAGED

#if defined(RPC_X_SS_HANDLES_MISMATCH)
#undef RPC_X_SS_HANDLES_MISMATCH
#endif
#define RPC_X_SS_HANDLES_MISMATCH           RPC_NT_SS_HANDLES_MISMATCH

#if defined(RPC_X_SS_CANNOT_GET_CALL_HANDLE)
#undef RPC_X_SS_CANNOT_GET_CALL_HANDLE
#endif
#define RPC_X_SS_CANNOT_GET_CALL_HANDLE     RPC_NT_SS_CANNOT_GET_CALL_HANDLE

#if defined(RPC_X_NULL_REF_POINTER)
#undef RPC_X_NULL_REF_POINTER
#endif
#define RPC_X_NULL_REF_POINTER              RPC_NT_NULL_REF_POINTER

#if defined(RPC_X_ENUM_VALUE_OUT_OF_RANGE)
#undef RPC_X_ENUM_VALUE_OUT_OF_RANGE
#endif
#define RPC_X_ENUM_VALUE_OUT_OF_RANGE       RPC_NT_ENUM_VALUE_OUT_OF_RANGE

#if defined(RPC_X_BYTE_COUNT_TOO_SMALL)
#undef RPC_X_BYTE_COUNT_TOO_SMALL
#endif
#define RPC_X_BYTE_COUNT_TOO_SMALL          RPC_NT_BYTE_COUNT_TOO_SMALL

#if defined(RPC_X_BAD_STUB_DATA)
#undef RPC_X_BAD_STUB_DATA
#endif
#define RPC_X_BAD_STUB_DATA                 RPC_NT_BAD_STUB_DATA

#if defined(RPC_S_CALL_IN_PROGRESS)
#undef RPC_S_CALL_IN_PROGRESS
#endif
#define RPC_S_CALL_IN_PROGRESS              RPC_NT_CALL_IN_PROGRESS

#if defined(RPC_S_GROUP_MEMBER_NOT_FOUND)
#undef RPC_S_GROUP_MEMBER_NOT_FOUND
#endif
#define RPC_S_GROUP_MEMBER_NOT_FOUND        RPC_NT_GROUP_MEMBER_NOT_FOUND

#if defined(EPT_S_CANT_CREATE)
#undef EPT_S_CANT_CREATE
#endif
#define EPT_S_CANT_CREATE                   EPT_NT_CANT_CREATE

#if defined(RPC_S_INVALID_OBJECT)
#undef RPC_S_INVALID_OBJECT
#endif
#define RPC_S_INVALID_OBJECT                RPC_NT_INVALID_OBJECT

#if defined(RPC_S_INVALID_ASYNC_HANDLE)
#undef RPC_S_INVALID_ASYNC_HANDLE
#endif
#define RPC_S_INVALID_ASYNC_HANDLE          RPC_NT_INVALID_ASYNC_HANDLE

#if defined(RPC_S_INVALID_ASYNC_CALL)
#undef RPC_S_INVALID_ASYNC_CALL
#endif
#define RPC_S_INVALID_ASYNC_CALL            RPC_NT_INVALID_ASYNC_CALL

#if defined(RPC_X_PIPE_CLOSED)
#undef RPC_X_PIPE_CLOSED
#endif
#define RPC_X_PIPE_CLOSED                   RPC_NT_PIPE_CLOSED

#if defined(RPC_X_PIPE_EMPTY)
#undef RPC_X_PIPE_EMPTY
#endif
#define RPC_X_PIPE_EMPTY                    RPC_NT_PIPE_EMPTY

#if defined(RPC_X_PIPE_DISCIPLINE_ERROR)
#undef RPC_X_PIPE_DISCIPLINE_ERROR
#endif
#define RPC_X_PIPE_DISCIPLINE_ERROR         RPC_NT_PIPE_DISCIPLINE_ERROR

#define RPC_S_INVALID_ARG                   STATUS_INVALID_PARAMETER
#define RPC_S_OUT_OF_MEMORY                 STATUS_NO_MEMORY
#define RPC_S_OUT_OF_THREADS                STATUS_NO_MEMORY
#define RPC_S_INVALID_LEVEL                 STATUS_INVALID_PARAMETER
#define RPC_S_BUFFER_TOO_SMALL              STATUS_BUFFER_TOO_SMALL
#define RPC_S_INVALID_SECURITY_DESC         STATUS_INVALID_SECURITY_DESCR
#define RPC_S_ACCESS_DENIED                 STATUS_ACCESS_DENIED
#define RPC_S_ASYNC_CALL_PENDING            STATUS_PENDING
#define RPC_S_UNKNOWN_PRINCIPAL             STATUS_NONE_MAPPED
#define RPC_S_NOT_ENOUGH_QUOTA              STATUS_QUOTA_EXCEEDED
#define RPC_X_NO_MEMORY                     STATUS_NO_MEMORY
#define RPC_X_INVALID_BOUND                 RPC_NT_INVALID_BOUND
#define RPC_X_INVALID_TAG                   RPC_NT_INVALID_TAG
#define RPC_X_ENUM_VALUE_TOO_LARGE          RPC_NT_ENUM_VALUE_OUT_OF_RANGE
#define RPC_X_SS_CONTEXT_MISMATCH           RPC_NT_SS_CONTEXT_MISMATCH
#define RPC_X_INVALID_BUFFER                STATUS_INVALID_BUFFER_SIZE
#define RPC_X_PIPE_APP_MEMORY               STATUS_NO_MEMORY

#endif  // _KRPCENV_

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

#endif /* __RPCNTERR_H__ */
#pragma option pop /*P_O_Pop*/
