# push_swap

Sorting algorithm between 2 stacks.  

Main goal is 2 programs:  
./push_swap - return commands for sorting the stack  
	if number of digits == 3 - no more then 2-3 operations  
	if number of digits <= 5 - no more then 8 operations  
	if number of digits > 5 and number == 100 - no more then 700 operations  
	if number of digits > 5 and number == 500 - no more then 5300 operations  
./checker - using commands make manipulations with stack and show result OK/KO  
  
The folders organization:  
push_swap_s - push_swap program  
checker_s - checker program    
shares_s - folder for shared functions  
libft - shared libraries functions  
pushchecker.sh - script for multiple testing  

###How to run?
```
make
```
###push_swap
```
./push_swap 2 3 1
```
~~~~
rra
~~~~

You can run push_swap with extra flag  
-v Show the stacks status after each operation

```
./push_swap -v 2 3 1
```
~~~~
 - - - - - - - - - - - - - 0

 0| 2
 1| 3
 2| 1
    _   _
    a   b
                    top a:   0
                    top b:   2
                    elems a: 3
                    elems b: 0

rra - - - - - - - - - - - - - 1

 0| 1
 1| 2
 2| 3
    _   _
    a   b
                    top a:   0
                    top b:   2
                    elems a: 3
                    elems b: 0
~~~~

###checker
```
./checker 2 3 1
rra
<RETURN or CTR+D>
```
commands for checker:  
sa   swap a - swap the first 2 elements at the top of stack a  
sb   swap b - swap the first 2 elements at the top of stack b  
ss   sa and sb at the same time  
pa   push a - take the first element at the top of b and put it at the top of a  
pb   push b - take the first element at the top of a and put it at the top of b  
ra   rotate a - shift up all elements of stack a by 1  
rb   rotate b - shift up all elements of stack b by 1  
rr   ra and rb at the same time  
rra  reverse rotate a - shift down all elements of stack a by 1  
rrb  reverse rotate b - shift down all elements of stack b by 1  
rrr  rra and rrb at the same time  
  
You can run checker with 2 extra flags  
-v Show the stacks status after each operation  
-g Game mode - Try to sort stacks by yourself in interactive mode

```
./checker -v 2 3 1
./checker -g 2 3 1
```
~~~~
NEW GAME started
- - - - - - - - - - - - - - -
(l) usage/HELP
(o) used operators list
(c) clean mode
(s) is sorted? - check the stack order
(=) print stacks
(h) print history of commands
(n) new game
(q) quit
~~~~
or
```
A="2 3 1"; ./push_swap $A | ./cheker $A
```
or
```
sh pushcheker.sh 100 5
```
