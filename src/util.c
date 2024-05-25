#include <util.h>

static int atoi(char* str){
    int res = 0;
    while(*str){
        res = res * 10 + *str -'0';
        str++;
    }
    return res;
}

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
    printf("Usage: temp_statistics -f <filename.csv> [-m <month>] [-y <year>]\n");
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