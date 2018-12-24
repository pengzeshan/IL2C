#include "il2c_private.h"
#include "System.Runtime.InteropServices.GCHandle.h"

/////////////////////////////////////////////////////////////
// System.Runtime.InteropServices.GCHandle

System_Object* System_Runtime_InteropServices_GCHandle_get_Target(System_Runtime_InteropServices_GCHandle* this__)
{
    il2c_assert(this__ != NULL);
    return (System_Object*)*this__;
}

void System_Runtime_InteropServices_GCHandle_set_Target(System_Runtime_InteropServices_GCHandle* this__, System_Object* value)
{
    il2c_assert(this__ != NULL);

    if (value != NULL)
    {
        IL2C_REF_HEADER* pHeader = il2c_get_header__(value);
        volatile interlock_t gcMark = pHeader->gcMark;
        if ((gcMark == GCMARK_NOMARK) || (gcMark == GCMARK_LIVE))
        {
            // Fixed this objref
            pHeader->gcMark = GCMARK_FIXED;
        }
    }

    *this__ = (intptr_t)value;
}

void System_Runtime_InteropServices_GCHandle_Free(System_Runtime_InteropServices_GCHandle* this__)
{
    il2c_assert(this__ != NULL);

    System_Object* obj = (System_Object*)*this__;
    if (obj != NULL)
    {
        IL2C_REF_HEADER* pHeader = il2c_get_header__(obj);
        if (pHeader->gcMark == GCMARK_FIXED)
        {
            // No problem for previous state was GCMARK_NOMARK.
            pHeader->gcMark = GCMARK_LIVE;
        }
    }

    *this__ = 0;
}

intptr_t System_Runtime_InteropServices_GCHandle_ToIntPtr(System_Runtime_InteropServices_GCHandle* this__)
{
    il2c_assert(this__ != NULL);
    return *this__;
}

intptr_t System_Runtime_InteropServices_GCHandle_AddrOfPinnedObject(System_Runtime_InteropServices_GCHandle* this__)
{
    il2c_assert(this__ != NULL);

    // Same as ToIntPtr because the IL2C's objref is always pinned native pointer.
    return *this__;
}

System_Runtime_InteropServices_GCHandle System_Runtime_InteropServices_GCHandle_Alloc(System_Object* value)
{
    // intptr_t aliased
    return (System_Runtime_InteropServices_GCHandle)value;
}

System_Runtime_InteropServices_GCHandle System_Runtime_InteropServices_GCHandle_Alloc_1(
    System_Object* value, System_Runtime_InteropServices_GCHandleType type)
{
    il2c_assert((type == System_Runtime_InteropServices_GCHandleType_Normal) ||
        (type == System_Runtime_InteropServices_GCHandleType_Pinned));

    // intptr_t aliased
    return (System_Runtime_InteropServices_GCHandle)value;
}

System_Runtime_InteropServices_GCHandle System_Runtime_InteropServices_GCHandle_FromIntPtr(intptr_t value)
{
    // intptr_t aliased
    return value;
}

int32_t System_Runtime_InteropServices_GCHandle_GetHashCode(System_Runtime_InteropServices_GCHandle* this__)
{
    // TODO:
    il2c_assert(0);
    return (int32_t)(intptr_t)this__;
}

bool System_Runtime_InteropServices_GCHandle_Equals(System_Runtime_InteropServices_GCHandle* this__, System_Object* obj)
{
    // TODO:
    il2c_assert(0);
    return false;
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

static int32_t System_Runtime_InteropServices_GCHandle_GetHashCode_Trampoline_VFunc__(System_ValueType* this__)
{
    il2c_assert(this__ != NULL);

    System_Runtime_InteropServices_GCHandle* pValue = il2c_unsafe_unbox__(this__, System_Runtime_InteropServices_GCHandle);
    return System_Runtime_InteropServices_GCHandle_GetHashCode(pValue);
}

static bool System_Runtime_InteropServices_GCHandle_Equals_Trampoline_VFunc__(System_ValueType* this__, System_Object* obj)
{
    il2c_assert(this__ != NULL);

    System_Runtime_InteropServices_GCHandle* pValue = il2c_unsafe_unbox__(this__, System_Runtime_InteropServices_GCHandle);
    return System_Runtime_InteropServices_GCHandle_Equals(pValue, obj);
}

System_Runtime_InteropServices_GCHandle_VTABLE_DECL__ System_Runtime_InteropServices_GCHandle_VTABLE__ = {
    0, // Adjustor offset
    (bool(*)(void*, System_Object*))System_Runtime_InteropServices_GCHandle_Equals_Trampoline_VFunc__,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Runtime_InteropServices_GCHandle_GetHashCode_Trampoline_VFunc__,
    (System_String* (*)(void*))System_Object_ToString
};

IL2C_RUNTIME_TYPE_BEGIN(
    System_Runtime_InteropServices_GCHandle,
    "System.Runtime.InteropServices.GCHandle",
    IL2C_TYPE_VALUE,
    sizeof(System_Runtime_InteropServices_GCHandle),
    System_ValueType,
    0, 0)
IL2C_RUNTIME_TYPE_END();
