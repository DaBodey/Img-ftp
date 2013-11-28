/*
 Simple_window.cpp
 Minimally revised for C++11 features of GCC 4.6.3 or later
 Walter C. Daugherity		June 10, 2012
 */

//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//modified by David Bodey, Mitchell Blowey, and Sara Ballard
#include <vector>
#include "Simple_window.h"
#include "Graph.h"
#include <iostream>
#include "GUI.h"
#include <ctime>
#include <algorithm>
using namespace Graph_lib;
//------------------------------------------------------------------------------
Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
		Window(xy, w, h, title),
		// switch_button(Point(x_max()-70,0), 70, 20, "Next Window", cb_switch),
		submit_button(Point(x_max() - 400, 20), 85, 35, "Submit", cb_submit), browse_button(
				Point(x_max() - 400, 60), 85, 35, "Browse", cb_browse), input_box1(
				Point(400, 20), 400, 30, "File Location"), rect_back(
				Point(0, 0), x_max(), y_max()), //black background
		previous_button(Point(x_max() / 4, y_max() - 80), 300, 80, "Previous",
				cb_previous), next_button(
				Point(x_max() - (x_max() / 2), y_max() - 80), 300, 80, "Next",
				cb_next), delete_button(Point(0, y_max() - 50), 115, 50,
				"Delete", cb_deleted), tag1_button(
				Point(x_max() - 130, y_max() - 245), 120, 45, "Add to Family",
				cb_tag1), tag2_button(Point(x_max() - 130, y_max() - 290), 120,
				45, "Add to Friends", cb_tag2), tag3_button(
				Point(x_max() - 130, y_max() - 335), 120, 45,
				"Add to Aggieland", cb_tag3), tag4_button(
				Point(x_max() - 130, y_max() - 380), 120, 45, "Add to Pets",
				cb_tag4), tag5_button(Point(x_max() - 130, y_max() - 425), 120,
				45, "Add to Vacation", cb_tag5),

		tag1_switch_button(Point(90, y_max() - 245), 120, 45, " View Family",
				cb_switch_tag1), tag2_switch_button(Point(90, y_max() - 290),
				120, 45, "View Friends", cb_switch_tag2), tag3_switch_button(
				Point(90, y_max() - 335), 120, 45, "View Aggieland",
				cb_switch_tag3), tag4_switch_button(Point(90, y_max() - 380),
				120, 45, "View Pets", cb_switch_tag4), tag5_switch_button(
				Point(90, y_max() - 425), 120, 45, "View Vacation",
				cb_switch_tag5), button_pushed(NULL),
		//   error_msg(NULL),
		//  tag(NULL),
//   tag_switch(NULL),
		img(NULL) {
	//   rect_back.set_fill_color(Color::black);
	int x_val = 0;
	for (int j = 0; j < 2; ++j) { //used to create color around tag related buttons
		x_val = x_val + 90;
		int y_val = y_max() - 245;
		for (int i = 0; i <= 4; ++i) {
			vr_rect.push_back(new Rectangle(Point(x_val, y_val), 120, 45));
			vr_rect[vr_rect.size() - 1].set_color(Color::black);
			y_val = y_val - 45;
		}
		x_val = x_max() - 220;
	}
	string temp = "";
	ifstream r_imgViewDB("imgViewDB.txt");
	while (getline(r_imgViewDB, temp)) {  //initial db to array
		vr.push_back(temp);
	}
	r_imgViewDB.close();
//    err = "Nothing to see here"; //out of bounds message
//    error_msg = new Text(Point(20, y_max()-70), err); //initial error to be used later in Next/prev
	//   tag = new Text(Point(20, y_max()-70), err); //initial error to be used later in Next/prev
	//       tag_switch = new Text(Point(20, y_max()-70), err); //initial error to be used later in Next/prev
	//  error_msg -> set_color(Color::red);
	for (int i = 0; i < vr_rect.size(); ++i) {
		attach(vr_rect[i]);
	}
	attach(delete_button);
	attach(rect_back);
//    attach(switch_button);
	attach(browse_button);
	attach(submit_button);
	attach(input_box1);
	attach(next_button);
	attach(previous_button);
	attach(tag1_button);
	attach(tag2_button);
	attach(tag3_button);
	attach(tag4_button);
	attach(tag5_button);

	attach(tag1_switch_button);
	attach(tag2_switch_button);
	attach(tag3_switch_button);
	attach(tag4_switch_button);
	attach(tag5_switch_button);

	// attach(*error_msg);
}
//------------------------------------------------------------------------------
bool Simple_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
{
	show();
	button_pushed = false;
#if 0
	// Simpler handler
	while (!button_pushed) Fl::wait();
	Fl::redraw();
#else
	// To handle the case where the user presses the X button in the window frame
	// to kill the application, change the condition to 0 to enable this branch.
	Fl::run();
#endif
	return button_pushed;
}
//------------------------------------------------------------------------------

