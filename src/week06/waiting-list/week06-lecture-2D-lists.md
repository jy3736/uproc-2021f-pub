<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>

<hr style="border:4px solid gray"> </hr>

<br><br>
<div style="text-align: center;">    
    
    
# [2-Dimensional Lists (Arrays)](https://snakify.org/en/lessons/two_dimensional_lists_arrays/)
    
#### Source : *https://snakify.org/en/lessons/two_dimensional_lists_arrays/*

</div>

<br><br><hr style="border:2px solid orange"> </hr>

# [<span style="color:yellow">*Nested Lists: processing and printing*</span>](https://snakify.org/en/lessons/lists/)

* In the real world, usually tasks must store rectangular data `tables`. 
* Such tables are called `matrices` or `two-dimensional arrays`. 
* In Python any table can be represented as `a list of lists`.

<hr style="border:1px solid white"> </hr>

<div style="font-size:150%;">
    
*Example : A list of lists*

</div>
    
```Python 
L1 = [1, 5, 4, 3, 2, 4, 3, 5, 3, 6]
L2 = [1, 1, 5, 2, 5, 3]
L3 = [5, 4, 6, 5]
M1 = [L1,L2,L3]

print(M1)
```

<hr style="border:0.5px solid gray"> </hr>

*Output :*
```
[[1, 5, 4, 3, 2, 4, 3, 5, 3, 6], [1, 1, 5, 2, 5, 3], [5, 4, 6, 5]]
```

<hr style="border:1px solid white"> </hr>

<div style="font-size:150%;">
    
*Example : Print out matrix*

</div>
    
```Python 
def printMatrix(m):
    for l in m:
        for e in l:
            print(f"{e:4}",end="")
        print()

L1 = [1, 5, 4, 3, 2, 4, 3, 5, 3, 6]
L2 = [1, 1, 5, 2, 5, 3]
L3 = [5, 4, 6, 5]
M1 = [L1,L2,L3]

printMatrix(M1)
```

<hr style="border:0.5px solid gray"> </hr>

*Output :*
```
   1   5   4   3   2   4   3   5   3   6
   1   1   5   2   5   3
   5   4   6   5
```

<hr style="border:1px solid white"> </hr>

<div style="font-size:150%;">
    
*Example : Random matrix generator 1*

</div>
    

```Python 
from random import randrange

def mkMatrix(R, C=0):
    m=[]
    for r in range(R):
        mr=[randrange(1,7) for c in range(randrange(5,11) if C==0 else C)]
        m.append(mr)
    return m

def printMatrix(m):
    for l in m:
        for e in l:
            print(f"{e:4}",end="")
        print()

M1 = mkMatrix(5,3)
M2 = mkMatrix(5)
print("M1 :")
printMatrix(M1)
print("\nM2 :")
printMatrix(M2)
```

<hr style="border:0.5px solid gray"> </hr>

*Output :*
```
M1 :
   1   1   6
   2   3   6
   2   3   1
   2   2   2
   2   1   4

M2 :
   5   4   5   1   6   5   3   4
   2   1   3   1   4
   5   5   4   4   3
   6   6   1   1   6   5   4   3   2
   2   5   2   2   2   5   2   3   6   1
```

<hr style="border:1px solid white"> </hr>

<div style="font-size:150%;">
    
*Example : Random matrix generator 2*

</div>
    

```Python 
from random import randrange

def mkMatrix(R, C=0):
    cs = [randrange(5,11) if C==0 else C for r in range(R)]
    m  = [[randrange(1,7) for i in range(c)] for c in cs]
    return m

def printMatrix(m):
    for l in m:
        for e in l:
            print(f"{e:4x}",end="")
        print()

M1 = mkMatrix(5,3)
M2 = mkMatrix(5)
print("M1 :")
printMatrix(M1)
print("\nM2 :")
printMatrix(M2)
```

<hr style="border:0.5px solid gray"> </hr>

*Output :*
```
M1 :
   3   4   6
   1   2   4
   2   1   3
   3   5   4
   2   4   4

M2 :
   4   2   6   6   2   4
   3   6   6   6   6   1   6   6
   6   2   6   4   3   2   1   5   2
   6   4   2   3   3
   1   2   2   5   2
```


<br><br><hr style="border:2px solid orange"> </hr>

# [<span style="color:yellow">*How do you input a two-dimensional array?*</span>](https://snakify.org/en/lessons/two_dimensional_lists_arrays/#section_3)

* Given an input sequence and parse it into a 2D array.

```python
# input data
3
1 2 
4 5 6 6 6
7 8 9

# parsed Python matrix
[[1, 2], [4, 5, 6, 6, 6], [7, 8, 9]]

```
<hr style="border:1px solid white"> </hr>

<div style="font-size:150%;">
    
*Parse a serial of input() into a 2D array*

</div>
    
```Python 
def printMatrix(m):
    for l in m:
        for e in l:
            print(f"{e:4x}",end="")
        print()
    print()
```

<hr style="border:0.5px solid gray"> </hr>

*Method 1:*    
    
```Python  
n = int(input()) 
a1 = []
for i in range(n):
    row = []
    for c in input().split():
        row.append(int(c))
    a1.append(row)
```

<hr style="border:0.5px solid gray"> </hr>

*Method 2:*    
    
```Python  
n = int(input()) 
a2 = []
for i in range(n):
    a2.append([int(j) for j in input().split()])
```

<hr style="border:0.5px solid gray"> </hr>

*Method 3:*    
    
```Python  
n = int(input()) 
a3 = [[int(j) for j in input().split()] for i in range(n)]
```

<hr style="border:0.5px solid gray"> </hr>

```Python  
printMatrix(a1)
printMatrix(a2)
printMatrix(a3)
```

*Output :*
```
   2   3   4   5
   4   4   4
   3   4   2   3   4

   1   2   3
   4   5   6
   7   8   9

   1   1   1
   2   2   2
   3   3   3   3   3   3   3
```

<br>

<hr style="border:2px solid orange"> </hr>
<br>

<div style="text-align: left;">
<img src="images/break-yang-tr.png" alt="Break" class="center" style="width: 500px;"/>
</div>


