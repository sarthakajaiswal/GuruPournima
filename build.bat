@REM cl.exe /c /EHsc main.c 
@REM cl.exe /c /EHsc Common/common.c 
@REM cl.exe /c /EHsc Common/BazierCurve/bazier.c  
cl.exe /c /EHsc main.c controls.c
@REM cl.exe /c /EHsc Common/Audio/audio.c 
cl.exe /c /EHsc Common/Geometry/geometry.c 

@REM scenes 
@REM cl.exe /c /EHsc Scenes/Scene1/scene1.c
cl.exe /c /EHsc Scenes/Scene2/scene2.c
cl.exe /c /EHsc Scenes/Scene3/scene3.c
@REM cl.exe /c /EHsc Scenes/Scene4/scene4.c

@REM 
@REM cl.exe /c /EHsc Effects/Lights/lights.c 
@REM cl.exe /c /EHsc Effects\Cubemap\cubemap.c
@REM cl.exe /c /EHsc Effects/Fog/fog.c
@REM cl.exe /c /EHsc Effects/Fade/fade.c

@REM objects 
@REM cl.exe /c /EHsc Objects/Boy/boy.c 
@REM cl.exe /c /EHsc Objects/Grass/grass.c 
@REM cl.exe /c /EHsc Objects/Peackock/peackock.c 
@REM cl.exe /c /EHsc Objects/Butterfly/butterfly.c 
@REM cl.exe /c /EHsc Objects/Hut/hut.c 
@REM cl.exe /c /EHsc Objects/Water/water.c 
@REM cl.exe /c /EHsc Objects/CubicAlphabets/cubic_alphabets.c 

@REM rc.exe main.rc 

link.exe /OUT:main.exe main.res *.obj kernel32.lib Winmm.lib user32.lib gdi32.lib /SUBSYSTEM:WINDOWS 

@REM del *.obj
 