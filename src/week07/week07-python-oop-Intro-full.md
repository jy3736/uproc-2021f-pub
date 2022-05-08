<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>

<hr style="border:4px solid gray"> </hr>

<div style="text-align: center;">    
<br>    
    
# [Python Object Oriented Programming](https://www.programiz.com/python-programming/object-oriented-programming)

### Class, Object, and Constroctor
    
##### Source: https://www.programiz.com/python-programming

</div>

<br>
<hr style="border:4px solid gray"> </hr>


<br>
<hr style="border:2px solid orange"> </hr>

# [Introduction to Python OOP](https://www.programiz.com/python-programming/object-oriented-programming)

* Python is a multi-paradigm programming language: `Functional`, `Object-Oriented`, and `Procedural`.
* The concept of OOP in Python focuses on creating `reusable code`. 
* A `class` is a blueprint for the object.
* An `object` (instance) is an instantiation of a class. 
* In OOP, an object has two characteristics: `attributes` and `behavior`
    * Take Complex class as example:
        * attributes : real, img
        * behavior : add, sub, mul, div, ...
* In Python the `__init__()` method is called the constructor and is always called when an object is created.

<hr style="border:2px solid orange"> </hr>

## Class, Object, and Constructor

* Syntax of class declaration :

```python
class className:
    # body of the class
```

* Syntax of constructor declaration :

```python
class className:
    
    def __init__(self):
        # body of the constructor

    def __init__(self, param1, param2):
        # body of the constructor        
```

* Syntax of object instantiation:

```python
obj1 = className()
obj2 = className(1,2)
```


<hr style="border:0.5px solid gray"> </hr>


```python
class Complex:
    
    # constructor
    def __init__(self, real, img):
        self.real = real
        self.img  = img
    
    # print all attributes
    def attributes(self):
        print(self.__class__.__name__, self.__dict__)
```

<hr style="border:0.5px solid gray"> </hr>


```python
c1 = Complex(1,2)
c1.attributes()

# Output:
# ----------------------------------------
```

    Complex {'real': 1, 'img': 2}
    

<hr style="border:0.5px solid gray"> </hr>


```python
c1 = Complex()

# Output:
# ----------------------------------------
```
    TypeError  Traceback (most recent call last)

    <ipython-input-9-2e1f2fd9155d> in <module>
    ----> 1 c1 = Complex()
          2 
          3 # Output:
          4 # ----------------------------------------
   
    TypeError: __init__() missing 2 required positional arguments: 'real' and 'img'

<hr style="border:0.5px solid gray"> </hr>


```python
class Complex:
    
    # constructors
    def __init__(self, real, img):
        self.real = real
        self.img  = img
        
    def __init__(self):
        self.real = 0.0
        self.img  = 0.0

    # print all attributes
    def attributes(self):
        print(self.__class__.__name__, self.__dict__)
        
c1 = Complex()
c1.attributes()

# Output:
# ----------------------------------------
```

    Complex {'real': 0.0, 'img': 0.0}
    

<hr style="border:0.5px solid gray"> </hr>


```python
class Complex:
    
    # constructor
    def __init__(self, real=0.0, img=0.0):
        self.real = real
        self.img  = img
    
    # print all attributes
    def attributes(self):
        print(self.__class__.__name__, self.__dict__)

c1 = Complex()
c2 = Complex(1)
c3 = Complex(1, 2)
c4 = Complex(img=3.14)
Dummy = [c.attributes() for c in (c1, c2, c3, c4)]

# Output:
# ----------------------------------------
```

    Complex {'real': 0.0, 'img': 0.0}
    Complex {'real': 1, 'img': 0.0}
    Complex {'real': 1, 'img': 2}
    Complex {'real': 0.0, 'img': 3.14}
    

<hr style="border:0.5px solid gray"> </hr>


```python
class Complex:
    
    # copy constructor
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

c1 = Complex()
c2 = Complex(1)
c3 = Complex(1,2)
c4 = Complex(img=3.14)
c5 = Complex(c3)
Dummy = [c.attributes() for c in (c1, c2, c3, c4, c5)]

# Output:
# ----------------------------------------
```

    Complex {'real': 0.0, 'img': 0.0}
    Complex {'real': 1, 'img': 0.0}
    Complex {'real': 1, 'img': 2}
    Complex {'real': 0.0, 'img': 3.14}
    Complex {'real': 1, 'img': 2}
    

<hr style="border:2px solid orange"> </hr>

## Methods

* Methods are `functions` defined inside the body of a class. They are used to define the behaviors of an object.

<hr style="border:0.5px solid gray"> </hr>


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
        self.real += c.real
        self.img += c.img
    
c1 = Complex(1,2)
c2 = Complex(3)
c1._add(c2)
c1.attributes()
c2.attributes()

# Output:
# ----------------------------------------
```

    Complex {'real': 4, 'img': 2.0}
    Complex {'real': 3, 'img': 0.0}
    

<hr style="border:0.5px solid gray"> </hr>


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
        self.real += c.real
        self.img += c.img
    
    # return (self + Complex c)
    def add(self, c):
        cr = Complex(self)
        cr._add(c)
        return cr
    
c1 = Complex(1,2)
c2 = Complex(3)
c3 = c1.add(c2)
c1.attributes()
c2.attributes()
c3.attributes()

# Output:
# ----------------------------------------
```

    Complex {'real': 1, 'img': 2}
    Complex {'real': 3, 'img': 0.0}
    Complex {'real': 4, 'img': 2.0}
    

<hr style="border:0.5px solid gray"> </hr>


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
    
c1 = Complex(1,2)
c2 = Complex(3)
c3 = c1.add(c2)
c4 = c1 + c2
c1.attributes()
c2.attributes()
c3.attributes()
c4.attributes()

# Output:
# ----------------------------------------
```

    Complex {'real': 1, 'img': 2}
    Complex {'real': 3, 'img': 0.0}
    Complex {'real': 4, 'img': 2.0}
    Complex {'real': 4, 'img': 2.0}
    

<hr style="border:0.5px solid gray"> </hr>


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
    
c1 = Complex(1,2)
c2 = Complex(3)
c3 = c1.add(c2)
c4 = c1 + c2
print(f"c1 = {c1}")
print(f"c2 = {c2}")
print(f"c3 = {c3}")
print(f"c4 = {c4}")

# Output:
# ----------------------------------------
```

    c1 = 1 + 2i
    c2 = 3 + 0.0i
    c3 = 4 + 2.0i
    c4 = 4 + 2.0i
    

<br><hr style="border:3px solid red"> </hr>
<div style="text-align: center;">         
    
# *Homework Assignment*

</div>
<hr style="border:3px solid red"> </hr>
<br>
### Homework 01 - Class Complex with +, -, *, and / operations

* Modify the Class Complx sample code to suit the following usage:

```python
c1 = Complex(1,2)
c2 = c1 + 4
c3 = c1 + 3.14
```

* Please refer to _add(), add() and __add__() to implement all necessary methods for -, * and / operations.

```python
c1 = Complex(1,2)
c2 = c1 + 4
c3 = c2 * c1
c4 = c3 / c2
c5 = c4 * c1 / 5
```



<hr style="border:2px solid orange"> </hr>
<br>

<div style="text-align: left;">
<img src="images/break-yang-tr.png" alt="Break" class="center" style="width: 500px;"/>
</div>

