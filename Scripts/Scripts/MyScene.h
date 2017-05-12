#pragma once

/**
*	@file	MyScene.cpp
*	@brief	シーンクラスの宣言は、ここでしましょう
*	@author	-
*/

#include "Suken.h"
#include "Window.h"

class CSTitle :public CScene {
	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	FlipSceneされた時に呼び出される
	void End();
};

class CSGame :public CScene {
	//～変数宣言～

	int zikix;
	int zikiy;
	int zikivx;
	int zikivy;
	int test;
	bool textF[100],llo;
	Graph zikiGraph;
	Graph mapChip[10];
	MCE map;
	CTextWindow *text;

	//初期化　画像のロードなども
	void Start();
	//処理　毎フレーム呼ばれる
	void Loop();
	//描画　毎フレーム呼ばれる
	void Draw();
	//後片付け	必要なら使おう
	void End();

	class Menu:public CScene{
		CSGame& game;

		//初期化　画像のロードなども
		void Start();
		//処理　毎フレーム呼ばれる
		void Loop();
		//描画　毎フレーム呼ばれる
		void Draw();
		//後片付け	必要なら使おう
		void End();

	public:
		Menu(CSGame& game);
	};
};