#ifndef OBSTACLE_DETECTOR_RENDERER_H_
#define OBSTACLE_DETECTOR_RENDERER_H_

#include <bot_vis/bot_vis.h>
#include <bot_param/param_client.h>
#include <bot_frames/bot_frames.h>

#ifdef __cplusplus
extern "C" {
#endif

void setup_renderer_tracks(BotViewer *viewer, int priority, lcm_t *_lcm, BotParam * param);

#ifdef __cplusplus
}
#endif

#endif
