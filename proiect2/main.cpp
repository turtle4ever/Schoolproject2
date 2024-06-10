#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <windows.h>
#include <string>
#include <cctype>

using namespace std;

ifstream statin ( "STATII.in" ) ;
ifstream linin ( "LINII.in" ) ;
ifstream idin ( "ID.in" ) ;

//numar statii si numar linii
int n , m ;

//matrice adiacenta
int ma [ 1001 ] [ 1001 ] ;

//vector vizitati
int v [ 1001 ] = { 0 } ;

//vector drum
int dr [ 1001 ] = { 0 } , cnt ;

//vector frecvente linii
int frecv [ 1002 ] , frecv2 [ 1002 ] ;

//linii si statii de autobuz
struct linii
{
    int linie ;
    int izolat ;
    int numstatii ;
    char statii [ 46 ] [ 50 ] ;
    int statiiid [ 46 ] ;
} linii [ 150 ] ;

struct id
{
    int ids ;
    char idstatii [ 50 ] ;
} id [ 1001 ] ;

// citire matrice adiacenta
void readma ( )
{
    int i , j ;
    statin >> n ;
    for ( i = 0 ; i < n ; i ++ )
        for ( j = 0 ; j < n ; j ++ )
            statin >> ma [ i ] [ j ] ;
}

//citire sistem de linii si statii
void readl ( )
{
    int i , j ;
    linin >> m ;
    for ( i = 0 ; i < m ; i ++ )
    {
        linin >> linii [ i ] .linie ;
        linin >> linii [ i ] .numstatii ;
        linin.get ( ) ;
        for ( j = 0 ; j < linii [ i ] .numstatii ; j ++ )
        {
            linin >> linii [ i ] .statii [ j ] >> linii [ i ] .statiiid [ j ] ;
            linin.get ( ) ;
        }
    }
}

void readid ( )
{
    int i ;
    for ( i = 0 ; i < n ; i ++ )
    {
        idin >> id [ i ] .ids ;
        idin >> id [ i ] .idstatii ;
    }
}

//read
void read ( )
{
    readma ( );
    readl ( ) ;
    readid ( ) ;
}

//cases cout
void casesout ( )
{
    system ( "cls" ) ;
    cout << "1. Ce statii contine o linie de stb? \n" ; //done
    cout << "2. Ce linii contine statia A? \n" ; //done
    cout << "3. \n" ;
    cout << "4. Se poate ajunge din A in B? \n" ; //done
    cout << "5. Ce distanta are linia A? \n" ; //done
    cout << "6. Care este cea mai \"aglomerata\" statie? \n" ; //done
    cout << "7. Care sunt statiile fara alte conexiuni ale unei linii? \n" ; //dpme
    cout << "8. Care sunt liniile izolate? \n" ;
    cout << "9. Afiseaza statiile si codurile lor, respectiv liniile \n" ;
    cout << "0. Cate statii comune are linia a cu b? \n" ;//done
    cout << "Press the number of the case to access it or space to exit \n" ;
}

//cout good day and terminate
void gd ( )
{
    system ( "cls" ) ;
    cout << "Have a good day!" ;
    getch ( ) ;
}


//pathing
void findPath( int start, int en ) {

    int i ;

    v [ start ] = 1 ;
    if (start == en) {
        return;
    }

    for ( i = 0 ; i < n ; i ++ )
    {
        if ( ma [ start ] [ i ] == 1 && v [ i ] == 0 ) {
            findPath( i, en ) ;
        }
    }

    v [ start ] = 0 ;
}


