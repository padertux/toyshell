# toyshell
Little shell that uses fork, execvp, waitpid and the readline library. The readline library can be consumed via conan package.


# Install
mkdir toyshell
cd toyshell
cp ~/source/toyshell/conanfile.txt .
conan install .
cmake ~/source/toyshell/
make
