# chromatic_polyn

Topic: graph theory

A chromatic polynomial comes from a graph where the goal is to color the nodes of the graph 
but adjecent nodes cannot be the same color.

ex. 
       (a) 0
           |
           |
(g)0----(b)0-----(c)0
          / \
         /   \
     (e)0--(f)0
     
if x represents the number of colors available to color the nodes the number of ways to color the graph 
is x*{(x-1)^4}*(x-2). Including all permutations of the colorings.

So far:
  -README.md - duh
  -polyn.cpp - a polynomial class to multiply polynomials
  
To do:
  -file_parser - read in a file to generate a graph from format where a->b represents an edge from node a to node b
                 each edge must be on its own line
  -graph class - a class to hold the graph
  -node class  - a class to represent nodes 
  
Dream:
  -Add graphics to show different colorings
