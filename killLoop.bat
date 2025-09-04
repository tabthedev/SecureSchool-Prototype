:Loop
taskkill /f /im widgets.exe
taskkill /f /im widgetService.exe
timeout -t 1
goto Loop