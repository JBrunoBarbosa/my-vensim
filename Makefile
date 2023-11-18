all: build_funcional build_unit

build_funcional: FunctionalTests.o ModelImpl.o FlowImpl.o FlowExponential.o FlowLogistic.o SystemImpl.o MainFuncional.o
	g++ ./bin/FunctionalTests.o ./bin/SystemImpl.o ./bin/FlowImpl.o ./bin/FlowExponential.o ./bin/FlowLogistic.o ./bin/ModelImpl.o ./bin/MainFuncional.o -o ./bin/FunctionalTests

build_unit: UnitFlow.o UnitSystem.o UnitModel.o SystemImpl.o FlowImpl.o FlowExponential.o FlowLogistic.o ModelImpl.o MainUnit.o
	g++ ./bin/UnitFlow.o ./bin/UnitSystem.o ./bin/UnitModel.o ./bin/SystemImpl.o ./bin/FlowImpl.o ./bin/FlowExponential.o ./bin/FlowLogistic.o ./bin/ModelImpl.o ./bin/MainUnit.o -o ./bin/UnitTests

SystemImpl.o: ./src/SystemImpl.cpp ./src/SystemImpl.hpp
	g++ -Wall -g -c ./src/SystemImpl.cpp -o ./bin/SystemImpl.o

FlowImpl.o: ./src/FlowImpl.cpp ./src/FlowImpl.hpp
	g++ -Wall -g -c ./src/FlowImpl.cpp -o ./bin/FlowImpl.o

FlowExponential.o: ./test/models/FlowExponential.cpp ./test/models/FlowExponential.hpp 
	g++ -Wall -g -c ./test/models/FlowExponential.cpp -o ./bin/FlowExponential.o

FlowLogistic.o: ./test/models/FlowLogistic.cpp ./test/models/FlowLogistic.hpp 
	g++ -Wall -g -c ./test/models/FlowLogistic.cpp -o ./bin/FlowLogistic.o

ModelImpl.o: ./src/ModelImpl.cpp ./src/ModelImpl.hpp 
	g++ -Wall -g -c ./src/ModelImpl.cpp -o ./bin/ModelImpl.o

FunctionalTests.o: ./test/functional/FunctionalTests.cpp ./test/functional/FunctionalTests.hpp
	g++ -Wall -g -c ./test/functional/FunctionalTests.cpp -o ./bin/FunctionalTests.o

MainFuncional.o: ./test/functional/Main.cpp
	g++ -Wall -g -c ./test/functional/Main.cpp -o ./bin/MainFuncional.o

UnitFlow.o: ./test/unit/UnitFlow.cpp ./test/unit/UnitFlow.hpp
	g++ -Wall -g -c ./test/unit/UnitFlow.cpp -o ./bin/UnitFlow.o

UnitSystem.o: ./test/unit/UnitSystem.cpp ./test/unit/UnitSystem.hpp
	g++ -Wall -g -c ./test/unit/UnitSystem.cpp -o ./bin/UnitSystem.o

UnitModel.o: ./test/unit/UnitModel.cpp ./test/unit/UnitModel.hpp
	g++ -Wall -g -c ./test/unit/UnitModel.cpp -o ./bin/UnitModel.o

MainUnit.o: ./test/unit/Main.cpp
	g++ -Wall -g -c ./test/unit/Main.cpp -o ./bin/MainUnit.o

run_functional: build_funcional
	./bin/FunctionalTests

run_unit: build_unit
	./bin/UnitTests

clean:
	del /Q .\bin\*
