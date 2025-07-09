# *CShift*
## **My Custom CLI**  

### **Command listing**:  
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



### **Notes**:  
- CShift only supports debian-based linux distros because of dependencies on linux-only headers such as *<unistd.h>* and installations made using the apt package manager (if you somehow installed it on an arch-linux based system, good for you, you can use CShift).  
- To install CShift, you can download cshift.tar.gz and move the unzippped folder to the home directory (~) and to run it you can run "./cshift/cshift-executable" after having changes execute permissions  
- To make CShift your main shell, go to the terminal and edit your config file for the shell you want to run CShift the moment that shell is open. In there, put the line at the bottom ./~/cshift/cshift-executable
