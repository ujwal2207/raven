#pragma once

#include <stdbool.h>

#include "air/air.h"
#include "air/air_config.h"
#include "air/air_io.h"

#include "input/input.h"

#include "util/time.h"

typedef struct input_air_bind_s
{
    input_t input;
    air_io_t air;
    air_config_t air_config;
    int state;
    air_bind_packet_t bind_packet;
    time_micros_t bind_packet_expires;
    time_micros_t send_response_at;
    bool bind_accepted;
    bool bind_confirmation_sent; // Wether the user has accepted the bind in this node
    bool bind_completed;
    int band_index; // for multiple band support
    time_micros_t switch_band_at;
} input_air_bind_t;

void input_air_bind_init(input_air_bind_t *input_air_bind, air_addr_t addr, air_config_t *air_config);