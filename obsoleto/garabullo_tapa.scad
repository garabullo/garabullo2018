color("orange")union()
{
    difference()
    {
        union()
        {
            base (altura = 4, radio = 5, tope = 20, compensacion = 0);
        }
        union() // aquí los vaciados toditos
            {
                translate([-45,0,19.5])interruptor();
                vaciado_tornillos_tapa();
                vaciado_tornillos_placa();
                hueco_boton();
                translate([31,-31 , 1])cylinder(d = 7, h =5, $fn = 50); // led bateria
                translate([31,0,0])pantalla();
               translate([36,32,0])hueco_reset();
                translate([-60,-60, -10])cube([120,120,10]);// suelo para que el redondeo inferior acabe en ángulo
                translate([10,44,34])rotate([-90,0,0])huecoRueda();
                translate([10,-44,34])rotate([90,0,0])huecoRueda();
            difference()
            {
                union()
                {
                    translate([0,0,1])base (altura = 3.5, radio = 2.5, tope = 50, compensacion = 5); // parte interna
                }
                union() // aquí va lo que no se quiere restar al principio en la resta inicial
                //de cuando se resta lo que se resta al principio si no se quiere restar cuando al principio
                //se hace la resta para el vaciado inicial... del principio, cuando se hace... de la parte contratante
                {
                    tornillos_tapa();
                    taco_interruptor();
                    tornillos_placa();
                    translate([10,44.5,34])rotate([90,0,0])paseRueda(); //ya lo pone... pase de rueda
                    translate([10,-44.5,34])rotate([90,0,0])paseRueda();// y esta tambíen está explicado hombre
                }
            }
        }
    }
    array_botones();
    translate([36,32,0])boton_reset();
    difference()
    {
        union()
        {
            translate([31,-31 , 0.1])cylinder(d = 12, h =7, $fn = 50); // led bateria
        }
        union()
        {
            translate([31,-31 , 0.9])cylinder(d = 4, d2 = 10, h = 7, $fn = 50); // led bateria
            translate([31,-25 , 7])cube([20,6,5], center = true);
        }
    }
}
//modulo de redondeos inferiores
module base(altura, radio, tope, compensacion)
{
    hull()
    {
        translate([45,-42,altura])sphere(r = radio, $fn = 100);// redondeo esquina delantera derecha
        translate([45,42,altura])sphere(r = radio, $fn = 100);// redondeo esquina delantera izquierda  
        translate([-35,32,altura])rotate_extrude($fn = 100)// redondeo esquina trasera izquierda
          translate([10, 0, altura])
            circle(r = radio);
        translate([-35,-32,altura])rotate_extrude($fn = 100)// redondeo esquina trasera derecha
          translate([10, 0, 0])
            circle(r = radio);
        translate([-35, -32,altura])cylinder(r = radio * 3 + compensacion, h = tope - altura, $fn = 100);// cilindro altura trasera derecha
        translate([-35, 32,altura])cylinder(r = radio* 3 + compensacion, h = tope - altura, $fn = 100);// cilindro altura trasera izquierda
        translate([45, -42,altura])cylinder(r = radio, h = tope - altura, $fn = 100);// cilidro altura delantera derecha
        translate([45, 42,altura])cylinder(r = radio, h = tope - altura, $fn = 100);//cilindro altura delantera izquierda
    }
}
module paseRueda()
{
    hull()
    {
        translate([0,0,-5])rotate_extrude($fn = 100)
          translate([28.5, 0, 0])
            circle(r = 3);
        translate([0,0,5])rotate_extrude($fn = 100)
          translate([28.5, 0, 0])
            circle(r = 3);
    }
}
module huecoRueda()
{
    hull()
    {
        translate([0,0,-5])rotate_extrude($fn = 100)
          translate([27.5, 0, 0])
            circle(r = 1);
        translate([0,0,5])rotate_extrude($fn = 100)
          translate([27.5, 0, 0])
           circle(r = 1);
    }
    difference()
    {
        translate([0,0,2.6])cylinder(r = 30, h = 10, $fn = 100);
        translate([0,0,2.4])rotate_extrude($fn = 100)
                  translate([30.5, 0, 0])
                    circle(r = 2);
    }
}
module array_botones()
{
    for (pos_x = [-20, 0, 20])
    {
        for (pos_y = [-20, 0, 20])
        {
            translate([pos_x-18, pos_y, 0])boton();
        }
    }
}
module boton()
    {
        difference()
        {
            union()
            {
                hull()
                {
                translate([0,0,1]) cylinder(d1 = 13,d2=14, h = 5.5,$fn = 100);
                translate([6,0,1])cylinder(r = 2.5, h = 5.5,$fn = 100);
                cylinder(d = 11, h = 2,$fn = 100);
                translate([6,0,0])cylinder(r = 1.5, h = 2,$fn = 100);
                }
                hull() //lengüeta
                {
                translate([-9.1, -2, 1])cube([12,4, 1]);
                translate([-9.1, -1.5, 0])cube([12,3, 0.1]);
                }
            }
            union()
            {
                translate([0,0,1.2])cylinder(d1 = 10, d2 = 12, h = 8, $fn = 100);
                translate([0,-4, 4.5])cube([10, 8,10]);
            }
        }
}
module hueco_boton()
{
    for (pos_x = [-20, 0, 20])
    {
        for (pos_y = [-20, 0, 20])
        {
            
            translate([pos_x-18,pos_y,0])union()
            {
                hull()
                {
                    hull()
                    {
                    translate([6,0,0])cylinder(d = 5.9, h = 0.9,$fn = 100);
                    cylinder(d = 13.9, h = 0.9,$fn = 100);
                    }
                    hull()
                    {
                    translate([6,0,-1.1])cylinder(d = 10, h = 0.1,$fn = 100);
                    translate([0,0,-1.1])cylinder(d = 18, h = 0.1,$fn = 100);
                    }
                }
                hull()
                {
                translate([-9, -2.45, 1])cube([12,4.9, 0.1]);
                translate([-9, -4.5, -1.1])cube([12,9, 0.1]);
                }
                translate([-9,-2.5, -1])cube([12,5, 10]);
                hull()
                {
                translate([6,0,0])cylinder(r = 3, h = 10,$fn = 100, center = true);
                cylinder(r = 7, h = 10,$fn = 100, center = true);
                }
            }
        }
    }
}
module tornillos_tapa()
{
        translate([-25, -42,0])cylinder(r = 5, h =  40, $fn = 100);
        translate([-25, 42,0])cylinder(r = 5, h = 40, $fn = 100);
        translate([45, -42,0])cylinder(r = 5, h =  40, $fn = 100);
        translate([45, 42,0])cylinder(r = 5, h = 40, $fn = 100);
}
module vaciado_tornillos_tapa()
{
       
