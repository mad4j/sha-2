
EXE=sha2t


all: $(EXE)

$(EXE):
	gcc sha2.c sha2t.c -o $(EXE)

clean:
	-rm -rf $(EXE)

