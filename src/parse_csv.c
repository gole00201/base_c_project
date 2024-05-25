#include <parse_csv.h>

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
            fprintf(stderr, "Ошибка чтения строки из файла %s: %d\n", state->csv_path, state->data_cnt);
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