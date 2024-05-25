#include <stdio.h>
#include <util.h>
#include <temp_functions.h>

/**
 * @brief Инициализируем контекст исполнения
 */
SCOPE_t state = {
    .csv_path = NULL,
    .need_mouth = 0
};


int main(int argc, char** argv){
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
     * @brief Выводим данные в соответсвии с контекстом
     */
    if(state.need_mouth){
        stats_one_mouth(state);
    } else {
        stats_per_mouth(state);
        stats_per_year(state);
    }

    /**
     * @brief I`m not Rust, but i`m memory safe xD
     */
    free(state.data);
}

