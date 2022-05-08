<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>

<hr style="border:4px solid gray"> </hr>

<br><br>
<div style="text-align: center;">    
<br>    
    
# [Sets](https://snakify.org/en/lessons/sets/) and [Dictionaries](https://snakify.org/en/lessons/dictionaries_dicts/)
    
#### Source : *https://snakify.org/en*

</div>

<br>
<hr style="border:4px solid gray"> </hr>


<br>
<hr style="border:2px solid orange"> </hr>

### What is a set

* Set in Python is a data structure `equivalent to sets in mathematics`. 
* It may consist of various elements; the order of elements in a set is undefined. 
* You can perform standard operations on sets (`union`, `intersection`, `difference`). 
* Besides that, you can check if an element belongs to a set.
* Unlike arrays, the order of elements in a set is undefined.
* Any `immutable data type` can be an element of a set: a number, a string, a tuple. In particular, list `cannot` be an element of a set.


<br>
<hr style="border:2px solid orange"> </hr>

### How to define a set?



```python
s1 = {1,2,3}
s2 = {4,'s', 5, 4.6, (1,2,3)}
s3 = set()
s4 = set('Hello Python')
s5 = set([5,6,7,8])

for s in s1,s2,s3,s4,s5:
    print(s,end="\n\n")
```

<hr style="border:0.1px solid gray"> </hr>

    {1, 2, 3}
    {4, 5, 4.6, (1, 2, 3), 's'}
    set()
    {'t', 'l', 'o', 'n', 'P', 'h', ' ', 'H', 'y', 'e'}
    {8, 5, 6, 7}
    

<br>
<hr style="border:2px solid orange"> </hr>

### Operations with elements


```python
s = set()
s.add(1)
s.add(99)
s.add((3,4,5))
print(s)
```

<hr style="border:0.1px solid gray"> </hr>

    {(3, 4, 5), 1, 99}
    
<hr style="border:0.1px solid gray"> </hr>

```python
s.remove(99)
print(s)
s.remove(99)
print(s)
```

<hr style="border:0.1px solid gray"> </hr>


    {(3, 4, 5), 1}
    

    KeyError                                  Traceback (most recent call last)

    <ipython-input-24-37cf2c2c00b7> in <module>
          1 s.remove(99)
          2 print(s)
    ----> 3 s.remove(99)
          4 print(s)
    

    KeyError: 99

<hr style="border:0.1px solid gray"> </hr>

```python
s.discard(1)
print(s)
s.discard(1)
print(s)
```

<hr style="border:0.1px solid gray"> </hr>

    {(3, 4, 5)}
    {(3, 4, 5)}
    
<hr style="border:0.1px solid gray"> </hr>

```python
e = s.pop()
print(s)
print(e)
```

<hr style="border:0.1px solid gray"> </hr>

    set()
    (3, 4, 5)
    
<hr style="border:0.1px solid gray"> </hr>

```python
e = s.pop()
```

<hr style="border:0.1px solid gray"> </hr>


    KeyError                                  Traceback (most recent call last)

    <ipython-input-27-8042c8236e18> in <module>
    ----> 1 e = s.pop()
    

    KeyError: 'pop from an empty set'

<br>
<hr style="border:2px solid orange"> </hr>

### Well-known operations on sets

| Operation                 | Equivalent | Result                                              |
|---------------------------|------------|-----------------------------------------------------|
| len(s)                    |            | number of elements in set s (cardinality)           |
| x in s                    |            | test x for membership in s                          |
| x not in s                |            | test x for non-membership in s                      |
| s.issubset(t)             | s <= t     | test whether every element in s is in t             |
| s.issuperset(t)           | s >= t     | test whether every element in t is in s             |
| s.union(t)                | s \| t     | new set with elements from both s and t             |
| s.intersection(t)         | s & t      | new set with elements common to s and t             |
| s.difference(t)           | s - t      | new set with elements in s but not in t             |
| s.symmetric_difference(t) | s ^ t      | new set with elements in either s or t but not both |
| s.copy()                  |            | new set with a shallow copy of s                    |

<hr style="border:0.1px solid gray"> </hr>

```python
s1 = set(range(10))
s2 = set(range(0,10,2))
s3 = set(range(1,10,2))
dummy = [print(s) for s in [s1,s2,s3]]
print("s1==s2  : ",s1 == s2)
print("s1>=s2  : ",s1 >= s2)
print("s1 & s2 : ",s1 & s2)
print("s2 | s3 : ",s1 | s3)
print("s1 - s2 : ",s1 - s2)
print("s1 ^ s2 : ",s1 ^ s2)
print("s2 ^ s3 : ",s2 ^ s3)
```

<hr style="border:0.1px solid gray"> </hr>

    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}  
    {0, 2, 4, 6, 8}
    {1, 3, 5, 7, 9}
    s1==s2  :  False
    s1>=s2  :  True
    s1 & s2 :  {0, 2, 4, 6, 8}
    s2 | s3 :  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    s1 - s2 :  {1, 3, 5, 7, 9}
    s1 ^ s2 :  {1, 3, 5, 7, 9}
    s2 ^ s3 :  {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    
<br>

<hr style="border:2px solid orange"> </hr>
<br>

<div style="text-align: left;">
<img src="images/break-yang-tr.png" alt="Break" class="center" style="width: 500px;"/>
</div>



```python

```
