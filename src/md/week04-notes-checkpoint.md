<div style="text-align: center;">
<img src="images/stust.png" alt="STUST" class="center" style="width: 900px;"/>
</div>
<hr style="border:4px solid gray"> </hr>

<div style="text-align: center;">
<br>

# Python Language Fundamental II
## Source : [https://snakify.org/en/](https://snakify.org/en/)

<br>
</div>

<br>
<hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">s.find(substring)</span>](https://snakify.org/en/lessons/strings_str/#section_6)
* returns the index of the first occurrence of the substring
* returns -1 if the substring is not found

<hr style="border:1px solid gray"> </hr>

> Example:
```Python 
i = "0123456789"
s = "abcdeabcde"
print("s.find('d') =",s.find('d'))
print("s.find('f') =",s.find('f'))
```

<hr style="border:1px solid gray"> </hr>

> Output:
```
s.find('d') = 3
s.find('f') = -1
```

<br><hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">s.rfind(substring)</span>](https://snakify.org/en/lessons/strings_str/#section_6)
* returns the index of the last occurrence of the substring
* returns -1 if the substring is not found

<hr style="border:1px solid gray"> </hr>

> Example:
```python
i = "0123456789"
s = "abcdeabcde"
print("s.rfind('d') =",s.find('d'))
print("s.rfind('f') =",s.find('f'))
``` 

<hr style="border:1px solid gray"> </hr>

> Output:
```
s.rfind('d') = 8
s.rfind('f') = -1
```

<br><hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">s.find(substring, left , right)、s.find(substring, left)</span>](https://snakify.org/en/lessons/strings_str/#section_6)
* search substring inside the slice s[left : right]
* search substring inside the slice s[left :]
* returns the absolute index, relatively to the whole string s, and not to the 

<hr style="border:1px solid gray"> </hr>

> Example:
```python
i = "0123456789"
s = "abcdeabcde"
print("s.find('d',5) =",s.find('d',5))
print("s.find('d',4,7) =",s.find('d',4,7))
```

<hr style="border:1px solid gray"> </hr>

> Output:
```
s.find('d',5) = 8
s.find('d',4,7) = -1
```

<br><hr style="border:2px solid orange"> </hr>

# [Lab 01 - To swap the two words](https://snakify.org/en/lessons/strings_str/problems/swap_two_words/)

<hr style="border:1px solid gray"> </hr>

> Model solution
```Python
s = input()
first_word = s[:s.find(' ')]
second_word = s[s.find(' ') + 1:]
print(second_word + ' ' + first_word)
```

<hr style="border:1px solid gray"> </hr>

> Young's solution
```Python
s = input()
ss = s.split()
print(ss[1],ss[0])
```


```python

```

<br><hr style="border:2px solid orange"> </hr>

# [Lab 02 - The second occurrence](https://snakify.org/en/lessons/strings_str/problems/second_occurrence/)

<hr style="border:1px solid gray"> </hr>

> Model solution
```Python
s = input()
if s.count('f') == 1:
    print(-1)
elif s.count('f') < 1:
    print(-2)
else:
    print(s.find('f', s.find('f') + 1))    
```

<hr style="border:1px solid gray"> </hr>

> Young's solution
```Python
s = input()
fp = s.find('f')
if fp>=0:
    fp = s.find('f',fp+1)
    print(-1 if fp==-1 else fp)
else:
    print(-2)
```


```python

```

<br><hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">s.replace(old, new)</span>](https://snakify.org/en/lessons/strings_str/#section_7)
* takes the string s and replaces all occurrences of substring *old* with the substring *new*

<hr style="border:1px solid gray"> </hr>

> Example:
```python
s = "abcd_abcd_abcd"
s1 = s.replace('ab','**')
print(s1)
```

<hr style="border:1px solid gray"> </hr>

> Output:
```
**cd_**cd_**cd
```


```python

```

<br><hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">s.replace(old, new, count)</span>](https://snakify.org/en/lessons/strings_str/#section_7)
* replace only first count occurrences and then stop

<hr style="border:1px solid gray"> </hr>

> Example:
```python
s = "abcd_abcd_abcd"
s1 = s.replace('ab','**',2)
print(s1)
```

<hr style="border:1px solid gray"> </hr>

> Output:
```
**cd_**cd_abcd
```


```python

```

<br><hr style="border:2px solid orange"> </hr>

# [Lab 03 - Replace within the fragment](https://snakify.org/en/lessons/strings_str/problems/replace_inside_fragment/)

<hr style="border:1px solid gray"> </hr>

