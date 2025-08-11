# Hyprland Macro Board
  A fully custom macro board designed to improve workflow on Hyprland or any related window managers.

# LCD Image Help
  It might be that you do not like the images I've used for the LCD Screen (in hyprland-macro-board/macro-board-images/). If that is the case I would recommend using https://javl.github.io/image2cpp/ to 
convert images. You can make your own 128x32 (recommended) or get images off the internet and have image2cpp monochrome and resize them for you.

# Copying Keyboard Firmware to qmk_firmware Directory 
  Copy /hyprland-macro-board/hyprmacroboard into where your qmk_firmware/keyboards directory is so you can easily flash the firmware. Do this in the /hypr-macro-board directory

``` 
cp hyprmacroboard /PATH/TO/YOUR/QMK/KEYBOARD/DIR
```

# Compiling and Flashing
* Compile:
``` 
qmk compile -kb hyprmacroboard -km default
```

* Flash:
```
qmk flash -kb hyprmacroboard -km default
```

# Things to know 
  Resetting the board is annoying 9_9
