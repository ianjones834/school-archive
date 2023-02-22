CFLAGS = -c -I$(HOME)/source/schoolwork/csis-3700/Programming/include

libdataStructures.a: ../src/fraction.o ../src/dictionary.o
	ar r libdataStructures.a ../src/fraction.o ../src/dictionary.o

../src/fraction.o: ../src/fraction.cpp ../include/fraction.h
	g++ $(CFLAGS) -o ../src/fraction.o ../src/fraction.cpp

../src/dictionary.o: ../src/dictionary.cpp ../include/dictionary.h
	g++ $(CFLAGS) -o ../src/dictionary.o ../src/dictionary.cpp