void Simple_window::cb_tag1(Address, Address pw)
// call Simple_window::tag1() for the window located at pw
		{
	reference_to<Simple_window>(pw).tag1();
}

void Simple_window::cb_tag2(Address, Address pw)
// call Simple_window::tag2() for the window located at pw
		{

	reference_to<Simple_window>(pw).tag2();
}

void Simple_window::cb_tag3(Address, Address pw)
// call Simple_window::tag3() for the window located at pw
		{

	reference_to<Simple_window>(pw).tag3();
}

void Simple_window::cb_tag4(Address, Address pw)
// call Simple_window::tag4() for the window located at pw
		{

	reference_to<Simple_window>(pw).tag4();
}

void Simple_window::cb_tag5(Address, Address pw)
// call Simple_window::tag5() for the window located at pw
		{

	reference_to<Simple_window>(pw).tag5();
}

void Simple_window::cb_switch_tag1(Address, Address pw)
// call Simple_window::tag1() for the window located at pw
		{
	reference_to<Simple_window>(pw).switch_tag1();
}

void Simple_window::cb_switch_tag2(Address, Address pw)
// call Simple_window::tag2() for the window located at pw
		{

	reference_to<Simple_window>(pw).switch_tag2();
}

void Simple_window::cb_switch_tag3(Address, Address pw)
// call Simple_window::tag3() for the window located at pw
		{

	reference_to<Simple_window>(pw).switch_tag3();
}

void Simple_window::cb_switch_tag4(Address, Address pw)
// call Simple_window::tag4() for the window located at pw
		{

	reference_to<Simple_window>(pw).switch_tag4();
}

void Simple_window::cb_switch_tag5(Address, Address pw)
// call Simple_window::tag5() for the window located at pw
		{

	reference_to<Simple_window>(pw).switch_tag5();
}

void Simple_window::cb_submit(Address, Address pw)
// call Simple_window::submit() for the window located at pw
		{
	reference_to<Simple_window>(pw).submit();
}
void Simple_window::cb_browse(Address, Address pw)
// call Simple_window::browse() for the window located at pw
		{
	reference_to<Simple_window>(pw).browse();
}
/*void Simple_window::cb_switch(Address, Address pw)
 // call Simple_window::switch() for the window located at pw
 {
 }
 */
void Simple_window::cb_previous(Address, Address pw)
// call Simple_window::previous() for the window located at pw
		{
	reference_to<Simple_window>(pw).previous();
}
void Simple_window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
		{
	reference_to<Simple_window>(pw).next();
}
void Simple_window::cb_deleted(Address, Address pw)
// call Simple_window::deleted() for the window located at pw
		{
	reference_to<Simple_window>(pw).deleted();
}
//------------------------------------------------------------------------------
string Simple_window::test_type(string &s) {
	result = "";
	time_t raw;
	time(&raw);
	pic_num = ctime(&raw); //adds timestamp picture number
	pic_num = pic_num.substr(0, pic_num.length() - 1);
	string filename; //temporary variable for utilization of below c++11 features
	for (auto c : pic_num) { //remove unwanted characters from timestamp
		if (c == ':' || c == ' ')
			c = '-';
		filename.push_back(c);
	}

	if (s.find(".png") != string::npos) { //used to properly identify image from url and name it.
		s = "wget " + s + " -O " + filename + ".png";
		result = filename + ".png";
	} else if (s.find(".jpg") != string::npos) {
		s = "wget " + s + " -O " + filename + ".jpg";
		result = filename + ".jpg";
	} else if (s.find(".jpeg") != string::npos) {
		s = "wget " + s + " -O " + filename + ".jpeg";
		result = filename + ".jpeg";
	} else if (s.find(".bmp") != string::npos) {
		s = "wget " + s + " -O " + filename + ".bmp";
		result = filename + ".bmp";
	} else if (s.find(".gif") != string::npos) {
		s = "wget " + s + " -O " + filename + ".gif";
		result = filename + ".gif";
	}
	return result;
}

