#!/bin/bash

# variables
TEMPFILE=resulttempfile.txt;
RANGENUM=10000

# unchanging variables
YESNO=0;
A=;
RED='\033[0;31m';
WHITE='\033[1m';
CLN='\033[0m';
RM=/bin/rm;
WRONGCOUNT=0;
OKCOUNT=0;
SORTCOUNTEROK=0;
SORTCOUNTERKO=0;

if [ "$#" -eq 1 ]; then
	NUMBERS=$1;
	if [[ ${NUMBERS} -le 1 ]]; then
        echo "Error: wrong argument";
        exit 1;
    fi;
	LOOPS=1;
	echo ${WHITE}${NUMBERS}${CLN} "random numbers";
elif [ "$#" -eq 2 ]; then
    NUMBERS=$1;
    if [[ ${NUMBERS} -le 0 ]]; then
        echo "Error: wrong argument";
        exit 1;
    fi;
    LOOPS=$2;
    if [[ ${LOOPS} -le 0 ]]; then
        echo "Error: wrong argument";
        exit 1;
    fi;
    echo ${WHITE}${LOOPS}${CLN} "loops";
    echo ${WHITE}${NUMBERS}${CLN} "random numbers each";
else
   	echo "usage (default ${WHITE}2${CLN} numbers and ${WHITE}1${CLN} loop): sh pushchecker.sh [NUMBER] [LOOPS]";
	NUMBERS=2;
	LOOPS=1;
fi


#elif [[ ${LOOPS} -eq 0 ]]; then
#    echo "wrong argument";
#    exit 1;
#fi

LOOPSCOUNT=${LOOPS};

# while loops
while [ ${LOOPS} -gt 0 ]; do
    # generating set of random numbers
    while [ ${YESNO} -lt ${NUMBERS} ]; do
        TEMP=$((RANDOM%${RANGENUM}+1))" ";
        if [[ ${A} == *${TEMP}* ]]; then
            continue;
        else
            A+=${TEMP};
            ((YESNO++));
        fi
    done

    # main body
    echo "\n"${A}"\n";
    ./push_swap ${A} > ${TEMPFILE};
    echo "-----------------------";
    echo "operations: \c";
    OPER=$(cat ${TEMPFILE} | wc -l | tr -d " ");

    if [ ${NUMBERS} -eq 3 ]; then
        if [ ${OPER} -gt 3 ]; then
            echo "${RED}WRONG${CLN} \c";
            ((WRONGCOUNT++));
        else
            echo ${WHITE}"OK \c"${CLN};
            ((OKCOUNT++));
        fi
    elif [ ${NUMBERS} -eq 5 ]; then
        if [ ${OPER} -gt 12 ]; then
            echo "${RED}WRONG${CLN} \c";
            ((WRONGCOUNT++));
        elif [ ${OPER} -le 8 ]; then
            echo ${WHITE}"Great!"${CLN};
        else
            echo ${WHITE}"OK \c"${CLN};
            ((OKCOUNT++));
        fi
    elif [ ${NUMBERS} -eq 100 ]; then
        if [ ${OPER} -gt 700 ]; then
            echo "${RED}WRONG${CLN} \c";
            ((WRONGCOUNT++));
        else
            echo ${WHITE}"OK \c"${CLN};
            ((OKCOUNT++));
        fi
    elif [ ${NUMBERS} -eq 500 ]; then
        if [ ${OPER} -gt 5300 ]; then
            echo ${RED}"WRONG${CLN} \c";
            ((WRONGCOUNT++));
        else
            echo ${WHITE}"OK${CLN} \c";
            ((OKCOUNT++));
        fi
    fi

    echo ${OPER};
    echo "./checker:  \c";
    R=$(cat ${TEMPFILE} | ./checker $A);
    if [[ ${R} == "OK" ]]; then
        echo ${WHITE}${R}${CLN};
        ((SORTCOUNTEROK++));
    else
        echo ${RED}${R}${CLN};
        ((SORTCOUNTERKO++));
    fi
    echo "-----------------------";
    rm ${TEMPFILE};
    A=;
    TEMP=;
    YESNO=0;
    ((LOOPS--));
done

echo "\nfinal result (${LOOPSCOUNT} loops): \c";
if [ ${WRONGCOUNT} -eq 0 ]; then
    if [ ${SORTCOUNTERKO} -eq 0 ]; then
        echo ${WHITE}"GOOD"${CLN};
    else
        echo ${RED}"BAD"${CLN};
    fi;
else
    echo ${RED}"BAD"${CLN};
fi

if [ ${LOOPSCOUNT} -gt 1 ]; then
    echo "operations: ${OKCOUNT} OK / ${WRONGCOUNT} Wrong";
    echo "sorting:    ${SORTCOUNTEROK} OK / ${SORTCOUNTERKO} KO";
fi
exit 0
