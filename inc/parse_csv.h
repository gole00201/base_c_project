/**
 * @file parse_csv.h
 * @author Volkov Egor
 * @brief Парсер CSV таблицы с данными
 * @version 0.1
 * @date 2024-05-23
 * @copyright Copyright (c) 2024
 */
#ifndef PARSE_CSV
#define PARSE_CSV

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <temp_functions.h>
#include <util.h>
#include <stdlib.h>
/**
 * @brief Парсер csv файла с данными
 * @param state контекст исполнения
 * @return int 0 в случае ошибки, 1 в случае успеха
 */
int read_csv(SCOPE_t* state);


#endif