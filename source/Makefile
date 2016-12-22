# Makefile

CC	= cc
OBJS	= asteroid_main.o sub.o all_acc.o acc.o predictor.o corrector.o iteration.o energy.o orbital_elements.o timestep.o angularmomentum.o
CFILE	= asteroid_main.c sub.c all_acc.c acc.c predictor.c corrector.c iteration.c energy.c orbital_elements.c timestep.c angularmomentum.c
FLAG	= -g -O0

asteroid: $(OBJS)
	$(CC) -O3 -o $@ $(OBJS)

debug: $(OBJS)
	$(CC) $(FLAG) -o $@ $(OBJS)

.c.o:
	$(CC) -c $<

$(OBJS): $(CFILE) asteroid.h


clean:
	rm -f $(OBJS) *~ *.dat
