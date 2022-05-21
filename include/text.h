#ifndef __PROGRAM_TEXT_H__
#define __PROGRAM_TEXT_H__

#ifndef PROGRAM_NAME
#define PROGRAM_NAME "snare_sound.exe"
#endif

// Как с этим препроцессором договориться? Почему мне надо всё это в printf_s сувать?!
// Дефайны из args.h на этапе препроцессора как-будто не видны
#if LANG_RU
    #define TEXT_HELP_STRING \
        "Утилита для генерации случайного набора кусков разных частот.\n" \
        "Использование:\n"                                                \
        "    " PROGRAM_NAME "\n"                                          \
        "        [%s | %s <имя_файла>]\n"                                 \
        "        [%s | %s <количество_бит>\n"                             \
        "        [%s | %s <частота_дескретизации>]\n"                     \
        "        [%s | %s <количество_каналов>]\n"                        \
        "        [%s | %s <макс_частота>]\n"                              \
        "        [%s | %s <мин_частота>]\n"                               \
        "        [%s | %s <количество_кусков>]\n"                         \
        "        [%s | %s <длительность>]\n"                              \
        "        [%s | %s <ключ_генерации>]\n"                            \
        "    " PROGRAM_NAME " [%s] [%s] [%s]\n"                           \
        "Стандартные значения:\n"                                         \
        "    имя_файла: %s\n"                                             \
        "    количество_бит: %u\n"                                        \
        "    частота_дескретизации: %u\n"                                 \
        "    количество_каналов: %u\n"                                    \
        "    макс_частота: %.2llf\n"                                      \
        "    мин_частота: %.2llf\n"                                       \
        "    количество_кусков: %u\n"                                     \
        "    длительность: %.2llf\n"                                      \
        "    ключ_генерации: Текущее UNIX время\n"                        \
        "Пример:\n"                                                       \
        "    " PROGRAM_NAME "\\\n"                                        \
        "        %s sound0.wav \\\n"                                      \
        "        %s 48000 \\\n"                                           \
        "        %s 220 \\\n"                                             \
        "        %s 440 \\\n"                                             \
        "        %s 16 \\\n"                                              \
        "        %s 12345678\n"                                           \
        "    " PROGRAM_NAME " %s sound1.wav"
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
    #define TEXT_HELP_STRING \
        "A utility for generating a random set of chunks of different frequencies.\n" \
        "Usage:\n"                                                                    \
        "    " PROGRAM_NAME "\n"                                                      \
        "        [%s | %s <filename>]\n"                                              \
        "        [%s | %s <bits_per_sample>\n"                                        \
        "        [%s | %s <sample_rate>]\n"                                           \
        "        [%s | %s <channel_count>]\n"                                         \
        "        [%s | %s <max_frequency>]\n"                                         \
        "        [%s | %s <min_frequency>]\n"                                         \
        "        [%s | %s <slice_count>]\n"                                           \
        "        [%s | %s <duration>]\n"                                              \
        "        [%s | %s <seed>]\n"                                                  \
        "    " PROGRAM_NAME " [%s] [%s] [%s]\n"                                       \
        "Default values:\n"                                                           \
        "    filename: %s\n"                                                          \
        "    bits_per_sample: %u\n"                                                   \
        "    sample_rate: %u\n"                                                       \
        "    channel_count: %u\n"                                                     \
        "    max_frequency: %.2llf\n"                                                 \
        "    min_frequency: %.2llf\n"                                                 \
        "    slice_count: %u\n"                                                       \
        "    duration: %.2llf\n"                                                      \
        "    seed: Current UNIX time\n"                                               \
        "Example:\n"                                                                  \
        "    " PROGRAM_NAME "\\\n"                                                    \
        "        %s sound0.wav \\\n"                                                  \
        "        %s 48000 \\\n"                                                       \
        "        %s 220 \\\n"                                                         \
        "        %s 440 \\\n"                                                         \
        "        %s 16 \\\n"                                                          \
        "        %s 12345678\n"                                                       \
        "    " PROGRAM_NAME " %s sound1.wav"
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