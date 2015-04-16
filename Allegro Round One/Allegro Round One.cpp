#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <iostream>
using namespace std;
int main(void)
{
	ALLEGRO_DISPLAY *display = NULL;
	if (!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "Failed to initalize Allegro", NULL, NULL);
		return -1;
	}
	display = al_create_display(640, 480);

	if (!display)
	{
		al_show_native_message_box(NULL, NULL, NULL, "Failed to initalize Display", NULL, NULL);
		return -1;
	}

	al_init_font_addon();
	al_init_ttf_addon();

	ALLEGRO_FONT *fontArial24 = al_load_font("arial.ttf", 24, 0);
	ALLEGRO_FONT *fontcalibri36 = al_load_font("calibri.ttf", 36, 0);
	ALLEGRO_FONT *fontarial18 = al_load_font("arial.ttf", 18, 0);

	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(fontArial24, al_map_rgb(255, 0, 255), 50, 50, 0, "Hellow world, this is 24 Point");
	al_draw_text(fontarial18, al_map_rgb(244, 123, 44), 640 / 2, 480 / 2, ALLEGRO_ALIGN_CENTER, "This text is centred");
	al_draw_text(fontcalibri36, al_map_rgb(23, 244, 55), 620, 350, ALLEGRO_ALIGN_RIGHT, "This is right aligned and 36 Point");
	
	
	int screen_w = al_get_display_width(display);
	int screen_h = al_get_display_height(display);
	cout << screen_h << " and " << screen_w << endl;

	al_draw_textf(fontarial18, al_map_rgb(255, 255, 255), screen_w / 2, 400, ALLEGRO_ALIGN_CENTRE, "TEXT with variable output (textf): Screen width and height = %i / %i", screen_w, screen_h);
	al_flip_display();
	al_rest(5);
	al_destroy_display(display);
	return 0;
}

