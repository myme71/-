#include "MyScene.h"

void CSGame::Start() {
	zikix=0;
	zikiy=0;
	zikivx=0;
	zikivy=0;
	test=0;
	zikiGraph[0] = "myme/sinom0.png";
	zikiGraph[1] = "myme/sinol0.png";
	zikiGraph[2] = "myme/sinou0.png";
	zikiGraph[3] = "myme/sinor0.png";
	graphKind = 0;
	LoadDivGraph("myme/mapChip.png",10,2,5,40,40,mapChip);
	map="myme/MCE/test.mce";
}

void CSGame::Loop() {
	if(0==zikix%40 && 0==zikiy%40 && scrollX%40==0){
		zikivx=0;
		zikivy=0;
		scrollVX = 0;
		scrollVY = 0;
		if(Input.GetKeyDown(Input.key.DOWN)){
			if (map.Get(map.layer.A, (zikix+scrollX) / 40, (zikiy+scrollY)/ 40 + 1) <= 8) {
				if (zikiy < 300) {
					zikivx = 0;
					zikivy = 5;
				}
				if (zikiy >= 300) {
					scrollVY = 5;
				}
			}
			graphKind=0;
		}
		if (Input.GetKeyDown(Input.key.RIGHT)){
			if (map.Get(map.layer.A, (zikix + scrollX) / 40 + 1, (zikiy + scrollY) / 40 )<= 8) {
				if (zikix < 400) {
					zikivx = 5;
					zikivy = 0;
				}
				if (zikix >= 400) {
					scrollVX = 5;
				}
			}
			graphKind=1;
		}
		if(Input.GetKeyDown(Input.key.UP)){
			if (map.Get(map.layer.A, (zikix + scrollX) / 40, (zikiy + scrollY) / 40 - 1) <= 8) {
				zikivx = 0;
				zikivy = -5;
			}
			graphKind=2;
		}
		if(Input.GetKeyDown(Input.key.LEFT)){
			if (map.Get(map.layer.A, (zikix + scrollX) / 40 - 1, (zikiy + scrollY) / 40) <= 8) {
				zikivx = -5;
				zikivy = 0;
			}
			graphKind=3;
		}
		
	}
	zikix+=zikivx;
	zikiy+=zikivy;

	scrollX += scrollVX;
	scrollY += scrollVY;

	if(Input.GetKeyEnter(Input.key.SPACE)){
		FlipScene(new Menu(*this));
	}
}

void CSGame::Draw() {
	for(int i=0;i<20;i++){
		for(int j=0;j<15;j++){
			mapChip[map.Get(map.layer.A,i,j)-1].Draw(40*i-scrollX,40*j-scrollY);
		}
	}

	

	zikiGraph[graphKind].Draw(zikix,zikiy-40);
}

void CSGame::End() {

}

void CSGame::Menu::Start() {

}

void CSGame::Menu::Loop() {
	if(Input.GetKeyEnter(Input.key.SPACE)){
		game.RemoveScene();
	}
}

void CSGame::Menu::Draw() {
	DrawBox(40,40,160,160,BLUE,TRUE);
}

void CSGame::Menu::End() {

}

CSGame::Menu::Menu(CSGame& game):game(game){}