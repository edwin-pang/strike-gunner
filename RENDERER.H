#ifndef RENDERER_H
#define RENDERER_H

#include "TYPES.H"
#include "RASTER.H"
#include "MODEL.H"
#include "font.h"
void render_panel_left(UINT32 *base);
void render_panel_right(UINT32 *base);
void render_all_32(Model *model, UINT32 *base);
void render_all_8(Model *model, UINT8 *base);
void render_all_16(Model *model, UINT16 *base);
void render();
void render_score(Model *model, UINT8 *base);

#endif