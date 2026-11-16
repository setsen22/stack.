#include "DS.h"
#include <stdio.h>
#include <stdlib.h>

/* p-ийн зааж буй List-д x утгыг төгсгөлд хийнэ */
void l_push_back(List *p, int x)
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
        p->len++;
}

/* p-ийн зааж буй List-д x утгыг эхэнд хийнэ */
void l_push_front(List *p, int x)
{
        Elm *e = malloc(sizeof(Elm));
        if (e == NULL)
                return;
        e->x = x;
        e->next = p->head;
        p->head = e;
        if (p->tail == NULL)
                p->tail = e;
        p->len++;
}

/*
  p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ.
  Байрлал сүүлийн индексээс их бол төгсгөлд орно.
 */
void l_insert(List *p, int x, int pos)
{
        if (pos < 0 || pos >= p->len) {
                l_push_back(p, x);
                return;
        }
        if (pos == 0) {
                l_push_front(p, x);
                return;
        }
        Elm *e = malloc(sizeof(Elm));
        if (e == NULL)
                return;
        e->x = x;

        Elm *prev = p->head;
        int i;
        for (i = 0; i < pos - 1; i++)
                prev = prev->next;

        e->next = prev->next;
        prev->next = e;
        p->len++;
}

/* p-ийн зааж буй List-н эхлэлээс гаргана */
void l_pop_front(List *p)
{
        if (p->head == NULL)
                return;
        Elm *tmp = p->head;
        p->head = tmp->next;
        if (p->head == NULL)
                p->tail = NULL;
        free(tmp);
        p->len--;
}

/* p-ийн зааж буй List-н төгсгөлөөс гаргана */
void l_pop_back(List *p)
{
        if (p->head == NULL)
                return;
        if (p->head == p->tail) {
                free(p->head);
                p->head = p->tail = NULL;
                p->len--;
                return;
        }
        Elm *prev = p->head;
        while (prev->next != p->tail)
                prev = prev->next;
        free(p->tail);
        prev->next = NULL;
        p->tail = prev;
        p->len--;
}

/*
  p-ийн зааж буй List-н pos байрлалаас гаргана.
  pos байрлалаас гарах боломжгүй бол юу ч хийхгүй.
 */
void l_erase(List *p, int pos)
{
        if (pos < 0 || pos >= p->len)
                return;
        if (pos == 0) {
                l_pop_front(p);
                return;
        }
        Elm *prev = p->head;
        int i;
        for (i = 0; i < pos - 1; i++)
                prev = prev->next;

        Elm *del = prev->next;
        prev->next = del->next;
        if (del == p->tail)
                p->tail = prev;
        free(del);
        p->len--;
}

/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void l_print(List *p)
{
        Elm *cur;
        for (cur = p->head; cur != NULL; cur = cur->next)
                printf("%d\n", cur->x);
}

/*
  p-ийн зааж буй List-с x тоог хайн олдсон хаягийг буцаана.
  Олдохгүй бол NULL хаяг буцаана.
 */
Elm *l_search(List *p, int x)
{
        Elm *cur;
        for (cur = p->head; cur != NULL; cur = cur->next)
                if (cur->x == x)
                        return cur;
        return NULL;
}
