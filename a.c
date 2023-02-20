// used for passing phase5

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf env;
uint64_t search_tree[]={
    49, (uint64_t)search_tree+sizeof(uint64_t)*3, (uint64_t)search_tree+sizeof(uint64_t)*6, 20,
    (uint64_t)search_tree+sizeof(uint64_t)*9, (uint64_t)search_tree+sizeof(uint64_t)*12, 92, (uint64_t)search_tree+sizeof(uint64_t)*15,
    (uint64_t)search_tree+sizeof(uint64_t)*18, 3, 0, 0,
    37, 0, 0, 55,
    0, 0, 94, 0,
    0
};

uint64_t func_5(uint64_t x0, uint64_t *x1){
    if(x1 == NULL) return 0;

    uint64_t x20 = x0;
    uint64_t *x19 = x1;
    x0 = x1[0];
    if(x0 == x20){
        longjmp(env, 0);
    }
        
    x0 = x19[0];
    if(x0 > x20){
        x1 = (uint64_t*)x19[1];
        x0 = x20;
        x0 = func_5(x0, x1);
        x0 *= 2;
        return x0;
    }
    x1 = (uint64_t*)x19[2];
    x0 = x20;
    x0 = func_5(x0, x1);
    x0 = x0*2+1;
    return x0;
}

void phase_5(uint64_t input){
    uint64_t ret = func_5(input, search_tree);
    if(ret != 3){
        printf("ret = %lu\n", ret);
        return;
    }
        
    printf("successed when input = %lu\n", input);
}

int main(){
    for(uint64_t i = 0; i < 100; ++i){
        phase_5(i);
        setjmp(env);
    }
}