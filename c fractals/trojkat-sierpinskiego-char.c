/*
Zaimplementuj jednowymiarowy automat komórkowy działający na tablicy 32x65 (t,x). W każdym wierszu będzie jedna iteracja po czasie. Zachowanie układu określają reguły:

0 < 0 > 0 —> 0         1)

0 < 0 > 1 —> 1         2)

0 < 1 > 0 —> 0         3)

0 < 1 > 1 —> 0         4)

1 < 0 > 0 —> 1         5)

1 < 0 > 1 —> 0         6)

1 < 1 > 0 —> 0         7)

1 < 1 > 1 —> 0         8)

0 < 0 > 1 —> 1: oznacza, że jeśli układ dla t=a jest w stanie < 0 > i po lewej stronie jest 0, a po prawej jest 1
// to dla t=a+1 przejdź do stanu 1. Pozostałe reguły analogicznie.


wiec dla x = 1; x<32; x++
if( tab[t][x-1] = 0 && tab[t][x] = 0 && tab[t][x+1] = 1)

tab[t+1][x] = 1

Wartość początkowa: t=0 —> x = 0...010...0 - środkowa pozycja jest równa 1; pozostałe 0.

int tab[32][65] = {0};
tab[0][32] = 1;

Rezultatem działania ma być graficzna reprezentacja zachowania się układu dla t od 0 do 31 t.j. trójkąt Sierpińskiego.
*/

#include <stdio.h>
#define HEIGHT 32                         // maksymalna wysokosc obrazka
#define WIDTH 65                          // maksymalna szerokosc obrazka

// deklaracja funkcji wypisujaca trojkat na standardowe wyjscie
void printing_trinagle(char *sierpinski);

int main()
{
    // zadeklarowanie tablicy i przypisanie elementom wartosci 0
    char sierpinski[HEIGHT][WIDTH] = {0};

    // wartosc poczatkowa: t = 0 —> x = 0...010...0 - srodkowa pozycja jest rowna 1; pozostale 0.
    // srodkowa pozycja czyli polowa drugiej wspolrzednej mediana 65 to 33 pozycja w tablicy
    sierpinski[0][32] = 1;

    // zmienne od pozycji i czasu
    int t;
    int x;

    // od czasu t0 = 0s az do wartosci wysokosci
    for(t=0; t < HEIGHT-1; t++)
    {
        // wspolrzedna sprawdzajaca wartosci poszcczegolnych pozycji np 0 0 0
        // zaczecie od x = 1 pozwoli nam na przesuniecie sie "w lewo" na x-1 bez wyjscia poza zakres tablicy
        for(x=1; x < WIDTH; x++)
        {
            if(sierpinski[t][x-1] == 0 && sierpinski[t][x] == 0 && sierpinski[t][x+1] == 0)                  // 1)
                // zmiana stanu w kolejnym czasie
                sierpinski[t+1][x] = 0;
            else if(sierpinski[t][x-1] == 0 && sierpinski[t][x] == 0 && sierpinski[t][x+1] == 1)             // 2)
                sierpinski[t+1][x] = 1;
            else if(sierpinski[t][x-1] == 0 && sierpinski[t][x] == 1 && sierpinski[t][x+1] == 0)             // 3)
                sierpinski[t+1][x] = 0;
            else if (sierpinski[t][x-1] == 0 && sierpinski[t][x] == 1 && sierpinski[t][x+1] == 1)            // 4)
                sierpinski[t+1][x] = 0;
            else if(sierpinski[t][x-1] == 1 && sierpinski[t][x] == 0 && sierpinski[t][x+1] == 0)             // 5)
                sierpinski[t+1][x] = 1;
            else if(sierpinski[t][x-1] == 1 && sierpinski[t][x] == 0 && sierpinski[t][x+1] == 1)             // 6)
                sierpinski[t+1][x] = 0;
            else if(sierpinski[t][x-1] == 1 && sierpinski[t][x] == 1 && sierpinski[t][x+1] == 0)             // 7)
                sierpinski[t+1][x] = 0;
            else if(sierpinski[t][x-1] == 1 && sierpinski[t][x] == 1 && sierpinski[t][x+1] == 1)             // 8)
                sierpinski[t+1][x] = 0;
        }
    }

    printing_trinagle(*sierpinski);

    return 0;
}


// funkcja wypisujaca w kazdej iteracji dany znak
// jezeli natrafimy na pozycje z wartoscia 0, wypisujemy znak spacji " "
// gdy jednak natrafimy na wartosc rowna 1, wypisujemy znak #, ktory utworzy nam trojkat
// pierwsza # wypisuje nam dopiero w polowie, poniewaz dopiero w polowie tablicy dla t0 natrafiamy na x == 1
// potem kolejne dwa # # drukuja sie, bo w tym samym ruchu w x-1 i x + 1 napotkalismy na 1
// 1 > wydrukowalo sie #
// widzimy ze w nastepnym ruchu jest na miejscu x (x+1) jest 1, drukujemy # przed tym,
// widzimy ze w poprzednim ruchu na miejscu x (x-1) bylo 1, drukujemy # po tym
//
//     #
//    # #
//
// itd

void printing_trinagle(char *sierpinski)
{
    // zmienne od czasu i pozycji (potrzebne do zmiany stanu)
    int t;
    int x;

    // wypisywanie dla t < 31 jak w poleceniu
    // dla t < 32 wypisze nam "podstawe"
    for(t=0; t<32; t++)
    {
        for(x=0; x<65; x++)
        {
            if(*sierpinski == 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }

            // wskaznik ulatwiajacy nam przesuniecie po obu indeksach na raz
            sierpinski++;
        }
        printf("\n");
    }
}