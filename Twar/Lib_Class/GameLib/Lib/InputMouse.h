﻿/**
* @file		InputMouse.h
* @brief	InputMouseクラスヘッダ
* @author	haga
*/
#ifndef INPUT_MOUSE_H
#define INPUT_MOUSE_H

#include <d3dx9.h>
#include "InputDevice.h"

/**マウスのボタン*/
enum MOUSEBUTTON
{
	MouseLeft,		//!< 左ボタン
	MouseRight,		//!< 右ボタン
	MouseCenter,	//!< 真ん中
	ButtonMAX,
};
/**マウスホイールの状態*/
enum WHEELSTATE
{
	WHEEL_NONE = 0,		//!< 回転していない
	WHEEL_UP = 1,		//!< 奥に回転させている状態
	WHEEL_DOWN = -1,	//!< 手前に回転させている状態
};

/**
* マウス操作に関するクラス
*/
class InputMouse
{
private:
	HWND				 m_hWnd;								//!< ウィンドウハンドル格納
	LPDIRECTINPUTDEVICE8 m_pMouseDevice;						//!< マウスデバイス
	DIMOUSESTATE2		 m_dims;								//!< マウス構造体(ボタン関連)
	INT					 m_wndWid;								//!< ウインドウサイズ幅
	INT					 m_wndHgt;								//!< ウィンドドウサイズ高さ
	LONG				 m_posX;								//!< マウスのx座標
	LONG				 m_posY;								//!< マウスのy座標
	LONG				 m_Wheel;								//!< マウスのホイール
	bool				 m_LDown;								//!< Update時点の左ボタン状態
	bool				 m_RDown;								//!< Update時点の右ボタン状態
	bool				 m_MDown;								//!< Update時点の中ボタン状態
	bool				 m_LAction;								//!< ボタン押した直後だけONになる(クリックを拾うときに)
	bool				 m_RAction;								//!< ボタン押した直後だけONになる(クリックを拾うときに)
	bool				 m_MAction;								//!< ボタン押した直後だけONになる(クリックを拾うときに)
	int					 m_PreMouse[MOUSEBUTTON::ButtonMAX];	//!< マウスのボタンの前の状態を格納する変数
	BTN_STATE			 m_mouse[MOUSEBUTTON::ButtonMAX];		//!< マウスのボタンの状態を格納する変数

	/**マウスの左ボタンの状態確認*/
	bool GetIsLAction() const { return m_LAction; }

	/**マウスの右ボタンの状態確認*/
	bool GetIsRAction() const { return m_RAction; }

	/**マウスの真ん中ボタンの状態確認*/
	bool GetIsMAction() const { return m_MAction; }

	/**
	* 状態を確認する関数
	* @param[in] mouseButton マウスのボタンの種類
	*/
	void CheckState(MOUSEBUTTON mouseButton);

public:
	/**コンストラクタ*/
	InputMouse();
	/**デストラクタ*/
	~InputMouse();

	/**マウスの更新*/
	void UpdateMouse();

	/**
	* マウスの状態を確認する関数
	* @param[in] mouseButton マウスのボタンの種類
	* @return ボタンが押されているかどうか
	*/
	BTN_STATE ChecKMouse(MOUSEBUTTON mouseButton);

	/**
	* マウスホイール状態を取得する関数
	* @return ホイール状態
	*/
	WHEELSTATE GetWheelState();

	/**マウスx座標を取得する*/
	LONG GetPosX() const { return m_posX; }
	/**マウスy座標を取得する*/
	LONG GetPosY() const { return m_posY; }
	/**ホイール状態を取得する*/
	LONG GetWheel() const { return m_Wheel; }

	/**
	* マウスカーソルの描画をONかOFFにする関数.
	* @param[in] isVisible 表示するならtrue,非表示ならfalse
	*/
	void ShowMouseCursor(bool isVisible);

	/**
	* マウスの座標をセット.
	* @param[in] x		  座標x
	* @param[in] y		  座標y
	*/
	void SetMouseCursor(int x, int y);

	/**マウスの座標を中心にあわす*/
	void SetMouseCenter();

	/**マウスの動く範囲をウィンドウ内に制限する関数*/
	void RestrictCursor();
};

#endif // INPUT_MOUSE_H