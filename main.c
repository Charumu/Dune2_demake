#include "libki/consts.h"
#include "libki/structs.h"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/bitmap.h>
#include <allegro5/bitmap_draw.h>
#include <allegro5/bitmap_io.h>
#include <allegro5/events.h>
#include <allegro5/mouse.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void edjednostka(JEDNOSTKA *j1) { // funkcja do zmiany pozycji
}
int main() {
  unsigned int zaznaczone[3];
  int power = 0;
  bool budowanie = false;
  int campoz[2] = {0, 0};      // pozycja kamery
  GRID *map[MapSize][MapSize]; // tworzenie mapy
  srand(time(NULL));
  for (int i = 0; i < MapSize; i++) {
    for (int j = 0; j < MapSize; j++) {
      map[i][j] = (GRID *)malloc(sizeof(GRID));
      if (i == 0)
        map[i][j]->typ[0] = 1;
      else if (j == 0)
        map[i][j]->typ[0] = 1;
      else if (i == MapSize - 1)
        map[i][j]->typ[0] = 1;
      else if (j == MapSize - 1)
        map[i][j]->typ[0] = 1;
      else
        map[i][j]->typ[0] = (rand() & 1) + 1;
      map[i][j]->typ[1] = 0;
      map[i][j]->el = NULL;
    }
  }
  for (int lel = 0; lel < 8; lel++) {
    for (int i = 1; i < MapSize - 1; i++) {
      for (int j = 1; j < MapSize - 1; j++) {
        if (map[i][j]->typ[0] == 1 && map[i - 1][j]->typ[0] == 2 &&
            map[i + 1][j]->typ[0] == 2 && map[i][j + 1]->typ[0] == 2)
          map[i][j]->typ[0] = 2;
        if (map[i][j]->typ[0] == 2 && map[i - 1][j]->typ[0] == 1 &&
            map[i + 1][j]->typ[0] == 1 && map[i][j + 1]->typ[0] == 1)
          map[i][j]->typ[0] = 1;

        if (map[i][j]->typ[0] == 1 && map[i][j - 1]->typ[0] == 2 &&
            map[i + 1][j]->typ[0] == 2 && map[i][j + 1]->typ[0] == 2)
          map[i][j]->typ[0] = 2;
        if (map[i][j]->typ[0] == 2 && map[i][j - 1]->typ[0] == 1 &&
            map[i + 1][j]->typ[0] == 1 && map[i][j + 1]->typ[0] == 1)
          map[i][j]->typ[0] = 1;

        if (map[i][j]->typ[0] == 1 && map[i][j - 1]->typ[0] == 2 &&
            map[i - 1][j]->typ[0] == 2 && map[i][j + 1]->typ[0] == 2)
          map[i][j]->typ[0] = 2;
        if (map[i][j]->typ[0] == 2 && map[i][j - 1]->typ[0] == 1 &&
            map[i - 1][j]->typ[0] == 1 && map[i][j + 1]->typ[0] == 1)
          map[i][j]->typ[0] = 1;

        if (map[i][j]->typ[0] == 1 && map[i][j - 1]->typ[0] == 2 &&
            map[i - 1][j]->typ[0] == 2 && map[i + 1][j]->typ[0] == 2)
          map[i][j]->typ[0] = 2;
        if (map[i][j]->typ[0] == 2 && map[i][j - 1]->typ[0] == 1 &&
            map[i - 1][j]->typ[0] == 1 && map[i + 1][j]->typ[0] == 1)
          map[i][j]->typ[0] = 1;
      }
    }
  }
  for (int lel = 0; lel < 8; lel++) {
    for (int i = 1; i < MapSize - 1; i++) {
      for (int j = 1; j < MapSize - 1; j++) {
        if (map[i][j]->typ[0] == 2 && map[i - 1][j]->typ[0] == 1 &&
            map[i + 1][j]->typ[0] == 1)
          map[i][j]->typ[0] = 1;
          if (map[i][j]->typ[0] == 2 && map[i][j - 1]->typ[0] == 1 &&
            map[i][j + 1]->typ[0] == 1)
          map[i][j]->typ[0] = 1;

      }
    }
  }
  for (int i = 1; i < MapSize - 1; i++) {
    for (int j = 1; j < MapSize - 1; j++) {
      if (map[i][j]->typ[0] == 2 && map[i - 1][j]->typ[0] == 1 &&
          map[i][j + 1]->typ[0] == 1)
        map[i][j]->typ[0] = 3;
      if (map[i][j]->typ[0] == 2 && map[i + 1][j]->typ[0] == 1 &&
          map[i][j + 1]->typ[0] == 1)
        map[i][j]->typ[0] = 5;
      if (map[i][j]->typ[0] == 2 && map[i - 1][j]->typ[0] == 1 &&
          map[i][j - 1]->typ[0] == 1)
        map[i][j]->typ[0] = 9;
      if (map[i][j]->typ[0] == 2 && map[i + 1][j]->typ[0] == 1 &&
          map[i][j - 1]->typ[0] == 1)
        map[i][j]->typ[0] = 11;
    }
  }
  for (int i = 1; i < MapSize - 1; i++) {
    for (int j = 1; j < MapSize - 1; j++) {
      if (map[i][j]->typ[0] == 2 && map[i][j + 1]->typ[0] == 1)
        map[i][j]->typ[0] = 4;
      if (map[i][j]->typ[0] == 2 && map[i - 1][j]->typ[0] == 1)
        map[i][j]->typ[0] = 6;
      if (map[i][j]->typ[0] == 2 && map[i + 1][j]->typ[0] == 1)
        map[i][j]->typ[0] = 8;
      if (map[i][j]->typ[0] == 2 && map[i][j - 1]->typ[0] == 1)
        map[i][j]->typ[0] = 10;
    }
  }
  for (int i = 1; i < MapSize - 1; i++) { // budowa początkowego cyard
    if (map[i][i]->typ[0] > 1 && map[i + 1][i]->typ[0] > 1 &&
        map[i][i + 1]->typ[0] > 1 && map[i + 1][i + 1]->typ[0] > 1) {
      map[i][i]->typ[1] = 2;
      map[i + 1][i]->typ[1] = 3;
      map[i][i + 1]->typ[1] = 4;
      map[i + 1][i + 1]->typ[1] = 5;
      if (i > 5) {
        campoz[0] = i - 6;
        campoz[1] = i - 4;
      }
      zaznaczone[0] = i;
      zaznaczone[1] = i;
      zaznaczone[2] = map[i][i]->typ[1];
      break;
    }
  }
  for (int i = MapSize - 1; i > 1; i--) { // budowa początkowego cyard
    if (map[i][i]->typ[0] > 1 && map[i + 1][i]->typ[0] > 1 &&
        map[i][i + 1]->typ[0] > 1 && map[i + 1][i + 1]->typ[0] > 1) {
      map[i][i]->typ[1] = 2;
      map[i + 1][i]->typ[1] = 3;
      map[i][i + 1]->typ[1] = 4;
      map[i + 1][i + 1]->typ[1] = 5;
      break;
    }
  }

  // respienie jednostki
  map[0][0]->el = (JEDNOSTKA *)malloc(sizeof(JEDNOSTKA));
  map[0][0]->typ[1] = Id_Jednostka;

  unsigned char rbudynku = 1;
  al_init();
  al_install_mouse(); // inicjalizacja
  al_init_image_addon();
  al_install_keyboard();
  ALLEGRO_TIMER *timer = al_create_timer(1.0 / 30.0);
  ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
  ALLEGRO_DISPLAY *disp = al_create_display(1398, 874);
  ALLEGRO_FONT *font = al_create_builtin_font();
  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(disp));
  al_register_event_source(queue, al_get_timer_event_source(timer));
  al_register_event_source(queue,
                           al_get_mouse_event_source()); // koniec inicjalizacji
  ALLEGRO_BITMAP *tekstury[] = {
      al_load_bitmap("./images/zaznaczenie.png"), // mapa bitowa tekstur
      al_load_bitmap("./images/zaznaczenie_nie.png"),
      al_load_bitmap("./images/pasek_gorny.png"),
      al_load_bitmap("./images/panel_boczny.png")};
  ALLEGRO_BITMAP *tekstury_ziemia[] = {
      al_load_bitmap("./images/slab.png"), // mapa bitowa podłoża
      al_load_bitmap("./images/piasek.png"),
      al_load_bitmap("./images/kamulec.png"),
      al_load_bitmap("./images/kamulec1.png"),
      al_load_bitmap("./images/kamulec2.png"),
      al_load_bitmap("./images/kamulec3.png"),
      al_load_bitmap("./images/kamulec4.png"),
      al_load_bitmap("./images/kamulec5.png"),
      al_load_bitmap("./images/kamulec6.png"),
      al_load_bitmap("./images/kamulec7.png"),
      al_load_bitmap("./images/kamulec8.png"),
      al_load_bitmap("./images/kamulec9.png")};
  ALLEGRO_BITMAP *tekstury_jednostki[][3] = {
      al_load_bitmap("./images/typo.png")};
  ALLEGRO_BITMAP *tekstury_budynki[] = {al_load_bitmap("./images/cyard0.png"),
                                        al_load_bitmap("./images/cyard1.png"),
                                        al_load_bitmap("./images/cyard2.png"),
                                        al_load_bitmap("./images/cyard3.png"),
                                        al_load_bitmap("./images/pplant0.png"),
                                        al_load_bitmap("./images/pplant1.png"),
                                        al_load_bitmap("./images/pplant2.png"),
                                        al_load_bitmap("./images/pplant3.png")};
  ALLEGRO_BITMAP *tekstury_przyciski[] = {
      al_load_bitmap("./images/wybuduj.png"), // mapa bitowa tekstur przycisków
      al_load_bitmap("./images/anuluj.png"),
      al_load_bitmap("./images/przycisk_fundament.png"),
      al_load_bitmap("./images/przycisk_power_plant.png"),
      al_load_bitmap("./images/przycisk_rafineria.png"),
      al_load_bitmap("./images/przycisk_baraki.png"),
      al_load_bitmap("./images/przycisk_fabryka.png")};

  bool done = false; // stan programu
  bool redraw = true;
  int znacznik[3] = {0, 0, 1}; // znacznik budowy
  ALLEGRO_EVENT event;
  float mouse[2]; // pozycja myszy
  al_start_timer(timer);
  while (1) { // pętla logiki gry
    al_wait_for_event(queue, &event);

    switch (event.type) {
    case ALLEGRO_EVENT_TIMER:
      redraw = true;
      break;
    case ALLEGRO_EVENT_MOUSE_AXES:
      mouse[0] = event.mouse.x; // pobranie pozycji myszy do zmiennych
      mouse[1] = event.mouse.y - 34;
      znacznik[0] = (int)(mouse[0] / TilePxs); // ustawienie znacznika
      znacznik[1] = (int)(mouse[1] / TilePxs) - 2;
      break;
    case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
      if(mouse[0] > 1124 && mouse[1] > 451 && mouse[0] < 1394 && mouse[1] < 503 && zaznaczone[2] == 2){
        budowanie = true;
      }
      if(mouse[0] > 1128 && mouse[1] > 392 && mouse[0] < 1389 && mouse[1] < 449 && zaznaczone[2] == 2){
        budowanie = false;
      }
      if(mouse[0] > 1128 && mouse[1] > 276 && mouse[0] < 1188 && mouse[1] < 415 && zaznaczone[2] == 2){
        rbudynku = 1;
      }
      if(mouse[0] > 1190 && mouse[1] > 276 && mouse[0] < 1250 && mouse[1] < 415 && zaznaczone[2] == 2){
        rbudynku = 2;
      }
      if (!znacznik[2] ||
          map[znacznik[0] + campoz[0]]
             [znacznik[1] + campoz[1]] // sprawdzanie czy pole zajęte
                 ->typ[1])
        break;
      switch (rbudynku) {
      case 0:
        break;
      case 1: // budowa fundamentu
        if (map[znacznik[0] + campoz[0]][znacznik[1] + campoz[1]]->typ[0] < 2 ||
            znacznik[0] > 14 || znacznik[1] < 0 || !znacznik[2] || !budowanie)
          break;
        map[znacznik[0] + campoz[0]][znacznik[1] + campoz[1]]->typ[0] =
            fundament;
            budowanie = false;
        break;
      case 2:
        if (map[znacznik[0] + campoz[0] + 1][znacznik[1] + campoz[1]]->typ[1]
        >
                1 ||
            map[znacznik[0] + campoz[0]][znacznik[1] + campoz[1] + 1]->typ[1]
            >
                1 ||
            map[znacznik[0] + campoz[0] + 1][znacznik[1] + campoz[1] + 1]
                    ->typ[1] > 1)
          break;
        if (map[znacznik[0] + campoz[0]][znacznik[1] + campoz[1]]->typ[0] ==
                1 ||
            map[znacznik[0] + campoz[0] + 1][znacznik[1] + campoz[1]]->typ[0]
            ==
                1 ||
            map[znacznik[0] + campoz[0]][znacznik[1] + campoz[1] + 1]->typ[0]
            ==
                1 ||
            map[znacznik[0] + campoz[0] + 1][znacznik[1] + campoz[1] + 1]
                    ->typ[0] == 1)
          break;
        if(budowanie){
        map[znacznik[0] + campoz[0]][znacznik[1] + campoz[1]]->typ[1] = 6;
        map[znacznik[0] + campoz[0] + 1][znacznik[1] + campoz[1]]->typ[1] =
        7; map[znacznik[0] + campoz[0]][znacznik[1] + campoz[1] + 1]->typ[1]
        = 8; map[znacznik[0] + campoz[0] + 1][znacznik[1] + campoz[1] +
        1]->typ[1] =
            9;
            budowanie = false;
            power += 100;
            }
      default:
        break;
      }
      break;
    case ALLEGRO_EVENT_KEY_DOWN:
      switch (event.keyboard.keycode) { // ruszanie kamerom
      case 84:
        if (campoz[1] - 1 >= 0)
          campoz[1] -= 1;
        break;
      case 85:
        if (campoz[1] + 10 < MapSize)
          campoz[1] += 1;
        break;
      case 82:
        if (campoz[0] - 1 >= 0)
          campoz[0] -= 1;
        break;
      case 83:
        if (campoz[0] + 15 < MapSize)
          campoz[0] += 1;
        break;
      default:
        break;
      }
      break;
    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      done = true;
      break;
    }

    if (done)
      break;

    if (redraw && al_is_event_queue_empty(queue)) { // rysowanie
      al_draw_bitmap(tekstury[2], 0, 0, 0);
      al_draw_bitmap(tekstury[3], 1053, 174, 0);
      if (zaznaczone[2] != 0) {
        switch (zaznaczone[2]) {
        case 2:
          al_draw_bitmap(tekstury_przyciski[0], 1124, 485, 0);
          al_draw_bitmap(tekstury_przyciski[1], 1128, 426, 0);
          al_draw_bitmap(tekstury_przyciski[2], 1128, 310, 0);
          al_draw_bitmap(tekstury_przyciski[3], 1190, 310, 0);
          al_draw_bitmap(tekstury_przyciski[4], 1252, 310, 0);
          al_draw_bitmap(tekstury_przyciski[5], 1314, 310, 0);
          al_draw_bitmap(tekstury_przyciski[6], 1128, 368, 0);
          break;

        default:
          break;
        }
      }
      if (znacznik[0] > 14 || znacznik[1] < 0)
        znacznik[2] = 0;
      else
        znacznik[2] = 1;
      for (int x = 0; x < 15 && (campoz[0]) + x < MapSize; x++) {
        for (int y = 0; y < 10 && (campoz[1]) + y < MapSize; y++) {
          al_draw_bitmap(
              tekstury_ziemia[(map[(campoz[0]) + x][(campoz[1]) + y]->typ[0])],
              TilePxs * x, TilePxs * y + TopHeight, 0);
          switch (map[(campoz[0]) + x][(campoz[1]) + y]->typ[1]) {
          case 0:
            break;
          case Id_Jednostka:
            al_draw_bitmap(tekstury_jednostki[0][0], TilePxs * x,
                           TilePxs * y + TopHeight, 0);
            break;
          default:
            al_draw_bitmap(
                tekstury_budynki[map[(campoz[0]) + x][(campoz[1]) + y]->typ[1] -
                                 2],
                TilePxs * x, TilePxs * y + TopHeight, 0);
            break;
          }
          if (!znacznik[2])
            continue;
          if (znacznik[2] > 0 && znacznik[2] < 3) {
            if (map[znacznik[0] + campoz[0]][znacznik[1] + campoz[1]]->typ[1])
              znacznik[2] = 2;
            else
              znacznik[2] = 1;
              if(budowanie)
            al_draw_bitmap(tekstury[znacznik[2] - 1], znacznik[0] * TilePxs,
                           znacznik[1] * TilePxs + 174, 0);
          }
        }
      }
      al_flip_display();

      redraw = false;
    }
  }

  al_destroy_font(font);
  al_destroy_display(disp);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);

  return 0;
}
