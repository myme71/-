#pragma once

/**
*	@file	MyScene.cpp
*	@brief	�V�[���N���X�̐錾�́A�����ł��܂��傤
*	@author	-
*/

#include "Suken.h"
#include "Window.h"

class CSTitle :public CScene {
	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	FlipScene���ꂽ���ɌĂяo�����
	void End();
};

class CSGame :public CScene {
	//�`�ϐ��錾�`

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

	//�������@�摜�̃��[�h�Ȃǂ�
	void Start();
	//�����@���t���[���Ă΂��
	void Loop();
	//�`��@���t���[���Ă΂��
	void Draw();
	//��Еt��	�K�v�Ȃ�g����
	void End();

	class Menu:public CScene{
		CSGame& game;

		//�������@�摜�̃��[�h�Ȃǂ�
		void Start();
		//�����@���t���[���Ă΂��
		void Loop();
		//�`��@���t���[���Ă΂��
		void Draw();
		//��Еt��	�K�v�Ȃ�g����
		void End();

	public:
		Menu(CSGame& game);
	};
};