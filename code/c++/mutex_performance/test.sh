#!/bin/bash

for j in `seq 1 3`; do
    echo "====================================="
    echo "Recurso compartido entre $j thread/s"
    echo "====================================="
    echo ""
    for i in `seq 0 3`; do
        if [[ $i -eq 2 ]]; then
            continue
        fi
        g++ -std=c++11 -Werror -Wall -pedantic -pthread main.cpp mutex.cpp futex.cpp aux.cpp mutex_v0.cpp mutex_v1.cpp mutex_v2.cpp mutex_v3.cpp -o main -DN_THREADS=$j -DMUTEX_V=$i
        /usr/bin/time -p ./main
        echo ""
    done
done
