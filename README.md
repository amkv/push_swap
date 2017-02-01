# push_swap

Sorting algorithm between 2 stacks.  

**Main goal is 2 programs:**  
**./push_swap** - return commands for sorting the stack "a"  
	if number of digits == **3** - no more then **2-3** operations  
	if number of digits <= **5** - no more then **8** operations  
	if number of digits > 5 and number == **100** - no more then **700** operations  
	if number of digits > 5 and number == **500** - no more then **5300** operations  
**./checker** - using commands make manipulations with stacks "a" and show the result **OK**/**KO**  
  
The project organization:  
**push_swap_s** - push_swap program  
**checker_s** - checker program    
**shared_s** - folder for shared functions  
libft - shared libraries functions  
**pushchecker.sh** - script for multiple testing  

###How to run?
```
make
```
```
A="2 3 1"; ./push_swap $A | ./cheker $A
```
###push_swap
```
./push_swap 2 3 1
```
You can run push_swap with extra flag  
**-v** Show the stacks status after each operation

```
./push_swap -v 2 3 1
```
~~~~
 - - - - - - - - - - - - - - 0

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
**sa**   swap a - swap the first 2 elements at the top of stack a  
**sb**   swap b - swap the first 2 elements at the top of stack b  
**ss**   sa and sb at the same time  
**pa**   push a - take the first element at the top of b and put it at the top of a  
**pb**   push b - take the first element at the top of a and put it at the top of b  
**ra**   rotate a - shift up all elements of stack a by 1  
**rb**   rotate b - shift up all elements of stack b by 1  
**rr**   ra and rb at the same time  
**rra**  reverse rotate a - shift down all elements of stack a by 1  
**rrb**  reverse rotate b - shift down all elements of stack b by 1  
**rrr**  rra and rrb at the same time  
  
You can run checker with 1 extra flag  
**-g** Game mode. Try to sort stacks by yourself in interactive mode

```
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
  
pb - - - - - - - - - - - - - 1

 0|
 1| 1
 2| 2   3
    _   _
    a   b
                    top a:   1
                    top b:   2
                    elems a: 2
                    elems b: 1
~~~~
###pushcheker.sh
```
sh pushcheker.sh 100 2
```
~~~~
2 loops
100 random numbers each

5696 699 1993 8427 1035 264 540 5777 9044 4944 1402 2378 9132 8193 3513 2525 1880 524 757 7436 5947 2989 7216 9472 933 5328 5932 8187 5767 1531 3022 1501 8383 7647 1604 8793 9336 8116 5653 2874 1302 3088 2570 800 2271 2517 1184 7230 7974 4750 7663 4773 2940 7288 456 2958 9685 2544 145 7866 1611 8079 4490 5094 953 8616 7533 966 5728 4806 2445 725 4392 5306 7304 2736 435 3878 9503 5455 2312 3257 5697 6723 7977 1733 666 3599 7490 6569 3615 8340 1840 4126 4215 721 2926 2608 6985 9224

-----------------------
operations: OK 625
./checker:  OK
-----------------------

4860 3110 8565 2540 8434 7485 4605 203 8904 52 1023 8123 3793 6696 457 2054 1019 8350 3051 2437 450 9659 7230 6904 8113 4011 269 9150 152 6651 9812 7744 2924 6750 962 955 4806 4157 9044 396 1860 382 5839 4463 2065 4882 7705 7734 3599 5361 1978 9192 1654 1910 3407 3020 3162 9127 1360 7088 1554 1292 1224 7111 391 7603 4091 5212 6169 5080 7260 2419 8092 5451 1348 1373 2388 5506 4371 3764 2422 3230 8875 7241 4563 7326 2583 9692 261 316 1118 3478 8360 8910 8064 9481 3848 5756 966 6681

-----------------------
operations: OK 577
./checker:  OK
-----------------------

final result (2 loops): GOOD
operations:       2 OK / 0 Wrong
sorting:          2 OK / 0 KO
max (operations): 625
min (operations): 577
~~~~
