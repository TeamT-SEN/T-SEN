﻿/**
* @file		TitleMenu.h
* @brief	TitleMenuクラスヘッダ
* @author	haga
*/

#ifndef TITLE_MENU_H
#define TITLE_MENU_H

#include <vector>
#include "TitleScene.h"

class Button;
/**
* タイトルメニューの操作を管理するクラス.
*/
class TitleMenu
{
public:
	/**
	* コンストラクタ.
	* @param hasSaveData セーブデータがあるかどうか
	*/
	explicit TitleMenu(bool hasSaveData);

	~TitleMenu();

	/**コントロール関数*/
	TitleScene::STATE Control();

	/**描画関数*/
	void Draw();

private:
	TitleScene::STATE			m_MenuSelectState;		//!< メニューが選んでいるタイトルの状態
	std::vector<Button*>		m_pButton;				//!< ボタンクラス

};

#endif	// TITLE_MENU_H
