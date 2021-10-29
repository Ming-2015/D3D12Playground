# D3D12Playground (Real Time)

A personal project that uses DX12 to implement various render techniques to ultimately create breathtaking real-time visuals. 

## Features to implement
### Implemented
1. Render a window

### To be implemented (speculative list, might not be in-order)
1. Font Renderer - For debugging, etc
    - D3D12 Interop with D2D
1. Forward rendering - Single Triangle
1. 3D object parser
1. Forward rendering - Multiple objects
1. Scene Graph
    - serializer and loader
1. Implement one or more of:
    - Deferred rendering (most likely)
    - Forward+ rendering
1. PBR Shader
1. Light clustering
1. Skybox
1. Local Shadows
    - Aliasing - Cascaded Shadow Map
    - Softening - Percentage Closer Filtering
1. Frustrum Culling
    - Spatial Partitioning? 
1. Occlusion Culling
    - Hi-Z Occlusion
1. Screen Space Ambient Occlusion (SSAO)
    - Ground Truth Ambient Occlusion (GTAO)
1. Screen Space Shadows
1. Anti-Aliasing
    - Temporal Anti Aliasing (TAA)
    - Fast approximate Anti-aliasing (FXAA)
    - Morphological Anti-Aliasing (MLAA)
1. Sky rendering
    - Atmospheric Scattering
    - Bruneton fog
    - Volumetric Cloud
1. Indirect Probe Lighting
    - A way to produce light probes (and maybe store them)
1. Post processing
    - Bloom
    - Depth of Field (DoF)
1. Water rendering
1. Reflection
    - Differed Reflection with reflection probes
    - Screen Space Reflection
1. Particles System
1. Decal system

## Open Source Libraries
### Integrated
1. DirectX Tool Kit for DirectX12, by Microsoft
1. D3D12 Memory Allocator, by AMD GPUOpen

### To be integrated (depending on the needs of feature implementation)
1. Assimp, for model loading
1. Imgui, for debug UI

## Documents, Papers, Literature, yada yada
A list of useful, information sources referenced, implicitly or explicitly, in the implementation of this project
1. Real Time Rendering, 4th Edition
1. DirectX 12 Programming Guide

## License
Default github license. All rights reserved until further notified. 