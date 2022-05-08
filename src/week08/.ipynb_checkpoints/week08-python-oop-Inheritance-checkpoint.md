<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>

<hr style="border:4px solid gray"> </hr>

<div style="text-align: center;">    
<br>    
    
# [Python Object Oriented Programming](https://www.programiz.com/python-programming/object-oriented-programming)

# Code Reuse via Inheritance

</div>

<br>
<hr style="border:4px solid gray"> </hr>


<hr style="border:2px solid orange"> </hr>

## [Inheritance](https://codefellows.github.io/sea-python-401d4/lectures/inheritance_v_composition.html)

* `Everything in Python is an object`. Modules are objects, class definitions and functions are objects, and of course, objects created from classes are objects too.
* In object-oriented programming (OOP), `inheritance` is a way to reuse code of existing objects. 
* `Objects` are defined by `classes`, classes can inherit `attributes and behavior` from pre-existing classes. The resulting classes are known as `derived classes` or `subclasses`.
* A `subclass` “inherits” all the attributes (methods, etc) of the `parent class`. 
    * We can `create new` attributes or methods to add to the behavior of the parent.
    * We can `change (“override”)` some or all of the attributes or methods to change the behavior. 
    * We can also `extend` the behavior of the parent by `using the original methods` and adding a bit more.

###### Source: https://codefellows.github.io/sea-python-401d4/lectures/inheritance_v_composition.html

<hr style="border:2px solid orange"> </hr>

## Complex class from previos lecture:


```python
class Complex:
    
    # constructor
    def __init__(self, real=0.0, img=0.0):
        if isinstance(real, Complex):
            self.real = real.real
            self.img = real.img
        else:
            self.real = real
            self.img  = img
    
    # print all attributes
    def attributes(self):
        print(self.__class__.__name__, self.__dict__)
        
    # self = (self + Complex c)
    def _add(self, c):
        c = Complex(c)
        self.real += c.real
        self.img += c.img
    
    # return (self + Complex c)
    def add(self, c):
        cr = Complex(self)
        cr._add(c)
        return cr
    
    # operator overloading +
    def __add__(self, c):
        return self.add(c)
    
    # Improve the readability of str() and print() functions
    def __str__(self):
        return f"{self.real} + {self.img}i"
```

<hr style="border:2px solid orange"> </hr>

## Overloading attributes/methods


```python
class myComplex(Complex):
    
    # The constructor uses the constructor of the parent class
    def __init__(self, r=0.0, i=0.0):
        super().__init__(r,i)
    
    # overload operator - (negative)
    def __neg__(self):
        return myComplex(-self.real, -self.img)
```

<hr style="border:0.5px solid gray"> 


```python
c1 = myComplex(-2,2)
c2 = myComplex(4,-2)
print(f"-({c1}) = {-c1}")
print(f"-({c2}) = {-c2}")

# Output:
# --------------------------------------
```

    -(-2 + 2i) = 2 + -2i
    -(4 + -2i) = -4 + 2i
    

<hr style="border:2px solid orange"> </hr>

## Create new methods by reusing the methods of the parent class


```python
class myComplex(Complex):
    
    # The constructor uses the constructor of the parent class
    def __init__(self, r=0.0, i=0.0):
        super().__init__(r,i)
    
    # overload operator - (negative)
    def __neg__(self):
        return myComplex(-self.real, -self.img)
    
    # implement sub as (self + (-c))
    def sub(self,c):
        return super().add(-c)
    
    # overload operator - (substraction)
    def __sub__(self,c):
        return self.sub(c)
```

<hr style="border:0.5px solid gray"> 


```python
c1 = myComplex(-2,2)
c2 = myComplex(4,-2)
print(-c1)
print(c1.sub(c2))
print(c1-c2)

# Output:
# --------------------------------------
```

    2 + -2i
    -6 + 4i
    -6 + 4i
    

<hr style="border:2px solid orange"> </hr>

## Override the method of the parent class


```python
class myComplex(Complex):
    
    # The constructor uses the constructor of the parent class
    def __init__(self, r=0.0, i=0.0):
        super().__init__(r,i)

    # overload operator - (negative)
    def __neg__(self):
        return myComplex(-self.real, -self.img)
    
    # implement sub as (self + (-c))
    def sub(self,c):
        return super().add(-c)
    
    # overload operator - (substraction)
    def __sub__(self,c):
        return self.sub(c)
    
    # 'override' __str__() by reusing the __str__() of the parent class
    def __str__(self):
        if self.real!=0:
            if self.img>0:
                return super().__str__()   # parent-class's __str__
            elif self.img<0: 
                return f"{self.real} - {-self.img}i"
            else:
                return f"{self.real}"
        else:
            if self.img==0:
                return "0"
            else:
                return f"{self.img}i"     
```

<hr style="border:0.5px solid gray"> 


