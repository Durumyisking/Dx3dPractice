#pragma once
#include "Entity.h"
#include "Layer.h"
#include "SceneMgr.h"

#include "Transform.h"
#include "MeshRenderer.h"
#include "SpriteRenderer.h"
#include "Renderer.h"
#include "Texture.h"
#include "Camera.h"
#include "CameraScript.h"

#include "FontWrapper.h"

namespace dru
{
	using namespace enums;
	class CSceneMgr;
	class CScene : public CEntity // 이름과 고유 id를 가진 class
	{
	public:
		CScene();
		virtual ~CScene();

		virtual void Initialize();
		virtual void update();
		virtual void fixedUpdate();
		virtual void render();
		virtual void fontRender();
		virtual void destroy();

		virtual void Enter();
		virtual void Exit();


		void AddGameObject(CGameObj* _GameObj, const eLayerType _eLayer);

		void SetType(CSceneMgr::eSceneType _eType) { mType = _eType; }
		CSceneMgr::eSceneType GetType() const { return mType; }

		CLayer& GetLayer(eLayerType _Type)  { return mLayers[(UINT)_Type]; }

		std::vector<CGameObj*> GetDontDestroyObjects();

		const std::vector<CGameObj*>& GetGameObj(eLayerType _eLayer);

	protected :
		std::vector<CLayer> mLayers;
		CSceneMgr::eSceneType mType;

		std::vector<CGameObj*> mDeadObjects;

		bool mDeleteObj;

	public:
		bool mbPause;

	};

}

