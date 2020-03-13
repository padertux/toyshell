all: toyshell.cpp
	g++ -o toyshell toyshell.cpp -lreadline

clean:
	rm toyshell
