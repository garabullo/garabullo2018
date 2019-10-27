

color("lightblue")difference()
{
    union()
    {
        base (altura = 3, radio = 5, tope = 18, compensacion = 0);
        difference()
{
    union()
    {
            translate([10,43,23-18.5])rotate([-90,0,0])huecoRueda();
            translate([10,-43,23-18.5])rotate([90,0,0])huecoRueda();
    }
    union()
    {
        translate([0,0,-20])cube([100,100,60],center = true);
    }
}
    }
    union() // aquí los vaciados toditos
        {
            translate([45,-4, 10])cube([10,8,4.5]);//usb arduino
            translate([-45,0,31.5-19])interruptor();
            vaciado_tornillos_placa();
            //translate([10,0,23])rebaje_motores(); // hueco del alojamiento de las pestañas de los tornillos de los motores
            rotate([0,0,90])translate([3,-10,0])translate([-49,0,9])cargador();       
            difference()
            {
                union()
                {
                //translate([10,0,23])hueco_motores(); // ¿te lo tengo que explicar?
                }
                union()
                {
                //translate([0,-17,0])cube([150,34,50]);//hueco central para meter cositas entre motores
                //translate([15,-18,0])cube([10,36,1.6]);//parte central del suelo entre motores
                }
            }
            translate([-60,-60, -10])cube([120,120,10]);// suelo para que el redondeo inferior acabe en ángulo
            
            //translate([-8,37.01,-1])cube([36,10,55]);//cubo chaflán pase rueda
            //translate([-8,-47.01,-1])cube([36,10,55]);//cubo chaflán pase rueda
            //translate([-38,35,-1])cylinder(d = 17, h = 16, $fn = 100);// huecos bolas
            //translate([-38,-35,-1])cylinder(d = 17, h = 16, $fn = 100);//huecos bolas
            //translate([-38,35,15.2])cylinder(d = 2.8, h = 26, $fn = 100);// tornillos bolas
            //translate([-38,-35,15.2])cylinder(d = 2.8, h = 26, $fn = 100);//tornillos bolas
        difference()
        {
            union();
            {
                translate([0,0,1])base (altura = 3, radio = 2.5, tope = 50, compensacion = 5); // parte interna
            }
            union() // aquí va lo que no se quiere restar al principio en la resta inicial
            //de cuando se resta lo que se resta al principio si no se quiere restar cuando al principio
            //se hace la resta para el vaciado inicial... del principio, cuando se hace.
            {
                tornillos_placa();
                //soporte_bolas();// lo "ques palojar" las bolas
                translate([-19,0,0])bateria();
                translate([0,0,-19])soporte_interruptor();
                translate([10,33,0])step_up();
                //translate([10,0,23])tacos_tornillos_motores();
                rotate([0,0,-90])translate([67,10,0])alojamiento_cargador();
            }
        }
    }
}



module alojamiento_cargador()
{
    union()
                    {
                    translate([-50,-11.5,0])cube([31,23,10]); // soporte para el cargador
                    hull()
                    {
                    translate([-35,-15,0])cylinder(d = 10, h = 10, $fn = 50);
                    translate([-35,15,0])cylinder(d = 10, h = 10, $fn = 50);
                    }
                }
}
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
        translate([0,0,2.5])rotate_extrude($fn = 100)
          translate([26.5, 0, 0])
            circle(r = 1);
        translate([0,0,3])rotate_extrude($fn = 100)
          translate([26.5, 0, 0])
            circle(r = 1);
    }
}

