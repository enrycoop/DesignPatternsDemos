#include <iostream>
#include <memory>
#include "Geometry.h"

using namespace std;

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

int main(int argc, char **argv) {
    const auto window = make_unique<Fl_Window>(300, 200, "Hello, FLTK");
    const auto box = make_unique<Fl_Box>(20, 80, 260, 40, "Hello, World!");
    box->box(FL_UP_BOX);
    box->labelfont(FL_BOLD + FL_COURIER);
    box->labelsize(24);
    window->end();
    window->show(argc, argv);

    vector<shared_ptr<VectorObject>> vectorObjects{
        std::make_shared<VectorRectangle>(10, 10, 100, 100),
        std::make_shared<VectorRectangle>(30, 30, 60, 60),
    };
    return Fl::run();
}





