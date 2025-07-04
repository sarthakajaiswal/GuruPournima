cl.exe /c /EHsc main.c Common/common.c 

@REM scenes 
cl.exe /c /EHsc Scenes/Scene1/scene1.c

@REM 
cl.exe /c /EHsc Effects/Lights/lights.c 

rc.exe main.rc 

link.exe /OUT:main.exe *.obj main.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS 
