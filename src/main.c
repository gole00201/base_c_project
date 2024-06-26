#include <stdio.h>
#include <util.h>
#include <temp_functions.h>
#include <locale.h>

/**
 * @brief Инициализируем контекст исполнения
 */
SCOPE_t state = {
    .csv_path = NULL,
    .need_mouth = 0,
    .need_raw = 0,
    .need_sort = '\0'
};


int main(int argc, char** argv){
    #ifdef WIN32
    setlocale(LC_ALL, "ru-RU");
    #endif
    /**
     * @brief Разбираем аргументы
     */
    if(!parse_args(argc, argv, &state)){
        return 1;
    }

    /**
     * @brief Парсим таблицу
     */
    if(!read_csv(&state)){
        return 0;
    };

    /**
     * @brief Вывод конктреного месяца если нужно
     */
    if( state.need_mouth ){
        stats_one_mouth(state);
        free(state.data);
        return 0;
    }

    /**
     * @brief Сортируем если нужно
     */
    if( state.need_sort == 'd'){
        sort_by(&state, cmpr_by_date);
    } else if( state.need_sort == 't'){
        sort_by(&state, cmpr_by_temp);
    } else {
        fprintf(stderr, "Неизвестный ключ: %c\n", state.need_sort);
    }

    /**
     * @brief Сырой вывод данных если нужно
     */
    if( state.need_raw ){
        printf_data(state);
        free(state.data);
        return 0;
    }

    /**
     * @brief Вывод статистики по месяцам и за год
     */
    stats_per_mouth(state);
    stats_per_year(state);

    /**
     * @brief I`m not Rust, but i`m memory safe xD
     */
    free(state.data);
}

