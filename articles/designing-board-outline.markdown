# Desiging a Board Outline

This part explores how to create a board outline using [OpenSCAD](https://www.openscad.org/), however, it's not going to be a tutorial on how to use OpenSCAD, there are loads of those and they do a much better job than I can. You don't *need* to do it this way at all, and in fact, on the face of it, it doesn't really bring any benefit to what we're doing in this short KiCAD tutorial. However, I've found it to be incredibly useful when I'm designing a board that I want to also design a laser-cut or 3d-printed case for later. As ever, I'm *sure* there are other ways to do this, there might even be *better* ways to do it, but I like this one.

Open up a new SCAD project:

![OpenSCAD][069]

Let's start off with a *square* - openSCAD can be used to design both 2D and 3D objects, and in our case we want to defind a 2D cut in the PCB material.

We're making a small board, so lets draw our 'square' (I don't know why they called the function *square* and not *rectangle*) 16mm wide by 32mm long. Press the F5 key to quick-render it:

![a square][070]

Next let's give it rounded corners. The minkowski function takes a shape and applies it all around the edge of another shape. This has the effect of making the original shape bigger by the size of the added shape. To apply a rounded corner with a radius of 2mm to our board shape, we need to minkowski it with a circle with radius of 2mm. If we want to keep our board the same width and height, we also need to decrease these values by 2:

![rounded corners][071]

That's it! Everything we've done here is entirely achievable (and arguably easier) in PCBnew itself, however, that's mostly because our board shape is very simple and small.

We need to export this drawing as a *.dxf* file, but first we need to render it. Press *F6* to render the shape, then choose *Export > Export as dxf...* from the *File* menu and save the .dxf file in the project folder.

Next, switch back to PCBnew and choose *Import > DXF File...* from the *File* menu. Select the file you just saved, then make sure *Edge.Cuts* is selected from the *Graphic Layer* dropdown and click *OK*.

![Import DXF][072]

The shape we just drew will now be attached to your mouse. Click somewhere on the PCB to place it:

![Place outline][073]

All of the footprints we imported earlier will need to be placed *inside* this shape.

Let's extend our board design slightly and add some screw holes. Switch back to OpenSCAD. We can use the *difference()* function to subtract one shape from another. Let's place a 2mm screw hole:

![Screw hole][074]

Now let's *translate* that hole into a corner:

![Screw hole placed][075]

finally, duplicate the hole and put one in each corner:

![4 holes][076]

**re-render the shape by pressing *F6*** and then export it as a .dxf file again. OpenSCAD works a little counter-intuitively when it comes to rendering and will export whatever the last *F6* rendered shape is.

Switch back to PCBnew and import the .dxf file, but *this* time, place it on the *Eco1.User* layer - this layer is useful for comments and notes and anything that won't make it onto the final board - adding the screw hole outline here gives us guides to add the *actual* holes later:

![Import .dxf][077]

Once you import the .dxf file, the outline will be attached to your mouse. Here's where we need to take a little more care: we want the main outline of the 'new' shape to line up with the original shape on the *Edge.Cuts* layer. To do this, you will probably need to change the *Grid Size* from the drop down at the top. In this case, I've chosen the smallest (built-in) grid size of *0.01mm*. In reality, I'm not sure many fabs are actually that accurate, but we should try our best anyway.

![Line up layers][078]

If you've placed it correctly, the outside outlines should line up perfectly and there should be 4 green circles in each corner showing where the holes can go:

![screw holes placed][079]

Again - all of this could be done happily in PCB new, *however* the .dxf file we just produced *could* be fed into a laser cutter and it could spit out a little case with perfectly aligned screw holes. It *is* also possible to export .dxf files from PCBnew too, but by using OpenSCAD we have options to create 3D models for cases and other attachments to the PCB and keep everything lined up. For a simple project like this one, designing the board shape in OpenSCAD is huge overkill, but it's a useful thing to know about and it makes my little write up here a little more unique.

[069]: screenshots/069-new-openscad.png
[070]: screenshots/070-a-square.png
[071]: screenshots/071-rounded-corners.png
[072]: screenshots/072-import-dxf.png
[073]: screenshots/073-outline-imported.png
[074]: screenshots/074-screwhole.png
[075]: screenshots/075-screwhole-placed.png
[076]: screenshots/076-4-screwholes.png
[077]: screenshots/077-import-screwholes.png
[078]: screenshots/078-screwholes-nearly-placed.png
[079]: screenshots/079-screwholes-placed.png
