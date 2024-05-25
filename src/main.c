#include <stdio.h>
#include <parse_csv.h>
#include <util.h>
#include <temp_functions.h>
SCOPE_t state = {
    .csv_path = NULL,
    .need_mouth = 0
};


int main(int argc, char** argv){
    if(!parse_args(argc, argv, &state)){
        usage();
        return 1;
    }
    read_csv(&state);
    if(state.need_mouth){
        stats_one_mouth(state);
    } else {
        stats_per_mouth(state);
        stats_per_year(state);
    }
    free(state.data);
}

