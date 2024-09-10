name="$1"

read -p "enter an option" op

case $op in
1) sed -n '1~2p' "$name">oddfile.txt;;

2) sed -n '2~2p' "$name">evenfile.txt;;

*) echo "nan"
esac



