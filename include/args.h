#ifndef __PROGRAM_ARGS_H__
#define __PROGRAM_ARGS_H__

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "text.h"
#include "swap.h"

#define DEFAULT_FILENAME        "a.wav"
#define DEFAULT_BITS_PER_SAMPLE 8
#define DEFAULT_SAMPLE_RATE     44100
#define DEFAULT_CHANNEL_COUNT   2
#define DEFAULT_MAX_FREQUENCY   220.0
#define DEFAULT_MIN_FREQUENCY   0.0
#define DEFAULT_COUNT           8
#define DEFAULT_DURATION        1.0
#define DEFAULT_SEED            1234

#define ARG_HELP                  "--help"
#define ARG_HELP_SHORT            "-h"
#define ARG_HELP_ALT              "/?"
#define ARG_FILENAME              "--filename"
#define ARG_FILENAME_SHORT        "-o"
#define ARG_BITS_PER_SAMPLE       "--bits-per-sample"
#define ARG_BITS_PER_SAMPLE_SHORT "-b"
#define ARG_SAMPLE_RATE           "--rate"
#define ARG_SAMPLE_RATE_SHORT     "-r"
#define ARG_CHANNEL_COUNT         "--channels"
#define ARG_CHANNEL_COUNT_SHORT   "-c"
#define ARG_MAX_FREQUENCY         "--max"
#define ARG_MAX_FREQUENCY_SHORT   "-h"
#define ARG_MIN_FREQUENCY         "--min"
#define ARG_MIN_FREQUENCY_SHORT   "-l"
#define ARG_COUNT                 "--count"
#define ARG_COUNT_SHORT           "-n"
#define ARG_DURATION              "--duration"
#define ARG_DURATION_SHORT        "-d"
#define ARG_SEED                  "--seed"
#define ARG_SEED_SHORT            "-s"

typedef struct {
    const char *filename;
    uint16_t bitsPerSample;
    uint32_t sampleRate;
    uint32_t numChannels;
    double maxFrequency;
    double minFrequency;
    uint32_t sliceCount;
    double duration;
    uint32_t seed;
} ProgramArgs;

bool IsHelp(int, char*[]);
void GetArgs(int, char*[], ProgramArgs*);
void PrintArgs(ProgramArgs*);
void PrintHelp(void);

#endif