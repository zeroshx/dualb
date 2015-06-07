﻿#ifndef __SCENE_LOGIN_H__
#define __SCENE_LOGIN_H__

#include "cocos2d.h"
#include "PublicApi.h"
#include "AppUser.h"
#include "DialogBuilder.h"
#include "ProgressCircle.h"
#include "TextureLoadingManager.h"

class SceneLogin : public cocos2d::Layer, public TextureLoadingDelegate, public DialogDelegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();    
    
    // implement the "static create()" method manually
    CREATE_FUNC(SceneLogin);
	
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

	// listener
	void addListener();
	void removeListener();

	// texture resource loading
	void loadResources();
	
	// init background view 
	void initView();
	

private:

	ProgressCircle *_progressCircle;
};

#endif // __SCENE_LOGIN_H__
