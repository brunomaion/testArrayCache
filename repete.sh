#!/bin/bash
./criar

echo "=-=-=Testando com Matriz Normal=-=-="
for i in {200..2000..200}; do
	echo "Testando $i"
	for j in 1 2 3 4 5 6 7 8 9 10; do
		echo "Teste $j"
		./final o $i $i $i $i 
		echo ""
	done
	echo ""
done
echo "=-=-=Testando com Matriz Transposta=-=-="
for i in {200..2000..200}; do
	echo "Testando $i"
	for j in 1 2 3 4 5 6 7 8 9 10; do
		echo "Teste $j"
		./final t $i $i $i $i 
		echo ""
	done
	echo ""
done
