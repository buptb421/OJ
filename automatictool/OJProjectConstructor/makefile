ylibAnalyser : ConstData.hpp ylibAnalyser.o ScopeOperation.o LineOperation.o StringOperation.o
	g++ ylibAnalyser.o -o ylibAnalyser

ylibAnalyser.o : ylibAnalyser.cpp ConstData.hpp ScopeOperation.o LineOperation.o StringOperation.o
	g++ -c -Wall -g ylibAnalyser.cpp

ScopeOperation.o : ScopeOperation.cpp ScopeOperation.hpp ConstData.hpp LineOperation.o StringOperation.o
	g++ -c -Wall -g ScopeOperation

LineOperation.o : LineOperation.cpp LineOperation.hpp ConstData.hpp StringOperation.o
	g++ -c -Wall -g LineOperation.cpp

StringOperation.o : StringOperation.cpp StringOperation.hpp ConstData.hpp
	g++ -c -Wall -g StringOperation.cpp

.PHONY : clean

clean :
	rm ylibAnalyser.o ylibAnalyser ScopeOperation.o LineOperation.o StringOperation.o
