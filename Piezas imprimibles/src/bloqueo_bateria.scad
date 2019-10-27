// bloqueo de batería de garabullo2

mirror([0,0,1])difference()
{
    union()
    {
        hull()
        {
            translate([-15,2.5,18])cylinder(d1 = 3,d2 = 5, h = 1, $fn = 50);
            translate([-15,-2.5,18])cylinder(d1 = 3,d2 = 5, h = 1, $fn = 50);
            translate([-15,2.5,22])cylinder(d1 = 5,d2 = 3, h = 1, $fn = 50);
            translate([-15,-2.5,22])cylinder(d1 = 5,d2 = 3, h = 1, $fn = 50);
            translate([4,0,18])cylinder(d1 = 8,d2 = 10, h = 1, $fn = 50);
            translate([4,0,22])cylinder(d1 = 10,d2 = 8, h = 1, $fn = 50);
        }
        hull()
        {
            translate([4,0,18])cylinder(d = 10, h = 1, $fn = 50);
            translate([4,0,15])cylinder(d1 = 8, d2 = 10, h = 1, $fn = 50);
        }
    }
    union()
    {
        translate([-9,0,11])rotate([90,0,0])cylinder(d = 18.2, h = 8, $fn = 50, center = true); //bateria
        translate([-9,4,11])rotate([-90,0,0])cylinder(d1 = 18.2,d2 = 20, h = 3, $fn = 50, center = true); //chaflan bateria
        translate([-9,-4,11])rotate([90,0,0])cylinder(d1 = 18.2,d2 = 20, h = 3, $fn = 50, center = true); //chaflan bateria
        translate([4,0,0])cylinder(d = 3.5, h = 30, $fn = 50);
        translate([4,0,22])cylinder(d1 = 3.4,d2 = 5, h = 1.1, $fn = 50);
        translate([4,0,14.9])cylinder(d1 = 5, d2 = 3.4, h = 1, $fn = 50);
        
    }
}


            