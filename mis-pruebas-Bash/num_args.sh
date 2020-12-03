#script que devuelva un exit status 0 si se le llama con exactamente 2 argumentos y uno si no es asi, si se le llama con dos args
#mostrar cada argumento uno por linea
#ojo!! para q sea un script ejecutable hay que darle permisos -> chmod u+x nombre

#poner siempre esta linea de abajo --> shell a usar?
#! /bin/bash

# si le ponemos al final -x va ejecutando linea a linea y asi podemos medio depurar

#dos modos de resolver:

# [ $# -eq 2 ] || exit 1 #en caso de que sea cierto no ejecuta el resto asiq haria el exit de abajo, poner corchetes con espacios sino mal
# exit 0

#otro modo
# if [ $# -eq 2 ]; then exit 0; else exit 1; fi

#lo mismo
if ! [ $# -eq 2 ]; then
    exit 1
fi

#aqui tenemos asegurado que tiene 2 args --> normalmente error arriba y luego programa abajo

for i in "$@"; do #da igual $@ que "$@" que "$*" (le quita saltos de linea) que $*
    echo $i
done

#muestre el directorio actual y bucle con sus ficheros en formato largo y que diga cuantos hay

#se puede hacer sin bucle poniendo ls -l
echo $PWD
k=0 #let -i x=0 #declaro como variable entera
for i in *; do
    ls -l $i
    ((k++)) #x++
done
echo Hay $k ficheros

echo hay $(($(ls -l | wc --lines) - 1)) ficheros

#preguntar si cada fichero es un directorio y tiene permisos de lectura
for i in *; do
    if [ -d "$i" -a -r "$i" ]; then #es un directorio y es legible
        echo "${i} es un directorio legible"
        #otro modo de ponerlo es [ -d "$i" -a -r "$i" ] && echo "${i} es un directorio" -> si se cumple lo primero ejecuta lo segundo
    else
        echo "${i} no es un directorio legible"
    fi
done

#crear un directorio con el login del usuario del script, $USER y dentro de el subdirectorios 
#con nombres de una variable valor leida de un fichero llamado subdirectorios en un solo mandato

exit 0
