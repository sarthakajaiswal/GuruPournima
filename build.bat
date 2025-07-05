cl.exe /c /EHsc main.c Common/common.c 

@REM scenes 
cl.exe /c /EHsc Scenes/Scene1/scene1.c
cl.exe /c /EHsc Scenes/Scene2/scene2.c

@REM 
@REM cl.exe /c /EHsc Effects/Lights/lights.c 
cl.exe /c /EHsc Effects\Cubemap\cubemap.c

rc.exe main.rc 

link.exe /OUT:main.exe *.obj main.res user32.lib gdi32.lib /SUBSYSTEM:WINDOWS 

del *.obj
