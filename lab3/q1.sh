
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 filename"
    exit 1
fi

filename=$1

if [ -d "$filename" ]; then
    echo "$filename is a directory."

elif [ -f "$filename" ]; then
    echo "$filename is a regular file."
else
    echo "$filename does not exist or is not a regular file or directory."
fi

