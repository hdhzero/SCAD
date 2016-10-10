#ifndef SCAD_MAIN_WINDOW_H
#define SCAD_MAIN_WINDOW_H

#include <gtkmm.h>

namespace Scad {
    class ScadMainWindow : public Gtk::Window {
        private:
            Gtk::Box box1;
            Gtk::Box top_area_box;
            Gtk::Box main_area_box;
            Gtk::Box bottom_area_box;
            Gtk::Button df;
            Gtk::GLArea glarea;

        public:
            ScadMainWindow();
            virtual ~ScadMainWindow();

        public:
            void set_schematic_view();
            bool on_render(const Glib::RefPtr<Gdk::GLContext>& context);

        private:
            void build_main_area();
    };
}

#endif
