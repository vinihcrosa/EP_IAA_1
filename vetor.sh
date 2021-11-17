#!/bin/bash
for i in {1..100}
do
./main $1 $2 dados_$1_$2.csv
done