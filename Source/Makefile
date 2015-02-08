BAS=STRUCTRS
IMG=../Disks/$(BAS).atr

TAR=$(BAS).PRG
SRC=$(BAS).pl65
UTL=pl65_to_prg

all:	$(IMG)

$(IMG):	$(TAR)
	atari800 -atari -playback build.rec -H1 ../Work ../Disks/PL65_BW.atr $(IMG)

$(TAR): $(SRC) $(UTL)
	./pl65_to_prg $(SRC) > ../Work/$(TAR)

$(UTL): $(UTL).c
	gcc -o $(UTL) $(UTL).c

.PHONY: run
run:
	atari800 -atari $(IMG)

.PHONY: record
record:
	atari800 -atari -record build.rec -rtime8 -H1 ../Work ../Disks/PL65_BW.atr $(IMG)

.PHONY: edit
edit:
	vim -u ./.vimrc $(SRC)

.PHONY: norun
norun:
	atari800 -atari ../Disks/PL65_BW.atr $(IMG)

.PHONY: log
log:
	./atari2ascii ../Work/STRUCTRS.ERR > structrs.err
	cat structrs.err
