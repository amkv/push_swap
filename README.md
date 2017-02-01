# push_swap

Sorting algorithm between 2 stacks.[dill]
Main goal is 2 programs:[dill]
./push_swap - return commands for sorting the stack[dill]
	if number of digits == 3 - no more then 2-3 operations[dill]
	if number of digits <= 5 - no more then 8 operations[dill]
	if number of digits > 5 and number == 100 - no more then 700 operations[dill]
	if number of digits > 5 and number == 500 - no more then 5300 operations[dill]
./checker - using commands make manipulations with stack and show result OK/KO[dill]

The folders organization:[dill]
push_swap_s - push_swap programm[dill]
checker_s - checker programm[dill]
shares_s - folder for shared functions[dill]
libft - shared libraries functions[dill]
pushchecker.sh - script for multiple testing[dill]

```
make
```