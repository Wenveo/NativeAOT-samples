using Xunit;

using System.Runtime.InteropServices;

public class PInvokeTest
{
    [DllImport(@"..\..\..\..\..\artifacts\NativeLibraryZ.dll")]
    private static extern int Add(int a, int b);

    [Fact]
    public void PInvoke_AddTest()
    {
        var ret = Add(20, 30);
        Assert.False(ret != 50, "Wrong!");
    }
}