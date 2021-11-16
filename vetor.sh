#!/bin/bash
for i in {1..100}
do
./vetor $1 vetor$i.txt
./main 20 vetor$i.txt dados_$1.csv
rm -rf vetor$i.txt
done