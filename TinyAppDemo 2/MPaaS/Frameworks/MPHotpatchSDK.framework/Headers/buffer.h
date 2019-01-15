//
//  buffer.h
//  APMobileSecurity
//
//  Created by wenbi on 14-7-17.
//  Copyright (c) 2014年 Alipay. All rights reserved.
//

#ifndef APMobileSecurity_buffer_h
#define APMobileSecurity_buffer_h

#include <stdint.h>

typedef struct APSecBuffer
{
    size_t  length;
    uint8_t data[1];
} APSecBuffer, *APSecBufferRef;

#endif
