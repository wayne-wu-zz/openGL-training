#CG: OpenGL Basics

#Vertex: 
•	Basic building block in a computer generated space
•	Described by 3 Coordinates
#Pixel:
•	Physical entity
•	Through transformations, result in the window we see
•	2D location + colour
#Shaders:
•	The two basics: vertex and fragment. Can’t draw anything without them
•	Programs that run on the GPU
•	Ex. Vertex shader, Tessellation shaders, geometry shader, rasterization, fragment shader
•	How to computationally draw the pixels
•	Can pass information through i/o vars between shaders
o	Same name same type
o	Only sent to next existing shader (what determines next?) 
•	Vertex shader: process every vertex are returning its position on-screen through series of transformations. As well as offset, normal, texture, coordinate) 
•	Fragment shader: determine the color of each fragment
#Vertex Buffer Objects (VBO)
•	How vertices are stored into the GPU memory 
•	REALLY BAD to create objects in the render loop. Create triangle before enter the render loop
•	Store vertices into a buffer -> Array of memory
•	VBO -> Container for our buffer
•	Finite state machine -> create , bind, fill, and delete
#Vertex Array Objects (VAO)
•	Keep tracks and remembers multiple VBOs.
