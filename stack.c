#include "DS.h"
/*
  p-ийн зааж буй Stack-т x утгыг оруулна
 */
void s_push(Stack *p, int x)
{
 Elm *e = malloc(sizeof(Elm));
        if (e == NULL)
                return;
        e->x = x;
        e->next = p->top;
        p->top = e;
        p->len++;        /* Энд оруулах үйлдлийг хийнэ үү */
}
/*
  p-ийн зааж буй Stack-аас гарах функц
 */
void s_pop(Stack *p)
{
if (p->top == NULL)
                return;
        Elm *tmp = p->top;
        p->top = tmp->next;
        free(tmp);
        p->len--;        /* Энд гаргах үйлдлийг хийнэ үү */
}
/*
    p-ийн зааж буй Stack-д байгаа элементүүдийг хэвлэх функц.
    Хамгийн сүүлд орсон элементээс эхлэн дарааллаар, нэг мөрөнд
    нэг л элемент хэвлэнэ.
 */
void s_print(Stack *p)
{
Elm *cur;
        for (cur = p->top; cur != NULL; cur = cur->next)
                printf("%d\n", cur->x);        /* Энд хэвлэх үйлдлийг хийнэ үү */
}
