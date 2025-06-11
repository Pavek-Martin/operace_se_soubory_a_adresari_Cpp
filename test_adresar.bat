@echo off
title test adresar

echo vytvorim novy adresar z nazvem "folder_1"
pause
mkdir_argv_1.exe folder_1
dir
attrib folder_1

echo adresari "folder_1" ted pridam atribut ReadOnly
pause
file_attrib_read_only_argv_2.exe folder_1
attrib folder_1

echo pokusim se ted smazat adresar "folder_1" ktery ma attribut ReadOnly
pause
delete_folder_argv_3.exe folder_1

echo adresar "folder_1" z atributem ReadOnly ted nejde smazat
echo takze mu attribute ReadOnly napred odsranime a pak se ho pokusime smazat znovu
pause
file_attrib_read_only_remove_argv_2.exe folder_1
attrib folder_1

echo v poslednim kroku zmazeme adresar "folder_1"
pause
delete_folder_argv_3.exe folder_1
dir


echo "to je vsechno"
pause