module soporte_bolas()
{
    hull()
    {
        translate([-38,35,0])cylinder(d = 21, h = 26, $fn = 100);
        translate([-49,35,0])cylinder(d = 21, h = 26, $fn = 100);
        translate([-38,46,0])cylinder(d = 21, h = 26, $fn = 100);
    }
    hull()
    {
        translate([-38,-35,0])cylinder(d = 21, h = 26, $fn = 100);
        translate([-49,-35,0])cylinder(d = 21, h = 26, $fn = 100);
        translate([-38,-46,0])cylinder(d = 21, h = 26, $fn = 100);
    }
}
module hueco_motores()
{
    rotate([0,-45,0])union()
    {
        translate([0,0,-8])rotate([90,0,0])cylinder(d = 28.6, h = 100, $fn = 100, center = true);
        translate([-35/2,0,-8])rotate([90,0,0])cylinder(d = 2.8, h = 100, $fn = 20, center = true);
        translate([35/2,0,-8])rotate([90,0,0])cylinder(d = 2.8, h = 100, $fn = 20, center = true);
        translate([-3.5, -50,-26.5])cube([7,100,17.3]);
        translate([-7.7, -50,-25.4])cube([15.4,100,17.3]);
        hull()
        {
        translate([-17.5/2, -50,-21.3])cube([17.5,100,17.3]);
        translate([-7.5, -50,-22.4])cube([15,100,17.3]);
        }
    }
    hull()
    {
    rotate([0,-45,0])  translate([0,0,-8])rotate([90,0,0])cylinder(d = 28.6, h = 100, $fn = 100, center = true);
    translate([0,-50,6])cube([11,100,3]);
    }
}
module tacos_tornillos_motores()
{
    difference()
    {
        union()
        {
            hull()
            {
               rotate([0,-45,0]) translate([-35/2,0,-8])rotate([90,0,0])cylinder(d = 8, h = 72, $fn = 40, center = true);
               translate([-10.7,-36,-23])cube([8,72,2]);
            }
               rotate([0,-45,0]) translate([35/2,0,-8])rotate([90,0,0])cylinder(d = 8, h = 72, $fn = 40, center = true);
               difference()
            {
                union()
                {
               rotate([0,-45,0]) translate([0,0,-8])rotate([90,0,0])cylinder(d = 43, h = 72, $fn = 100, center = true);
                }
                union()
                {
                    rotate([0,-45,0]) translate([-25,-50,-8])cube([50,100,50]);
                    translate([-25,-50,-58])cube([60,100,50]);
                }
            }
        }
        union()
        {
            cube([70,48,50],center = true);
            hull()
    {
    translate([20,0,-8])cube([40,70,1],center = true);
    translate([20,0,3])cube([40,48,1],center = true);
    }
        }
    }
}
module cargador()
{
    hull()
    {
        translate([0,-18/2,0])cube([27.5,18,1.5]);//placa
        translate([4,-18/2,0])cube([24.5,18,5]);//placa
    }
    translate([3,-7.5,-1.5])cube([21.2,16,2]);
    translate([0,-4,-2.5])cube([10,8,3]);//usb
    hull()
    {
    translate([-2,-3,-1.5])rotate([0,90,0])cylinder(d = 2.2, h = 10,$fn = 20);
    translate([-2,3,-1.5])rotate([0,90,0])cylinder(d = 2.2, h = 10,$fn = 20);
    translate([-2,-2,-0.25])rotate([0,90,0])cylinder(d = 2, h = 10,$fn = 20);
    translate([-2,2,-0.25])rotate([0,90,0])cylinder(d = 2, h = 10,$fn = 20);
    }
    translate([24,-8.75,-5])cube([3,7,6]);//cables
    translate([24,1.75,-5])cube([3,7,6]);//cables
    translate([14,-15,-8])cylinder(d = 2.8, h = 12, $fn = 50);
    translate([14,15,-8])cylinder(d = 2.8, h = 12, $fn = 50);
    hull()
    {
        translate([8,-7,-11])cylinder(d = 1.8, h = 12, $fn = 20);
        translate([13,-7,-11])cylinder(d = 1.8, h = 12, $fn = 20);
    }
}
module rebaje_motores()
{
    rotate([0,-45,0])hull()
    {
        translate([-35/2,-37,-8])rotate([90,0,0])cylinder(d = 7.5, h = 1.5, $fn = 20, center = true);
        translate([35/2,-37,-8])rotate([90,0,0])cylinder(d = 7.5, h = 1.5, $fn = 20, center = true);
    }
     rotate([0,-45,0])hull()
    {
        translate([-35/2,37,-8])rotate([90,0,0])cylinder(d = 7.5, h = 1.5, $fn = 20, center = true);
        translate([35/2,37,-8])rotate([90,0,0])cylinder(d = 7.5, h = 1.5, $fn = 20, center = true);
    }
}
module bateria()
{
    difference()
    {
        union()
        {
            hull()
            {
                translate([-1,18,0])cylinder(d = 5, h = 5, $fn = 50);
                translate([-17,18,0])cylinder(d = 5, h = 5, $fn = 50);
            }
            hull()
            {
                translate([-1,-18,0])cylinder(d = 5, h = 5, $fn = 50);
                translate([-17,-18,0])cylinder(d = 5, h = 5, $fn = 50);
            }
            translate([4,0,0])cylinder(d = 10, h = 15, $fn = 50);
        }
        union()
        {
            translate([-9,0,11])rotate([90,0,0])cylinder(d = 18.2, h = 69, $fn = 50, center = true);
            translate([4,0,0])cylinder(d = 2.8, h = 16, $fn = 50);
        }
    }

}