//cases interface
void cases ( )
{
    //character for switch and a bool for loop
    char ch , ok ;

    ok = 1 ;

    //loop
    while ( ok )
    {
        casesout ( ) ;
        ch = getch ( ) ;
        switch ( ch )
        {
            case '1' :
            {
                int okt ;
                okt = 1 ;
                while ( okt )
                {
                    system ( "cls" ) ;
                    cout << "Inserati numarul liniei\n" ;

                    int i , tn ;
                    char crc ;
                    cin >> tn ;

                    for ( i = 0 ; i < m ; i ++ )
                    {
                        if ( linii [ i ] .linie == tn )
                        {
                            int j ;
                            for ( j = 0 ; j < linii [ i ] .numstatii ; j ++ )
                            {
                                cout << linii [ i ] .statii [ j ] << "\n" ;
                            }
                            okt = 0 ;
                            getch ( ) ;
                        }
                    }

                    if ( okt )
                    {
                        cout << "\nLinia nu exista!" ;
                        cout << "\nApasati backspace pentru a va intoarce la meniu sau orice alta tasta pentru a incerca din nou" ;
                        crc = getch ( ) ;
                        switch ( crc )
                        {
                            case '\b' :
                            {
                                okt = 0 ;
                                break;
                            }
                            default :
                            {
                                okt = 1 ;
                            }
                        }
                    }
                }
                break ;

            }
            case '2' :
            {
                int okt ;
                okt = 1 ;
                while ( okt )
                {
                    system ( "cls" ) ;
                    cout << "Inserati numele statiei\n" ;

                    int i , j ;
                    char tn [ 50 ] ;
                    char crc ;
                    cin >> tn ;

                    for ( i = 0 ; i < m ; i ++ )
                    {
                        for ( j = 0 ; j < linii [ i ] .numstatii ; j ++ )
                        {
                            if ( strcmp ( tn , linii [ i ] .statii [ j ] ) == 0 )
                            {
                                okt = 0 ;
                                cout << linii [ i ] .linie << "\n";
                                j = linii [ i ] .numstatii ;
                            }
                        }
                    }
                    if ( okt )
                    {
                        cout << "\nStatia nu exista!" ;
                        cout << "\nApasati backspace pentru a va intoarce la meniu sau orice alta tasta pentru a incerca din nou" ;
                        crc = getch ( ) ;
                        switch ( crc )
                        {
                            case '\b' :
                            {
                                okt = 0 ;
                                break;
                            }
                            default :
                            {
                                okt = 1 ;
                            }
                        }
                    }
                }
                break ;

            }
            case '4' :
            {
                int okt , okk ;
                int i , j , aa , bb;
                char tna [ 50 ] , tnb [ 50 ] ;
                okt = okk = 1 ;
                while ( okt )
                {
                    system ( "cls" ) ;
                    cout << "Inserati statiile\n" ;

                    char crc ;
                    cin >> tna >> tnb ;

                    for ( i = 0 ; i < m ; i ++ )
                    {
                        for ( j = 0 ; j < linii [ i ] .numstatii ; j ++ )
                        {
                            if ( strcmp ( linii [ i ] .statii [ j ] , tna ) == 0 )
                            {
                                aa = linii [ i ] .statiiid [ j ] ;
                                okt = 0 ;
                            }
                        }

                    }
                    if ( okt )
                    {
                        cout << "\nStatia A nu exista!" ;
                        cout << "\nApasati backspace pentru a va intoarce la meniu sau orice alta tasta pentru a incerca din nou" ;
                        crc = getch ( ) ;
                        switch ( crc )
                        {
                            case '\b' :
                            {
                                okt = 0 ;
                                break;
                            }
                            default :
                            {
                                okt = 1 ;
                            }
                        }
                    }
                    else
                    {
                        okt = 1 ;
                        for ( i = 0 ; i < m ; i ++ )
                        {
                            for ( j = 0 ; j < linii [ i ] .numstatii ; j ++ )
                            {
                                if ( strcmp ( linii [ i ] .statii [ j ] , tna ) == 0 )
                                {
                                    bb = linii [ i ] .statiiid [ j ] ;
                                    okt = 0 ;
                                    okk = 0 ;
                                }
                            }
                        }
                        if ( okt )
                        {
                            cout << "\nStatia B nu exista!" ;
                            cout << "\nApasati backspace pentru a va intoarce la meniu sau orice alta tasta pentru a incerca din nou" ;
                            crc = getch ( ) ;
                            switch ( crc )
                            {
                                case '\b' :
                                {
                                    okt = 0 ;
                                    break;
                                }
                                default :
                                {
                                    okt = 1 ;
                                }
                            }
                        }
                    }
                }
                if ( okk == 0 )
                {
                   findPath ( aa , bb ) ;
                   if ( v [ bb ] == 1 )
                   {
                       system ( "cls" ) ;
                       cout << "Exista o cale sa se ajunga din A in B" ;
                   }
                   fill ( v , v + n , 0 ) ;
                }
                break ;
            }
            case '3' :
            {
                system ( "cls" ) ;
                cout << "test4" ;
                getch ( ) ;
                break ;
            }
            case '5' :
            {
                int okt ;
                okt = 1 ;
                while ( okt )
                {
                    system ( "cls" ) ;
                    cout << "Inserati numarul liniei\n" ;

                    int i , tn ;
                    char crc ;
                    cin >> tn ;

                    for ( i = 0 ; i < m ; i ++ )
                    {
                        if ( linii [ i ] .linie == tn )
                        {
                            cout << linii [ i ] .numstatii << "\n" ;
                            okt = 0 ;
                            getch ( ) ;
                        }
                    }

                    if ( okt )
                    {
                        cout << "\nLinia nu exista!" ;
                        cout << "\nApasati backspace pentru a va intoarce la meniu sau orice alta tasta pentru a incerca din nou" ;
                        crc = getch ( ) ;
                        switch ( crc )
                        {
                            case '\b' :
                            {
                                okt = 0 ;
                                break;
                            }
                            default :
                            {
                                okt = 1 ;
                            }
                        }
                    }
                }
                break ;

            }
            case '6' :
            {
                int maxx , i , j , maxime [ 1001 ] = { 0 } ;

                maxx = 0 ;

                if ( frecv [ 0 ] == 0 )
                {
                    for ( i = 0 ; i < m ; i ++ )
                    {
                        for ( j = 0 ; j < n ; j ++ )
                        {
                            frecv [ linii [ i ] .statiiid [ j ] + 1 ] ++ ;
                        }
                    }
                    frecv [ 0 ] = -1 ;
                }

                j = 0 ;

                for ( i = 1 ; i <= n ; i ++ )
                {
                    if ( maxx < frecv [ i - 1 ] )
                    {
                        maxx = frecv [ i - 1 ] ;
                        maxime [ 0 ] = i - 1 ;
                        j = 1 ;

                    }
                    else
                        if ( maxx == frecv [ i - 1 ] )
                        {
                            maxime [ j ] = i - 1 ;
                            j ++ ;
                        }
                }


                system ( "cls" ) ;
                if ( j == 1 )
                    cout << "Statia cea mai \"aglomerata\" este " << id [ maxime [ 0 ] - 1 ] .idstatii ;
                else
                {
                    cout << "Statia cele mai \"aglomerate\" sunt : \n" ;
                    for ( i = 0 ; i < j - 1 ; i ++ )
                    {
                        cout << id [ maxime [ i ] ] .idstatii << ", \n" ;
                    }
                    cout << id [ maxime [ j - 1 ] ] .idstatii << "\n" ;
                }


                getch ( ) ;
                break ;
            }
            case '7' :
            {
                int i , j , minime [ 1001 ] = { 0 } ;

                if ( frecv2 [ 0 ] == 0 )
                {
                    for ( i = 0 ; i < m ; i ++ )
                    {
                        for ( j = 0 ; j < n ; j ++ )
                        {
                            frecv2 [ linii [ i ] .statiiid [ j ] + 1 ] ++ ;
                        }
                    }
                    frecv2 [ 0 ] = -1 ;
                }

                j = 0 ;

                for ( i = 2 ; i <= n ; i ++ )
                {
                    if ( frecv2 [ i - 1 ] == 1 )
                    {
                        minime [ j ] = i - 1 ;
                        j ++ ;

                    }
                }


                system ( "cls" ) ;
                if ( j == 1 )
                    cout << "Statia fara alte conexiuni ale unei linii este " << id [ minime [ 0 ] - 1 ] .idstatii ;
                else
                {
                    if ( j == 0 )
                    {
                        cout << "Nu exista statii fara alte conexiuni ale unei linii \n" ;
                    }
                    else
                    {
                        cout << "Statiile fara alte conexiuni ale unei linii sunt : \n" ;
                        for ( i = 0 ; i < j - 1 ; i ++ )
                        {
                            cout << id [ minime [ i ] ] .idstatii << ", \n" ;
                        }
                        cout << id [ minime [ j - 1 ] ] .idstatii << "\n" ;
                    }
                }

                getch ( ) ;
                break ;
            }
            case '8' :
            {
                system ( "cls" ) ;
                cout << "test8" ;
                getch ( ) ;
                break ;
            }
            case '9' :
            {
                system ( "cls" ) ;
                for ( i = 0 ; i < m ; i ++ )
                cout << "test9" ;
                getch ( ) ;
                break ;
            }
            case '0' :
            {
                int okt , okk ;
                int i , tna , tnb , aa , bb ;
                okt = okk = 1 ;
                while ( okt )
                {
                    system ( "cls" ) ;
                    cout << "Inserati liniile\n" ;

                    char crc ;
                    cin >> tna >> tnb ;

                    for ( i = 0 ; i < m ; i ++ )
                    {
                        if ( linii [ i ] .linie == tna )
                        {
                            aa = i ;
                            okt = 0 ;
                        }
                    }
                    if ( okt )
                    {
                        cout << "\nLinia A nu exista!" ;
                        cout << "\nApasati backspace pentru a va intoarce la meniu sau orice alta tasta pentru a incerca din nou" ;
                        crc = getch ( ) ;
                        switch ( crc )
                        {
                            case '\b' :
                            {
                                okt = 0 ;
                                break;
                            }
                            default :
                            {
                                okt = 1 ;
                            }
                        }
                    }
                    else
                    {
                        okt = 1 ;
                        for ( i = 0 ; i < m ; i ++ )
                        {
                            if ( linii [ i ] .linie == tnb )
                            {
                                bb = i ;
                                okt = 0 ;
                                okk = 0 ;
                            }
                        }
                        if ( okt )
                        {
                            cout << "\nLinia B nu exista!" ;
                            cout << "\nApasati backspace pentru a va intoarce la meniu sau orice alta tasta pentru a incerca din nou" ;
                            crc = getch ( ) ;
                            switch ( crc )
                            {
                                case '\b' :
                                {
                                    okt = 0 ;
                                    break;
                                }
                                default :
                                {
                                    okt = 1 ;
                                }
                            }
                        }
                    }
                }
                if ( okk == 0 )
                {
                    int s = 0 ;
                    for ( i = 0 ; i < linii [ aa ] .numstatii ; i ++ )
                    {
                        int j ;
                        for ( j = 0 ; j < linii [ bb ] .numstatii ; j ++ )
                        {
                            if ( linii [ aa ] .statii [ i ] == linii [ bb ] .statii [ i ] )
                                s ++ ;
                        }
                    }
                    system ( "cls" ) ;
                    cout << "Liniile " << aa << " si " << bb << " au " << s << " statii in comun." ;
                    getch ( ) ;
                }
                break ;
            }
            case ' ' :
            {
                gd ( ) ;
                ok = 0 ;
                abort ( ) ;
            }
            default : {
                cout << "\nPlease press a correct key to access the cases or exit!" ;
                getch ( ) ;
                break ;
            }
        }
    }
}

int main()
{
    read ( ) ;
    cases ( ) ;
    return 0;
}
