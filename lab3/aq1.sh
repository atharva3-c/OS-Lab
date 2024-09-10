read -p "enter number " num

if [ "$num" -eq 2 ]; then 
	echo "Prime"
	exit 0
	
elif [ "$num" -eq 1 ] || [ "$num" -eq 0 ]; then 
	echo "INVALID"
	exit 1


else
	flag=0
	for((i=2;i*i<num;i++));do
	if [ $((num%i)) -eq 0 ];then
		echo "Not Prime"
		flag=1
		break
	fi
	done
	
	if [ "$flag" -eq 0 ]; then
		echo "Prime"
	fi
fi

