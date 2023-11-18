build_funcional: ./test/functional/Main.cpp FunctionalTests.o ModelImpl.o FlowImpl.o FlowExponential.o FlowLogistic.o SystemImpl.o 
	g++ ./test/functional/Main.cpp -o ./bin/FunctionalTests ./bin/SystemImpl.o ./bin/FlowImpl.o ./bin/FlowExponential.o ./bin/FlowLogistic.o ./bin/ModelImpl.o ./bin/FunctionalTests.o 

SystemImpl.o: ./src/SystemImpl.cpp ./src/SystemImpl.hpp
	g++ -Wall -g -c ./src/SystemImpl.cpp -o ./bin/SystemImpl.o

FlowImpl.o: ./src/FlowImpl.cpp ./src/FlowImpl.hpp SystemImpl.o
	g++ -Wall -g -c ./src/FlowImpl.cpp -o ./bin/FlowImpl.o

FlowExponential.o: ./test/models/FlowExponential.cpp ./test/models/FlowExponential.hpp SystemImpl.o
	g++ -Wall -g -c ./test/models/FlowExponential.cpp -o ./bin/FlowExponential.o

FlowLogistic.o: ./test/models/FlowLogistic.cpp ./test/models/FlowLogistic.hpp SystemImpl.o
	g++ -Wall -g -c ./test/models/FlowLogistic.cpp -o ./bin/FlowLogistic.o

ModelImpl.o: ./src/ModelImpl.cpp ./src/ModelImpl.hpp FlowImpl.o SystemImpl.o
	g++ -Wall -g -c ./src/ModelImpl.cpp -o ./bin/ModelImpl.o

FunctionalTests.o: ./test/functional/FunctionalTests.cpp ./test/functional/FunctionalTests.hpp ModelImpl.o FlowImpl.o SystemImpl.o
	g++ -Wall -g -c ./test/functional/FunctionalTests.cpp -o ./bin/FunctionalTests.o

run_functional:
	./bin/FunctionalTests

clean:
	rm -f ./bin/*
