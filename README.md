#SabRename
pySabRename is a post-processing script for sabnzbd.
It renames the biggest file in the final download folder to the job name.

##pySabRename vs sabRename
* pySabRename is written in Python, sabRename is written in C++
* pySabRename also checks subfolders (I've not seen many spots placing the actual movie in a subfolder, but I've seen them), sabRename doesn't afaik
* pySabRename is multi OS, sabRename uses Windows.h (not exactly multi OS)
* pySabRename's py2exe is 4.76MB, sabRename.exe is 15,0kB

##Use
This program is used in sabnzbd and works really well when using the latest SpotWeb pull. It is designed for (mostly) movies with 'encrypted' (=mostly random or flipped) filenames.

##OS
This software can be used on Windows only since it uses windows.h!

##Todo
* Add subfolder support
* Make this multi OS
* Make program less rules
* Added functionality is always welcome