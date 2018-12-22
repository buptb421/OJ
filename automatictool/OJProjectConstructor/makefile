ylibAnalyser : ylibAnalyser.o
	g++ ylibAnalyser.o -o ylibAnalyser
ylibAnalyser.o : ylibAnalyser.cpp dataheader.hpp
	g++ -c -Wall -g ylibAnalyser.cpp

.PHONY : clean

clean :
	rm ylibAnalyser.o ylibAnalyser
