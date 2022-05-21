#ifndef __DXX_WAVE_H__
#define __DXX_WAVE_H__

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "wave_format.h"
#include "text.h"

typedef struct {
    uint32_t chunkId;
    uint32_t chunkSize;
    uint32_t format;
    uint32_t subchunk1Id;
    uint32_t subchunk1Size;
    uint16_t audioFormat;
    uint16_t numChannels;
    uint32_t sampleRate;
    uint32_t byteRate;
    uint16_t blockAlign;
    uint16_t bitsPerSample;
    uint32_t subchunk2Id;
    uint32_t subchunk2Size;
} WaveStruct;

typedef struct {
    WaveStruct wave;
    uint8_t *data;
    uint32_t numSamples;
} WaveUnit;

typedef struct {
    uint16_t numChannels;
    uint16_t bitsPerSample;
    uint32_t sampleRate;
    bool update;
    bool reallocateData;
} WaveArgs;

#define WAVEUNIT_NOARG16 UINT16_MAX
#define WAVEUNIT_NOARG UINT32_MAX
#define new(x) (x*)malloc(sizeof(x))
#define new_size(item,type,size) (type*)realloc(item, size);
#define get_uint32(x) *((uint32_t*)(x))

WaveUnit *WaveUnit_Create(void);
void WaveUnit_Update(WaveUnit*, bool);
void WaveUnit_Set(WaveUnit*, WaveArgs*);
void WaveUnit_Free(WaveUnit*);
errno_t WaveUnit_Save(WaveUnit*, const char*);

#endif