void Simple_window::previous() {
	if (img) {
		detach(*img);
		delete img;
	} // removes image if it is currently attached

	if ( pic_view < vr.size() && pic_view != -1 && pic_view != 0) {
		--pic_view;
		check_tag_status();

		if (vr[pic_view].find(',') != string::npos)
			img = new Image(Point(x_max() - 950, y_max() / 7),
					vr[pic_view].substr(0, vr[pic_view].find(',')));
		else {
			img = new Image(Point(x_max() - 950, y_max() / 7), vr[pic_view]);
		}
		img->set_mask(Point(0, 0), 750, 600);

	} else {
		pic_view = -1; //sets up next button to be pressed to increment to element 0

			img = new Image(Point(x_max() - 950, y_max() / 7), "end.jpg");
	}
	attach(*img);
	redraw();
}
void Simple_window::next() {
	button_pushed = true;
	if (img) {
		detach(*img);
		delete img;
	}
	++pic_view;
	if (pic_view < vr.size()) {
	check_tag_status();

		if (vr[pic_view].find(',') != string::npos)
			img = new Image(Point(x_max() - 950, y_max() / 7), vr[pic_view].substr(0, vr[pic_view].find(',')));
		else {
			img = new Image(Point(x_max() - 950, y_max() / 7), vr[pic_view]);
		}
		img->set_mask(Point(0, 0), 750, 600);

	} else {
		pic_view = -1;
		img = new Image(Point(x_max() - 950, y_max() / 7), "end.jpg");

	}
	attach(*img);
	redraw();
	button_pushed = false;
}
void Simple_window::browse() {
	fnfc.title("Pick a file");
	fnfc.type(Fl_Native_File_Chooser::BROWSE_FILE);
	fnfc.filter("Pictures\t*.{jpg,gif,jpeg,JPG,GIF,JPEG,bmp,BMP,png,PNG}"); // includes two EC types
	fnfc.directory("/var/tmp");           // default directory to use
	switch (fnfc.show()) { // Show native chooser
	case -1:
		printf("ERROR: %s\n", fnfc.errmsg());
		break;  // ERROR
	case 1:
		printf("CANCEL\n");
		break;  // CANCEL
	default:
		printf("PICKED: %s\n", fnfc.filename());
		break;  // FILE CHOSEN
	}
	if (img) {
		detach(*img);
		delete img;
	}
	string filelocation = fnfc.filename(); //chosen filename with location
	string filename = filelocation.substr(filelocation.find_last_of('/') + 1,
	string::npos); //substr such that only the name of the file is obtained
	string cp_string = "if [ ! -f filename] then cp " + filelocation + " "
			+ filename; //command to be used in next line if file doesnt already exist.
	system(cp_string.c_str()); //copies  picture to root directory of this app
	img = new Image(Point(x_max() - 950, y_max() / 7), filename);
	vr.push_back(filename);
	pic_view = vr.size() - 1; //after selecting photo, gallery adds to end and switches location to it.
	img->set_mask(Point(0, 0), 750, 600);
	attach(*img);
	output();
	redraw();
}
void Simple_window::submit() {
	pic_view = vr.size() - 1; //sets current image to the last image in the gallery
	test_output1 = "";
	test_output1 = input_box1.get_string();
	result = test_type(test_output1); // check type of img being requested
	ss << result;
	system(test_output1.c_str());
	if (img) {
		detach(*img);
		delete img;
	}
	img = new Image(Point(x_max() - 950, y_max() / 7), result);
	img->set_mask(Point(0, 0), 750, 600);
	vr.push_back(result);
	pic_view = vr.size() - 1; // goes to where photo has been pushed back
	attach(*img);
	output();
	redraw();
}
void Simple_window::output() {
	ofstream w_imgViewDB("imgViewDB.txt");
	for (int i = 0; i < vr.size(); ++i) {
		if (!vr[i].empty()) //removes empty lines
			w_imgViewDB << vr[i] << endl;
	}
	w_imgViewDB.close();
	rebuild_array();
	check_tag_status();
}
void Simple_window::deleted() //used to delete a photo from gallery upon users request
{
	if (img && pic_view != -1) {
		detach(*img);
		delete img;
	}
	if (vr.size() > 0 && pic_view != -1) { //make sure it has something to delete
		vr[pic_view].clear(); //erase photo from vector
		output(); //this recreates the database, then the vector from that, removing extra lines and such
	} //remove old image that is being displayed
	if (pic_view < vr.size() && pic_view != -1) {
		pic_view = 0;
		img = new Image(Point(x_max() - 950, y_max() / 7), vr[pic_view]); //resets when the last image is deleted.
		img->set_mask(Point(0, 0), 750, 600);
		attach(*img);
	}
	redraw();
	//    img = new Image(Point (x_max()-950, y_max()/7), vr[pic_view - 1]);  // used when it was not the last image being affected
}

