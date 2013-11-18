//
// Copyright (c) 2012 Samsung Electronics Co., Ltd.
//
// Licensed under the Flora License, Version 1.1 (the License);
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://floralicense.org/license
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an AS IS BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "SceneTransitionPolicyProvider.h"
#include "ShowTimeRegister.h"

using namespace Tizen::Ui::Scenes;


SceneTransitionPolicyProvider::SceneTransitionPolicyProvider(void)
{
}

SceneTransitionPolicyProvider::~SceneTransitionPolicyProvider(void)
{
}

Tizen::Ui::Scenes::SceneId
SceneTransitionPolicyProvider::GetNextScene(const Tizen::Ui::Scenes::SceneId& currentSceneId,
											const Tizen::Base::Collection::IList* pArgs)
{
	AppLog("GET NEXT SCENE");
	/*if (currentSceneId == SCENE_COMPLEX_1)
	{
		return SCENE_COMPLEX_2;
	}
	else if (currentSceneId == SCENE_COMPLEX_2)
	{
		return SCENE_COMPLEX_3;
	}
	else if (currentSceneId == SCENE_COMPLEX_3)
	{
		return SCENE_COMPLEX_4;
	}*/
	return L"";
}
