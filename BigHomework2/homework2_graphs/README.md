# Description

## Read input
Read all words from inpit file till there is "." string detected.
Store all words in vector DS for processing.
If we have more than 50 words or if single word length is greater than 10 we will
throw 'invalid_argument' exception.

## Graph
Directed graph will be represented as adjacency list using 'DirectedGraph' class.

## Main algorithm
Main algorithm will be implemented inside 'buildDependencyGraph' function.
We will iterate over all possible prefixes and build directed grap edges accordingly.

## Topological sorting
For topological sorting we will use Kahn's algorithm from wiki (https://en.wikipedia.org/wiki/Topological_sorting).
If topological sorting is not possible, we will throw 'invalid_argument' exception with approapriate message.

