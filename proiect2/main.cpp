#include <fstream>

using namespace std;

ifstream statin ( "STATII.in" ) ;
ofstream linin ( "LINII.in" ) ;

//numar statii si numar linii
int n , m ;

//matrice adiacenta
int ma [ 3500 ] [ 3500 ] ;

//linii si statii de autobuz
struct linii
{
    int linie ;
    int numstatii ;
    char statii [ 52 ] [ 40 ] ;
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
            linin >>
    }
}

int read ( )
{
    readma ( );
    readl ( ) ;
}

int main()
{
    read ( ) ;
    return 0;
}
