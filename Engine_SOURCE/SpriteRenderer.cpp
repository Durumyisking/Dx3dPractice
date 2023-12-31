#include "SpriteRenderer.h"
#include "GameObj.h"
#include "Transform.h"
#include "Animator.h"

namespace dru
{
	CSpriteRenderer::CSpriteRenderer()
		: CBaseRenderer(eComponentType::Renderer)
	{
	}

	CSpriteRenderer::~CSpriteRenderer()
	{
	}

	void CSpriteRenderer::Initialize()
	{
		CBaseRenderer::Initialize();
	}

	void CSpriteRenderer::update()
	{
		CBaseRenderer::update();
	}

	void CSpriteRenderer::fixedUpdate()
	{
		CBaseRenderer::fixedUpdate();
	}

	void CSpriteRenderer::render()
	{
		GetOwner()->GetComponent<CTransform>()->SetConstantBuffer();

		GetMesh()->BindBuffer();
		GetMaterial()->Bind();


		CAnimator* animator = GetOwner()->GetComponent<CAnimator>();

		if (animator)
		{
			animator->Binds();
		}	

		GetMesh()->Render();

		GetMaterial()->Clear();
			
		if (animator)
			animator->Clear();

		CBaseRenderer::render();
	}


}