module step_up()
{
    difference()
    {
        union()
        {
            hull()
            {
                translate([7,15,0])cylinder(d = 8, h = 10, $fn = 30);
                translate([7,-15,0])cylinder(d = 8, h = 10, $fn = 30);
            }
            hull()
            {
                translate([-19,-9,0])cylinder(d = 3, h = 10,$fn = 20);
                translate([19,-9,0])cylinder(d = 3, h = 10,$fn = 20);
                translate([19,12,0])cylinder(d = 3, h = 10,$fn = 20);
                translate([-19,12,0])cylinder(d = 3, h = 10,$fn = 20);
                translate([-13,-9,0])cylinder(d = 5, h = 10,$fn = 20);
                translate([13,-9,0])cylinder(d = 5, h = 10,$fn = 20);
                translate([13,9,0])cylinder(d = 5, h = 10,$fn = 20);
                translate([-13,9,0])cylinder(d = 5, h = 10,$fn = 20);
            }
        }
        union()
        {
                translate([7,15,0])cylinder(d = 2.8, h = 12, $fn = 30);
                translate([7,-15,0])cylinder(d = 2.8, h = 12, $fn = 30);
            hull()
            {
                translate([-18,-8,9])cylinder(d = 2, h = 10,$fn = 20);
                translate([18,-8,9])cylinder(d = 2, h = 10,$fn = 20);
                translate([18,8,9])cylinder(d = 2, h = 10,$fn = 20);
                translate([-18,8,9])cylinder(d = 2, h = 10,$fn = 20);
            }
            hull()
            {
                translate([-13,-8,3])cylinder(d = 4, h = 10,$fn = 20);
                translate([13,-8,3])cylinder(d = 4, h = 10,$fn = 20);
                translate([13,8,3])cylinder(d = 4, h = 10,$fn = 20);
                translate([-13,8,3])cylinder(d = 4, h = 10,$fn = 20);
            }
            hull()
            {
                translate([-16,4,3])cylinder(d = 4, h = 10,$fn = 20);
                translate([16,4,3])cylinder(d = 4, h = 10,$fn = 20);
            }
            hull()
            {
                translate([-16,-4,3])cylinder(d = 4, h = 10,$fn = 20);
                translate([16,-4,3])cylinder(d = 4, h = 10,$fn = 20);
            }
        }
    }
}
module tornillos_placa()
{
        translate([-25, -42,0])cylinder(r = 5, h =  40, $fn = 100);// cilidro altura delantera derecha
        translate([-25, 42,0])cylinder(r = 5, h = 40, $fn = 100);//cilindro altura delantera izquierda
        translate([45, -42,0])cylinder(r = 5, h =  40, $fn = 100);// cilidro altura delantera derecha
        translate([45, 42,0])cylinder(r = 5, h = 37, $fn = 100);//cilindro altura delantera izquierda
}
module vaciado_tornillos_placa()
{
        translate([-25, -42,-1])cylinder(r = 3.2, h =  13, $fn = 100);// cilidro altura delantera derecha
        translate([-25, 42,-1])cylinder(r = 3.2, h = 13, $fn = 100);//cilindro altura delantera izquierda
        translate([45, -42,-1])cylinder(r = 3.2, h =  13, $fn = 100);// cilidro altura delantera derecha
        translate([45, 42,-1])cylinder(r = 3.2, h = 13, $fn = 100);//cilindro altura delantera izquierda
        translate([-25, -42,12.2])cylinder(r = 1.7, h =  10, $fn = 100);// cilidro altura delantera derecha
        translate([-25, 42,12.2])cylinder(r = 1.7, h = 10, $fn = 100);//cilindro altura delantera izquierda
        translate([45, -42,12.2])cylinder(r = 1.7, h =  10, $fn = 100);// cilidro altura delantera derecha
        translate([45, 42,12.2])cylinder(r = 1.7, h = 10, $fn = 100);//cilindro altura delantera izquierda
}
module interruptor()
{
    translate([0,-11.5/2,0])cube([6,11,10]);//cuerpo
    translate([0,-10.5,0])cube([0.8,21,10]);//placa frontal
    translate([0,-8/2,0])cube([10,8,10]);//culito paloscables
    translate([-10, -7.5/2,1])cube([20,7.5,9]);
    translate([-7,0,0])hull()// loqueslodemeterlaszarpaspancender
    {
        translate([0,-5,2])sphere(d = 10, $fn = 50);
        translate([0,-5,4])sphere(d = 10, $fn = 50);
        translate([0,5,2])sphere(d = 10, $fn = 50);
        translate([0,5,4])sphere(d = 10, $fn = 50);
    }
}
module soporte_interruptor()
{
    hull()
    {
        hull()
        {
            translate([-50,-12,30])cube([7,24,7]);
            translate([-50,-12,25])cube([2,24,7]);
        }
        hull()
        {
            translate([-50,-7,30])cube([13,14,7]);
            translate([-50,-7,19])cube([2,14,7]);
        }
    }
}