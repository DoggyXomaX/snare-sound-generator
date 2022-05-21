#include "wav.h"

WaveUnit *WaveUnit_Create() {
    WaveUnit *unit = new(WaveUnit);

    unit->wave.chunkId       = get_uint32("RIFF");
    unit->wave.chunkSize     = 36;
    unit->wave.format        = get_uint32("WAVE");
    unit->wave.subchunk1Id   = get_uint32("fmt ");
    unit->wave.subchunk1Size = 16;
    unit->wave.audioFormat   = WAVE_FORMAT_PCM;
    unit->wave.numChannels   = 1;
    unit->wave.sampleRate    = 44100;
    unit->wave.byteRate      = 44100;
    unit->wave.blockAlign    = 1;
    unit->wave.bitsPerSample = 8;
    unit->wave.subchunk2Id   = get_uint32("data");
    unit->wave.subchunk2Size = 0;

    unit->numSamples = 0;
    unit->data = NULL;

    return unit;
}

void WaveUnit_Update(WaveUnit *unit, bool reallocateData) {
    unit->wave.blockAlign    = unit->wave.numChannels * unit->wave.bitsPerSample / 8;
    unit->wave.subchunk2Size = unit->numSamples * unit->wave.blockAlign;
    unit->wave.chunkSize     = 4 + (8 + unit->wave.subchunk1Size) + (8 + unit->wave.subchunk2Size);
    unit->wave.byteRate      = unit->wave.sampleRate * unit->wave.blockAlign;

    if (reallocateData) {
        printf_s(TEXT_WAV_REALLOCATE, unit->wave.subchunk2Size);
        unit->data = new_size(unit->data, uint8_t, unit->wave.subchunk2Size);
    }
}

void WaveUnit_Set(WaveUnit *unit, WaveArgs *args) {
    if (args->bitsPerSample != WAVEUNIT_NOARG16)
        unit->wave.bitsPerSample = args->bitsPerSample;
    if (args->numChannels != WAVEUNIT_NOARG16)
        unit->wave.numChannels = args->numChannels;
    if (args->sampleRate != WAVEUNIT_NOARG)
        unit->wave.sampleRate = args->sampleRate;
    if (args->update)
        WaveUnit_Update(unit, args->reallocateData);
}

void WaveUnit_Free(WaveUnit *unit) {
    if (unit == NULL) return;
    if (unit->data != NULL) free(unit->data);
    free(unit);
}

errno_t WaveUnit_Save(WaveUnit *unit, const char *path) {
    if (unit == NULL) {
        puts(TEXT_WAV_UNIT_NULL);
        return EINVAL;
    }
    if (path == NULL) {
        puts(TEXT_WAV_PATH_NULL);
        return EINVAL;
    }

    FILE *waveFile;
    errno_t error = fopen_s(&waveFile, path, "wb");
    if (error) {
        printf_s(TEXT_WAV_FAILED_OPEN_FILE, path, error, strerror(error));
        return error;
    }

    fwrite(&unit->wave, sizeof(WaveStruct), 1, waveFile);
    fwrite(unit->data, unit->wave.subchunk2Size, 1, waveFile);

    fclose(waveFile);
}
