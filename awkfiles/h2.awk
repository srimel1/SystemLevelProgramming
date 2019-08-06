BEGIN {print "Start to scan file"}
{print $2 "<" $NR}
END {print "END-", FILENAME}
