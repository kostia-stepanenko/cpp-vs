# Main algorithm explained

We will do Depth-first search for each connected component of a graph.
For each DFS we will find the vertex(es) that doesn't have any OUT edges.
We will save all such vertexes as 'candidates'.

At the end we will check the following conditions:
1. If we have only ONE candidate, we will check if all other vertexes connected to candidate. 
If yes, we found Homer, otherwise there is no Homer.
2. If the number of candidates is NOT equal to 1, we don't have Homer at all.
