<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>
<hr style="border:4px solid gray"> </hr>

<div style="text-align: center;">
    
# Python Language Fundamental 3
## Source : [https://snakify.org/en/](https://snakify.org/en/)

</div>

<br><hr style="border:2px solid orange"> </hr>

# [<span style="color:yellow">*Lists*</span>](https://snakify.org/en/lessons/lists/)

* Python lists can hold `any combination of objects.`
* Lists are `mutable` universal containers.

<hr style="border:1px solid gray"> </hr>

*Example : Declare and access Python lists*

```Python 
Primes = [2, 3, 5, 7, 11, 13]
Rainbow = ['Red', 'Orange', 'Yellow', 'Green', 'Blue', 'Indigo', 'Violet']
Item = ["Apple", 13.5, 300, "Tainan"]

for i in range(len(Rainbow)):
    print(Rainbow[i], end=" ")

Rainbow[0] = 'red'
print()

for c in Rainbow:
    print(c,end=" ")
```

<hr style="border:1px solid gray"> </hr>

*Output :*
```
Red Orange Yellow Green Blue Indigo Violet 
red Orange Yellow Green Blue Indigo Violet 
```
<hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">L.append(Item)</span>](https://snakify.org/en/lessons/lists/)
* add Item to the end of list L

<hr style="border:1px solid gray"> </hr>

*Example : Generate a list L with N random numbers between 1 and 6*
```python
from random import randint

L=[]
for i in range(int(input())):
    L.append(randint(1,6))

for dat in L:
    print(dat, end=" ")
``` 

<hr style="border:1px solid gray"> </hr>

*Output :*
```
 20
4 6 1 2 2 1 6 1 5 1 4 6 1 4 5 1 5 5 4 2 
```

<hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow"> Split and join methods</span>](https://snakify.org/en/lessons/lists/#section_2)
* `split` and `join` are string methods
* `S.split(D)` cut the string `S` into a list with `D` as the separator; the separator is blank(s) by default
* `D.join(L)` uses `D` as a delimiter to join the list `L` into a string

<hr style="border:1px solid gray"> </hr>

*Example : split/join strings using different delimiters*
```python
S1 = "12 34 56"
L1 = S1.split()
S2 = ':'.join(L1)
L2 = S2.split(':')
print("S1 =", S1)
print("L1 =", L1)
print("S2 =", S2)
print("L2 =", L2)
```

<hr style="border:1px solid gray"> </hr>

*Output :*
```
S1 = 12 34 56
L1 = ['12', '34', '56']
S2 = 12:34:56
L2 = ['12', '34', '56']
```

<hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">Generators</span>](https://snakify.org/en/lessons/lists/#section_3)
*  The general form of a generator: `[expression for variable in sequence]`
    * `variable` is the ID of some variable
    * `sequence` is a sequence of values, which takes the variable (this can be a list, a string, or an object obtained using the function range)
    * `expression` — The list elements will be filled according to this expression.


<hr style="border:1px solid gray"> </hr>

*Example : list generator*
```python
L1 = [0 for i in range(10)]
L2 = [i*i for i in range(10)]
L3 = [[i*j for i in range(1,10)] for j in range(1,10)]

print("L1 =", L1)
print("L2 =", L2)

print()
for l in L3:
    for p in l:
        print('{0:3}'.format(p),end=" ")
    print()
```

<hr style="border:1px solid gray"> </hr>

*Output :*
```
L1 = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
L2 = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

  1   2   3   4   5   6   7   8   9 
  2   4   6   8  10  12  14  16  18 
  3   6   9  12  15  18  21  24  27 
  4   8  12  16  20  24  28  32  36 
  5  10  15  20  25  30  35  40  45 
  6  12  18  24  30  36  42  48  54 
  7  14  21  28  35  42  49  56  63 
  8  16  24  32  40  48  56  64  72 
  9  18  27  36  45  54  63  72  81 
```

<hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">Slices</span>](https://snakify.org/en/lessons/lists/#section_4)

* Except that lists are mutable, all slicing operations are similar to strings.

<hr style="border:1px solid gray"> </hr>

*Example : list slicing*
```python
A = list(range(10))
print("A         =", A)
print("A[3:7]    =", A[3:7])
print("A[7:3:-1] =", A[7:3:-1])
print("A[::2]    =", A[::2])
print("A[::-2]   =", A[::-2])
```

<hr style="border:1px solid gray"> </hr>

*Output :*
```
A         = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
A[3:7]    = [3, 4, 5, 6]
A[7:3:-1] = [7, 6, 5, 4]
A[::2]    = [0, 2, 4, 6, 8]
A[::-2]   = [9, 7, 5, 3, 1]
```

<hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">Operations on lists</span>](https://snakify.org/en/lessons/lists/#section_5)

| Operation  |                               Function                              |
|:----------:|---------------------------------------------------------------------|
| x in A     | return True if the list A contains element x                        |
| x not in A | return True if element x is not in the list A                       |
| min(A)     | return the smallest element of the list A                           |
| max(A)     | return the largest element in the list A                            |
| A.index(x) | return the index of the first occurrence of element x in the list A |
| A.count(x) | return the number of occurrences of element x in the list A         |

<hr style="border:1px solid gray"> </hr>

*Example : list operations*
```Python
A = [chr(ch) for ch in range(ord('a'),ord('f'))]
N = [A.append(ch) for ch in "abcaba"]
print("A             =", A)
print("'a' in A      =", 'a' in A)
print("'a' not in A  =", 'a' not in A)
print("not('a' in A) =", not('a' in A))
print("'k' not in A  =", 'k' not in A)
print("min(A)        =", min(A))
print("max(A)        =", max(A))
print("A.count('a')  =", A.count('a'))
print("A.count('b')  =", A.count('b'))
print("A.count('c')  =", A.count('c'))
print("A.index('e')  =", A.index('e'))
```

<hr style="border:1px solid gray"> </hr>

*Output :*
```
A             = ['a', 'b', 'c', 'd', 'e', 'a', 'b', 'c', 'a', 'b', 'a']
'a' in A      = True
'a' not in A  = False
not('a' in A) = False
'k' not in A  = True
min(A)        = a
max(A)        = e
A.count('a')  = 4
A.count('b')  = 3
A.count('c')  = 2
A.index('e')  = 4
```

<br><hr style="border:2px solid red"> </hr><br>

<div style="text-align: left;">
<img src="images/break-yang-tr.png" alt="Break" class="center" style="width: 600px;"/>
</div>


