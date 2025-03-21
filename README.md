﻿# Game of Life
## Summary
This is a simple simulation that runs Conway's Game of Life using Scribble2D, a basic 2D rendering engine written by me in C++ and OpenGL. The controls are as follows:
- You can press the enter key on your keyboard or numpad to play/pause the simulation.
- You can click anywhere while the sim is paused to place a living cell at that grid position
- You can press the spacebar to reset the world to the same position that you see when you open the app.
- You can press the escape key to clear the world entirely.
- Press the right/left or up/down arrow keys to speed up or slow down the simulation.

## Supported Platforms
Currently, Scribble2D only supports Windows systems. 

## How to Build
If you'd like to build this project, you must follow these steps:
- Clone the repo recursively with ```git clone --recursive https://github.com/Masonluna/Game-of-Life.git``` to your chosen location
  - NOTE: You MUST clone recursively in order to properly clone the Scribble2D submodule.
- Generate the project files
  - From the root directory,  run ```GenerateProjects.bat``` to generate a Visual Studio 2022 project, OR
  - From the root directory, run ```call vendor\premake\premake5.exe vs2022``` to accomplish the same feat. If you'd like to generate the project files in a different IDE, replace vs2022 with one of the following:
    - vs2022, Visual Studio 2022
    - vs2019, Visual Studio 2019
    - vs2017, Visual Studio 2017
    - vs2015, Visual Studio 2015
    - vs2013, Visual Studio 2013
    - vs2012, Visual Studio 2012
    - vs2010, Visual Studio 2010
    - vs2008, Visual Studio 2008
    - vs2005, Visual Studio 2005
    - gmake, GNU Makefiles (including Cygwin and MinGW)
    - gmakelegacy, GNU Makefiles (deprecated exporter)
    - codelite, CodeLite projects
    - **As a warning, this project has only been tested using Visual Studio 2022, so I cannot currently guarantee that it will work on any other IDE
- Once your project files have been generated, open your solution and build in one of the supported configurations, Debug or Release.

## How to Download the Simulator
Unfortunately, there is no release version ready yet. The moment a release version is ready, it will be posted in the Releases tab here on Github, and instructions will be found here!
