# Graph Concepts

## Example Graph

```text
    A
   / \
  5   3
 /     \
B ----- C
    2
```

Vertices (nodes): A, B, C

Edges (connections):
- A — B (weight 5)
- A — C (weight 3)
- B — C (weight 2)

---

## 1. Undirected Graph (Non-Directed Graph)

In an undirected graph, connections work both ways.

```text
A ----- B
```

This means:
- A is connected to B
- B is connected to A

No arrow is used because the relationship is mutual.

### Real-world Example
Friendship on social media:
- If Alice is a friend of Bob, Bob is also a friend of Alice.

---

## 2. Directed Graph

In a directed graph, edges have a direction.

```text
A -----> B
```

This means:
- A can go to B
- It does NOT automatically mean B can go to A

### Real-world Example
Following on social media:
- A follows B
- B may not follow A

---

## 3. Vertex (Plural: Vertices)

A vertex is a point or node in the graph.

```text
A ----- B ----- C
```

Vertices are:
- A
- B
- C

### Real-world Example
In a city map:
- Each city is a vertex.

---

## 4. Edge

An edge is a connection between two vertices.

```text
A ----- B
```

The line between A and B is an edge.

### Real-world Example
In a road network:
- Cities = vertices
- Roads = edges

---

## 5. Weight

A weight is a value assigned to an edge.

```text
A --5-- B
```

Weight = 5

The weight can represent:
- Distance
- Cost
- Time
- Traffic
- Strength of relationship

### Example

```text
A --10-- B
A --20-- C
```

Meaning:
- Distance from A to B = 10 km
- Distance from A to C = 20 km

---

## 6. Degree

The degree of a vertex is the number of edges connected to it.

Example:

```text
    B
    |
A---C---D
    |
    E
```

- Degree(A) = 1
- Degree(B) = 1
- Degree(C) = 4
- Degree(D) = 1
- Degree(E) = 1

### For Directed Graphs

```text
A -----> B -----> C
 \               ^
  \-------------/
```

There are two types of degree:

| Type | Meaning |
|------|---------|
| In-degree | Number of incoming edges |
| Out-degree | Number of outgoing edges |

For the graph above:

- A: In-degree = 0, Out-degree = 2
- B: In-degree = 1, Out-degree = 1
- C: In-degree = 2, Out-degree = 0

---

## Quick Summary

| Concept | Meaning | Example |
|----------|----------|----------|
| Vertex | A node in a graph | A, B, C |
| Edge | Connection between vertices | A—B |
| Undirected Graph | Connection works both ways | A—B |
| Directed Graph | Connection has direction | A→B |
| Weight | Value on an edge | A—5—B |
| Degree | Number of connected edges | Degree(C)=4 |

### Road Map Example

- Cities → Vertices
- Roads → Edges
- Road distance → Weight
- One-way roads → Directed edges
- Two-way roads → Undirected edges
- Number of roads connected to a city → Degree
