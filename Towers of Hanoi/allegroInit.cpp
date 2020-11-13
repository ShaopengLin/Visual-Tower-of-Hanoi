#include "prototypesHanoi.h"
//initialize Allegro functions
int initializeAllegro()
{
    // Initialize Allegro
    al_init();

    // initialize display
    display = al_create_display(SCREENWIDTH,SCREENHEIGHT);
    if (!display) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize display!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    al_set_window_title(display, "Towers of Hanoi");
    // Initialize keyboard routines
    if (!al_install_keyboard()) {
        al_show_native_message_box(display, "Error", "Error", "failed to initialize the keyboard!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    // need to add image processor
    if (!al_init_image_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize image addon!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    //bitmaps
    ricardo = al_load_bitmap("ricardo.jpg");
    ingameBackground = al_load_bitmap("ingame.jpg");
    introBackground = al_load_bitmap("intro.jpg");
    elon = al_load_bitmap("elon.jpg");

    if (!(ricardo || ingameBackground || introBackground || elon)){
        al_show_native_message_box(display, "Error", "Error", "Failed to create bitmap",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    // Add fonts
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon
    //fonts
    farry = al_load_ttf_font(FONTNAMEFORFARRY, FONTSIZE, 0);
    farryHalfsize = al_load_ttf_font(FONTNAMEFORFARRY, FONTSIZE/2, 0);
    mh = al_load_ttf_font(FONTNAMEFORMH, FONTSIZE/2, 0);
    titleFont = al_load_ttf_font(FONTNAMEFORTITLE, FONTSIZE+16, 0);

    if (!(farry || farryHalfsize || mh || titleFont)) {
        al_show_native_message_box(display, "Error", "Error", "Could not load all fonts",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }
    // Initialize primative add on
    if (!al_init_primitives_addon()) {
        al_show_native_message_box(display, "Error", "Error", "Failed to initialize primatives addon!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        return -1;
    }

    // set up event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        al_show_native_message_box(display, "Error", "Error", "Failed to create event_queue!",
                                   nullptr, ALLEGRO_MESSAGEBOX_ERROR);
        al_destroy_display(display);
        return -1;
    }
    al_install_mouse();
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_mouse_event_source());

    return 0;
}
//destroy created allegro variables
int destroyAllegro()
{
    al_destroy_display(display);
    al_destroy_font(farry);
    al_destroy_font(farryHalfsize);
    al_destroy_font(mh);
    al_destroy_font(titleFont);
    al_destroy_bitmap(ricardo);
    al_destroy_bitmap(elon);
    al_destroy_bitmap(introBackground);
    al_destroy_bitmap(ingameBackground);
    al_destroy_event_queue(event_queue);
}
