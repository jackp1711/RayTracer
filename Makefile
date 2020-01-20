OBJ = main.o
INC = -I "./"

RayTracer: $(OBJ)
	g++ $(OBJ) -o RayTracer.exe
	rm -f $(OBJ)

main.o:
	g++ -c src/main.cpp $(INC)

clean:
	rm -f $(OBJ) RayTracer