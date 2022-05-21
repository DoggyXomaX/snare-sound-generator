#ifndef __PROGRAM_TEXT_H__
#define __PROGRAM_TEXT_H__

#include "args.h"

#ifndef PROGRAM_NAME
#define PROGRAM_NAME "snare_sound.exe"
#endif

// https://stackoverflow.com/questions/1562074/how-do-i-show-the-value-of-a-define-at-compile-time
#define XSTR(x) STR(x)
#define STR(x) #x

// Как с этим препроцессором договориться? Почему мне надо всё это в printf_s сувать?!
// Дефайны из args.h на этапе препроцессора как-будто не видны
#if LANG_RU
    #define TEXT_HELP_STRING (\
        "Утилита для генерации случайного набора кусков разных частот.\n"                    \
        "Использование:\n"                                                                   \
        "    " PROGRAM_NAME "\n"                                                             \
        "        [" ARG_FILENAME_SHORT "|" ARG_FILENAME " <имя_файла>]\n"                    \
        "        [" ARG_BITS_PER_SAMPLE_SHORT "|" ARG_BITS_PER_SAMPLE " <количество_бит>]\n" \
        "        [" ARG_SAMPLE_RATE_SHORT "|" ARG_SAMPLE_RATE " <частота_дескретизации>]\n"  \
        "        [" ARG_CHANNEL_COUNT_SHORT "|" ARG_CHANNEL_COUNT " <количество_каналов>]\n" \
        "        [" ARG_MAX_FREQUENCY_SHORT "|" ARG_MAX_FREQUENCY " <макс_частота>]\n"       \
        "        [" ARG_MIN_FREQUENCY_SHORT "|" ARG_MIN_FREQUENCY " <мин_частота>]\n"        \
        "        [" ARG_COUNT_SHORT "|" ARG_COUNT " <количество_кусков>]\n"                  \
        "        [" ARG_DURATION_SHORT "|" ARG_DURATION " <длительность>]\n"                 \
        "        [" ARG_SEED_SHORT "|" ARG_SEED " <ключ_генерации>]\n"                       \
        "    " PROGRAM_NAME " [" ARG_HELP_SHORT "|" ARG_HELP "|" ARG_HELP_ALT "]\n"          \
        "Стандартные значения:\n"                                                            \
        "    имя_файла: " DEFAULT_FILENAME "\n"                                              \
        "    количество_бит: " XSTR(DEFAULT_BITS_PER_SAMPLE) "\n"                            \
        "    частота_дескретизации: " XSTR(DEFAULT_SAMPLE_RATE) "\n"                         \
        "    количество_каналов: " XSTR(DEFAULT_CHANNEL_COUNT) "\n"                          \
        "    макс_частота: " XSTR(DEFAULT_MAX_FREQUENCY) "\n"                                \
        "    мин_частота: " XSTR(DEFAULT_MIN_FREQUENCY) "\n"                                 \
        "    количество_кусков: " XSTR(DEFAULT_COUNT) "\n"                                   \
        "    длительность: " XSTR(DEFAULT_DURATION) "\n"                                     \
        "    ключ_генерации: Текущее UNIX время\n"                                           \
        "Пример:\n"                                                                          \
        "    " PROGRAM_NAME " \\\n"                                                           \
        "        " ARG_FILENAME_SHORT " sound0.wav \\\n"                                     \
        "        " ARG_SAMPLE_RATE_SHORT " 48000 \\\n"                                       \
        "        " ARG_MIN_FREQUENCY_SHORT " 220 \\\n"                                       \
        "        " ARG_MAX_FREQUENCY_SHORT " 440 \\\n"                                       \
        "        " ARG_COUNT_SHORT " 16 \\\n"                                                \
        "        " ARG_SEED_SHORT " 12345678\n"                                              \
        "    " PROGRAM_NAME " " ARG_FILENAME_SHORT " sound1.wav")
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
    #define TEXT_HELP_STRING (\
        "A utility for generating a random set of chunks of different frequencies.\n"         \
        "Usage:\n"                                                                            \
        "    " PROGRAM_NAME "\n"                                                              \
        "        [" ARG_FILENAME_SHORT "|" ARG_FILENAME " <filename>]\n"                      \
        "        [" ARG_BITS_PER_SAMPLE_SHORT "|" ARG_BITS_PER_SAMPLE " <bits_per_sample>]\n" \
        "        [" ARG_SAMPLE_RATE_SHORT "|" ARG_SAMPLE_RATE " <sample_rate>]\n"             \
        "        [" ARG_CHANNEL_COUNT_SHORT "|" ARG_CHANNEL_COUNT " <channel_count>]\n"       \
        "        [" ARG_MAX_FREQUENCY_SHORT "|" ARG_MAX_FREQUENCY " <max_frequency>]\n"       \
        "        [" ARG_MIN_FREQUENCY_SHORT "|" ARG_MIN_FREQUENCY " <min_frequency>]\n"       \
        "        [" ARG_COUNT_SHORT "|" ARG_COUNT " <slice_count>]\n"                         \
        "        [" ARG_DURATION_SHORT "|" ARG_DURATION " <duration>]\n"                      \
        "        [" ARG_SEED_SHORT "|" ARG_SEED " <seed>]\n"                                  \
        "    " PROGRAM_NAME " [" ARG_HELP_SHORT "|" ARG_HELP "|" ARG_HELP_ALT "]\n"           \
        "Default values:\n"                                                                   \
        "    filename: " DEFAULT_FILENAME "\n"                                                \
        "    bits_per_sample: " XSTR(DEFAULT_BITS_PER_SAMPLE) "\n"                            \
        "    sample_rate: " XSTR(DEFAULT_SAMPLE_RATE) "\n"                                    \
        "    channel_count: " XSTR(DEFAULT_CHANNEL_COUNT) "\n"                                \
        "    max_frequency: " XSTR(DEFAULT_MAX_FREQUENCY) "\n"                                \
        "    min_frequency: " XSTR(DEFAULT_MIN_FREQUENCY) "\n"                                \
        "    slice_count: " XSTR(DEFAULT_COUNT) "\n"                                          \
        "    duration: " XSTR(DEFAULT_DURATION) "\n"                                          \
        "    seed: Current UNIX time\n"                                                       \
        "Example:\n"                                                                          \
        "    " PROGRAM_NAME " \\\n"                                                            \
        "        " ARG_FILENAME_SHORT " sound0.wav \\\n"                                      \
        "        " ARG_SAMPLE_RATE_SHORT " 48000 \\\n"                                        \
        "        " ARG_MIN_FREQUENCY_SHORT " 220 \\\n"                                        \
        "        " ARG_MAX_FREQUENCY_SHORT " 440 \\\n"                                        \
        "        " ARG_COUNT_SHORT " 16 \\\n"                                                 \
        "        " ARG_SEED_SHORT " 12345678\n"                                               \
        "    " PROGRAM_NAME " " ARG_FILENAME_SHORT " sound1.wav")
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

#endif