all: shell.cpp
	g++ -o toyshell shell.cpp -lreadline 

clean:
	rm toyshell
