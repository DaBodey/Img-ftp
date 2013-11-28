//Program created by David Bodey, Mitchell Blowey, and Sara Ballard
//advice taken from Programming Principles and Practice Using C++ by Bjarne Stroustrup
//This program uses fltk to create a GUI based image viewer
//fnfc implementation information obtained from fltk.org, and then modified by myself
//as needed for use in this program

#include "std_lib_facilities_3.h"
#include "Simple_window.h"
#include "Graph.h"

int main()

try {
	//string s = "webfile.jpeg";
	Simple_window window(Point(0, 0), 1200, 800, "imgView"); //create windows
//    window.wait_for_button();
// keep_window_open();
	return (Fl::run());
//return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1; //indicates failure
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2; //indicates failure
}
