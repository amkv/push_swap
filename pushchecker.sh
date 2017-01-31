#!/bin/bash
LOOPS=30;
YESNO=0;
A=;
RED='\033[0;31m';
WHITE='\033[1m';
CLN='\033[0m';
TEMPFILE=tempresult.txt

if [ "$#" -ne 1 ]; then
	echo "usage (default ${WHITE}2${CLN}): sh pushchecker.sh NUMBER";
	NUMBERS=2;	
else
	NUMBERS=$1;
	echo ${WHITE}$NUMBERS${CLN} "random numbers";
fi

while [ $YESNO -lt $NUMBERS ]; do
	TEMP=$((RANDOM%100000000+0))" ";
	if [[ $A == *$TEMP* ]]; then
		continue;
	else
		A+=$TEMP;
		((YESNO++));
	fi
done

echo "\n"$A"\n";
./push_swap $A > $TEMPFILE;
echo "operations: \c";
OPER=$(cat $TEMPFILE | wc -l | tr -d " ");

if [ $NUMBERS -eq 100 ]; then
	if [ $OPER -gt 700 ]; then
		echo "$(RED)WRONG${CLN} \c";
	else
		echo ${WHITE}"OK \c"${CLN};
	fi
fi

if [ $NUMBERS -eq 500 ]; then
	if [ $OPER -gt 5300 ]; then
		echo ${RED}"WRONG${CLN} \c";
	else
		echo ${WHITE}"OK${CLN} \c";
	fi
fi

echo $OPER;
echo "./checker result: \c";
R=$(cat $TEMPFILE | ./checker $A);
echo ${WHITE}$R${CLN};
rm $TEMPFILE
