echo the name of this script is $0
echo the first argument is $1
echo the list of all arguments in $*
echo this script places the date into a temporary file 
echo call $1.$$
date > $1.$$
ls $1.$$
rm $1.$$
