all: build_funcional build_unit

build_funcional: FunctionalTests.o FlowExponential.o FlowLogistic.o MainFuncional.o System.dll Flow.dll Model.dll MyVensim.dll
	g++ -Wall -g ./bin/FunctionalTests.o ./bin/FlowExponential.o ./bin/FlowLogistic.o ./bin/MainFuncional.o -o ./bin/FunctionalTests -L./bin -lFlow -lModel -lMyVensim

build_unit: UnitFlow.o UnitSystem.o UnitModel.o MainUnit.o FlowLogistic.o FlowExponential.o System.dll Flow.dll Model.dll MyVensim.dll
	g++ -Wall -g ./bin/UnitFlow.o ./bin/FlowExponential.o ./bin/FlowLogistic.o ./bin/UnitSystem.o ./bin/UnitModel.o ./bin/MainUnit.o -o ./bin/UnitTests -L./bin -lSystem -lFlow -lModel -lMyVensim

System.dll: ./src/SystemImpl.cpp 
	g++ -Wall -g -shared ./src/SystemImpl.cpp -o ./bin/System.dll

Flow.dll: ./src/FlowImpl.cpp
	g++ -Wall -g -shared ./src/FlowImpl.cpp -o ./bin/Flow.dll 

Model.dll: ./src/ModelImpl.cpp 
	g++ -Wall -g -shared ./src/ModelImpl.cpp -o ./bin/Model.dll -L./bin -lSystem -lFlow

MyVensim.dll: ./src/MyVensimImpl.cpp 
	g++ -Wall -g -shared ./src/MyVensimImpl.cpp -o ./bin/MyVensim.dll -L./bin -lSystem -lFlow -lModel

FlowLogistic.o: ./test/models/FlowLogistic.cpp 
	g++ -Wall -g -c ./test/models/FlowLogistic.cpp -o ./bin/FlowLogistic.o

FlowExponential.o: ./test/models/FlowExponential.cpp 
	g++ -Wall -g -c ./test/models/FlowExponential.cpp -o ./bin/FlowExponential.o

FunctionalTests.o: ./test/functional/FunctionalTests.cpp
	g++ -Wall -g -c ./test/functional/FunctionalTests.cpp -o ./bin/FunctionalTests.o

MainFuncional.o: ./test/functional/Main.cpp
	g++ -Wall -g -c ./test/functional/Main.cpp -o ./bin/MainFuncional.o 

UnitFlow.o: ./test/unit/UnitFlow.cpp FlowExponential.o 
	g++ -Wall -g -c ./test/unit/UnitFlow.cpp -o ./bin/UnitFlow.o 

UnitSystem.o: ./test/unit/UnitSystem.cpp 
	g++ -Wall -g -c ./test/unit/UnitSystem.cpp -o ./bin/UnitSystem.o 

UnitModel.o: ./test/unit/UnitModel.cpp 
	g++ -Wall -g -c ./test/unit/UnitModel.cpp -o ./bin/UnitModel.o 

MainUnit.o: ./test/unit/Main.cpp
	g++ -Wall -g -c ./test/unit/Main.cpp -o ./bin/MainUnit.o

run_functional: build_funcional
	./bin/FunctionalTests

run_unit: build_unit
	./bin/UnitTests

clean:
	del /Q .\bin\*
