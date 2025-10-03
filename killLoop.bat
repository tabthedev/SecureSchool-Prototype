:Loop
taskkill /f /im IntelAudioProcess.exe
taskkill /f /im widgetService.exe
timeout -t 1
goto Loop