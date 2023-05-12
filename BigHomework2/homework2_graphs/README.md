# Description

## Read from file
Read all words from inpit file 'index.in' till there is "." string detected using 'readWordsFromFile' function.
Store all words in vector DS for processing.
If we have more than 50 words or if single word length is greater than 10 we will
throw 'invalid_argument' exception.

## Write to file
Index value will be written as single string value to file 'index.out' using 'writeToFile' function.

## Graph
Directed graph will be represented as adjacency list using 'DirectedGraph' class.

## Main algorithm
Main algorithm will be implemented inside 'buildDependencyGraph' function.
We will iterate over all possible prefixes and build directed grap edges accordingly.

## Topological sorting
For topological sorting we will use Kahn's algorithm from wiki (https://en.wikipedia.org/wiki/Topological_sorting).
If topological sorting is not possible, we will throw 'invalid_argument' exception with approapriate message.

