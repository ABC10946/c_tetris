#ifndef TETRIS_H
#define TETRIS_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ncurses.h>
#include <time.h>
#define WIDTH 12
#define HEIGHT 21

typedef enum
{
	Tet_I,
	Tet_O,
	Tet_S,
	Tet_Z,
	Tet_J,
	Tet_L,
	Tet_T
} TetriminoKind;

typedef enum
{
	Space,
	Block,
	Operating,
	Wall
} BlockKind;

typedef enum
{
	Up,
	Down,
	Left,
	Right
} Direction;

BlockKind field[HEIGHT][WIDTH];

extern int i_tet[4][4][2];
extern int o_tet[4][4][2];
extern int s_tet[4][4][2];
extern int z_tet[4][4][2];
extern int j_tet[4][4][2];
extern int l_tet[4][4][2];
extern int t_tet[4][4][2];

typedef struct Tetrimino
{
	int (*tet)[];
} Tetrimino;

typedef struct OperateTet
{
	int x;
	int y;
	TetriminoKind kind;
	int rotation_id;
} OperateTet;

Tetrimino *tetriminos(TetriminoKind kind, int rotation_id);

OperateTet opTet;

OperateTet nextOpTet;

TetriminoKind kinds[7];

void init_field();

void put_tetrimino(int tetrimino[4][2], int x, int y);

void print_field();

void clear_operated_tetrimino();

bool setable_operated_tet(OperateTet opTet);

void change_to_block(OperateTet opTet);

void move_all_block(int pivot, int step);

void delete_line(int line_num);

bool is_full_line(int line_num);

void reset_game();

void reset_operated_tetrimino();

void left_proc();

void right_proc();

void fall_proc();

void up_proc();

#endif