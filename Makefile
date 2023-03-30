__start__: clean_screen clean _free_lines_ obj all __end__ #run
INCLUDEPATH += inc/
CFLAGS = -Wall -pedantic -I$(INCLUDEPATH)# tutaj można dodawać inne flagi kompilatora
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
	
all: OBJ/rectangle.o  OBJ/main.o
	@echo "Kompilacja i konsolidacja programu"
	@echo
	g++ ${CFLAGS} -o ${OUT} OBJ/main.o OBJ/rectangle.o 
	@echo
	@echo

OBJ/rectangle.o: src/rectangle.cpp inc/rectangle.hpp
	@echo "Kompilacja pliku $(bold)rectangle.cpp$(sgr0)"
	@echo
	g++ -c ${CFLAGS} src/rectangle.cpp -o OBJ/rectangle.o
	@echo
	@echo

OBJ/main.o: src/main.cpp inc/rectangle.hpp
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