__start__: clean_screen _free_lines_  clean  _horizontal_line_ all _horizontal_line2_ __end__ #run
INCLUDEPATH += inc/
CFLAGS = -g -I$(INCLUDEPATH) -Wall -pedantic -std=c++0x# compilators flags
LIBS =  #libs flags
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
	
all: OBJ/vector2d.o OBJ/matrix2x2.o OBJ/geometric_obj.o OBJ/scene_obj.o OBJ/cuboid.o OBJ/hexagonal_prism.o OBJ/cuboid_obstacle.o OBJ/drone.o OBJ/scene.o  OBJ/scene.o OBJ/lacze_do_gnuplota.o OBJ/main.o 
	@echo "\e[42mKompilacja i konsolidacja programu\e[49m"
	g++ -g -Wall -pedantic -std=c++0x -o ${OUT} OBJ/main.o OBJ/cuboid.o OBJ/scene_obj.o OBJ/vector2d.o OBJ/matrix2x2.o   OBJ/geometric_obj.o OBJ/hexagonal_prism.o OBJ/drone.o  OBJ/lacze_do_gnuplota.o OBJ/cuboid_obstacle.o OBJ/scene.o

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


OBJ/matrix2x2.o: src/matrix2x2.cpp inc/matrix2x2.hpp inc/vector2d.hpp
	@echo "\e[44mKompilacja pliku $(bold)matrix2x2.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/matrix2x2.cpp -o OBJ/matrix2x2.o
	@echo
	@echo


# OBJ/gnuplot_link.o: src/gnuplot_link.cpp inc/gnuplot_link.hpp
# 	@echo "\e[44mKompilacja pliku $(bold)gnuplot_link.cpp$(sgr0)\e[49m"
# 	g++ -c ${CFLAGS} src/gnuplot_link.cpp -o OBJ/gnuplot_link.o
# 	@echo
# 	@echo

OBJ/lacze_do_gnuplota.o: src/lacze_do_gnuplota.cpp inc/lacze_do_gnuplota.hpp
	@echo "\e[44mKompilacja pliku $(bold)lacze_do_gnuplota.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/lacze_do_gnuplota.cpp -o OBJ/lacze_do_gnuplota.o
	@echo
	@echo
OBJ/geometric_obj.o:  src/geometric_obj.cpp inc/geometric_obj.hpp inc/matrix2x2.hpp inc/vector2d.hpp 
	@echo "\e[44mKompilacja pliku $(bold)geometric_obj.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/geometric_obj.cpp -o OBJ/geometric_obj.o
	@echo
	@echo
OBJ/scene_obj.o:  src/scene_obj.cpp inc/scene_obj.hpp inc/vector2d.hpp
	@echo "\e[44mKompilacja pliku $(bold)scene_obj.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/scene_obj.cpp -o OBJ/scene_obj.o
	@echo
	@echo
OBJ/scene.o:  src/scene.cpp inc/scene.hpp inc/matrix2x2.hpp inc/vector2d.hpp  inc/drone.hpp inc/scene_obj.hpp inc/cuboid_obstacle.hpp
	@echo "\e[44mKompilacja pliku $(bold)scene.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/scene.cpp -o OBJ/scene.o
	@echo
	@echo
OBJ/drone.o:  src/drone.cpp inc/drone.hpp inc/hexagonal_prism.hpp inc/cuboid.hpp inc/matrix2x2.hpp inc/vector2d.hpp inc/geometric_obj.hpp inc/scene_obj.hpp
	@echo "\e[44mKompilacja pliku $(bold)drone.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/drone.cpp -o OBJ/drone.o
	@echo
	@echo
OBJ/cuboid_obstacle.o:  src/cuboid_obstacle.cpp inc/cuboid_obstacle.hpp inc/matrix2x2.hpp inc/vector2d.hpp  inc/cuboid.hpp
	@echo "\e[44mKompilacja pliku $(bold)cuboid_obstacle.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/cuboid_obstacle.cpp -o OBJ/cuboid_obstacle.o
	@echo
	@echo
