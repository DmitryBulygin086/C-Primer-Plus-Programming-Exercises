// A text file holds information about a softball team. Each line has data arranged as
// follows:
// 4 Jessie Joybat 5 2 1 1
// The first item is the player’s number, conveniently in the range 0–18. The second item
// is the player’s first name, and the third is the player’s last name. Each name is a single
// word. The next item is the player’s official times at bat, followed by the number of hits,
// walks, and runs batted in (RBIs). The file may contain data for more than one game,
// so the same player may have more than one line of data, and there may be data for
// other players between those lines. Write a program that stores the data into an array of
// structures. The structure should have members to represent the first and last names, the
// at bats, hits, walks, and RBIs (runs batted in), and the batting average (to be calculated
// later). You can use the player number as an array index. The program should read to end-
// of-file, and it should keep cumulative totals for each player.
// The world of baseball statistics is an involved one. For example, a walk or reaching base
// on an error doesn’t count as an at-bat but could possibly produce an RBI. But all this
// program has to do is read and process the data file, as described next, without worrying
// about how realistic the data is.
// The simplest way for the program to proceed is to initialize the structure contents to
// zeros, read the file data into temporary variables, and then add them to the contents of
// the corresponding structure. After the program has finished reading the file, it should
// then calculate the batting average for each player and store it in the corresponding
// structure member. The batting average is calculated by dividing the cumulative number
// of hits for a player by the cumulative number of at-bats; it should be a floating-point
// calculation. The program should then display the cumulative data for each player along
// with a line showing the combined statistics for the entire team.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMELEN 21
#define PLAYERS 19
struct player {
    int number;
    char fname[NAMELEN];
    char lname[NAMELEN];
    int atbats;
    int hits;
    int walks;
    int rbis;
    double batting_avg;
};
void showteamdata(int rostersize, struct player[rostersize]);
int main(void)
{
    struct player players[PLAYERS];

    for (int i = 0; i < PLAYERS; i++)
    {
        players[i] = (struct player) {0, "", "", 0, 0, 0, 0, 0.0};
    }
        
    
    FILE *fp;
    int number;
    char fname[NAMELEN];
    char lname[NAMELEN];
    int atbats;
    int hits;
    int walks;
    int rbis;
    double batting_avg;

    fp = fopen("roster.txt", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Could not open roster.txt\n");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%d %s %s %d %d %d %d\n", &number, fname, 
        lname, &atbats, &hits, 
        &walks, &rbis);
        if (players[number].fname[0] == '\0')
        {
            strncpy(players[number].fname, fname, NAMELEN);
            strncpy(players[number].lname, lname, NAMELEN);
        }

        players[number].atbats += atbats;
        players[number].hits += hits;
        players[number].walks += walks;
        players[number].rbis += rbis;
    }
    
    // Calculate batting average
    for (int i = 0; i < PLAYERS; i++)
    {
        players[i].batting_avg = (double) players[i].hits / (double) players[i].atbats;
    }

    showteamdata(PLAYERS, players);

    return 0;
}

void showteamdata(int rostersize,struct player players[rostersize] )
{
    int atbats = 0, hits = 0, walks = 0, rbis = 0;
    printf("%19s %12s %12s %8s %8s %8s %7s %13s\n", "number", "first name", "last name", "atbats", "hits", "walks", "RBIs", "batting average");
    for (int i = 0; i < rostersize; i++)
    {
        printf("%19d %12s %12s %8d %8d %8d %7d %13lf\n", i, players[i].fname, players[i].lname, 
        players[i].atbats, players[i].hits, players[i].walks, players[i].rbis, players[i].batting_avg);

        // Calculating combined stats
        atbats += players[i].atbats;
        hits += players[i].hits;
        walks += players[i].walks;
        rbis += players[i].rbis;
    }

    printf("Combined stats: %38d %8d %8d %7d %13lf\n", atbats, hits, walks, rbis, (double)hits / (double) atbats);
}