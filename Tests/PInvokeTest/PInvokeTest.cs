using Xunit;

using System.Runtime.InteropServices;

namespace PInvokeTest;

public class UnitTest1
{
    [DllImport(@"..\..\..\..\NativeLibrary-ZeroRuntime\bin\Release\net8.0\win-x64\publish\NativeLibrary.dll")]
    private static extern int Add(int a, int b);

    [Fact]
    public void AddTest()
    {
        var ret = Add(20, 30);
        Assert.False(ret != 50, "Wrong!");
    }
}