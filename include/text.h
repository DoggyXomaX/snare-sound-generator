#ifndef __PROGRAM_TEXT_H__
#define __PROGRAM_TEXT_H__

#include "args.h"

#ifndef PROGRAM_NAME
#define PROGRAM_NAME "snare_sound.exe"
#endif

// https://stackoverflow.com/questions/1562074/how-do-i-show-the-value-of-a-define-at-compile-time
#define XSTR(x) STR(x)
#define STR(x) #x

#if LANG_RU
    #define TEXT_HELP_STRING_HEADER                "Утилита для генерации случайного набора кусков разных частот."
    #define TEXT_HELP_STRING_USAGE                 "Использование:"
    #define TEXT_HELP_STRING_PARAM_FILENAME        "имя_файла"
    #define TEXT_HELP_STRING_PARAM_BITS_PER_SAMPLE "количество_бит"
    #define TEXT_HELP_STRING_PARAM_SAMPLE_RATE     "частота_дескретизации"
    #define TEXT_HELP_STRING_PARAM_CHANNEL_COUNT   "количество_каналов"
    #define TEXT_HELP_STRING_PARAM_MAX_FREQUENCY   "макс_частота"
    #define TEXT_HELP_STRING_PARAM_MIN_FREQUENCY   "мин_частота"
    #define TEXT_HELP_STRING_PARAM_COUNT           "количество_кусков"
    #define TEXT_HELP_STRING_PARAM_DURATION        "длительность"
    #define TEXT_HELP_STRING_PARAM_SEED            "ключ_генерации"
    #define TEXT_HELP_STRING_UNIX_TIME             "Текущее UNIX время"
    #define TEXT_HELP_STRING_STANDARD              "Стандартные значения:"
    #define TEXT_HELP_STRING_EXAMPLE               "Пример:"

    #define TEXT_CREATE_STRUCTURE "Создаем структуру"
    #define TEXT_SET_PARAMS "Задаем параметры и выделяем память для генерации"
    #define TEXT_GENERATION "Генерация..."
    #define TEXT_BLOCK_N "Блок №%u, частота %.2llf\n"
    #define TEXT_FREE_MEM "Очищаем память"
    #define TEXT_RETURN_NOERROR "Завершено успешно!"
    #define TEXT_RETURN_ERROR "Завершено с ошибками."
    #define TEXT_INPUT_PARAMS \
        "Начинаем генерировать файл...\n"    \
        "Входные параметры:\n"               \
        "    Имя файла: %s\n"                \
        "    Количество бит на сэпмл: %u\n"  \
        "    Частота дескретизации: %u\n"    \
        "    Количество каналов: %u\n"       \
        "    Максимальная частота: %.2llf\n" \
        "    Минимальная частота: %.2llf\n"  \
        "    Количество частей: %u\n"        \
        "    Длительность: %.2llf\n"         \
        "    Ключ генерации: %u\n"
    #define TEXT_WAV_REALLOCATE "Выделяем %u чанков(блоков)\n"
    #define TEXT_WAV_UNIT_NULL "WaveUnit_Save: unit не определен (null)"
    #define TEXT_WAV_PATH_NULL "WaveUnit_Save: path не определен (null)"
    #define TEXT_WAV_FAILED_OPEN_FILE "Не удалось открыть файл \"%s\". Ошибка №%d: %s\n"
#else
    #define TEXT_HELP_STRING_HEADER                "A utility for generating a random set of chunks of different frequencies."
    #define TEXT_HELP_STRING_USAGE                 "Usage:"
    #define TEXT_HELP_STRING_PARAM_FILENAME        "filename"
    #define TEXT_HELP_STRING_PARAM_BITS_PER_SAMPLE "bits_per_sample"
    #define TEXT_HELP_STRING_PARAM_SAMPLE_RATE     "sample_rate"
    #define TEXT_HELP_STRING_PARAM_CHANNEL_COUNT   "channel_count"
    #define TEXT_HELP_STRING_PARAM_MAX_FREQUENCY   "max_frequency"
    #define TEXT_HELP_STRING_PARAM_MIN_FREQUENCY   "min_frequency"
    #define TEXT_HELP_STRING_PARAM_COUNT           "slice_count"
    #define TEXT_HELP_STRING_PARAM_DURATION        "duration"
    #define TEXT_HELP_STRING_PARAM_SEED            "seed"
    #define TEXT_HELP_STRING_UNIX_TIME             "Current UNIX time"
    #define TEXT_HELP_STRING_STANDARD              "Default values:"
    #define TEXT_HELP_STRING_EXAMPLE               "Example:"
    
    #define TEXT_CREATE_STRUCTURE "Creating structure"
    #define TEXT_SET_PARAMS "Set params and allocate memory for generation"
    #define TEXT_GENERATION "Generating..."
    #define TEXT_BLOCK_N "Block #%u, frequency %.2llf\n"
    #define TEXT_FREE_MEM "Free memory"
    #define TEXT_RETURN_NOERROR "Completed successfully!"
    #define TEXT_RETURN_ERROR "Completed with errors."
    #define TEXT_INPUT_PARAMS \
        "Prepare to generate file...\n" \
        "Input params:\n"               \
        "    Filename: %s\n"            \
        "    Bits per sample: %u\n"     \
        "    Sample rate: %u\n"         \
        "    Channel count: %u\n"       \
        "    Max frequency: %.2llf\n"   \
        "    Min frequency: %.2llf\n"   \
        "    Slice count: %u\n"         \
        "    Duration: %.2llf\n"        \
        "    Seed: %u\n"
    #define TEXT_WAV_REALLOCATE "Allocating %u chunks(blocks)\n"
    #define TEXT_WAV_UNIT_NULL "WaveUnit_Save: unit is null"
    #define TEXT_WAV_PATH_NULL "WaveUnit_Save: path is null"
    #define TEXT_WAV_FAILED_OPEN_FILE "Failed to open file \"%s\". Error #%d: %s\n"
