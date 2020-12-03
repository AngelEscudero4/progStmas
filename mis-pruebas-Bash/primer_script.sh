
#! /bin/bash

echo $0 #donde se ejecuta
echo $1 #primer param
echo $2 #segundo param
echo ${11} #param 11, si no pongo llaves me coge param 1 y luego otro 1
echo $@ #todos los param q le he pasado
echo $# #muestra el num de argumentos
echo $*
echo $$ #PID
echo $PPID #PID del padre
echo $? #valor de exit status
a="en distinto shell"
echo b = $b 
exit 0
