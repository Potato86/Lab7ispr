#include <stdio.h>
#include <math.h>
#include <locale.h>

int classify_char(char c);
int check_op(char op);
float calculate(float x, char op, float y);
int check_day(int day);
int days_until_sunday(int day);

int main() {
    setlocale(LC_CTYPE, "ru_RU.UTF-8");

    char c;
    int type;

    printf("Задание 1\n");
    printf("Введите символ: ");
    scanf("%c", &c);

    type = classify_char(c);
    if (type == 1)
        printf("Это цифра\n");
    else if (type == 2)
        printf("Это буква\n");
    else
        printf("Неизвестный символ\n");

    float x, y, result;
    char op;

    printf("\nЗадание 2\n");
    printf("Введите выражение (например 2+3): ");
    scanf("%f%c%f", &x, &op, &y);

    if (check_op(op) == 0) {
        printf("Неизвестная операция\n");
    }
    else if (op == '/' && y == 0) {
        printf("Деление на ноль\n");
    }
    else {
        result = calculate(x, op, y);
        printf("=%f\n", result);
    }

    int day;

    printf("\nЗадание 3\n");
    printf("Введите номер дня недели (1-7): ");
    scanf("%d", &day);

    if (check_day(day) == 0) {
        printf("Неверный номер дня\n");
    }
    else {
        switch (day) {
        case 1: printf("Понедельник"); break;
        case 2: printf("Вторник"); break;
        case 3: printf("Среда"); break;
        case 4: printf("Четверг"); break;
        case 5: printf("Пятница"); break;
        case 6: printf("Суббота"); break;
        case 7: printf("Воскресенье"); break;
        }
        printf(", до воскресенья %d дней\n", days_until_sunday(day));
    }

    return 0;
}

int classify_char(char c) {
    if (c >= '0' && c <= '9')
        return 1;

    switch (c) {
    case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g':
    case 'h': case 'i': case 'j': case 'k': case 'l': case 'm': case 'n':
    case 'o': case 'p': case 'q': case 'r': case 's': case 't': case 'u':
    case 'v': case 'w': case 'x': case 'y': case 'z':
    case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G':
    case 'H': case 'I': case 'J': case 'K': case 'L': case 'M': case 'N':
    case 'O': case 'P': case 'Q': case 'R': case 'S': case 'T': case 'U':
    case 'V': case 'W': case 'X': case 'Y': case 'Z':
    case 'а': case 'б': case 'в': case 'г': case 'д': case 'е': case 'ё':
    case 'ж': case 'з': case 'и': case 'й': case 'к': case 'л': case 'м':
    case 'н': case 'о': case 'п': case 'р': case 'с': case 'т': case 'у':
    case 'ф': case 'х': case 'ц': case 'ч': case 'ш': case 'щ': case 'ъ':
    case 'ы': case 'ь': case 'э': case 'ю': case 'я':
    case 'А': case 'Б': case 'В': case 'Г': case 'Д': case 'Е': case 'Ё':
    case 'Ж': case 'З': case 'И': case 'Й': case 'К': case 'Л': case 'М':
    case 'Н': case 'О': case 'П': case 'Р': case 'С': case 'Т': case 'У':
    case 'Ф': case 'Х': case 'Ц': case 'Ч': case 'Ш': case 'Щ': case 'Ъ':
    case 'Ы': case 'Ь': case 'Э': case 'Ю': case 'Я':
        return 2;
    default:
        return 0;
    }
}

int check_op(char op) {
    switch (op) {
    case '+': case '-': case '*': case '/': case '^':
        return 1;
    default:
        return 0;
    }
}

float calculate(float x, char op, float y) {
    switch (op) {
    case '+': return x + y;
    case '-': return x - y;
    case '*': return x * y;
    case '/': return x / y;
    case '^': return pow(x, y);
    }
    return 0;
}

int check_day(int day) {
    if (day >= 1 && day <= 7)
        return 1;
    return 0;
}

int days_until_sunday(int day) {
    switch (day) {
    case 1: return 6;
    case 2: return 5;
    case 3: return 4;
    case 4: return 3;
    case 5: return 2;
    case 6: return 1;
    case 7: return 0;
    }
    return -1;
}
