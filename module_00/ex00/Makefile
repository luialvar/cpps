# Nombre del ejecutable
NAME = megaphone

# Lista de archivos fuente
SRCS = megaphone.cpp

# Archivos objeto generados a partir de los fuentes
OBJS = $(SRCS:.cpp=.o)

# Compilador y flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Regla por defecto: compilar el ejecutable
all: $(NAME)

# Regla para generar el ejecutable a partir de los objetos
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

# Regla implícita para generar los objetos a partir de los fuentes
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de archivos objeto
clean:
	rm -f $(OBJS)

# Limpieza completa (objetos + ejecutable)
fclean: clean
	rm -f $(NAME)

# Regenerar todo
re: fclean all

# Evitar conflictos con archivos que se llamen como reglas
.PHONY: all clean fclean re
