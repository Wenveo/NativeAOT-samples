using System.Runtime.InteropServices;

var ret = Add(12, 24);
if (ret is not 36)
{
    throw new InvalidDataException("Wrong!");
}

Console.WriteLine($"Result: {ret}");

#if PUBLISH
[DllImport("..\\lib\\NativeLibraryZ.dll")]
#else
[DllImport("..\\..\\..\\..\\..\\..\\artifacts\\lib\\NativeLibraryZ.dll")]
#endif
static extern int Add(int a, int b);