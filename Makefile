CC=g++
CFLAGS=-c -Wshadow -Winit-self \
		-Wredundant-decls -Wcast-align \
		-Wundef -Wfloat-equal -Winline -Wunreachable-code \
		-Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum \
		-Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe \
		-fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy \
		-Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
SOURCES=main.cpp solver.cpp input_coefficients.cpp printer.cpp proverka.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=my_program.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o my_program.exe
