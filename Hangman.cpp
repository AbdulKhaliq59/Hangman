#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    fstream file;
    file.open("words.txt",ios::in);

    cout<<"Please enter a word to play (0 for random):";
    int choice;
    
    bool valid=false;
    while(!valid)
    {
        cin>>choice;
        if(choice>=0 && choice<=20)
        {
            valid=true;
        }
        else
        {
            cout<<"Error. Please Enter a number in the range 0-20:";
        }
    }
    //Choosing word Randomly
    if(choice==0)
    {
        choice = rand() % 20 +1;
    }
    string word;
    bool atWord=false;
    int wordNum=1;

    while (!atWord)
    { 
     file>>word;
      if(wordNum == choice)  
      {
        atWord=true;
      }
     wordNum++;
    }
    string blanks = word;
    //Hidden Character to guess for
    for(char& c :blanks)
    {
        c='*';
    }
    int guesses=5;

    bool gameOver=false;
    while(!gameOver)
    {
        cout<<"The Word is "<<blanks<<'\n';
        cout<<"You\'ve "<<guesses<<" guesses remaining.\n";
        cout<<"Please enter a letter to guess:";
        char letter;
        cin>>letter;
        int i=0;
        bool match = false;
        for(char c: word)
        {
            if(letter == c)
            {
                blanks[i]=letter;
                match=true;
            }  
            i++;
        }
         if(!match)
            {
                cout<<"Sorry, but the word doesn't contain a "<<letter<<"\n";
                guesses --;
            }
        if(blanks== word)
        {
            gameOver=true;
            cout<<"Congratulations! You are such a great game player. \n";
            cout<<"The word was "<<blanks<<".\n";
        }
        if(guesses==0)
        {
            gameOver=true;
            cout<<"You\'re out of guesses. I am sure you\'ll win next time." 
            <<"Or You can buy our hint book only for $1.99 \n";
        }
    }
    return 0;
} 
