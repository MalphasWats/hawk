# Assembly

This section is short because I have no intention of writing a soldering tutorial! I am terrible at soldering but I've managed to make some fairly complex stuff just by having a go - SMD terrified me because I didn't want to waste a load of time and money messing up. In the end I treated myself to a cheap hot air rework station and had a go and it turned out to be a lot simpler than I expected. I'm still bad at it though.

I'm not going to assemble a whole board - just enough to get something I can play with.

![Parts][01]

Here you can see the glorious board we have been designing. I don't actually recommend that you make one of these - there are quite a few issues with it that I want to try and address in a future tutorial - but it does work and will serve my purpose of learning to program for SAMD chips.

Next I carefully splooged out some solder paste on the pads that I want to solder components to:

![Paste][02]

When I first started thinking about Surface Mount soldering, I thought you had to be REALLY careful with how you applied the paste. I deliberately didn't bother making stencils for this board because I wanted to show that it's perfectly possible to assemble SMD boards without one.

You can see that I've made a bit of a mess up by the linear regulator IC, which is ok, I'm not planning to populate that part of the circuit.

Next I placed each component carefully - the 2 that *really* matter are the LED and the MCU - you have to make sure you orient them correctly. The MCU has a little dent in the plastic casing next to Pin 1, which goes at the top on our board. The LED will have a little symbol on the bottom which shows which way around it goes.

![Placed][03]

Once all of the parts were in place, I shot hot air at it until the solder melted, everything stopped sliding around and the solder looked nice and shiny.

**Then I walked away and left it**.

Don't try moving it, it will take a while for the solder to cool and re-solidify and any movement during this time will knock components off their pads. Also the board itself is **HOT**.

You might also notice that I stuck the board to my desk with some double sided tape. I thought this was a really clever idea that would help me to place things without everything sliding all over the place. It turned out to be a **REALLY BAD IDEA**. The heat from the hot air gun made the adhesive on the tap melt and stick to everything that I didn't want it to - I still have a sticky patch on my desk. It took a lot of effort to get it off the bottom of the board. I have since bought a nice little clamp harness thing.

Once it had cooled, I soldered some header pins to the programming header with a regular soldering iron.

Here it is with the [Blink example code loaded](https://github.com/MalphasWats/hawk/blob/master/blink/blink.c)

![Programmed][04]

[01]: photos/01-parts-knolled.jpeg
[02]: photos/02-paste.jpeg
[03]: photos/03-components-placed.jpeg
[04]: photos/04-blink.jpeg
