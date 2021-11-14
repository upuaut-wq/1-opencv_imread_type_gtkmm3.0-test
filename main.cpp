#include <gtkmm/window.h>
#include <gtkmm/application.h>
#include "imread.h"


int main(int argc, char * argv[]){
    Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "Exemplo.imread.OpenCv");
    ImRead imread;
    app->run(imread);
}
