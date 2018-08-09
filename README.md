# tmpGLM4D
A simplified version of GLM plus extensions for 4D geometry

This is meant to be a temporary, simplified stand-in for GLM. The features implemented have the same API as those in GLM. In parallel, once the need for performance and flexibility is large enough, this may be replaced by fourveo/GLM4D. Once the 4D features have been properly implemented in GLM4D, it can be a drop-in replacement for this library.

Borrowed from GLM:
- vec1, vec2, vec3, vec4, and basic operators
- mat3x3, mat4x4, and basic operators
- matrix operations for mat3x3 and mat4x4
- [what else?]

Added for 4D:
- vec5, vec6, and basic operators
- "cross product" for vec4's
- mat5x5, and basic operators
- maxtrix operations for mat5x5
- quaternion-like rotation for 4D
- [what else?]