#endif

#define TEXT_HELP_STRING (\
    TEXT_HELP_STRING_HEADER "\n"                                                                                     \
    TEXT_HELP_STRING_USAGE "\n"                                                                                      \
    "    " PROGRAM_NAME "\n"                                                                                         \
    "        [" ARG_FILENAME_SHORT "|" ARG_FILENAME " <" TEXT_HELP_STRING_PARAM_FILENAME ">]\n"                      \
    "        [" ARG_BITS_PER_SAMPLE_SHORT "|" ARG_BITS_PER_SAMPLE " <" TEXT_HELP_STRING_PARAM_BITS_PER_SAMPLE ">]\n" \
    "        [" ARG_SAMPLE_RATE_SHORT "|" ARG_SAMPLE_RATE " <" TEXT_HELP_STRING_PARAM_SAMPLE_RATE ">]\n"             \
    "        [" ARG_CHANNEL_COUNT_SHORT "|" ARG_CHANNEL_COUNT " <" TEXT_HELP_STRING_PARAM_CHANNEL_COUNT ">]\n"       \
    "        [" ARG_MAX_FREQUENCY_SHORT "|" ARG_MAX_FREQUENCY " <" TEXT_HELP_STRING_PARAM_MAX_FREQUENCY ">]\n"       \
    "        [" ARG_MIN_FREQUENCY_SHORT "|" ARG_MIN_FREQUENCY " <" TEXT_HELP_STRING_PARAM_MIN_FREQUENCY ">]\n"       \
    "        [" ARG_COUNT_SHORT "|" ARG_COUNT " <" TEXT_HELP_STRING_PARAM_COUNT ">]\n"                               \
    "        [" ARG_DURATION_SHORT "|" ARG_DURATION " <" TEXT_HELP_STRING_PARAM_DURATION ">]\n"                      \
    "        [" ARG_SEED_SHORT "|" ARG_SEED " <" TEXT_HELP_STRING_PARAM_SEED ">]\n"                                  \
    "    " PROGRAM_NAME " [" ARG_HELP_SHORT "|" ARG_HELP "|" ARG_HELP_ALT "]\n"                                      \
    TEXT_HELP_STRING_STANDARD "\n"                                                                                   \
    "    " TEXT_HELP_STRING_PARAM_FILENAME ": " DEFAULT_FILENAME "\n"                                                \
    "    " TEXT_HELP_STRING_PARAM_BITS_PER_SAMPLE ": " XSTR(DEFAULT_BITS_PER_SAMPLE) "\n"                            \
    "    " TEXT_HELP_STRING_PARAM_SAMPLE_RATE ": " XSTR(DEFAULT_SAMPLE_RATE) "\n"                                    \
    "    " TEXT_HELP_STRING_PARAM_CHANNEL_COUNT ": " XSTR(DEFAULT_CHANNEL_COUNT) "\n"                                \
    "    " TEXT_HELP_STRING_PARAM_MAX_FREQUENCY ": " XSTR(DEFAULT_MAX_FREQUENCY) "\n"                                \
    "    " TEXT_HELP_STRING_PARAM_MIN_FREQUENCY ": " XSTR(DEFAULT_MIN_FREQUENCY) "\n"                                \
    "    " TEXT_HELP_STRING_PARAM_COUNT ": " XSTR(DEFAULT_COUNT) "\n"                                                \
    "    " TEXT_HELP_STRING_PARAM_DURATION ": " XSTR(DEFAULT_DURATION) "\n"                                          \
    "    " TEXT_HELP_STRING_PARAM_SEED ": " TEXT_HELP_STRING_UNIX_TIME "\n"                                          \
    TEXT_HELP_STRING_EXAMPLE "\n"                                                                                    \
    "    " PROGRAM_NAME " \\\n"                                                                                      \
    "        " ARG_FILENAME_SHORT " sound0.wav \\\n"                                                                 \
    "        " ARG_SAMPLE_RATE_SHORT " 48000 \\\n"                                                                   \
    "        " ARG_MIN_FREQUENCY_SHORT " 220 \\\n"                                                                   \
    "        " ARG_MAX_FREQUENCY_SHORT " 440 \\\n"                                                                   \
    "        " ARG_COUNT_SHORT " 16 \\\n"                                                                            \
    "        " ARG_SEED_SHORT " 12345678\n"                                                                          \
    "    " PROGRAM_NAME " " ARG_FILENAME_SHORT " sound1.wav")

#endif