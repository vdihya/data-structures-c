#include<stdio.h>

/*Global Declaration.*/
char str [ 100 ], pat [ 100 ], rep [ 100 ];
int str_len, pat_len,rep_len;  /*Global variables are initialized to 0 automatically.*/

/*Function definition to read main, pattern and replace strings.*/
void read_strings()
{
        int i;

        printf ( "\nEnter the main string: " );
        scanf ( "%s", str );

        printf ( "\nEnter the pattern string: " );
        scanf ( "%s", pat );

        printf ( "\nEnter the replace string: " );
        scanf ( "%s", rep );

        /*Find the length of main string.*/
        for ( i = 0 ; str [ i ] != '\0' ; i++ )
                str_len++;

        /*Find the length of pattern string.*/
        for ( i = 0 ; pat [ i ] != '\0' ; i++ )
                pat_len++;

        for ( i = 0 ; pat [ i ] != '\0' ; i++ )
                rep_len++;


}


/*Function to find the occurrences of pattern and replace with a string.*/
void pattern_match()
{
        int i;          /*Index to access main string.*/
        int j;          /*Index to access pattern string.*/
        int flag = 0;   /*Assume pattern does not exist.*/
        int count = 0;  /*Keeps track of number of occurrences of pattern.*/

        for ( i = 0 ; i < str_len ; i++ )
        {
                j = 0;  /*Initialize index of pattern to 0.*/
                while ( ( str [ i + j ] == pat [ j ] ) && ( j < pat_len ) ) 	/*Check if pattern exists.*/
                        j++;

                if ( j == pat_len )
                {

                        flag = 1;  /*Pattern found.*/
                        count++;    /*Counts the number of occurrences of pattern in main string.*/
                        for ( j = 0 ; j < pat_len ; j++ )
                        {
                                str [ i + j ]  = rep [ j ];
                        }
                        i = i + pat_len - 1; /*i now points where the pattern is ending in the main
   string.*/
                }
        }

        if ( flag == 0 )
                printf ( "\nPattern doesnt exist in main string!!!" );
        else
        {
                printf ( "\nThe number of occurrences of the pattern: %d", count );
                printf ( "\nThe main string after replacement is %s", str );
        }
}

int main()
{
        read_strings();

        pattern_match();

        return ( 0 );
}
