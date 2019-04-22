# Manufacturing the PCB

Now that we have a completed board, it's time to send it off for manufacture.

![Completed Board][119]

I use [JLCPCB](https://jlcpcb.com) for all of my projects at the moment. JLCPCB have offered to pay for this little project board to be produced and asked me to write a little bit about how I've found their service.

This is my 13th board with them and I've been really happy with the quality - one board had a small issue with the solder mask covering some pads and they fixed it and sent me replacements with no issues. I do this stuff as a hobby so it's definitely a bonus that the service is affordable.

First step is just to make a final DRC check to make sure everything checks out:

![DRC][120]

The JLCPCB service requires that you upload Gerber files which KiCAD can produce. Click *File > Plot...* to bring up the plot pane:

![Plot][121]

Make sure to choose a folder for the files to be generated into at the top. By default KiCAD selects the right set of layers and other settings, so just click *Plot* at the bottom to generate the Gerber files.

As well as Gerber files, JLCPCB need Drill files. Click the *Generate Drill Files...* button to bring up the Drill Files pane:

![Drills][122]

Choose *Millimeters* under the *Drill Units* heading, make sure that the output directory is the same as for the Gerber files and press the *Generate Drill File*.

The Gerber files need to be uploaded as a zip file. The *Plot* output folder can be zipped up:

![Zip][123]

Next load up the [JLCPCB website](https://jlcpcb.com) and click the *Quote Now* button:

![JCLPCB][124]

Click on *Add your gerber file* and choose the zip file containing the Gerber files. They will be uploaded and scanned and a nice little picture of what the board will look like will be generated:

![Gerbers Uploaded][125]

Scroll down to the options for your board:

![Board options][126]

Here you can choose things like board thickness, solder mask colour (which is now a free option!) and the pad surface finish. The rest of the settings here can be safely ignored until you need them.

Once you're happy with your options click *Save to cart*.

![Save to cart][127]

You'll be asked to create an account and pay, once you've done that, you can track your order's progress. Depending on which delivery option you choose, your order will arrive 1-3 weeks later neatly boxed and ready for assembly!

[119]: screenshots/119-completed-board.png
[120]: screenshots/120-check-DRC.png
[121]: screenshots/121-plot.png
[122]: screenshots/122-drills.png
[123]: screenshots/123-zip.png
[124]: screenshots/124-jlcpcb.png
[125]: screenshots/125-gerbers-uploaded.png
[126]: screenshots/126-board-options.png
[127]: screenshots/127-added-to-cart.png
[128]: screenshots/128-order-details.png
