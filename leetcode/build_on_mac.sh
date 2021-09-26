# shellcheck disable=SC2006
MYDIR=`pwd`

echo $MYDIR
cd `pwd` || exit
gcc -o a Lc01_remove_duplicaties.c
${MYDIR}/a