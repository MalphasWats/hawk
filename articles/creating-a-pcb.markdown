# Creating a PCB

KiCAD is not actually *an* application, it's a collection of applications for designing electronic devices. PCBnew is the program we need to use to lay out the PCB. Open it up from the main KiCAD project window and you'll be presented with a blank PCB design:

![New PCB][065]

The first step is to import the *Netlist* we exported from our schematic. This will give us all of the footprints that we need to set out, as well as how they all connect together.

From the *Tools* menu choose *Load Netlist...*. PCBnew should automatically populate the *Netlist file* field, but just check it is pointing to the correct file that was exported in the previous step:

![Read netlist][066]

Click the *Read Current Netlist* button and PCBnew will read it in. You'll see the results from what it found in the little text area. Once the netlist has been read, click the *Close* button. You'll notice that you now have a bunch of yellow, red and blue things stuck to your mouse.

![Place footprints][067]

Click somewhere on the blank PCB to place the *footprints*. These are all of the footprints that we defined in our schematic:

![Footprints placed][068]

All of these footprints will need to be moved and connected with copper traces, but before we do that, we want to define a board outline. We can do this really simply, but I'm only going to explain that briefly here. I want to create the shape of the board using a different program.

You can safely skip that though and draw the PCB *Edge* using the tools in PCBnew. On the very right-hand side of the program window are a list of layers. These layers define all the different parts of  PCB. The shape of the PCB itself is defined by the *Edge.Cuts* layer.

Select the *Edge.Cuts* layer by clicking on it.

Next choose the *Line* option from the *Place* menu - this tool allows you to draw simple graphic lines. Click on an empty space in the PCB to start drawing a line, each subsequent click creates a line and also starts a new line. You can use this tool to draw out the shape of your PCB. Once you've joined the lines to create a complete shape, press the *Escape* key to exit drawing mode.

I'm pretty sure this is how the *vast majority* of people design the shape of their boards, however, I don't do it that way and want to talk a little about how *I* do it in the next part.

[065]: screenshots/065-new-pcb.png
[066]: screenshots/066-read-netlist.png
[067]: screenshots/067-netlist-read.png
[068]: screenshots/068-footprints-placed.png
