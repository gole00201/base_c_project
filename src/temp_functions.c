#include <temp_functions.h>


void stats_per_mouth(SCOPE_t state){
    printf("\t-------------------------------\n");
    printf("\t|    СТАТИСТИКА ПО МЕСЯЦАМ    |\n");
    printf("\t-------------------------------\n");
    for(int i = 1; i <= 12; i++){
        int max = -999;
        int min = 999;
        float sum_of_temp = 0;
        int cnt = 0;
        for(int j = 0; j < state.data_cnt; j++){
            if(state.data[j].mouth == i){
                DATA_ROW_t tmp = state.data[j];
                if(tmp.temp > max){
                    max = tmp.temp;
                }
                if(tmp.temp < min){
                    min = tmp.temp;
                }
                sum_of_temp += tmp.temp;
                cnt++;
            }
        }
        char mouth_name[20];
        int_to_mouth_name(mouth_name, i);
        printf("Средняя температура      в %s составила: %.2f\n", mouth_name, sum_of_temp / (float)cnt);
        printf("Максимальная температура в %s составила: %d\n", mouth_name, max);
        printf("Минимальная температура  в %s составила: %d\n", mouth_name, min);
        printf("---------------------------------------\n");
    }
}


void stats_per_year(SCOPE_t state){
    printf("\t-------------------------------\n");
    printf("\t|      СТАТИСТИКА ЗА ГОД      |\n");
    printf("\t-------------------------------\n");
    int max = -999;
    int min = 999;
    float sum_of_temp = 0;
    for(int j = 0; j < state.data_cnt; j++){
        DATA_ROW_t tmp = state.data[j];
        if(tmp.temp > max){
            max = tmp.temp;
        }
        if(tmp.temp < min){
            min = tmp.temp;
        }
        sum_of_temp += tmp.temp;
    }
    printf("Средняя температура году в составила: %.2f\n", sum_of_temp / (float)state.data_cnt);
    printf("Максимальная температура году в составила: %d\n", max);
    printf("Минимальная температура году в составила: %d\n", min);
    printf("---------------------------------------\n");
}

void stats_one_mouth(SCOPE_t state){
    char mouth_name[20];
    int_to_mouth_name(mouth_name, state.need_mouth);
    if(mouth_name[0] == 'N'){
        fprintf(stderr, "Некорректный месяц %d\n", state.need_mouth);
        return;
    }
    printf("\t-------------------------------\n");
    printf("\t|    СТАТИСТИКА ЗА %s    |\n", mouth_name);
    printf("\t-------------------------------\n");
    int max = -999;
    int min = 999;
    float sum_of_temp = 0;
    int cnt = 0;
    for(int j = 0; j < state.data_cnt; j++){
        if(state.data[j].mouth == state.need_mouth){
            DATA_ROW_t tmp = state.data[j];
            if(tmp.temp > max){
                max = tmp.temp;
            }
            if(tmp.temp < min){
                min = tmp.temp;
            }
            sum_of_temp += tmp.temp;
            cnt++;
        }
    }
    printf("Средняя температура      в %s составила: %.2f\n", mouth_name, sum_of_temp / (float)cnt);
    printf("Максимальная температура в %s составила: %d\n", mouth_name, max);
    printf("Минимальная температура  в %s составила: %d\n", mouth_name, min);
    printf("---------------------------------------\n");
}