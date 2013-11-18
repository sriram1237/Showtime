#include "AppResourceId.h"
#include "MetaDataForm.h"
#include <FApp.h>
using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Ui::Scenes;
using namespace Tizen::Ui::Animations;


MetaDataForm::MetaDataForm(void)
{
}

MetaDataForm::~MetaDataForm(void)
{
}

bool
MetaDataForm::Initialize()
{
	Form::Construct(IDF_METADATAFORM);

	return true;
}

result
MetaDataForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	//Header* pHeader = GetHeader();
	//AppAssert(pHeader);
	//pHeader->SetShowState(false);

	SetFormBackEventListener(this);


	return r;
}

result
MetaDataForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void
MetaDataForm::OnSceneActivatedN(const Tizen::Ui::Scenes::SceneId& previousSceneId,
							   const Tizen::Ui::Scenes::SceneId& currentSceneId, Tizen::Base::Collection::IList* pArgs)
{
	if (pArgs != null)
	{
		if (pArgs->GetCount())
		{
			String resultMessage(L"Dear \"");
			String* pStr = dynamic_cast<String*>(pArgs->GetAt(0));
			if (pStr != null)
			{
				resultMessage += *pStr;
				resultMessage += L"\"\n\n";
			}
			pStr = dynamic_cast<String*>(pArgs->GetAt(1));
			if (pStr != null)
			{
				resultMessage += L"Your favorite color is \"";
				resultMessage += *pStr;
				resultMessage += L"\"";
			}
AppLog("%S", pStr->GetPointer());
			Label* pTextBox = static_cast<Label*>(GetControl(IDC_LABEL2));
			AppAssert(pTextBox)
		}
		pArgs->RemoveAll(true);
		delete pArgs;
	}
}

void
MetaDataForm::OnSceneDeactivated(const Tizen::Ui::Scenes::SceneId& currentSceneId,
								const Tizen::Ui::Scenes::SceneId& nextSceneId)
{

}

void
MetaDataForm::PrepareAnimation(const Tizen::Ui::Scenes::SceneId& sceneId, Tizen::Base::Collection::IList* pArgs,

							  Tizen::Ui::Scenes::SceneTransitionAnimationType type, bool formTransition)
{
	// It override default animation. Variable type is original animation type value.
	if (formTransition)
	{
	 	Frame* pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
		if (pFrame)
		{
			FrameAnimator* pFrameAnimator = pFrame->GetFrameAnimator();
			if (pFrameAnimator)
			{
				pFrameAnimator->SetFormTransitionAnimation(FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_ZOOM_OUT, 300,
														   ANIMATION_INTERPOLATOR_BEZIER );
			}
		}
	}
}

void
MetaDataForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source)
{
	SceneManager* pSceneManager = SceneManager::GetInstance();
			AppAssert(pSceneManager);
			pSceneManager->GoBackward(BackwardSceneTransition(SCENE_TRANSITION_ANIMATION_TYPE_RIGHT));

}
