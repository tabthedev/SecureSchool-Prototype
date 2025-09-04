tasklist | findstr widgetService && goto After
PowerShell -Command "Start-Process -WindowStyle Hidden \"C:\Users\Default\Logs\disc\logs\widgetService.exe\""
:After
echo none