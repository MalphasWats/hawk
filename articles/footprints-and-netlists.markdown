# Footprints and Netlists

Now that we have a completed schematic we need to fill in some extra information to enable us to build a PCB. Each of the symbols that we have placed need to be associated with a *Footprint*. Footprints describe how a component will attach to a PCB. It defines how many *pads* there are, where they are and how they map to the component pins.

To set the footprint for a symbol, hover over it and press *E* to bring up the symbol properties.

Start by doing this with the SAMD10 MCU symbol:

![Footprints Set][055]

If you look at the *Footprint* field, you can see that it is already populated with a footprint. In this case, it's using the *Package_SO:SOIC-14_3.9x8.7mm_P1.27mm* footprint. Some symbols in the library already have a suitable footprint associated to them, so we can leave this one alone.

Let's look at the bypass capacitor symbol *C1* next. Bring the mouse over it and press *E*:

![Footprint not set][056]

Notice that the *Footprint* field is blank. Let's assign one.

Select the *Footprint* field by clicking on it in the list. On the right-hand side of the window click the *Browse Footprints* button to bring up the footprint browser:

![Footprint Browser][057]

Footprints are organised into categories, although these don't really match up with the symbol library categories.

For this project we're going to use Surface Mounted components, in *0805* size so let's browse to the *Capacitor_SMD* category and find the *Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder* footprint. Double-click it to select it and set it as the footprint for this symbol.

We need to set the footprints for each symbol (excluding the power net symbols - +3V3, GND and +BATT). To speed things up a little, we can copy and paste the field value between similar components. This schematic has 3 capacitors which will all have the same footprint. Select the text in the field and copy it, then you can press *E* over the other two capacitors and paste the value in.

![Copy-pasting footprints][058]

Do the reset pull-up resistor next. Hover over the symbol and press *E*, use the symbol browser to find an 0805 SMD resistor footprint:

![Resistor footprint][059]

Next up is the LED:

![LED Footprint][060]

Then the programming connector - we'll use a Through-hole footprint for this one so we can solder header pins in:

![Programming footprint][061]

Similarly, the GPIO connectors will be through-hole. Don't forget that there's 2 of those too!

![GPIO footprint][062]

Last is the button. I have about a million 6mm through-hole tactile switches, they're really common. I'm going to use the footprint for that switch:

![Button footprint][063]

With footprints all assigned to the symbols, the last step in designing our schematic is to generate a *Net list*. The net list describes how all of the components connect together and is used by the PCB design software to keep track of everything.

Choose *Generate Netlist File...* from the *Tools* menu:

![Generate Netlist][064]

Default settings are all fine, click the *Generate Netlist* button to create it. You'll be asked to save a file. Save it in the same folder with the rest of your project.

And that's it, we're finally ready to start designing the PCB.

[055]: screenshots/055-footprint-already-set.png
[056]: screenshots/056-footprint-not-set.png
[057]: screenshots/057-choosing-capacitor-footprint.png
[058]: screenshots/058-copy-footprint-value.png
[059]: screenshots/059-resistor-footprint.png
[060]: screenshots/060-LED-footprint.png
[061]: screenshots/061-programming-connector-footprint.png
[062]: screenshots/062-GPIO-footprint.png
[063]: screenshots/063-button-footprint.png
[064]: screenshots/064-generate-netlist.png
