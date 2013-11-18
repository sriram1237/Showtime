/*
 * ShowTimeRegister.cpp
 *
 *  Created on: Jun 12, 2013
 *      Author: surendran
 */

#include "ShowTimeRegister.h"
#include "FormFactory.h"
#include "PanelFactory.h";
#include "SceneTransitionPolicyProvider.h"

using namespace Tizen::Ui::Scenes;

const wchar_t* SCENE_MAIN_FORM = L"ScnMainForm";
const wchar_t* SCENE_FEATURE_FORM = L"ScnFeatureForm";
const wchar_t* SCENE_UPCOMING_TAB = L"ScnUpcomingTab";
const wchar_t* SCENE_CHANNEL_FORM = L"ScnChannelForm";
const wchar_t* SCENE_METDATA_FORM = L"ScnMetadataForm";
const wchar_t* SCENE_SETTINGS_FORM = L"ScnSettingsForm";

ShowTimeRegister::ShowTimeRegister() {
	// TODO Auto-generated constructor stub

}

ShowTimeRegister::~ShowTimeRegister() {
	// TODO Auto-generated destructor stub
}

void ShowTimeRegister::RegisterAllScenes(void) {
	static const wchar_t* PANEL_BLANK = L"";
	static FormFactory formFactory;
	static PanelFactory panelFactory;
	static SceneTransitionPolicyProvider policyProvider;
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	pSceneManager->RegisterFormFactory(formFactory);
	pSceneManager->RegisterPanelFactory(panelFactory);
	pSceneManager->SetSceneTransitionPolicyProvider(&policyProvider);
	pSceneManager->RegisterScene(SCENE_METDATA_FORM, FORM_METADATA,
			PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_CHANNEL_FORM, FORM_CHANNEL, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_MAIN_FORM, FORM_MAIN, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_FEATURE_FORM, FORM_FEATURE, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_SETTINGS_FORM, FORM_SETTINGS, PANEL_BLANK);
	pSceneManager->RegisterScene(SCENE_UPCOMING_TAB, FORM_FEATURE,
			PANEL_UPCOMING);

}
