# Elements of computing

These are notes I've recorded while working through the text "Elements of Computing". I'm only as skilled as my memory. Hoping this can help me retain concepts for later recollection.

## Introduction

Computers use a heterogenous set of gates to represent the logic they can execute. The components may be derived from different materials, but the logic is conistent.

ALl computing systems operate on binary codes - which is all we can represent at the time being. These modes are constructed into logic gates that are combined to represent a system that can execute computation.

The reading presents information in a consistent format of sections.

Primary sections will provide prerequisite knowlege for completion or comprehension of the learning.

Secondary sections will provide specifications of the abstract problem to be solved through hardware or software configuration.

Final sections will provides implementation details or a enumerated list of tasks to achieve the soluition.

A perspective section will conlude with key topics and technical projects to dive deeper.

## Prerequisites


Boolean Algebra: The computation of inputs of binary values and their result using functions.

Notation for boollean algebra uses common math symbols to represent the state evaluation:

Not means the opposite value

so: not(1) = 0, not(0) = 1

It's a flip of a value, logical operations

Notation | Meaning
---|---
x *  y, xy | x AND y
x + y | x OR y
(line above) x | NOT x

```
Example:

f(x,y,z) = (x + y) * (NOT) y

(x Or Y) AND NOT z

f(1,0,1) = (1 OR 0) AND NOT 1

(1 OR 0) = 1

1 AND (NOT 1) = 1 AND 0 = 0


```
<br/>


<b>Connonical Representations</b>

In simple terms this is just the syntax for writing out the combination of values where f(x,...n) = 1.

The syntax is intended to state: term(a) OR term(b) OR term(c) will result in true, 1, or yes, where:

any of the terms = the combination of 1s and 0s


<br/>
<br/>

# Trying to understand the capibilities and limitations

We have two possible states: 0 & 1

We are defining logical operations and trying to build an algorithm to compute a result

What are the permutations of the results possible with a binary system?

```
 x : 0, 0, 1, 1
_______________________
 Y : 0, 1, 0, 1

```

What are the functions(logical statements) representing the results of these inputs? What can we test

And, Or, Not

<!-- insert an image from the Resources directory -->
<img src="./Resources/FunctionsTable.png">


<br/>
<br/>
<br/>

# Questions

How were the logical functions derived? Were they based on the result of the table, or was it related to testing the inputs and their result?
- thinking of NOR and Nand gates in particular. They get the result of the input and then do some logical mutation to it. So I'm assuming we wanted to get more out of the basic outputs to represent something.

<br/>

# References: 

Elements of computing Chapter 1: 
https://b1391bd6-da3d-477d-8c01-38cdf774495a.filesusr.com/ugd/44046b_f2c9e41f0b204a34ab78be0ae4953128.pdf



Chat GPT: asked some questions for context:
- What are pneumatic mechanisms: section 1.1.2 p 2 of ["Elements of computing"](https://b1391bd6-da3d-477d-8c01-38cdf774495a.filesusr.com/ugd/44046b_f2c9e41f0b204a34ab78be0ae4953128.pdf)
- 


# Glossary

<b>Gate : </b> A physical device that implements boolean logic through a boolean function(in the context of computers)