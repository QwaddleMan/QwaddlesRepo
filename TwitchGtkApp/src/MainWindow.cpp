#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow()
  : m_button1("My Button")
{
  set_title("Basic Application");
  set_border_width(10);

  add(m_box);

  m_button1.signal_clicked().connect(sigc::bind<Glib::ustring>(
        sigc::mem_fun(*this, &MainWindow::on_button_clicked), "button 1"));

  m_box.pack_start(m_button1);
  m_button1.show();
  m_box.show();
}

MainWindow::~MainWindow()
{
  
}

void MainWindow::on_button_clicked(Glib::ustring data)
{
  std::cout<<"hello\n";
}
