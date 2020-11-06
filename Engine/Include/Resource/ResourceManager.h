#pragma once

#include "../GameEngine.h"

class CResourceManager
{
#ifdef _EDITOR
	friend class CPlayerEditDlg;
#endif

private:
	System* m_pSystem;
	ChannelGroup* m_pMasterGroup;

private:
	//2D �⺻ �簢��
	class CMesh2D* m_pDefault2DMesh;

	//�⺻ UI �簢��
	class CMesh2D* m_pDefaultUIMesh;

	//UI �⺻ Texture
	class CTexture* m_pDefaultUITexture;

	//Mesh ���� Map
	unordered_map<string, class CMesh*>		m_mapMesh;

	//Material ���� Map
	unordered_map<string, class CMaterial*> m_mapMaterial;

	//Texture ���� Map
	unordered_map<string, class CTexture*> m_mapTexture;

	//AnimationSequence���� Map
	unordered_map<string, class CAnimation2DSequence*> m_mapAnim2D;

	//Sound,Channel���� Map
	unordered_map<string, class CSound*>		m_mapSound;
	unordered_map<string, class ChannelGroup*>	m_mapChannelGroup;

	//Sampler
	//-----------------------------------
	ID3D11SamplerState* m_pPointSmp;
	ID3D11SamplerState* m_pLinearSmp;
	ID3D11SamplerState* m_pAnisotropicSmp;
	//-----------------------------------

public:
	//2D �⺻ �簢�� Get�Լ�
	class CMesh2D* GetDefault2DMesh() const;
	//UI �⺻ �簢�� Get�Լ�
	class CMesh2D* GetDefaultUIMesh()	const;
	//UI �⺻ Texture Get�Լ�
	class CTexture* GetDefaultUITexture()	const;
public:
	bool Init();

public:
	bool CreateMesh(MESH_TYPE eType, const string& strName,
		void* pVertices, int iVtxCount, int iVtxSize,
		D3D11_USAGE eVtxUsage,
		D3D11_PRIMITIVE_TOPOLOGY ePrimitive, void* pIndices = nullptr,
		int iIdxCount = 0, int iIdxSize = 0,
		D3D11_USAGE eIdxUsage = D3D11_USAGE_DEFAULT,
		DXGI_FORMAT eFmt = DXGI_FORMAT_UNKNOWN);
	void ReleaseMesh(const string& strName);
	class CMesh* FindMesh(const string& strName);

public:
	//Material �Լ�
	//-------------------------------------------------
	class CMaterial* CreateMaterial(const string& strName);
	void ReleaseMaterial(const string& strName);
	class CMaterial* FindMaterial(const string& strName);
	//-------------------------------------------------
public:
	//�ش� �̸��� ���� Texture Load
	//-------------------------------------------------
	bool LoadTexture(const string& strName,
		const TCHAR* pFileName,
		const string& strPathName = TEXTURE_PATH);
	bool LoadTextureFullPath(const string& strName,
		const TCHAR* pFullPath);
	//-------------------------------------------------

	//vector�� ����ִ� ��� Texture Load
	//-------------------------------------------------
	bool LoadTexture(const string& strName,
		const vector<const TCHAR*>& vecFileName,
		const string& strPathName = TEXTURE_PATH);
	bool LoadTextureFullPath(const string& strName,
		const vector<const TCHAR*>& vecFullPath);
	//-------------------------------------------------

	void ReleaseTexture(const string& strName);

	class CTexture* FindTexture(const string& strName);

public:
	//Animation2DSequence �Լ�
	//-------------------------------------------------
	bool CreateAnimation2DSequence(const string& strName,
		class CTexture* pTexture, float fPlayTime = 1.f,
		float fPlayRate = 1.f);
	bool LoadAnimation2DSequence(const string& strName,
		const char* pFileName,
		const string & strPathName = ANI_PATH);
	bool LoadAnimation2DSequence(const char* pFileName,
		const string& strPathName = ANI_PATH);
	void AddAnimation2DFrame(const string& strName,
		const Vector2& vStart, const Vector2& vEnd);
	void SetAnimation2DFrame(const string& strName,
		int iCount);
	void ReleaseAnimation2DSequence(const string& strName);
	class CAnimation2DSequence* FindAnim2DSequence(const string& strName);
	void AddAnimation2DNotify(const string& strSequence,
		const string& strName, int iFrame);
	//-------------------------------------------------

public:
	//Sound�Լ�
	//-------------------------------------------------
	bool LoadSound(const string& strGroup, bool bLoop,
		const string& strName, const char* pFileName,
		const string& strPathName = SOUND_PATH);
	class CSound* FindSound(const string& strName);
	bool CreateChannelGroup(const string& strName);
	ChannelGroup* FindChannelGroup(const string& strName);
	void ReleaseSound(const string& strName);
	void SetVolume(int iVolume);
	void SetGroupVolume(const string& strGroup, int iVolume);
	bool SoundPlay(const string& strName);
	bool SoundStop(const string& strName);
	bool SoundPause(const string& strName);
	bool SoundResume(const string& strName);
	//-------------------------------------------------

private:
	void InitFMOD();

private:
	ID3D11SamplerState* CreateSampler(D3D11_FILTER eFilter);

	DECLARE_SINGLE(CResourceManager)
};