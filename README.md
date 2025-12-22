# 3D Donut Console Renderer

### THIS PROJECT WAS MADE BY ONE PERSON
### CONTRIBUTOR:
- [Your Name]

---

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
- CMake >= 3.20 (optional, can also compile directly)
- Windows / Linux / macOS console

#### Steps
1. Clone the repository:
git clone <your-repo-url>
2. Compile:
g++ -std=c++20 main.cpp -o Donut
3. Run:
./Donut

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
- Support resizing of the donut or adjustable rotation speed.
- Implement double buffering to reduce flickering.
- Expand to render other 3D shapes.

---

### License
Personal project – 2025
