@echo off
setlocal EnableDelayedExpansion

::
:: Вид сборки / суффикс в названии каталога сборки
::
:: "Ninja" / "ninja"
:: "Visual Studio 17 2022" / "visual_studio"
::
set BUILD_TYPE=Ninja
set BUILD_SUFFIX=ninja

chcp 65001

set BUILD_FOLDER=build_%BUILD_SUFFIX%
set SOURCE_FOLDER=projects

if not exist %BUILD_FOLDER% mkdir %BUILD_FOLDER%

cd %BUILD_FOLDER%

cmake -G %BUILD_TYPE% ..\%SOURCE_FOLDER%
cmake --build .

set arr[0].file=run_radix_sort.bat
set arr[1].file=run_radix_sort_mf.bat
set arr[2].file=run_recursion.bat
set arr[3].file=run_travel_to_russia.bat

set arr[0].folder=radix_sort
set arr[1].folder=radix_sort_mf
set arr[2].folder=recursion
set arr[3].folder=travel_to_russia

for /L %%i in (0,1,3) do ( 
	copy ..\%SOURCE_FOLDER%\!arr[%%i].folder!\!arr[%%i].file! .\!arr[%%i].folder!
)

copy ..\run_tests.bat .

cmd /k
