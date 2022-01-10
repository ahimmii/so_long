CC = gcc
W = -lmlx -framework OpenGL -framework AppKit
CFILES =	so_long.c \
			ft_itoa.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_putnbr.c \
			ft_split.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			maps.c \
			mlx_key.c \
			move.c test.c \
			ft_strncmp.c
CFILESBONUS =	so_long_bonus.c \
				ft_itoa_bonus.c \
				ft_memcpy_bonus.c \
				ft_memmove_bonus.c \
				ft_putnbr_bonus.c \
				ft_split_bonus.c \
				ft_strdup_bonus.c \
				ft_strjoin_bonus.c \
				ft_strlen_bonus.c \
				maps_bonus.c \
				mlx_key_bonus.c \
				move.c test_bonus.c \
				ft_strncmp_bonus.c

OFILES = ${CFILES:.c=.o}
OFILESBONUS = ${CFILESBONUS:.c=.o}
NAME = so_long.a
INC = so_long.h
INCBONUS = so_long_bonus.h
NAMEO = -o so_long

${NAME} : ${OFILES} ${INC}
	@${CC} ${W} ${NAMEO} ${CFILES}
	@ar -rc ${NAME} ${OFILES}
clean :
	@rm -f  ${OFILES} ${OFILESBONUS}
fclean : clean
	@rm -f ${NAME}
bonus : ${OFILESBONUS} ${INCBONUS}
	@${CC} ${W} ${NAMEO} ${CFILESBONUS}
	@ar -rc ${NAME} ${OFILESBONUS}
re : fclean all
all : ${NAME}
