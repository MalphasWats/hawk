# Creating the schematic

I'm using KiCAD for this project. It's free and it more than does the job. I'm sure people have various Strong Opinions on which EDA software is the best, but I'm also sure that they're all wrong, regardless of which one they think is best.

Open up KiCAD and create a new project:

![New KiCAD Project][001]

I've named this project *Hawk*. My projects generally get named when I make them a repository in [GitHub](https://github.com/MalphasWats). I think I wanted a name that suggested 'dev-board' and had recently read a tweet about Tony Hawk, who is a skate*board*er. Welcome, reader, to the inside of my brain.

We'll start by creating a Schematic for our board:

![New KiCAD Schematic][002]

Ok, we have a nice blank schematic. Press the *A* key to add a *symbol*. This brings up the symbol browser:

![Symbol Browser][003]

Now, this is where things go immediately off the rails - the basic installation of KiCAD does not have a symbol for the Microcontroller we're using in this project. You can download these footprints from the [KiCAD GitHub Symbol Library](https://kicad.github.io/symbols/).

Once you've downloaded the correct library [ (MCU Microchip SAMD) ](https://kicad.github.io/symbols/MCU_Microchip_SAMD), choose *Manage Symbol Libraries...* from the *Preferences* menu, then click the *Browse Libraries...* button to add the downloaded library.

Now you should be able to find the ATSAMD10C14 symbol shown in the screenshot. This is the only 'non-standard' component we'll be using for this project.

Double click the symbol in the list and the browser window closes and the symbol is attached to your mouse. Click anywhere on the page to add the symbol to the schematic.

![Symbol Placed][004]

Congratulations, you've made a schematic! It doesn't really do very much yet though. Let's add a bypass capacitor for the MCU IC.

When we pressed *A* earlier, we selected the *Place Symbol* tool, that means we just have to click anywhere on the schematic page to add another symbol. KiCAD puts passive components like capacitors and resistors in the *Devices* section of the symbol library browser:

![Finding Passives][005]

Expand it and find the *C* symbol (I prefer to use the *C_Small* version, but either will do.).

![Bypass Capacitor][006]

Double click to select the symbol then click where you want to place it on the schematic page:

![Capacitor Placed][007]

I tend to use 0.1uF capacitors for bypassing ICs, I'm sure the internet is replete with screeds on why a different value is better. Frankly, most of my projects work without even bothering to solder the thing to the board.

Bring your mouse over the capacitor *Value Field*, if you chose the regular symbol version it will just be a capital *C*, otherwise it'll say *C_Small*. With your mouse over the field, press the *E* key on your keyboard to bring up the field editor.

Enter the new value for your capacitor and press *OK*.

![Edit the field value][008]

We'll connect the capacitor to the power net next. Press *P* on the keyboard to bring up the *Power Symbol Browser*.

![Power Symbol Browser][010]

Expand the *power* list and scroll down to find +3V3. Double click it to select.

Now, instead of just clicking on an empty spot on the schematic, attach the symbol to the lead sticking out of the top of the capacitor symbol.

Press *P* again and scroll down to place a *GND* symbol. Attach it to the bottom lead of the capacitor symbol.

Once you have symbols placed on the schematic, you can duplicate them by hovering over them and pressing the *C* key. Duplicate the +3V3 symbol and the GND symbol to attach them to the relevant leads of the MCU.

You'll also notice in the screenshot below that I've moved the labels for the MCU. You can do this by hovering your mouse over them and pressing *M*.

*M*, *C*, *A* and *P* are super useful shortcuts for laying out schematics. They become muscle memory quite quickly.

![Place Power Symbols][011]

[001]: screenshots/001-new-kicad-project.png
[002]: screenshots/002-new-kicad-schematic.png
[003]: screenshots/003-adding-a-component.png
[004]: screenshots/004-first-component-placed.png
[005]: screenshots/005-finding-passives.png
[006]: screenshots/006-adding-bypass-capacitor.png
[007]: screenshots/007-capacitor-placed.png
[008]: screenshots/008-editing-field-value.png
[009]: screenshots/009-adding-power-symbols.png
[010]: screenshots/010-power-symbols-list.png
[011]: screenshots/011-power-symbols-placed.png
[012]: screenshots/012-adding-global-label.png
[013]: screenshots/013-global-label-placed.png
[014]: screenshots/014-more-global-labels.png
[015]: screenshots/015-reset-pull-up.png
[016]: screenshots/016-annotations.png
[017]: screenshots/017-components-annotated.png
[018]: screenshots/018-reset-switch.png
[019]: screenshots/019-reset-switch-circuit.png
[020]: screenshots/020-wiring.png
[021]: screenshots/021-adding-LED-label.png
[022]: screenshots/022-adding-LED-component.png
[023]: screenshots/023-LED-circuit.png
[024]: screenshots/024-LED-circuit-wired.png
[025]: screenshots/025-annotations.png
[026]: screenshots/026-programming-connector.png
[027]: screenshots/027-programming-connector-placed.png
[028]: screenshots/028-programming-connector-labelled.png
[029]: screenshots/029-GPIO-connector.png
[030]: screenshots/030-GPIO-connector-placed.png
[031]: screenshots/031-GPIO-connector-duplicated.png
[032]: screenshots/032-GPIO-connector-mirrored.png
[033]: screenshots/033-GPIO-labels.png
[034]: screenshots/034-GPIO-labels-placed.png
[035]: screenshots/035-GPIO-labels-duplicated.png
[036]: screenshots/036-connectors-annotated.png
[037]: screenshots/037-editing-connector-annotations.png
[038]: screenshots/038-connector-annotations-edited.png