// void Simple_window::tags()
// {
//     if (vr.size() > 0 ) {
//         vr[pic_view].append(1, ',');
//     }
// }
void Simple_window::rebuild_array() //recreates the vector based on the current database file.
{
	vr.clear(); //remove all items from vector
	string temp = "";
	ifstream r_imgViewDB("imgViewDB.txt");
	while (getline(r_imgViewDB, temp)) { //read from database and push line into vector as element
		vr.push_back(temp);
	}
	r_imgViewDB.close();
}

void Simple_window::tag1() {
	color_change(9, b_tag10);
	tag_passed = "family";
	if (vr[pic_view].find(tag_passed) != string::npos) {
		vr[pic_view].replace(vr[pic_view].find(", family"), 8, ""); //remove tag if button is clicked with tag already existing
	} else {
		vr[pic_view].append(", " + tag_passed);
	}
	output();
	button_pushed = false;
}
void Simple_window::tag2() {
	color_change(8, b_tag9);
	tag_passed = "friends";
	if (vr[pic_view].find(tag_passed) != string::npos) {
		vr[pic_view].replace(vr[pic_view].find(", friends"), 9, ""); //remove tag if button is clicked with tag already existing
	} else {
		vr[pic_view].append(", " + tag_passed);
	}
	output();
}
void Simple_window::tag3() {
	color_change(7, b_tag8);
	tag_passed = "aggieland";
	if (vr[pic_view].find(tag_passed) != string::npos) {
		vr[pic_view].replace(vr[pic_view].find(", aggieland"), 11, ""); //remove tag if button is clicked with tag already existing
	} else {
		vr[pic_view].append(", " + tag_passed);
	}
	output();
}
void Simple_window::tag4() {
	color_change(6, b_tag7);
	tag_passed = "pets";
	if (vr[pic_view].find(tag_passed) != string::npos) {
//vr[pic_view] = vr[pic_view].substr(vr[pic_view].find(tag_passed), vr[pic_view].find(',') 
//vr[pic_view].erase (std::remove(vr[pic_view].begin(), vr[pic_view].end(), tag_passed), vr[pic_view].end());
		vr[pic_view].replace(vr[pic_view].find(", pets"), 6, ""); //remove tag if button is clicked with tag already existing
	} else {
		vr[pic_view].append(", " + tag_passed);
	}
	output();
}
void Simple_window::tag5() {
	color_change(5, b_tag6);
	tag_passed = "vacation";
	if (vr[pic_view].find(tag_passed) != string::npos) {
		vr[pic_view].replace(vr[pic_view].find(", vacation"), 10, ""); //remove tag if button is clicked with tag already existing

	} else {
		vr[pic_view].append(", " + tag_passed);
	}
	output();
	button_pushed = false;
}

