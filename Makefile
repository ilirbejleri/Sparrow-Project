p3: p3.cpp libsparrow.dylib p1 p2
	g++ -std=c++20 p3.cpp -L./ -lsparrow -o p3 -g
p2: p2.cpp libsparrow.dylib p1
	g++ -std=c++20 p2.cpp -L./ -lsparrow -o p2 
p1: p1.cpp libsparrow.dylib
	g++ -std=c++20 p1.cpp -L./ -lsparrow -o p1
libsparrow.dylib: sparrow.cpp sparrow.h
	g++ -std=c++20 -dynamiclib -o libsparrow.dylib sparrow.cpp
