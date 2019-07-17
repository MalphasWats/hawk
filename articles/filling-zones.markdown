# Fill Zones

The last thing we need to do is to connect up all of the *GND* pads together. We *could* simply connect them all up using traces in the same way we did with all of the other pads. Indeed, this is how you *should* do it sometimes where you're being really careful to keep your digital signals clean and you really know what you're doing.

We don't really know what we're doing so we'll use a *filled zone*, sometimes referred to as a *copper pour*. This is a large *continuous* area of copper on the board that can be used to connect a common *net* together across the board.

Making sure the *F.cu* layer is selected, click the *Add filled zones* button in the tool bar that sits between the main pane and the layers list, then click somewhere in the main pain but *outside* of the board outline. This will bring up the zone fill options:

![Zone Fill][105]

The default settings are actually not wonderfully helpful. It took me quite a few boards to work this out. First off, select the *GND* net from the list of nets in the middle - you'll see that there's an entry for all of the various connections on our board. It usually doesn't make a lot of sense to use the others for zone fills, although sometimes it can be useful.

Now, let's check our PCB fab capabilities:

![pcb capabilities][104]

Now obviously different fabs will have different capabilities. We can see here that this one has a Minimum Width and Minimum Spacing of 3.5mil (a mil is apparently 1 one-thousandth of an inch, Metric Imperial. Eyroll Emoji.). 3.5mil is approximately 0.089mm. Changing the *Clearance* and *Minimum Width* settings to match these means that our filled zone will be able to sneak through smaller gaps and make it more likely  that everything will connect properly. You can see above that I have set them to 0.1mm just because I didn't want/need to push things right to the limit.

Click OK and you then need to complete drawing the zone. Draw a rectangle around the outside of the board outline. Clicking back on the starting point completes the zone, or Double-clicking will automatically join in a straight line from where your mouse is back to the starting point.

![Ground zone][106]

You can see that the empty space inside the board outline is now filled in red, and all of the *GND* pads should be connected to the zone.

Be careful using zones in this way. It is possible (and very common) for KiCAD not to be able to route around some traces or footprints and you can end up with *multiple, separate zones* which aren't electrically connected - for example, if the reset trace was routed too close to the edge of the board, there wouldn't be enough space for the ground zone to fill around it and the top and bottom zones *could* have been left unconnected.

Let's check everything is connected. In the top toolbar there's button with a little beetle on it, click this to bring up the Design Rules Check (DRC) window

Click the *Start DRC button*. KiCAD will check to make sure everything is connected properly and nothing is overlapping or broken.

![DRC][107]

DRC has found a problem with our board. It has noticed that the *1* pins of the switch aren't connected. This isn't *actually* a problem. The little 4-pin tactile push buttons we're using actually have those pins connected internally, but KiCAD doesn't know this and really, it's probably good practice not to rely on it when it comes to components like this. We can add a trace between the 2 pins:

![Reset pins connected][108]

If you do make this fix, you *MUST* re-fill the ground zone by pressing *b* on the keyboard. If you don't do this, the button would be shorted to ground.

Get into the habit of re-running DRC again after making changes like this. Helpfully, if you try to run DRC without re-filling any zones, it'll remind you and ask if you want to:

![Refill zones][109]

![DRC OK][110]

And here's our electrically complete board:

![DRC OK][111]

[105]: screenshots/105-ground-zone.png
[106]: screenshots/106-ground-zone-filled.png
[107]: screenshots/107-DRC.png
[108]: screenshots/108-connect-button.png
[109]: screenshots/109-refill-zones.png
[110]: screenshots/110-DRC-OK.png
[111]: screenshots/111-board-complete.png
