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

Using the *scroll-wheel* on the mouse lets you zoom in so  you can actually see what you're doing. As far as I've managed to work out, zooming like this centres the zoom wherever your mouse pointer is.

![Place Power Symbols][011]

Notice that the capacitor and MCU aren't connected directly, we've just connected them to the power net, it'll be up to us to place them sensibly on the PCB so that the capacitor can do its job.

Ok, let's create a reset circuit. First, we want to add a *pull-up* resistor to the MCU's reset pin. If we simply leave the pin floating, the MCU could behave strangely as our circuit gets subjected to electromagnetic interference.

We'll start by labelling the reset pin. I use *global* labels because I think they make a schematic more readable. Choose *Global Label* from the *Place* menu and then click on the end of the lead for *pin 6* to bring up the label pane:

![Adding a global label][012]

Give the label a sensible name and make sure *Left* is chosen for *Orientation*. Click *OK* and then click the mouse on the end of the *pin 6* lead to attach the label to it.

![Place the label][013]

Whilst we're at it, let's add 2 more labels for the programming pins, we're already in *Label Place mode* so we just need to click on the schematic to add a new label:

![Programming pin labels][014].

Next let's add the pull-up resistor. Press *A* to go back into symbol placing mode and bring up the symbol browser. You'll find it in the *Devices* section again, called simply *R*.

Click to place it, then use the *C* shortcut to copy the 3V3 power symbol and attach it to the top lead of the resistor. Use *C* again to copy the *reset* label from the MCU pin 6.

With the *reset* label attached to the mouse, press the *R* key to rotate it 90 degrees. Press the *R* key until the label is pointing *up* and attach it to the bottom lead of the resistor.

Finally, hover over the bottom *R* label, press *E* and add a suitable resistance value - I tend to use 10K ohm:

![Pull up resistor][015]

Alright, we have a stable circuit for an MCU. If you look at each symbol it has a second label with the symbol designator (U, C, R) and a question mark (?). We need to annotate our schematic to give each of these a unique identifying number. You can simply hover over each one, press *E* and type it manually, and indeed sometimes that's the way you want to do it, however, there is also a tool built in that will do it for us. You can do this at any stage of development, including right at the very end, but I like to try to keep an eye on what numbers mean what and do it as I go.

Choose *Annotate Schematic...* from the *Tools* menu to bring up the annotation tool

![Annotation tool][016]

Default settings are fine, simply click *Annotate* to automatically annotate the schematic symbols:

![Annotated Schematic][017]

We get *U1*, *C1*, and *R1*.

**Now is also a good place to save the schematic if you haven't already.**

Now we'll add a button so we can reset the MCU when we're frustrated that it isn't doing what it's supposed to be because we wrote the wrong code but haven't accepted that yet.

Press *A* to add a symbol, navigate to *Switches* and find the SW_Push symbol. It doesn't really matter too much which switch symbols we use for a simple Single-pole-single-throw switch, but this is technically the *proper* one.

![Push Switch][018]

Double-click to choose the symbol then click somewhere on the schematic to place it.

Use the *C* key to duplicate the *reset* label and connect it to the left-hand lead of the switch symbol.

Next duplicate a *GND* symbol from somewhere and place it *near* the right-hand lead:

![Reset Circuit][019]

You *could* simply connect the *GND* symbol to the switch, but I think it looks a little bit cluttered, so instead, we'll leave a little gap and use the *Wiring tool* to connect the symbols.

Press the *W* key to choose the wiring tool and then click the little circle stuck to the end of the right-hand lead of the switch symbol, then move your mouse, drawing a green wire behind and click the little circle at the top of the *GND* symbol to connect them together:

![Complete reset circuit][020]

So now we have *A*, *P*, *M*, *E*, *R* and *W* shortcuts. All well worth remembering.

All development boards need an LED, otherwise how are you supposed to write a Blink program for it? Let's add one.

Start off by adding a new *Global Label*, call it *LED* and orient it *Right*:

![LED Label][021]

Connect it to *pin 13* of the MCU.

Next, press *A* to add an LED symbol. Whilst the symbol browser has an LED section, all the symbols in here appear to be special ones. We just want the LED symbol in the *Device* category. I prefer the *LED_Alt* version. Double click it and then place it somewhere on the schematic.

![LED symbol][022]

Next, add a resistor (or duplicate the one from the reset pull up), place it near the LED symbol and edit its value to 1k. Now, duplicate the *LED* label, rotate it and connect it to the left-hand lead of the LED. Finally, duplicate a *GND* symbol and place it near the right-hand lead of the resistor:

