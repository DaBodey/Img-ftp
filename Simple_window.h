// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//modified by David Bodey, Mitchell Blowey, and Sara Ballard

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"
#include <FL/Fl_Native_File_Chooser.H>
//#include <time.h>
using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Simple_window: Graph_lib::Window {

	Simple_window(Point xy, int w, int h, const string& title);
	bool wait_for_button(); // simple event loop

private:
//	time_t timestamp; //used in naming the photos
	string test_output1;string result;

	bool b_tag1 = false;
	bool b_tag2 = false;
	bool b_tag3 = false;
	bool b_tag4 = false;
	bool b_tag5 = false;
	bool b_tag6 = false;
	bool b_tag7 = false;
	bool b_tag8 = false;
	bool b_tag9 = false;
	bool b_tag10 = false;
	//string err; // used with error_msg to display feedback to user
	string tag_passed;
	ostringstream ss;
	Button browse_button; //used for looking for a file without URL
	Button submit_button;     // the "next" button
	//Button switch_button;
	Button previous_button; //used to see previous photo in gallery
	Button delete_button; //used to delete a photo
	Button next_button; //used to see next photo in gallery
	Button tag1_button; //used for tag implementation
	Button tag2_button; //used for tag implementation
	Button tag3_button; //used for tag implementation
	Button tag4_button; //used for tag implementation
	Button tag5_button; //used for tag implementation

	Button tag1_switch_button; //used for tag implementation
	Button tag2_switch_button; //used for tag implementation
	Button tag3_switch_button; //used for tag implementation
	Button tag4_switch_button; //used for tag implementation
	Button tag5_switch_button; //used for tag implementation

	Rectangle rect_back; //used for background
	//   Text *error_msg; //used to display prompt to user if out of bounds in gallery
	//Text *tag_switch; //used to display info to user about onscreen buttons
	//  Text *tag; //used to display info to user about onscreen buttons
	In_box input_box1; //used to obtain url from user for new photo
	ifstream r_imgViewDB;  //used to read from database
	ofstream w_imgViewDB; //used for writing to database
	vector<string> vr; //used to store image locations
	Image *img;
	Fl_Native_File_Chooser fnfc; //fltk file browser
	bool button_pushed;     // implementation detail
	bool b_tag = false; //used to determine tags
	string test_type(string &s);string pic_num = ""; //used for naming files appropriately
	int pic_view = -1; // used for next/previous - used -1 to display first image(0) when next is clicked
	Vector_ref<Rectangle> vr_rect;
	static void cb_submit(Address, Address); // callback for submit_button
	static void cb_browse(Address, Address); // callback for browse_button
	//static void cb_switch(Address, Address); // callback for switch_button
	static void cb_previous(Address, Address); // callback for previous_button
	static void cb_next(Address, Address); // callback for next_button
	static void cb_deleted(Address, Address); // callback for delete_button
	static void cb_tag1(Address, Address); // callback for tag1_button
	static void cb_tag2(Address, Address); // callback for tag2_button
	static void cb_tag3(Address, Address); // callback for tag3_button
	static void cb_tag4(Address, Address); // callback for tag4_button
	static void cb_tag5(Address, Address); // callback for tag5_button

	static void cb_switch_tag1(Address, Address); // callback for tag1_switch_button
	static void cb_switch_tag2(Address, Address); // callback for tag2_switch_button
	static void cb_switch_tag3(Address, Address); // callback for tag3_switch_button
	static void cb_switch_tag4(Address, Address); // callback for tag4_switch_button
	static void cb_switch_tag5(Address, Address); // callback for tag5_switch_button

	bool check_switch_tag(bool);

	void submit();            // action to be done when submit_button is pressed
	void browse();            // action to be done when browse_button is pressed
	void previous();        // action to be done when previous_button is pressed
	void next();            // action to be done when next_button is pressed
	void output();            // redetermines database and then rebuilds_array()
	void deleted();            // deletes image upon users request
	void tags();            // adds tags to db file
	void rebuild_array();            // rebuilds array based on db file
	void color_change(int, bool &); //changes color of tag buttons.
	void check_tag_status();
	void tag1(); // the five tags
	void tag2(); // the five tags
	void tag3(); // the five tags
	void tag4(); // the five tags
	void tag5(); // the five tags

	void switch_tag1(); // used to modify viewed gallery
	void switch_tag2(); // used to modify viewed gallery
	void switch_tag3(); // used to modify viewed gallery
	void switch_tag4(); // used to modify viewed gallery
	void switch_tag5(); // used to modify viewed gallery

};
/*
 struct tab_window1 : Graph_lib::Window {
 tab_window1(Point xy, int w, int h, const string& title );
 bool wait_for_button();
 private:
 static void cb_tab1(Address, Address); // callback for browse_button
 Button tab_button1;
 bool button_pushed;     // implementation detail
 };
 */
//------------------------------------------------------------------------------
#endif // SIMPLE_WINDOW_GUARD
