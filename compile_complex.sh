#!/bin/bash
#A short bash script to help with compiling the files that contain the Complex class

echo Beginning Compilation
echo Compiling...
g++ ComplexOperations.cpp Complex.cpp -o ComplexOperations
echo Completed 1 of 2 \(ComplexOperations\)
g++ Equivalence.cpp Complex.cpp -o EquivalenceCalculator
echo Completed 2 of 2 \(EquivalenceCalculator\)
echo Compilation Complete
