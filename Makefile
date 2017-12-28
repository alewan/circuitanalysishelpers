#Everything
all: equivalence complexops deltawye cleanobjfiles
	@echo "Task Complete"

#Executables with object file dependencies
equivalence: equivalence.o complex.o
	@g++ Equivalence.o complex.o -o EquivalenceCalculator

complexops: complexoperations.o complex.o
	@g++ complexoperations.o complex.o -o ComplexOps

#Executables without .o dependencies
deltawye: delta_wyecalculator.cpp
	@g++ delta_wyecalculator.cpp -o DeltaWyeCalculator

#Intermediate Object Files (can be removed with cleanobjfiles)
complex.o: Complex.cpp Complex.h
	@g++ -c Complex.cpp -o complex.o

complexoperations.o: ComplexOperations.cpp Complex.h
	@g++ -c ComplexOperations.cpp -o complexoperations.o

equivalence.o: Equivalence.cpp Complex.h
	@g++ -c Equivalence.cpp

#Cleanup
cleanobjfiles:
	@rm -f *.o

clean: cleanobjfiles
	@rm -f EquivalenceCalculator ComplexOps DeltaWyeCalculator
	@echo "Task Complete"