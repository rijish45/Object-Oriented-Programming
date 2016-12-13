CC = g++
CFLAGS = -c


OBJS = main.o Game_Command.o Model.o View.o Game_Object.o Person.o Miner.o Soldier.o Gold_Mine.o Town_Hall.o Cart_Point.o Cart_Vector.o

default: PA4

PA4: $(OBJS)
	$(CC) -o PA4 $(OBJS)

Cart_Point.o: Cart_Point.cpp Cart_Point.h Cart_Vector.h
	$(CC) $(CFLAGS) Cart_Point.cpp -o Cart_Point.o

Cart_Vector.o: Cart_Vector.cpp Cart_Vector.h
	$(CC) $(CFLAGS) Cart_Vector.cpp -o Cart_Vector.o

Game_Object.o: Game_Object.cpp Game_Object.h Cart_Point.h Cart_Vector.h Model.h
	$(CC) $(CFLAGS) Game_Object.cpp -o Game_Object.o

Gold_Mine.o: Gold_Mine.cpp Gold_Mine.h Game_Object.h Cart_Point.h Model.h
	$(CC) $(CFLAGS) Gold_Mine.cpp -o Gold_Mine.o

Town_Hall.o: Town_Hall.cpp Town_Hall.h Game_Object.h Cart_Point.h Model.h
	$(CC) $(CFLAGS) Town_Hall.cpp -o Town_Hall.o

Person.o: Person.cpp Person.h Model.h Game_Object.h Cart_Point.h Cart_Vector.h Town_Hall.h Gold_Mine.h
	$(CC) $(CFLAGS) Person.cpp -o Person.o

Miner.o: Miner.cpp Miner.h Person.h Game_Object.h Gold_Mine.h Town_Hall.h Cart_Point.h Cart_Vector.h Model.h
	$(CC) $(CFLAGS) Miner.cpp -o Miner.o

Soldier.o: Soldier.cpp Soldier.h Person.h Game_Object.h Cart_Point.h Cart_Vector.h Model.h
	$(CC) $(CFLAGS) Soldier.cpp -o Soldier.o

#Inspector.o: Inspector.cpp Inspector.h Model.h Person.h Game_Object.h Cart_Point.h Cart_Vector.h Model.h
#$(CC) $(CFLAGS) Inspector.cpp -o Inspector.o

View.o: View.cpp View.h Game_Object.h Cart_Point.h
	$(CC) $(CFLAGS) View.cpp -o View.o

Model.o: Model.cpp Model.h Game_Object.h Person.h Miner.h Soldier.h Town_Hall.h Gold_Mine.h View.h
	$(CC) $(CFLAGS) Model.cpp -o Model.o

Game_Command.o: Game_Command.cpp Game_Command.h Model.h View.h Person.h Town_Hall.h Gold_Mine.h Cart_Point.h
	$(CC) $(CFLAGS) Game_Command.cpp -o Game_Command.o

main.o: main.cpp Model.h View.h Game_Object.h
	$(CC) $(CFLAGS) main.cpp -o main.o

# destroys old object (.o) files before a new make
clean:
	rm $(OBJS)
