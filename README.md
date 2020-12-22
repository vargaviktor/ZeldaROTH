# ZeldaROTH
Port of Zelda ROTH on 3ds

This is a port to 3ds of a great Zelda fan game, Zelda Return of the Hylian.
Additional new language to play: Hungarian

## Screenshots
![Screenshot0](https://github.com/vargaviktor/ZeldaROTH/blob/master/zeldaroth0.png)
![Screenshot1](https://github.com/vargaviktor/ZeldaROTH/blob/master/zeldaroth1.jpg)
![Screenshot2](https://github.com/vargaviktor/ZeldaROTH/blob/master/zeldaroth2.jpg)

## Credits

The original game is made by Vincent Jouillat (http://www.zeldaroth.fr)
Original port made by NOD90
This game uses the sf2d sftd and sfil libraries created by Xerpi.
Hungarian translation added by vargaviktor.

## Installation

In the zip there is a folder with the 3dsx and amdh files inside, to be used with a homebrew launcher. All the resources are included in the executabile using romfs.
The game creates a ZeldaROTH subfolder inside the 3ds folder if doesn't exist. Here will be saved your game progresses.
In the zip there is also a CIA version.

## Commands
- Read / Open / Speak: A
- Confirm / Pass text: A
- Move Link: Arrows
- Run : R hold
- Use sword: B
- Spin attack: B hold then dropped
- Item selection: L + START
- Use selected object: X
- Pick up items (with the glove): Y
- Open the map: START (outside of dungeons)
- Open the map: START (in dungeons)
- View defeated monsters: L and B
- Look around: L and direction
- Enlarge / Shrink screen size: L and A
- Show help: L and X
- Save / Quit: SELECT
- Close the game: SELECT from the title screen

## Build
1. Install [DevKitPro](https://devkitpro.org/wiki/Getting_Started)
2. Run your shell (ie. `MSYS2 64bit > MSYS2 MinGW 64 bit`), then change into your development/working directory, ie.:

  ```sh
  cd /c/Users/Development/3ds/
  ```
3. Install the 3dportlibs in pacman

  ```sh
  pacman -S 3ds-portlibs
  ```
4. Build and install latest `sf2dlib`:

  ```sh
  git clone https://github.com/vargaviktor/sf2dlib
  cd sf2dlib/libsf2d
  make
  make install
  cd ../..
  ```

5. Build and install latest `sfillib`:

  ```sh
  git clone https://github.com/xerpi/sfillib
  cd sfillib/libsfil
  make
  make install
  cd ../..
  ```

6. Build and install latest `sftdlib`:

  ```sh
  git clone https://github.com/xerpi/sftdlib
  cd sftdlib/libsftd
  make
  make install
  cd ../..
  ```

7. Build ZeldaROTH`:
  ```sh
  git clone https://github.com/vargaviktor/ZeldaROTH
  cd ZeldaROTH
  make
  ```
  
## Testing
### On Nintendo 3DS
1. Start the Homebrew launcher on 3DS
2. Send the .3dsx file to the 3DS with 3dslink

## Creating CIA
1. Download and install [makerom](https://github.com/3DSGuy/Project_CTR/releases)
2. Strip the ELF (make a beckup copy before, it will modify it).
  ```sh
  strip <builded.elf>
  ```
3. Run makerom
  ```sh
  makerom -f cia -o <target.cia> -rsf ./resources/<resourcefile.rsd> -target t -exefslogo -elf <stripped.elf> -icon <builded.smdh> -banner ./resources/banner.bin
  ```
 
