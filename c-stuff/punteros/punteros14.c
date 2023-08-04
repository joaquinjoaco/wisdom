#include <stdio.h>

struct pack3 {
    int a;
};
struct pack2 {
    int b;
    struct pack3 *next;
};
struct pack1 {
    int c;
    struct pack2 *next;
};

int main() {
    struct pack1 data1, *data_ptr;
    struct pack2 data2;
    struct pack3 data3;
    data1.c = 30;
    data2.b = 20;
    data3.a = 10;
    data_ptr = &data1;
    data1.next = &data2;
    data2.next = &data3;

    // printf("%d", pelao);

    return 0;
}

// data1.c (CORRECTA, 30)
// data_ptr->c (CORRECTA, 30)
// data_ptr.c (INCORRECTA)
// data1.next->b (CORRECTA, 20)
// data_ptr->next->b (CORRECTA, 20)
// data_ptr.next.b (INCORRECTA)
// data_ptr->next.b (INCORRECTA)
// (*(data_ptr->next)).b (CORRECTA, 20)
// data1.next->next->a (CORRECTA, 10)
// data_ptr->next->next.a (INCORRECTA)
// data_ptr->next->next->a (CORRECTA, 10)
// data_ptr->next->a (INCORRECTA, no llega a pack3)
// data_ptr->next->next->b (INCORRECTA, se pasa, llega al pack3 y b esta en)