OBJ/main.o: src/main.cpp inc/cuboid.hpp inc/vector2d.hpp inc/matrix2x2.hpp inc/gnuplot_link.hpp inc/hexagonal_prism.hpp inc/drone.hpp inc/scene_obj.hpp
	@echo "\e[44mKompilacja pliku $(bold)main.cpp$(sgr0)\e[49m"
	g++ -c ${CFLAGS} src/main.cpp -o OBJ/main.o
	@echo
	@echo

number_of_files=$(ls -A OBJ | wc -l)
clean:	
	@echo "Removing old $(bold) *.o$(sgr0) files"
	@if test -d OBJ; then echo "$(bold)OBJ $(sgr0)directory found"; else echo "$(bold)OBJ $(sgr0) not found... creating" && mkdir OBJ; fi;
	@[ -f OBJ/lacze_do_gnuplota.o ] && rm OBJ/lacze_do_gnuplota.o && echo "rm $(bold) lacze_do_gnuplota.o$(sgr0)" || echo no  " **$(bold) lacze_do_gnuplota.o doesn't exist$(sgr0) **"
	@[ -f OBJ/vector2d.o ] && rm OBJ/vector2d.o && echo "rm $(bold) vector2d.o$(sgr0)" || echo no  " **$(bold) vector2d.o doesn't exist$(sgr0) **"
	@[ -f OBJ/matrix2x2.o ] && rm OBJ/matrix2x2.o && echo "rm $(bold) matrix2x2.o$(sgr0)" || echo  " **$(bold) matrix2x2.o doesn't exist$(sgr0) **"
	@[ -f OBJ/geometric_obj.o ] && rm OBJ/geometric_obj.o && echo "rm $(bold) geometric_obj.o$(sgr0)" || echo " **$(bold) geometric_obj.o doesn't exist$(sgr0) **"
	@[ -f OBJ/cuboid.o ] && rm OBJ/cuboid.o && echo "rm $(bold) cuboid.o$(sgr0)" || echo  " **$(bold) cuboid.o doesn't exist$(sgr0) **"
	@[ -f OBJ/hexagonal_prism.o ] && rm OBJ/hexagonal_prism.o && echo "rm $(bold) hexagonal_prism.o$(sgr0)" || echo  "$(bold) hexagonal_prism.o doesn't exist$(sgr0) **"
	@[ -f OBJ/scene_obj.o ] && rm OBJ/scene_obj.o && echo "rm $(bold) scene_obj.o$(sgr0)" || echo " **$(bold) scene_obj.o doesn't exist$(sgr0) **"
	@[ -f OBJ/drone.o ] && rm OBJ/drone.o && echo "rm $(bold) drone.o$(sgr0)" || echo  " **$(bold) drone.o doesn't exist$(sgr0) **"
	@[ -f OBJ/cuboid_obstacle.o ] && rm OBJ/cuboid_obstacle.o && echo "rm $(bold) cuboid_obstacle.o$(sgr0)" || echo  " **$(bold) cuboid_obstacle.o doesn't exist$(sgr0) **"
	@[ -f OBJ/scene.o ] && rm OBJ/scene.o && echo "rm $(bold) scene.o$(sgr0)" || echo   " **$(bold) scene.o doesn't exist$(sgr0) **"
	@[ -f OBJ/main.o ] && rm OBJ/main.o && echo "rm $(bold) main.o$(sgr0)" || echo " **$(bold) main.o doesn't exist$(sgr0) **"
	
# @[ -f OBJ/gnuplot_link.o ] && rm OBJ/gnuplot_link.o && echo "rm $(bold) gnuplot_link.o$(sgr0)" || echo  " **$(bold) gnuplot_link.o doesn't exist$(sgr0) **"
	
clean_exec:
	rm Program

obj: 	
	@if [ ls -d OBJ ]; then\
		echo "OBJ directory found";\
	else echo "Making the $(bold) OBJ$(sgr0) directory" && mkdir OBJ;\
    fi

run: clean_screen go


go:
	@echo "Uruchamianie pliku $(bold)${OUT}$(sgr0)"
	./${OUT}

data_dir:
	@if [ ls -d data/ ]; then\
	echo "data directory found"; \
	else  mkdir OBJ;\
    fi
data_clean:
	rm data/*	
clean_screen:
	clear


clean_pgm:
	rm *.pgm