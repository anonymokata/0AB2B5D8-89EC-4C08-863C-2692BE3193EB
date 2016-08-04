CC=gcc

BUILDDIR=build
OBJDIR=obj
SRCDIR=src

build: $(OBJDIR)/roman_calculator.o
	mkdir -p $(BUILDDIR)
	ar rcs $(BUILDDIR)/libroman_calculator.a $(OBJDIR)/roman_calculator.o

$(OBJDIR)/roman_calculator.o: $(SRCDIR)/roman_calculator.c
	mkdir -p $(OBJDIR)
	$(CC) -fPIC -o $(OBJDIR)/roman_calculator.o -c $(SRCDIR)/roman_calculator.c

clean: 
	rm -r -f $(OBJDIR)
	rm -r -f $(BUILDDIR)