#pragma once

#include "UIControl.h"

class CUITitleBar : public CUIControl
{
	friend class CUIObject;

protected:
	CUITitleBar();
	CUITitleBar(const CUITitleBar& control);
	virtual ~CUITitleBar();

protected:
	bool		m_bMouseCollision;
	Vector3		m_vPrevPos;
	bool		m_bDown;
	bool		m_bPush;
	bool		m_bUp;
	bool		m_bDrag;
	
public:
	virtual bool Init();
	virtual void Start();
	virtual void Update(float fTime);
	virtual void PostUpdate(float fTime);
	virtual void PrevRender();
	virtual void Render();
	virtual void PostRender();
	virtual CUITitleBar* Clone();
	virtual void CollisionMouse(const Vector2& vMousePos, float fTime);
	virtual void CollisionReleaseMouse(const Vector2& vMousePos, float fTime);
};

