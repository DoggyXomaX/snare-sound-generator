#include "args.h"

#define ArgIs(a, x) (strcmp((a), x##_SHORT) == 0 || strcmp((a), x) == 0)

bool IsHelp(int argc, char *argv[]) {
    return argc > 1 && (
        ArgIs(argv[1], ARG_HELP) ||
        strcmp(argv[1], ARG_HELP_ALT) == 0
    );
}

void GetArgs(int argc, char *argv[], ProgramArgs *args) {
    if (args == NULL) return;
    args->filename      = DEFAULT_FILENAME;
    args->bitsPerSample = DEFAULT_BITS_PER_SAMPLE;
    args->sampleRate    = DEFAULT_SAMPLE_RATE;
    args->numChannels   = DEFAULT_CHANNEL_COUNT;
    args->maxFrequency  = DEFAULT_MAX_FREQUENCY;
    args->minFrequency  = DEFAULT_MIN_FREQUENCY;
    args->sliceCount    = DEFAULT_COUNT;
    args->duration      = DEFAULT_DURATION;
    args->seed          = time(NULL);

    for (int i = 1; i < argc; i += 2) {
        if (i + 1 == argc) return;
        const char *value = argv[i + 1];

             if (ArgIs(argv[i], ARG_FILENAME))        args->filename = value;
        else if (ArgIs(argv[i], ARG_BITS_PER_SAMPLE)) args->bitsPerSample = abs(atoi(value));
        else if (ArgIs(argv[i], ARG_SAMPLE_RATE))     args->sampleRate = abs(atoi(value));
        else if (ArgIs(argv[i], ARG_CHANNEL_COUNT))   args->numChannels = abs(atoi(value));
        else if (ArgIs(argv[i], ARG_MAX_FREQUENCY))   args->maxFrequency = fabs(atof(value));
        else if (ArgIs(argv[i], ARG_MIN_FREQUENCY))   args->minFrequency = fabs(atof(value));
        else if (ArgIs(argv[i], ARG_COUNT))           args->sliceCount = abs(atoi(value));
        else if (ArgIs(argv[i], ARG_DURATION))        args->duration = fabs(atof(value));
        else if (ArgIs(argv[i], ARG_SEED))            args->seed = atoi(value);
    }

    if (args->maxFrequency < args->minFrequency)
        SwapDouble(args->maxFrequency, args->minFrequency);
}

void PrintArgs(ProgramArgs *args) {
    printf_s(TEXT_INPUT_PARAMS,
        args->filename,
        args->bitsPerSample,
        args->sampleRate,
        args->numChannels,
        args->maxFrequency,
        args->minFrequency,
        args->sliceCount,
        args->duration,
        args->seed
    );
}

void PrintHelp() {
    printf_s(TEXT_HELP_STRING,
        ARG_FILENAME_SHORT, ARG_FILENAME,
        ARG_BITS_PER_SAMPLE_SHORT, ARG_BITS_PER_SAMPLE,
        ARG_SAMPLE_RATE_SHORT, ARG_SAMPLE_RATE,
        ARG_MAX_FREQUENCY_SHORT, ARG_MAX_FREQUENCY,
        ARG_MIN_FREQUENCY_SHORT, ARG_MIN_FREQUENCY,
        ARG_COUNT_SHORT, ARG_COUNT,
        ARG_DURATION_SHORT, ARG_DURATION,
        ARG_SEED_SHORT, ARG_SEED,
        ARG_HELP_SHORT, ARG_HELP, ARG_HELP_ALT,
        DEFAULT_FILENAME,
        DEFAULT_BITS_PER_SAMPLE,
        DEFAULT_SAMPLE_RATE,
        DEFAULT_CHANNEL_COUNT,
        DEFAULT_MAX_FREQUENCY,
        DEFAULT_MIN_FREQUENCY,
        DEFAULT_COUNT,
        DEFAULT_DURATION,
        ARG_FILENAME_SHORT,
        ARG_SAMPLE_RATE_SHORT,
        ARG_MIN_FREQUENCY_SHORT,
        ARG_MAX_FREQUENCY_SHORT,
        ARG_COUNT_SHORT,
        ARG_SEED_SHORT,
        ARG_FILENAME_SHORT
    );
}
