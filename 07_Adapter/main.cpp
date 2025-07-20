#include <iostream>
#include <memory>
#include "Geometry.h"

using namespace std;

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>

#include "graphics_gui.h"

//
// class DrawingWidget : public Fl_Box {
//     vector<shared_ptr<VectorObject>> objects;
//
// public:
//     DrawingWidget(int x, int y, int w, int h) : Fl_Box(x, y, w, h) {}
//
//     void addObject(shared_ptr<VectorObject> obj) {
//         objects.push_back(obj);
//     }
//
//     void draw() override {
//         Fl_Box::draw();
//
//         fl_color(FL_BLACK);
//
//         // Disegna tutti gli oggetti vettoriali
//         for (const auto& obj : objects) {
//             for (auto it = obj->begin(); it != obj->end(); ++it) {
//                 const Line& line = *it;
//                 fl_line(line.start.x, line.start.y, line.end.x, line.end.y);
//             }
//         }
//     }
// };


int main(int argc, char **argv) {
    // const auto window = make_unique<Fl_Window>(1080, 720, "Hello, FLTK");
    // const auto drawingArea = make_unique<DrawingWidget>(0, 0, 1080, 720);
    //
    // // Aggiungi gli oggetti geometrici al widget di disegno
    // drawingArea->addObject(std::make_shared<VectorRectangle>(10, 10, 100, 100));
    // drawingArea->addObject(std::make_shared<VectorRectangle>(30, 30, 60, 60));
    //
    // window->end();
    // window->show();

    make_window()->show();
    return Fl::run();

}





