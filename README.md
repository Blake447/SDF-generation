# SDF-generation
SDF-generation for raymarching arbitrary functions

To generate the shader for a function, modify the c++ program sdf-gen. You must give it a function, its derivative, and its second derivative. Make sure these are strings that when evaluated in GLSL, will evaluate to a float.

On top of this, make sure to include a list of all points that are extrema, inflection points, or vertical asymptotes (not tested yet). Additionally, specify the correct number of these points. As of right now, they must be in ascending order (sorting function not tested yet.)

To use, compile with a c++ compiler like g++. Make sure to use the c++11 standard. compilation example:

g++ sdf-gen.cpp -std=c++11

Copy the output into shadertoy in order to render the sdf for the function fed into the shader. If you get any compiler errors, (specifically from improperly formating the functions) it is much easier to fix it inside shadertoy.
