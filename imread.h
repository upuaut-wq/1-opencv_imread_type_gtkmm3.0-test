#ifndef GTKMMOPENCV_IMREAD_H
#define GTKMMOPENCV_IMREAD_H
#include <gtkmm/box.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/radiobutton.h>
#include <gtkmm/frame.h>
#include <gtkmm/entry.h>
#include <gdkmm/pixbuf.h>
#include <glibmm/refptr.h>
#include <opencv2/opencv.hpp>


class ImRead:public Gtk::Window{
    public:
        ImRead();
        virtual ~ImRead();
        int get_active_radio_button();
    protected:
        //Sinal
        void on_btn_carregar();

        Gtk::RadioButtonGroup grupo;
        Gtk::RadioButton btn01;
        Gtk::RadioButton btn02;
        Gtk::RadioButton btn03;
        Gtk::RadioButton btn04;
        Gtk::RadioButton btn05;
        Gtk::RadioButton btn06;
        Gtk::RadioButton btn07;
        Gtk::RadioButton btn08;
        Gtk::RadioButton btn09;
        Gtk::RadioButton btn10;
        Gtk::RadioButton btn11;
        Gtk::RadioButton btn12;
        Gtk::RadioButton btn13;
        Gtk::RadioButton btn14;
        Gtk::RadioButton btn15;
        Gtk::RadioButton btn16;
        Gtk::Frame frame_radio;

        Gtk::Entry m_entry;
        Gtk::Box m_frame_box;
        Gtk::Frame frame_entry;

        Gtk::Box m_main_box;
        Gtk::Box m_dir_box;
        Gtk::Box m_dir_box1;
        Gtk::Box m_dir_box2;
        Gtk::Box m_esq_box;
        Gtk::Box m_esq_box1;





    //Imagem original
    Glib::RefPtr<Gdk::Pixbuf> img_or;
    Gtk::Image imgor;
    //Imagem Carregada
    Glib::RefPtr<Gdk::Pixbuf> img_des;
    Gtk::Image imgdes;

    Gtk::Button carregar;


};

#endif //GTKMMOPENCV_IMREAD_H