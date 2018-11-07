#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.Exception

void System_Exception__ctor(System_Exception* this__)
{
    il2c_assert(this__ != NULL);
}

// TODO:
IL2C_CONST_STRING(System_Exception_message, L"System.Exception");
System_String* System_Exception_ToString(System_Exception* this__)
{
    il2c_assert(this__ != NULL);

    return System_Exception_message;
}

void il2c_throw__(jmp_buf unwind_target, System_Exception* ex)
{
    il2c_assert(ex != NULL);

    // TODO:
    longjmp(unwind_target, 1);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

__System_Exception_VTABLE_DECL__ __System_Exception_VTABLE__ = {
    /* internalcall */ il2c_isinst__,
    (bool(*)(void*, System_Object*))System_Object_Equals,
    (void(*)(void*))System_Object_Finalize,
    (int32_t(*)(void*))System_Object_GetHashCode,
    (System_String* (*)(void*))System_Exception_ToString,
};

IL2C_DECLARE_RUNTIME_TYPE(System_Exception, "System.Exception", IL2C_TYPE_REFERENCE, System_Object);