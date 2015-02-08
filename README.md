# README #

# Structris for Atari 800 #
Retrochallenge 2015/01 project to learn about Noahsoft's PL65 language and use it to port the modern-day Apple II game, Structris, to the Atari 800.
If you just want the game disk look in the Downloads section for "STRUCTRS.ATR"

### Game Prerequisites ###
   * Any Atari 800 emulator that reads ATR disk images (get the STRUCTRS.ATR file from the Downloads section).

### Build Prerequisites ###
   * atari800 emulator for Unix (Makefile uses recorded session to playback build process)
   * gcc (Used to compile simple C program to convert the ASCII file to something digestible to the Atari 800)


##  Version ##
   *   0.1 
      *   Initial Version
   *   0.2 
      *   Corrected scoring 
      *   Corrected drawing along line 0
      *   Added version number to title/help screen

## Known Bugs ##
   * Graphics mode temporarily glitches during cut-scene animation (now a feature)
   * Pink pieces occasionally hesitate before making appearance
