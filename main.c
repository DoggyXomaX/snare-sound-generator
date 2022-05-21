#include <locale.h>

#include "include/swap.h"
#include "include/wav.h"

#define PROGRAM_NAME "snare_sound.exe"
#include "include/args.h"
#include "include/text.h"

int main(int argc, char *argv[]) {
    setlocale(LC_CTYPE, "Russian");

    if (IsHelp(argc, argv)) {
        PrintHelp();
        return 0;
    }

    ProgramArgs programArgs;
    GetArgs(argc, argv, &programArgs);
    PrintArgs(&programArgs);
    const double deltaFrequency = programArgs.maxFrequency - programArgs.minFrequency;
    srand(programArgs.seed);

    puts(TEXT_CREATE_STRUCTURE);
    WaveUnit *unit = WaveUnit_Create();
    WaveArgs args = {
        .bitsPerSample = programArgs.bitsPerSample,
        .numChannels = programArgs.numChannels,
        .sampleRate = programArgs.sampleRate,
        .update = true,
        .reallocateData = true
    };
    unit->numSamples = (uint32_t)(programArgs.duration * (double)programArgs.sampleRate);
    puts(TEXT_SET_PARAMS);

    WaveUnit_Set(unit, &args);

    puts(TEXT_GENERATION);
    uint32_t blockLength = unit->numSamples / programArgs.sliceCount;
    for (uint32_t a = 0; a < programArgs.sliceCount; a++) {
        double randCoef = (double)(rand()) / (double)(RAND_MAX);
        double randFrequency = programArgs.minFrequency + randCoef * deltaFrequency;
        printf_s(TEXT_BLOCK_N, a, randFrequency);
        for (uint32_t b = 0; b < blockLength; b++) {
            uint32_t i = a * blockLength + b;
            double coef = (double)i / (double)(unit->numSamples); // 0..1
            double value = (1.0 + sin(coef * M_PI * 2.0 * randFrequency)) * 0.5 * 255.0;
            for (uint32_t d = 0; d < unit->wave.blockAlign; d++)
                unit->data[i * unit->wave.blockAlign + d] = (uint8_t)value;
        }
    }

    errno_t error = WaveUnit_Save(unit, programArgs.filename);

    puts(TEXT_FREE_MEM);
    WaveUnit_Free(unit);

    puts(error ? TEXT_RETURN_ERROR : TEXT_RETURN_NOERROR);

    return error;
}
