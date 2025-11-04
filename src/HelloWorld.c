#include <stdio.h>

// Print "Hello, world!
void Exercise1_1()
{
    printf("Hello, world!\n");
}

// Try to print special characters
void Exercise1_2()
{
    printf("Hello, characters! : \a \t \\ \" Testing :)  \n");
}

// Add a header to Fahrenheit -> Celsius chart
void Exercise1_3()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Fahrenheit | Celsius\n");
    
    while(fahr<= upper)
    {
        celsius = (5.0/9.0) *(fahr-32.0);
        printf("%10.0f | %8.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

// Print a Celsius -> Fahrenheit conversion table
void Exercise1_4()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -60;
    upper = 140;
    step = 20;

    celsius = lower;

    printf("Celsius | Fahrenheit\n");
    
    while(celsius<= upper)
    {
        fahr = ((9.0/5.0) *(celsius)) + 32.0;
        printf("%7.1f | %10.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

// Print the table in reverse order
void Exercise1_5()
{
    int fahr;

    for(fahr = 300; fahr >= 0; fahr-=20)
    {
        printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32));
    }

}

// Verify that the expression for c is 0 or 1.
void Exercise1_6()
{
    int c;
    c = getchar() != EOF;
    if(c == 0 || c ==1)
    {
        printf("c is equal to a boolean value. \n");
    }
    else
    {
        printf("c is not equal to a boolean value. \n");
    }
}

// Write a program that prints the value of "EOF"
void Exercise1_7()
{
    printf("The decimal value of \"EOF\" is %d \n", EOF);
}

// Write a program that counts tabs, spaces, and newlines
void Exercise1_8()
{
    int c, count;

    count = 0;

    printf("Count \\n, \\t, and spaces. To finish in Windows: press Enter, then Ctrl + Z, then Enter again.\n");
    while(( c = getchar()) != EOF)
    {
        if(c == '\n' || c == '\t' || c == ' ')
        {
            ++count;
        }
    }

    printf("%d\n",count);

}

// Copy input to output, replacing multiple spaces with a single one.
void Exercise1_9()
{
    int c;
    unsigned char bLastCharWasEmpty = 0;
    
    printf("To finish in windows, press Enter, then Ctrl + Z, then Enter again.\n");
    
    while(( c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            if(!bLastCharWasEmpty)
            {
                bLastCharWasEmpty = 1;
                putchar(' ');
            }
        }
        else
        {
            bLastCharWasEmpty = 0;
            putchar(c);
        }
    }
}

// Write a program to make visible: \t \b and //  
void Exercise1_10()
{
    int c;
    
    printf("To finish in windows, press Enter, then Crtl + Z, then Enter again.\n");
    
    while(( c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            printf("\\t");
        }
        else if(c == '\b')
        {
            printf("\\b"); // Hard to test on modern consoles
        }
        else if(c == '\\')
        {
            printf("\\\\");
        }
        else
        {
            putchar(c);
        }
    }
}

// Print one word per line
void Exercise1_12()
{
    int c;

    while((c = getchar()) != EOF )
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            putchar('\n');             
        }
        else
        {
            putchar(c);
        }
    }
}

#define MaxLetters_Exercise1_13 10

// Print Histogram of word lengths
void Exercise1_13()
{
    int c, i, j, characterCount;
    int frequency[MaxLetters_Exercise1_13];

    for(i = 0; i < MaxLetters_Exercise1_13; ++i)
    {
        frequency[i] = 0;
    } 

    while((c = getchar()) != EOF)
    {
        if( c == ' ')
        {
            if(characterCount>=0 && characterCount < MaxLetters_Exercise1_13)
            {
                ++frequency[characterCount];
            }
            characterCount=0;
        }
        else
        {
            ++characterCount;
        }
    }

    printf("Histogram of word lengths:\n\n");
    for(i = 0; i < MaxLetters_Exercise1_13; ++i)
    {
        printf("%2d : ", i);
        for(j = 0; j < frequency[i]; ++j)
        {
            putchar('#');
        }
        printf("\n\n");     
    } 

}

#define MaxLetters_Exercise1_14 'Z'-'A'

// Print Histogram of character counts from A–Z:
void Exercise1_14()
{
    int c, i, j;
    int frequency[MaxLetters_Exercise1_14];

    for(i = 0; i < MaxLetters_Exercise1_14; ++i)
    {
        frequency[i] = 0;
    } 

    while((c = getchar()) != EOF)
    {
        if( c >= 'A' && c <= 'Z' )
        {
            ++frequency[c - 'A'];
        }
    }

    printf("Histogram of character counts from A–Z:\n\n");
    for(i = 0; i < MaxLetters_Exercise1_14; ++i)
    {
        putchar('A'+i);
        printf(" : ");
        for(j = 0; j < frequency[i]; ++j)
        {
            putchar('#');
        }
        printf("\n\n");     
    } 
}

int CelsiusToFahrenheit(int celsius)
{
    return ((9.0/5.0) *(celsius)) + 32.0;
}

// Rewrite the Celsius exercise using a function
void Exercise1_15()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -60;
    upper = 140;
    step = 20;

    celsius = lower;

    printf("Celsius | Fahrenheit\n");
    
    while(celsius<= upper)
    {
        fahr = CelsiusToFahrenheit(celsius);
        printf("%7.1f | %10.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}

int main() 
{
    printf("\n");
    Exercise1_15();
    printf("\n");
    return 0;
}
