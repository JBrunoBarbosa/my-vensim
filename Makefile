all: dll functional unit

dll:
	g++ -c ./src/*.cpp -fpic
	g++ *.o -shared -o ./bin/my_vensim_lib.dll -fpic
	del *.o

functional:
	g++ -c ./test/functional/*.cpp ./test/models/*.cpp
	g++ *.o -o ./bin/functional -L./bin -lmy_vensim_lib
	del *.o

unit:
	g++ -c ./test/unit/*.cpp ./test/models/*.cpp
	g++ *.o -o ./bin/unit -L./bin -lmy_vensim_lib
	del *.o

run_functional: 
	./bin/functional

run_unit:
	./bin/unit
	
clean: 
	del /Q .\bin\*.exe
	del /Q .\bin\*.dll

run:
	./main