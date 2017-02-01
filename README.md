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

```
./push_swap 2 3 1
```
or

```
./checker 2 3 1
rra
<RETURN or CTR+D>
```
or
```
A="2 3 1"; ./push_swap $A | ./cheker $A
```

or
```
sh pushcheker.sh 100 5
```