NAME = endgame

SRC = src/*.c

INC = inc/*.h

CFILES = *.c

HFILES = *.h

CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic

FFLAGS = -I ./inc/SDL2.framework/Headers \
	-I ./SDL2_image.framework/Headers \
    -F ./inc -framework SDL2 -rpath ./inc \
	-F ./inc -framework SDL2_image -rpath ./inc \


all: install clean

install:
	@cp $(SRC) .
	@cp $(INC) .
	@clang $(CFLAGS) $(FFLAGS) -o $(NAME) $(CFILES)
clean:
	@rm -rf $(CFILES)
	@rm -rf $(HFILES)
uninstall: clean
	@rm -rf $(NAME)

reinstall: uninstall all