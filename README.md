# 3D Donut Console Renderer

### General Information  
**3D Donut Console Renderer** is a small C++ console project that renders a rotating 3D donut using ASCII characters.  
The project is inspired by **A1k0n's donut** from the internet and demonstrates basic **3D rotation, projection, and shading** in a terminal window.  

**Technologies used:**
- C++20
- Standard library only
- Console rendering

---

### How to Build and Run

#### Prerequisites
- Visual Studio 2022 (or compatible)
- Windows / Linux / macOS console

### Steps
1. Clone the repository:
```
git clone https://github.com/tiagzoc/DonutMath.git
```
2. Go to the .exe file :
> Note: you can find it in the x64/Debug folder.
```
cd x64/Debug
```
3. Open a cmd and write this command:
> Note: The list of all possible parameters is after this part.
```
.\DonutMath.exe -r 128
```
> Note: You can also open the .sln with an IDE and modify the running parameters.

> The donut will continuously rotate in the terminal until you close the window.

---

### How the Project Works
- Computes 3D coordinates of a torus (donut) in real-time.
- Applies rotation along X, Y, and Z axes.
- Projects 3D points onto 2D console coordinates.
- Calculates simple luminance for ASCII shading.
- Updates the console frame by frame for animation.

---

### What I Learned
- Implemented **3D rotation and projection** in a minimal C++ project.
- Learned to **render graphics in the console** using ASCII.
- Practiced **trigonometry, matrices, and frame-based animation**.
- Explored **performance optimizations** for real-time console rendering.

---

### Possible Improvements
- Add color support in the console.
- Expand to render other 3D shapes.

