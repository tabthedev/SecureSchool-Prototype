:Loop
taskkill /f /im msiexec.exe
timeout -t 1
goto Loop