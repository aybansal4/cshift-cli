 cshift.cpp# cshift-cli
***My Custom CLI***  

**Command listing**:  
make file <filename>
:   Create a file

make directory <dirname>
:   Create a directory

delete file <filename>
:   Move file to trash

delete directory <dirname>
:   Move directory to trash

edit --nano <filename>
:   Edit file with nano

edit --vi <filename>
:   Edit file with vi

execute <filename>
:   Run a file:
    - *.js → runs with node
    - *.class → runs with java
    - others → runs as executable

c++ <filename>
:   Compile a C++ file with g++

c <filename>
:   Compile a C file with gcc

java <filename>
:   Compile a Java file with javac

move <source> <destination>
:   Move or rename a file/directory

packages all
:   Install common packages (nodejs, JDK, build-essential, etc.)

packages <package>
:   Install a specific package

bash <command...>
:   Execute a raw bash command

zsh <command...>
:   Execute a raw zsh command

chdir <path>
:   Change working directory (supports `~` for home)

list
:   List files in current directory

list more
:   List files with detailed view

end
:   Exit the shell
    
help
:  Show list of commands



**Notes**:  
- CShift only supports linux distros because of dependencies on linux-only headers such as *<unistd.h>*  
- To install CShift, you can download cshift.tar.gz and move the unzippped folder to the home directory (~) and to run it you can run "./cshift/cshift-executable" after having changes execute permissions  
- To make CShift your main shell, go to the terminal (preferably GNOME), select the three lines and hit preferences, if you don't already have a profile, make one and select it, go to command the click run custom command instead of my shell, and put "./cshift-executable" in the box unless you renamed or moved cshift-executable in which case you put the execute command with the path to the CShift executable in the box. Save the setting and done.  

***WARNING:***  
    If you want to make cshift your main shell, please never, ever delete cshift-executable in the main directory, doing this will delete the whole of cshift permanently.
