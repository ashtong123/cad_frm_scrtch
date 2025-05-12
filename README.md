Plan is to build a CAD program from scratch. Currently working on implementing some functions for 
vector manipulation in order to implement .stl file creation from a simple 3D.

3/25/25:
Completed the functions to write an .stl file given a set of triangles. Next I would like to be able to write ASCII binary files instead of text. I will probably start with a compiler that can convert from ASCII to binary. In the future it may be more efficient to create shapes as binary directly
Added the functionality to write ASCII or binary STL files given a set of triangles

STRUCTURE:
	BUILD --> BATCH SCRIPT TO BUILD PROJECT ON WINDOWS, EXECUTABLE IS CREATED HERE
	SOURCE/INCLUDES (MODULES) 
		VECTOR_OPS --> DEFINES THE VECTOR STRUCT AND SOME OPERATIONS ON IT
		TRIANGLE_OPS --> DEFINES THE TRIANGLE STRUCT AND SOME OPERATIONS ON IT
		WRITE_STL --> WRITES TRIANGLE STRUCTS TO STL FILES IN EITHER ASCII OR BINARY FORMAT
		SHAPES --> CREATES PRIMITIVE SHAPES FROM TRIANGLES (ONLY HAS UNIT CUBE FOR NOW)
	MODELS --> GENERATED STL FILES GO HERE
	

Both the "Modeling" and "Rendering" directories have "Build" directories which contain 
.bat scripts to build the projects on windows.