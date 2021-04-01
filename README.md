# About
The attempt to make a simple engine on C++ using graphical library SFML.
# Usage
Everything you need to include is the "Engine.h" header - it has all needed dependencies, and also the engine has a Makefile to compile itself.
# Main Structure
The program starts by creating object of type "Application" and calling the method "launch".

<a href="https://imgbb.com/"><img src="https://i.ibb.co/80SMtGX/Emr-ZG54chzc.jpg" alt="Emr-ZG54chzc" border="0"></a>

  The main concept is "Sketch" - something like a drawing sketch. You create a sketch and include some objects into it, write the rules for them to update and etc,
and then push it into the SketchManager using SketchAssistant - and everything will be shown in the window. Also you can create several sketches that will work
simultaneously - for example, you can create the pause menu by addind another sketch and stopping to upload the main one.

<a href="https://imgbb.com/"><img src="https://i.ibb.co/w6pmdxv/sketch.png" alt="sketch" border="0"></a>

  To draw something you need to use GraphicalDriver, that is accessible through the GraphicalAssistant. The method to be called is draw - and it will draw your shape/sprite on the screen. Also you can get some information about the window like resolution through GraphicalAssistant.
  Also if you draw something that moves do not forget to adjust its movements with the time passed between frames. In order to do that you can this time by using TimeDriver through TimeAssistant by calling method getFrameTime.
  
  <a href="https://ibb.co/W5JbtkT"><img src="https://i.ibb.co/ZXDnmBZ/move.png" alt="move" border="0"></a>
  
 To access the keyboard or the mouse use InputDrive through InputAssistant (as you might have noticed, each driver has its assistant to be accessed in the program). <still in progress> 


# Features
## CircleShape
Just a wrapper for a common CircleShape class in SFML - you can create and set its settings as you wish.

<a href="https://imgbb.com/"><img src="https://i.ibb.co/ww3YFdh/draw.png" alt="draw" border="0"></a>

# Progress
Engine is very raw, it needs more time to add the minimum amount of features into it to make it usable.
