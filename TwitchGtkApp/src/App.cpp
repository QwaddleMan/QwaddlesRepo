#include <gtkmm.h> //MainWindow.h"
#include "MainWindow.h"

int main(int argc, char * argv[])
{
  auto app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
  
  MainWindow window;

  return app->run(window);
}
