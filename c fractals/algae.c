#include <stdio.h>

/* staly rozmiar tablicy znakow algae i tablicy pomocniczej w uzupelnianiu kolejnych pozycji A > AB i B > A */
#define SIZE 100

/* funkcja "rozrastajaca glony", czyli powiekszajaca tablice o nowe znaki z kazda iteracja
A > AB (pozycja x z A na A, pozycja x + 1 dodanie B) i B > A (pozycja x z B na A) */
void dynamics(char *);

int main()
{
    /* deklaraca tablicy algae, ktorej nazwy uzyjemy jako wskaznika w funkcji dynamics */
    char algae[SIZE];

    /* uzycie funkcji "rozrasrajacej" i wypisanie naszego wyniku na standardowe wyjscie */
    dynamics(algae);

    /* zakonczenie dzialania programu i zwrocenie wartosci 0 */
    return 0;
}


/* funkcja pobiera nazwe tablicy jako staly wskaznik do niej i operuje na jej elementach
pierwszemu indeksowi przypisujemy wartosc A, ktora wraz z kolejnymi iteracjami do liczby operacji
wykorzystywana jest do przypisania wartosci dla odpowiadajacych indeksow tablicy drugiej

gdy element Ti w tablicy pierwszej wynosi A, element Tj w tablicy drugiej wynosi A, a Tj+1 wynosi B
w ten sposob nie nadpisujemy lancucha znakow w jedna komorke tablicy (blad), ale wykorzystujemy iteracje
i zmiane miejsca w tablicy. Dzieki temu z jednego elementu A zrobily sie dwa elementy AB, itd.
Operacja powtarzana jest przez wszystkie elementy w tablicy (dopoki nie napotkamy ostatniego elementu '\0'), dzieki czemu
jestesmy w stanie wypelnic ja w calosci.
Wykorzystujemy tu glownie tablice 1 (jej wskaznik), wiec iterator w petli zalezy od iteratora elementow pierwszej tablicy
(tablica - algae_tab, jej iterator - alg_iterator)

Po wykonaniu operacji zamiany elementow w petli pora na ich przypisanie w odpowiednie miejsca do tablicy pierwszej.

Przypisanie tablicy drugiej do tablicy pierwszej (algae_tab) wykonujemy w petli for,
poczawszy od zera, az przez caly jej rozmiar (czyli do konca)

Nastepnie wypisujemy poszczegolne indeksy wyswietlanych linijek dzieki new_row, ktore zwieksza sie po kazdej wykonanej operacji

Ostatnim i najwazniejszym procesem jest wypisanie tablicy na standardowe wyjscie
Chcemy aby wypisala sie cala, czyli zaczynamy od zera, az do napotkania jej konca, czyli elementu '\0'
Wykorzystujemy ten sam iterator co przy przypisaniu */

void dynamics(char *algae_tab)
{
    /* stworzenie tablicy o rozmiarze 200 i dwoma elementami - '0' i '\0' */
    char supporting_tab[200] = {'0'};

    /* przyjecie do funkcji tablicy algae z main i wskazanie na nia */
    /* przypisanie pierwszemu elementowi tablicy algae[0] = 'A */
    *algae_tab = 'A';

    /* ilosc zapetlen ktore przeprowadzimy */
    int number_of_operations = 10;

    /* iterator glownej tablicy algae */
    int alg_iterator = 0;

    /* iterator tablicy pomocniczej, ktora bedziemy wypelniac */
    int sup_iterator = 0;

    /* iterator sluzacy do przypisania tablicy pomocniczej do algae, a potem pozniejszego jej wypisania */
    int assigment_iterator = 0;

    /* iterator wypisujacy numeracje linii */
    int new_row = 0;


    /* wypisanie pierwszego elementu - A */
    printf("%d. %c \n",new_row,*algae_tab);    

    /* zwiekszenie na stale iteratora linijek, teraz przyjmuje wartosc 1 */                                               
    new_row++;                                                                                 

    /* glowna petla, od liczby linijki rownej 1 do ilosci wykonanych operacji (11) */
    for(new_row = 1; new_row < number_of_operations+1; new_row++)
    {
        do
        {
            /* zamiana z A na AB */
            if (*(algae_tab + alg_iterator) == 'A')
            {
                supporting_tab[sup_iterator] = 'A';
                supporting_tab[sup_iterator + 1] = 'B';
                
                /* przesuniecie na kolejne dwie komorki (zwolnienie miejsca na dalsze zamiany)*/
                sup_iterator++;
                sup_iterator++;
            }

            /* zamiana z B na A */
            else if (*(algae_tab+alg_iterator) == 'B')
            {
                supporting_tab[sup_iterator] = 'A';

                /* przesuniecie na kolejna komorke */
                sup_iterator++;
            }

            /* zwiekszenie iteratora glownej tablicy (zmieniamy pozycje i przeszukujemy dalej) */
            alg_iterator++;

        } while (*(algae_tab + alg_iterator) != '\0'); /* przeszukiwania dopoki nie skonczy nam sie glowna tablica */

        /* przypisanie tablicy pomocniczej do glownej */
        for(assigment_iterator = 0; assigment_iterator < SIZE; assigment_iterator++)
        {
            *(algae_tab + assigment_iterator) = supporting_tab[assigment_iterator];
        }

        /* wypisanie linijki (zwieksza sie wraz z rozpoczeciem kolejnej petli)*/
        printf("%d. ", new_row);

        /* wypisanie glownej tablicy obok cyfry lini */
        for(assigment_iterator=0; *(algae_tab + assigment_iterator) != '\0'; assigment_iterator++)
        {
            printf("%c ", *(algae_tab+assigment_iterator));
        }

        printf("\n");
    }

    printf("\n");
}