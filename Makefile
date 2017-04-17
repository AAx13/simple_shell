all:
	gcc -Wall -Werror -pedantic -Wextra *.c -o shell
gdb:
	gcc -Wall -Werror -pedantic -Wextra *.c -ggdb -o shell
run:
	./shell
run-v:
	valgrind -v ./shell
run-m:
	valgrind --leak-check=full --show-leak-kinds=all ./shell
run-e:
	valgrind --track-origins=yes ./shell
clean:
	rm shell *~ *\#