```python
print(myComplex(1,3))
print(myComplex(1,-2))
print(myComplex(0,-2))
print(myComplex(0,0))
print(myComplex(-1,0))
print(myComplex(-1,-1))

# Output:
# --------------------------------------
```

    1 + 3i
    1 - 2i
    -2i
    0
    -1
    -1 - 1i
    

<hr style="border:2px solid orange"> </hr>

## Why does the overrided \_\_str\_\_() not work?


```python
c1 = myComplex(0,0)
c2 = myComplex(-1,-1)
c3 = myComplex(-1,-1) - myComplex(-1,-1)
c4 = myComplex(-1,-1).add(c1)
print(f"c1 = {c1}")
print(f"c2 = {c2}")
print(f"c3 = {c3}")
print(f"c4 = {c4}\n")
print(f"type(c1) = {type(c1)}")
print(f"type(c2) = {type(c2)}")
print(f"type(c3) = {type(c3)}")
print(f"type(c4) = {type(c4)}")

# Output:
# --------------------------------------
```

    c1 = 0
    c2 = -1 - 1i
    c3 = 0 + 0i
    c4 = -1 + -1i
    
    type(c1) = <class '__main__.myComplex'>
    type(c2) = <class '__main__.myComplex'>
    type(c3) = <class '__main__.Complex'>
    type(c4) = <class '__main__.Complex'>
    

<hr style="border:2px solid orange"> </hr>

## A quick way to solve the problem


```python
c1 = myComplex(0,0)
c2 = myComplex(-1,-1)
c3 = (myComplex)(myComplex(-1,-1) - myComplex(-1,-1))
c4 = (myComplex)(myComplex(-1,-1).add(c1))
print(f"c1 = {c1}")
print(f"c2 = {c2}")
print(f"c3 = {c3}")
print(f"c4 = {c4}\n")
print(f"type(c1) = {type(c1)}")
print(f"type(c2) = {type(c2)}")
print(f"type(c3) = {type(c3)}")
print(f"type(c4) = {type(c4)}")

# Output:
# --------------------------------------
```

    c1 = 0
    c2 = -1 - 1i
    c3 = 0
    c4 = -1 - 1i
    
    type(c1) = <class '__main__.myComplex'>
    type(c2) = <class '__main__.myComplex'>
    type(c3) = <class '__main__.myComplex'>
    type(c4) = <class '__main__.myComplex'>
    

<hr style="border:2px solid orange"> </hr>

## A Solution to better solve all problems at once


```python
class myComplex(Complex):
    
    # The constructor uses the constructor of the parent class
    def __init__(self, r=0.0, i=0.0):
        super().__init__(r,i)

    # overload operator - (negative)
    def __neg__(self):
        return myComplex(-self.real, -self.img)
    
    # implement sub as (self + (-c))
    def sub(self,c):
        return self.add(-c)     # <==== Notice!
    
    # overload operator - (substraction)
    def __sub__(self,c):
        return self.sub(c)
    
    # 'override' __str__() by reusing the __str__() of the parent class
    def __str__(self):
        if self.real!=0:
            if self.img>0:
                return super().__str__()   # parent-class's __str__
            elif self.img<0: 
                return f"{self.real} - {-self.img}i"
            else:
                return f"{self.real}"
        else:
            if self.img==0:
                return "0"
            else:
                return f"{self.img}i"     
            
    # casting operator + result to be myComplex type
    def add(self,c):
        return (myComplex) (super().add(c))   
```

<hr style="border:0.5px solid gray"> 


```python
c1 = myComplex(0,0)
c2 = myComplex(-1,-1)
c3 = myComplex(-1,-1) - myComplex(-1,-1)
c4 = myComplex(-1,-1).add(c1)
print(f"c1 = {c1}")
print(f"c2 = {c2}")
print(f"c3 = {c3}")
print(f"c4 = {c4}\n")
print(f"type(c1) = {type(c1)}")
print(f"type(c2) = {type(c2)}")
print(f"type(c3) = {type(c3)}")
print(f"type(c4) = {type(c4)}")

# Output:
# --------------------------------------
```

    c1 = 0
    c2 = -1 - 1i
    c3 = 0
    c4 = -1 - 1i
    
    type(c1) = <class '__main__.myComplex'>
    type(c2) = <class '__main__.myComplex'>
    type(c3) = <class '__main__.myComplex'>
    type(c4) = <class '__main__.myComplex'>
    

<hr style="border:2px solid orange"> </hr>

# This is not all, but we must stop here...

<br><hr style="border:3px solid red"> </hr>
<div style="text-align: center;">         
    
# *Homework Assignment*

</div>
<hr style="border:3px solid red"> </hr>
<br>

## Homework 01 - Extending the class myComplex with *, and / operations


<hr style="border:2px solid orange"> </hr>
<br>

<div style="text-align: left;">
<img src="images/break-yang-tr.png" alt="Break" class="center" style="width: 500px;"/>
</div>



```python

```
