__start__: clean_screen _free_lines_  clean  _horizontal_line_ all _horizontal_line2_ __end__ #run
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
_horizontal_line_:
	@echo "----------------------------------------------------------------------------"
_horizontal_line2_:
	@echo "----------------------------------------------------------------------------"

__end__:
	@echo
	@echo "\e[41mSkompilowano i skonsolidowano program\e[49m"
	@echo "Uruchom plik $(bold)${OUT}$(sgr0) w celu przetestowania programu"  
	@echo  ""
	
all: OBJ/vector2d.o OBJ/matrix2x2.o OBJ/geometric_obj.o OBJ/cuboid.o OBJ/hexagonal_prism.o OBJ/drone.o OBJ/gnuplot_link.o OBJ/main.o
	@echo "\e[42mKompilacja i konsolidacja programu\e[49m"
	g++ -Wall -pedantic -std=c++0x -o ${OUT} OBJ/main.o OBJ/cuboid.o OBJ/vector2d.o OBJ/matrix2x2.o OBJ/gnuplot_link.o  OBJ/geometric_obj.o OBJ/hexagonal_prism.o OBJ/drone.o 

OBJ/cuboid.o: src/cuboid.cpp inc/cuboid.hpp inc/matrix2x2.hpp inc/vector2d.hpp inc/geometric_obj.hpp 
	@echo "\e[44mKompilacja pliku $(bold)cuboid.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/cuboid.cpp -o OBJ/cuboid.o
	@echo
	@echo

OBJ/hexagonal_prism.o: src/hexagonal_prism.cpp inc/hexagonal_prism.hpp inc/matrix2x2.hpp inc/vector2d.hpp inc/geometric_obj.hpp 
	@echo "\e[44mKompilacja pliku $(bold)hexagonal_prism.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/hexagonal_prism.cpp -o OBJ/hexagonal_prism.o
	@echo
	@echo

OBJ/vector2d.o: src/vector2d.cpp inc/vector2d.hpp
	@echo "\e[44mKompilacja pliku $(bold)vector2d.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/vector2d.cpp -o OBJ/vector2d.o
	@echo
	@echo

OBJ/drone.o:  src/drone.cpp inc/drone.hpp inc/hexagonal_prism.hpp inc/cuboid.hpp inc/matrix2x2.hpp inc/vector2d.hpp inc/geometric_obj.hpp 
	@echo "\e[44mKompilacja pliku $(bold)drone.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/drone.cpp -o OBJ/drone.o
	@echo
	@echo

OBJ/matrix2x2.o: src/matrix2x2.cpp inc/matrix2x2.hpp inc/vector2d.hpp
	@echo "\e[44mKompilacja pliku $(bold)matrix2x2.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/matrix2x2.cpp -o OBJ/matrix2x2.o
	@echo
	@echo


OBJ/gnuplot_link.o: src/gnuplot_link.cpp inc/gnuplot_link.hpp
	@echo "\e[44mKompilacja pliku $(bold)gnuplot_link.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/gnuplot_link.cpp -o OBJ/gnuplot_link.o
	@echo
	@echo
OBJ/geometric_obj.o:  src/geometric_obj.cpp inc/geometric_obj.hpp inc/matrix2x2.hpp inc/vector2d.hpp 
	@echo "\e[44mKompilacja pliku $(bold)geometric_obj.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/geometric_obj.cpp -o OBJ/geometric_obj.o
	@echo
	@echo
OBJ/main.o: src/main.cpp inc/cuboid.hpp inc/vector2d.hpp inc/matrix2x2.hpp inc/gnuplot_link.hpp inc/hexagonal_prism.hpp inc/drone.hpp
	@echo "\e[44mKompilacja pliku $(bold)main.cpp$(sgr0)\e[49m"
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
	
	@echo "\e[40mUsuwanie plikow $(bold)*.o$(sgr0) w katalogu $(bold)OBJ$(sgr0)\e[49m"
	rm -f OBJ/*
# @echo "$(bold)Usuwanie$(sgr0) katalogu$(bold) OBJ$(sgr0)"
# rmdir OBJ

clean_exec:
	rm Program

obj: 
	@echo "\e[40mTworzenie katalogu$(bold) OBJ$(sgr0)\e[49m"
	mkdir OBJ
	@echo

run: clean_screen go


go:
	@echo "Uruchamianie pliku $(bold)${OUT}$(sgr0)"
	./${OUT}


clean_screen:
	clear


clean_pgm:
	rm *.pgm