CC = gcc
CFLAGS = -Wall -Wextra -g

OBJ = main.o liste.o insertion.o suppression.o analyse.o operations.o

programme: $(OBJ)
	$(CC) $(CFLAGS) -o programme $(OBJ)

main.o: main.c liste.h insertion.h suppression.h analyse.h operations.h
	$(CC) $(CFLAGS) -c main.c

liste.o: liste.c liste.h
	$(CC) $(CFLAGS) -c liste.c

insertion.o: insertion.c insertion.h liste.h
	$(CC) $(CFLAGS) -c insertion.c

suppression.o: suppression.c suppression.h liste.h
	$(CC) $(CFLAGS) -c suppression.c

analyse.o: analyse.c analyse.h liste.h
	$(CC) $(CFLAGS) -c analyse.c

operations.o: operations.c operations.h liste.h
	$(CC) $(CFLAGS) -c operations.c

clean:
	rm -f *.o programme
