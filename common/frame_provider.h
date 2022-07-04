#pragma once

#include "graphics.h"

class FrameProvider {
public:
    virtual image_raw8_t provide_frame() = 0;
    virtual void set_frame(image_t) = 0;

};