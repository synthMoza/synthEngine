# About
The attempt to make a simple engine on C++ using graphical library SFML.
# Main Structure
The program starts by creating object of type "Application" and calling the method "launch".
<a href="https://imgbb.com/"><img src="https://i.ibb.co/80SMtGX/Emr-ZG54chzc.jpg" alt="Emr-ZG54chzc" border="0"></a>

The main concept is "Sketch" - something like a drawing sketch. You create a sketch and include some objects into it, write the rules for them to update and etc,
and then push it into the SketchManager using SketchAssistant - and everything will be shown in the window. Also you can create several sketches that will work
simultaneously - for example, you can create the pause menu by addind another sketch and stopping to upload the main one.
# Features
## CircleShape
Just a wrapper for a common CircleShape class in SFML - you can create and set its settings as you wish.
