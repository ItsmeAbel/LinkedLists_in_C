#vars       $(X)
CC = gcc



lab3 : huvud.o driv.o list.o; $(CC) -o lab3 huvud.o driv.o list.o

huvud.o: huvud.c driv.h list.h; $(CC) -c $<
%.o: %.c %.h; $(CC) -c $<

clean:;rm *.o lab3
