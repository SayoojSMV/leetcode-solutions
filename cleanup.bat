@echo off  
git checkout main  
git pull origin main  
for /f "tokens=*" %%a in ("git branch") do (  
  echo %%a | findstr /r "feat/ docs/" >nul  
  if not errorlevel 1 for /f "tokens=*" %%b in ("%%a") do git branch -D %%b  
)  
git fetch --prune 
