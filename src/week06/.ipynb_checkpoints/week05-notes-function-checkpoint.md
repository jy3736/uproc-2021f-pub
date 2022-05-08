<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>
<hr style="border:4px solid gray"> </hr>

<div style="text-align: center;">
    
# Python Language Fundamental 3
## Source : [https://snakify.org/en/](https://snakify.org/en/)

</div>

<br><hr style="border:2px solid orange"> </hr>

# [<span style="color:yellow">*Functions and recursion*</span>](https://snakify.org/en/lessons/functions/)

<hr style="border:1px solid gray"> </hr>

*Example : print factrial 3 and 5 without function*

```Python 
# compute 3!
res = 1
for i in range(1, 4):
    res *= i
print(res)

# compute 5!
res = 1
for i in range(1, 6):
    res *= i
print(res)
```

<hr style="border:0.5px solid gray"> </hr>

*Example : declare a factrial function 1*

```Python 
# compute n!
def fact(n):
    res = 1
    for i in range(1, n + 1):
        res *= i
    print(res)

fact(3)
fact(5)
```

<hr style="border:0.5px solid gray"> </hr>

*Example : declare a factrial function 2*

```Python 
# compute n!
def fact(n):
    res = 1
    for i in range(1, n + 1):
        res *= i
    return res

f3 = fact(3)
f5 = fact(5)
print(f3)
print(f5)
```

<hr style="border:1px solid gray"> </hr>

*Output :*
```
6
120
```
<hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">Local and global variables</span>](https://snakify.org/en/lessons/functions/#section_2)

<hr style="border:1px solid gray"> </hr>

*Example : local variable vs. global variable*

<table style="width: 100%;">
<tr>
<th style="width: 20%;"> Code </th>
<th style="width: 50%;" > Output </th>
</tr>
<tr>
<td>

```python
def f():
    print(a)

a = 1
f()
``` 
    
</td>
<td>

```
1
```

</td>
</tr>
</table>
   
<table style="width: 100%;">
<tr>
<th style="width: 20%;"> Code </th>
<th style="width: 50%;" > Output </th>
</tr>
<tr>
<td>

```python
def f():
    a = 1

f()
print(a)
``` 
    
</td>
<td>

```
NameError  Traceback (most recent call last)
<ipython-input-1-a6432c295a68> in <module>
      3 
      4 f()
----> 5 print(a)

NameError: name 'a' is not defined
```

</td>
</tr>
</table>

<table style="width: 100%;">
<tr>
<th style="width: 20%;"> Code </th>
<th style="width: 50%;" > Output </th>
</tr>
<tr>
<td>

```python
def f():
    a = 2
    print(a)

a = 1
f()
print(a)
``` 
    
</td>
<td>

```
2
1
```

</td>
</tr>
</table>
    
<table style="width: 100%;">
<tr>
<th style="width: 20%;"> Code </th>
<th style="width: 50%;" > Output </th>
</tr>
<tr>
<td>

```python
def f():
    global a
    a = 2
    print(a)

a = 1
f()
print(a)
``` 
    
</td>
<td>

```
2
2
```

</td>
</tr>
</table>
    
<hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow"> Function returns multiple values</span>](https://snakify.org/en/lessons/functions/#section_2)

<hr style="border:1px solid gray"> </hr>

*Example : return max and min values of the given list*
```python
from random import randrange

def max_min(L):
    return [max(L), min(L)]

LA = [randrange(100) for i in range(10)]
a, b = max_min(LA)

print("LA =", LA)
print('After calling "a, b = max_min(LA)"')
print("a  =", a)
print("b  =", b)
```

<hr style="border:1px solid gray"> </hr>

*Output :*
```
LA = [95, 92, 33, 66, 33, 91, 85, 44, 72, 38]
After calling "a, b = max_min(LA)"
a  = 95
b  = 33
```
<hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">Recursion</span>](https://snakify.org/en/lessons/functions/#section_3)

<hr style="border:1px solid gray"> </hr>

*Example : aggregate all numbers in a given list*
```python
from random import randrange

def sum_iter(L):
    s = 0
    for v in L:
        s+=v
    return s

def sum_recu(L):
    if len(L)==1:
        return L[0]
    else:
        return sum_recu(L[1:])+L[0]

LR = [randrange(10) for i in range(10)]

print("LR =", LR)
print("sum_iter(LR) =", sum_iter(LR))
print("sum_recu(LR) =", sum_recu(LR))
print("sum(LR)      =", sum(LR))
```

<hr style="border:1px solid gray"> </hr>

*Output :*
```
LR = [8, 5, 9, 1, 9, 5, 6, 9, 2, 8]
sum_iter(LR) = 62
sum_recu(LR) = 62
sum(LR)      = 62
```

<br><hr style="border:2px solid red"> </hr><br>

<div style="text-align: left;">
<img src="images/break-yang-tr.png" alt="Break" class="center" style="width: 500px;"/>
</div>


