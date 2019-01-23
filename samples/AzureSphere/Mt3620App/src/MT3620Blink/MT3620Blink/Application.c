﻿// This is MT3620Blink native code translated by IL2C, do not edit.

#include <MT3620Blink.h>
#include <MT3620Blink_internal.h>

#include <mscorlib.h>

#ifdef __cplusplus
extern "C" {
#endif

//////////////////////////////////////////////////////////////////////////////////
// [9] Type: MT3620Blink.Application

//////////////////////////////////////////////////////////////////////////////////
// [9-2] File scope prototypes:

//////////////////////////////////////////////////////////////////////////////////
// [2-3] Methods:

//////////////////////////////////////////////////////////////////////////////////
// [9-3] Static field instances:

//////////////////////////////////////////////////////////////////////////////////
// [9-4] Type: MT3620Blink.Application

///////////////////////////////////////
// [3] MT3620Blink.Application..ctor(MT3620Blink.Application this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application__ctor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_Application* stack0_0__;
} MT3620Blink_Application__ctor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application__ctor(MT3620Blink_Application* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack1_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application__ctor_EXECUTION_FRAME__ frame__ =
        { NULL, 1 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: ldarg.0                         : Application.cs(14) */
    frame__.stack0_0__ = this__;
    /* IL_0001: ldc.i4.0                        : Application.cs(14) */
    stack1_0__ = 0;
    /* IL_0002: call MT3620Blink.Interops.epoll_create1 : Application.cs(14) */
    stack1_0__ = MT3620Blink_Interops_epoll_create1(stack1_0__);
    /* IL_0007: call MT3620Blink.Descriptor..ctor : Application.cs(14) */
    MT3620Blink_Descriptor__ctor((MT3620Blink_Descriptor*)frame__.stack0_0__, stack1_0__);
    /* IL_000c: nop                             : Application.cs(14) */
    /* IL_000d: nop  */
    /* IL_000e: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Application.RegisterDescriptor(MT3620Blink.Application this__, MT3620Blink.IEPollListener target)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_RegisterDescriptor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_IEPollListener* stack0_0__;
    MT3620Blink_Application* stack0_4__;
    MT3620Blink_IEPollListener* stack2_3__;
} MT3620Blink_Application_RegisterDescriptor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_RegisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_IEPollListener* target)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    System_Runtime_InteropServices_GCHandle handle;
    il2c_memset(&handle, 0x00, sizeof handle);
    MT3620Blink_epoll_event ev;
    il2c_memset(&ev, 0x00, sizeof ev);
    MT3620Blink_epoll_event local2__;
    il2c_memset(&local2__, 0x00, sizeof local2__);
    MT3620Blink_epoll_data_t local3__;
    il2c_memset(&local3__, 0x00, sizeof local3__);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    System_Runtime_InteropServices_GCHandle stack0_1__;
    MT3620Blink_epoll_event* stack0_2__;
    MT3620Blink_epoll_event stack0_3__;
    int32_t stack0_5__;
    int32_t stack1_0__;
    uint32_t stack1_1__;
    MT3620Blink_epoll_data_t* stack1_2__;
    MT3620Blink_epoll_data_t stack1_3__;
    System_Runtime_InteropServices_GCHandle stack2_0__;
    intptr_t stack2_1__;
    System_Runtime_InteropServices_NativePointer stack2_2__;
    int32_t stack2_4__;
    MT3620Blink_epoll_event* stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_RegisterDescriptor_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Application.cs(19) */
    /* IL_0001: ldarg.1  */
    frame__.stack0_0__ = target;
    /* IL_0002: ldc.i4.3                        : Application.cs(20) */
    stack1_0__ = 3;
    /* IL_0003: call System.Runtime.InteropServices.GCHandle.Alloc : Application.cs(20) */
    stack0_1__ = System_Runtime_InteropServices_GCHandle_Alloc_1(il2c_adjusted_reference(frame__.stack0_0__), (System_Runtime_InteropServices_GCHandleType)stack1_0__);
    /* IL_0008: stloc.0                         : Application.cs(20) */
    handle = stack0_1__;
    /* IL_0009: ldloca.s local2__               : Application.cs(22) */
    stack0_2__ = &local2__;
    /* IL_000b: initobj MT3620Blink.epoll_event : Application.cs(22) */
    il2c_memset(stack0_2__, 0x00, sizeof *stack0_2__);
    /* IL_0011: ldloca.s local2__               : Application.cs(22) */
    stack0_2__ = &local2__;
    /* IL_0013: ldsfld MT3620Blink.Interops.EPOLLIN : Application.cs(22) */
    stack1_1__ = MT3620Blink_Interops_EPOLLIN;
    /* IL_0018: stfld MT3620Blink.epoll_event.events : Application.cs(22) */
    stack0_2__->events = stack1_1__;
    /* IL_001d: ldloca.s local2__               : Application.cs(22) */
    stack0_2__ = &local2__;
    /* IL_001f: ldloca.s local3__               : Application.cs(22) */
    stack1_2__ = &local3__;
    /* IL_0021: initobj MT3620Blink.epoll_data_t : Application.cs(22) */
    il2c_memset(stack1_2__, 0x00, sizeof *stack1_2__);
    /* IL_0027: ldloca.s local3__               : Application.cs(22) */
    stack1_2__ = &local3__;
    /* IL_0029: ldloc.0                         : Application.cs(22) */
    stack2_0__ = handle;
    /* IL_002a: call System.Runtime.InteropServices.GCHandle.ToIntPtr : Application.cs(22) */
    stack2_1__ = System_Runtime_InteropServices_GCHandle_ToIntPtr(stack2_0__);
    /* IL_002f: call System.Runtime.InteropServices.NativePointer.op_Implicit : Application.cs(22) */
    stack2_2__ = System_Runtime_InteropServices_NativePointer_op_Implicit(stack2_1__);
    /* IL_0034: stfld MT3620Blink.epoll_data_t.ptr : Application.cs(22) */
    stack1_2__->ptr = stack2_2__;
    /* IL_0039: ldloc.3                         : Application.cs(22) */
    stack1_3__ = local3__;
    /* IL_003a: stfld MT3620Blink.epoll_event.data : Application.cs(22) */
    stack0_2__->data = stack1_3__;
    /* IL_003f: ldloc.2                         : Application.cs(22) */
    stack0_3__ = local2__;
    /* IL_0040: stloc.1                         : Application.cs(22) */
    ev = stack0_3__;
    /* IL_0041: ldarg.0                         : Application.cs(27) */
    frame__.stack0_4__ = this__;
    /* IL_0042: call MT3620Blink.Descriptor.get_Identity : Application.cs(27) */
    stack0_5__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_4__);
    /* IL_0047: ldsfld MT3620Blink.Interops.EPOLL_CTL_ADD : Application.cs(27) */
    stack1_0__ = MT3620Blink_Interops_EPOLL_CTL_ADD;
    /* IL_004c: ldarg.1                         : Application.cs(27) */
    frame__.stack2_3__ = target;
    /* IL_004d: callvirt MT3620Blink.IEPollListener.get_Identity : Application.cs(27) */
    stack2_4__ = frame__.stack2_3__->vptr0__->get_Identity(il2c_adjusted_reference(frame__.stack2_3__));
    /* IL_0052: ldloca.s ev                     : Application.cs(27) */
    stack3_0__ = &ev;
    /* IL_0054: call MT3620Blink.Interops.epoll_ctl : Application.cs(27) */
    stack0_5__ = MT3620Blink_Interops_epoll_ctl(stack0_5__, stack1_0__, stack2_4__, stack3_0__);
    /* IL_0059: pop                             : Application.cs(27) */
    /* IL_005a: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Application.UnregisterDescriptor(MT3620Blink.Application this__, MT3620Blink.IEPollListener target)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_UnregisterDescriptor_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_IEPollListener* stack0_0__;
    MT3620Blink_Application* stack0_4__;
    MT3620Blink_IEPollListener* stack2_0__;
} MT3620Blink_Application_UnregisterDescriptor_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_UnregisterDescriptor(MT3620Blink_Application* this__, MT3620Blink_IEPollListener* target)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    System_Runtime_InteropServices_GCHandle handle;
    il2c_memset(&handle, 0x00, sizeof handle);
    MT3620Blink_epoll_event ev;
    il2c_memset(&ev, 0x00, sizeof ev);

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    System_Runtime_InteropServices_GCHandle stack0_1__;
    System_Runtime_InteropServices_GCHandle* stack0_2__;
    MT3620Blink_epoll_event* stack0_3__;
    int32_t stack0_5__;
    int32_t stack1_0__;
    int32_t stack2_1__;
    MT3620Blink_epoll_event* stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_UnregisterDescriptor_EXECUTION_FRAME__ frame__ =
        { NULL, 3 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Application.cs(35) */
    /* IL_0001: ldarg.1  */
    frame__.stack0_0__ = target;
    /* IL_0002: ldc.i4.3                        : Application.cs(36) */
    stack1_0__ = 3;
    /* IL_0003: call System.Runtime.InteropServices.GCHandle.Alloc : Application.cs(36) */
    stack0_1__ = System_Runtime_InteropServices_GCHandle_Alloc_1(il2c_adjusted_reference(frame__.stack0_0__), (System_Runtime_InteropServices_GCHandleType)stack1_0__);
    /* IL_0008: stloc.0                         : Application.cs(36) */
    handle = stack0_1__;
    /* IL_0009: ldloca.s handle                 : Application.cs(37) */
    stack0_2__ = &handle;
    /* IL_000b: call System.Runtime.InteropServices.GCHandle.Free : Application.cs(37) */
    System_Runtime_InteropServices_GCHandle_Free(stack0_2__);
    /* IL_0010: nop                             : Application.cs(37) */
    /* IL_0011: ldloca.s ev */
    stack0_3__ = &ev;
    /* IL_0013: initobj MT3620Blink.epoll_event : Application.cs(39) */
    il2c_memset(stack0_3__, 0x00, sizeof *stack0_3__);
    /* IL_0019: ldarg.0                         : Application.cs(41) */
    frame__.stack0_4__ = this__;
    /* IL_001a: call MT3620Blink.Descriptor.get_Identity : Application.cs(41) */
    stack0_5__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_4__);
    /* IL_001f: ldsfld MT3620Blink.Interops.EPOLL_CTL_DEL : Application.cs(41) */
    stack1_0__ = MT3620Blink_Interops_EPOLL_CTL_DEL;
    /* IL_0024: ldarg.1                         : Application.cs(41) */
    frame__.stack2_0__ = target;
    /* IL_0025: callvirt MT3620Blink.IEPollListener.get_Identity : Application.cs(41) */
    stack2_1__ = frame__.stack2_0__->vptr0__->get_Identity(il2c_adjusted_reference(frame__.stack2_0__));
    /* IL_002a: ldloca.s ev                     : Application.cs(41) */
    stack3_0__ = &ev;
    /* IL_002c: call MT3620Blink.Interops.epoll_ctl : Application.cs(41) */
    stack0_5__ = MT3620Blink_Interops_epoll_ctl(stack0_5__, stack1_0__, stack2_1__, stack3_0__);
    /* IL_0031: pop                             : Application.cs(41) */
    /* IL_0032: ret  */
    il2c_unlink_execution_frame(&frame__);
    return;
}

