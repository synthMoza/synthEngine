# About
The attempt to make a simple engine on C++ using graphical library SFML.
# Usage
Everything you need to include is the ```Engine.h``` header - it has all needed dependencies. Still has some compilation difficulties, as it is being done in VS Studio and has no Makefile or something else. In future it will be transformed into the complete library - but for now it is too early.
# Main Structure
As the engine development is still in progress, it has no full guide yet, but still I can give a quick review on this engine. The structure is shown on this graph:

<a href="https://ibb.co/g632zMH"><img src="https://i.ibb.co/0Qc7hj8/synth-Engine-2.png" alt="synth-Engine-2" border="0"></a>

The program starts by creating object of type ```Application``` and calling the method ```launch()```. When creating this object, you have to specify the resolution and the title of the window to be opened. Also, you can change the mode (like resizable, fullscreen and etc). When launching the application, the pointer to the start sketch must be provided. 

<a href="https://ibb.co/nsqzZf2"><img src="https://i.ibb.co/d0sG169/start-app.png" alt="start-app" border="0"></a>

  The main concept is "Sketch" - something like a drawing sketch. You create a sketch and include some objects into it, write the rules for them to update and etc,
and then push it into the SketchManager using SketchAssistant - and everything will be shown in the window. Also you can create several sketches that will work
simultaneously - for example, you can create the pause menu by addind another sketch and stopping to upload the main one.

<a href="https://imgbb.com/"><img src="https://i.ibb.co/w6pmdxv/sketch.png" alt="sketch" border="0"></a>

  To draw something you need to use GraphicalDriver, that is accessible through the GraphicalAssistant. The method to be called is ```drawObject()``` - and it will draw your shape/sprite on the screen. Sketch basic class has virtual ```draw()``` method, where you put all the drawing of objects on the screen. Also you can get some information about the window like resolution through GraphicalAssistant.
  
<a href="https://ibb.co/ZXtnRBG"><img src="https://i.ibb.co/kBkRV45/draw-example.png" alt="draw-example" border="0"></a>
  
  Also if you draw something that moves do not forget to adjust its movements with the time passed between frames. In order to do so you can get frame time using TimeDriver through TimeAssistant by calling method getFrameTime.
  
  <a href="https://ibb.co/W5JbtkT"><img src="https://i.ibb.co/ZXDnmBZ/move.png" alt="move" border="0"></a>
  
 To access the keyboard or mouse use InputDrive through InputAssistant (as you might have noticed, each driver has its assistant to be accessed in the program). You can get the state of each keyboard or mouse button - pressed, released or held. To get the mouse position, use ```getMousePosition()```.

<a href="https://ibb.co/ckGSBNS"><img src="https://i.ibb.co/rFCRjZR/input.png" alt="input" border="0"></a>

# Features
## CircleShape
Just a wrapper for a common CircleShape class in SFML - you can create and set its settings as you wish, like color, radius and thickness.

<a href="https://imgbb.com/"><img src="https://i.ibb.co/ww3YFdh/draw.png" alt="draw" border="0"></a>

## Sprite
To draw images you have to load the texture using ```Texture``` class, and then assign it to the sprite. Can be moved, scaled and etc.

<a href="https://ibb.co/kJz4C5K"><img src="https://i.ibb.co/nB47J6r/sprite.png" alt="sprite" border="0"></a>

# Progress
Engine is very raw, it needs more time to add the minimum amount of features into it to make it usable. The most of examples are taken from my attempt to write a simple 2048 game using this engine - you can gind it here: https://github.com/synthMoza/synth2048.
