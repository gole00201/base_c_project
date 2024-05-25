#include <util.h>


int parse_args(int argc, char** argv, SCOPE_t* state){
    if( argc < 2 ){
        fprintf(stderr, "Недостаточно аргументов\n");
        return 0;
    }
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], FILE_PATH) == 0 && i + 1 < argc){
            state->csv_path = argv[i + 1];
        } else if(strcmp(argv[i], MOUNTH) == 0 && i + 1 < argc){
            state->need_mouth = atoi(argv[i + 1]);
        }
    }
    return state->csv_path != NULL;
}

void usage(){
    printf("Usage: temp_statistics -f <filename.csv> [-m <month>]\n");
}


void printf_row(DATA_ROW_t row){
    printf("Год: %d\n",         row.year);
    printf("Месяц: %d\n",       row.mouth);
    printf("День: %d\n",        row.day);
    printf("Час: %d\n",         row.hour);
    printf("Минута: %d\n",      row.minute);
    printf("Температура: %d\n", row.temp);
}


void printf_data(SCOPE_t state){
    for(int i = 0; i < state.data_cnt; i++){
        printf_row(state.data[i]);
    }
    printf("\n");
}


void int_to_mouth_name(char* dist, int number){
    switch (number)
    {
    case 1:
        strcpy(dist, "Январь");
        break;
    case 2:
        strcpy(dist, "Февраль");
        break;
    case 3:
        strcpy(dist, "Март");
        break;
    case 4:
        strcpy(dist, "Апрель");
        break;
    case 5:
        strcpy(dist, "Май");
        break;
    case 6:
        strcpy(dist, "Июнь");
        break;
    case 7:
        strcpy(dist, "Июль");
        break;
    case 8:
        strcpy(dist, "Август");
        break;
    case 9:
        strcpy(dist, "Сентябрь");
        break;
    case 10:
        strcpy(dist, "Октябрь");
        break;
    case 11:
        strcpy(dist, "Ноябрь");
        break;
    case 12:
        strcpy(dist, "Декабрь");
        break;
    default:
        strcpy(dist, "NON");
        break;
    }
}

int read_csv(SCOPE_t* state) {
    FILE *file = fopen(state->csv_path, "r");
    if (file == NULL) {
        fprintf(stderr, "Не удалось открыть файл: %s\n", state->csv_path);
        return 0;
    }
    char cur_line[256];
    int alrady_alloced = 10;
    state->data = (DATA_ROW_t* ) malloc(sizeof(DATA_ROW_t) * alrady_alloced); /* Аллокация стартовых 10 строк */
    if(state->data == NULL){
        fprintf(stderr, "Buy more RAM!!!! xD");
        return 0;
    }
    state->data_cnt = 0;
    while(fgets(cur_line, sizeof(cur_line), file)){
        if(sscanf(cur_line,
               "%d;%d;%d;%d;%d;%d",
               &state->data[state->data_cnt].year,
               &state->data[state->data_cnt].mouth,
               &state->data[state->data_cnt].day,
               &state->data[state->data_cnt].hour,
               &state->data[state->data_cnt].minute,
               &state->data[state->data_cnt].temp) != 6 ){
            fprintf(stderr, "Ошибка чтения строки из файла %s: %d\n", state->csv_path, state->data_cnt + 1);
            continue;
        } else {
            state->data_cnt++;
            if(state->data_cnt >= alrady_alloced){
                state->data = (DATA_ROW_t* ) realloc(state->data, (state->data_cnt + 10) * sizeof(DATA_ROW_t));
                if(state->data == NULL){
                    fprintf(stderr, "Buy more RAM!!!! xD\n");
                    free(state->data);
                    fclose(file);
                    return 0;
                }
                alrady_alloced += 10;
            }
        }
    }
    fclose(file);
    return 1;
}