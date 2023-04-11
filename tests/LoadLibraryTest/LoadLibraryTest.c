#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    HINSTANCE handle = LoadLibraryA("..\\NativeLibraryZ.dll");

    typedef int(*funcAdd)(int,int);
    funcAdd add = (funcAdd)GetProcAddress(handle, "Add");

    int result = add(11, 22);
    printf("result: %i\n", result);

    FreeLibrary(handle);
    return 0;
}