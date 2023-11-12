build_funcional: ./test/functional/Main.cpp FunctionalTests.o Model.o Flow.o System.o 
	g++ ./test/functional/Main.cpp -o ./bin/FunctionalTests ./bin/System.o ./bin/Flow.o ./bin/FlowExponential.o ./bin/FlowLogistic.o ./bin/Model.o ./bin/FunctionalTests.o 

System.o: ./src/System.cpp ./src/System.hpp
	g++ -Wall -g -c ./src/System.cpp -o ./bin/System.o

Flow.o: ./src/Flow.cpp ./src/Flow.hpp System.o
	g++ -Wall -g -c ./src/Flow.cpp -o ./bin/Flow.o

FlowExponential.o: ./test/models/FlowExponential.cpp ./test/models/FlowExponential.hpp System.o
	g++ -Wall -g -c ./test/models/FlowExponential.cpp -o ./bin/FlowExponential.o

FlowLogistic.o: ./test/models/FlowLogistic.cpp ./test/models/FlowLogistic.hpp System.o
	g++ -Wall -g -c ./test/models/FlowLogistic.cpp -o ./bin/FlowLogistic.o

Model.o: ./src/Model.cpp ./src/Model.hpp Flow.o System.o
	g++ -Wall -g -c ./src/Model.cpp -o ./bin/Model.o

FunctionalTests.o: ./test/functional/FunctionalTests.cpp ./test/functional/FunctionalTests.hpp Model.o Flow.o FlowExponential.o FlowLogistic.o System.o
	g++ -Wall -g -c ./test/functional/FunctionalTests.cpp -o ./bin/FunctionalTests.o

run_functional:
	./bin/FunctionalTests

clean:
	rm -f ./bin/*