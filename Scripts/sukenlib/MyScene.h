#pragma once

/**
*	@file	MyScene.cpp
*	@brief	�V�[���N���X�̐錾�́A�����ł��܂��傤
*	@author	-
*/

#include "Suken.h"

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
	int graphKind;
	int scrollX;
	int scrollY;
	int scrollVX;
	int scrollVY;
	Graph zikiGraph[4];
	Graph mapChip[10];
	MCE map;

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