sum=0
valgrind --leak-check=full testOpen |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testOpen Succeded"
else
		echo "testOpen Failed"
fi

valgrind --leak-check=full testClose |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testClose Succeded"
else
		echo "testClose Failed"
fi
valgrind --leak-check=full testPut |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testPut Succeded"
else
		echo "testPut Failed"
fi
valgrind --leak-check=full testSearch |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testSearch Succeded"
else
		echo "testSearch Failed"
fi
valgrind --leak-check=full testGet |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testGet Succeded"
else
		echo "testGet Failed"
fi
if [ ${sum} == 0 ] ; then
		echo "all tests ran with no leaks"
		exit 0
else
		echo "one or more tests failed due to leaks"
		exit 1
fi
