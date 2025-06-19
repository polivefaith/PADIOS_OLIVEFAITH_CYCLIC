# PADIOS_OLIVEFAITH_CYCLIC
AC128 Assignment 2 Coding the Cyclic Graph

This project includes two C++ programs (`cyclic_bfs.cpp` and `cyclic_dfs.cpp`) that check for **cycles in a directed graph** using two different algorithms:

`cyclic_bfs.cpp` — Uses **Kahn's Algorithm** (Topological Sort via BFS)
`cyclic_dfs.cpp` — Uses **DFS-based Cycle Detection**

## Input Format
1. Enter the **number of vertices**
2. Then enter the **adjacency matrix**, line by line:
   - `1` means there is an edge from vertex `i → j`
   - `0` means no edge

## How to Compile and Run
You must have **g++** installed (via MinGW or WSL)

### 1. Open the Project Folder in VS Code
Make sure `cyclic_bfs.cpp` and `cyclic_dfs.cpp` are inside the same folder.
### 2️. Open Terminal in VS Code
### 3️. Compile the Programs
#### Compile `cyclic_bfs.cpp`
g++ cyclic_bfs.cpp -o cyclic_bfs
#### Compile `cyclic_dfs.cpp`
g++ cyclic_dfs.cpp -o cyclic_dfs
### 4. Run the Programs
./cyclic_bfs
./cyclic_dfs






