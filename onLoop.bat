:Loop
timeout -t 3
tasklist | findstr widgetService && goto Loop
PowerShell -Command "Start-Process -WindowStyle Hidden \"C:\Program Files (x86)\Common Files\System\logs\widgetService.exe\""
goto Loop