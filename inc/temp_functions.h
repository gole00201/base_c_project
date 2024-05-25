/**
 * @file temp_functions.h
 * @author Volkov Egor
 * @brief Рассчет статистики данных
 * @version 0.1
 * @date 2024-05-23
 * @copyright Copyright (c) 2024
 */

#ifndef TEMP_F
#define TEMP_F


#include <util.h>


/**
 * @brief Статистика по месяца
 * @param state контекст исполнения
 */
void stats_per_mouth(SCOPE_t state);

/**
 * @brief Статистика за год
 * @param state контекст исполнения
 */
void stats_per_year(SCOPE_t state);

/**
 * @brief Статистика за выбранный месяц
 * @param state контекст исполнения
 */
void stats_one_mouth(SCOPE_t state);
#endif
