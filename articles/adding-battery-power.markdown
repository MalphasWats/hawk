# Adding Battery Power

In this part we're going to add battery power to the board. Most modern MCUs can take a pretty wide range of input voltage to power them. According to the [SAMD10 Datasheet](http://ww1.microchip.com/downloads/en/devicedoc/atmel-42242-sam-d10_datasheet.pdf), ours is happy between 1.63V and 3.63V. This means if we want to power our board with a LiPo cell, we need to regulate the voltage down since a fully charged LiPo cell will typically have a voltage of 4.2V which is too high for our controller.

To start with, find a 'fresh' area of the schematic page:

![Blank part of schematic][039]

Press *A* to add a symbol and add a 1x2 generic connector. This will be for our battery.

![Battery Connector][040]

Place the symbol and hover over the symbol name *Conn_01x02* and press *E* to edit and rename it:

![Rename connector][041]

Alright, next we want to add a *Linear Regulator* symbol. There are lots of different types. I'm using [these AP7333 regulators](https://uk.rs-online.com/web/p/products/7513106/) which *don't* have a symbol in the library. **However**, do not despair - there are others in the library with the same pins. Lets check the [datasheet for the regulator](https://docs-emea.rs-online.com/webdocs/104a/0900766b8104adfd.pdf):

![Regulator datasheet][044]

This particular one comes in 2 flavours, *SOT23* and *SOT23R*. I have quite a lot of both from a previous project where I bought the wrong ones because I'd used the wrong symbol! We're going to use the *SOT23* package one, so we need to find a symbol that has the *IN*, *OUT* and *GND* pins numbered the same way.

The symbol browser has a *Regulator_Linear* category so what I did was click the first one in the list and then keep pressing the *down arrow* on my keyboard until I found a symbol with the pins laid out the same way as in the datasheet:

![Linear regulator][042]

Place the symbol and then edit the name field to match the part that we're using. There's no magic inside any of these symbols; as long as the pins match up to the device we can use the symbol.

![Place regulator][043]

More often than not these kinds of Integrated Circuit devices need some extra components to make them work properly and this Linear Regulator is no different. Luckily it's pretty simple and helpfully documented in the datasheet:

![Typical Circuit][045]

What this is essentially saying is that we need bypass capacitors on both the voltage input and voltage output. that's easy enough. Press *A* and add 2 capacitor symbols to the schematic:

![Place Capacitors][046]

Next press *P* and place 3 *GND* symbols, then use *W* to wire the circuit:

![Wire circuit][047]

Our regulator will take any voltage up to 6V and regulate it down to 3.3V (it will keep working down to 1V too, but it won't bring the voltage *UP*). This works great for LiPo cells, although some additional protection would ideally be needed to ensure the cell voltage doesn't drop too low as this can damage the cell (I'm not covering this in this guide though.)

To connect the 3.3V output to our board, we can simply connect it to the +3V3 power net. Press *P* to add a power symbol and add a +3V3 symbol and connect it to the top of the output pin:

![Place 3v3][048]

This is a good point to annotate our symbols and **save the schematic**

![Annotate Schematic][049]

The next step is also a little involved and requires us to think about *Footprints*. A symbol footprint describes how a symbol will appear on a PCB. It describes whether it's a surface mount component or through-hole, how many *pads* it has and where they go. The generic connector we used for the battery doesn't have any footprint associated with it - we have to choose one.

Let's say we want to add a [standard JST battery connector](https://uk.rs-online.com/web/p/pcb-headers/8201422/). This connector has a slot to ensure that the battery is connected the right way around but we don't really know which pin is positive and which is negative.

Here's a picture of the battery-end of the connector (male):

![JST Connector](screenshots/050-jst-connector.jpg)

Tab at the top of the connector fits in to the slot on the PCB connector (female).

We can use the orientation of the red and black wires to help work out which pins are which on our generic connector, but we need to match the connector with a footprint first. Let's do that.

Hover your mouse over the battery connector symbol and press *E* to bring up the *Symbol Properties*:

![Symbol Properties][050]

One of the fields listed is for *Footprint* and it's currently blank. Click the *Browse Footprints* button to bring up the footprint browser. It might take a little while for the browser to load all of the footprints in, particularly the first time you open it. Be patient:

![Footprint browser][051]

The footprints are organised into categories, although these categories don't really match up with the symbol categories. There are so many different types of JST connector that they have their own category! Find that and then find the 1x2 2.00mm vertical option. Notice the drawing on the right shows us that the slot is pointing up and that pin 1 is on the left and pin 2 is on the right. Based on the picture of the LiPo battery above, we can see that Pin 1 is positive and 2 is ground.

**Caveat: I was able to find pictures of batteries connected both ways. A while back I plugged one of my LiPo batteries into a featherwing board I had and it went pop and let out the magic smoke. It appears that the wiring of 3.7v LiPo batteries is not standard and batteries bought from different places might be wired differently.**

I don't usually use connectors for my batteries - I tend to place flat pads and solder bare wires to the board. It's probably not the best way to do things but at least it avoids this issue. I'm not sure what the best solution here is. If you connect a battery with the wrong polarity to the linear regulator it goes pop and lets out the magic smoke. If you're lucky it does that faster than the MCU does. Still not an easy 'fuse' to have to replace (remember how I mentioned above that I have *both* the SOT23 and SOT23R versions of this regulator? Yeah...).

These are the stressful bits of designing your own boards. Let's press on...

Press *P* and add a +BATT power symbol the the schematic - connect it to *pin 1* of the battery connector.

Duplicate it and connect it to *pin 1* of the linear regulator too.

![Battery net][052]

Duplicate a *GND* symbol from somewhere and connect it to *pin 2*:

![Battery wired][053]

And that's it, our circuit is complete!

![Completed Circuit][054]

## Caveats

The whole battery wiring issue bothers me, and actually I wonder if you're better off *not* using connector with enforced orientation and simple marking on the board silkscreen (we'll get to that later) the polarity and simply solder in 2.00mm header pins. It's interesting that it only occurred to me when I wrote this that that might have been the reason for my featherwing board going pop!

It's worth considering adding a power switch to the mix - this could be added between the +BATT symbol and the connector pin. In my experience so far, finding nice power switches is actually harder than you think. ( [Here's a nice one](https://uk.rs-online.com/web/p/products/1238939/) )

As mentioned above, there's no protection against the battery over-discharging, although *most* LiPo cells do have that built in, it's probably not a good idea to rely on that.

You could also add a charging circuit that charges via USB, but to do that you've have to add a USB connector of some kind and I've avoided that for now because I kind of feel like if it's got a USB port on it, people expect it to be programmable via USB and that isn't something I feel like trying to do with this particular chip (I suppose it is *possible* via USART, but it's never going to be easy!)



[039]: screenshots/039-new-area-of-schematic.png
[040]: screenshots/040-battery-connector.png
[041]: screenshots/041-battery-connector-named.png
[042]: screenshots/042-linear-regulator-symbol.png
[043]: screenshots/043-regulator-placed.png
[044]: screenshots/044-datasheet-pinout.png
[045]: screenshots/045-datasheet-circuit.png
[046]: screenshots/046-capacitors-placed.png
[047]: screenshots/047-circuit-wired.png
[048]: screenshots/048-power-net-added.png
[049]: screenshots/049-symbols-annotated.png
[050]: screenshots/050-editing-symbol-properties.png
[051]: screenshots/051-choosing-footprint.png
[052]: screenshots/052-adding-battery-net.png
[053]: screenshots/053-battery-wired.png
[054]: screenshots/054-completed-circuit.png
