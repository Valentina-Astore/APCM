# Su Mac se non funziona dare tutti i percorsi
#gcc fibonacci.c -o fibonacci -lgmp -I/opt/local/include -L/opt/local/lib
all: factorial fibonacci simple
factorial: factorial.c
	gcc factorial.c -o factorial -lgmp

fibonacci: fibonacci.c
	gcc fibonacci.c -o fibonacci -lgmp

simple: simple.c
	gcc simple.c -o simple -lgmp
