#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/window.h>



class MainWindow : public Gtk::Window
{
public:
  MainWindow();
  virtual ~MainWindow();
private:
protected:
  void on_button_clicked(Glib::ustring data);

  Gtk::Box m_box;
  Gtk::Button m_button1;
};

#endif
