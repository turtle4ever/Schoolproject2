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

//comme

//alex e smecsi

using namespace std;

ifstream statin ( "STATII.in" ) ;
ifstream linin ( "LINII.in" ) ;

//numar statii si numar linii
int n , m ;

//matrice adiacenta
int ma [ 1001 ] [ 1001 ] ;

//linii si statii de autobuz
struct linii
{
    int linie ;
    int numstatii ;
    char statii [ 46 ] [ 50 ] ;
    int statiiid [ 46 ] ;
} linii [ 150 ] ;

// citire matrice adiacenta
int readma ( )
{
    int i , j ;
    statin >> n ;
    for ( i = 0 ; i < n ; i ++ )
        for ( j = 0 ; j < n ; j ++ )
            statin >> ma [ i ] [ j ] ;
}

//citire sistem de linii si statii
int readl ( )
{
    int i , j ;
    linin >> m ;
    for ( i = 0 ; i < m ; i ++ )
    {
        linin >> linii [ i ] .linie ;
        linin >> linii [ i ] .numstatii ;
        for ( j = 0 ; j < linii [ i ] .numstatii ; j ++ )
            linin >> linii [ i ] .statii [ j ] ;
        for ( j = 0 ; j < linii [ i ] .numstatii ; j ++ )
            linin >> linii [ i ] .statiiid [ j ] ;
    }
}

//read
int read ( )
{
    readma ( );
    readl ( ) ;
}

//cases cout
int casesout ( )
{
    system ( "cls" ) ;
    cout << "1. Ce statii contine o linie de stb? \n" ; //done
    cout << "2. Ce linii contin statia A? \n" ; //done
    cout << "3. Se poate ajunge din A in B? \n" ;
    cout << "4. Cum se ajunge din A in B? \n" ;
    cout << "5. Ce distanta are linia A? \n" ; //done
    cout << "6. Care este cea mai \"aglomerata\" statie? \n" ;
    cout << "7. Care sunt statiile fara alte conexiuni ale unei statii? \n" ;
    cout << "8. Care sunt liniile izolate? \n" ;
    cout << "9. Care doua linii au cele mai multe statii comune? \n" ;
    cout << "0. Cate statii comune are linia a cu b? \n" ;//done
    cout << "Press the number of the case to access it or space to exit \n" ;
}

//cout good day and terminate
int gd ( )
{
    system ( "cls" ) ;
    cout << "Have a good day!" ;
    getch ( ) ;
}

//cases interface
int cases ( )
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
                    char tn [ 40 ] ;
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
            case '3' :
            {
                system ( "cls" ) ;
                cout << "test3" ;
                getch ( ) ;
                break ;
            }case '4' :
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
                            int j ;
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
                system ( "cls" ) ;
                cout << "test6" ;
                getch ( ) ;
                break ;
            }
            case '7' :
            {
                system ( "cls" ) ;
                cout << "test`7" ;
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
