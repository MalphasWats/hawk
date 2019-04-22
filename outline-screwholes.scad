difference()
{

    minkowski()
    {
        square([14, 30], center=true);
        circle(r=2, $fn=30);
    }
    
    translate([7, 15]) circle(d=2.01, $fn=30);
    translate([-7, 15]) circle(d=2.01, $fn=30);
    translate([7, -15]) circle(d=2.01, $fn=30);
    translate([-7, -15]) circle(d=2.01, $fn=30);
}