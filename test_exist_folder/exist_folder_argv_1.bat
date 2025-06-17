@echo off
title exist_folder_argv_1.exe

set /p path="zadej cestu k adersari "
REM jenom enter bez nice ho ted vlozi hodnou xxx
exist_folder_argv_1.exe %path%
