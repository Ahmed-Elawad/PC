# Basic Boolean algebra logic

Operates on data represented in a Binary state - hence 'Boolean' algebra.

<br/>
<br/>

<b>X ^ Y</b>
X | Y | Returns
---|---|---
0 | 0 | 1

<br/>
<br/>

<b>X V Y</b>
X | Y | Returns
---|---|---


<br/>
<br/>

<b>NOT X</b>
X | Returns
--- | ---
1 | 0


<br/>
<br/>

Once basic operations are defined we can combine them similar to how mathimatical operations are applied.


```
f(x,y,z) = (x AND y) OR (NOT(X) AND  z)
```


<br/>
<br/>
Furthermore, there are common laws as with standard mathimatics.

<b>Cummulative Law</b>

<b>Associative Law</b>

<b>Distributive Law</b>

<b>De Morgans Law</b>

# Negative numbers

2s compliment notation is most often used for representing negative numbers. The preceeding method was using a signed bit to denote a negative(0) or positive(1) number. The following bits represent the negative number.
<br/>
<br/>

2s compliment:

```
Represent negative numbers -x using the positive number: 2^n -x

n = number of bits

3 = 0011
-3 = 2^n - 3 = 2^4 - 3 = 16 - 3 = 13 = 1101


While using 2s complement notation we half our range of values we can represent with n bits. Since the msb is used to represent a negative value

Positive 3: 0011
Negative 3: 1101 (2^n - x where x = the value we want to represent(3) 
                and n = number of available bits )
                so  2^(4)-3 = 16

Standard Notation: 2^(n-1)
2s compliment notation: 2^(n-1) -1
                        -2^(n-1)
```

Gate logic does not need modification to accomodate subtraction using 2s compliment.

<b>Why???</b>

```
-2  > 1110 || 14
+ 
-3  > 1101 || 13
__________________
     11011 = 16 + 8 + 2 + 1 = 27
     
final bit is actually thrown away so:
1011 which = 11 or in 2s compliment notation = -5

```

Binary addition is % 2^n

Binary representation is % 2^n


