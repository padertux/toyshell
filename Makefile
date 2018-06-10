all: shell.cpp
	g++ -o shell shell.cpp -lreadline 

clean:
	rm shell
