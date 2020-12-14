#include <stdio.h>
#include <stdlib.h>

int is_alpha(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int comparesl(char* s1, char* s2)
{
    while (1)
    {
        char c1 = *s1;
        char c2 = *s2;
        if (c1 == '\0' || c2 == '\0')
            return c1 - c2;
        if (c1 != c2)
            return c1 - c2;
        *s1++;
        *s2++;
    }
}

// Узел односвязного списка
struct Node
{
    char* word;  // указатель на слово, прочитанное из файла
    Node* next;  // указатель на следующий узел
};


// Список
struct List
{
    int id;      // ID списка (нужно только для вывода на экран)
    Node* start; // указатель на первый узел 
    Node* end;   // указатель на последний узел 
};



// Вставка узла "node" в упорядоченный односвязный список. 
void insert(List* list, Node* node)
{
    // если список пуст:
    if (!list->end)
    {
        node->next = NULL;
        list->end = node;
        list->start = node;
        return;
    }

    // если список не пуст, то надо пробежаться в цикле по всем узлам:
    Node* prev = NULL;     //  предыдущий узел
    Node* n = list->start; //  текущий узел 
    while (n != NULL)
    {
        // если узел "node" надо вставлять ПОСЛЕ узла "n",
    // то просто переходим к следующей итерации:
        if (comparesl(n->word, node->word) < 0)
        {
            prev = n;
            n = n->next;
        }

        // если узел "node" надо вставлять ПЕРЕД узлом "n",
    // то выполняем вставку и выходим из функции:
        else
        {
            if (prev != NULL) { // случай вставки в середину списка
                prev->next = node;
                node->next = n;
                return;
            }
            node->next = n; // случай вставки в начало списка
            list->start = node;
            return;
        }
    }

    // вставка в конец списка
    // (сюда мы можем прийти, только если оказалось, что на КАЖДОЙ итерации
    // узел "node" надо было вставлять ПОСЛЕ узла "n"):
    list->end->next = node;
    node->next = NULL;
    list->end = node;
}


// Создание упорядоченного списка на основе файла
List* create_list(const char* file, int id)
{
    // открываем файл:
    FILE* fp;
    if ((fp = fopen(file, "r")) == NULL) {
        printf("Cannot open file '%s'\n", file);
        exit(1);
    }

    // создаем пустой список:
    List* list = (List*)malloc(sizeof(List));
    list->start = NULL;
    list->end = NULL;
    list->id = id;

    // читаем первый символ из файла:
    char c = fgetc(fp);

    // в цикле читаем остальные символы из файла, определяем где начинается и заканчивается каждое слово,
    // записываем слово в дин.память, помещаем слово в узел, а узел - в список:
    int len = 0;           // длина слова и текущая позиция буквы в слове
    int capacity = 1;      // размер памяти, выделенной под текущее слово
    int first_letter = 1;  // флаг: является ли текущая буква первой в текущем слове?
    int inserted = 0;     // флаг: вставленно ли текущее слово в список?
    Node* node = NULL;     // текущий узел
    while (c != EOF)
    {
        // если это первая буква в слове, то создаем новый узел:
        if (is_alpha(c) && first_letter)
        {
            len = 0;
            capacity = 1;
            inserted = 0;
            node = (Node*)malloc(sizeof(Node));
            node->word = (char*)malloc(sizeof(char)); // выделяем 1 байт
            node->word[len] = c;  // помещаем в память символ, прочитанный из файла
            first_letter = 0;
            len++;
        }

        // если это уже не первая буква в слове, то записываем ее в созданный узел:
        else if (is_alpha(c) && !first_letter)
        {
            if (len >= capacity) { // если нужно, выделяем еще памяти
                capacity *= 2;
                node->word = (char*)realloc(node->word, capacity * sizeof(char));
            }
            node->word[len] = c; // помещаем в память символ, прочитанный из файла
            len++;
        }

        // если слово закончилось, то добавляем "\0" и вставляем созданный узел в список:
        else if (!is_alpha(c) && !first_letter && !inserted)
        {
            if (len >= capacity) { // (если нужно) выделяем 1 байт для символа "\0"
                node->word = (char*)realloc(node->word, capacity + 1);
            }
            node->word[len] = '\0'; // помещаем в память символ "\0" - "конец строки"
            len++;

            insert(list, node); // вставка узла в список
            inserted = 1;       // между словами может быть несколько пробелов (или "плохих" сиволов). Этот флаг позволяет игнорировать их.
            first_letter = 1;   // когда мы встретим обычную букву, то это означает начало нового слова.      
        }

        // читаем следующий символ из файла:
        c = fgetc(fp);
    }

    // закрываем файл:
    fclose(fp);

    return list;
}

// вывод списка на экран
void print_list(List* list)
{
    printf("List %d:\n", list->id);
    for (Node* n = list->start; n != NULL; n = n->next)
    {
        printf("Node->word: '%s'\n", n->word);
    }
}

// Объединение списков. Узлы списка "src" перемещаются в список "dst" 
void merge(List* dst, List* src)
{
    Node* n = src->start; // текущий узел
    while (n != NULL)
    {
        Node* node = n; // запоминаем текущий узел
        n = n->next;    // переходим к следующему

        insert(dst, node); // Вставляем имеено "node". Если бы мы вставили узел "n", то insert() поменял бы его указатель "n->next", и на следующей итерации мы получили бы ошибку 
    }

    // список "src" теперь пуст:
    src->start = NULL;
    src->end = NULL;
}


// Удаление списка
void delete_list(List* list)
{
    printf("Delete list %d\n", list->id);

    // сначала удаляем узлы списка, один за другим:
    Node* n = list->start; // текущий узел
    while (n != NULL)
    {
        Node* node = n;  // запоминаем текущий узел
        n = n->next;     // переходим к следующему

        printf("  delete '%s'\n", node->word);
        free(node->word);
        free(node);       // Удаляем имеено узел "node". Если бы мы удалили узел "n", на следующей итерации мы не смогли бы перейти к следующему узлу (n->next)
    }

    // удаляем пустой список:
    free(list);
}



int main()
{
    // создаем списки
    List* one = create_list("C:\\github\\labs\\lab6\\Debug\\one.txt", 1);
    List* two = create_list("C:\\github\\labs\\lab6\\Debug\\two.txt", 2);
    List* three = create_list("C:\\github\\labs\\lab6\\Debug\\three.txt", 3);

    // выводим списки на экран
    print_list(one);
    print_list(two);
    print_list(three);

    // объединяем списки ("one" становится одним большим списком, а "two" и "three" - пустыми)
    merge(one, two);
    merge(one, three);

    // 	выводим списки на экран
    printf("\nAfter merge:\n");
    print_list(one);
    print_list(two);
    print_list(three);

    // удаляем списки 
    printf("\n");
    delete_list(one);
    delete_list(two);
    delete_list(three);

    return 0;
}