        translate([-25, -42,2])cylinder(r = 1.4, h =  20, $fn = 100);
        translate([-25, 42,2])cylinder(r = 1.4, h = 20, $fn = 100);
        translate([45, -42,2])cylinder(r = 1.4, h =  20, $fn = 100);
        translate([45, 42,2])cylinder(r = 1.4, h = 20, $fn = 100);
}
module tornillos_placa()
{
        translate([-44, -33,0])cylinder(r = 3, h =  9, $fn = 100);
        translate([-44, 33,0])cylinder(r = 3, h = 9, $fn = 100);
        translate([-8, -10,0])cylinder(r = 3, h =  9, $fn = 100);
        translate([-8, 10,0])cylinder(r = 3, h = 9, $fn = 100);
        translate([44, -33,0])cylinder(r = 3, h =  9, $fn = 100);
        translate([44, 33,0])cylinder(r = 3, h = 9, $fn = 100);
}
module vaciado_tornillos_placa()
{
        translate([-44, -33,1])cylinder(r = 1.4, h =  20, $fn = 100);
        translate([-44, 33,1])cylinder(r = 1.4, h = 20, $fn = 100);
        translate([-8, -10,1])cylinder(r = 1.4, h =  20, $fn = 100);
        translate([-8, 10,1])cylinder(r = 1.4, h = 20, $fn = 100);
        translate([44, -33,1])cylinder(r = 1.4, h =  20, $fn = 100);
        translate([44, 33,1])cylinder(r = 1.4, h = 20, $fn = 100);
}
module pantalla()
{
    cube([27,27,50], center = true);
}
module interruptor()
{
    
    translate([-7,0,0])hull()// loqueslodemeterlaszarpaspancender
    {
        translate([0,-5,2])sphere(d = 10, $fn = 50);
        translate([0,-5,4])sphere(d = 10, $fn = 50);
        translate([0,5,2])sphere(d = 10, $fn = 50);
        translate([0,5,4])sphere(d = 10, $fn = 50);
    }
}
module taco_interruptor()
{
    hull()
    {
    translate([-50,-9,18])cube([7,18,2]);
    translate([-50,-4,13])cube([2,8,2]);
    }
}
module hueco_reset()
{
    hull()
    {
        cylinder(d = 8, h = 0.9,$fn = 100);
        translate([0,0,-1.1])cylinder(d = 12, h = 0.1,$fn = 100);
    }
    hull()
    {
        translate([-8, -2.45, 1])cube([8,4.9, 0.1]);
        translate([-8, -4.5, -1.1])cube([8,9, 0.1]);
    }          
    translate([-8,-2.5, -1])cube([8,5, 10]);
    cylinder(r = 4, h = 10,$fn = 100, center = true);
}
module boton_reset()
{
    hull()
                {
                translate([0,0,1]) cylinder(d1 = 4,d2= 7, h = 1,$fn = 100);
                cylinder(d = 5, h = 4.4,$fn = 100);
                }
                hull() //lengüeta
                {
                translate([-9.1, -2, 1])cube([9,4, 1]);
                translate([-9.1, -1.5, 0])cube([9,3, 0.1]);
                }
}