cl.exe /c /EHsc main.c Common/common.c 
cl.exe /c /EHsc main.c Common/BazierCurve/bazier.c  
@REM cl.exe /c /EHsc Common/Audio/audio.c 
cl.exe /c /EHsc Common/Geometry/geometry.c 

@REM scenes 
@REM cl.exe /c /EHsc Scenes/Scene1/scene1.c
@REM cl.exe /c /EHsc Scenes/Scene2/scene2.c
cl.exe /c /EHsc Scenes/Scene3/scene3.c

@REM 
@REM cl.exe /c /EHsc Effects/Lights/lights.c 
cl.exe /c /EHsc Effects\Cubemap\cubemap.c
@REM cl.exe /c /EHsc Effects/Fog/fog.c

@REM objects 
@REM cl.exe /c /EHsc Objects/Boy/boy.c 
cl.exe /c /EHsc Objects/Grass/grass.c 
cl.exe /c /EHsc Objects/Peackock/peackock.c 

rc.exe main.rc 

link.exe /OUT:main.exe *.obj main.res kernel32.lib Winmm.lib user32.lib gdi32.lib /SUBSYSTEM:WINDOWS 

del *.obj
 