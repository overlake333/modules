sum=0
valgrind --leak-check=full testhOpen |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhOpen Succeded"
else
		echo "testhOpen Failed"
fi
valgrind --leak-check=full testhClose |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testClose Succeded"
else
		echo "testClose Failed"
fi
valgrind --leak-check=full testhPutAgain |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhPutAgain Succeded"
else
		echo "testhPutAgain Failed"
fi
valgrind --leak-check=full testhPutAgainSameAddress |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhPutAgainSA Succeded"
else
		echo "testhPutAgainSA Failed"
fi
valgrind --leak-check=full testhPutEmpty |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhPutEmpty Succeded"
else
		echo "testhPutEmpty Failed"
fi
valgrind --leak-check=full testSearch |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testSearch Succeded"
else
		echo "testSearch Failed"
fi
valgrind --leak-check=full testhSearch |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhSearch Succeded"
else
		echo "testhSearch Failed"
fi
valgrind --leak-check=full testhSearchEmpty |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
    echo "testSearchEmpty Succeded"
else
    echo "testhSearchEmpty Failed"
fi
valgrind --leak-check=full testhSearchNonempty |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhSearchNE Succeded"
else
		echo "testhSearchNE Failed"
fi
valgrind --leak-check=full testhSearchValidity |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhSearchValidity Succeded"
else
		echo "testhSearchValidity Failed"
fi

valgrind --leak-check=full testhApply |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhApply Succeded"
else
		echo "testhApply Failed"
fi
valgrind --leak-check=full testhRemove |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhRemove Succeded"
else
		echo "testhRemove Failed"
fi
valgrind --leak-check=full testhRemoveEmpty |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhRemoveEmpty Succeded"
else
		echo "testhRemoveEmpty Failed"
fi
valgrind --leak-check=full testhRemoveValidity |& grep "no leaks are possible"
let "sum=sum+$?"
if [ ${sum} == 0 ] ; then
		echo "testhRemoveV Succeded"
else
		echo "testhRemoveV Failed"
fi
if [ ${sum} == 0 ] ; then
		echo "all tests ran with no leaks"
		exit 0
else
		echo "one or more tests failed due to leaks"
		exit 1
fi
