@ECHO OFF

SET DESTDIR=%CD%

CD %DESTDIR%

RD /S /Q Include
MD Include

CD Include
MD Toolkit

CD Toolkit
MD Core
CD Core
COPY ..\..\..\..\..\Src\Toolkit_Core\*.h %DESTDIR%\Include\Toolkit\Core\.
CD ..

MD Gui
CD Gui
COPY ..\..\..\..\..\Src\Toolkit_Gui\Lib\*.h %DESTDIR%\Include\Toolkit\Gui\.
CD ..

MD Math
CD Math
COPY ..\..\..\..\..\Src\Toolkit_Math\Lib\*.h %DESTDIR%\Include\Toolkit\Math\.
CD ..

MD Resource
CD Resource
COPY ..\..\..\..\..\Src\Toolkit_Resource\Lib\*.h %DESTDIR%\Include\Toolkit\Resource\.
CD ..

MD Test
CD Test
COPY ..\..\..\..\..\Src\Toolkit_Test\Lib\*.h %DESTDIR%\Include\Toolkit\Test\.
CD ..

CD ..\..

CD %CD%

ECHO %CD%
