__start__: clean_screen clean _free_lines_ obj all __end__ #run
INCLUDEPATH += inc/
CFLAGS = -g -I$(INCLUDEPATH) -Wall -pedantic -std=c++0x# tutaj można dodawać inne flagi kompilatora
LIBS =  #tutaj można dodawać biblioteki
OUT=Program
bold := $(shell tput bold)
sgr0 := $(shell tput sgr0)


_free_lines_:
	@echo 
	@echo
	@echo

__end__:
	@echo
	@echo "Skompilowano i skonsolidowano program"
	@echo "Uruchom plik $(bold)${OUT}$(sgr0) w celu przetestowania programu"  
	@echo  ""
	
all: OBJ/rectangle.o  OBJ/main.o OBJ/vector2d.o OBJ/matrix2x2.o OBJ/gnuplot_link.o
	@echo "Kompilacja i konsolidacja programu"
	@echo
	g++ -Wall -pedantic -std=c++0x -o ${OUT} OBJ/main.o OBJ/rectangle.o OBJ/vector2d.o OBJ/matrix2x2.o  OBJ/gnuplot_link.o
	@echo
	@echo

OBJ/rectangle.o: src/rectangle.cpp inc/rectangle.hpp
	@echo "Kompilacja pliku $(bold)rectangle.cpp$(sgr0)"
	@echo
	g++ -c ${CFLAGS} src/rectangle.cpp -o OBJ/rectangle.o
	@echo
	@echo


OBJ/vector2d.o: src/vector2d.cpp inc/vector2d.hpp
	@echo "Kompilacja pliku $(bold)vector2d.cpp$(sgr0)"
	@echo
	g++ -c ${CFLAGS} src/vector2d.cpp -o OBJ/vector2d.o
	@echo
	@echo


OBJ/matrix2x2.o: src/matrix2x2.cpp inc/matrix2x2.hpp
	@echo "Kompilacja pliku $(bold)matrix2x2.cpp$(sgr0)"
	@echo
	g++ -c ${CFLAGS} src/matrix2x2.cpp -o OBJ/matrix2x2.o
	@echo
	@echo


OBJ/gnuplot_link.o: src/gnuplot_link.cpp inc/gnuplot_link.hpp
	@echo "Kompilacja pliku $(bold)gnuplot_link.cpp$(sgr0)"
	@echo
	g++ -c ${CFLAGS} src/gnuplot_link.cpp -o OBJ/gnuplot_link.o
	@echo
	@echo

OBJ/main.o: src/main.cpp inc/rectangle.hpp inc/vector2d.hpp inc/matrix2x2.hpp inc/gnuplot_link.hpp
	@echo "Kompilacja pliku $(bold)main.cpp$(sgr0)"
	@echo
	g++ -c ${CFLAGS} src/main.cpp -o OBJ/main.o
	@echo
	@echo


# OBJ/image.o: src/image.c inc/image.h
# 	@echo "Kompilacja pliku $(bold)Image.c$(sgr0)"
# 	@echo
# 	g++ -c ${CFLAGS} src/image.c -o OBJ/image.o
# 	@echo
# 	@echo

clean:
	
	@echo "Usuwanie plikow $(bold)*.o$(sgr0) w katalogu $(bold)OBJ$(sgr0)"
	@echo
	rm -f OBJ/*
	@echo
	@echo "$(bold)Usuwanie$(sgr0) katalogu$(bold) OBJ$(sgr0)"
	@echo
	rmdir OBJ

clean_exec:
	rm Program

obj: 
	@echo "Tworzenie katalogu$(bold) OBJ$(sgr0)"
	@echo
	mkdir OBJ
	@echo
	@echo

run: clean_screen go


go:
	@echo "Uruchamianie pliku $(bold)${OUT}$(sgr0)"
	./${OUT}


clean_screen:
	clear


clean_pgm:
	rm *.pgm