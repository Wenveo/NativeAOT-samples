[CmdletBinding(PositionalBinding=$false)]
Param(
    [ValidateSet("Debug", "Release")]
    [string]$Configuration,
    [ValidateSet("win-x64", "win-arm64")]
    [string]$Platform
)

function Publish-Projects {
    param ([string[]]$Projects)
    foreach ($item in $Projects) {
        dotnet publish $item -c $Configuration -r $Platform --no-self-contained
    }
}

Write-Host "Build all sample projects."
Publish-Projects (Get-ChildItem -Path samples\*.csproj -Recurse -Forc)

Write-Host "Build all test projects."
Publish-Projects (Get-ChildItem -Path tests\*proj -Recurse -Forc)