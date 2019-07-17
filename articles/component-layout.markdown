# Laying out the Components

Now that we have our outline placed we need to arrange the components inside it. When laying out components on a board there are 2 key aspects that must be considered and balanced:

1. All the components will need to be connected together with traces in order for the board to function.
2. The board will need to make sense to the user in what ever context it will be used.

Even for a simple board like this, these two 'goals' will sometimes oppose each other. The nature of our board here means that #2 is going to impose the main *constraints*. Consider that we want to be able to plug this board into a breadboard. The position of the header pins is therefore important and this should be fairly obvious. Perhaps less obvious is that this also means that we need all of the components to be placed on the **top** of the board. We *could* get away with perhaps putting some of them on the bottom because of the plastic spacers lift the PCB away from the breadboard, but it is certainly something that would have to be considered - imagine a design that includes electrolytic capacitors for example!

When laying out components, clever use of the built-in grid can be really helpful. In the top toolbar, just below the menubar there's a *Grid:* drop-down menu. It has a lot of options built-in and you can also add custom grids too. We want to choose the 2.5400mm grid in order to place the GPIO headers. This will ensure that they will fit into a breadboard.

Hover the mouse over one of the header footprints and press the *m* key. This will attach it to the mouse so you can move it. Place it with a click. You may also need to rotate them, which you can do with *r*.

Place them at the edges of the PCB as shown:

![GPIO Headers][080]

Notice that they aren't centred - don't worry about this at this stage, and don't change the grid so you can nudge them to fit nicely! We'll fix that later.

Move the MCU footprint to sit between them - you'll probably want to change the grid back to 0.1000mm and you can place it between the headers by eye (you're very unlikely to be able to solder a component within 0.1mm accuracy, so placing things by eye on a board like this is fine.)

![MCU placed][081]

Now move the programming header and place it at the bottom of the board between the screw holes. Again, lining up by eye is fine.

![Programming Header][082]

You can see that the board is getting a little busy with all the layers shown. It's quite often worth turning off some of them at times to get a better view of what's going on. Turn off *ffab*:

![ffab layer][083]

Move the rest of the component footprints into place. This is only a *rough* placing, because we still need to align the outline properly.

![Footprints placed][084]

Now, click and drag to draw a selection box around everything. Right-click and find the *Select* sub-menu (I've noticed that it moves around in the context menu, sometimes it's at the top, sometimes halfway down. I'm sure there's a reason but I've not worked it out yet.). Choose *Filter Selection*.

This little window allows us to specify specific classes of objects to keep selected. We want to move the board outline (and *only* the board outline):

![Filter Selection][085]

(Technically you only need the *Board outlines* option.)s

Now you can move the board outline to properly centre the GPIO headers:

![GPIO Headers Centred][086]

Note that this throws a few other footprints off-centre, so we need to move those - **DON'T** move the GPIO headers independently they are our primary layout constraint because they have to interface with another device (breadboard).

Shuffle the last few components around to make them fit nicely

![Switch moved][087]

You've probably noticed all the little white lines that connect the various footprint *pads* - this is called the *ratsnest* (and can be switched on and off in the toolbar on the left). PCBNew gets the information for these lines from the schematic. We will need to complete all of these connections using *traces* on the board. It's not unusual to have to move components around in order to make these connections easier to make. Laying out traces is probably the hardest part of designing a circuit board.

[080]: screenshots/080-GPIO-footprints.png
[081]: screenshots/081-MCU-placed.png
[082]: screenshots/082-programming-header-placed.png
[083]: screenshots/083-ffab-layer.png
[084]: screenshots/084-footprints-placed.png
[085]: screenshots/085-filter-selection.png
[086]: screenshots/086-outlines-moved.png
[087]: screenshots/087-switch-moved.png
[088]: screenshots/088-first-trace.png
