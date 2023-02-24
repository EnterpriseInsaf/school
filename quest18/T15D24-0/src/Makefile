FLAGS = -Wall -Werror -Wextra

database: modules_db.c modules.c levels.c status_events.c shared.c binary_work.c
	gcc $(FLAGS) -c modules_db.c modules.c levels.c status_events.c shared.c binary_work.c
	gcc modules.o levels.o status_events.o shared.o modules_db.o binary_work.o -o database

clean:
	rm *.o
	rm ../build/*
	
all: database
