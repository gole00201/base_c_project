/**
 * @file util.h
 * @author Volkov Egor
 * @brief Утилсы для работы с данными
 * @version 0.1
 * @date 2024-05-23
 * @copyright Copyright (c) 2024
 */

#ifndef UTIL
#define UTIL

#include <stdio.h>
#include <string.h>
#define FILE_PATH "-f"
#define MOUNTH    "-m"
#define HELP      "-h"

/**
 * @brief Структурный тип описывающий строку данных
 */
typedef struct DATA_ROW_t
{
    int year;
    int mouth;
    int day;
    int hour;
    int minute;
    int temp;
}DATA_ROW_t;


/**
 * @brief Струткутра сосстояния программы
 */
typedef struct SCOPE_t
{
    /**
     * @brief Путь к файлу с данными
     */
    char* csv_path;
    /**
     * @brief Необходимый месяц для рассчета
     */
    int need_mouth;

    /**
     * @brief Прочитанные данные (массив)
     */
    DATA_ROW_t* data;

    /**
     * @brief Количество записей
     */
    int data_cnt;

}SCOPE_t;

/**
 * @brief Парсер аргументов командной строки
 * @param argc
 * @param argv
 * @param state структура хронящая состояние программы на инициации
 * @return int 0 - файл найден , 1 - не найден файл
 */
int parse_args(int argc, char** argv, SCOPE_t* state);

/**
 * @brief Вывод использования программы
 */
void usage();

/**
 * @brief Вывод на этран строки данных
 * @param row строка данных
 */
void printf_row(DATA_ROW_t row);


/**
 * @brief Вывод на экран всех данных
 * @param data
 */
void printf_data(SCOPE_t data);


/**
 * @brief Конвертация числа в месяц
 * @param dist строка
 * @param number номер месяца
 */
void int_to_mouth_name(char* dist, int number);

#endif