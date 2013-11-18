
#include <new>
#include "FormFactory.h"
#include "ShowTimeMainForm.h"
#include "FeatureForm.h"
#include "MetaDataForm.h"
#include "ChannelForm.h"
#include "SettingsForm.h"


using namespace Tizen::Ui::Scenes;

// Definitions of extern.
const wchar_t* FORM_MAIN = L"FormMain";
const wchar_t* FORM_FEATURE = L"FormFeature";
const wchar_t* FORM_CHANNEL = L"FormChannel";
const wchar_t* FORM_METADATA = L"FormMetadata";
const wchar_t* FORM_SETTINGS=L"FormSettings";

FormFactory::FormFactory(void) {
}

FormFactory::~FormFactory(void) {
}

Tizen::Ui::Controls::Form*
FormFactory::CreateFormN(const Tizen::Base::String& formId,
		const Tizen::Ui::Scenes::SceneId& sceneId) {
	Tizen::Ui::Controls::Form* pNewForm = null;
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);

	if (formId == FORM_MAIN) {
		AppLog("Main");
		ShowTimeMainForm* pForm = new (std::nothrow) ShowTimeMainForm();
		pForm->Initialize();
		pNewForm = pForm;
	} else if (formId == FORM_FEATURE) {
		AppLog("Feature");
		FeatureForm* pForm = new (std::nothrow) FeatureForm();
		 pForm->Initialize();
		 pSceneManager->AddSceneEventListener(sceneId, *pForm);
		 pSceneManager->SetSceneAnimationProvider(sceneId, pForm);
		pNewForm = pForm;
	}

	else if (formId == FORM_METADATA) {
		AppLog("Metadata");
		MetaDataForm* pForm = new (std::nothrow) MetaDataForm();
		pForm->Initialize();
		pSceneManager->AddSceneEventListener(sceneId, *pForm);
			pSceneManager->SetSceneAnimationProvider(sceneId, pForm);
		pNewForm = pForm;
	} else if (formId == FORM_CHANNEL) {
		AppLog("Channel");
		ChannelForm* pForm = new (std::nothrow) ChannelForm();
		pForm->Initialize();
		pNewForm = pForm;
	}
	 else if (formId == FORM_SETTINGS) {
			AppLog("Channel");
			SettingsForm* pForm = new (std::nothrow) SettingsForm();
			pForm->Initialize();
			pNewForm = pForm;
		}

	return pNewForm;
}
