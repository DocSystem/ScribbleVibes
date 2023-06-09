// Scribble Vibes
// Authors : Valentin Gourjon & Antoine Souben-Fink
// Ce fichier contient les fonctions de gestion d'une liste doublement chaînée

#include "double_chained_list.h"


lnode* lst_create_node(void *data) {
    // Création d'un nouveau noeud
    lnode *pnew = malloc(sizeof(lnode));
    pnew->data = data;
    pnew->prev = NULL;
    pnew->next = NULL;
    return pnew;
}

List* lst_create_list() {
    // Création d'une nouvelle liste
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void lst_delete_list(List *list) {
    // Suppression de la liste
    lnode *p = list->head;
    while (p != NULL) {
        lnode *tmp = p->next;
        free(p);
        p = tmp;
    }
    free(list);
}

void lst_insert_head(List *list, lnode* pnew) {
    // Insertion en tête
    if (list == NULL) {
        list = lst_create_list();
    }
    if (list->head == NULL) {
        list->head = pnew;
        list->tail = pnew;
    } else {
        pnew->next = list->head;
        list->head->prev = pnew;
        list->head = pnew;
    }
}

void lst_insert_tail(List *list, lnode* pnew) {
    // Insertion en queue
    if (list == NULL) {
        list = lst_create_list();
    }
    if (list->head == NULL) {
        list->head = pnew;
        list->tail = pnew;
    } else {
        pnew->prev = list->tail;
        list->tail->next = pnew;
        list->tail = pnew;
    }
}

void lst_insert_after(List *list, lnode *pnew, lnode *ptr) {
    // Insertion après un noeud
    if (ptr == list->tail) {
        lst_insert_tail(list, pnew);
    } else {
        pnew->next = ptr->next;
        pnew->prev = ptr;
        ptr->next->prev = pnew;
        ptr->next = pnew;
    }
}

void lst_delete_head(List *list) {
    // Suppression de la tête
    if (list->head == NULL) {
        return;
    }
    lnode *tmp = list->head;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    free(tmp);
}

void lst_delete_tail(List *list) {
    // Suppression de la queue
    if (list->tail == NULL) {
        return;
    }
    lnode *tmp = list->tail;
    list->tail = list->tail->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(tmp);
}

void lst_delete_node(List *list, lnode *ptr) {
    // Suppression d'un noeud
    if (ptr == list->head) {
        lst_delete_head(list);
    } else if (ptr == list->tail) {
        lst_delete_tail(list);
    } else {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }
}

lnode* get_first_node(List *list) {
    // Récupération du premier noeud
    if (list == NULL) {
        return NULL;
    }
    return list->head;
}

lnode* get_last_node(List *list) {
    // Récupération du dernier noeud
    return list->tail;
}

lnode* get_next_node(lnode *node) {
    // Récupération du noeud suivant
    return node->next;
}

void* get_previous_elem(List *list) {
    // Récupération du noeud précédent
    return list->tail->data;
}

lnode* get_node_by_index(List *list, int index) {
    // Récupération du noeud à l'index donné
    lnode *p = list->head;
    int i = 0;
    while (p != NULL && i < index) {
        p = p->next;
        i++;
    }
    return p;
}

void* get_data(lnode* node) {
    // Récupération des données du noeud
    if (node == NULL) {
        return NULL;
    }
    return node->data;
}
