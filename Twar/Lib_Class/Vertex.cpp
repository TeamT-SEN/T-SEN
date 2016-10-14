/**
* @file   Vertex.h
* @brief  �o�[�e�b�N�X�N���X��cpp
* @author haga
*/
#include "Vertex.h"


// �R���X�g���N�^�i�ʏ�j
Vertex::Vertex(float width, float height) :
m_pD3Device(GraphicsDevice::GetInstance().GetDevice()),
m_texWidth(width),
m_texheight(height),
m_texDepth(0.5f),
m_tuMax(1.0f),
m_tvMax(1.0f),
m_tuMin(0.0f),
m_tvMin(0.0f)
{
	m_color[0] = 0xFFFFFFFF;
	m_color[1] = 0xFFFFFFFF;
	m_color[2] = 0xFFFFFFFF;
	m_color[3] = 0xFFFFFFFF;
}

// �R���X�g���N�^(�l���Z�b�g)
Vertex::Vertex(float width, float height, float tu, float tv) :
m_pD3Device(GraphicsDevice::GetInstance().GetDevice()),
m_texWidth(width),
m_texheight(height),
m_texDepth(0.5f),
m_tuMax(tu),
m_tvMax(tv),
m_tuMin(0.0f),
m_tvMin(0.0f)
{
	m_color[0] = 0xFFFFFFFF;
	m_color[1] = 0xFFFFFFFF;
	m_color[2] = 0xFFFFFFFF;
	m_color[3] = 0xFFFFFFFF;

}

// �R���X�g���N�^(Z���W���Z�b�g����)
Vertex::Vertex(float width, float height, float depth, float tu, float tv) :
m_pD3Device(GraphicsDevice::GetInstance().GetDevice()),
m_texWidth(width),
m_texheight(height),
m_texDepth(depth),
m_tuMax(tu),
m_tvMax(tv),
m_tuMin(0.0f),
m_tvMin(0.0f)
{
	m_color[0] = 0xFFFFFFFF;
	m_color[1] = 0xFFFFFFFF;
	m_color[2] = 0xFFFFFFFF;
	m_color[3] = 0xFFFFFFFF;
}

// �f�X�g���N�^
Vertex::~Vertex()
{
}

// �`��
void Vertex::Draw(Texture* texture, float posX, float posY)
{
	CUSTOMVERTEX vtex[] = {
		{		0.0f,		 0.0f, m_texDepth, 1.0f, m_color[0], m_tuMin, m_tvMin },
		{ m_texWidth,		 0.0f, m_texDepth, 1.0f, m_color[1], m_tuMax, m_tvMin },
		{ m_texWidth, m_texheight, m_texDepth, 1.0f, m_color[2], m_tuMax, m_tvMax },
		{		0.0f, m_texheight, m_texDepth, 1.0f, m_color[3], m_tuMin, m_tvMax },
	};

	for (int i = 0; i < 4; i++)
	{
		vtex[i].x += posX;
		vtex[i].y += posY;
	}

	texture->RenderTex(vtex);
}

// �`�� ������Z���W�ǉ�
void Vertex::Draw(Texture* texture, float posX, float posY, float posZ)
{
	CUSTOMVERTEX vtex[] = {
		{		0.0f, m_texheight,	 	 0.0f, 1.0f, m_color[0], m_tuMin, m_tvMin },
		{ m_texWidth, m_texheight,		 0.0f, 1.0f, m_color[1], m_tuMax, m_tvMin },
		{ m_texWidth, m_texheight, m_texDepth, 1.0f, m_color[2], m_tuMax, m_tvMax },
		{		0.0f, m_texheight, m_texDepth, 1.0f, m_color[3], m_tuMin, m_tvMax },
	};

	for (int i = 0; i < 4; i++)
	{
		vtex[i].x += posX;
		vtex[i].y += posY;
		vtex[i].z += posZ;
	}

	texture->RenderTex(vtex);
}

// �`��(�e�N�X�`���[�̒��S�ɍ��W�����킹��)
void Vertex::DrawCP(Texture* texture, float posX, float posY)
{
	CUSTOMVERTEX vtex[] = {
		{ -m_texWidth, -m_texheight, m_texDepth, 1.0f, m_color[0], m_tuMin, m_tvMin },
		{  m_texWidth, -m_texheight, m_texDepth, 1.0f, m_color[1], m_tuMax, m_tvMin },
		{  m_texWidth,  m_texheight, m_texDepth, 1.0f, m_color[2], m_tuMax, m_tvMax },
		{ -m_texWidth,  m_texheight, m_texDepth, 1.0f, m_color[3], m_tuMin, m_tvMax },
	};

	for (int i = 0; i < 4; i++)
	{
		vtex[i].x += posX;
		vtex[i].y += posY;
	}
	texture->RenderTex(vtex);
}

// �`��(�e�N�X�`���[�̒��S�ɍ��W�����킹��)������Z���W�ǉ�
void Vertex::DrawCP(Texture* texture, float posX, float posY, float posZ)
{
	CUSTOMVERTEX vtex[] = {
		{ -m_texWidth, m_texheight, -m_texDepth, 1.0f, m_color[0], m_tuMin, m_tvMin },
		{  m_texWidth, m_texheight, -m_texDepth, 1.0f, m_color[1], m_tuMax, m_tvMin },
		{  m_texWidth, m_texheight,  m_texDepth, 1.0f, m_color[2], m_tuMax, m_tvMax },
		{ -m_texWidth, m_texheight,  m_texDepth, 1.0f, m_color[3], m_tuMin, m_tvMax },
	};

	for (int i = 0; i < 4; i++)
	{
		vtex[i].x += posX;
		vtex[i].y += posY;
		vtex[i].z += posZ;
	}
	texture->RenderTex(vtex);
}

// �e�N�X�`���[�T�C�Y���Z�b�g����֐�
void Vertex::SetTexSize(float texWidth, float texHeight)
{
	m_texWidth = texWidth;
	m_texheight = texHeight;
}

// tu,tv�l��ݒ肷��֐�
void Vertex::SetTuTvVal(float tuMin, float tuMax, float tvMin, float tvMax)
{
	m_tuMin = tuMin;
	m_tvMin = tvMin;
	m_tuMax = tuMax;
	m_tvMax = tvMax;
}

// �F��ݒ肷��֐�
void Vertex::SetColor(DWORD color)
{
	for (int i = 0; i < 4; i++)
	{
		m_color[i] = color;
	}
}