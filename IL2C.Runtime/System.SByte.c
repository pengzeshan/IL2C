#include "il2c_private.h"

/////////////////////////////////////////////////////////////
// System.SByte

System_String* System_SByte_ToString(int8_t* this__)
{
    wchar_t buffer[5];

    il2c_itow(*this__, buffer, 10);
    return il2c_new_string(buffer);
}

/////////////////////////////////////////////////
// VTable and runtime type info declarations

IL2C_RUNTIME_TYPE_DECL __System_SByte_RUNTIME_TYPE__ = {
    "System.SByte",
    IL2C_TYPE_INTEGER,
    sizeof(System_SByte),
    /* internalcall */ IL2C_DEFAULT_MARK_HANDLER };