#include "MyScene.h"

void CSGame::Start() {
	zikix=0;
	zikiy=0;
	zikivx=0;
	zikivy=0;
	test=0;
	llo =false;
	zikiGraph="myme/sinom2.png";
	for(int i=0;i<100;i++){
		textF[i]=false;
	}


	LoadDivGraph("myme/mapChip.png",10,2,5,40,40,mapChip);
	map="myme/MCE/test.mce";
	text=new CTextWindow("");
}

void CSGame::Loop() {
	if( 0==zikix%40 && 0==zikiy%40){
		zikivx=0;
		zikivy=0;
		if(Input.GetKeyDown(Input.key.DOWN)){
			zikivx=0;
			zikivy=5;

		}
		if(Input.GetKeyDown(Input.key.RIGHT)){
			zikivx=5;
			zikivy=0;

		}
		if(Input.GetKeyDown(Input.key.UP)){
			zikivx=0;
			zikivy=-5;

		}
		if(Input.GetKeyDown(Input.key.LEFT)){
			zikivx=-5;
			zikivy=0;
			
		}
	}
	zikix+=zikivx;
	zikiy+=zikivy;

	if(Input.GetKeyEnter(Input.key.A)){
		llo=true;
		text->PushText("Ž„‚Í/naa/n‚±‚±‚±/n‚²‚²‚²‚‡/n‚ ‚©‚³/n‚ ‚ ‚ /n‚±‚±‚±/n‚“‚“‚“/n‚Û‚Û‚Û‚¶‚¶‚¶‚¶‚¶‚¶‚¶‚„‚†‚„‚†‚„‚ˆ‚†‚“‚„‚†‚©‚„‚™‚ƒ‚ª‚¢‚“‚‡‚µ");
	}
	

	if(llo==true){
		text->Loop();
	}

	if(Input.GetKeyEnter(Input.key.SPACE)){
		FlipScene(new Menu(*this));
	}
}

void CSGame::Draw() {
	for(int i=0;i<20;i++){
		for(int j=0;j<15;j++){
			mapChip[map.Get(map.layer.A,i,j)-1].Draw(40*i,40*j);
		}
	}

	if(llo==true){
		text->Draw();
	}

	zikiGraph.Draw(zikix,zikiy);
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