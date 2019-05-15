@echo off
setlocal enabledelayedexpansion

set VERSION=0.4.60

if exist artifacts (
    move artifacts artifacts_
    rmdir /s /q artifacts_
)
mkdir artifacts

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Interop
echo.

dotnet pack --configuration Release --include-symbols IL2C.Interop\IL2C.Interop.csproj
copy IL2C.Interop\bin\Release\IL2C.Interop.%VERSION%.symbols.nupkg artifacts\IL2C.Interop.%VERSION%.nupkg

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Core
echo.

dotnet pack --configuration Release --include-symbols IL2C.Core\IL2C.Core.csproj
copy IL2C.Core\bin\Release\IL2C.Core.%VERSION%.symbols.nupkg artifacts\IL2C.Core.%VERSION%.nupkg

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime
echo.

.nuget\nuget pack -Prop version=%VERSION% -OutputDirectory artifacts IL2C.Runtime\IL2C.Runtime.nuspec 

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Runtime.msvc
echo.

.nuget\nuget pack -Prop version=%VERSION% -OutputDirectory artifacts IL2C.Runtime\IL2C.Runtime.msvc.nuspec 

echo.
echo ///////////////////////////////////////////////
echo // Build IL2C.Build
echo.

dotnet pack --configuration Release --include-symbols IL2C.Tasks\IL2C.Tasks.csproj
copy IL2C.Tasks\bin\Release\IL2C.Build.%VERSION%.symbols.nupkg artifacts\IL2C.Build.%VERSION%.nupkg

echo.
echo ///////////////////////////////////////////////
echo // Build Arduino library
echo.

mkdir artifacts\Arduino
xcopy /s IL2C.Runtime\include\*.h artifacts\Arduino\src\
xcopy /s IL2C.Runtime\src\*.h artifacts\Arduino\src\
xcopy /s IL2C.Runtime\src\*.c artifacts\Arduino\src\

for /f "delims=" %%a in (Arduino.properties) do (
  set line=%%a
  echo !line:{version}=%VERSION%! >> artifacts\Arduino\library.properties
)

echo.
echo Done.
echo.
