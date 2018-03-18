#pragma once
#include "AITypes.h"
#include "Board.h"
#include "ChessShape.h"
#include <time.h>
#include <iostream>
#include <string>


class AIWine
{
public:
	AIWine();
	~AIWine();
	static const int MaxSize = 28;
	static const int MaxDepth = 50;
	static const int MinDepth = 1;
	static const int MaxCand = 256;

	void restart();
	void turnUndo();
	bool setSize(int size);
	bool isValidPos(int x, int y);
	void turnMove(int x, int y);
	void turnBest(int &x, int &y);
	Cand rootSearch(int depth, int alpha, int beta);
	int search(int depth, int alpha, int beta);

	int nSearched;							//每次思考时,搜索的局面数
	int speed;								//搜索速度
	Cand rootBest;							//根节点返回的最佳点
	Cand rootCand[MaxCand];					//根节点分支
	int nRootCand;							//根节点分支数
	int timeout_turn;						//步时
	int timeout_match;						//局时
	int time_left;							//剩余时间
	long start_time;						//开始时间
	bool terminateAI;						//停止搜索标志

	void delLoseCand();
	void delVctLose();
	void sortCand(Cand cand[], int nCand);
	void showDepthInfo(int depth, Cand best, long td);
	long stopTime() { return start_time + __min(timeout_turn, time_left / 7) - 30; }
	long getTime() { return clock() * 1000 / CLOCKS_PER_SEC; }
	int pointX(int index) { return index >> 5; }
	int pointY(int index) { return index & 31; }
	int makePoint(int x, int y) { return (x << 5) + y; }
	
private:
	Board* board;
	HashTable* hashTable;
};
