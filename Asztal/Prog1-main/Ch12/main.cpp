/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"


double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 400;

    int x_orig = xmax/2;
    int y_orig = ymax/2;

    int rmin = -10;
    int rmax = 10;
    
    int n_points = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "My window"};

	Point origo {x_orig, y_orig};

	int xlength = xmax -200;
	int ylength = ymax ;

	int xscale = 20, yscale = 20;


	Function sq (square, rmin, rmax, origo, n_points, xscale, yscale);
	Function sine(sin,0,100,origo,1000,40,40);
	sine.set_color(Color::blue);

	Axis x {Axis::x, Point{100, y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig, ylength}, ylength, ylength/yscale, "y"};

	Polygon poly;
	poly.add(Point{300,200});
	poly.add(Point{300,300});
	poly.add(Point{200,200});


	poly.set_color(Color::magenta);
	poly.set_style(Line_style::dash);
	win.set_label("Polygon");
	

	Text t {Point{350,400}, "Hello world!"};
	t.set_font(Font::times_bold);
	t.set_font_size(20);

	Image ii {Point{100,0}, "badge.jpg"};


	win.attach(ii);
	win.attach(t);
	win.attach(sq);
	win.attach(x);
	win.attach(y);
	win.attach(poly);
    win.wait_for_button();

}
