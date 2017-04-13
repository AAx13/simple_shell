
all:
	gcc -Wall -Werror -pedantic -Wextra *.c -o simple_shell
run:
	valgrind ./simple_shell
run-v:
	valgrind -v ./simple_shell
run-m:
	valgrind --leak-check=full --show-leak-kinds=all ./simple_shell
run-e:
	valgrind --track-origins=yes ./simple_shell
clean:
	rm simple_shell *~ *\#