> Model solution
```Python
s = input()
a = s[:s.find('h') + 1] 
b = s[s.find('h') + 1:s.rfind('h')]
c = s[s.rfind('h'):]
s = a + b.replace('h', 'H') + c
print(s)
```

<hr style="border:1px solid gray"> </hr>

> Young's solution
```Python
s = input()
la = s.find('h')
ra = s.rfind('h')
sh = s[:la+1]
st = s[ra:]
sm = s[la+1:ra].replace('h','H')
print(sh+sm+st)
```


```python

```

<br><hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">Loop control flow: else</span>](https://snakify.org/en/lessons/while_loop/#section_2)
* One can write an else: statement after a loop body which is executed once after the end of the loop

<hr style="border:1px solid gray"> </hr>

> Example:
```Python
cnt=1
while cnt<5:
    print("cnt = ",cnt)
    cnt+=1
else:
    print(">>> cnt = ",cnt)
```

<hr style="border:1px solid gray"> </hr>

> Output:
```
cnt =  1
cnt =  2
cnt =  3
cnt =  4
>>> cnt =  5
```


```python

```

<br><hr style="border:2px solid orange"> </hr>

## [<span style="color:yellow">Multiple assignment</span>](https://snakify.org/en/lessons/while_loop/#section_4)
* In Python it is possible for a single assignment statement to change the value of several variables.

<hr style="border:1px solid gray"> </hr>

> Example:
```Python
a, b, c = 1, 2, 3
print(a,b,c)
a, b, c = c, b, a
print(a,b,c)
```

<hr style="border:1px solid gray"> </hr>

> Output:
```
1 2 3
3 2 1
```


```python

```

<br><hr style="border:2px solid orange"> </hr>

# [Lab 04 - The power of two](https://snakify.org/en/lessons/while_loop/problems/powers_of_two/)

<hr style="border:1px solid gray"> </hr>

> Model solution
```Python
n = int(input())
two_in_power = 2
power = 1
while two_in_power <= n:
    two_in_power *= 2
    power += 1
print(power - 1, two_in_power // 2)
```

<hr style="border:1px solid gray"> </hr>

> Young's solution
```Python
N = int(input())
x = 0
p = 1
while p<=N:
    x+=1
    p*=2
print(x-1,p//2)
```



```python

```

<br><hr style="border:2px solid orange"> </hr>

# [Lab 05 - The number of elements that are greater than the previous one](https://snakify.org/en/lessons/while_loop/problems/seq_increasing_neighbours/)

<hr style="border:1px solid gray"> </hr>

> Model solution
```Python
prev = int(input())
answer = 0
while prev != 0:
    next = int(input())
    if next != 0 and prev < next:
        answer += 1
    prev = next
print(answer)
```

<hr style="border:1px solid gray"> </hr>

> Young's solution
```Python
n = int(input())
cnt = 0
while n!=0:
    prev = n
    n = int(input())
    if n>prev: cnt+=1
print(cnt)
```


```python

```

<br><hr style="border:2px solid orange"> </hr>

# [Lab 06 - The maximum number of consecutive equal elements](https://snakify.org/en/lessons/while_loop/problems/seq_max_chunk_of_repetitions/)

<hr style="border:1px solid gray"> </hr>

> Model solution
```Python
prev = -1
curr_rep_len = 0
max_rep_len = 0
element = int(input())
while element != 0:
    if prev == element:
        curr_rep_len += 1
    else:
        prev = element
        max_rep_len = max(max_rep_len, curr_rep_len)
        curr_rep_len = 1
    element = int(input())
max_rep_len = max(max_rep_len, curr_rep_len)
print(max_rep_len)
```

<hr style="border:1px solid gray"> </hr>

> Young's solution
```Python
n = int(input())
cc, wc = 1, 1
while n!=0:
    next = int(input())
    if n==next:
        cc+=1
    else:
        n = next
        if cc>wc: wc = cc
        cc = 1
else:
    if cc>wc: wc = cc
print(wc)
```


```python

```

<br><hr style="border:2px solid orange"> </hr>

# [Lab 07 - TinkerCAD Arduino Simulator](https://www.tinkercad.com/)

<hr style="border:1px solid gray"> </hr>

<table style="width: 100%;">
<tr>
<th style="width: 50%;"> Arduino </th>
<th style="width: 50%;" > Sketch </th>
</tr>
<tr>
<td>

<img src="./images/arduino-01.png" style="width: 300px;"/>

</td>
<td>

```c++
int buttonState = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  delay(10); 
}
```

</td>
</tr>
</table>

<br><hr style="border:4px solid gray"> </hr>
<div style="text-align: center;">
<img src="images/break.png" alt="STUST" class="center" style="width: 700px;"/>
</div>
