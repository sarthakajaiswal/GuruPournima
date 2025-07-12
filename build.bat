cl.exe /c /EHsc main.c Common/common.c Common/BazierCurve/bazier.c  main.c controls.c Common/Audio/audio.c Common/Geometry/geometry.c Scenes/Scene1/scene1.c Scenes/Scene2/scene2.c Scenes/Scene3/scene3.c Scenes/Scene4/scene4.c Effects/Lights/lights.c  Effects\Cubemap\cubemap.c Effects/Fog/fog.c Effects/Fade/fade.c Objects/Boy/boy.c  Objects/Grass/grass.c  Objects/Butterfly/butterfly.c  Objects/Hut/hut.c  Objects/CubicAlphabets/cubic_alphabets.c 
rc.exe main.rc 
link.exe /OUT:main.exe main.res *.obj kernel32.lib Winmm.lib user32.lib gdi32.lib /SUBSYSTEM:WINDOWS 
del *.obj
 