bool Simple_window::check_switch_tag(bool b_tag_check) {
	if (b_tag_check == false)
		return true;
	else if (b_tag_check == true)
		return false;

	else return false; //was warning
}
void Simple_window::check_tag_status() { ///used to identify from the db if tags are already added to file
	int i = 5; //rectangles for these tags range from 5-9
	vector<string> tag_options = { "family", "friends", "aggieland", "pets",
			"vacation" };
	for (auto check : tag_options) {
		if (vr[pic_view].find(check) != string::npos) {
			vr_rect[i].set_color(Color::green);
			switch (i) //used to change the value of the tag bool so that proper color is displayed.
			{
			case 5:
				b_tag6 = true;
				break;
			case 6:
				b_tag7 = true;
				break;
			case 7:
				b_tag8 = true;
				break;
			case 8:
				b_tag9 = true;
				break;
			case 9:
				b_tag10 = true;
				break;
			}
		} else {
			vr_rect[i].set_color(Color::red);
			{
				switch (i) //used to change the value of the tag bool so that proper color is displayed.
				{
				case 5:
					b_tag6 = false;
					break;
				case 6:
					b_tag7 = false;
					break;
				case 7:
					b_tag8 = false;
					break;
				case 8:
					b_tag9 = false;
					break;
				case 9:
					b_tag10 = false;
					break;
				}
			}
		}
		++i; //increments regardless
	}
}

void Simple_window::color_change(int col, bool &b_tag_check) {
	b_tag_check = check_switch_tag(b_tag_check);
	if (b_tag_check == true) { //used to change color of rectangle around button(on/off)
		vr_rect[col].set_color(Color::green);
		redraw();
	} else {
		vr_rect[col].set_color(Color::red);
		redraw();
	}
}
void Simple_window::switch_tag1() {
	vr.clear(); //remove all items from vector
	color_change(0, b_tag1); //changes button color
	string temp = "";
	ifstream r_imgViewDB("imgViewDB.txt");
	while (getline(r_imgViewDB, temp)) { //read from database and push line into vector as element
		if (temp.find("family") != string::npos) {
		} else
			vr.push_back(temp);
	}
	r_imgViewDB.close();
}
void Simple_window::switch_tag2() {
	vr.clear(); //remove all items from vector
	color_change(1, b_tag2);
	string temp = "";
	ifstream r_imgViewDB("imgViewDB.txt");
	while (getline(r_imgViewDB, temp)) { //read from database and push line into vector as element
		if (temp.find("friends") != string::npos) {
		} else
			vr.push_back(temp);
	}
	r_imgViewDB.close();
}
void Simple_window::switch_tag3() {
	vr.clear(); //remove all items from vector
	color_change(2, b_tag3);
	string temp = "";
	ifstream r_imgViewDB("imgViewDB.txt");
	while (getline(r_imgViewDB, temp)) { //read from database and push line into vector as element
		if (temp.find("aggieland") != string::npos) {
		} else
			vr.push_back(temp);
	}
	r_imgViewDB.close();
}
void Simple_window::switch_tag4() {
	vr.clear(); //remove all items from vector
	color_change(3, b_tag4);
	string temp = "";
	ifstream r_imgViewDB("imgViewDB.txt");
	while (getline(r_imgViewDB, temp)) { //read from database and push line into vector as element
		if (temp.find("pets") != string::npos) {
		} else
			vr.push_back(temp);
	}
	r_imgViewDB.close();
}
void Simple_window::switch_tag5() {
	vr.clear(); //remove all items from vector
	color_change(4, b_tag5);
	string temp = "";
	ifstream r_imgViewDB("imgViewDB.txt");
	while (getline(r_imgViewDB, temp)) { //read from database and push line into vector as element
		if (temp.find("vacation") != string::npos) {
		} else
			vr.push_back(temp);
	}
	r_imgViewDB.close();
}
//------------------------------------------------------------------------------
