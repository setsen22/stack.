#include "DS.h"

/* p-ийн зааж буй Queue-д x утгыг хийнэ */
void q_push(Queue *p, int x)
{
Elm *e = malloc(sizeof(Elm));
        if (e == NULL)
                return;
        e->x = x;
        e->next = NULL;
        if (p->tail == NULL)
                p->head = p->tail = e;
        else {
                p->tail->next = e;
                p->tail = e;
        }
        p->len++;        /* Энд оруулах үйлдлийг хийнэ үү */
}

/* p-ийн зааж буй Queue-с гаргана */
void q_pop(Queue *p)
{
 if (p->head == NULL)
                return;
        Elm *tmp = p->head;
        p->head = tmp->next;
        if (p->head == NULL)
                p->tail = NULL;
        free(tmp);
        p->len--;        /* Энд гаргах үйлдлийг хийнэ үү */
}

/*
  p-ийн зааж буй Queue-н утгуудыг хэвлэнэ.
  Хамгийн эхний элементээс эхлэн дарааллаар, нэг мөрөнд
  нэг л элемент хэвлэнэ.
 */
void q_print(Queue *p)
{
Elm *cur;
        for (cur = p->head; cur != NULL; cur = cur->next)
                printf("%d\n", cur->x);        /* Энд хэвлэх үйлдлийг хийнэ үү */
}
