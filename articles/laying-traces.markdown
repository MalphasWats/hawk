# Laying Traces

Alright, so this is it, this is the Main Event. Laying the traces. On a board like we're making here it's not going to be *too* challenging, but there are some things we did wrong earlier that are going to bite us now (I did it on purpose!).

We'll start with the reset trace - we need to connect the reset pin on the MCU to the reset pad of the programming header. Start by pressing the *x* key. This is the shortcut for the trace tool. There's a button on the toolbar between the main pane and the layers list, but trust me, forget about it and use the keyboard shortcut.

Make sure the little blue triangle is showing that the *F.cu* layer is the currently active layer in the list on the right.

Click on the *reset* pad of the Microcontroller footprint. This starts one end of a *trace*. It also lights up all of the footprints that need to be connected:

![First Trace][088]

Your mouse now has a line attached. Move over to the *reset* pad on the programming header and click. KiCAD will try and route the trace as best it can. It's usually pretty good at it.

![Trace placed][089]

Nice, now we can do the two programming pins *SWDIO* and *SWCLK*. KiCAD should still be in trace mode, so simply clicking the appropriate pads will place the traces.

![Programming Traces][090]

Alright, now let's take a look at the GPIO pins and headers:

![Ratsnest][091]

In the previous section I mentioned the white lines connecting pads - the Ratsnest. You can see here that the lines are going from one side of the MCU across to the other. It *could* be that this is just how things are and you'd have to find a way to route the traces - have a go at connecting all 8 GPIO pins up and you'll probably get stuck because they have to cross. Because of the nature of our board, it doesn't really matter which header pins connect to which GPIO pins on the MCU, so we can make our lives much easier by rearranging the schematic.

![Update Schematic][092]

Switch back to the schematic editor and rearrange the labels to better match the orientation - this can take a bit of back and forth between the schematic and the PCB.

![Updated Schematic][096]

Regenerate the netlist:

![regen netlist][093]

and re-read it into the PCB editor

![Re-read netlist][094]

Now, here you can see that the ratsnest has updated and shows much easier to route connections:

![Updated ratsnest][097]

HOWEVER, I've had a few issues with this (it's probably related to doing the thing with netlists that you don't really need to do any more!).

Notice here that I've *actually* clicked on Pin 5 for *GPIO_4* but *GPIO_5* has been highlighted? I'm pretty sure this is a bug in KiCAD - remember previously the pad we clicked *was* GPIO_6.

![Wrong netlist][098]

It's not too much of an issue here because it stands out, but it can cause problems where the change is subtle. The only way I've found to fix it is to close PCBNew and re-open it. Eyeroll emoji.

Now we can route the GPIO pins

![GPIO start routing][099]

![GPIOs Routed][100]

Next route the battery positive terminal across to the bypass capacitor *C2* and then on to the regulator IC. We can also connect the current limiting resistor *R2* to the LED.

![Battery routed][101]

And now [draw the rest of the owl](https://knowyourmeme.com/memes/how-to-draw-an-owl).

![3v Routed][102]

Notice how we aren't routing any *GND* pads? We'll come back to that later.

Lastly, the reset button needs to connect all the way down to the reset pin on the MCU. Notice also that we can't really get directly to the pin because of all of the other traces? That's just a small taster of routing more complex boards.

Connect it right the way down to the pad on the programming header instead. It's still making an electrical connection with the reset pin. It's usually not a problem to connect things like this, but if you're working with very high-speed digital signals you need to be a little more careful - you'd want to lay your footprints out to take these contraints into account *first* and then connect everything else. The *reset* line is very much not a high-speed digital connection, so it gets routed last!

![Reset routed][103]

That's it. Our PCB is now nearly fully connected. We'll look at the *GND* connections in the next part.

[088]: screenshots/088-first-trace.png
[089]: screenshots/089-trace-placed.png
[090]: screenshots/090-programming-traces.png
[091]: screenshots/091-ratsnest.png
[092]: screenshots/092-schematic.png
[093]: screenshots/093-regenerate-netlist.png
[094]: screenshots/094-re-read-netlist.png
[095]: screenshots/095-ratsnest-updated.png
[096]: screenshots/096-GPIO-labels-updated.png
[097]: screenshots/097-clean-ratsnest.png
[098]: screenshots/098-ratsnest-wrong.png
[099]: screenshots/099-GPIO-trace.png
[100]: screenshots/100-GPIOs-routed.png
[101]: screenshots/101-batt-routed.png
[102]: screenshots/102-3v-routed.png
[103]: screenshots/103-reset-routed.png
