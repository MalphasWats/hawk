# Silkscreen & Finishing Touches

This section of the guide is probably the worst part, so my apologies for that. I haven't really found a style for how I like my silkscreen to be and since it mostly doesn't affect the overall functionality of the board and I'm mostly learning how to make the things work, I tend not to put as much effort in as I should. It is part of my plan to re-visit this project and improve various aspects as part of another tutorial.

So, Silkscreen. The silkscreen on a PCB are the (usually) white characters and symbols printed that help whoever is assembling/using the board.

The first thing we'll do is switch off the *F.cu* layer so we can better see the silkscreen layer, we also have the *F.Fab* layer disabled from a previous part.

![Disable Layers][112]

Now we just hover over the silkscreen text we want to move, press *m* to move and *r* to rotate. Let's move the *J3* text:

![Move J3][113]

Repeat this and place all of the silkscreen text so that it clearly identifies each footprint.

![Tidy Silkscreen][114]

You can also add free text using the text tool on the middle toolbar.

Lastly, we'll add some holes and align them with our screwhole marks. Choose *Place > Footprint* from the menu or press *o*. Click anywhere on the board to bring up the Footprint Browser - this may take a while to load.

![Add Footprint][115]

Find the 2mm Plated Test Point footprint, double-click it to add it to the board. Using the green *Eco1.User* layer, align the inner black hole with the green rings:

![Align footprint][116]

These footprints aren't associated with any nets, and they don't appear in the schematic. That's why they have REF above them, and this will appear in the silkscreen. To remove it, hover over the text and press *e*, then change the layer from *F.SilkS* to *F.Fab*.

![Hide Refs][118]

Use *ctrl-d* to duplicate this 3 more times and place them on the remaining holes.

![Duplicate screwholes][117]

Don't forget to update the ground fill by pressing the *b* key, and re-run DRC to make sure nothing is overlapping.

And that's it! We have successfully created our own PCB! The only thing left is to send the files off to a fab to have it manufactured!

![Completed Board][119]

[112]: screenshots/112-switch-off-layers.png
[113]: screenshots/113-move-J3.png
[114]: screenshots/114-tidy-silkscreen.png
[115]: screenshots/115-add-screwhole.png
[116]: screenshots/116-align-screwhole.png
[117]: screenshots/117-duplicate-screwholes.png
[118]: screenshots/118-hide-refs.png
[119]: screenshots/119-completed-board.png
[120]: screenshots/120-check-DRC.png
