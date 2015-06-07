﻿#ifndef __SCENE_LOBBY_H__
#define __SCENE_LOBBY_H__

#include "cocos2d.h"
#include "PublicApi.h"
#include "AppUser.h"
#include "DialogBuilder.h"
#include "ProgressCircle.h"
#include "TextureLoadingManager.h"
#include "LetterBoard.h"
#include "Sprabel.h"
#include "Ranking.h"
#include "BaccaratMode.h"
#include "SceneIntro.h"
#include "SceneLogin.h"

class SceneLobby : public cocos2d::Layer, public TextureLoadingDelegate, 
	public DialogDelegate,
	public BaccaratModeDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();    
    
    // implement the "static create()" method manually
    CREATE_FUNC(SceneLobby);
	
	// scene life cycle
	virtual void onEnter();
	virtual void onExit();
	virtual void onEnterTransitionDidFinish();
	virtual void onExitTransitionDidStart();

	virtual void onTextureLoadingBegan(TextureLoadingManager* tlm);
	virtual void onTextureLoaded(TextureLoadingManager* tlm);
	virtual void onTextureLoadingEnded(TextureLoadingManager* tlm);

	virtual void onClickPositiveButton(Dialog* pDialog, int index);
	virtual void onClickNegativeButton(Dialog* pDialog, int index);	

	virtual void onSinglePlaySelected(BaccaratMode* pSender);
	virtual void onWorldClassSelected(BaccaratMode* pSender);

	// listener
	void addListener();
	void removeListener();

	// texture resource loading
	void loadResources();
	
	// init background view 
	void initView();
	
	void menuCallback1(Ref* pSender);
	void menuCallback2(Ref* pSender);
	void menuCallback3(Ref* pSender);
	void menuCallback4(Ref* pSender);
	void menuCallback5(Ref* pSender);

private:

	Menu *_menu;
	ProgressCircle *_progressCircle;
	LetterBoard *_letterBoard;
};

#endif // __SCENE_LOBBY_H__
