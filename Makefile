NAME = endgame
INC = inc/header.h
HEADTMP = header.h
SRCS = src/rand.c \
    
CTMP = rand.c \
	
OUT = ./src/fsdl.o \

FFLAG1 = -I ./inc/SDL2.framework/Headers \
	-I ./SDL2_mixer.framework/Headers \

FFLAG2 = -F ./inc -framework SDL2 -rpath ./inc \
	-F ./inc -framework SDL2_mixer -rpath ./inc \

all: install uninstall
install:
	@cp $(SRCS) .
	@cp $(INC) .
	@clang $(CFLAGS) $(FFLAG1) $(FFLAG2) $(DFLAGS) -o $(NAME) $(CTMP)
uninstall: clean
	@rm -rf $(CTMP)
	@rm -rf $(OUT)
	@rm -rf $(HEADTMP)
clean:
	@rm -rf $(CTMP)
	@rm -rf $(OUT)
	@rm -rf $(HEADTMP)
reinstall: clean all
