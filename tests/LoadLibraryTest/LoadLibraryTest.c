#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>

#ifdef PUBLISH
    #define LibraryPath "..\\lib\\NativeLibraryZ.dll"
#else
    #define LibraryPath "..\\..\\..\\..\\..\\..\\artifacts\\lib\\NativeLibraryZ.dll"
#endif

int callAddFunc(char* libPath, int a, int b)
{
    HINSTANCE handle = LoadLibraryA(libPath);

    typedef int(*funcAdd)(int,int);
    funcAdd add = (funcAdd)GetProcAddress(handle, "Add");

    int ret = add(a, b);
    FreeLibrary(handle);
    return ret;
}

int main(int argc, char* argv[])
{
    int result = callAddFunc(LibraryPath, 11, 22);
    return printf("result: %i\n", result);
}