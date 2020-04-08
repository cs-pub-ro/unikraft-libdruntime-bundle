run: main

main:	main.o helper.o
	dmd -L-lstdc++ main.o helper.o

main.o:	main.d
	dmd main.d -c

helper.o: helper.cpp
	g++ helper.cpp -c

clean:
	rm *.o main
