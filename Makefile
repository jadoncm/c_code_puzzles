OK_COLOR=\x1b[32;01m
NO_COLOR=\x1b[0m
OK_STRING=$(OK_COLOR)[COMPILING]$(NO_COLOR)
PP_STRING=$(OK_COLOR)[PREPROCESSER]$(NO_COLOR)

default: bug01 bug02 bug03 bug04 bug05 bug06 bug07 bug08 bug09 misc01

bug01: find_the_bugs/bug01.c
	@echo -e '$(OK_STRING)     bug01..'
	@gcc find_the_bugs/bug01.c -o bug01

bug02: find_the_bugs/bug02.c
	@echo -e '$(OK_STRING)     bug02..'
	@gcc find_the_bugs/bug02.c -o bug02

bug03: find_the_bugs/bug03.c
	@echo -e '$(OK_STRING)     bug03..'
	@gcc find_the_bugs/bug03.c -o bug03

bug04: find_the_bugs/bug04/caller.c find_the_bugs/bug04/func.c
	@echo -e '$(OK_STRING)     bug04..'
	@gcc -Wno-int-to-pointer-cast -c -o find_the_bugs/bug04/func.o find_the_bugs/bug04/func.c
	@gcc -Wno-int-to-pointer-cast find_the_bugs/bug04/caller.c -o bug04 find_the_bugs/bug04/func.o

bug05: find_the_bugs/bug05.c
	@echo -e '$(PP_STRING)  bug05.pp..'
	@gcc -E find_the_bugs/bug05.c -o bug05.pp

bug06: find_the_bugs/bug06.1.c
	@echo -e '$(OK_STRING)     bug06..'
	@gcc find_the_bugs/bug06.1.c -o bug06

bug07: find_the_bugs/bug07.c
	@echo -e '$(OK_STRING)     bug07..'
	@gcc find_the_bugs/bug07.c -o bug07

bug08: find_the_bugs/bug08.c
	@echo -e '$(OK_STRING)     bug08..'
	@gcc find_the_bugs/bug08.c -o bug08

bug09: find_the_bugs/bug09.c
	@echo -e '$(OK_STRING)     bug09..'
	@gcc find_the_bugs/bug09.c -o bug09

misc01: misc/misc01.c
	@echo -e '$(OK_STRING)     misc01..'
	@gcc misc/misc01.c -o misc01
	
clean:
	@rm -rfv bug* find_the_bugs/bug04/func.o ./misc01
