#include <X11/X.h>
#include <stdbool.h>
#define OLIVEC_IMPLEMENTATION
#include "../lib/olive.c"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../lib/stb_image_write.h"

#include <X11/Xlib.h>
#include <stdint.h>
#include <stdio.h>

#define WIDTH 800
#define HEIGHT 640

uint32_t paint_buffer[WIDTH * HEIGHT];
uint32_t show_buffer[WIDTH * HEIGHT];

int main(void) {
  // creating a window
  Display *display = XOpenDisplay(NULL);
  Window window = XCreateSimpleWindow(display, XDefaultRootWindow(display), 0,
                                      0, WIDTH, HEIGHT, 0, 0x000000, 0x000000);
  XStoreName(display, window, "First Window");
  XSelectInput(display, window, KeyPressMask | KeyReleaseMask);
  XMapWindow(display, window);

  // main loop
  while (1) {
    while (XPending(display) > 0) {
      XEvent event = {0};
      XNextEvent(display, &event);

      Olivec_Canvas canva = olivec_canvas(paint_buffer, WIDTH, HEIGHT, WIDTH);
      olivec_fill(canva, 0xffffffff);
      olivec_circle(canva, WIDTH / 2, HEIGHT / 2, 20, 0xff000ff);
    }
  }

  return 0;
}
