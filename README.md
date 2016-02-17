# smartbrowser
project
usage

This is an open source project and can be modified by any person who has the know how of how it works to suit his/her need
this project is written in files and in the absence of one of these file the program might not work correctly or it might not work at all
The file called real .c is the file that contains the main function while the file named add_page.c is the one that is responsible for adding new tabs (pages to the notebook)
also the file called removesearch also contains some very important files that are required for the proper functioning of the system eg it contains the function that removes a tab and a lot more you can open in a text editor and take a look if you are a programmer but don't change anything if you don't understand  what it does for it might lead to compilation errors

REQUIRMENT
there should also be a gtk labrary installed in your machine
there should be a webkit library install in your machine


COMPILING THE CODE FROM SOURCE
in order to compile the code from source you need to compile the various files  files independently and then link them 
or you do the compilation and linking at the same time by using :
gcc -o  main main.c add_page.c removesearch.c `pkg-config --cflags --libs gtk+-2.0 webkit-1`
then run the program by using ./real
that's all what is required for someone to compile and run the code
else you should just double click on the executable file named main and you will be good to go
or you open the terminal and type ./main on the directory where the file named real is found
