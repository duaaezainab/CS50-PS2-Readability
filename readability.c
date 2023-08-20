#include <cs50.h>
#include <stdio.h>

#include <string.h> // to access strlen: int strlen(string s);  - calculate the length of a string
#include <math.h> // to access round: double round(double x);;  - round a number to the nearest integer
#include <ctype.h>


// Problem Set 1 (A)
// Coleman-Liau index. The Coleman-Liau index of a text is designed to output the (U.S.) grade level that is needed to understand some text.
// The formula is: index = 0.0588 * L - 0.296 * S - 15.8
// L is the average number of letters per 100 words in the text, total letters*100/total words
// S is the average number of sentences per 100 words in the text,  total sentences*100/total words
// Before Grade 1, Grade 1-16, Grade 16+


int total_letters(string text);                                               //declare function 1 charachters minus spaces
int total_words(string text);                                                 //declare function 2 spaces + 1
int total_lines(string text);                                                 //declare function 3 Indicators: .,?,!


int main(void)
{
  string text = get_string("Text: ");
  float L = ( 100.0 * total_letters(text) ) / total_words(text);                     // call func 1 and func 2

  float S = ( 100.0 * total_lines(text) ) / total_words(text);                       // call func 2 and func 3

  float index=(0.0588 * L) - (0.296 * S) - 15.8;

  int x = round(index);

  if (x<1)
 {
  printf("%s\n","Before Grade 1");
 }
 if (x>16)
 {
  printf("%s\n","Grade 16+");
 }
if (x>=1 && x<=16)
 {
   printf("Grade %i\n", x);
 }

}


//----------------------------------------------------------------------------

// Define function 1: Count Total Letters in the Text.
int total_letters(string text)
  {
    int letter_count = 0;
    for (int i = 0; i < strlen(text); i++)
     {
      if (isalpha(text[i]) != 0)
    {
      letter_count++;
    }
     }

    return letter_count;
  }

// Define function 2:  Count Total Words in the Text.
int total_words(string text)
  {
    int spaces = 0;

    for (int i = 0; i < strlen(text); i++)
     {
        if(text[i]== ' ')  // if text is equal to sapce then count it.
            {
              spaces++;
            }

     }

    int  word_count=spaces+1;
    return word_count;
  }

// Define function 3: Count Total Lines in the Text.
int total_lines(string text)
{
    int line_count = 0;
    for (int i = 0; i < strlen(text); i++)
     {
       if ( (text[i] == '.') || (text[i]== '?') || (text[i] == '!') )  // if letter is (!,.,or ?)  ASCII
       {
        line_count++;
       }
     }

    return line_count;
}