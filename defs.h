#ifndef defsH
#define defsH

#include <stdlib.h>

#define debug
#ifndef debug
#else
#define assert(n) \
if(!(n)) { \
    printf("%s - Failed", #n); \
    printf("On %s ", __DATE__); \
    printf("At %s ", __TIME__); \
    printf("In file ", __FILE__); \
    printf("At line %d\n", __LINE__); \
    exit(1); }
#endif

#define name "Rising Sun"

typedef unsigned long long uLL;

#define boardSquareNum 120
#define maxGameMoves 2048

// Pieces for both colors
enum { empty, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bQ, bK };

// Rank and file definition
enum { fileA, fileB, fileC, fileD, fileE, fileF, fileG, fileH, fileNone };
enum { rank1, rank2, rank3, rank4, rank5, rank6, rank7, rank8, rankNone };


// Side colors
enum { white, black, both };

// Board square defintion
enum {
    a1 = 21, b1, c1, d1, e1, f1, g1, h1,
    a2 = 31, b2, c2, d2, e2, f2, g2, h2,
    a3 = 41, b3, c3, d3, e3, f3, g3, h3,
    a4 = 51, b4, c4, d4, e4, f4, g4, h4,
    a5 = 61, b5, c5, d5, e5, f5, g5, h5,
    a6 = 71, b6, c6, d6, e6, f6, g6, h6,
    a7 = 81, b7, c7, d7, e7, f7, g7, h7,
    a8 = 91, b8, c8, d8, e8, f8, g8, h8, noSquare 
};

enum { FALSE, TRUE };

// Castling definition
enum { wKCastle = 1, wQCastle = 2, bKCastle = 4, bQCastle = 8 };

typedef struct {
    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    uLL posKey;
} strUndo;

typedef struct {
    int pieces[boardSquareNum];
    uLL pawns[3];

    int kingSquare[2];

    int side;
    int enPas;
    int fiftyMove;

    int ply;
    int hisPly;

    int castlePerm;

    uLL posKey;

    int pieceNum[13];
    int bigPieces[3];
    int majorPieces[3];
    int minorPieces[3];

    strUndo history[maxGameMoves];

    // Piece list
    int pList[13][10]; 
} strBoard;

// Macros 
#define fileRankToSquare(f, r) ( (21 + (f)  ) + ( (r) * 10 ) )
// Globals
extern int convert120To64[boardSquareNum];
extern int convert64To120[64];

// Functions
extern void allInit();
#endif