///////////////////////////////////////
// [3] MT3620Blink.Application.Run(MT3620Blink.Application this__)

//-------------------
// [3-7] Declare execution frame:

typedef struct MT3620Blink_Application_Run_EXECUTION_FRAME_DECL
{
    const IL2C_EXECUTION_FRAME* pNext__;
    const uint16_t objRefCount__;
    const uint16_t valueCount__;
    //-------------------- objref
    MT3620Blink_IEPollListener* target;
    MT3620Blink_Application* stack0_2__;
    System_Object* stack0_10__;
    MT3620Blink_IEPollListener* stack0_11__;
} MT3620Blink_Application_Run_EXECUTION_FRAME__;

//-------------------
// [3-2] Function body:

void MT3620Blink_Application_Run(MT3620Blink_Application* this__)
{
    il2c_assert(this__ != NULL);

    //-------------------
    // [3-3] Local variables (!objref):

    MT3620Blink_epoll_event ev;
    il2c_memset(&ev, 0x00, sizeof ev);
    int32_t numEventsOccurred = 0;
    bool local2__ = false;
    bool local3__ = false;
    System_Runtime_InteropServices_GCHandle handle;
    il2c_memset(&handle, 0x00, sizeof handle);
    bool local6__ = false;

    //-------------------
    // [3-4] Evaluation stacks (!objref):

    int32_t stack0_0__;
    MT3620Blink_epoll_event* stack0_1__;
    bool stack0_3__;
    MT3620Blink_epoll_event stack0_4__;
    MT3620Blink_epoll_data_t stack0_5__;
    System_Runtime_InteropServices_NativePointer stack0_6__;
    intptr_t stack0_7__;
    System_Runtime_InteropServices_GCHandle stack0_8__;
    System_Runtime_InteropServices_GCHandle* stack0_9__;
    MT3620Blink_epoll_event* stack1_0__;
    int32_t stack1_1__;
    int32_t stack2_0__;
    int32_t stack3_0__;

    //-------------------
    // [3-5] Setup execution frame:

    MT3620Blink_Application_Run_EXECUTION_FRAME__ frame__ =
        { NULL, 4 };
    il2c_link_execution_frame(&frame__);

    //-------------------
    // [3-6] IL body:

    /* IL_0000: nop                             : Application.cs(49) */
    /* IL_0001: br.s IL_005f */
    goto IL_005f;
IL_0003:
    /* IL_0003: nop                             : Application.cs(51) */
    /* IL_0004: ldloca.s ev */
    stack0_1__ = &ev;
    /* IL_0006: initobj MT3620Blink.epoll_event : Application.cs(52) */
    il2c_memset(stack0_1__, 0x00, sizeof *stack0_1__);
    /* IL_000c: ldarg.0                         : Application.cs(53) */
    frame__.stack0_2__ = this__;
    /* IL_000d: call MT3620Blink.Descriptor.get_Identity : Application.cs(53) */
    stack0_0__ = MT3620Blink_Descriptor_get_Identity((MT3620Blink_Descriptor*)frame__.stack0_2__);
    /* IL_0012: ldloca.s ev                     : Application.cs(53) */
    stack1_0__ = &ev;
    /* IL_0014: ldc.i4.1                        : Application.cs(53) */
    stack2_0__ = 1;
    /* IL_0015: ldc.i4.m1                       : Application.cs(53) */
    stack3_0__ = -1;
    /* IL_0016: call MT3620Blink.Interops.epoll_wait : Application.cs(53) */
    stack0_0__ = MT3620Blink_Interops_epoll_wait(stack0_0__, stack1_0__, stack2_0__, stack3_0__);
    /* IL_001b: stloc.1                         : Application.cs(53) */
    numEventsOccurred = stack0_0__;
    /* IL_001c: ldloc.1                         : Application.cs(55) */
    stack0_0__ = numEventsOccurred;
    /* IL_001d: ldc.i4.m1                       : Application.cs(55) */
    stack1_1__ = -1;
    /* IL_001e: ceq                             : Application.cs(55) */
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_0020: stloc.2                         : Application.cs(55) */
    local2__ = (bool)stack0_0__;
    /* IL_0021: ldloc.2                         : Application.cs(55) */
    stack0_3__ = local2__;
    /* IL_0022: brfalse.s IL_0027               : Application.cs(55) */
    if (stack0_3__ == false) goto IL_0027;
    /* IL_0024: nop                             : Application.cs(56) */
    /* IL_0025: br.s IL_0064 */
    goto IL_0064;
IL_0027:
    /* IL_0027: ldloc.1                         : Application.cs(59) */
    stack0_0__ = numEventsOccurred;
    /* IL_0028: ldc.i4.1                        : Application.cs(59) */
    stack1_1__ = 1;
    /* IL_0029: ceq                             : Application.cs(59) */
    stack0_0__ = (int32_t)stack0_0__ == (int32_t)stack1_1__;
    /* IL_002b: stloc.3                         : Application.cs(59) */
    local3__ = (bool)stack0_0__;
    /* IL_002c: ldloc.3                         : Application.cs(59) */
    stack0_3__ = local3__;
    /* IL_002d: brfalse.s IL_005e               : Application.cs(59) */
    if (stack0_3__ == false) goto IL_005e;
    /* IL_002f: nop                             : Application.cs(60) */
    /* IL_0030: ldloc.0  */
    stack0_4__ = ev;
    /* IL_0031: ldfld MT3620Blink.epoll_event.data : Application.cs(61) */
    stack0_5__ = stack0_4__.data;
    /* IL_0036: ldfld MT3620Blink.epoll_data_t.ptr : Application.cs(61) */
    stack0_6__ = stack0_5__.ptr;
    /* IL_003b: call System.Runtime.InteropServices.NativePointer.op_Implicit : Application.cs(61) */
    stack0_7__ = System_Runtime_InteropServices_NativePointer_op_Implicit_1(stack0_6__);
    /* IL_0040: call System.Runtime.InteropServices.GCHandle.FromIntPtr : Application.cs(61) */
    stack0_8__ = System_Runtime_InteropServices_GCHandle_FromIntPtr(stack0_7__);
    /* IL_0045: stloc.s handle                  : Application.cs(61) */
    handle = stack0_8__;
    /* IL_0047: ldloca.s handle                 : Application.cs(62) */
    stack0_9__ = &handle;
    /* IL_0049: call System.Runtime.InteropServices.GCHandle.get_Target : Application.cs(62) */
    frame__.stack0_10__ = System_Runtime_InteropServices_GCHandle_get_Target(stack0_9__);
    /* IL_004e: castclass MT3620Blink.IEPollListener : Application.cs(62) */
    frame__.stack0_11__ = il2c_castclass(frame__.stack0_10__, MT3620Blink_IEPollListener);
    /* IL_0053: stloc.s target                  : Application.cs(62) */
    frame__.target = frame__.stack0_11__;
    /* IL_0055: ldloc.s target                  : Application.cs(63) */
    frame__.stack0_11__ = frame__.target;
    /* IL_0057: callvirt MT3620Blink.IEPollListener.OnRaised : Application.cs(63) */
    frame__.stack0_11__->vptr0__->OnRaised(il2c_adjusted_reference(frame__.stack0_11__));
    /* IL_005c: nop                             : Application.cs(63) */
    /* IL_005d: nop  */
IL_005e:
    /* IL_005e: nop  */
IL_005f:
    /* IL_005f: ldc.i4.1  */
    stack0_0__ = 1;
    /* IL_0060: stloc.s local6__                : Application.cs(50) */
    local6__ = (bool)stack0_0__;
    /* IL_0062: br.s IL_0003                    : Application.cs(50) */
    goto IL_0003;
IL_0064:
    /* IL_0064: ret                             : Application.cs(66) */
    il2c_unlink_execution_frame(&frame__);
    return;
}

//////////////////////
// [7] Runtime helpers:

// [7-10-1] VTable (Not defined, same as MT3620Blink.Descriptor)

// [7-13] VTable for System.IDisposable
System_IDisposable_VTABLE_DECL__ MT3620Blink_Application_System_IDisposable_VTABLE__ = {
    il2c_adjustor_offset(MT3620Blink_Application, System_IDisposable),
    (void (*)(void*))MT3620Blink_Descriptor_Dispose,
};

// [7-8] Runtime type information
IL2C_RUNTIME_TYPE_BEGIN(MT3620Blink_Application, "MT3620Blink.Application", IL2C_TYPE_REFERENCE, sizeof(MT3620Blink_Application), MT3620Blink_Descriptor, 0, 1)
    IL2C_RUNTIME_TYPE_INTERFACE(MT3620Blink_Application, System_IDisposable)
IL2C_RUNTIME_TYPE_END();

#ifdef __cplusplus
}
#endif
