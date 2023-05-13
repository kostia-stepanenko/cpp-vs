# Main data models

We will implement Quad tree using 'QuadTree' class with a single root Node.

Every node of QuadTree will be impelemented as 'Node' class.

Node class will have color and child nodes (represented as vector<Node*>)

We use 'Color' enum to represent different colors of nodes: black, white, gray.


# Build Quad Tree from pre-order string

We will use 'QuadTree(string preOrderStr)' constructor to recursively build quad tree from pre-order string.
See code with comments for details.


# Merge trees

Merge operation will be implemented as 'QuadTree(const QuadTree& first, const QuadTree& second)' constructor.
See code comments for more details.


# Count black pixels

We will use recursive 'countBlackPixels' function to count the number of black pixels. 
We start from root node with dimenion 32x32 and traverse down the tree decreasing size by 2 for every level,