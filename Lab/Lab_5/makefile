outputProg = lab5
progFiles = driver.cpp imageP5.cpp

run: compile
	./$(outputProg) lab5Out.ppm

compile: $(progFiles)
	g++ -std=c++11 -Wall $(progFiles) -o $(outputProg)

clean:
	rm lab5
	rm lab5Out.ppm

cc:
	rm lab5
	rm lab5Out.ppm
	clear