#!/bin/bash

cat="cat "
s_21cat="./s21_cat "
SUCCESS=0
FAIL=0
COUNTER=0

testing(){
    ./s21_cat $var test.txt> test_s21_cat.log 
    cat $var test.txt> test_cat.log
    if cmp -s test_s21_cat.log test_cat.log
    then
    (( SUCCESS++ ))
    (( COUNTER++ ))

    echo "Test  №$COUNTER SUCCESS $var";
    else
    (( FAIL++ ))
    (( COUNTER++ ))

    echo "Test  №$COUNTER FAIL $var"
    fi
    rm test_s21_cat.log test_cat.log
}


for var1 in e b n s t v
do  
    var="-$var1"
    testing $var
done

for var1 in e b n s t v
do  
    for var2 in e b n s t v
    do  
        if [ $var1 != $var2 ]
        then
            var="-$var1 -$var2"
            testing $var
        fi
    done
done

for var1 in e b n s t v
do  
    for var2 in e b n s t v
    do  
        for var3 in e b n s t v
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then  
                var="-$var1 -$var2 -$var3"
                testing $var
            fi
        done
    done
done

echo "SUCCESS  $SUCCESS from $COUNTER ";
echo "FAILED  $FAIL from $COUNTER ";