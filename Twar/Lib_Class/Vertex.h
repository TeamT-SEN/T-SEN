/**
* @file   Vertex.h
* @brief  バーテックスクラス
* @author haga
*/
#ifndef VERTEX_H
#define VERTEX_H

#include "GraphicsDevice.h"
#include "Texture.h"

/**
* バーテックスクラス
*/
class Vertex
{
private:
	IDirect3DDevice9*		m_pD3Device;			//!< デバイス
	float					m_texWidth;		  	    //!< テクスチャーの幅
	float					m_texheight;			//!< テクスチャーの高さ
	float					m_tuMax;				//!< テクスチャーのtu最大値
	float					m_tuMin;				//!< テクスチャーのtu最小値
	float					m_tvMax;				//!< テクスチャーのtv最大値
	float					m_tvMin;				//!< テクスチャーのtv最小値
	DWORD                   m_color[4];				//!< 色の値

public:
	/**
	* コンストラクタ.
	* @param[in] width  幅
	* @param[in] height 高さ
	*/
	Vertex(float width, float height);

	/**
	* コンストラクタ.
	* 数値を指定するときに使用
	* @param[in] width  幅
	* @param[in] height 高さ
	* @param[in] tu	    tu値
	* @param[in] tv		tv値
	*/
	Vertex(float width,float height,float tu,float tv);

	/**デストラクタ*/
	~Vertex();

	/**
	* 通常描画関数<br>
	* テクスチャーの左上に座標をセットする.
	* @param[in] texture テクスチャークラスのポインタ
	* @param[in] posX     X座標 
	* @param[in] posY     Y座標
	*/
	void Draw(Texture* texture, float posX, float posY);

	/**
	* 描画関数<br>
	* テクスチャーの中心に座標をセットする.
	* @param[in] texture テクスチャークラスのポインタ
	* @param[in] posX     X座標
	* @param[in] posY     Y座標
	*/
	void DrawCP(Texture* texture, float posX, float posY);

	/**
	* テクスチャーサイズをセットする関数.
	* @param[in] texWidth  テクスチャーの幅
	* @param[in] texHeight テクスチャーの高さ
	*/
	void SetTexSize(float texWidth, float texHeight);

	/**
	* tu,tv値を設定する関数.
	* @param[in] tuMin tu値の最小値
	* @param[in] tuMax tu値の最大値
	* @param[in] tvMin tv値の最小値
	* @param[in] tvMax tv値の最大値
	*/
	void SetTuTvVal(float tuMin,float tuMax, float tvMin,float tvMax);

	/**
	* テクスチャー色をセットする関数.
	* @param[in] color  色の設定
	*/
	void SetColor(DWORD color);

};

#endif