![LED Circuit][023]

Use the *W* key to switch to wiring mode and connect the circuit:

![Complete LED circuit][024]

Now is a good point to annotate the schematic **and save it**:

![Annotated Schematic][025]

We could simply stop there. We could program the MCU using one of those clip things and then we have everything we need to blink an LED, but ultimately the feeling of achievement would fade and we'd be left with more e-junk. Let's expand our circuit a little so it's useful after we've flashed a light.

We'll start off adding a programming header. I don't have one of those clip things that would fit this chip.

Press *A* to add a new symbol, expand the *Connector_Generic* category and find a 2x3 Odd/Even connector:

![SWD Connector][026]

The SAMD10 is programmed using the Single-Wire-Debug (SWD) interface, so-called because it uses just a single wire. Plus one other wire, a reset wire, power and ground. So 5 wires. There are some standard connector layouts for SWD as part of the JTAG definition, but these tend to use connectors with at least 10 pins and as many as 20. I already have a nice little 2x3 programming ribbon cable so I'm using that. The nice thing about tutorials is you're entirely free to do it you're own way!

Place the connector on the schematic and rename it to something useful. Remember you can hover over the *Conn_02x03_Odd_Even* label and press *E*. I've named it *SWD_PGM*.

![Place Connector][027]

Earlier we created some global labels for *reset*, *SWDIO* and *SWCLK*. Duplicate those, along with a *+3V3* and a *GND* and connect them to the connector leads as below:

![Connect programming header][028]

I've used this layout because it's similar to the ISP layout for programming AVR via SPI. This helps me remember what each pin is for.

Next up, let's add some headers for some of the GPIO pins. Use *A* to add 2 generic 1x4 connectors:

![Generic Connector][029]

Place one and name it:

![Place Connector][030]

Duplicate and rename it:

![Duplicate connector][031]

I wanted to have an extra visual queue for which connector is which, so I mirrored the second one so the leads pointed the other way. Hover your mouse over the symbol and press *E*, choose *Mirror around y-axis* from the *Aspect* section:

![Mirror Connector][032]

Create some more *global labels*:

![GPIO Labels][033]

One for each of the spare MCU pins:

![GPIO Labels placed][034]

Now duplicate each one and connect them to the generic connector pins:

![GPIO Labels connected to connector][035]

We've reached another good point to annotate and **save the schematic**

![Annotate schematic][036]

One thing that bugged me about the annotations for the connectors was that one of the GPIO connectors was *J1*, the programming connector was *J2* and the other GPIO connector ended up with *J3*. If you're more normal this probably doesn't bother you.

To edit the *Reference field*, hover over it with your mouse and press *E*.

![Change reference field][037]

You can change the numbers to make things more sensible.

![Updated Annotations][038]

We've also reached the end of this part of the tutorial. Again, at this stage we could make the PCB and we'd have a board that we could actually use, but there are a few more things I want to add first.


## Caveats

It's worth noting at this point that there are a few issues with the schematic. I made the thing and took all of the screenshots in one go with a view to creating this tutorial rather than a super-awesome-development-board. Afterwards I was reading the [SAMD10 Datasheet](http://ww1.microchip.com/downloads/en/devicedoc/atmel-42242-sam-d10_datasheet.pdf). Section 36 has some suggestions for a reset circuit (p 854) which includes an extra resistor to control the discharge of the bypass capacitor when the reset pin is grounded. It also notes that the reset pin has an internal pull-up resistor so doesn't necessarily need an external one. Personally I think it's a good habit to get into, if only for reset pins.

It also strongly recommends (p 858) that the *SWCLK* pin has a pull-up resistor added to it to prevent noise. If we were making a commercial product, we'd probably go back and fix that. I know from previous experiments with this chip though that it should still work in most cases without it.

I also noticed that there's no easy way to supply power to any theoretical breadboard we might plug this device into. Although we could actually use the *+3V3* and *GND* pins from the programming connector if we needed to, this wouldn't be ideal. To fix this, we could instead make the 1x4 GPIO connectors into 1x5 and add connections to the power net.

This is what the updated schematic for these fixes might look like:

![Updated Schematic][038-5]

The rest of the tutorial however will still use the older version. I've ordered the boards to be made like this too, so we can actually find out how well it works anyway!

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

[038-5]: screenshots/038-updated-schematic.png
