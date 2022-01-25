g++ -g -c src/ElementType.C -o obj/ElementType.o
g++ -g -c src/ListADT.C -o obj/ListADT.o
g++ -g -c src/BigIntAdd.C -o obj/BigIntAdd.o
g++ -g -c src/BigIntAddMain.C -o obj/BigIntAddMain.o
g++ obj/BigIntAddMain.o obj/BigIntAdd.o obj/ListADT.o obj/ElementType.o -o bin/solution