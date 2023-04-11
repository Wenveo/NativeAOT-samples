// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.

#include <stdio.h>
#include <stdint.h>
#include <Windows.h>

extern "C" void OnLoaded();
extern "C" void OnUnloaded();

BOOL WINAPI DllMain(
    HINSTANCE hinstDLL,  // handle to DLL module
    DWORD fdwReason,     // reason for calling function
    LPVOID lpReserved )  // reserved
{
    /* 
        We can also do a few different things like
        Create another DllMain method in c# and invoke it. Just like:
        '
          C#
            [RuntimeExport("SharpDllMain")]
            static int SharpDllMain(nint hinstDLL, ulong fdwReason, nint lpReserved)
            {
                ...
            }

          C/C++
            extern "C" int SharpDllMain(HINSTANCE, DWORD, LPVOID);
            // SharpDllMain(hinstDLL, fdwReason, lpReserved);
        '.
        :)
    */

    // Perform actions based on the reason for calling.
    switch( fdwReason )
    {
        case DLL_PROCESS_ATTACH:
         // Initialize once for each new process.
         // Return FALSE to fail DLL load.
            OnLoaded();
            break;

        case DLL_THREAD_ATTACH:
         // Do thread-specific initialization.
            break;

        case DLL_THREAD_DETACH:
         // Do thread-specific cleanup.
            break;

        case DLL_PROCESS_DETACH:
         // Perform any necessary cleanup.
            OnUnloaded();
            break;
    }
    return TRUE;  // Successful DLL_PROCESS_ATTACH.
}
