#include "imread.h"
#include <iostream>


ImRead::ImRead(){
    //Titulo da janela
    this->set_title("Exemplo IMREAD OPENCV");

    //Caixa principal
    this->add(this->m_main_box);
    this->m_main_box.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    this->m_main_box.pack_start(this->m_dir_box);
    this->m_dir_box.set_orientation(Gtk::ORIENTATION_HORIZONTAL);
    this->m_dir_box.pack_start(this->m_dir_box1);
    this->m_dir_box.pack_start(this->m_dir_box2);
    this->m_main_box.pack_start(this->m_esq_box);
    this->m_esq_box.set_orientation(Gtk::ORIENTATION_VERTICAL);

    //Permite que a box se posicione na parte superior deixando todo o conteudo na parte 
    //superior dentro dos limites de cada box, frame e botôes
    //////////////////////////////////////////////////////////////////
    //----------------------------------
    //|                     |           |  
    //|                     |-----------|
    //|                     |           |  <-  Alinha conteudo na parte superior FORÇANDO
    //|                     |           |      o conteúdo se ajustar na parte superior.
    //|                     |           |
    //|                     |-----------|
    //|                                 |
    //|                                 |
    //----------------------------------
    this->m_esq_box.set_valign(Gtk::ALIGN_START);

    Gtk::RadioButtonGroup grupo;
    
    this->m_esq_box.pack_start(frame_entry);
    this->frame_entry.add(this->m_frame_box);
    
    //Seta Label ao Gtk::Frama que segura o Gtk::Entry
    this->carregar.set_label("Carregar Image");
    this->m_frame_box.pack_start(this->m_entry);

    //Seta margens (Visual)
    this->m_frame_box.set_margin_top(5);
    this->m_frame_box.set_margin_bottom(10);
    this->m_frame_box.set_margin_start(10);
    this->m_frame_box.set_margin_end(10);
    this->frame_entry.set_label(" Imagem ");
    this->frame_entry.set_label_align(0.05);
    this->m_frame_box.pack_start(this->carregar);

    //Sinal para carregar uma umagem.
    this->carregar.signal_clicked().connect(sigc::mem_fun(*this,&ImRead::on_btn_carregar));
    
    //Configuração das opções de carregamento. 
    //Adiciona um label no Gtk::Frame
    this->frame_radio.set_label(" Tipo de Carregamento ");

    //Cria espaços para que o Label não fique soporeposto na borda esquerda e superior.
    this->frame_radio.set_margin_top(10);
    this->frame_radio.set_label_align(0.05);

    //Adiciona o segundo grama em uma box.
    this->m_esq_box.pack_start(this->frame_radio);
    this->frame_radio.add(this->m_esq_box1);

    //Seta uma orientação para box que vai segurar os radio buttons.
    //Seta margins na box.
    this->m_esq_box1.set_orientation(Gtk::ORIENTATION_VERTICAL);
    this->m_esq_box1.set_margin_top(5);
    this->m_esq_box1.set_margin_bottom(10);
    this->m_esq_box1.set_margin_start(10);
    this->m_esq_box1.set_margin_end(10);

    //Configura os dario button
    //Adiciona o botão na box
    this->m_esq_box1.pack_start(this->btn01);
    //Seta um label
    this->btn01.set_label("IMREAD_UNCHANGED");
    //Adiciona o radio button no grupo chamado grupo.
    this->btn01.set_group(grupo); 
    this->m_esq_box1.pack_start(this->btn02);
    this->btn02.set_label("IMREAD_GRAYSCALE ");
    this->btn02.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn03);
    this->btn03.set_label("IMREAD_COLOR");
    this->btn03.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn04);
    this->btn04.set_label("IMREAD_ANYDEPTH");
    this->btn04.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn05);
    this->btn05.set_label("IMREAD_ANYCOLOR");
    this->btn05.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn06);
    this->btn06.set_label("IMREAD_LOAD_GDAL");
    this->btn06.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn07);
    this->btn07.set_label("IMREAD_REDUCED_GRAYSCALE_2");
    this->btn07.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn08);
    this->btn08.set_label("IMREAD_REDUCED_COLOR_2");
    this->btn08.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn09);
    this->btn09.set_label("IMREAD_REDUCED_GRAYSCALE_4");
    this->btn09.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn10);
    this->btn10.set_label("IMREAD_REDUCED_COLOR_4");
    this->btn10.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn11);
    this->btn11.set_label("IMREAD_REDUCED_GRAYSCALE_8");
    this->btn11.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn12);
    this->btn12.set_label("IMREAD_REDUCED_COLOR_8");
    this->btn12.set_group(grupo);
    this->m_esq_box1.pack_start(this->btn13);
    this->btn13.set_label("IMREAD_IGNORE_ORIENTATION");
    this->btn13.set_group(grupo);

    //Seta um default no Gtk::Entry
    this->m_entry.set_text("img_test.png");
    
    //Adiciana as Gtk::Imagem nas devidas box
    this->m_dir_box1.pack_start(this->imgor);
    this->m_dir_box2.pack_start(this->imgdes);

    //Adiciana na "referência" das imagens a informação dos arquivos 
    this->img_or = Gdk::Pixbuf::create_from_file("or.png");
    this->img_des = Gdk::Pixbuf::create_from_file("ds.png");

    //Adiciona as referencias nas Gtk::Imagens
    imgdes.set(this->img_des);
    imgor.set(this->img_or);

    //Exibe todos os sub widges adicionadas na Gtk::Window.
    this->show_all_children();

}



void ImRead::on_btn_carregar(){
    cv::Mat outImage;
    cv::String str;
    str = this->m_entry.get_text();
    std::cout << str << std::endl;


    outImage = cv::imread(str,this->get_active_radio_button());
    cv::imwrite("grav.jpg",outImage);
    this->img_or = Gdk::Pixbuf::create_from_file(str);
    this->img_des = Gdk::Pixbuf::create_from_file("grav.jpg");
    imgdes.set(this->img_des);
    imgor.set(this->img_or);
   
}


int ImRead::get_active_radio_button(){
if(this->btn01.get_active() == true){
    return -1;
}
if(this->btn02.get_active() == true){
    return 0;
}
if(this->btn03.get_active() == true){
    return 1;
}
if(this->btn04.get_active() == true){
    return 2;
}
if(this->btn05.get_active() == true){
    return 4;
}
if(this->btn06.get_active() == true){
    return 8;
}
if(this->btn07.get_active() == true){
    return 16;
}
if(this->btn08.get_active() == true){
    return 17;
}
if(this->btn09.get_active() == true){
    return 32;
}
if(this->btn10.get_active() == true){
    return 33;
}
if(this->btn11.get_active() == true){
    return 64;
}
if(this->btn12.get_active() == true){
    return 65;
}
if(this->btn13.get_active() == true){
    return 128;
}

}

ImRead::~ImRead(){

    
}