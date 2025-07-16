# Dijkstra Algorithm
 This folder contains problems that rely on **Dijkstra’s algorithm** for finding shortest paths in weighted graphs. Each problem explores a different application or twist on the core algorithm.

## Key Concepts
- Dijkstra’s algorithm using min-priority queue (heap)
- Path reconstruction via parent arrays
- Multi-source shortest path
- Edge analysis for fractional distances
- Real-world applications of shortest path logic

---

## Dijkstra’s Algorithm – Overview

Dijkstra’s algorithm finds the shortest path from a **source node** to all other nodes in a graph with **non-negative edge weights**. It relies on:

- A **min-priority queue (min-heap)** to greedily expand the next closest unvisited node.
- An array of distances `dist[]` where `dist[v]` is the shortest known distance from the source to node `v`.
- A **visited array** or set to avoid revisiting nodes.

---

### Key Steps in Order:
1. Initialize all distances as ∞ except for the source node (0).
2. Push the source node into the min-heap.
3. While the heap is not empty:
   - Pop the node `u` with the smallest `dist[u]`.
   - For each neighbor `v` of `u`, if `dist[v] > dist[u] + w`, update `dist[v]` and push `v` into the heap.

This greedy strategy ensures that once we pop a node from the queue, we’ve found the **shortest** path to it.

---

## Example Problems (from Codeforces)

These problems demonstrate the application of sorting in diverse algorithmic contexts beyond simple array manipulation.

| Problem | Tags |
|--------|------|
| [CF 20C - Dijkstra?](https://codeforces.com/problemset/problem/20/C) | Graphs, Shortest Paths, Dijkstra's Algorithm, Path Reconstruction, Greedy |
| [CF 144D - Missile Silos](https://codeforces.com/problemset/problem/144/D) | Graphs, Dijkstra's Algorithm, Shortest Paths, Edge Case Handling, Exact Distance Count |
| [CF 1349C - Orac and Game of Life](https://codeforces.com/problemset/problem/1349/C) | Graphs, BFS, Multi_source BFS, Grid simulation, 2D Grids |

---

##  What You'll Learn

- Implementing Dijkstra with optimal time complexity `O(M log N)`
- Maintaining correct processing order using a heap
- Adapting Dijkstra to unusual requirements (edge fractions, BFS-style use)
- Reconstructing shortest paths

--

## Objective

This section is designed to:
- Showcase a foundational understanding of Dijkstra’s algorithm for shortest path computation.
- Demonstrate practical applications of Dijkstra’s algorithm in varied problem settings, including path reconstruction, distance constraints, and grid-based propagation.
- Highlight flexibility in adapting Dijkstra’s algorithm to non-standard environments such as time-evolving states and mixed edge-node distance queries.

---
